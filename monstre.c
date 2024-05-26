#include "define.h"
#include "salle.h"
#include "perso.h"
#include "bobby.h"
#include "sauvegarde.h"
#include "monstre.h"


void m_attaque(int mat[DTAILLE][DTAILLE],Monstre* m,Perso* j){

  //VERIFIE SI LE JOUEUR EST AUTOUR DU MONSTRE
  for(int i=0;i<3;i++){
    if(mat[(*m).xy.x-1 +CST][(*m).xy.y-1 +i +CST] == 1 | mat[(*m).xy.x+1 +CST][(*m).xy.y-1 +i +CST] == 1){
      j->PV -= m->attaque;
    }
  }

  if(mat[(*m).xy.x+CST][(*m).xy.y-1+CST] == 1 || mat[(*m).xy.x+CST][(*m).xy.y+1+CST] == 1){
    j->PV -= m->attaque;
  }

  //printf("PV JOUEUR (m_attaque) : %d\n\n",j->PV);
}




//RENVOIE UN TABLEAU AVEC LES X Y A AJOUER AUX COORDONEES DU MONSTRE
void deplacement_monstre(int mat[DTAILLE][DTAILLE],Monstre* m,int xj,int yj,int num_salle_joueur,Perso* j){

  int dist_y = abs((*m).xy.y-yj);  //distance du joueur pour y
  int dist_x = abs((*m).xy.x-xj);  //distance du joueur pour x

  int dir_x = xj -(*m).xy.x; //sens de direction vers le joueur en x
  int dir_y = yj -(*m).xy.y; //sens de direction vers le joueur en y


  //SI UNE DIRECTION EST NULLE ALORS ON MET 10 POUR SIMPLIFIER LES CALCULS APRES
  if(dir_x == 0){
    dir_x = 10;
  }
  if(dir_y == 0){
    dir_y = 10;
  }




  //AJT SI OBJET BLOQUENT LE CHEMIN
  // -> ALLER A L'OPPO DU JOUEUR



  //DETERMINE SI LE MONSTRE BOUGE OU ATTAQUE
  if((dist_x == 1 && dist_y == 1) || (dist_x == 1 && dist_y == 0) || (dist_x == 0 && dist_y == 1)){
    m_attaque(mat,m,j);
    //printf("PV JOUEUR (deplacement_m) : %d\n",j->PV);
  }

  else{
    int deplacement_x=0, deplacement_y=0;

  //printf("distance : %d %d\n",dist_x,dist_y);
  //printf("direction : %d %d\n",dir_x,dir_y);

  //printf("coef x : %d ",dist_x/dir_x);
  //printf("coef y : %d \n",dist_y/dir_y);


  //int a = 1;

  //0 HAUT ; 1 DROITE ; 2 BAS ; 3 GAUCHE


  //SI JOUEUR PAS DANS SALLE
  //SELECTIONNE UNE DIRECTION (POUR ALLER VERS LE JOUEUR)

  //printf("num s j : %d \n",num_salle_joueur);
  //printf("num s m : %d \n",m->num_s);


  if(num_salle_joueur != m->num_s){ //SI JOUEUR ET MONSTRE PAS DANS MEME SALLE
    //printf("MONSTRE ET JOUEUR PAS DANS MEME SALLE\n");


    int choix_xy;
    do{

      deplacement_x = 0;
      deplacement_y = 0;

      choix_xy = rand()%4; //DEPLACEMENT ALEATOIRE PARMIS 4 DIRECTIONS

      switch(choix_xy){
        case 0:
          deplacement_x = 1;
        break;
        case 1:
          deplacement_x = -1;
        break;
        case 2:
          deplacement_y = 1;
        break;
        case 3:
          deplacement_y = -1;
        break;
        }


      //aff_matrice(mat);
      //printf("deplacement %d %d COORD %d %d COORD M ORIGINE %d %d RANDOM %d\n",deplacement_x,deplacement_y,(*m).xy.x +deplacement_x ,(*m).xy.y +deplacement_y,(*m).xy.x,(*m).xy.x,choix_xy);


    }while(mat[(*m).xy.x +deplacement_x +CST][(*m).xy.y +deplacement_y +CST] != 7);
    //VERIF SI LE MONSTRE VA SUR UNE CASE SOL
  }



  else{
    //printf("MONSTRE ET JOUEUR DANS MEME SALLE\n");

    //VERIF SI CASE VERS JOUEUR LIBRE (PAS OBJET TYPE COFFRE)
    int case_x = 1;
    int case_y = 1;

    if(mat[(*m).xy.x +dist_x/dir_x +CST][(*m).xy.y +CST] == 7){  //SI SOL       ++++AJT JOUEUR? ET OBJETS
      //printf("CASE X LIBRE\n");
      case_x = 0;
    }
    //printf("blblblblbl\n");
    if(mat[(*m).xy.x +CST][(*m).xy.y +dist_y/dir_y +CST] == 7){  //SI SOL       ++++AJT JOUEUR? ET OBJETS
      //printf("CASE Y LIBRE\n");
      case_y = 0;
    }


    //SELECTIONNE UNE CASE LIBRE VERS LE JOUEUR
    if(case_x == 0 && case_y == 0){ //SI LES 2 CASES SONT LIBRES
      //printf("2 CASES LIBRES\n");
      int nbb;
      if(dist_x >= dist_y){
        nbb = 0;
      }
      else{
        nbb = 1;
      }

      if(nbb == 0){
        deplacement_x = dist_x/dir_x;
      }
      else{
        deplacement_y = dist_y/dir_y;
      }
    }

    else if(case_x == 0){ //SI LA CASE DES X EST LIBRE
      //printf("SI CASE X LIBRE\n");
      deplacement_x = dir_x/dist_x;
    }
    else if(case_y == 0){ //SI LA CASE DES X EST LIBRE
      //printf("SI CASE X LIBRE\n");
      deplacement_y = dir_y/dist_y;
    }



    }
    //printf("deplacement : %d %d\n",deplacement_x,deplacement_y);

    mat[(*m).xy.x+CST][(*m).xy.y+CST] = 7;//               ++++ OBJETS
    //printf("ok1\n");
    (*m).xy.x += deplacement_x;
    (*m).xy.y += deplacement_y;
    //printf("ok2\n\n\n");
    mat[(*m).xy.x+CST][(*m).xy.y+CST] = 9;
  }
}



void deplacement_monstre_salle(int mat[DTAILLE][DTAILLE],Salle* s,Perso* j){

  //printf("   --- depl m s ---   \n");
  //printf(" nbm : %d\n",s->nbm);

  for(int i=0;i<s->nbm;i++){
    //printf("for depl_m_s \n");

    if(s->m->pv >= 0){ //vérifie si le monstre est vivant
      deplacement_monstre(mat,s->m+i,j->xy.x,j->xy.y,j->num_salle,j);
    }
  }
  //printf("   --- FIN depl m s ---   \n");
}
