#include "define.h"
#include "perso.h"

void deplacement_bobby(Perso* pperso,int matrice[DTAILLE][DTAILLE]){
    if((*pperso).bobby.xy.x == (*pperso).xy.x && (*pperso).bobby.xy.y == (*pperso).xy.y){
        matrice[(*pperso).bobby.xy.x+CST][(*pperso).bobby.xy.y+CST] = 1;
        (*pperso).bobby.xy.x = (*pperso).bobby.ancienne_pj.x;
        (*pperso).bobby.xy.y = (*pperso).bobby.ancienne_pj.y;
        matrice[(*pperso).bobby.xy.x+CST][(*pperso).bobby.xy.y+CST] = 666;
    }
    else if((*pperso).bobby.ancienne_pj.x != (*pperso).xy.x || (*pperso).bobby.ancienne_pj.y != (*pperso).xy.y){
        matrice[(*pperso).bobby.xy.x+CST][(*pperso).bobby.xy.y+CST] = 7;
        (*pperso).bobby.xy.x = (*pperso).bobby.ancienne_pj.x;
        (*pperso).bobby.xy.y = (*pperso).bobby.ancienne_pj.y;
        matrice[(*pperso).bobby.xy.x+CST][(*pperso).bobby.xy.y+CST] = 666;
    }
}
