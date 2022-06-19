 
#pragma warning( disable : 4996 ) 
 
#include "G2D.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
  
 
#define ECRAN_ACCUEIL 0
#define ECRAN_OPTIONS 1
#define INIT_PARTIE 2
#define ECRAN_JEU 3
#define ECRAN_GAME_OVER 4
#define ECRAN_WIN 5

struct _plateau {
    string Map1 ="M M M M "
        " M M M M"
        "M M M M "
        " M M M M"
        "M M M M "
        " M M M M"
        "M M M M "
        " M M M M"
        ;

    string textureMur = "[66666666]"
        "[66666666]"
        "[66666666]"
        "[66666666]"
        "[66666666]"
        "[66666666]"
        "[66666666]"
        "[66666666]";
    string textureSol = "[77777777]"
        "[77777777]"
        "[77777777]"
        "[77777777]"
        "[77777777]"
        "[77777777]"
        "[77777777]"
        "[77777777]";
    string texturePossible = "[        ]"
        "[   GG   ]"
        "[  G  G  ]"
        "[ G GG G ]"
        "[ G GG G ]"
        "[  G  G  ]"
        "[   GG   ]"
        "[        ]";

    string positionPiece = "22222222"
        "22222222"
        "00000000"
        "00000000"
        "00000000"
        "00000000"
        "11111111"
        "11111111";

    void setPositionPiece(int x, int y, string valeur) { positionPiece.replace((8 - y - 1) * 8 + x,1,valeur); }
    int getPositionPiece(V2 pos) {
        int valeur = positionPiece[(8 - pos.y - 1) * 8 + pos.x] - 48;
        return valeur;
    }
    string getPlateau() { return positionPiece; }

};
struct _Piece {
    int couleur;
    V2 pos;
    bool estVivant;
    int typePiece;
    V2 Size;
    float Zoom;
    int IdTex;
    string Texture;
    bool noMove;
    int TimeDead = -1   ;

    _Piece(V2 _Pos, int _couleur) {
        pos = _Pos;
        couleur = _couleur;
        estVivant = true;
        noMove = true;
    }
    void setNoMove(bool _noMove) { noMove = _noMove; }
    int getNoMove() { return noMove; }
    void setTypePiece(int _typePiece) { typePiece = _typePiece; }
    void setEstVivant(bool _estVivant) { estVivant = _estVivant; }
    bool getEstVivant() { return estVivant; }
    void setCoord(V2 Coord) { pos = Coord; }
    V2 getCoord() { return pos; }
    int getCouleur() { return couleur; }
    void setZoomSize(float _Zoom) {Zoom = _Zoom;}
    void setIdTex(int _idTex) {
        IdTex = _idTex;
    }
    void setTexture(string _Texture) {
        Texture = _Texture;
    }
    int getTypePiece() { return typePiece; }
};
struct _Cavalier : public _Piece {
    string CavalierNoir =

        "[                       KKKKK                ]"
        "[                      KJ!!!JK               ]"
        "[                     KJ!!J!!JK              ]"
        "[                     KJ!JTJ!JK              ]"
        "[                      KJTB!JJK              ]"
        "[                      KTTB!TTK              ]"
        "[                      KTTTTTKK              ]"
        "[                    KKKKTTTKKKKK            ]"
        "[                   KNKKKKKKEEKNEK           ]"
        "[                   KKE?EEE??KNOJJK          ]"
        "[                  KOK?NNNN??KNO!JK          ]"
        "[                 KO?K?NNNN??KN?O!JK         ]"
        "[                 KNEKEKKKKKKKKN?O!EK        ]"
        "[      KKKKKKK     KKKKE?N??EKKKK??KK        ]"
        "[    KK!!!!!!!KK  K?O!KE?N??EK KEKKK         ]"
        "[   K!!!*!!*!!!*KK?K?EKE?N??EK  KO!KK        ]"
        "[  K*!****!**!**JK??KK K????EKK K?K?EK       ]"
        "[ KK**JKKJ*****JJJK?K K????EEEEKKKK?EK       ]"
        "[KF!OOK/FJ*JJ*JJ*JJKK KKKKKKEN?*K?EKKKK      ]"
        "[ KKNNOKKKJJJJJJ*JJJJK!KKKKKEKK?KKKEK*JK     ]"
        "[  KN?EO!!JKFJFJJJJJKKK!KKKKKOOKNKKKK***K    ]"
        "[  KN?E!JE!KF//JFFJJFFK!KKKSSKOK???EKK***K   ]"
        "[  K??E!K?EKFF//F/JF/FJ!SSS+WKOOK?EKEEK**K   ]"
        "[   KOOOK?K//FF////F/SSS+WWW++KGKKKNNEEKJJK  ]"
        "[   KNE!FEK///FF//SSS+WWW++GSS?KK?N?EEEEKJK  ]"
        "[   K?E!KK1F//FSSS+WWW++GSSSN?KK?NOOO!!EKJK  ]"
        "[   KE/FFK11FSS+WWW++GSSSFKNNN?EKOOO!!EEKJK  ]"
        "[   K/KF1K11S+WW++GSSSFJJJJKEEEKKEE!!EEEKK   ]"
        "[    KKKKKKSWW+GSSS/JJJ!**!KKKKEK?NEE?EEKK   ]"
        "[        KKSSSSSKKKJ!!*JJJ!JK?EEK????EEKJK   ]"
        "[        K??N???EEK*JJJFFJ!JK??EEKEEEEKKJK   ]"
        "[        KOON?O!!EKJFFF/FJ*KKE?EEKKKKKKJJJK  ]"
        "[       K1K?OO!EEKFF///FJJ*KE?EEEKF//FKJJJK  ]"
        "[      K111KN??KKFF///FFJ*JK?N??EKFF/FKJJJJK ]"
        "[     K11111KKKF11FFFFFJKKKKNNN?K/FFFFKJJJJJK]"
        "[     KFFKKKKKKKKKKFFFKK   KKKKKKK/FFFFKJJJJK]"
        "[     KFFK        KFFFK      K111KKKFF//KJKK ]"
        "[     K111KKK      KFFK      K111K1FKF//KK   ]"
        "[      KK11KSK     KFFK      K11K  1FKFFK    ]"
        "[       K111SK     K//FK    K111K   1KFFK    ]"
        "[        KKSSK     K//FK    K111K    KFFK    ]"
        "[          KK       KF1K   K1111K    KFFK    ]"
        "[                   KF1KKK KSS1K    KFFFK    ]"
        "[            KKKKKKKKF1KKKKKSSSKKKKKKFFFKKK  ]"
        "[        KKKKKKKKKKKKFFFKKKKKKKKKKKKFFFKKKK  ]"
        "[       KKKKKKKKKKKKFGGKKKKKKKKKKKKKSSSKKK   ]"
        "[       KKKKKKKKKKKKSSGFKKKKKKKKKKKKSSSKKK   ]"
        "[        KKKKKKKKKKKSSSKKKKKKKKKKKKKKKKK     ]"
        "[             KKKKKKKKKKKKKKKK               ]";

    string CavalierBlanc =
        "[                       KKKKK                ]"
        "[                      KJ!!!JK               ]"
        "[                     KJ!!J!!JK              ]"
        "[                     KJ!JTJ!JK              ]"
        "[                      KJTK!JJK              ]"
        "[                      KTTK!TTK              ]"
        "[                      KTTTTTKK              ]"
        "[                    KKKKTTTKKKKK            ]"
        "[                   KXKKKKKKRRKXRK           ]"
        "[                   KKRZRRRZZKXOJJK          ]"
        "[                  KOKZXXXXZZKXO!JK          ]"
        "[                 KOZKZXXXXZZKXZO!JK         ]"
        "[                 KXRKRKKKKKKKKXZO!RK        ]"
        "[      KKKKKKK     KKKKRZXZZRKKKKZZKK        ]"
        "[    KK!!!!!!!KK  KZO!KRZXZZRK KRKKK         ]"
        "[   K!!!*!!*!!!*KKZKZRKRZXZZRK  KO!KK        ]"
        "[  K*!****!**!**JKZZKK KZZZZRKK KZKZRK       ]"
        "[ KK**JKKJ*****JJJKZK KZZZZRRRRKKKKZRK       ]"
        "[KF!OOK/FJ*JJ*JJ*JJKK KKKKKKRXZ*KZRKKKK      ]"
        "[ KKXXOKKKJJJJJJ*JJJJK!KKKKKRKKZKKKRK*JK     ]"
        "[  KXZRO!!JKFJFJJJJJKKK!KKKKKOOKXKKKK***K    ]"
        "[  KXZR!JR!KF//JFFJJFFK!KKKSSKOKZZZRKK***K   ]"
        "[  KZZR!KZRKFF//F/JF/FJ!SSS+WKOOKZRKRRK**K   ]"
        "[   KOOOKZK//FF////F/SSS+WWW++KGKKKXXRRKJJK  ]"
        "[   KXR!FRK///FF//SSS+WWW++GSSZKKZXZRRRRKJK  ]"
        "[   KZR!KK1F//FSSS+WWW++GSSSXZKKZXOOO!!RKJK  ]"
        "[   KR/FFK11FSS+WWW++GSSSFKXXXZRKOOO!!RRKJK  ]"
        "[   K/KF1K11S+WW++GSSSFJJJJKRRRKKRR!!RRRKK   ]"
        "[    KKKKKKSWW+GSSS/JJJ!**!KKKKRKZXRRZRRKK   ]"
        "[        KKSSSSSKKKJ!!*JJJ!JKZRRKZZZZRRKJK   ]"
        "[        KZZXZZZRRK*JJJFFJ!JKZZRRKRRRRKKJK   ]"
        "[        KOOXZO!!RKJFFF/FJ*KKRZRRKKKKKKJJJK  ]"
        "[       K1KZOO!RRKFF///FJJ*KRZRRRKF//FKJJJK  ]"
        "[      K111KXZZKKFF///FFJ*JKZXZZRKFF/FKJJJJK ]"
        "[     K11111KKKF11FFFFFJKKKKXXXZK/FFFFKJJJJJK]"
        "[     KFFKKKKKKKKKKFFFKK   KKKKKKK/FFFFKJJJJK]"
        "[     KFFK        KFFFK      K111KKKFF//KJKK ]"
        "[     K111KKK      KFFK      K111K1FKF//KK   ]"
        "[      KK11KSK     KFFK      K11K  1FKFFK    ]"
        "[       K111SK     K//FK    K111K   1KFFK    ]"
        "[        KKSSK     K//FK    K111K    KFFK    ]"
        "[          KK       KF1K   K1111K    KFFK    ]"
        "[                   KF1KKK KSS1K    KFFFK    ]"
        "[            KKKKKKKKF1KKKKKSSSKKKKKKFFFKKK  ]"
        "[        KKKKKKKKKKKKFFFKKKKKKKKKKKKFFFKKKK  ]"
        "[       KKKKKKKKKKKKFGGKKKKKKKKKKKKKSSSKKK   ]"
        "[       KKKKKKKKKKKKSSGFKKKKKKKKKKKKSSSKKK   ]"
        "[        KKKKKKKKKKKSSSKKKKKKKKKKKKKKKKK     ]"
        "[             KKKKKKKKKKKKKKKK               ]";

    _Cavalier(V2 _Pos, int _couleur) : _Piece(_Pos, _couleur)
    {
        setZoomSize(1.5);
        setTypePiece(2);
        if (_couleur == 1)
            setTexture(CavalierBlanc);
        else
            setTexture(CavalierNoir);
    }

};
struct _Dame : public _Piece {
    string reineBlanche =
        "[             K             ]"
        "[            KUK            ]"
        "[           KUVUK           ]"
        "[         KKKUVUKKK         ]"
        "[        KYOUUUUUOYK        ]"
        "[       KOUUUUUUUUYOK       ]"
        "[      KOYOOOYYYYOYOK       ]"
        "[      KOYYOOOOYOOYYOK      ]"
        "[      KOYOTTTOOTTOYOK      ]"
        "[     KOYOTTTTTTTTTOYOK     ]"
        "[     KOYYTBWTTTWBWYYOK     ]"
        "[     KOYYTBBTTTBBWYYOK     ]"
        "[      KOYHHTTTTTHHYOK      ]"
        "[     KOYYOTTTTTTTOYYOK     ]"
        "[    KOYYYYOTTRRTOYYYYOK    ]"
        "[   KOYOWOOOOTTTOOOOWOYOK   ]"
        "[   KOYOWWWTTTTTTTWWWOYOK   ]"
        "[  KOYYOOXWWWWTWWWWXOOYYOK  ]"
        "[  KOYOXXXIWWWWWWWIXXXOYOK  ]"
        "[   KOXXXXIIIIWIIIIXXXXOK   ]"
        "[    KXXXOIIIIIIIIIOXXXK    ]"
        "[   KXXXOYOIIIIIIIOYOXXXK   ]"
        "[  KXXXOYYOIIIIIIIOYYOXXXK  ]"
        "[ KTTTKKOOKHIIIIIHKOOKKTTTK ]"
        "[ KTTTK KKHHHIIIHHHKK  KTTTK]"
        "[  KKK  KHHHHHIHHHHHK   KKK ]"
        "[       KHHXHHHHHXHHK       ]"
        "[      KHHXXXHHHXXXHHK      ]"
        "[      KHZXXXXHXXXXZHK      ]"
        "[      KHZXXXZHZXXXZHK      ]"
        "[      KZXXXZXXXZXXXZK      ]"
        "[      KZXXXZXXXZXXXZK      ]"
        "[     KZXXXZXXXXXZXXXZK     ]"
        "[    KZXXXXZXXXXXZXXXXZK    ]"
        "[    KZXXXXZXXXXXZXXXXZK    ]"
        "[   KZXXXXZXXXXXXXZXXXXZK   ]"
        "[   KZXXXXZXXXXXXXZXXXXZK   ]"
        "[  KZXXXXZXXXXXXXXXZXXXXZK  ]"
        "[ KZXXXXZXXXXXXXXXXXZXXXXZK ]"
        "[ KZXXXZXXXXXXXXXXXXXZXXXZK ]"
        "[KZXXXZXXXXXXXXXXXXXXXZXXXZK]"
        "[KZXXZXXXXXXXXXXXXXXXXXZXXZK]"
        "[ KZXZXXXXXXXXXXXXXXXXXZXZK ]"
        "[  KZZZZZXXXXXXXXXXXZZZZZK  ]"
        "[   KKKKKZZZZZZZZZZZKKKKK   ]"
        "[        KKKKKKKKKKK        ]";


