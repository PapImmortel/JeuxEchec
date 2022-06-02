 
#pragma warning( disable : 4996 ) 
 
#include <cstdlib>
#include <vector>
#include <iostream>
#include <string>
#include "G2D.h"
 

using namespace std;
  
 

struct Dessin {
    string roiBlanc =
        "[  K  KKKKKKK  K  ]"
        "[ KOKKRORRRORKKOK ]"
        "[ KOOROOOROOOROOK ]"
        "[ KOOOOOOOOOOOOOK ]"
        "[ KWAWAAWAWAAWAWK ]"
        "[ KOOOOOOOOOOOOOK ]"
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

    string roiNoir = "[  K  KKKKKKK  K  ]"
        "[ KYKKRYRRRYRKKYK ]"
        "[ KYYRYYYRYYYRYYK ]"
        "[ KYYYYYYYYYYYYYK ]"
        "[ KWAWAAWAWAAWAWK ]"
        "[ KYYYYYYYYYYYYYK ]"
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

};
 