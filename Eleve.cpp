 
#pragma warning( disable : 4996 ) 
 
#include <cstdlib>
#include <vector>
#include <iostream>
#include <string>
#include "G2D.h"
 

using namespace std;
  
 

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
    string ChevalierNoir =

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

    string chevalierRouge=
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
 