    string reineNoire =
        "[             K             ]"
        "[            KUK            ]"
        "[           KUVUK           ]"
        "[         KKKUVUKKK         ]"
        "[        KLFUUUUUFLK        ]"
        "[       KFUUUUUUUULFK       ]"
        "[      KFLFFFLLLLFLFK       ]"
        "[      KFLLFFFFLFFLLFK      ]"
        "[      KFLFTTTFFTTFLFK      ]"
        "[     KFLFTTTTTTTTTFLFK     ]"
        "[     KFLLTQVTTTVQTLLFK     ]"
        "[     KFLLTQQTTTQQTLLFK     ]"
        "[      KFLCCTTTTTCCLFK      ]"
        "[     KFLLFTTTTTTTFLLFK     ]"
        "[    KFLLLLFTTRRTFLLLLFK    ]"
        "[   KFLFWFFFFTTTFFFFWFLFK   ]"
        "[   KFLFWWWTTTTTTTWWWFLFK   ]"
        "[  KFLLFFNWWWWTWWWWNFFLLFK  ]"
        "[  KFLFNNNEWWWWWWWENNNFLFK  ]"
        "[   KFNNNNEEEEWEEEENNNNFK   ]"
        "[    KNNNFEEEEEEEEEFNNNK    ]"
        "[   KNNNFLFEEEEEEEFLFNNNK   ]"
        "[  KNNNFLLFEEEEEEEFLLFNNNK  ]"
        "[ KTTTKKFFKCEEEEECKFFKKTTTK ]"
        "[ KTTTK KKCCCEEECCCKK KTTTK ]"
        "[  KKK  KCCCCCECCCCCK  KKK  ]"
        "[       KCCNCCCCCNCCK       ]"
        "[      KCCNNNCCCNNNCCK      ]"
        "[      KCBNNNNCNNNNBCK      ]"
        "[      KCBNNNBCBNNNBCK      ]"
        "[      KBNNNBNNNBNNNBK      ]"
        "[      KBNNNBNNNBNNNBK      ]"
        "[     KBNNNBNNNNNBNNNBK     ]"
        "[    KBNNNNBNNNNNBNNNNBK    ]"
        "[    KBNNNNBNNNNNBNNNNBK    ]"
        "[   KBNNNNBNNNNNNNBNNNNBK   ]"
        "[   KBNNNNBNNNNNNNBNNNNBK   ]"
        "[  KBNNNNBNNNNNNNNNBNNNNBK  ]"
        "[ KBNNNNBNNNNNNNNNNNBNNNNBK ]"
        "[ KBNNNBNNNNNNNNNNNNNBNNNBK ]"
        "[KBNNNBNNNNNNNNNNNNNNNBNNNBK]"
        "[KBNNBNNNNNNNNNNNNNNNNNBNNBK]"
        "[ KBNBNNNNNNNNNNNNNNNNNBNBK ]"
        "[  KBBBBBNNNNNNNNNNNBBBBBK  ]"
        "[   KKKKKKBBBBBBBBBBBKKKK   ]"
        "[         KKKKKKKKKKK       ]"
        ;

    _Dame(V2 _Pos, int _couleur) : _Piece(_Pos, _couleur)
    {
        setZoomSize(1.7);
        setTypePiece(4);
        if (_couleur == 1)
            setTexture(reineBlanche);
        else
            setTexture(reineNoire);
    }

};
struct _Roi : public _Piece {
    string roiNoir =
        "[  K  KKKKKKK  K  ]"
        "[ KOKKPOPPPOPKKOK ]"
        "[ KOOPOOOPOOOPOOK ]"
        "[ KOOOOOOOOOOOOOK ]"
        "[ KWAWAAWAWAAWAWK ]"
        "[ KOOOOOOOOOOOOOK ]"
        "[ KJTWRTTTTTRWTJK ]"
        "[ KJTWKTTTTTKWTJK ]"
        "[KJTTWWTTTTTWWTTJK]"
        "[KJTTTTJJJJJTTTTJK]"
        "[KJJJTJTTTTTJTJJJK]"
        "[ KJJTJTTJTTJTJJK ]"
        "[  KJJJJJJJJJJJK  ]"
        "[  KKJJJJJJJJJSK  ]"
        "[ Y KSSSSCSSSSKK  ]"
        "[YAY KKKSCSKKKWK  ]"
        "[ YKPWWWSCSWWWPK  ]"
        "[ GKPPPWSCSWPPPK  ]"
        "[ YPPPPWBCBWPPPK  ]"
        "[ G KPPWMMMWPPKK  ]"
        "[ G KPPWBCBWPPTK  ]"
        "[ G KPPWBCBWPPK   ]"
        "[ G KPPWBCBWPPK   ]"
        "[ G KPPWBCBWPPK   ]"
        "[ G KKKWBCBWKKK   ]"
        "[      KKKKK      ]";

    string roiBlanc = "[  K  KKKKKKK  K  ]"
        "[ KYKKRYRRRYRKKYK ]"
        "[ KYYRYYYRYYYRYYK ]"
        "[ KYYYYYYYYYYYYYK ]"
        "[ KWAWAAWAWAAWAWK ]"
        "[ KYYYYYYYYYYYYYK ]"
        "[ KGTWDTTTTTDWTGK ]"
        "[ KGTWDTTTTTDWTGK ]"
        "[KGTTWWTTTTTWWTTGK]"
        "[KGTTTTGGGGGTTTTGK]"
        "[KGGGTGTTTTTGTGGGK]"
        "[ KGGTGTTGTTGTGGK ]"
        "[  KGGGGGGGGGGGK  ]"
        "[  KKGGGGGGGGGSK  ]"
        "[ Y KSSSSCSSSSKK  ]"
        "[YAY KKKSCSKKKWK  ]"
        "[ YKRWWWSCSWWWRK  ]"
        "[ GKRRRWSCSWRRRK  ]"
        "[ YRRRRWBCBWRRRK  ]"
        "[ G KRRWMMMWRRKK  ]"
        "[ G KRRWBCBWRRTK  ]"
        "[ G KRRWBCBWRRK   ]"
        "[ G KRRWBCBWRRK   ]"
        "[ G KRRWBCBWRRK   ]"
        "[ G KKKWBCBWKKK   ]"
        "[      KKKKK      ]";

    _Roi(V2 _Pos, int _couleur) : _Piece(_Pos, _couleur)
    {
        setZoomSize(2.8);
        setTypePiece(5);
        if (_couleur == 1)
            setTexture(roiBlanc);
        else
            setTexture(roiNoir);
    }

};
struct _Tour : public _Piece {
    string tourBlanche =
        "[            YY            ]"
        "[            II            ]"
        "[           IIII           ]"
        "[           IIII           ]"
        "[          IIIIII          ]"
        "[          J2222J          ]"
        "[      Y   J2JJ2J   Y      ]"
        "[      I   J2JJ2J   I      ]"
        "[      I   J2222J   I      ]"
        "[     III  J2222J  III     ]"
        "[     III  J2JJ2J  III     ]"
        "[    IIIII J2JJ2J IIIII    ]"
        "[    J222J J2222J J222J    ]"
        "[    J2J2JJJJJJJJJJ2J2J    ]"
        "[  Y J2J2J22222222J2J2J Y  ]"
        "[  I J2J2J222JJ222J2J2J I  ]"
        "[  I J222J22JNNJ22J222J I  ]"
        "[ IIIJ222J22JNNJ22J222JIII ]"
        "[ IIIJ222J222JJ222J222JIII ]"
        "[IIIII222J22222222J222IIII ]"
        "[J222J222J22222222J222J222J]"
        "[J222J2JJJ2JJJ2JJJJJJJJ222J]"
        "[J222JJJ2JJJ2JJJ2JJJ2JJ222J]"
        "[J222J2222222222222222J222J]"
        "[J2J2J2222222222222222J2J2J]"
        "[J2J2J2222222222222222J2J2J]"
        "[J2J2J2222222112222222J2J2J]"
        "[J222J2222221//1222222J222J]"
        "[J222J222221////122222J222J]"
        "[J222J222221//1/122222J222J]"
        "[J222J222221//1/122222J222J]"
        "[J222J222221//1/122222J222J]"
        "[J222J222221////122222J222J]"
        "[J222J222221////122222J222J]"
        "[JJJJJJJJJJ111111JJJJJJJJJJ]"
        ;

    string tourNoire = "[            YY            ]"
        "[            ??            ]"
        "[           ????           ]"
        "[           ????           ]"
        "[          ??????          ]"
        "[          J++++J          ]"
        "[      Y   J+JJ+J   Y      ]"
        "[      ?   J+JJ+J   ?      ]"
        "[      ?   J++++J   ?      ]"
        "[     ???  J++++J  ???     ]"
        "[     ???  J+JJ+J  ???     ]"
        "[    ????? J+JJ+J ?????    ]"
        "[    J+++J J++++J J+++J    ]"
        "[    J+J+JJJJJJJJJJ+J+J    ]"
        "[  Y J+J+J++++++++J+J+J Y  ]"
        "[  ? J+J+J+++JJ+++J+J+J ?  ]"
        "[  ? J+++J++JVVJ++J+++J ?  ]"
        "[ ???J+++J++JVVJ++J+++J??? ]"
        "[ ???J+++J+++JJ+++J+++J??? ]"
        "[?????+++J++++++++J+++???? ]"
        "[J+++J+++J++++++++J+++J+++J]"
        "[J+++J+JJJ+JJJ+JJJJJJJJ+++J]"
        "[J+++JJJ+JJJ+JJJ+JJJ+JJ+++J]"
        "[J+++J++++++++++++++++J+++J]"
        "[J+J+J++++++++++++++++J+J+J]"
        "[J+J+J++++++++++++++++J+J+J]"
        "[J+J+J+++++++11+++++++J+J+J]"
        "[J+++J++++++1331++++++J+++J]"
        "[J+++J+++++133331+++++J+++J]"
        "[J+++J+++++133131+++++J+++J]"
        "[J+++J+++++133131+++++J+++J]"
        "[J+++J+++++133131+++++J+++J]"
        "[J+++J+++++133331+++++J+++J]"
        "[J+++J+++++133331+++++J+++J]"
        "[JJJJJJJJJJ111111JJJJJJJJJJ]";

    _Tour(V2 _Pos, int _couleur) : _Piece(_Pos, _couleur)
    {
        setZoomSize(2.1);
        setTypePiece(1);
        if (_couleur == 1)
            setTexture(tourBlanche);
        else
            setTexture(tourNoire);
    }
};
struct _Fou : public _Piece {
    string fouBlanc =
        "[                   KKKKKKKKK                                                ]"
        "[                 KKRRRRRK888KKKKK                 KKKKKK                    ]"
        "[                KRRRRRRRRK8KRRRRKKK           KKKKKKKKKKKK                  ]"
        "[               KRRRKRRRRRRKRRRRRK88K      KKKKKKKKKKKKKKKKK                 ]"
        "[               KRRK8KRRRRRRRRRRRRKKKK   KK88KKKKKKKKKKKKK88K                ]"
        "[              KRRRK88KRRRRRRRRRRRRRRK  KKKKKKKKKKKK8KKKKKKKK                ]"
        "[              KRRRK8KRRRRRRRRRKRRRRRRKKKKKKKKKKKKK8KKKKKKKKKK               ]"
        "[             KRRRRRKRRRRRRRRRK8KRRRRRKKKKKKKKKKKKKKKKKKKKKKKK               ]"
        "[             KRRRRRRRRRRRRRRK888KRRRRKKKKKKKKKKKKKKKKKKKKKKKKK              ]"
        "[             KRRRRRRRRRRRRRRRKKKRRRRRKKKK8KKKKKKKKKKKKKK8KKKKK              ]"
        "[            KRRRRRRRRRRKRRRRRRRRRRRRRKKKK8KKKKKKKKKKKKKK8KKKKK              ]"
        "[            KRRRRRRRRRK8KRRRRRRRRRRRRKKKKKKKKKKKKKKKKKKKKKKKKKK             ]"
        "[            KKKRRRRRKKK88KRRRRRRRRRRRRKKKKKKKK8KKKKKKKKKKKKKKKK             ]"
        "[            K88KRRKK   KKRRRRRRRKKKRRRKKKKKKKKK8KKKKKKKKKKKKKKK             ]"
        "[            KK8KRK       KRRRRRK888KRRKKKKKKKKKKKKKKK  KKKKKK8K             ]"
        "[            KRKKRK       KRRRRRRK8KRRRKKK8KKKKKKKKKK      KKKKK             ]"
        "[            KRRRRK       KRRRRRKKKKKKKKKKKKKKKKKKKK       KKKKK             ]"
        "[             KRRK         KRRKK8888888K888888KKKKKK        KKK              ]"
        "[             KRK          KRK888888888888888888KKK          K               ]"
        "[              K            KK888888888888888888KK          KOK              ]"
        "[             KOK           KK8KKKKK888888KKKKK8K           KOK              ]"
        "[            KOOOK           K8KKKKKK8888KKKKKK8K            K               ]"
        "[             KKK            KKKKKKKK8888KKKKKK8K                            ]"
        "[                            K8KKKOKK8888KKOKKK8K                            ]"
        "[                            K8KKKKKK8888KKKKKK8K                            ]"
        "[                            K8K888KK8888KK888K8K                            ]"
        "[                            K888888888888888888K                            ]"
        "[                             K8888888888888888K                             ]"
        "[                             K8KKK88888888KKK8K                             ]"
        "[                             K88K!KK8888KK!K88K                             ]"
        "[                              K8K!K!KKKK!K!K8K                              ]"
        "[   KK                         K88KK!K!!K!KK88K                         KK   ]"
        "[  KGGK                         K888KKKKKK888K                         KGGK  ]"
        "[ KGGGGK KK                      KK888888K8KK                      KK KGGGGK ]"
        "[KGGGGGGKGGK             KKKKK     KKK88KKK     KKKKK             KGGKGGGGGGK]"
        "[KGGGGGGKGK             KRRRRRK    KKKKKKKK    KKKKKKK             KGKGGGGGGK]"
        "[ KKGGGGGGKK           KRRRRRRRKKKKRRKKKKKKKKKKKKKKKKKK           KKGGGGGGKK ]"
        "[   KKKKKKKK           KRRKKKKKKKKRRRRKKKKKKKRRKKKKKKKK           KRKKKKKK   ]"
        "[   KKKKKKKK            KKKKKKKKKRRRRRKKKKKKKKRRRRRRKK            KRRRRRRK   ]"
        "[    KKKKKKK           KKKKKKKKKRRRKRRKKKKKKKKKRRRRRRRK           KRRRRRK    ]"
        "[    KKKRKKKK         KKKKKKKKKOKRKKKRRKKKRKKKOKRRRRRRRK         KRRKRRRK    ]"
        "[    KKKKKKKK        KKKKKKRKKKOOKKKRRRKKKKRKOOKRRRKRRRRK        KRRRRRRK    ]"
        "[     KKKKKKKK      KKKKKKKKKKKKKKKOKRKKKKOKRKKKRRRRRRRRRK      KRRRRRRK     ]"
        "[     KKKKKKKKK   KKKKRKKKKKKKKKKKKOOKKRKOOKRRRRRRRRRRRRRRKK   KRRRRRRRK     ]"
        "[      KKKKKRKKKKKKKKKKKKKKKKKKKKKKKKKKRRKKKRRRRRRRRRRRRRRRRKKKRRRRRRKK      ]"
        "[      KKKKKKKKKKKKKKKKKKKKKKKKKRKKKKKKRRRRRRRRRRRRRRRRKRRRRRRRRRRRRRRK      ]"
        "[       KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKRRRRRRRRKRRRKKRRRRRRRRRKRRRRRRK       ]"
        "[        KKKKKKKKKKKKKKKKK  KKKKKKKKKKKRRRRRRRRRRRK  KRRRRRRRRRRRRRRK        ]"
        "[         KKKKKKKRKKKKKKK   KKKKKKKRKKKRRRRRRRRRRRK   KRRRRRRRRRRRRK         ]"
        "[          KKKKKKKKKKKKK    KKKKKKKKKKKRRRRRRRRRRK     KRRRKRRRRRRK          ]"
        "[           KKKKKKKKKKK     KKKKKKKKKKKKRRRRRRRRRK      KKKKKKKKKK           ]"
        "[                           KKKKKKKKKKKKRRRRRRRRRK                           ]"
        "[                           KKKKRKKKKKKKRRKRRRRRRK                           ]"
        "[                          KKKKKKKKKKKKKRRRRRRRRRRK                          ]"
        "[                          KKKKKKKKKKKKKRRRRRKRRRRK                          ]"
        "[                          KKKKKKKKKKKKKRRRRRRRRRRK                          ]"
        "[                         KKKRKKKKKKKRKKRRRRRRRRRRRK                         ]"
        "[                         KKKKKKKKKKKKKKRRRRRRRRKRRK                         ]"
        "[                         KKKKKKKKKKKKKKRRRRRRRRRRRRK                        ]"
        "[                         KKKKKKKKKKKKKKRRRRRRRRRRRRK                        ]"
        "[                        KKKKKKKKKRKKKKKRRRKRRRRRRRRK                        ]"
        "[                        KKRKKKKKKKKKKKRRRRRRRRRRRRRRK                       ]"
        "[                        KKKKKKKKKKKKKKRRRRRRRRRRKRRRRK                      ]"
        "[                       KKKKKKKKKKKKKKKRRRRRRRRRRRRRRRK                      ]"
        "[                       KKKKKKKKKKKKKKKRRRRRRKKRRRRRRRK                      ]"
        "[                       KKKKRKKKKKKKKKKRRRRRKKKKRRRRRK                       ]"
        "[                       KKKKRKKKKKKKRKKRRRRRKKKKKRRRRK                       ]"
        "[                       KKKKRRKKKKKRRKKKRRRKKKKKKKRRRK                       ]"
        "[                       KKKKRRKKKKRRRRKKKRKKKKRKKKKRK                        ]"
        "[                       KKKKRRRKKKRRRRKKKRKKKKKKKKKK                         ]"
        "[                       KKKKKRRKKKRRKRKKKKKKKKKKKKKOK                        ]"
        "[                        K  KRRRKRRRRRKKKOKKKKKKKKOOOK                       ]"
        "[                       KOK KRRKOKRRRRKKOOOKKKKKKKKKKK                       ]"
        "[                       KOK KRRKOKRRRRRKKKKKKKRKKKKKKKK                      ]"
        "[                        K  KRRRKRRRRRRKKRKKKKKKKKKKKRKK                     ]"
        "[                          KRRRRRRRRRRKKKKKKKKKKKKKKKKKKK                    ]"
        "[                          KRRRRRKRRRK     KKKKKKKKKKKKKK                    ]"
        "[                          KRRRRRRRRRK       KKKKKRKKKKKK                    ]"
        "[                          KRKRRRRRRK         KKKKKKKKKKK                    ]"
        "[                         KRRRRRRRRRK          KKKKKKKKKK                    ]"
        "[                         KRRRRRRRRK           KKKKKKKKK                     ]"
        "[                         KRRRRRRKRK          KKKKKKKRKK                     ]"
        "[                        KRRRRRRRRRK          KKKKKKKKK                      ]"
        "[                        KRKRRRRRRK          KKRKKKKKKK                      ]"
        "[                        KRRRRKRRRK          KKKKKKKKKK                      ]"
        "[                 KKK   KRRRRRRRRRK          KKKKKKKKK   KK                  ]"
        "[                KKKKK  KRRRRRRRRK          KKKKKKKRKK  KRRK                 ]"
        "[               KKKKK  KRRRRRRKRRK          KKKKKKKKKK   KRRK                ]"
        "[               KKKKK  KRRRRRRRRRK         KRKKKKKKKKKK  KRRK                ]"
        "[               KKKKKKKKKKRRRRRRK         KRRRRKKKKKKK  KRRRK                ]"
        "[               KKKKKKKKKKKKKKKKK         KRRRRRRRRRRRKKRRRRK                ]"
        "[                KKKKKKKKKKKKKKK          KRRRRRRRRRRRRRRRRK                 ]"
        "[                 KKKKKKKKKKKKKK           KRRRRRRRRRRRRRRK                  ]"
        "[                  KKKKKKKKKKKK             KKKRRRRRRRRRKK                   ]"
        "[                    KKKKKKKKK                 KKKKKKKKK                     ]"
        ;

    string fouNoir =
        "[                   KKKKKKKKK                                                ]"
        "[                 KKBBBBBK888KKKKK                 KKKKKK                    ]"
        "[                KBBBBBBBBK8KBBBBKKK           KKKKKKKKKKKK                  ]"
        "[               KBBBKBBBBBBKBBBBBK88K      KKKKKKKKKKKKKKKKK                 ]"
        "[               KBBK8KBBBBBBBBBBBBKKKK   KK88KKKKKKKKKKKKK88K                ]"
        "[              KBBBK88KBBBBBBBBBBBBBBK  KKKKKKKKKKKK8KKKKKKKK                ]"
        "[              KBBBK8KBBBBBBBBBKBBBBBBKKKKKKKKKKKKK8KKKKKKKKKK               ]"
        "[             KBBBBBKBBBBBBBBBK8KBBBBBKKKKKKKKKKKKKKKKKKKKKKKK               ]"
        "[             KBBBBBBBBBBBBBBK888KBBBBKKKKKKKKKKKKKKKKKKKKKKKKK              ]"
        "[             KBBBBBBBBBBBBBBBKKKBBBBBKKKK8KKKKKKKKKKKKKK8KKKKK              ]"
        "[            KBBBBBBBBBBKBBBBBBBBBBBBBKKKK8KKKKKKKKKKKKKK8KKKKK              ]"
        "[            KBBBBBBBBBK8KBBBBBBBBBBBBKKKKKKKKKKKKKKKKKKKKKKKKKK             ]"
        "[            KKKBBBBBKKK88KBBBBBBBBBBBBKKKKKKKK8KKKKKKKKKKKKKKKK             ]"
        "[            K88KBBKK   KKBBBBBBBKKKBBBKKKKKKKKK8KKKKKKKKKKKKKKK             ]"
        "[            KK8KBK       KBBBBBK888KBBKKKKKKKKKKKKKKK  KKKKKK8K             ]"
        "[            KBKKBK       KBBBBBBK8KBBBKKK8KKKKKKKKKK      KKKKK             ]"
        "[            KBBBBK       KBBBBBKKKKKKKKKKKKKKKKKKKK       KKKKK             ]"
        "[             KBBK         KBBKK8888888K888888KKKKKK        KKK              ]"
        "[             KBK          KBK888888888888888888KKK          K               ]"
        "[              K            KK888888888888888888KK          KOK              ]"
        "[             KOK           KK8KKKKK888888KKKKK8K           KOK              ]"
        "[            KOOOK           K8KKKKKK8888KKKKKK8K            K               ]"
        "[             KKK            KKKKKKKK8888KKKKKK8K                            ]"
        "[                            K8KKKOKK8888KKOKKK8K                            ]"
        "[                            K8KKKKKK8888KKKKKK8K                            ]"
        "[                            K8K888KK8888KK888K8K                            ]"
        "[                            K888888888888888888K                            ]"
        "[                             K8888888888888888K                             ]"
        "[                             K8KKK88888888KKK8K                             ]"
        "[                             K88K!KK8888KK!K88K                             ]"
        "[                              K8K!K!KKKK!K!K8K                              ]"
        "[   KK                         K88KK!K!!K!KK88K                         KK   ]"
        "[  KGGK                         K888KKKKKK888K                         KGGK  ]"
        "[ KGGGGK KK                      KK888888K8KK                      KK KGGGGK ]"
        "[KGGGGGGKGGK             KKKKK     KKK88KKK     KKKKK             KGGKGGGGGGK]"
        "[KGGGGGGKGK             KBBBBBK    KKKKKKKK    KKKKKKK             KGKGGGGGGK]"
        "[ KKGGGGGGKK           KBBBBBBBKKKKBBKKKKKKKKKKKKKKKKKK           KKGGGGGGKK ]"
        "[   KKKKKKKK           KBBKKKKKKKKBBBBKKKKKKKBBKKKKKKKK           KBKKKKKK   ]"
        "[   KKKKKKKK            KKKKKKKKKBBBBBKKKKKKKKBBBBBBKK            KBBBBBBK   ]"
        "[    KKKKKKK           KKKKKKKKKBBBKBBKKKKKKKKKBBBBBBBK           KBBBBBK    ]"
        "[    KKKBKKKK         KKKKKKKKKOKBKKKBBKKKBKKKOKBBBBBBBK         KBBKBBBK    ]"
        "[    KKKKKKKK        KKKKKKBKKKOOKKKBBBKKKKBKOOKBBBKBBBBK        KBBBBBBK    ]"
        "[     KKKKKKKK      KKKKKKKKKKKKKKKOKBKKKKOKBKKKBBBBBBBBBK      KBBBBBBK     ]"
        "[     KKKKKKKKK   KKKKBKKKKKKKKKKKKOOKKBKOOKBBBBBBBBBBBBBBKK   KBBBBBBBK     ]"
        "[      KKKKKBKKKKKKKKKKKKKKKKKKKKKKKKKKBBKKKBBBBBBBBBBBBBBBBKKKBBBBBBKK      ]"
        "[      KKKKKKKKKKKKKKKKKKKKKKKKKBKKKKKKBBBBBBBBBBBBBBBBKBBBBBBBBBBBBBBK      ]"
        "[       KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKBBBBBBBBKBBBKKBBBBBBBBBKBBBBBBK       ]"
        "[        KKKKKKKKKKKKKKKKK  KKKKKKKKKKKBBBBBBBBBBBK  KBBBBBBBBBBBBBBK        ]"
        "[         KKKKKKKBKKKKKKK   KKKKKKKBKKKBBBBBBBBBBBK   KBBBBBBBBBBBBK         ]"
        "[          KKKKKKKKKKKKK    KKKKKKKKKKKBBBBBBBBBBK     KBBBKBBBBBBK          ]"
        "[           KKKKKKKKKKK     KKKKKKKKKKKKBBBBBBBBBK      KKKKKKKKKK           ]"
        "[                           KKKKKKKKKKKKBBBBBBBBBK                           ]"
        "[                           KKKKBKKKKKKKBBKBBBBBBK                           ]"
        "[                          KKKKKKKKKKKKKBBBBBBBBBBK                          ]"
        "[                          KKKKKKKKKKKKKBBBBBKBBBBK                          ]"
        "[                          KKKKKKKKKKKKKBBBBBBBBBBK                          ]"
        "[                         KKKBKKKKKKKBKKBBBBBBBBBBBK                         ]"
        "[                         KKKKKKKKKKKKKKBBBBBBBBKBBK                         ]"
        "[                         KKKKKKKKKKKKKKBBBBBBBBBBBBK                        ]"
        "[                         KKKKKKKKKKKKKKBBBBBBBBBBBBK                        ]"
        "[                        KKKKKKKKKBKKKKKBBBKBBBBBBBBK                        ]"
        "[                        KKBKKKKKKKKKKKBBBBBBBBBBBBBBK                       ]"
        "[                        KKKKKKKKKKKKKKBBBBBBBBBBKBBBBK                      ]"
        "[                       KKKKKKKKKKKKKKKBBBBBBBBBBBBBBBK                      ]"
        "[                       KKKKKKKKKKKKKKKBBBBBBKKBBBBBBBK                      ]"
        "[                       KKKKBKKKKKKKKKKBBBBBKKKKBBBBBK                       ]"
        "[                       KKKKBKKKKKKKBKKBBBBBKKKKKBBBBK                       ]"
        "[                       KKKKBBKKKKKBBKKKBBBKKKKKKKBBBK                       ]"
        "[                       KKKKBBKKKKBBBBKKKBKKKKBKKKKBK                        ]"
        "[                       KKKKBBBKKKBBBBKKKBKKKKKKKKKK                         ]"
        "[                       KKKKKBBKKKBBKBKKKKKKKKKKKKKOK                        ]"
        "[                        K  KBBBKBBBBBKKKOKKKKKKKKOOOK                       ]"
        "[                       KOK KBBKOKBBBBKKOOOKKKKKKKKKKK                       ]"
        "[                       KOK KBBKOKBBBBBKKKKKKKBKKKKKKKK                      ]"
        "[                        K  KBBBKBBBBBBKKBKKKKKKKKKKKBKK                     ]"
        "[                          KBBBBBBBBBBKKKKKKKKKKKKKKKKKKK                    ]"
        "[                          KBBBBBKBBBK     KKKKKKKKKKKKKK                    ]"
        "[                          KBBBBBBBBBK       KKKKKBKKKKKK                    ]"
        "[                          KBKBBBBBBK         KKKKKKKKKKK                    ]"
        "[                         KBBBBBBBBBK          KKKKKKKKKK                    ]"
        "[                         KBBBBBBBBK           KKKKKKKKK                     ]"
        "[                         KBBBBBBKBK          KKKKKKKBKK                     ]"
        "[                        KBBBBBBBBBK          KKKKKKKKK                      ]"
        "[                        KBKBBBBBBK          KKBKKKKKKK                      ]"
        "[                        KBBBBKBBBK          KKKKKKKKKK                      ]"
        "[                 KKK   KBBBBBBBBBK          KKKKKKKKK   KK                  ]"
        "[                KKKKK  KBBBBBBBBK          KKKKKKKBKK  KBBK                 ]"
        "[               KKKKK  KBBBBBBKBBK          KKKKKKKKKK   KBBK                ]"
        "[               KKKKK  KBBBBBBBBBK         KBKKKKKKKKKK  KBBK                ]"
        "[               KKKKKKKKKKBBBBBBK         KBBBBKKKKKKK  KBBBK                ]"
        "[               KKKKKKKKKKKKKKKKK         KBBBBBBBBBBBKKBBBBK                ]"
        "[                KKKKKKKKKKKKKKK          KBBBBBBBBBBBBBBBBK                 ]"
        "[                 KKKKKKKKKKKKKK           KBBBBBBBBBBBBBBK                  ]"
        "[                  KKKKKKKKKKKK             KKKBBBBBBBBBKK                   ]"
        "[                    KKKKKKKKK                 KKKKKKKKK                     ]"
        ;

    _Fou(V2 _Pos, int _couleur) : _Piece(_Pos, _couleur)
    {
        setZoomSize(0.80);
        setTypePiece(3);
        if (_couleur == 1)
            setTexture(fouBlanc);
        else
            setTexture(fouNoir);
    }
};
struct _Pion : public _Piece {
    string pionBlanc ="[       KKKKKK                     ]"          
        "[      K445445KK                   ]"
        "[     K44545445KK                  ]"
        "[    K445554544KK                  ]"
        "[    KKK444KTTTK                   ]"
        "[    K45454TKKTK                   ]"
        "[    KK45KKTWKTKK        KKKKKK    ]"
        "[     K4KTKTTTTTK       K4GSSSGK   ]"
        "[     K4KTTTTTTK       K4GSSSSSGK  ]"
        "[      KTKTTTTJK      KGSWKKKKKWGK ]"
        "[     KTTTKTTTTK      KGWK     KW4 ]"
        "[    KLTTTTKTTWJK    K4WK       KSK]"
        "[   KJATTTTTTTTKJK   KGWK       KGK]"
        "[  KJLLATTTTTALKJK   KSWK        4K]"
        "[ KJLJLA9TTTTT9KJK   K8WK        KK]"
        "[ KJLAJLA99TTT9JKKK  KWSK         K]"
        "[KJLAALLLL99T9ALKLK K8WG          K]"
        "[KJKJLLJLLJA99JLKAKKKGSK           ]"
        "[KKJJKJKJLLLJLAJKTTTTKK            ]"
        "[KJLJJLJLLLAALLJKTTTTK             ]"
        "[KLAALKJLLLALLLJKTTTTK             ]"
        "[KLAL9LJJLLLLLLKKGTTTK             ]"
        "[KLL9ALJJLLLALJKG8KTTK             ]"
        "[KLAALLJJJLLALLGWGKTTK             ]"
        "[KLL99JJJJJLJJGWGKTTJ              ]"
        "[KLAAJLLJJLLJG8SKLTTJ              ]"
        "[KLAAJLJTTJJTTJJJJTJ               ]"
        "[KLLJLLJTTTTTTTJKKK                ]"
        "[ KLKLKTTTTTTTTK                   ]"
        "[ KKKKKKKTTTTTKK                   ]"
        "[ KJJLJJKKKKKKJK                   ]"
        "[ KJLLLLKWS4KJLJK                  ]"
        "[ KJLLALK8GKJLLJK                  ]"
        "[ KJLLALJKKJJLLJK                  ]"
        "[ KJLLALLJLLJLLJK                  ]"
        "[ KJLLJALLLLJLLJK                  ]"
        "[ KJJLJLJJALJJLLK                  ]"
        "[  KJKJKJ%KKJJKKK                  ]"
        "[  KJJJ%%%%JJ%%K                   ]"
        "[  KJJ%%%U%JJ%UK                   ]"
        "[  KJJ%%%U%JJ%UK                   ]"
        "[   KJ%%%UUJJU%K                   ]"
        "[   KJ%%UU%J%U%K                   ]"
        "[   KJJ%U%%J%U%K                   ]"
        "[   KJ%J%%JJ%%%K                   ]"
        "[   K%%%%%JJ%U%K                   ]"
        "[  KJ%%%%%JJ%%%K                   ]"
        "[  KJ%%%U%JKKKKKK                  ]"
        "[  KJ%%%U%JKGSGGK                  ]"
        "[  KKKKKKKKKKK4GK                  ]"
        "[  KGS8SGGKKK4KGK                  ]"
        "[  KKKKK4GK4G8GK                   ]"
        "[  K4SGGKGK4S8SK                   ]"
        "[  KG8SGKKK4GSGK                   ]"
        "[  KG8SGK K4GSGK                   ]"
        "[  K48SGK KKGSGK                   ]"
        "[  K4GSGK K4GGSKKKK                ]"
        "[  KKGSGK K44SGSS8GK               ]"
        "[  KKSGSKKKKKK44GS8SK              ]"
        "[ KKGGSGSS8GKKKKKKKKK              ]"
        "[ KKG4G4GGS8SK   KKK               ]"
        "[  KKKKKKKKKKK                     ]"
        
        ;

    string pionNoir = 
        "[       KKKKKK                     ]"          
        "[      K445445KK                   ]"
        "[     K44545445KK                  ]"
        "[    K445554544KK                  ]"
        "[    KKK444KTTTK                   ]"
        "[    K45454TKKTK                   ]"
        "[    KK45KKTWKTKK        KKKKKK    ]"
        "[     K4KTKTTTTTK       K4GSSSGK   ]"
        "[     K4KTTTTTTK       K4GSSSSSGK  ]"
        "[      KTKTTTTJK      KGSWKKKKKWGK ]"
        "[     KTTTKTTTTK      KGWK     KW4 ]"
        "[    K?TTTTKTTWEK    K4WK       KSK]"
        "[   KENTTTTTTTTKEK   KGWK       KGK]"
        "[  KE??NTTTTTALKEK   KSWK        4K]"
        "[ KE?E?N9TTTTT9KEK   K8WK        KK]"
        "[ KE?NE?N99TTT9EKKK  KWSK         K]"
        "[KE?NN????99T9N?K?K K8WG          K]"
        "[KEKE??E??EN99E?KNKKKGSK           ]"
        "[KKEEKEKE???E?NEKTTTTKK            ]"
        "[KE?EE?E???NN??EKTTTTK             ]"
        "[K?NN?KE???N???EKTTTTK             ]"
        "[K?N?9?EE??????KKGTTTK             ]"
        "[K??9N?EE???N?EKG8KTTK             ]"
        "[K?NN??EEE??N??GWGKTTK             ]"
        "[K??99EEEEE?EEGWGKTTE              ]"
        "[K?NNE??EE??EG8SK?TTE              ]"
        "[K?NNE?ETTEETTEEEETE               ]"
        "[K??E??ETTTTTTTEKKK                ]"
        "[ K?K?KTTTTTTTTK                   ]"
        "[ KKKKKKKTTTTTKK                   ]"
        "[ KEE?EEKKKKKKEK                   ]"
        "[ KE????KWS4KE?EK                  ]"
        "[ KE??N?K8GKE??EK                  ]"
        "[ KE??N?EKKEE??EK                  ]"
        "[ KE??N??E??E??EK                  ]"
        "[ KE??EN????E??EK                  ]"
        "[ KEE?E?EEN?EE??K                  ]"
        "[  KJKJKJ%KKJJKKK                  ]"
        "[  KJJJ%%%%JJ%%K                   ]"
        "[  KJJ%%%U%JJ%UK                   ]"
        "[  KJJ%%%U%JJ%UK                   ]"
        "[   KJ%%%UUJJU%K                   ]"
        "[   KJ%%UU%J%U%K                   ]"
        "[   KJJ%U%%J%U%K                   ]"
        "[   KJ%J%%JJ%%%K                   ]"
        "[   K%%%%%JJ%U%K                   ]"
        "[  KJ%%%%%JJ%%%K                   ]"
        "[  KJ%%%U%JKKKKKK                  ]"
        "[  KJ%%%U%JKGSGGK                  ]"
        "[  KKKKKKKKKKK4GK                  ]"
        "[  KGS8SGGKKK4KGK                  ]"
        "[  KKKKK4GK4G8GK                   ]"
        "[  K4SGGKGK4S8SK                   ]"
        "[  KG8SGKKK4GSGK                   ]"
        "[  KG8SGK K4GSGK                   ]"
        "[  K48SGK KKGSGK                   ]"
        "[  K4GSGK K4GGSKKKK                ]"
        "[  KKGSGK K44SGSS8GK               ]"
        "[  KKSGSKKKKKK44GS8SK              ]"
        "[ KKGGSGSS8GKKKKKKKKK              ]"
        "[ KKG4G4GGS8SK   KKK               ]"
        "[  KKKKKKKKKKK                     ]"

        ;

    _Pion(V2 _Pos, int _couleur) : _Piece(_Pos, _couleur)
    {
        setZoomSize(1.2);
        setTypePiece(0);
        if (_couleur == 1)
            setTexture(pionBlanc);
        else
            setTexture(pionNoir);
    }
};
struct Dessin {
    string roiNoir =
        "[  K  KKKKKKK  K  ]"
        "[ KOKKRORRRORKKOK ]"
        "[ KOOROOOROOOROOK ]"
        "[ KOOOOOOOOOOOOOK ]"
        "[ KWAWAAWAWAAWAWK ]"
        "[ KOOOOOOOOOOOOOK ]"
        "[ KJTWRTTTTTRWTJK ]"
        "[ KJTWKTTTTTKWTJK ]"
        "[KJTTWWTTTTTWWTTJK]"
        "[KJTTTTJJJJJTTTTJK]"
        "[KJJJTJTTTTTJTJJJK]"
        "[ KJJTJTTJTTJTJJK ]"
        "[  KJJJJJJJJJJJK  ]"
        "[  KKJJJJJJJJJSK  ]"
        "[ Y KSSSSCSSSSKK  ]"
        "[YAY KKKSCSKKKWK  ]"
        "[ YKPWWWSCSWWWPK  ]"
        "[ GKPPPWSCSWPPPK  ]"
        "[ YPPPPWBCBWPPPK  ]"
        "[ G KPPWMMMWPPKK  ]"
        "[ G KPPWBCBWPPTK  ]"
        "[ G KPPWBCBWPPK   ]"
        "[ G KPPWBCBWPPK   ]"
        "[ G KPPWBCBWPPK   ]"
        "[ G KKKWBCBWKKK   ]"
        "[      KKKKK      ]";

    string roiBlanc = "[  K  KKKKKKK  K  ]"
        "[ KYKKRYRRRYRKKYK ]"
        "[ KYYRYYYRYYYRYYK ]"
        "[ KYYYYYYYYYYYYYK ]"
        "[ KWAWAAWAWAAWAWK ]"
        "[ KYYYYYYYYYYYYYK ]"
        "[ KGTWDTTTTTDWTGK ]"
        "[ KGTWDTTTTTDWTGK ]"
        "[KGTTWWTTTTTWWTTGK]"
        "[KGTTTTGGGGGTTTTGK]"
        "[KGGGTGTTTTTGTGGGK]"
        "[ KGGTGTTGTTGTGGK ]"
        "[  KGGGGGGGGGGGK  ]"
        "[  KKGGGGGGGGGSK  ]"
        "[ Y KSSSSCSSSSKK  ]"
        "[YAY KKKSCSKKKWK  ]"
        "[ YKRWWWSCSWWWRK  ]"
        "[ GKRRRWSCSWRRRK  ]"
        "[ YRRRRWBCBWRRRK  ]"
        "[ G KRRWMMMWRRKK  ]"
        "[ G KRRWBCBWRRTK  ]"
        "[ G KRRWBCBWRRK   ]"
        "[ G KRRWBCBWRRK   ]"
        "[ G KRRWBCBWRRK   ]"
        "[ G KKKWBCBWKKK   ]"
        "[      KKKKK      ]";

    string reineBlanche =
        "[            U            ]"
        "[           UVU           ]"
        "[           UVU           ]"
        "[        YOUUUUUOY        ]"
        "[       OUUUUUUUUYO       ]"
        "[      OYOOOYYYYOYO       ]"
        "[      OYYOOOOYOOYYO      ]"
        "[      OYOTTTOOTTOYO      ]"
        "[     OYOTTTTTTTTTOYO     ]"
        "[     OYYTBWTTTWBWYYO     ]"
        "[     OYYTBBTTTBBWYYO     ]"
        "[      OYHHTTTTTHHYO      ]"
        "[     OYYOTTTTTTTOYYO     ]"
        "[    OYYYYOTTRRTOYYYYO    ]"
        "[   OYOWOOOOTTTOOOOWOYO   ]"
        "[   OYOWWWTTTTTTTWWWOYO   ]"
        "[  OYYOOXWWWWTWWWWXOOYYO  ]"
        "[  OYOXXXIWWWWWWWIXXXOYO  ]"
        "[   OXXXXIIIIWIIIIXXXXO   ]"
        "[    XXXOIIIIIIIIIOXXX    ]"
        "[   XXXOYOIIIIIIIOYOXXX   ]"
        "[  XXXOYYOIIIIIIIOYYOXXX  ]"
        "[ TTT  OO HIIIIIH OO  TTT ]"
        "[ TTT    HHHIIIHHH    TTT ]"
        "[       HHHHHIHHHHH       ]"
        "[       HHXHHHHHXHH       ]"
        "[      HHXXXHHHXXXHH      ]"
        "[      HZXXXXHXXXXZH      ]"
        "[      HZXXXZHZXXXZH      ]"
        "[      ZXXXZXXXZXXXZ      ]"
        "[      ZXXXZXXXZXXXZ      ]"
        "[     ZXXXZXXXXXZXXXZ     ]"
        "[    ZXXXXZXXXXXZXXXXZ    ]"
        "[    ZXXXXZXXXXXZXXXXZ    ]"
        "[   ZXXXXZXXXXXXXZXXXXZ   ]"
        "[   ZXXXXZXXXXXXXZXXXXZ   ]"
        "[  ZXXXXZXXXXXXXXXZXXXXZ  ]"
        "[ ZXXXXZXXXXXXXXXXXZXXXXZ ]"
        "[ ZXXXZXXXXXXXXXXXXXZXXXZ ]"
        "[ZXXXZXXXXXXXXXXXXXXXZXXXZ]"
        "[ZXXZXXXXXXXXXXXXXXXXXZXXZ]"
        "[ ZXZXXXXXXXXXXXXXXXXXZXZ ]"
        "[  ZZZZZXXXXXXXXXXXZZZZZ  ]"
        "[       ZZZZZZZZZZZ       ]"; 

    string reineNoire =
        "[            U            ]"
        "[           UVU           ]"
        "[           UVU           ]"
        "[        LFUUUUUFL        ]"
        "[       FUUUUUUUULF       ]"
        "[      FLFFFLLLLFLF       ]"
        "[      FLLFFFFLFFLLF      ]"
        "[      FLFTTTFFTTFLF      ]"
        "[     FLFTTTTTTTTTFLF     ]"
        "[     FLLTQVTTTVQTLLF     ]"
        "[     FLLTQQTTTQQTLLF     ]"
        "[      FLCCTTTTTCCLF      ]"
        "[     FLLFTTTTTTTFLLF     ]"
        "[    FLLLLFTTRRTFLLLLF    ]"
        "[   FLFWFFFFTTTFFFFWFLF   ]"
        "[   FLFWWWTTTTTTTWWWFLF   ]"
        "[  FLLFFNWWWWTWWWWNFFLLF  ]"
        "[  FLFNNNEWWWWWWWENNNFLF  ]"
        "[   FNNNNEEEEWEEEENNNNF   ]"
        "[    NNNFEEEEEEEEEFNNN    ]"
        "[   NNNFLFEEEEEEEFLFNNN   ]"
        "[  NNNFLLFEEEEEEEFLLFNNN  ]"
        "[ TTT  FF CEEEEEC FF  TTT ]"
        "[ TTT    CCCEEECCC    TTT ]"
        "[       CCCCCECCCCC       ]"
        "[       CCNCCCCCNCC       ]"
        "[      CCNNNCCCNNNCC      ]"
        "[      CBNNNNCNNNNBC      ]"
        "[      CBNNNBCBNNNBC      ]"
        "[      BNNNBNNNBNNNB      ]"
        "[      BNNNBNNNBNNNB      ]"
        "[     BNNNBNNNNNBNNNB     ]"
        "[    BNNNNBNNNNNBNNNNB    ]"
        "[    BNNNNBNNNNNBNNNNB    ]"
        "[   BNNNNBNNNNNNNBNNNNB   ]"
        "[   BNNNNBNNNNNNNBNNNNB   ]"
        "[  BNNNNBNNNNNNNNNBNNNNB  ]"
        "[ BNNNNBNNNNNNNNNNNBNNNNB ]"
        "[ BNNNBNNNNNNNNNNNNNBNNNB ]"
        "[BNNNBNNNNNNNNNNNNNNNBNNNB]"
        "[BNNBNNNNNNNNNNNNNNNNNBNNB]"
        "[ BNBNNNNNNNNNNNNNNNNNBNB ]"
        "[  BBBBBNNNNNNNNNNNBBBBB  ]"
        "[       BBBBBBBBBBB       ]";


    string tourRouge =
        "[            YY            ]"
        "[            II            ]"
        "[           IIII           ]"
        "[           IIII           ]"
        "[          IIIIII          ]"
        "[          J2222J          ]"
        "[      Y   J2JJ2J   Y      ]"
        "[      I   J2JJ2J   I      ]"
        "[      I   J2222J   I      ]"
        "[     III  J2222J  III     ]"
        "[     III  J2JJ2J  III     ]"
        "[    IIIII J2JJ2J IIIII    ]"
        "[    J222J J2222J J222J    ]"
        "[    J2J2JJJJJJJJJJ2J2J    ]"
        "[  Y J2J2J22222222J2J2J Y  ]"
        "[  I J2J2J222JJ222J2J2J I  ]"
        "[  I J222J22JNNJ22J222J I  ]"
        "[ IIIJ222J22JNNJ22J222JIII ]"
        "[ IIIJ222J222JJ222J222JIII ]"
        "[IIIII222J22222222J222IIII ]"
        "[J222J222J22222222J222J222J]"
        "[J222J2JJJ2JJJ2JJJJJJJJ222J]"
        "[J222JJJ2JJJ2JJJ2JJJ2JJ222J]"
        "[J222J2222222222222222J222J]"
        "[J2J2J2222222222222222J2J2J]"
        "[J2J2J2222222222222222J2J2J]"
        "[J2J2J2222222112222222J2J2J]"
        "[J222J2222221//1222222J222J]"
        "[J222J222221////122222J222J]"
        "[J222J222221//1/122222J222J]"
        "[J222J222221//1/122222J222J]"
        "[J222J222221//1/122222J222J]"
        "[J222J222221////122222J222J]"
        "[J222J222221////122222J222J]"
        "[JJJJJJJJJJ111111JJJJJJJJJJ]"
        ;

    string tourNoir = "[            YY            ]"
        "[            ??            ]"
        "[           ????           ]"
        "[           ????           ]"
        "[          ??????          ]"
        "[          J++++J          ]"
        "[      Y   J+JJ+J   Y      ]"
        "[      ?   J+JJ+J   ?      ]"
        "[      ?   J++++J   ?      ]"
        "[     ???  J++++J  ???     ]"
        "[     ???  J+JJ+J  ???     ]"
        "[    ????? J+JJ+J ?????    ]"
        "[    J+++J J++++J J+++J    ]"
        "[    J+J+JJJJJJJJJJ+J+J    ]"
        "[  Y J+J+J++++++++J+J+J Y  ]"
        "[  ? J+J+J+++JJ+++J+J+J ?  ]"
        "[  ? J+++J++JVVJ++J+++J ?  ]"
        "[ ???J+++J++JVVJ++J+++J??? ]"
        "[ ???J+++J+++JJ+++J+++J??? ]"
        "[?????+++J++++++++J+++???? ]"
        "[J+++J+++J++++++++J+++J+++J]"
        "[J+++J+JJJ+JJJ+JJJJJJJJ+++J]"
        "[J+++JJJ+JJJ+JJJ+JJJ+JJ+++J]"
        "[J+++J++++++++++++++++J+++J]"
        "[J+J+J++++++++++++++++J+J+J]"
        "[J+J+J++++++++++++++++J+J+J]"
        "[J+J+J+++++++11+++++++J+J+J]"
        "[J+++J++++++1331++++++J+++J]"
        "[J+++J+++++133331+++++J+++J]"
        "[J+++J+++++133131+++++J+++J]"
        "[J+++J+++++133131+++++J+++J]"
        "[J+++J+++++133131+++++J+++J]"
        "[J+++J+++++133331+++++J+++J]"
        "[J+++J+++++133331+++++J+++J]"
        "[JJJJJJJJJJ111111JJJJJJJJJJ]";
    string FouRouge =
        "[                   KKKKKKKKK                                                ]"
        "[                 KKRRRRRKSSSKKKKK                 KKKKKK                    ]"
        "[                KRRRRRRRRKSKRRRRKKK           KKKKKKKKKKKK                  ]"
        "[               KRRRKRRRRRRKRRRRRKSSK      KKKKKKKKKKKKKKKKK                 ]"
        "[               KRRKSKRRRRRRRRRRRRKKKK   KKSSKKKKKKKKKKKKKSSK                ]"
        "[              KRRRKSSKRRRRRRRRRRRRRRK  KKKKKKKKKKKKSKKKKKKKK                ]"
        "[              KRRRKSKRRRRRRRRRKRRRRRRKKKKKKKKKKKKKSKKKKKKKKKK               ]"
        "[             KRRRRRKRRRRRRRRRKSKRRRRRKKKKKKKKKKKKKKKKKKKKKKKK               ]"
        "[             KRRRRRRRRRRRRRRKSSSKRRRRKKKKKKKKKKKKKKKKKKKKKKKKK              ]"
        "[             KRRRRRRRRRRRRRRRKKKRRRRRKKKKSKKKKKKKKKKKKKKSKKKKK              ]"
        "[            KRRRRRRRRRRKRRRRRRRRRRRRRKKKKSKKKKKKKKKKKKKKSKKKKK              ]"
        "[            KRRRRRRRRRKSKRRRRRRRRRRRRKKKKKKKKKKKKKKKKKKKKKKKKKK             ]"
        "[            KKKRRRRRKKKSSKRRRRRRRRRRRRKKKKKKKKSKKKKKKKKKKKKKKKK             ]"
        "[            KSSKRRKK   KKRRRRRRRKKKRRRKKKKKKKKKSKKKKKKKKKKKKKKK             ]"
        "[            KKSKRK       KRRRRRKSSSKRRKKKKKKKKKKKKKKK  KKKKKKSK             ]"
        "[            KRKKRK       KRRRRRRKSKRRRKKKSKKKKKKKKKK      KKKKK             ]"
        "[            KRRRRK       KRRRRRKKKKKKKKKKKKKKKKKKKK       KKKKK             ]"
        "[             KRRK         KRRKKSSSSSSSKSSSSSSKKKKKK        KKK              ]"
        "[             KRK          KRKSSSSSSSSSSSSSSSSSSKKK          K               ]"
        "[              K            KKSSSSSSSSSSSSSSSSSSKK          KOK              ]"
        "[             KOK           KKSKKKKKSSSSSSKKKKKSK           KOK              ]"
        "[            KOOOK           KSKKKKKKSSSSKKKKKKSK            K               ]"
        "[             KKK            KKKKKKKKSSSSKKKKKKSK                            ]"
        "[                            KSKKKOKKSSSSKKOKKKSK                            ]"
        "[                            KSKKKKKKSSSSKKKKKKSK                            ]"
        "[                            KSKSSSKKSSSSKKSSSKSK                            ]"
        "[                            KSSSSSSSSSSSSSSSSSSK                            ]"
        "[                             KSSSSSSSSSSSSSSSSK                             ]"
        "[                             KSKKKSSSSSSSSKKKSK                             ]"
        "[                             KSSK!KKSSSSKK!KSSK                             ]"
        "[                              KSK!K!KKKK!K!KSK                              ]"
        "[   KK                         KSSKK!K!!K!KKSSK                         KK   ]"
        "[  KGGK                         KSSSKKKKKKSSSK                         KGGK  ]"
        "[ KGGGGK KK                      KKSSSSSSKSKK                      KK KGGGGK ]"
        "[KGGGGGGKGGK             KKKKK     KKKSSKKK     KKKKK             KGGKGGGGGGK]"
        "[KGGGGGGKGK             KRRRRRK    KKKKKKKK    KKKKKKK             KGKGGGGGGK]"
        "[ KKGGGGGGKK           KRRRRRRRKKKKRRKKKKKKKKKKKKKKKKKK           KKGGGGGGKK ]"
        "[   KKKKKKKK           KRRKKKKKKKKRRRRKKKKKKKRRKKKKKKKK           KRKKKKKK   ]"
        "[   KKKKKKKK            KKKKKKKKKRRRRRKKKKKKKKRRRRRRKK            KRRRRRRK   ]"
        "[    KKKKKKK           KKKKKKKKKRRRKRRKKKKKKKKKRRRRRRRK           KRRRRRK    ]"
        "[    KKKRKKKK         KKKKKKKKKOKRKKKRRKKKRKKKOKRRRRRRRK         KRRKRRRK    ]"
        "[    KKKKKKKK        KKKKKKRKKKOOKKKRRRKKKKRKOOKRRRKRRRRK        KRRRRRRK    ]"
        "[     KKKKKKKK      KKKKKKKKKKKKKKKOKRKKKKOKRKKKRRRRRRRRRK      KRRRRRRK     ]"
        "[     KKKKKKKKK   KKKKRKKKKKKKKKKKKOOKKRKOOKRRRRRRRRRRRRRRKK   KRRRRRRRK     ]"
        "[      KKKKKRKKKKKKKKKKKKKKKKKKKKKKKKKKRRKKKRRRRRRRRRRRRRRRRKKKRRRRRRKK      ]"
        "[      KKKKKKKKKKKKKKKKKKKKKKKKKRKKKKKKRRRRRRRRRRRRRRRRKRRRRRRRRRRRRRRK      ]"
        "[       KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKRRRRRRRRKRRRKKRRRRRRRRRKRRRRRRK       ]"
        "[        KKKKKKKKKKKKKKKKK  KKKKKKKKKKKRRRRRRRRRRRK  KRRRRRRRRRRRRRRK        ]"
        "[         KKKKKKKRKKKKKKK   KKKKKKKRKKKRRRRRRRRRRRK   KRRRRRRRRRRRRK         ]"
        "[          KKKKKKKKKKKKK    KKKKKKKKKKKRRRRRRRRRRK     KRRRKRRRRRRK          ]"
        "[           KKKKKKKKKKK     KKKKKKKKKKKKRRRRRRRRRK      KKKKKKKKKK           ]"
        "[                           KKKKKKKKKKKKRRRRRRRRRK                           ]"
        "[                           KKKKRKKKKKKKRRKRRRRRRK                           ]"
        "[                          KKKKKKKKKKKKKRRRRRRRRRRK                          ]"
        "[                          KKKKKKKKKKKKKRRRRRKRRRRK                          ]"
        "[                          KKKKKKKKKKKKKRRRRRRRRRRK                          ]"
        "[                         KKKRKKKKKKKRKKRRRRRRRRRRRK                         ]"
        "[                         KKKKKKKKKKKKKKRRRRRRRRKRRK                         ]"
        "[                         KKKKKKKKKKKKKKRRRRRRRRRRRRK                        ]"
        "[                         KKKKKKKKKKKKKKRRRRRRRRRRRRK                        ]"
        "[                        KKKKKKKKKRKKKKKRRRKRRRRRRRRK                        ]"
        "[                        KKRKKKKKKKKKKKRRRRRRRRRRRRRRK                       ]"
        "[                        KKKKKKKKKKKKKKRRRRRRRRRRKRRRRK                      ]"
        "[                       KKKKKKKKKKKKKKKRRRRRRRRRRRRRRRK                      ]"
        "[                       KKKKKKKKKKKKKKKRRRRRRKKRRRRRRRK                      ]"
        "[                       KKKKRKKKKKKKKKKRRRRRKKKKRRRRRK                       ]"
        "[                       KKKKRKKKKKKKRKKRRRRRKKKKKRRRRK                       ]"
        "[                       KKKKRRKKKKKRRKKKRRRKKKKKKKRRRK                       ]"
        "[                       KKKKRRKKKKRRRRKKKRKKKKRKKKKRK                        ]"
        "[                       KKKKRRRKKKRRRRKKKRKKKKKKKKKK                         ]"
        "[                       KKKKKRRKKKRRKRKKKKKKKKKKKKKOK                        ]"
        "[                        K  KRRRKRRRRRKKKOKKKKKKKKOOOK                       ]"
        "[                       KOK KRRKOKRRRRKKOOOKKKKKKKKKKK                       ]"
        "[                       KOK KRRKOKRRRRRKKKKKKKRKKKKKKKK                      ]"
        "[                        K  KRRRKRRRRRRKKRKKKKKKKKKKKRKK                     ]"
        "[                          KRRRRRRRRRRKKKKKKKKKKKKKKKKKKK                    ]"
        "[                          KRRRRRKRRRK     KKKKKKKKKKKKKK                    ]"
        "[                          KRRRRRRRRRK       KKKKKRKKKKKK                    ]"
        "[                          KRKRRRRRRK         KKKKKKKKKKK                    ]"
        "[                         KRRRRRRRRRK          KKKKKKKKKK                    ]"
        "[                         KRRRRRRRRK           KKKKKKKKK                     ]"
        "[                         KRRRRRRKRK          KKKKKKKRKK                     ]"
        "[                        KRRRRRRRRRK          KKKKKKKKK                      ]"
        "[                        KRKRRRRRRK          KKRKKKKKKK                      ]"
        "[                        KRRRRKRRRK          KKKKKKKKKK                      ]"
        "[                 KKK   KRRRRRRRRRK          KKKKKKKKK   KK                  ]"
        "[                KKKKK  KRRRRRRRRK          KKKKKKKRKK  KRRK                 ]"
        "[               KKKKK  KRRRRRRKRRK          KKKKKKKKKK   KRRK                ]"
        "[               KKKKK  KRRRRRRRRRK         KRKKKKKKKKKK  KRRK                ]"
        "[               KKKKKKKKKKRRRRRRK         KRRRRKKKKKKK  KRRRK                ]"
        "[               KKKKKKKKKKKKKKKKK         KRRRRRRRRRRRKKRRRRK                ]"
        "[                KKKKKKKKKKKKKKK          KRRRRRRRRRRRRRRRRK                 ]"
        "[                 KKKKKKKKKKKKKK           KRRRRRRRRRRRRRRK                  ]"
        "[                  KKKKKKKKKKKK             KKKRRRRRRRRRKK                   ]"
        "[                    KKKKKKKKK                 KKKKKKKKK                     ]";
};

struct deplacement {
    V2 start;
    V2 Fin;
    int indexP;
    int couleur;
    deplacement(V2 pS, V2 pF)
    {
        start = pS;
        Fin = pF;

    }
    deplacement(V2 pS, V2 pF, int pP)
    {
        start = pS;
        Fin = pF;
        indexP = pP;
    }
    deplacement(V2 pS, V2 pF, int pP, int pcouleur)
    {
        start = pS;
        Fin = pF;

        couleur = pcouleur;
    }
};
struct GameData {

    int ecran = 0;
    int joueur;
    int joueurIa;
    _plateau Plateau;
    bool Mur(int x, int y) { return Plateau.Map1[(8- y - 1) * 8 + x] == 'M'; }
    int xMouse;
    int yMouse;
    int Lpix = 80;
    V2 Size;
    int IdTexMur;
    int IdTexSol;
    int IdTexPossible;
    deplacement test = deplacement(V2(), V2());
    vector<V2> zonesJouables = {};
    
    bool mouseIsActive = false;
    int getJoueur() { return joueur; }
    void setJoueur() {
        if (joueur == 1) 
        { 
            joueur = 2; 
        }
        else { joueur = 1; }
    }
    void setMouseIsActive(bool _mouseIsActive) { mouseIsActive = _mouseIsActive; }
    vector<_Piece> pieces = {};
    int pieceEncours=-1;
    void setPieces() {
        pieces.clear();

        pieces.push_back(_Pion(V2(0, 6), 2));
        pieces.push_back(_Pion(V2(1, 6), 2));
        pieces.push_back(_Pion(V2(2, 6), 2));
        pieces.push_back(_Pion(V2(3, 6), 2));
        pieces.push_back(_Pion(V2(4, 6), 2));
        pieces.push_back(_Pion(V2(5, 6), 2));
        pieces.push_back(_Pion(V2(6, 6), 2));
        pieces.push_back(_Pion(V2(7, 6), 2));



        pieces.push_back(_Tour(V2(0, 7), 2));
        pieces.push_back(_Tour(V2(7, 7), 2));
        pieces.push_back(_Cavalier(V2(1, 7), 2));
        pieces.push_back(_Cavalier(V2(6, 7), 2));
        pieces.push_back(_Fou(V2(2, 7), 2));
        pieces.push_back(_Fou(V2(5, 7), 2));
        pieces.push_back(_Dame(V2(3, 7), 2));
        pieces.push_back(_Roi(V2(4, 7), 2));

        pieces.push_back(_Pion(V2(0, 1), 1));
        pieces.push_back(_Pion(V2(1, 1), 1));
        pieces.push_back(_Pion(V2(2, 1), 1));
        pieces.push_back(_Pion(V2(3, 1), 1));
        pieces.push_back(_Pion(V2(4, 1), 1));
        pieces.push_back(_Pion(V2(5, 1), 1));
        pieces.push_back(_Pion(V2(6, 1), 1));
        pieces.push_back(_Pion(V2(7, 1), 1));


        pieces.push_back(_Tour(V2(0, 0), 1));
        pieces.push_back(_Tour(V2(7, 0), 1));
        pieces.push_back(_Cavalier(V2(1, 0), 1));
        pieces.push_back(_Cavalier(V2(6, 0), 1));
        pieces.push_back(_Fou(V2(2, 0), 1));
        pieces.push_back(_Fou(V2(5, 0), 1));
        pieces.push_back(_Dame(V2(3, 0), 1));
        pieces.push_back(_Roi(V2(4, 0), 1));


        for (_Piece& piece : pieces) {
            piece.IdTex = G2D::InitTextureFromString(piece.Size, piece.Texture); 
            piece.Size = piece.Size * piece.Zoom;
        }
    }
    GameData() {}
};
GameData G;

   

bool DeplacementPiece(_Piece Piece, V2 pNewPos){
    //0 = pion, 1 = tour, 2 = cavalier, 3 = fou, 4 =dame , 5 = roi, 6 = roi pour test
    V2 vCoord = Piece.getCoord();
    if (vCoord == pNewPos)
        return false;
    if (Piece.getTypePiece() == 0)//pion
    {
        if (((((vCoord + V2(0, 1)==pNewPos )|| (vCoord + V2(0, 2) == pNewPos && vCoord.y == 1 && G.Plateau.getPositionPiece(vCoord + V2(0, 1))==0)) && Piece.getCouleur() == 1 )|| (((vCoord + V2(0,-1) == pNewPos) || (vCoord + V2(0, -2) == pNewPos && vCoord.y == 6) && G.Plateau.getPositionPiece(vCoord + V2(0, -1)) == 0) && Piece.getCouleur() == 2) || (((vCoord + V2(1,1) == pNewPos) || vCoord + V2(-1, 1) == pNewPos) && Piece.getCouleur() == 1) || (((vCoord + V2(1, -1) == pNewPos) || vCoord + V2(-1, -1) == pNewPos) && Piece.getCouleur() == 2)) && pNewPos.x >= 0 && pNewPos.x < 8 && pNewPos.y >= 0 && pNewPos.y < 8) {
            if (G.Plateau.getPositionPiece(pNewPos) == 0 && vCoord.x == pNewPos.x) {
                return true;
            }
            else if(G.Plateau.getPositionPiece(pNewPos) != 0 && G.Plateau.getPositionPiece(pNewPos) != Piece.getCouleur() && vCoord.x != pNewPos.x){
                return true;
            }
        }
        return false;
    }
    if (Piece.getTypePiece() == 1)//tour
    {
        //Si horizontal
        if (vCoord.x != pNewPos.x && vCoord.y == pNewPos.y && pNewPos.x >= 0 && pNewPos.x < 8 && pNewPos.y >= 0 && pNewPos.y < 8) {
            //Test droite
            if (vCoord.x < pNewPos.x) {
                for (int i = vCoord.x + 1; i <= pNewPos.x; i++)
                {
                    if (G.Plateau.getPositionPiece(V2(i, pNewPos.y)) == 0 || G.Plateau.getPositionPiece(V2(i, pNewPos.y))!= Piece.getCouleur()) {
                        if (i == pNewPos.x)
                            return true;
                        else if (G.Plateau.getPositionPiece(V2(i, pNewPos.y)) != 0)
                            return false;
                    }
                    else
                        return false;
                }
            }
            //Test gauche
            else if (vCoord.x > pNewPos.x) {
                for (int i = vCoord.x - 1; i >= pNewPos.x; i--)
                {
                    if (G.Plateau.getPositionPiece(V2(i, pNewPos.y)) == 0 || G.Plateau.getPositionPiece(V2(i, pNewPos.y)) != Piece.getCouleur()) {
                        if (i == pNewPos.x)
                            return true;
                        else if (G.Plateau.getPositionPiece(V2(i, pNewPos.y)) != 0)
                            return false;
                    }
                    else
                        return false;
                }
            }
        }

        //Si vertical
        if (vCoord.y != pNewPos.y && vCoord.x == pNewPos.x && pNewPos.x >= 0 && pNewPos.x < 8 && pNewPos.y >= 0 && pNewPos.y < 8) {

            //Teste bas
            if (vCoord.y < pNewPos.y) {
                for (int i = vCoord.y + 1; i <= pNewPos.y; i++)
                {
                    if (G.Plateau.getPositionPiece(V2(pNewPos.x, i)) == 0 || G.Plateau.getPositionPiece(V2(pNewPos.x, i)) != Piece.getCouleur()) {
                        if (i == pNewPos.y)
                            return true;
                        else if (G.Plateau.getPositionPiece(V2(pNewPos.x, i)) != 0)
                            return false;
                    }
                    else
                        return false;                    
                }
            }

            //Teste haut
            else if (vCoord.y > pNewPos.y) {
                for (int i = vCoord.y - 1; i >= pNewPos.y; i--)
                {
                    if (G.Plateau.getPositionPiece(V2(pNewPos.x, i)) == 0 || G.Plateau.getPositionPiece(V2(pNewPos.x, i)) != Piece.getCouleur()) {
                        if (i == pNewPos.y)
                            return true;
                        else if (G.Plateau.getPositionPiece(V2(pNewPos.x, i)) != 0)
                            return false;
                    }
                    else
                        return false;
                }
            }
        }
        return false;
    }
    if (Piece.getTypePiece() == 2)//cavalier
    {
        if ((vCoord + V2(2, 1) == pNewPos || vCoord + V2(1, 2) == pNewPos || vCoord + V2(-2, -1) == pNewPos || vCoord + V2(-1, -2) == pNewPos || vCoord + V2(2, -1) == pNewPos || vCoord + V2(-2, 1) == pNewPos || vCoord + V2(1, -2) == pNewPos || vCoord + V2(-1, 2) == pNewPos) && pNewPos.x >= 0 && pNewPos.x < 8 && pNewPos.y >= 0 && pNewPos.y < 8)
            if (G.Plateau.getPositionPiece(pNewPos) != Piece.getCouleur())
                return true;
        return false;
    }
    if (Piece.getTypePiece() == 3)//fou
    {
        //Initialisation des positions actuelles de la pi�ce et de la distance entre d�part et arriv�e.
        int pos_x = 0;
        int pos_y = 0;
        int nb_move = 0;

        //Verifie si le mouvement est une diagonale
        if (abs(pNewPos.x - vCoord.x) == abs(pNewPos.y - vCoord.y) && pNewPos.x >= 0 && pNewPos.x < 8 && pNewPos.y >= 0 && pNewPos.y < 8) {
            pos_x = vCoord.x;
            pos_y = vCoord.y;

            if (vCoord.x < pNewPos.x && vCoord.y < pNewPos.y) {
                pos_x = vCoord.x + 1;
                pos_y = vCoord.y + 1;

                // V�rification si le mouvement est valide case par case (diagonale vers haut et droite).
                nb_move = abs(pNewPos.x - vCoord.x);
                for (int i = 0; i <= nb_move; i++) {
                    if (G.Plateau.getPositionPiece(V2(pos_x, pos_y)) == 0 || G.Plateau.getPositionPiece(V2(pos_x, pos_y)) != Piece.getCouleur()) {
                        if (pos_x == pNewPos.x && pos_y == pNewPos.y)
                            return true;
                        else if (G.Plateau.getPositionPiece(V2(pos_x, pos_y)) != 0)
                            return false;
                    }
                    else
                        return false;
                    pos_x++;
                    pos_y++;
                }
            }

            if (vCoord.x > pNewPos.x && vCoord.y > pNewPos.y) {
                pos_x = vCoord.x - 1;
                pos_y = vCoord.y - 1;

                // V�rification si le mouvement est valide case par case (diagonale vers bas et gauche).
                nb_move = abs(pNewPos.x - vCoord.x);
                for (int i = 0; i <= nb_move; i++) {
                    if (G.Plateau.getPositionPiece(V2(pos_x, pos_y)) == 0 || G.Plateau.getPositionPiece(V2(pos_x, pos_y)) != Piece.getCouleur()) {
                        if (pos_x == pNewPos.x && pos_y == pNewPos.y)
                            return true;
                        else if (G.Plateau.getPositionPiece(V2(pos_x, pos_y)) != 0)
                            return false;
                    }
                    else
                        return false;
                    pos_x--;
                    pos_y--;
                }
            }

            if (vCoord.x < pNewPos.x && vCoord.y > pNewPos.y) {
                pos_x = vCoord.x + 1;
                pos_y = vCoord.y - 1;

                // V�rification si le mouvement est valide case par case (diagonale vers bas et droite).
                nb_move = abs(pNewPos.x - vCoord.x);
                for (int i = 0; i <= nb_move; i++) {
                    if (G.Plateau.getPositionPiece(V2(pos_x, pos_y)) == 0 || G.Plateau.getPositionPiece(V2(pos_x, pos_y)) != Piece.getCouleur()) {
                        if (pos_x == pNewPos.x && pos_y == pNewPos.y)
                            return true;
                        else if (G.Plateau.getPositionPiece(V2(pos_x, pos_y)) != 0)
                            return false;
                    }
                    else
                        return false;
                    pos_x++;
                    pos_y--;
                }
            }

            if (vCoord.x > pNewPos.x && vCoord.y < pNewPos.y) {
                pos_x = vCoord.x - 1;
                pos_y = vCoord.y + 1;

                // V�rification si le mouvement est valide case par case (diagonale vers haut et gauche).
                nb_move = abs(pNewPos.x - vCoord.x);
                for (int i = 0; i <= nb_move; i++) {
                    if (G.Plateau.getPositionPiece(V2(pos_x, pos_y)) == 0 || G.Plateau.getPositionPiece(V2(pos_x, pos_y)) != Piece.getCouleur()) {
                        if (pos_x == pNewPos.x && pos_y == pNewPos.y)
                            return true;
                        else if (G.Plateau.getPositionPiece(V2(pos_x, pos_y)) != 0)
                            return false;
                    }
                    else
                        return false;
                    pos_x--;
                    pos_y++;
                }
            }
        }
        return false;
    }
    if (Piece.getTypePiece() == 4)//dame
    {
        
        return DeplacementPiece(_Tour(Piece.getCoord(),Piece.getCouleur()),pNewPos)|| DeplacementPiece(_Fou(Piece.getCoord(), Piece.getCouleur()), pNewPos);
    }
    if (Piece.getTypePiece() == 5)//roi
    {
        if ((pNewPos.x == vCoord.x + 1 || pNewPos.x == vCoord.x - 1 || pNewPos.x == vCoord.x) && (pNewPos.y == vCoord.y + 1 || pNewPos.y == vCoord.y - 1 || pNewPos.y == vCoord.y) && pNewPos.x >= 0 && pNewPos.x < 8 && pNewPos.y >= 0 && pNewPos.y < 8){
            if (G.Plateau.getPositionPiece(pNewPos) != Piece.getCouleur()) {   
                return true;
            }
        }
        else if (Piece.getNoMove())//TEst pour le roque
        {
            if ((vCoord.y == pNewPos.y && vCoord.x + 2 == pNewPos.x)) {
                if (Piece.getCouleur() == 1 && G.pieces[25].getNoMove() && G.pieces[25].getEstVivant()) {
                    //cout << "maybe" << endl;
                    //cout<< "dernier" << DeplacementPiece(Piece, V2(6, 0));

                    if (DeplacementPiece(G.pieces[25], V2(5, 0)) && DeplacementPiece(Piece, V2(5, 0)))
                    {
                        Piece.setCoord(V2(5, 0));
                        G.Plateau.setPositionPiece(4, 0, "0");
                        G.Plateau.setPositionPiece(5, 0, "1");
                        if (DeplacementPiece(Piece, V2(6, 0)))
                        {
                            G.Plateau.setPositionPiece(4, 0, "1");
                            G.Plateau.setPositionPiece(5, 0, "0");
                            Piece.setCoord(V2(4, 0));
                            return true;
                        }
                        G.Plateau.setPositionPiece(4, 0, "1");
                        G.Plateau.setPositionPiece(5, 0, "0");
                        Piece.setCoord(V2(4, 0));
                        return false;
                    }
                }
                else if (Piece.getCouleur() == 2 && G.pieces[9].getNoMove() && G.pieces[9].getEstVivant()) {
                    //cout << "maybe" << endl;
                    //cout<< "dernier" << DeplacementPiece(Piece, V2(6, 0));

                    if (DeplacementPiece(G.pieces[9], V2(5, 7)) && DeplacementPiece(Piece, V2(5, 7)))
                    {
                        
                        Piece.setCoord(V2(5, 7));
                        G.Plateau.setPositionPiece(4, 7, "0");
                        G.Plateau.setPositionPiece(5, 7, "2");
                        if (DeplacementPiece(Piece, V2(6, 7)))
                        {
                            G.Plateau.setPositionPiece(4, 7, "2");
                            G.Plateau.setPositionPiece(5, 7, "0");
                            Piece.setCoord(V2(4, 7));
                            return true;
                        }
                        G.Plateau.setPositionPiece(4, 7, "2");
                        G.Plateau.setPositionPiece(5, 7, "0");
                        Piece.setCoord(V2(4, 7));
                        return false;
                    }
                }
            }
            else if (vCoord.y == pNewPos.y && vCoord.x - 2 == pNewPos.x) {
                if (Piece.getCouleur() == 1 && G.pieces[24].getNoMove() && G.pieces[24].getEstVivant()) {
                    if (DeplacementPiece(G.pieces[24], V2(3, 0)) && DeplacementPiece(Piece, V2(3, 0)))
                    {
                        
                        Piece.setCoord(V2(3, 0));
                        G.Plateau.setPositionPiece(4, 0, "0");
                        G.Plateau.setPositionPiece(3, 0, "1");
                        if (DeplacementPiece(Piece, V2(2, 0)))
                        {
                            G.Plateau.setPositionPiece(4, 0, "1");
                            G.Plateau.setPositionPiece(3, 0, "0");
                            Piece.setCoord(V2(4, 0));
                            return true;
                        }
                        G.Plateau.setPositionPiece(4, 0, "1");
                        G.Plateau.setPositionPiece(3, 0, "0");
                        Piece.setCoord(V2(4, 0));
                        return false;
                    }
                }
                else if (Piece.getCouleur() == 2 && G.pieces[8].getNoMove() && G.pieces[8].getEstVivant()) {
                    //cout << "maybe" << endl;
                    //cout<< "dernier" << DeplacementPiece(Piece, V2(6, 0));

                    if (DeplacementPiece(G.pieces[8], V2(3, 7)) && DeplacementPiece(Piece, V2(3, 7)))
                    {
                        
                        Piece.setCoord(V2(3, 7));
                        G.Plateau.setPositionPiece(4, 7, "0");
                        G.Plateau.setPositionPiece(3, 7, "2");                        
                        if (DeplacementPiece(Piece, V2(2, 7)))
                        {
                            G.Plateau.setPositionPiece(4, 7, "2");
                            G.Plateau.setPositionPiece(3, 7, "0");
                            Piece.setCoord(V2(3, 7));
                            return true;
                        }
                        G.Plateau.setPositionPiece(4, 7, "2");
                        G.Plateau.setPositionPiece(3, 7, "0");
                        Piece.setCoord(V2(3, 7));
                        return false;
                    }
                }
            }
            
        }

        return false;
    }
    if (Piece.getTypePiece() == 6) {
        if ((pNewPos.x == vCoord.x + 1 || pNewPos.x == vCoord.x - 1 || pNewPos.x == vCoord.x) && (pNewPos.y == vCoord.y + 1 || pNewPos.y == vCoord.y - 1 || pNewPos.y == vCoord.y) && pNewPos.x >= 0 && pNewPos.x < 8 && pNewPos.y >= 0 && pNewPos.y < 8) {
            return true;
        }
        return false;
    }
    return false;
}
bool NoSuicideMove(_Piece Piece, V2 pNewPos) {
    char pastPlateau = G.Plateau.getPositionPiece(pNewPos);
    V2 vCoord = Piece.getCoord();
    int leMort = -1; // la piece qui meurt si on joue notre coup
    G.Plateau.setPositionPiece(pNewPos.x, pNewPos.y, to_string(Piece.getCouleur()));
    G.Plateau.setPositionPiece(vCoord.x, vCoord.y, to_string(0));
    if (Piece.getCouleur() == 1) 
    {
        if (!(Piece.getTypePiece()==5)) 
        {
            for (int i = 0; i < 15; i++) 
            {
                if (G.pieces[i].getCoord() == pNewPos && G.pieces[i].getEstVivant())
                {
                    leMort = i;
                    G.pieces[i].setEstVivant(false);
                }
                else if (G.pieces[i].getEstVivant()) 
                {
                    
                    if (DeplacementPiece(G.pieces[i], G.pieces[31].getCoord())) 
                    {
                        G.Plateau.setPositionPiece(pNewPos.x, pNewPos.y, to_string(pastPlateau));
                        G.Plateau.setPositionPiece(vCoord.x, vCoord.y, to_string(Piece.getCouleur()));
                        if (leMort != -1)
                        {
                            G.pieces[leMort].setEstVivant(true);

                        }
                        return false;
                    }
                }
            }
            if (leMort != -1)
            {
                G.pieces[leMort].setEstVivant(true);

            }
            G.pieces[15].setTypePiece(6);

            if (DeplacementPiece(G.pieces[15], G.pieces[31].getCoord()))
            {
                G.Plateau.setPositionPiece(pNewPos.x, pNewPos.y, to_string(pastPlateau));
                G.Plateau.setPositionPiece(vCoord.x, vCoord.y, to_string(Piece.getCouleur()));
                G.pieces[15].setTypePiece(5);
                return false;
            }
            G.pieces[15].setTypePiece(5);
        }
        else
        {
            for (int i = 0; i < 15; i++) {
                if (G.pieces[i].getEstVivant()) {

                    if (DeplacementPiece(G.pieces[i], pNewPos)) {
                        G.Plateau.setPositionPiece(pNewPos.x, pNewPos.y, to_string(pastPlateau));
                        G.Plateau.setPositionPiece(vCoord.x, vCoord.y, to_string(Piece.getCouleur()));
                        return false;
                    }
                }
            }
            G.pieces[15].setTypePiece(6);

            if (DeplacementPiece(G.pieces[15], pNewPos))
            {
                G.Plateau.setPositionPiece(pNewPos.x, pNewPos.y, to_string(pastPlateau));
                G.Plateau.setPositionPiece(vCoord.x, vCoord.y, to_string(Piece.getCouleur()));
                G.pieces[15].setTypePiece(5);
                return false;
            }
            G.pieces[15].setTypePiece(5);
        }
        
    }
    else if (Piece.getCouleur() == 2) {
        if (!(Piece.getTypePiece() == 5))
        {
            for (int i = 16; i < 31; i++) {
                if (G.pieces[i].getCoord() == pNewPos && G.pieces[i].getEstVivant())
                {
                    leMort = i;
                    G.pieces[i].setEstVivant(false);
                }
                else if (G.pieces[i].getEstVivant()) {

                    if (DeplacementPiece(G.pieces[i], G.pieces[15].getCoord())) {
                        G.Plateau.setPositionPiece(pNewPos.x, pNewPos.y, to_string(pastPlateau));
                        G.Plateau.setPositionPiece(vCoord.x, vCoord.y, to_string(Piece.getCouleur()));
                        if (leMort != -1)
                        {
                            G.pieces[leMort].setEstVivant(true);

                        }
                        return false;
                    }
                }
            }
            if (leMort != -1)
            {
                G.pieces[leMort].setEstVivant(true);

            }
            G.pieces[31].setTypePiece(6);
            if (DeplacementPiece(G.pieces[31], G.pieces[15].getCoord())) {
                G.Plateau.setPositionPiece(pNewPos.x, pNewPos.y, to_string(pastPlateau));
                G.Plateau.setPositionPiece(vCoord.x, vCoord.y, to_string(Piece.getCouleur()));
                G.pieces[31].setTypePiece(5);
                return false;
            }
            G.pieces[31].setTypePiece(5);
        }
        else 
        {
            for (int i = 16; i < 31; i++) {
                if (G.pieces[i].getEstVivant()) {

                    if (DeplacementPiece(G.pieces[i], pNewPos)) {
                        G.Plateau.setPositionPiece(pNewPos.x, pNewPos.y, to_string(pastPlateau));
                        G.Plateau.setPositionPiece(vCoord.x, vCoord.y, to_string(Piece.getCouleur()));
                        return false;
                    }
                }
            }
            G.pieces[31].setTypePiece(6);
            if (DeplacementPiece(G.pieces[31], pNewPos)) {
                G.Plateau.setPositionPiece(pNewPos.x, pNewPos.y, to_string(pastPlateau));
                G.Plateau.setPositionPiece(vCoord.x, vCoord.y, to_string(Piece.getCouleur()));
                G.pieces[31].setTypePiece(5);
                return false;
            }
            G.pieces[31].setTypePiece(5);
        }

        

    }
    G.Plateau.setPositionPiece(pNewPos.x, pNewPos.y, to_string(pastPlateau));
    G.Plateau.setPositionPiece(vCoord.x, vCoord.y, to_string(Piece.getCouleur()));
    return true;

}
void setZonesJouables(_Piece pieceActuelle) {
    G.zonesJouables.clear();
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            if (DeplacementPiece(pieceActuelle, V2(x, y)))
            {
                if (NoSuicideMove(pieceActuelle, V2(x, y))) 
                {
                    G.zonesJouables.push_back(V2(x, y));
                }
            }
        }
    }
}
//IA 

int point()
{
    int point = 0;
    int zoneAttaque = 0;
    for (int i = 0; i < 32; i++)
    {

        _Piece P = G.pieces[i];
        if (i < 16)
        {
            if (P.estVivant)
            {
                if (P.typePiece == 0) { point += 1; }
                if (P.typePiece == 2) { point += 3; }
                if (P.typePiece == 1) { point += 5; }
                if (P.typePiece == 3) { point += 3; }
                if (P.typePiece == 4) { point += 8; }
                if (P.typePiece == 5) { point += 100; }
                setZonesJouables(P);
                zoneAttaque += G.zonesJouables.size();
            }
        }
        else
        {
            if (P.estVivant)
            {
                if (P.typePiece == 0) { point -= 1; }
                if (P.typePiece == 2) { point -= 3; }
                if (P.typePiece == 1) { point -= 5; }
                if (P.typePiece == 3) { point -= 3; }
                if (P.typePiece == 4) { point -= 8; }
                if (P.typePiece == 5) { point -= 100; }
                setZonesJouables(P);
                zoneAttaque -= G.zonesJouables.size();
            }
        }
    }
    int score = point + zoneAttaque;
    return score;
}
//IA
void Timer(_Piece* piece, int multiplier)
{
    int t = piece->TimeDead + 1 * multiplier;
    piece->TimeDead = t;
}

deplacement changePos(_Piece* piece, V2 pos)
{
    G.Plateau.setPositionPiece(piece->getCoord().x, piece->getCoord().y, "0");
    deplacement D = deplacement(piece->getCoord(), pos, 0, G.Plateau.getPositionPiece(pos));

    for (_Piece& P : G.pieces)
    {
        if (!P.estVivant)
        {
            Timer(&P, 1);
        }
        if (P.pos == pos && P.estVivant)
        {
            P.setEstVivant(!P.getEstVivant());
            P.TimeDead = 0;
            G.Plateau.setPositionPiece(P.pos.x, P.pos.y, "0");
        }

    }

    piece->pos = pos;
    G.Plateau.setPositionPiece(piece->getCoord().x, piece->getCoord().y, std::to_string(piece->getCouleur()));
    return D;
}
void changeBack(deplacement D)
{
    for (_Piece& piece : G.pieces)
    {


        if (piece.pos == D.Fin)
        {
            if (piece.estVivant)
            {
                if (G.Plateau.getPositionPiece(piece.pos))
                {
                    G.Plateau.setPositionPiece(piece.pos.x, piece.pos.y, to_string(D.couleur));
                }
                piece.pos = D.start;
                G.Plateau.setPositionPiece(piece.pos.x, piece.pos.y, to_string(piece.getCouleur()));

            }

        }
        if (!piece.estVivant)
        {
            if (piece.TimeDead == 0)
            {
                piece.setEstVivant(!piece.getEstVivant());
                piece.TimeDead = -1;
                G.Plateau.setPositionPiece(piece.pos.x, piece.pos.y, to_string(piece.couleur));

            }
            else
            {
                Timer(&piece, -1);
            }
        }
        /* if (!G.pieces[17].getEstVivant())
         {
             cout << G.Plateau.getPlateau() << endl;
         }*/
    }
}
void fin()
{
    for (int i = 0; i < 32; i++)
    {
        if (!G.pieces[i].getEstVivant())
        {
            G.pieces[i].TimeDead = 100;
        }
    }
}
void actualisePlateau()
{
    for (int i = 0; i < 32; i++)
    {
        if (G.pieces[i].getEstVivant())
        {
            if (G.pieces[i].couleur == 1)
                G.Plateau.setPositionPiece(G.pieces[i].pos.x, G.pieces[i].pos.y, "3");
            else
                G.Plateau.setPositionPiece(G.pieces[i].pos.x, G.pieces[i].pos.y, "4");
        }
    }
    for (int x = 0; x < 8; x++)
    {
        for (int y = 0; y < 8; y++)
        {
            //cout << G.Plateau.getPositionPiece(V2(x, y)) << endl;
            if (G.Plateau.getPositionPiece(V2(x, y)) == 3)
            {
                G.Plateau.setPositionPiece(x, y, "1");
            }
            else if (G.Plateau.getPositionPiece(V2(x, y)) == 4)
            {
                G.Plateau.setPositionPiece(x, y, "2");
            }
            else
            {
                G.Plateau.setPositionPiece(x, y, "0");
            }
        }

    }
    //cout << G.Plateau.getPlateau() << endl;
}
vector<deplacement> DePossible(int joueur)
{
    vector < deplacement > DP = {};
    if (joueur == 1)
    {
        for (int i = 16; i < 32; i++)
        {
            _Piece vPiece = G.pieces[i];
            for (int k = 0; k < 8; k++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (i == 31 && (abs(vPiece.pos.x - k) < 2))
                    {
                        if (DeplacementPiece(vPiece, V2(k, j)))
                        {
                            if (NoSuicideMove(vPiece, V2(k, j))) {
                                DP.push_back(deplacement(vPiece.pos, V2(k, j), i));
                                // std::cout << "(" << vPiece.pos.x << vPiece.pos.y << ";" << k << j << ")" << endl;
                            }
                        }
                    }
                    else if (i != 31 && DeplacementPiece(vPiece, V2(k, j)) && vPiece.estVivant)
                    {
                        if (NoSuicideMove(vPiece, V2(k, j)) && vPiece.estVivant) {
                            DP.push_back(deplacement(vPiece.pos, V2(k, j), i));
                            //std::cout << "(" << vPiece.pos.x << vPiece.pos.y << ";" << k << j << ")" << endl;
                        }
                    }

                }
            }
        }
        return DP;
    }
    else
    {
        for (int i = 0; i < 16; i++)
        {
            _Piece vPiece = G.pieces[i];
            for (int k = 0; k < 8; k++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (i == 15 && (abs(vPiece.pos.x - k) < 2))
                    {
                        if (DeplacementPiece(vPiece, V2(k, j)))
                        {
                            if (NoSuicideMove(vPiece, V2(k, j))) {
                                DP.push_back(deplacement(vPiece.pos, V2(k, j), i));
                                //std::cout << "(" << vPiece.pos.x << vPiece.pos.y << ";" << k << j << ")" << endl;
                                int p = 0;
                            }   
                        }
                    }
                    else if (i != 15 && DeplacementPiece(vPiece, V2(k, j)))
                    {
                        if (NoSuicideMove(vPiece, V2(k, j))) {
                            DP.push_back(deplacement(vPiece.pos, V2(k, j), i));
                            //std::cout << "(" << vPiece.pos.x << vPiece.pos.y << ";" << k << j << ")" << endl;
                        }
                    }
                }
            }
        }
        return DP;
    }
}
int IaN(int alpha, int beta, bool EMin, bool fils, int depth)
{
    int v;
    deplacement coup = deplacement(V2(9, 9), V2(9, 9));
    if (depth == 0)
    {

        return point();
    }
    if (abs(point() > 500))
    {
        return point();
    }
    else if (EMin)
    {
        v = 2000;
        vector<deplacement> DP = DePossible(1);
        int size = DP.size();
        for (int i = 0; i < size; i++)
        {
            deplacement y = changePos(&G.pieces[DP[i].indexP], DP[i].Fin);
            v = min(v, IaN(alpha, beta, false, true, depth - 1));
            if (alpha > v)
            {
                if (fils)
                {
                    changeBack(y);
                    actualisePlateau();
                    return v;
                }
            }
            beta = min(beta, v);
            changeBack(y);
            actualisePlateau();
        }
    }
    else
    {
        v = -2000;
        vector<deplacement> DP = DePossible(2);
        int size = DP.size();
        for (int i = 0; i < size; i++)
        {
            /*if (!fils)
            {
               // std::cout << i;
            }*/
            coup = DP[0];
            deplacement x = changePos(&G.pieces[DP[i].indexP], DP[i].Fin);
            int m = v;
            v = max(v, IaN(alpha, beta, true, true, depth - 1));
            if (v != m)
                coup = DP[i];
            if (beta < v)
            {

                if (fils)
                {
                    changeBack(x);
                    actualisePlateau();
                    return v;
                }
            }
            alpha = max(beta, v);
            changeBack(x);
            actualisePlateau();
        }
    }
    if (fils)
    {
        return v;
    }
    else
    {
        changePos(&G.pieces[coup.indexP], coup.Fin);
        actualisePlateau();
        fin();
        return v;
    }
}

void affichage_ecran_accueil() {
    G2D::DrawStringFontMono(V2(50, 400), "Jeux d'echec",
        20, 4, Color::White);
    G2D::DrawStringFontMono(V2(80, 300), "Appuyez sur ENTER pour continuer.", 20,
        3, Color::Green);
}
//end

void affichage_ecran_options() {
    G2D::DrawStringFontMono(V2(100, 500), "Choisissez votre difficulte !", 23, 3,
        Color::White);
    G2D::DrawStringFontMono(V2(50, 300),
        "Appuyez sur A pour jouer les blancs contre l'ia", 16, 3,
        Color::Green);
    G2D::DrawStringFontMono(V2(50, 250),
        "Appuyez sur B pour jouer les noirs contre l'ia", 16, 3,
        Color::Yellow);
    G2D::DrawStringFontMono(V2(50, 200),
        "Appuyez sur C pour jouer en JCJ", 16, 3,
        Color::Red);
}
//END

void affichage_init_partie() {
    G2D::DrawStringFontMono(V2(220, 100), "Appuyez sur ENTER", 16, 3, Color::Cyan);
    G2D::DrawCircle(V2(150, 250), 50, Color::Green);
    G2D::DrawCircle(V2(450, 450), 30, Color::Cyan);
    G2D::DrawCircle(V2(250, 550), 60, Color::Blue);
    G2D::DrawCircle(V2(500, 50), 30, Color::Magenta);
}
//ecran chargement
void affichage_ecran_jeu() {
    //TOUS LES AFFICHAGES VISUELS
    for (int x = 0; x < 8; x++)
        for (int y = 0; y < 8; y++) {
            int xx = x * G.Lpix -12;
            int yy = y * G.Lpix;
            if (G.Mur(x, y))
                G2D::DrawRectWithTexture(G.IdTexMur, V2(xx, yy),
                    G.Size);
            else {
                G2D::DrawRectWithTexture(G.IdTexSol, V2(xx, yy),
                    G.Size);
            }
        }
    
    

    //affichage pieces
    for (int i = 0; i<32;i++) {
        if (G.pieces[i].getEstVivant() && i!=G.pieceEncours) 
        {
            G.pieces[i].IdTex = G2D::InitTextureFromString(G.pieces[i].Size, G.pieces[i].Texture);
            G.pieces[i].Size = G.pieces[i].Size * G.pieces[i].Zoom;
            G2D::DrawRectWithTexture(G.pieces[i].IdTex, V2(G.pieces[i].getCoord().x * G.Lpix + 8, G.pieces[i].getCoord().y * G.Lpix + 2), G.pieces[i].Size);
        }
    }
    if (G.pieceEncours != -1) {
        for (V2 position : G.zonesJouables) {
            int xx = position.x * G.Lpix - 12;
            int yy = position.y * G.Lpix;
            G2D::DrawRectWithTexture(G.IdTexPossible, V2(xx, yy),
                G.Size);
        }
    }
    if (G2D::IsMouseLeftButtonPressed())
    {
        if (G.mouseIsActive)
        {
            G.pieces[G.pieceEncours].IdTex = G2D::InitTextureFromString(G.pieces[G.pieceEncours].Size, G.pieces[G.pieceEncours].Texture);
            G.pieces[G.pieceEncours].Size = G.pieces[G.pieceEncours].Size * G.pieces[G.pieceEncours].Zoom * 1.5;
            G2D::DrawRectWithTexture(G.pieces[G.pieceEncours].IdTex, V2((G.xMouse - G.pieces[G.pieceEncours].Size.x / 2), G.yMouse - G.pieces[G.pieceEncours].Size.y / 2), G.pieces[G.pieceEncours].Size);
        }
    }

}
//end
void affichage_ecran_game_over() {
    G2D::DrawStringFontMono(V2(70, 500), "Game over", 80, 10, Color::Red);
    G2D::DrawStringFontMono(V2(50, 200),
        "Appuyez sur ENTER pour faire une autre partie.", 16,
        3, Color::Green);
}
//end

void affichage_ecran_win() {
    G2D::DrawStringFontMono(V2(70, 500), "You WIN !!!!", 80, 10, Color::Green);
    G2D::DrawStringFontMono(V2(50, 200),
        "Appuyez sur ENTER pour faire une autre partie.", 16,
        3, Color::White);
}
//end
void render() {
    G2D::ClearScreen(Color::Black);
    if (G.ecran == ECRAN_ACCUEIL) {
        affichage_ecran_accueil();
    }
    if (G.ecran == ECRAN_OPTIONS) {
        affichage_ecran_options();
    }
    if (G.ecran == INIT_PARTIE) {
        affichage_init_partie();
    }
    if (G.ecran == ECRAN_JEU) {
        affichage_ecran_jeu();
    }
    if (G.ecran == ECRAN_GAME_OVER) {
        affichage_ecran_game_over();
    }
    if (G.ecran == ECRAN_WIN) {
        affichage_ecran_win();
    }
    G2D::Show();
}


int gestion_ecran_accueil() {
    if (G2D::IsKeyPressed(Key::ENTER)) {
        return 1;
    }
    return 0;
}
//end
int gestion_ecran_options() {
    // blanc contre ia
    if (G2D::IsKeyPressed(Key::A)) {
        G.joueurIa = 2;
        return 2;
    }
    // noir contre ia
    if (G2D::IsKeyPressed(Key::B)) {
        G.joueurIa = 1;
        return 2;
    }
    // jCJ
    if (G2D::IsKeyPressed(Key::C)) {

        G.joueurIa = 0;
        return 2;
    }
    return 1;
}
//end

int InitPartie() {
    if (G2D::IsKeyPressed(Key::ENTER)) {
        G.setPieces();
        G.joueur = 1;
        //r�initialise la game
        return 3;
    }
    return 2;
}
//end
int gestion_ecran_jeu() {
    //l'integralit� des fonctionnements gameplay / imput

    //cout << DeplacementPiece(_Pion(V2(6, 1), 1, 0), V2(6, 3)) << endl;
    if (G.getJoueur()==G.joueurIa)
    {
       actualisePlateau();
       IaN(-2000, 2000, false, false, 4);
       G.setJoueur();
    }
    else
    { 
        if (G2D::IsMouseLeftButtonPressed())
        {
            G2D::GetMousePos(&G.xMouse, &G.yMouse);
            if (!G.mouseIsActive)
            {
                if (G.getJoueur())
                {
                    for (int i = 16; i < 32; i++) {
                        if (G.pieces[i].getEstVivant() && G.pieces[i].getCoord() == V2((int)(G.xMouse / 80), (int)(G.yMouse / 80)))
                        {
                            G.pieceEncours = i;
                            G.setMouseIsActive(true);
                            setZonesJouables(G.pieces[G.pieceEncours]);
                            break;
                        }
                    }
                }
                else
                {
                    for (int i = 0; i < 16; i++) {
                        if (G.pieces[i].getEstVivant() && G.pieces[i].getCoord() == V2((int)(G.xMouse / 80), (int)(G.yMouse / 80)))
                        {
                            G.pieceEncours = i;
                            G.setMouseIsActive(true);
                            setZonesJouables(G.pieces[G.pieceEncours]);
                            break;
                        }
                    }
                }
            }
        }
        else
        {
            if (G.mouseIsActive)
            {
                G.setMouseIsActive(false);
                if (DeplacementPiece(G.pieces[G.pieceEncours], V2((int)(G.xMouse / 80), (int)(G.yMouse / 80)))) {
                    if (NoSuicideMove(G.pieces[G.pieceEncours], V2((int)(G.xMouse / 80), (int)(G.yMouse / 80)))) {
                        if (G.Plateau.getPositionPiece(V2((int)(G.xMouse / 80), (int)(G.yMouse / 80))) == 0) {
                            if (G.pieces[G.pieceEncours].getTypePiece() == 5) {//verification si roque
                                if ((G.pieces[G.pieceEncours].getCoord().x + 2 == (int)(G.xMouse / 80))) {
                                    if (G.pieces[G.pieceEncours].getCouleur() == 1) {
                                        G.Plateau.setPositionPiece(5, 0, "1");
                                        G.Plateau.setPositionPiece(7, 0, "0");
                                        G.pieces[25].setCoord(V2(5, 0));
                                    }
                                    else {
                                        G.Plateau.setPositionPiece(5, 7, "2");
                                        G.Plateau.setPositionPiece(7, 7, "0");
                                        G.pieces[9].setCoord(V2(5, 7));
                                    }
                                }
                                else if ((G.pieces[G.pieceEncours].getCoord().x - 2 == (int)(G.xMouse / 80))) {
                                    if (G.pieces[G.pieceEncours].getCouleur() == 1) {
                                        G.Plateau.setPositionPiece(3, 0, "1");
                                        G.Plateau.setPositionPiece(0, 0, "0");
                                        G.pieces[24].setCoord(V2(3, 0));
                                    }
                                    else {
                                        G.Plateau.setPositionPiece(3, 7, "2");
                                        G.Plateau.setPositionPiece(0, 7, "0");
                                        G.pieces[8].setCoord(V2(3, 7));
                                    }
                                }
                            }
                            G.Plateau.setPositionPiece((int)(G.xMouse / 80), (int)(G.yMouse / 80), to_string(G.pieces[G.pieceEncours].getCouleur()));
                            G.Plateau.setPositionPiece(G.pieces[G.pieceEncours].getCoord().x, G.pieces[G.pieceEncours].getCoord().y, "0");
                            G.pieces[G.pieceEncours].setCoord(V2((int)(G.xMouse / 80), (int)(G.yMouse / 80)));
                            if (G.pieces[G.pieceEncours].getNoMove()) {
                                G.pieces[G.pieceEncours].setNoMove(false);
                            }
                        }
                        else if (G.Plateau.getPositionPiece(V2((int)(G.xMouse / 80), (int)(G.yMouse / 80))) != G.pieces[G.pieceEncours].getCouleur()) {
                            for (_Piece& piece : G.pieces) {
                                if (piece.getCoord() == V2((int)(G.xMouse / 80), (int)(G.yMouse / 80))) {
                                    piece.setEstVivant(false);
                                }
                            }
                            G.Plateau.setPositionPiece((int)(G.xMouse / 80), (int)(G.yMouse / 80), to_string(G.pieces[G.pieceEncours].getCouleur()));
                            G.Plateau.setPositionPiece(G.pieces[G.pieceEncours].getCoord().x, G.pieces[G.pieceEncours].getCoord().y, "0");
                            G.pieces[G.pieceEncours].setCoord(V2((int)(G.xMouse / 80), (int)(G.yMouse / 80)));
                            if (G.pieces[G.pieceEncours].getNoMove()) {
                                G.pieces[G.pieceEncours].setNoMove(false);
                            }
                        }
                        if ((G.pieces[G.pieceEncours].getTypePiece() == 0 && G.pieces[G.pieceEncours].getCoord().y == 7 && G.pieces[G.pieceEncours].getCouleur() == 1) || (G.pieces[G.pieceEncours].getTypePiece() == 0 && G.pieces[G.pieceEncours].getCoord().y == 0 && G.pieces[G.pieceEncours].getCouleur() == 2)) {
                            G.pieces[G.pieceEncours] = _Dame(G.pieces[G.pieceEncours].getCoord(), G.pieces[G.pieceEncours].getCouleur());
                        }

                        G.setJoueur();
                    }
                }
                G.pieceEncours = -1;
            }
        }
    }
       
    return 3;
}
//end
int gestion_ecran_game_over() {
    if (G2D::IsKeyPressed(Key::ENTER)) {
        return 1;
    }
    return 4;
}
//end
int gestion_ecran_win() {
    if (G2D::IsKeyPressed(Key::ENTER)) {
        return 1;
    }
    return 5;
}
//end
void Logic() {
    if (G.ecran == ECRAN_ACCUEIL) {
        G.ecran = gestion_ecran_accueil();
    }

    if (G.ecran == ECRAN_OPTIONS) {
        G.ecran = gestion_ecran_options();
    }
    if (G.ecran == INIT_PARTIE) {
        G.ecran = InitPartie();
    }
    if (G.ecran == ECRAN_JEU) {
        G.ecran = gestion_ecran_jeu();
    }

    if (G.ecran == ECRAN_GAME_OVER) {
        G.ecran = gestion_ecran_game_over();
    }
    if (G.ecran == ECRAN_WIN) {
        G.ecran = gestion_ecran_win();
    }
}

void AssetsInit() {
    // Size pass� en ref et texture en param
    G.IdTexMur =
        G2D::InitTextureFromString(G.Size, G.Plateau.textureMur);
    G.IdTexSol =
        G2D::InitTextureFromString(G.Size, G.Plateau.textureSol);
    G.IdTexPossible =
        G2D::InitTextureFromString(G.Size, G.Plateau.texturePossible);
    G.Size =
        G.Size * 10; // on peut zoomer la taille du sprite
}
int main(int argc, char* argv[]) {
    G2D::InitWindow(argc, argv, V2(G.Lpix * 8, G.Lpix * 8), V2(200, 200),
        string("Echecs"));

    AssetsInit();

    G2D::Run(Logic, render);
}