#include "define.h"
#include "salle.h"
#include "perso.h"
#include "bobby.h"
#include "sauvegarde.h"
#include "monstre.h"

//graine

//fonction pour initialisé touts les aspect du perso
//fonction pour initialisé touts les aspect du perso
Perso initialisation_perso(){
    Perso a;
    a.inventaire.epee_en_bois = 0;
    a.inventaire.dague = 0;
    a.inventaire.epee_en_fer = 0;
    a.inventaire.armure_fer = 0;
    a.inventaire.armure_cuire = 0;
    a.inventaire.demi_armure_fer = 0;
    a.inventaire.demi_armure_cuire = 0;
    a.inventaire.pomme =0;
    a.inventaire.clee = 0;
    a.inventaire.torche = 0;
    a.inventaire.potion = 0;
    a.inventaire.fiole_de_xp = 0;
    a.inventaire.roche = 00;
    a.case_joueur = 7;
    a.num_salle = 0;
    a.num_porte = 0;
    a.xy.x = 5;
    a.xy.y = 5;
    a.PV = 1000;
    a.xp = 10;
    strcpy(a.objet_en_main,"rien");
    a. attaque = 5;
    a. defense = 0;
    a.nb_caillou_depose = 0;
    a.bobby.action =0;
    return a;
}

void aff_matrice(int mat[DTAILLE][DTAILLE]){

  printf("   ---AFF MAT---   \n");

  //int* mat[DTAILLE][DTAILLE] = {mat_x,mat_y};
  printf("\x1B[38;2;%d;%d;%dm",0,0,0);
  for(int y=DTAILLE-1;y>=0;y--){
    for(int x=0;x<DTAILLE;x++){

      switch(mat[x][y]){
      case 8:  //mur
        printf("\x1B[38;2;%d;%d;%dm",255,0,0);
        //comentaire.exe
      break;
      case 7:  //sol
        printf("\x1B[38;2;%d;%d;%dm",0,255,0);
        break;
      case 2:  //porte
        printf("\x1B[38;2;%d;%d;%dm",0,0,255);
        break;
        case 3://tombe
            printf("\x1B[38;2;%d;%d;%dm",36,54,32);
        break;
        case 4://coffre
            printf("\x1B[38;2;%d;%d;%dm",255,130,0);
        break;
        case 41://coffre ouvert
            printf("\x1B[38;2;%d;%d;%dm",255,131,50);
        break;
      case 9:  //monstre
        printf("\x1B[38;2;%d;%d;%dm",0,255,255);
        break;
      case 1:  //joueur
        printf("\x1B[38;2;%d;%d;%dm",255,255,255);
        break;
      case 71:  //sol enflammé
        printf("\x1B[38;2;%d;%d;%dm",255,255,0);
        break;
      case 72:  //sol ralentis
        printf("\x1B[38;2;%d;%d;%dm",200,200,200);
      break;
      case 51:  //portail non activé
        printf("\x1B[38;2;%d;%d;%dm",255,0,255);
        break;
      case 52:  //portail activé
        printf("\x1B[38;2;%d;%d;%dm",255,192,255);
        break;
      case 100:  //caillou
        printf("\x1B[38;2;%d;%d;%dm",100,100,100);
      break;
      case 666:  //Bobby
        printf("\x1B[38;2;%d;%d;%dm",127,127,255);
      break;
      }

      //printf("%d ",mat[x][y]);
      printf("1.");
      //printf("\U0001F449");
      printf("\x1B[38;2;%d;%d;%dm",0,0,0);
    }
    printf("\n");
  }
  printf("\x1B[38;2;%d;%d;%dm",255,255,255);
}

void aff_vision(int mat[DTAILLE][DTAILLE],int xp,int yp){

  int l_vision = 8, L_vision = 4;
  int ox = xp - l_vision/2;
  int oy = yp - L_vision/2;

  printf("   ---AFF VISION---   \n");

  printf("\x1B[38;2;%d;%d;%dm",0,0,0);
  for(int y=oy+L_vision-1+CST+1;y>=oy+CST;y--){
    for(int x=ox+CST;x<ox+l_vision+CST+1;x++){

      switch(mat[x][y]){
      case 8:  //mur
        printf("\x1B[38;2;%d;%d;%dm",255,0,0);
        break;
      case 7:  //sol
        printf("\x1B[38;2;%d;%d;%dm",0,255,0);
        break;
      case 2:  //porte
        printf("\x1B[38;2;%d;%d;%dm",0,0,255);
        break;
        case 3://tombe
            printf("\x1B[38;2;%d;%d;%dm",36,54,32);
        break;
        case 4://coffre
            printf("\x1B[38;2;%d;%d;%dm",255,130,0);
        break;
        case 41://coffre ouvert
            printf("\x1B[38;2;%d;%d;%dm",255,131,50);
        break;
      case 9:  //monstre
        printf("\x1B[38;2;%d;%d;%dm",0,255,255);
        break;
      case 1:  //joueur
        printf("\x1B[38;2;%d;%d;%dm",255,255,255);
        break;
      case 71:  //sol enflammé
        printf("\x1B[38;2;%d;%d;%dm",255,255,0);
        break;
      case 72:  //sol ralentis
        printf("\x1B[38;2;%d;%d;%dm",200,200,200);
      break;
      case 51:  //portail non activé
        printf("\x1B[38;2;%d;%d;%dm",255,0,255);
        break;
      case 52:  //portail activé
        printf("\x1B[38;2;%d;%d;%dm",255,192,255);
        break;
      case 100:  //caillou
        printf("\x1B[38;2;%d;%d;%dm",100,100,100);
      break;
      case 666:  //Bobby
        printf("\x1B[38;2;%d;%d;%dm",127,127,255);
      break;
      }

      printf("0.");
      printf("\x1B[38;2;%d;%d;%dm",0,0,0);
    }
    printf("\n");
  }
  printf("\x1B[38;2;%d;%d;%dm",255,255,255);


}

void tombe_vide(Perso* ptombe){
    (*ptombe).inventaire.epee_en_bois = 0;
    (*ptombe).inventaire.dague = 0;
    (*ptombe).inventaire.epee_en_fer = 0;
    (*ptombe).inventaire.armure_fer = 0;
    (*ptombe).inventaire.armure_cuire = 0;
    (*ptombe).inventaire.demi_armure_fer = 0;
    (*ptombe).inventaire.demi_armure_cuire = 0;
    (*ptombe).inventaire.pomme =0;
    (*ptombe).inventaire.clee = 0;
    (*ptombe).inventaire.torche = 0;
    (*ptombe).inventaire.potion = 0;
    (*ptombe).inventaire.fiole_de_xp = 0;
    (*ptombe).num_salle = 0;
    (*ptombe).case_joueur = 7;
}

Perso remplisagecoffre(){
    Perso coffre;
    coffre.inventaire.epee_en_bois = rand()%1;
    if(coffre.inventaire.epee_en_bois == 0){
        coffre.inventaire.dague = rand()%1;
        if(coffre.inventaire.dague == 0){
            coffre.inventaire.epee_en_fer = rand()%1;
        }
    }
    coffre.inventaire.demi_armure_cuire = rand()%1;
    if(coffre.inventaire.demi_armure_cuire == 0){
        coffre.inventaire.demi_armure_fer = rand()%1;
        if(coffre.inventaire.demi_armure_fer == 0){
            coffre.inventaire.armure_cuire = rand()%1;
            if(coffre.inventaire.armure_cuire == 0){
                coffre.inventaire.armure_fer = rand()%1;
            }
        }
    }
    coffre.inventaire.pomme = rand()%10;
    coffre.inventaire.torche = rand()%10;
    coffre.inventaire.potion = rand()%10;
    coffre.inventaire.fiole_de_xp = rand()%50;
    coffre.inventaire.clee = rand()%1;
    return coffre;
}

void sommedinventaire(Perso* pa,Perso* pc){
    (*pa).inventaire.epee_en_bois = (*pc).inventaire.epee_en_bois + (*pa).inventaire.epee_en_bois;
    (*pa).inventaire.dague = (*pc).inventaire.dague + (*pa).inventaire.dague;
    (*pa).inventaire.epee_en_fer = (*pc).inventaire.epee_en_fer + (*pa).inventaire.epee_en_fer;
    (*pa).inventaire.armure_fer = (*pc).inventaire.armure_fer + (*pa).inventaire.armure_fer;
    (*pa).inventaire.armure_cuire = (*pc).inventaire.armure_cuire + (*pa).inventaire.armure_cuire;
    (*pa).inventaire.demi_armure_fer = (*pc).inventaire.demi_armure_fer + (*pa).inventaire.demi_armure_fer;
    (*pa).inventaire.demi_armure_cuire = (*pc).inventaire.demi_armure_cuire + (*pa).inventaire.demi_armure_cuire;
    (*pa).inventaire.pomme = (*pc).inventaire.pomme + (*pa).inventaire.pomme;
    (*pa).inventaire.clee = (*pc).inventaire.clee + (*pa).inventaire.clee;
    (*pa).inventaire.torche = (*pc).inventaire.torche + (*pa).inventaire.torche;
    (*pa).inventaire.potion = (*pc).inventaire.potion + (*pa).inventaire.potion;
    (*pa).inventaire.fiole_de_xp = (*pc).inventaire.fiole_de_xp + (*pa).inventaire.fiole_de_xp;
}

//fonction d'affichage de l'inventaire du joueur.
void affichage_inventaire(Perso* pperso){
    //Chaque lignes vérifient que le joueur à l'Objet et si il l'a il écrit une phrase pour dire combien le joueur en a.
    if((*pperso).inventaire.epee_en_bois >0){
        printf("1:  %d épée en bois\n",(*pperso).inventaire.epee_en_bois);
    }
    if((*pperso).inventaire.epee_en_fer >0){
        printf("2:  %d épée en fer\n",(*pperso).inventaire.epee_en_fer);
    }
    if((*pperso).inventaire.dague >0){
        printf("3:  %d dague\n",(*pperso).inventaire.dague);
    }
    if((*pperso).inventaire.armure_cuire >0){
        printf("4:  %d armure cuire\n",(*pperso).inventaire.armure_cuire);
    }
    if((*pperso).inventaire.armure_fer >0){
        printf("5:  %d armure fer\n",(*pperso).inventaire.armure_fer);
    }
    if((*pperso).inventaire.demi_armure_cuire >0){
        printf("6:  %d demi armure cuire\n",(*pperso).inventaire.demi_armure_cuire);
    }
    if((*pperso).inventaire.demi_armure_fer >0){
        printf("7:  %d demi armure fer\n",(*pperso).inventaire.demi_armure_fer);
    }
    if((*pperso).inventaire.pomme >0){
        printf("8:  %d pomme\n",(*pperso).inventaire.pomme);
    }
    if((*pperso).inventaire.clee >0){
        printf("9:  %d clée\n",(*pperso).inventaire.clee);
    }
    if((*pperso).inventaire.torche >0){
        printf("10:  %d torche\n",(*pperso).inventaire.torche);
    }
    if((*pperso).inventaire.potion >0){
        printf("11:  %d potion\n",(*pperso).inventaire.potion);
    }
    if((*pperso).inventaire.fiole_de_xp >0){
        printf("12:  %d fiole d'xp\n",(*pperso).inventaire.fiole_de_xp);
    }
    if((*pperso).inventaire.roche >0){
        printf("13:  %d caillou\n",(*pperso).inventaire.roche);
    }
}

void affichage(Perso* pperso,int matrice[DTAILLE][DTAILLE],int fin){
    system("clear");
    printf(" ______________________________________________________________\n");
    printf("| A -> Accueil   Z -> Devant    E -> Interagir  R -> Utiliser |\n");
    printf("|-------------------------------------------------------------|\n");
    printf("| Q -> Gauche    S -> Derrière D -> Droite     F -> Attaquer |\n");
    printf(" ______________________________________________________________\n");

    int timer;
    int maintenant = clock() / CLOCKS_PER_SEC;
    timer = fin - maintenant ;
    printf("CHRONO |%d|\n", timer);

    //aff_matrice(matrice);
    aff_vision(matrice,(*pperso).xy.x,(*pperso).xy.y);
    affichage_inventaire(pperso);
    printf("PV = %d\n",(*pperso).PV);
    printf("xp = %d\n",(*pperso).xp);
    printf("objet en main : %s \n",(*pperso).objet_en_main);
    printf("point d'attaque : %d \n",(*pperso).attaque);
    printf("NUM salle : %d \n",(*pperso).num_salle);
}

Position_Autour pautour(Perso a){
    Position_Autour alpha;
    alpha.haut.x = a.xy.x;
    alpha.haut.y = a.xy.y +1;
    alpha.bas.x = a.xy.x;
    alpha.bas.y = a.xy.y -1;
    alpha.gauche.x = a.xy.x -1;
    alpha.gauche.y = a.xy.y;
    alpha.droite.x = a.xy.x +1;
    alpha.droite.y = a.xy.y;
    //printf("les positions à coté du joueur sont : d=(%d,%d) ; g=(%d,%d) ; h=(%d,%d) ; b=(%d,%d)\n",alpha.droite.x,alpha.droite.y,alpha.gauche.x,alpha.gauche.y,alpha.haut.x,alpha.haut.y,alpha.bas.x,alpha.bas.y);
    return alpha;
}

void creation_tombe(Perso* pperso,Perso* ptombe,int matrice[DTAILLE][DTAILLE]){
    matrice[(*pperso).xy.x+CST][(*pperso).xy.y+CST] = 3;
    (*ptombe).inventaire.epee_en_bois = (*pperso).inventaire.epee_en_bois;
    (*ptombe).inventaire.dague = (*pperso).inventaire.dague;
    (*ptombe).inventaire.epee_en_fer = (*pperso).inventaire.epee_en_fer;
    (*ptombe).inventaire.armure_fer = (*pperso).inventaire.armure_fer;
    (*ptombe).inventaire.armure_cuire = (*pperso).inventaire.armure_cuire;
    (*ptombe).inventaire.demi_armure_fer = (*pperso).inventaire.demi_armure_fer;
    (*ptombe).inventaire.demi_armure_cuire = (*pperso).inventaire.demi_armure_cuire;
    (*ptombe).inventaire.pomme = (*pperso).inventaire.pomme;
    (*ptombe).inventaire.clee = (*pperso).inventaire.clee;
    (*ptombe).inventaire.potion = (*pperso).inventaire.potion;
    (*ptombe).inventaire.torche = (*pperso).inventaire.torche;
    (*ptombe).inventaire.fiole_de_xp = (*pperso).inventaire.fiole_de_xp;
    (*ptombe).case_joueur =(*pperso).case_joueur;
    (*pperso) = initialisation_perso();
    matrice[(*pperso).xy.x+CST][(*pperso).xy.y+CST] = 1;
}

void prise_objet_main(Perso* pperso,short b,int matrice[DTAILLE][DTAILLE],int fin){
    switch(b){
        case 6:
            if((*pperso).inventaire.epee_en_bois >0){
                strcpy((*pperso).objet_en_main,"épée en bois");
                (*pperso).attaque = 10;
            }
            else{
                strcpy((*pperso).objet_en_main,"rien");
                (*pperso).attaque = 5;
            }
        break;
        case 7:
            if((*pperso).inventaire.epee_en_fer >0){
                strcpy((*pperso).objet_en_main,"épée en fer");
                (*pperso).attaque = 15;
            }
            else{
                strcpy((*pperso).objet_en_main,"rien");
                (*pperso).attaque = 5;
            }
        break;
        case 8:
            if((*pperso).inventaire.dague >0){
                (*pperso).attaque = 20;
                strcpy((*pperso).objet_en_main,"dague");
            }
            else{
                strcpy((*pperso).objet_en_main,"rien");
                (*pperso).attaque = 5;
            }
        break;
        case 9:
            if((*pperso).inventaire.armure_cuire >0){
                (*pperso).attaque = 5;
                strcpy((*pperso).objet_en_main,"armure cuire ");
            }
            else{
                strcpy((*pperso).objet_en_main,"rien");
                (*pperso).attaque = 5;
            }
        break;
        case 10:
            if((*pperso).inventaire.armure_fer >0){
                (*pperso).attaque = 6;
                strcpy((*pperso).objet_en_main,"armure fer");
            }
            else{
                strcpy((*pperso).objet_en_main,"rien");
                (*pperso).attaque = 5;
            }
        break;
        case 11:
            if((*pperso).inventaire.demi_armure_cuire >0){
                (*pperso).attaque = 3;
                strcpy((*pperso).objet_en_main,"demi armure cuire");
            }
            else{
                strcpy((*pperso).objet_en_main,"rien");
                (*pperso).attaque = 5;
            }
        break;
        case 12:
            if((*pperso).inventaire.demi_armure_fer >0){
                (*pperso).attaque = 5;
                strcpy((*pperso).objet_en_main,"demi armure fer");
            }
            else{
                strcpy((*pperso).objet_en_main,"rien");
                (*pperso).attaque = 5;
            }
        break;
        case 13:
            if((*pperso).inventaire.pomme >0){
                (*pperso).attaque = 1;
                strcpy((*pperso).objet_en_main,"pomme");
            }
            else{
                strcpy((*pperso).objet_en_main,"rien");
                (*pperso).attaque = 5;
            }
        break;
        case 14:
            if((*pperso).inventaire.clee >0){
                (*pperso).attaque = 1;
                strcpy((*pperso).objet_en_main,"clée");
            }
            else{
                strcpy((*pperso).objet_en_main,"rien");
                (*pperso).attaque = 5;
            }
        break;
        case 15:
            if((*pperso).inventaire.torche >0){
                (*pperso).attaque = 8;
                strcpy((*pperso).objet_en_main,"torche");
            }
            else{
                strcpy((*pperso).objet_en_main,"rien");
                (*pperso).attaque = 5;
            }
        break;
        case 16:
            if((*pperso).inventaire.potion >0){
                (*pperso).attaque = 10;
                strcpy((*pperso).objet_en_main,"potion");
            }
            else{
                strcpy((*pperso).objet_en_main,"rien");
                (*pperso).attaque = 5;
            }
        break;
        case 17:
            if((*pperso).inventaire.fiole_de_xp >0){
                (*pperso).attaque = 0;
                strcpy((*pperso).objet_en_main,"fiole de xp");
            }
            else{
                strcpy((*pperso).objet_en_main,"rien");
                (*pperso).attaque = 5;
            }
        break;
        case 18:
            if((*pperso).inventaire.roche >0){
                (*pperso).attaque = 0;
                strcpy((*pperso).objet_en_main,"caillou");
            }
            else{
                strcpy((*pperso).objet_en_main,"rien");
                (*pperso).attaque = 5;
            }
        break;
    }
     affichage(pperso,matrice,fin);
}

void utilisation(Perso* pperso,int matrice[DTAILLE][DTAILLE],int fin){
    if(strcmp((*pperso).objet_en_main,"armure cuire")==0){
        (*pperso).defense = 10;
        (*pperso).inventaire.armure_cuire =(*pperso).inventaire.armure_cuire -1;
        prise_objet_main(pperso,9,matrice,fin);
        affichage(pperso,matrice,fin);
    }
    else if(strcmp((*pperso).objet_en_main,"armure fer")==0){
        (*pperso).defense = 15;
        (*pperso).inventaire.armure_fer =(*pperso).inventaire.armure_fer -1;
        prise_objet_main(pperso,10,matrice,fin);
         affichage(pperso,matrice,fin);
    }
    else if(strcmp((*pperso).objet_en_main,"demi armure cuire")==0){
        (*pperso).defense = 5;
        (*pperso).inventaire.demi_armure_cuire =(*pperso).inventaire.demi_armure_cuire -1;
        prise_objet_main(pperso,11,matrice,fin);
         affichage(pperso,matrice,fin);
    }
    else if(strcmp((*pperso).objet_en_main,"demi armure fer")==0){
        (*pperso).defense = 10;
        (*pperso).inventaire.demi_armure_fer =(*pperso).inventaire.demi_armure_fer -1;
        prise_objet_main(pperso,12,matrice,fin);
         affichage(pperso,matrice,fin);
    }
    else if(strcmp((*pperso).objet_en_main,"pomme")==0){
         (*pperso).PV = (*pperso).PV +5;
        (*pperso).inventaire.pomme =(*pperso).inventaire.pomme -1;
        prise_objet_main(pperso,13,matrice,fin);
         affichage(pperso,matrice,fin);
    }
    else if(strcmp((*pperso).objet_en_main,"torche")==0){
        (*pperso).PV = (*pperso).PV -1;
        (*pperso).inventaire.torche = (*pperso).inventaire.torche -1;
        (*pperso).inventaire.epee_en_bois = 0;
        prise_objet_main(pperso,6,matrice,fin);
         affichage(pperso,matrice,fin);
        printf("Vous tentez de devenir saltimbanque, mais vous brûlez tous vos équipements en bois !!!\n");
    }
    else if(strcmp((*pperso).objet_en_main,"fiole de xp")==0){
         (*pperso).xp = (*pperso).xp +15;
        (*pperso).inventaire.fiole_de_xp =(*pperso).inventaire.fiole_de_xp -1;
        prise_objet_main(pperso,17,matrice,fin);
         affichage(pperso,matrice,fin);
    }
    else if(strcmp((*pperso).objet_en_main,"caillou")==0){
         affichage(pperso,matrice,fin);
        printf("Vous regardez cette belle pierre faire de la lumière !!!\n");
        printf("Elle vous appelle et vous dit : « Les maths, quelle est l'utilité ? L'info suffit. »\n");
    }
}

void ouverture_coffre(Perso* pperso){
    Perso coffre = remplisagecoffre();
    printf("Vous ouvrez le coffre!!\n");
    Perso* pcoffre = NULL;
    pcoffre = &coffre;
    if(pcoffre == NULL){
        printf("pcoffre problème");
        exit(999);
    }
    sommedinventaire(pperso,pcoffre);
    affichage_inventaire(pcoffre);
}

void ouverture_tombe(Perso* pperso,Perso* ptombe){
    printf("Vous ouvrez votre tombe !!\n");
    affichage_inventaire(ptombe);
    sommedinventaire(pperso,ptombe);
    tombe_vide(ptombe);
}

void verification_objet_statique(Perso* pperso,Perso* ptombe,int matrice[DTAILLE][DTAILLE],Position_Autour alpha, int fin){
    if(matrice[alpha.haut.x+CST][alpha.haut.y+CST] == 4){
        matrice[alpha.haut.x+CST][alpha.haut.y+CST] = 41;
         affichage(pperso,matrice,fin);
        ouverture_coffre(pperso);
        (*pperso).xp = (*pperso).xp + rand()%20;
    }
    else if(matrice[alpha.bas.x+CST][alpha.bas.y+CST] == 4){
        matrice[alpha.bas.x+CST][alpha.bas.y+CST] = 41;
         affichage(pperso,matrice,fin);
        ouverture_coffre(pperso);
        (*pperso).xp = (*pperso).xp + rand()%20;
    }
    else if(matrice[alpha.gauche.x+CST][alpha.gauche.y+CST] == 4){
        matrice[alpha.gauche.x+CST][alpha.gauche.y+CST] = 41;
         affichage(pperso,matrice,fin);
        ouverture_coffre(pperso);
        (*pperso).xp = (*pperso).xp + rand()%20;
    }
    else if(matrice[alpha.droite.x+CST][alpha.droite.y+CST] == 4){
        matrice[alpha.droite.x+CST][alpha.droite.y+CST] = 41;
         affichage(pperso,matrice,fin);
        ouverture_coffre(pperso);
        (*pperso).xp = (*pperso).xp + rand()%20;
    }
    else if(matrice[alpha.droite.x+CST][alpha.droite.y+CST] == 3){
        matrice[alpha.droite.x+CST][alpha.droite.y+CST] = (*ptombe).case_joueur;
        ouverture_tombe(pperso,ptombe);
    }
    else if(matrice[alpha.gauche.x+CST][alpha.gauche.y+CST] == 3){
        matrice[alpha.gauche.x+CST][alpha.gauche.y+CST] = (*ptombe).case_joueur;
        ouverture_tombe(pperso,ptombe);
    }
    else if(matrice[alpha.haut.x+CST][alpha.haut.y+CST] == 3){
        matrice[alpha.haut.x+CST][alpha.haut.y+CST] = (*ptombe).case_joueur;
        ouverture_tombe(pperso,ptombe);
    }
    else if(matrice[alpha.bas.x+CST][alpha.bas.y+CST] == 3){
        matrice[alpha.bas.x+CST][alpha.bas.y+CST] = (*ptombe).case_joueur;
        ouverture_tombe(pperso,ptombe);
    }
    else if(matrice[alpha.droite.x+CST][alpha.droite.y+CST] == 51){
        if((*pperso).inventaire.roche != 0){
            matrice[alpha.droite.x+CST][alpha.droite.y+CST] = 52;
            (*pperso).nb_caillou_depose ++;
            (*pperso).inventaire.roche --;
            if((*pperso).nb_caillou_depose !=4){
                 affichage(pperso,matrice,fin);
                printf("Bravo. vous avancez petit à petit vers la fin !!!!\n");
            }
            else{
                 affichage(pperso,matrice,fin);
                printf("BRAVO VOUS AVEZ TERMINÉ. WHAOU\n");
            }
        }
        else{
            printf("Hum il manque quelque chose ici quesque ça peut-être ?????\n");
        }
    }
    else if(matrice[alpha.gauche.x+CST][alpha.gauche.y+CST] == 51){
        if((*pperso).inventaire.roche != 0){
            matrice[alpha.gauche.x+CST][alpha.gauche.y+CST] = 52;
            (*pperso).nb_caillou_depose ++;
            (*pperso).inventaire.roche --;
            if((*pperso).nb_caillou_depose !=4){
                 affichage(pperso,matrice,fin);
                printf("bravo. vous avancez petit à petit vers la fin!!!!\n");
            }
            else{
                 affichage(pperso,matrice,fin);
                printf("BRAVO VOUS AVEZ TERMINÉ. WHAOU\n");
            }
        }
        else{
            printf("Hum il manque quelque chose ici qu'est-ce que ça peut-être ?????\n");
        }
    }
    else if(matrice[alpha.haut.x+CST][alpha.haut.y+CST] == 51){
        if((*pperso).inventaire.roche != 0){
            matrice[alpha.haut.x+CST][alpha.haut.y+CST] = 52;
            (*pperso).nb_caillou_depose ++;
            (*pperso).inventaire.roche --;
            if((*pperso).nb_caillou_depose !=4){
                 affichage(pperso,matrice,fin);
                printf("Bravo. vous avancez petit à petit vers la fin !!!!\n");
            }
            else{
                 affichage(pperso,matrice,fin);
                printf("BRAVO VOUS AVEZ TERMINÉ. WHAOU\n");
            }
        }
        else{
            printf("Hum il manque quelque chose ici qu'est-ce que ça peut-être ?????\n");
        }
    }
    else if(matrice[alpha.bas.x+CST][alpha.bas.y+CST] == 51){
        if((*pperso).inventaire.roche != 0){
            matrice[alpha.bas.x+CST][alpha.bas.y+CST] = 52;
            (*pperso).nb_caillou_depose ++;
            (*pperso).inventaire.roche --;
            if((*pperso).nb_caillou_depose !=4){
                 affichage(pperso,matrice,fin);
                printf("bravo. vous avancez petit à petit vers la fin !!!!\n");
            }
            else{
                 affichage(pperso,matrice,fin);
                printf("BRAVO VOUS AVEZ TERMINÉ. WHAOU\n");
            }
        }
        else{
            printf("Hum il manque quelque chose ici qu'est-ce que ça peut-être ?????\n");
        }
    }
    else if((*pperso).case_joueur == 100){
        (*pperso).case_joueur = 7;
        (*pperso).inventaire.roche =(*pperso).inventaire.roche +1;
         affichage(pperso,matrice,fin);
        printf("Vous trouvez un mystérieux caillou posé là et vous le ramassez\n");
    }
    else if((*pperso).case_joueur == 101){
        (*pperso).case_joueur = 7;
        (*pperso).inventaire.epee_en_bois =(*pperso).inventaire.epee_en_bois +1;
         affichage(pperso,matrice,fin);
        printf("Vous trouvez un bout de bois par terre et vous vous dites que c'est toujours mieux que rien vous en faites une epée en bois.\n");
    }
    else if((*pperso).case_joueur == 102){
        (*pperso).case_joueur = 7;
        (*pperso).inventaire.dague =(*pperso).inventaire.dague +1;
         affichage(pperso,matrice,fin);
        printf("Vous trouvez une petite épée par terre et vous vous dites que c'est toujours bien.\n");
    }
    else if((*pperso).case_joueur == 103){
        (*pperso).case_joueur = 7;
        (*pperso).inventaire.epee_en_fer =(*pperso).inventaire.epee_en_fer +1;
         affichage(pperso,matrice,fin);
        printf("Vous trouvez une petite épée en fer. Votre esprit chevaleresque prend le dessus et vous la sortez de son fourreaux avant de l'attacher à votre ceinture.\n");
    }
    else if((*pperso).case_joueur == 104){
        (*pperso).case_joueur = 7;
        (*pperso).inventaire.demi_armure_cuire =(*pperso).inventaire.demi_armure_cuire +1;
         affichage(pperso,matrice,fin);
        printf("Vous trouvez un bout de cuire qui dépasse et la vous reconnaissez un bout d'armure ce seras toujours mieux que rien.\n");
    }
    else if((*pperso).case_joueur == 105){
        (*pperso).case_joueur = 7;
        (*pperso).inventaire.demi_armure_fer =(*pperso).inventaire.demi_armure_fer +1;
         affichage(pperso,matrice,fin);
        printf("Un bout de métal qui traine par terre il vous servira de protection car cela ressemble à une armure.\n");
    }
    else if((*pperso).case_joueur == 106){
        (*pperso).case_joueur = 7;
        (*pperso).inventaire.armure_cuire =(*pperso).inventaire.armure_cuire +1;
         affichage(pperso,matrice,fin);
        printf("Une armure en cuire un gueux a dû la laisser tomber vous la ramassez.\n");
    }
    else if((*pperso).case_joueur == 107){
        (*pperso).case_joueur = 7;
        (*pperso).inventaire.armure_fer =(*pperso).inventaire.armure_fer +1;
         affichage(pperso,matrice,fin);
        printf("une armure en fer, posé là? sans doute un piege mais vous la prenais car ça reste une bonne armure.\n");
    }
    else if((*pperso).case_joueur == 108){
        (*pperso).case_joueur = 7;
        (*pperso).inventaire.pomme =(*pperso).inventaire.pomme +3;
         affichage(pperso,matrice,fin);
        printf("MIAM. miam. miam. miam. une pomme!!!!!! ce n'est pas une tarte au pomme ,mais ça fera l'affaire.\n");
    }
    else if((*pperso).case_joueur == 109){
        (*pperso).case_joueur = 7;
        (*pperso).inventaire.clee =(*pperso).inventaire.clee +1;
         affichage(pperso,matrice,fin);
        printf("Un objet brilliant attire votre regard. Ce n'est qu'une simple clée. Passe-Partout a dû passer par là lui aussi.\n");
    }
    else if((*pperso).case_joueur == 110){
        (*pperso).case_joueur = 7;
        (*pperso).inventaire.torche =(*pperso).inventaire.torche +1;
         affichage(pperso,matrice,fin);
        printf("Ma mère est une meurtrière en série, mon père un psycopathe, la pomme ne tombe pas loin du pommier. CETTE TORCHE M'INTÉRESSE.\n");
    }
    else if((*pperso).case_joueur == 111){
        (*pperso).case_joueur = 7;
        (*pperso).inventaire.potion =(*pperso).inventaire.potion +1;
         affichage(pperso,matrice,fin);
        printf("Un flacon bizzare vous tend les bras au sol. Il a l'air louche. C'est trop bien et vous le prenez.\n");
    }
    else if((*pperso).case_joueur == 112){
        (*pperso).case_joueur = 7;
        (*pperso).inventaire.fiole_de_xp =(*pperso).inventaire.fiole_de_xp +1;
         affichage(pperso,matrice,fin);
        printf("Vous êtes un imbéciles finis. cette expèrience vous aidera peut-être à compter jusqu'à 2.\n");
    }
    else if(matrice[alpha.droite.x+CST][alpha.droite.y+CST] == 666){
        (*pperso).bobby.action = 1;
        printf("vous intéragissez avec jésus\n");
    }
    else if(matrice[alpha.gauche.x+CST][alpha.gauche.y+CST] == 666){
        (*pperso).bobby.action = 1;
        printf("vous intéragissez avec jésus\n");
    }
    else if(matrice[alpha.haut.x+CST][alpha.haut.y+CST] == 666){
        (*pperso).bobby.action = 1;
        printf("vous intéragissez avec jésus\n");
    }
    else if(matrice[alpha.bas.x+CST][alpha.bas.y+CST] == 666){
        (*pperso).bobby.action = 1;
        printf("vous intéragissez avec jésus\n");
    }
    else{
         affichage(pperso,matrice,fin);
        printf("Vous ramassez de l'air. BRAVO !!! vous ne pensez pas que vous avez mieux à faire ?\n");
    }
}

int mort_monstre(int matrice[DTAILLE][DTAILLE],Salle* donj,Perso* pperso,int i){
    short a = rand()%4;
    switch(a){
        case 0:
            matrice[donj[(*pperso).num_salle].m[i].xy.x+CST][donj[(*pperso).num_salle].m[i].xy.y+CST] = 7;
        break;
        case 1:
            matrice[donj[(*pperso).num_salle].m[i].xy.x+CST][donj[(*pperso).num_salle].m[i].xy.y+CST] = 102;
        break;
        case 2:
            matrice[donj[(*pperso).num_salle].m[i].xy.x+CST][donj[(*pperso).num_salle].m[i].xy.y+CST] = 108;
        break;
        case 3:
            matrice[donj[(*pperso).num_salle].m[i].xy.x+CST][donj[(*pperso).num_salle].m[i].xy.y+CST] = 105;
        break;
        case 4:
            matrice[donj[(*pperso).num_salle].m[i].xy.x+CST][donj[(*pperso).num_salle].m[i].xy.y+CST] = 9;
            donj[(*pperso).num_salle].m[i].pv =50;
        break;
    }

    if(i == donj[(*pperso).num_salle].nbm && a !=4){

        donj[(*pperso).num_salle].nbm -=1;
    }
    else if(a != 4){

        donj[(*pperso).num_salle].m[i] = donj[(*pperso).num_salle].m[donj[(*pperso).num_salle].nbm -1];
    }

    donj[(*pperso).num_salle].nbm -= 1;

}

void attaque(Perso* pperso,int matrice[DTAILLE][DTAILLE],Position_Autour alpha,Salle* donj, int fin){

    if(matrice[alpha.bas.x+CST][alpha.bas.y+CST] == 9){
        for(int i=0;i<donj[(*pperso).num_salle].nbm;i++){
            if(donj[(*pperso).num_salle].m[i].xy.x ==alpha.bas.x && donj[(*pperso).num_salle].m[i].xy.y ==alpha.bas.y){
                donj[(*pperso).num_salle].m[i].pv = donj[(*pperso).num_salle].m[i].pv - (*pperso).attaque;
                if(donj[(*pperso).num_salle].m[i].pv <1){
                    mort_monstre(matrice,donj,pperso,i);
                    (*pperso).xp = (*pperso).xp + rand()%20;
                }
            }
        }
    }
    else if(matrice[alpha.gauche.x+CST][alpha.gauche.y+CST] == 9){
        for(int i=0;i<donj[(*pperso).num_salle].nbm;i++){
            if(donj[(*pperso).num_salle].m[i].xy.x ==alpha.gauche.x && donj[(*pperso).num_salle].m[i].xy.y ==alpha.gauche.y){
                donj[(*pperso).num_salle].m[i].pv = donj[(*pperso).num_salle].m[i].pv - (*pperso).attaque;
                if(donj[(*pperso).num_salle].m[i].pv <1){
                    mort_monstre(matrice,donj,pperso,i);
                    (*pperso).xp = (*pperso).xp + rand()%20;
                }
            }
        }
    }
    else if(matrice[alpha.haut.x+CST][alpha.haut.y+CST] == 9){
        for(int i=0;i<donj[(*pperso).num_salle].nbm;i++){
            if(donj[(*pperso).num_salle].m[i].xy.x ==alpha.haut.x && donj[(*pperso).num_salle].m[i].xy.y ==alpha.haut.y){
                donj[(*pperso).num_salle].m[i].pv = donj[(*pperso).num_salle].m[i].pv - (*pperso).attaque;
                if(donj[(*pperso).num_salle].m[i].pv <1){
                    mort_monstre(matrice,donj,pperso,i);
                    (*pperso).xp = (*pperso).xp + rand()%20;
                }
            }
        }
    }
    else if(matrice[alpha.droite.x+CST][alpha.droite.y+CST] == 9){
        for(int i=0;i<donj[(*pperso).num_salle].nbm;i++){
            if(donj[(*pperso).num_salle].m[i].xy.x ==alpha.droite.x && donj[(*pperso).num_salle].m[i].xy.y ==alpha.droite.y){
                donj[(*pperso).num_salle].m[i].pv = donj[(*pperso).num_salle].m[i].pv - (*pperso).attaque;
                if(donj[(*pperso).num_salle].m[i].pv <1){
                    mort_monstre(matrice,donj,pperso,i);
                    (*pperso).xp = (*pperso).xp + rand()%20;
                }
            }
        }
    }
    else if(matrice[alpha.bas.x+CST-1][alpha.bas.y+CST] == 9 && (*pperso).inventaire.potion >0){
        for(int i=0;i<donj[(*pperso).num_salle].nbm;i++){
            if(donj[(*pperso).num_salle].m[i].xy.x ==alpha.bas.x -1 && donj[(*pperso).num_salle].m[i].xy.y ==alpha.bas.y){
                donj[(*pperso).num_salle].m[i].pv = donj[(*pperso).num_salle].m[i].pv -10;
                (*pperso).inventaire.potion = (*pperso).inventaire.potion -1;
                if(donj[(*pperso).num_salle].m[i].pv <1){
                    mort_monstre(matrice,donj,pperso,i);
                    (*pperso).xp = (*pperso).xp + rand()%20;
                }
            }
        }
    }
    else if(matrice[alpha.bas.x+CST+1][alpha.bas.y+CST] == 9 && (*pperso).inventaire.potion >0){
        for(int i=0;i<donj[(*pperso).num_salle].nbm;i++){
            if(donj[(*pperso).num_salle].m[i].xy.x ==alpha.bas.x +1 && donj[(*pperso).num_salle].m[i].xy.y ==alpha.bas.y){
                donj[(*pperso).num_salle].m[i].pv = donj[(*pperso).num_salle].m[i].pv -10;
                (*pperso).inventaire.potion = (*pperso).inventaire.potion -1;
                if(donj[(*pperso).num_salle].m[i].pv <1){
                    mort_monstre(matrice,donj,pperso,i);
                    (*pperso).xp = (*pperso).xp + rand()%20;
                }
            }
        }
    }
    else if(matrice[alpha.haut.x+CST+1][alpha.haut.y+CST] == 9 && (*pperso).inventaire.potion >0){
        for(int i=0;i<donj[(*pperso).num_salle].nbm;i++){
            if(donj[(*pperso).num_salle].m[i].xy.x ==alpha.haut.x +1 && donj[(*pperso).num_salle].m[i].xy.y ==alpha.haut.y){
                donj[(*pperso).num_salle].m[i].pv = donj[(*pperso).num_salle].m[i].pv - 10;
                (*pperso).inventaire.potion = (*pperso).inventaire.potion -1;
                if(donj[(*pperso).num_salle].m[i].pv <1){
                    mort_monstre(matrice,donj,pperso,i);
                    (*pperso).xp = (*pperso).xp + rand()%20;
                }
            }
        }
    }
    else if(matrice[alpha.haut.x+CST-1][alpha.haut.y+CST] == 9 && (*pperso).inventaire.potion >0){
        for(int i=0;i<donj[(*pperso).num_salle].nbm;i++){
            if(donj[(*pperso).num_salle].m[i].xy.x ==alpha.haut.x -1 && donj[(*pperso).num_salle].m[i].xy.y ==alpha.haut.y){
                donj[(*pperso).num_salle].m[i].pv = donj[(*pperso).num_salle].m[i].pv - 10;
                (*pperso).inventaire.potion = (*pperso).inventaire.potion -1;
                if(donj[(*pperso).num_salle].m[i].pv <1){
                    mort_monstre(matrice,donj,pperso,i);
                    (*pperso).xp = (*pperso).xp + rand()%20;
                }
            }
        }
    }
    else if(matrice[alpha.bas.x+CST][alpha.bas.y+CST-1] == 9 && (*pperso).inventaire.potion >0){
        for(int i=0;i<donj[(*pperso).num_salle].nbm;i++){
            if(donj[(*pperso).num_salle].m[i].xy.x ==alpha.bas.x && donj[(*pperso).num_salle].m[i].xy.y ==alpha.bas.y -1){
                donj[(*pperso).num_salle].m[i].pv = donj[(*pperso).num_salle].m[i].pv - 10;
                (*pperso).inventaire.potion = (*pperso).inventaire.potion -1;
                if(donj[(*pperso).num_salle].m[i].pv <1){
                    mort_monstre(matrice,donj,pperso,i);
                    (*pperso).xp = (*pperso).xp + rand()%20;
                }
            }
        }
    }
    else if(matrice[alpha.haut.x+CST][alpha.haut.y+CST+1] == 9 && (*pperso).inventaire.potion >0){
        for(int i=0;i<donj[(*pperso).num_salle].nbm;i++){
            if(donj[(*pperso).num_salle].m[i].xy.x ==alpha.haut.x && donj[(*pperso).num_salle].m[i].xy.y ==alpha.haut.y+1){
                donj[(*pperso).num_salle].m[i].pv = donj[(*pperso).num_salle].m[i].pv - 10;
                (*pperso).inventaire.potion = (*pperso).inventaire.potion -1;
                if(donj[(*pperso).num_salle].m[i].pv <1){
                    mort_monstre(matrice,donj,pperso,i);
                    (*pperso).xp = (*pperso).xp + rand()%20;
                }
            }
        }
    }
    else if(matrice[alpha.gauche.x+CST-1][alpha.gauche.y+CST] == 9 && (*pperso).inventaire.potion >0){
        for(int i=0;i<donj[(*pperso).num_salle].nbm;i++){
            if(donj[(*pperso).num_salle].m[i].xy.x ==alpha.gauche.x -1 && donj[(*pperso).num_salle].m[i].xy.y ==alpha.gauche.y){
                donj[(*pperso).num_salle].m[i].pv = donj[(*pperso).num_salle].m[i].pv - 10;
                (*pperso).inventaire.potion = (*pperso).inventaire.potion -1;
                if(donj[(*pperso).num_salle].m[i].pv <1){
                    mort_monstre(matrice,donj,pperso,i);
                    (*pperso).xp = (*pperso).xp + rand()%20;
                }
            }
        }
    }
    else if(matrice[alpha.droite.x+CST+1][alpha.droite.y+CST] == 9 && (*pperso).inventaire.potion >0){
        for(int i=0;i<donj[(*pperso).num_salle].nbm;i++){
            if(donj[(*pperso).num_salle].m[i].xy.x ==alpha.droite.x +1 && donj[(*pperso).num_salle].m[i].xy.y ==alpha.droite.y){
                donj[(*pperso).num_salle].m[i].pv = donj[(*pperso).num_salle].m[i].pv - 10;
                (*pperso).inventaire.potion = (*pperso).inventaire.potion -1;
                if(donj[(*pperso).num_salle].m[i].pv <1){
                    mort_monstre(matrice,donj,pperso,i);
                    (*pperso).xp = (*pperso).xp + rand()%20;
                }
            }
        }
    }
    else{
        printf("brasser de l'air ne vous aideras pas a avancer plus vite !! \n");
    }
     affichage(pperso,matrice,fin);
}

int mouvementperso(int m,Perso* pperso,int matrice[DTAILLE][DTAILLE],Salle* donj,int* nbS,int nbSmax,int* nbspotentielle,int* nbcaillou,int nbstot,int* bobby_la, int fin){
    Perso perso=*pperso;
    (*pperso).bobby.ancienne_pj.x = (*pperso).xy.x;
    (*pperso).bobby.ancienne_pj.y = (*pperso).xy.y;
    switch(m){
        case 1:
            if(matrice[perso.xy.x+CST+1][perso.xy.y+CST] == 7){
                (*pperso).xy.x = (*pperso).xy.x +1;
                matrice[perso.xy.x+CST+1][perso.xy.y+CST] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 7;
            }
            else if(matrice[perso.xy.x+CST+1][perso.xy.y+CST] == 2 && matrice[perso.xy.x+CST+2][perso.xy.y+CST] == 0){
                (*pperso).xy.x = (*pperso).xy.x +1;
                matrice[perso.xy.x+CST+1][perso.xy.y+CST] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 2;
                (*pperso).num_porte = num_p(matrice,donj[(*pperso).num_salle],(*pperso).xy.x,(*pperso).xy.y);
                donj[*nbS] = creer_s_valide(donj,donj[(*pperso).num_salle],(*pperso).num_porte,nbS,nbSmax,matrice,nbspotentielle,nbcaillou,nbstot,bobby_la,pperso);
                matrice[perso.xy.x+1+CST][perso.xy.y+CST] = 1;
            }
            else if(matrice[perso.xy.x+CST+1][perso.xy.y+CST] == 2){
                (*pperso).xy.x = (*pperso).xy.x +1;
                matrice[perso.xy.x+CST+1][perso.xy.y+CST] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 2;
            }
            else if(matrice[perso.xy.x+CST+1][perso.xy.y+CST] == 71){
                (*pperso).xy.x = (*pperso).xy.x +1;
                matrice[perso.xy.x+CST+1][perso.xy.y+CST] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 71;
                (*pperso).PV = (*pperso).PV-1;
            }
            else if(matrice[perso.xy.x+CST+1][perso.xy.y+CST] == 4){
                (*pperso).xy.x = (*pperso).xy.x +1;
                matrice[perso.xy.x+CST+1][perso.xy.y+CST] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 4;
            }
            else if(matrice[perso.xy.x+CST+1][perso.xy.y+CST] == 72){
                (*pperso).xy.x = (*pperso).xy.x +1;
                matrice[perso.xy.x+CST+1][perso.xy.y+CST] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 72;
                m=5;
            }
            else if(matrice[perso.xy.x+CST+1][perso.xy.y+CST] == 100){
                (*pperso).xy.x = (*pperso).xy.x +1;
                matrice[perso.xy.x+CST+1][perso.xy.y+CST] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 100;
            }
            else if(matrice[perso.xy.x+CST+1][perso.xy.y+CST] == 101){
                (*pperso).xy.x = (*pperso).xy.x +1;
                matrice[perso.xy.x+CST+1][perso.xy.y+CST] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 101;
            }
            else if(matrice[perso.xy.x+CST+1][perso.xy.y+CST] == 102){
                (*pperso).xy.x = (*pperso).xy.x +1;
                matrice[perso.xy.x+CST+1][perso.xy.y+CST] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 102;
            }
            else if(matrice[perso.xy.x+CST+1][perso.xy.y+CST] == 103){
                (*pperso).xy.x = (*pperso).xy.x +1;
                matrice[perso.xy.x+CST+1][perso.xy.y+CST] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 103;
            }
            else if(matrice[perso.xy.x+CST+1][perso.xy.y+CST] == 104){
                (*pperso).xy.x = (*pperso).xy.x +1;
                matrice[perso.xy.x+CST+1][perso.xy.y+CST] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 104;
            }
            else if(matrice[perso.xy.x+CST+1][perso.xy.y+CST] == 105){
                (*pperso).xy.x = (*pperso).xy.x +1;
                matrice[perso.xy.x+CST+1][perso.xy.y+CST] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 105;
            }
            else if(matrice[perso.xy.x+CST+1][perso.xy.y+CST] == 106){
                (*pperso).xy.x = (*pperso).xy.x +1;
                matrice[perso.xy.x+CST+1][perso.xy.y+CST] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 106;
            }
            else if(matrice[perso.xy.x+CST+1][perso.xy.y+CST] == 107){
                (*pperso).xy.x = (*pperso).xy.x +1;
                matrice[perso.xy.x+CST+1][perso.xy.y+CST] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 107;
            }
            else if(matrice[perso.xy.x+CST+1][perso.xy.y+CST] == 108){
                (*pperso).xy.x = (*pperso).xy.x +1;
                matrice[perso.xy.x+CST+1][perso.xy.y+CST] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 108;
            }
            else if(matrice[perso.xy.x+CST+1][perso.xy.y+CST] == 109){
                (*pperso).xy.x = (*pperso).xy.x +1;
                matrice[perso.xy.x+CST+1][perso.xy.y+CST] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 109;
            }
            else if(matrice[perso.xy.x+CST+1][perso.xy.y+CST] == 110){
                (*pperso).xy.x = (*pperso).xy.x +1;
                matrice[perso.xy.x+CST+1][perso.xy.y+CST] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 110;
            }
            else if(matrice[perso.xy.x+CST+1][perso.xy.y+CST] == 111){
                (*pperso).xy.x = (*pperso).xy.x +1;
                matrice[perso.xy.x+CST+1][perso.xy.y+CST] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 111;
            }
            else if(matrice[perso.xy.x+CST+1][perso.xy.y+CST] == 112){
                (*pperso).xy.x = (*pperso).xy.x +1;
                matrice[perso.xy.x+CST+1][perso.xy.y+CST] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 112;
            }
            else if(matrice[perso.xy.x+CST+1][perso.xy.y+CST] == 666){
                (*pperso).xy.x = (*pperso).xy.x +1;
                matrice[perso.xy.x+CST+1][perso.xy.y+CST] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 72;
            }
        break;
        case 2:
            if(matrice[perso.xy.x+CST-1][perso.xy.y+CST] == 7){
                (*pperso).xy.x = (*pperso).xy.x -1;
                matrice[perso.xy.x+CST-1][perso.xy.y+CST] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 7;
            }
            else if(matrice[perso.xy.x+CST-1][perso.xy.y+CST] == 2 && matrice[perso.xy.x+CST-2][perso.xy.y+CST] == 0){
                (*pperso).xy.x = (*pperso).xy.x -1;
                matrice[perso.xy.x+CST-1][perso.xy.y+CST] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 2;
                (*pperso).num_porte = num_p(matrice,donj[(*pperso).num_salle],(*pperso).xy.x,(*pperso).xy.y);
                donj[*nbS] = creer_s_valide(donj,donj[(*pperso).num_salle],(*pperso).num_porte,nbS,nbSmax,matrice,nbspotentielle,nbcaillou,nbstot,bobby_la,pperso);
                matrice[perso.xy.x+CST-1][perso.xy.y+CST] = 1;
            }
            else if(matrice[perso.xy.x+CST-1][perso.xy.y+CST] == 2){
                (*pperso).xy.x = (*pperso).xy.x -1;
                matrice[perso.xy.x+CST-1][perso.xy.y+CST] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 2;
            }
            else if(matrice[perso.xy.x+CST-1][perso.xy.y+CST] == 71){
                (*pperso).xy.x = (*pperso).xy.x -1;
                matrice[perso.xy.x+CST-1][perso.xy.y+CST] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 71;
                (*pperso).PV = (*pperso).PV-1;
            }
            else if(matrice[perso.xy.x+CST-1][perso.xy.y+CST] == 4){
                (*pperso).xy.x = (*pperso).xy.x -1;
                matrice[perso.xy.x+CST-1][perso.xy.y+CST] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 4;
            }
            else if(matrice[perso.xy.x+CST-1][perso.xy.y+CST] == 72){
                (*pperso).xy.x = (*pperso).xy.x -1;
                matrice[perso.xy.x+CST-1][perso.xy.y+CST] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 72;
                m=5;
            }
            else if(matrice[perso.xy.x+CST-1][perso.xy.y+CST] == 100){
                (*pperso).xy.x = (*pperso).xy.x -1;
                matrice[perso.xy.x+CST-1][perso.xy.y+CST] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 100;
            }
            else if(matrice[perso.xy.x+CST-1][perso.xy.y+CST] == 101){
                (*pperso).xy.x = (*pperso).xy.x -1;
                matrice[perso.xy.x+CST-1][perso.xy.y+CST] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 101;
            }
            else if(matrice[perso.xy.x+CST-1][perso.xy.y+CST] == 102){
                (*pperso).xy.x = (*pperso).xy.x -1;
                matrice[perso.xy.x+CST-1][perso.xy.y+CST] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 102;
            }
            else if(matrice[perso.xy.x+CST-1][perso.xy.y+CST] == 103){
                (*pperso).xy.x = (*pperso).xy.x -1;
                matrice[perso.xy.x+CST-1][perso.xy.y+CST] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 103;
            }
            else if(matrice[perso.xy.x+CST-1][perso.xy.y+CST] == 104){
                (*pperso).xy.x = (*pperso).xy.x -1;
                matrice[perso.xy.x+CST-1][perso.xy.y+CST] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 104;
            }
            else if(matrice[perso.xy.x+CST-1][perso.xy.y+CST] == 105){
                (*pperso).xy.x = (*pperso).xy.x -1;
                matrice[perso.xy.x+CST-1][perso.xy.y+CST] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 105;
            }
            else if(matrice[perso.xy.x+CST-1][perso.xy.y+CST] == 106){
                (*pperso).xy.x = (*pperso).xy.x -1;
                matrice[perso.xy.x+CST-1][perso.xy.y+CST] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 106;
            }
            else if(matrice[perso.xy.x+CST-1][perso.xy.y+CST] == 107){
                (*pperso).xy.x = (*pperso).xy.x -1;
                matrice[perso.xy.x+CST-1][perso.xy.y+CST] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 107;
            }
            else if(matrice[perso.xy.x+CST-1][perso.xy.y+CST] == 108){
                (*pperso).xy.x = (*pperso).xy.x -1;
                matrice[perso.xy.x+CST-1][perso.xy.y+CST] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 108;
            }
            else if(matrice[perso.xy.x+CST-1][perso.xy.y+CST] == 109){
                (*pperso).xy.x = (*pperso).xy.x -1;
                matrice[perso.xy.x+CST-1][perso.xy.y+CST] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 109;
            }
            else if(matrice[perso.xy.x+CST-1][perso.xy.y+CST] == 110){
                (*pperso).xy.x = (*pperso).xy.x -1;
                matrice[perso.xy.x+CST-1][perso.xy.y+CST] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 110;
            }
            else if(matrice[perso.xy.x+CST-1][perso.xy.y+CST] == 111){
                (*pperso).xy.x = (*pperso).xy.x -1;
                matrice[perso.xy.x+CST-1][perso.xy.y+CST] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 111;
            }
            else if(matrice[perso.xy.x+CST-1][perso.xy.y+CST] == 112){
                (*pperso).xy.x = (*pperso).xy.x -1;
                matrice[perso.xy.x+CST-1][perso.xy.y+CST] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 112;
            }
            else if(matrice[perso.xy.x+CST-1][perso.xy.y+CST] == 666){
                (*pperso).xy.x = (*pperso).xy.x -1;
                matrice[perso.xy.x+CST-1][perso.xy.y+CST] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 72;
            }
        break;
        case 3:
            if(matrice[perso.xy.x+CST][perso.xy.y+CST+1] == 7){
                (*pperso).xy.y = (*pperso).xy.y +1;
                matrice[perso.xy.x+CST][perso.xy.y+CST+1] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 7;
            }
            else if(matrice[perso.xy.x+CST][perso.xy.y+CST+1] == 2 && matrice[perso.xy.x+CST][perso.xy.y+CST+2] == 0){
                (*pperso).xy.y = (*pperso).xy.y +1;
                matrice[perso.xy.x+CST][perso.xy.y+CST+1] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 2;
                (*pperso).num_porte = num_p(matrice,donj[(*pperso).num_salle],(*pperso).xy.x,(*pperso).xy.y);
                donj[*nbS] = creer_s_valide(donj,donj[(*pperso).num_salle],(*pperso).num_porte,nbS,nbSmax,matrice,nbspotentielle,nbcaillou,nbstot,bobby_la,pperso);
                matrice[perso.xy.x+CST][perso.xy.y+CST+1] = 1;
            }
            else if(matrice[perso.xy.x+CST][perso.xy.y+CST+1] == 2){
                (*pperso).xy.y = (*pperso).xy.y +1;
                matrice[perso.xy.x+CST][perso.xy.y+CST+1] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 2;
            }
            else if(matrice[perso.xy.x+CST][perso.xy.y+CST+1] == 71){
                (*pperso).xy.y = (*pperso).xy.y +1;
                matrice[perso.xy.x+CST][perso.xy.y+CST+1] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 71;
                (*pperso).PV = (*pperso).PV-1;
            }
            else if(matrice[perso.xy.x+CST][perso.xy.y+CST+1] == 4){
                (*pperso).xy.y = (*pperso).xy.y +1;
                matrice[perso.xy.x+CST][perso.xy.y+CST+1] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 4;
            }
            else if(matrice[perso.xy.x+CST][perso.xy.y+CST+1] == 72){
                (*pperso).xy.y = (*pperso).xy.y +1;
                matrice[perso.xy.x+CST][perso.xy.y+CST+1] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 72;
                m=5;
            }
            else if(matrice[perso.xy.x+CST][perso.xy.y+CST+1] == 100){
                (*pperso).xy.y = (*pperso).xy.y +1;
                matrice[perso.xy.x+CST][perso.xy.y+CST+1] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 100;
            }
            else if(matrice[perso.xy.x+CST][perso.xy.y+CST+1] == 101){
                (*pperso).xy.y = (*pperso).xy.y +1;
                matrice[perso.xy.x+CST][perso.xy.y+CST+1] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 101;
            }
            else if(matrice[perso.xy.x+CST][perso.xy.y+CST+1] == 102){
                (*pperso).xy.y = (*pperso).xy.y +1;
                matrice[perso.xy.x+CST][perso.xy.y+CST+1] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 102;
            }
            else if(matrice[perso.xy.x+CST][perso.xy.y+CST+1] == 103){
                (*pperso).xy.y = (*pperso).xy.y +1;
                matrice[perso.xy.x+CST][perso.xy.y+CST+1] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 103;
            }
            else if(matrice[perso.xy.x+CST][perso.xy.y+CST+1] == 104){
                (*pperso).xy.y = (*pperso).xy.y +1;
                matrice[perso.xy.x+CST][perso.xy.y+CST+1] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 104;
            }
            else if(matrice[perso.xy.x+CST][perso.xy.y+CST+1] == 105){
                (*pperso).xy.y = (*pperso).xy.y +1;
                matrice[perso.xy.x+CST][perso.xy.y+CST+1] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 105;
            }
            else if(matrice[perso.xy.x+CST][perso.xy.y+CST+1] == 106){
                (*pperso).xy.y = (*pperso).xy.y +1;
                matrice[perso.xy.x+CST][perso.xy.y+CST+1] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 106;
            }
            else if(matrice[perso.xy.x+CST][perso.xy.y+CST+1] == 107){
                (*pperso).xy.y = (*pperso).xy.y +1;
                matrice[perso.xy.x+CST][perso.xy.y+CST+1] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 107;
            }
            else if(matrice[perso.xy.x+CST][perso.xy.y+CST+1] == 108){
                (*pperso).xy.y = (*pperso).xy.y +1;
                matrice[perso.xy.x+CST][perso.xy.y+CST+1] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 108;
            }
            else if(matrice[perso.xy.x+CST][perso.xy.y+CST+1] == 109){
                (*pperso).xy.y = (*pperso).xy.y +1;
                matrice[perso.xy.x+CST][perso.xy.y+CST+1] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 109;
            }
            else if(matrice[perso.xy.x+CST][perso.xy.y+CST+1] == 110){
                (*pperso).xy.y = (*pperso).xy.y +1;
                matrice[perso.xy.x+CST][perso.xy.y+CST+1] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 110;
            }
            else if(matrice[perso.xy.x+CST][perso.xy.y+CST+1] == 111){
                (*pperso).xy.y = (*pperso).xy.y +1;
                matrice[perso.xy.x+CST][perso.xy.y+CST+1] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 111;
            }
            else if(matrice[perso.xy.x+CST][perso.xy.y+CST+1] == 112){
                (*pperso).xy.y = (*pperso).xy.y +1;
                matrice[perso.xy.x+CST][perso.xy.y+CST+1] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 112;
            }
            else if(matrice[perso.xy.x+CST][perso.xy.y+CST+1] == 666){
                (*pperso).xy.y = (*pperso).xy.y +1;
                matrice[perso.xy.x+CST][perso.xy.y+CST+1] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 72;
            }
        break;
        case 4:
            if(matrice[perso.xy.x+CST][perso.xy.y+CST-1] == 7){
                (*pperso).xy.y = (*pperso).xy.y -1;
                matrice[perso.xy.x+CST][perso.xy.y+CST-1] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 7;
            }
            else if(matrice[perso.xy.x+CST][perso.xy.y+CST-1] == 2 && matrice[perso.xy.x+CST][perso.xy.y+CST-2] == 0){
                (*pperso).xy.y = (*pperso).xy.y -1;
                matrice[perso.xy.x+CST][perso.xy.y+CST-1] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 2;
                (*pperso).num_porte = num_p(matrice,donj[(*pperso).num_salle],(*pperso).xy.x,(*pperso).xy.y);
                donj[*nbS] = creer_s_valide(donj,donj[(*pperso).num_salle],(*pperso).num_porte,nbS,nbSmax,matrice,nbspotentielle,nbcaillou,nbstot,bobby_la,pperso);
                matrice[perso.xy.x+CST][perso.xy.y+CST-1] = 1;
            }
            else if(matrice[perso.xy.x+CST][perso.xy.y+CST-1] == 2){
                (*pperso).xy.y = (*pperso).xy.y -1;
                matrice[perso.xy.x+CST][perso.xy.y+CST-1] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 2;
            }
            else if(matrice[perso.xy.x+CST][perso.xy.y+CST-1] == 71){
                (*pperso).xy.y = (*pperso).xy.y -1;
                matrice[perso.xy.x+CST][perso.xy.y+CST-1] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 71;
                (*pperso).PV = (*pperso).PV-1;
            }
            else if(matrice[perso.xy.x+CST][perso.xy.y+CST-1] == 4){
                (*pperso).xy.y = (*pperso).xy.y -1;
                matrice[perso.xy.x+CST][perso.xy.y+CST-1] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 4;
            }
            else if(matrice[perso.xy.x+CST][perso.xy.y+CST-1] == 72){
                (*pperso).xy.y = (*pperso).xy.y -1;
                matrice[perso.xy.x+CST][perso.xy.y+CST-1] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 72;
                m=5;
            }
            else if(matrice[perso.xy.x+CST][perso.xy.y+CST-1] == 100){
                (*pperso).xy.y = (*pperso).xy.y -1;
                matrice[perso.xy.x+CST][perso.xy.y+CST-1] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 100;
            }
            else if(matrice[perso.xy.x+CST][perso.xy.y+CST-1] == 101){
                (*pperso).xy.y = (*pperso).xy.y -1;
                matrice[perso.xy.x+CST][perso.xy.y+CST-1] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 101;
            }
            else if(matrice[perso.xy.x+CST][perso.xy.y+CST-1] == 102){
                (*pperso).xy.y = (*pperso).xy.y -1;
                matrice[perso.xy.x+CST][perso.xy.y+CST-1] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 102;
            }
            else if(matrice[perso.xy.x+CST][perso.xy.y+CST-1] == 103){
                (*pperso).xy.y = (*pperso).xy.y -1;
                matrice[perso.xy.x+CST][perso.xy.y+CST-1] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 103;
            }
            else if(matrice[perso.xy.x+CST][perso.xy.y+CST-1] == 104){
                (*pperso).xy.y = (*pperso).xy.y -1;
                matrice[perso.xy.x+CST][perso.xy.y+CST-1] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 104;
            }
            else if(matrice[perso.xy.x+CST][perso.xy.y+CST-1] == 105){
                (*pperso).xy.y = (*pperso).xy.y -1;
                matrice[perso.xy.x+CST][perso.xy.y+CST-1] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 105;
            }
            else if(matrice[perso.xy.x+CST][perso.xy.y+CST-1] == 106){
                (*pperso).xy.y = (*pperso).xy.y -1;
                matrice[perso.xy.x+CST][perso.xy.y+CST-1] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 106;
            }
            else if(matrice[perso.xy.x+CST][perso.xy.y+CST-1] == 107){
                (*pperso).xy.y = (*pperso).xy.y -1;
                matrice[perso.xy.x+CST][perso.xy.y+CST-1] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 107;
            }
            else if(matrice[perso.xy.x+CST][perso.xy.y+CST-1] == 108){
                (*pperso).xy.y = (*pperso).xy.y -1;
                matrice[perso.xy.x+CST][perso.xy.y+CST-1] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 108;
            }
            else if(matrice[perso.xy.x+CST][perso.xy.y+CST-1] == 109){
                (*pperso).xy.y = (*pperso).xy.y -1;
                matrice[perso.xy.x+CST][perso.xy.y+CST-1] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 109;
            }
            else if(matrice[perso.xy.x+CST][perso.xy.y+CST-1] == 110){
                (*pperso).xy.y = (*pperso).xy.y -1;
                matrice[perso.xy.x+CST][perso.xy.y+CST-1] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 110;
            }
            else if(matrice[perso.xy.x+CST][perso.xy.y+CST-1] == 111){
                (*pperso).xy.y = (*pperso).xy.y -1;
                matrice[perso.xy.x+CST][perso.xy.y+CST-1] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 111;
            }
            else if(matrice[perso.xy.x+CST][perso.xy.y+CST-1] == 112){
                (*pperso).xy.y = (*pperso).xy.y -1;
                matrice[perso.xy.x+CST][perso.xy.y+CST-1] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 112;
            }
            else if(matrice[perso.xy.x+CST][perso.xy.y+CST-1] == 666){
                (*pperso).xy.y = (*pperso).xy.y -1;
                matrice[perso.xy.x+CST][perso.xy.y+CST-1] = 1;
                matrice[perso.xy.x+CST][perso.xy.y+CST] = ((*pperso).case_joueur);
                (*pperso).case_joueur = 72;
            }
        break;
    }
    num_s_perso(donj,pperso,(*nbS));
    if((*pperso).bobby.action ==1){
        deplacement_bobby(pperso,matrice);
    }
     affichage(pperso,matrice,fin);
    return m;
}

//fonction pour voir quel lettre est tapé.
short queltouche(char a[256],int matrice[DTAILLE][DTAILLE]){
    short b = 21;
    if(strcmp(a,"d")==0){
        b=0;
    }
    else if(strcmp(a,"q")==0){
        b=1;
    }
    else if(strcmp(a,"z")==0){
        b=2;
    }
    else if(strcmp(a,"s")==0){
        b=3;
    }
    else if(strcmp(a,"e")==0){
        b=4;
    }
    else if(strcmp(a,"a")==0){
        b=5;
    }
    else if(strcmp(a,"1")==0){
        b=6;
    }
    else if(strcmp(a,"2")==0){
        b=7;
    }
    else if(strcmp(a,"3")==0){
        b=8;
    }
    else if(strcmp(a,"4")==0){
        b=9;
    }
    else if(strcmp(a,"5")==0){
        b=10;
    }
    else if(strcmp(a,"6")==0){
        b=11;
    }
    else if(strcmp(a,"7")==0){
        b=12;
    }
    else if(strcmp(a,"8")==0){
        b=13;
    }
    else if(strcmp(a,"9")==0){
        b=14;
    }
    else if(strcmp(a,"10")==0){
        b=15;
    }
    else if(strcmp(a,"11")==0){
        b=16;
    }
    else if(strcmp(a,"12")==0){
        b=17;
    }
    else if(strcmp(a,"13")==0){
        b=18;
    }
    else if(strcmp(a,"r")==0){
        b=19;
    }
    else if(strcmp(a,"f")==0){
        b=20;
    }
    return b;

}

//fonction pour réalisé les action.
void actionafaire(short b, Perso* pperso,Perso*ptombe,int matrice[DTAILLE][DTAILLE],Salle* donj,int* nbS,int nbSmax,int* nbspotentielle,int* nbcaillou,int nbstot,int* bobby_la,int fin){
    Perso coffre = remplisagecoffre();
    if(b<0 || b>21){
        exit(1);
        printf("actionafaire");
    }
    Perso perso=*pperso;
    int m=6;
    Position_Autour alpha = pautour(perso);
    switch(b){
        case 0:
            m=1;
            m=mouvementperso(m,pperso,matrice,donj,nbS,nbSmax,nbspotentielle,nbcaillou,nbstot,bobby_la,fin);
        break;
        case 1:
            m=2;
            m=mouvementperso(m,pperso,matrice,donj,nbS,nbSmax,nbspotentielle,nbcaillou,nbstot,bobby_la,fin);
        break;
        case 2:
            m=3;
            m=mouvementperso(m,pperso,matrice,donj,nbS,nbSmax,nbspotentielle,nbcaillou,nbstot,bobby_la,fin);
        break;
        case 3:
            m=4;
            m=mouvementperso(m,pperso,matrice,donj,nbS,nbSmax,nbspotentielle,nbcaillou,nbstot,bobby_la,fin);
        break;
        case 4:
            verification_objet_statique(pperso,ptombe,matrice,alpha,fin);
        break;
        case 5:
            printf("le jeu est arrété.\n");
        break;
        case 6:
            prise_objet_main(pperso,6,matrice,fin);
        break;
        case 7:
            prise_objet_main(pperso,7,matrice,fin);
        break;
        case 8:
            prise_objet_main(pperso,8,matrice,fin);
        break;
        case 9:
            prise_objet_main(pperso,9,matrice,fin);
        break;
        case 10:
            prise_objet_main(pperso,10,matrice,fin);
        break;
        case 11:
            prise_objet_main(pperso,11,matrice,fin);
        break;
        case 12:
            prise_objet_main(pperso,12,matrice,fin);
        break;
        case 13:
            prise_objet_main(pperso,13,matrice,fin);
        break;
        case 14:
            prise_objet_main(pperso,14,matrice,fin);
        break;
        case 15:
            prise_objet_main(pperso,15,matrice,fin);
        break;
        case 16:
            prise_objet_main(pperso,16,matrice,fin);
        break;
        case 17:
            prise_objet_main(pperso,17,matrice,fin);
        break;
        case 18:
            prise_objet_main(pperso,18,matrice,fin);
        break;
        case 19:
            utilisation(pperso,matrice,fin);
        break;
        case 20:
            attaque(pperso,matrice,alpha,donj,fin);
        break;
    }
    if(m==5){
        short c = 0;
        char a[256];
        do{
            vide_buffer();
            c=scanf("%s",a);
            if(strlen(a) >= 254){
                exit(85);
                printf("problème trop de lettres");
            }
        }while(c != 1);
    }
}

void enchainement(Perso* pperso,int matrice[DTAILLE][DTAILLE],Salle* donj,int* nbS,int nbSmax,int* nbspotentielle,int* nbcaillou,int nbstot,int* bobby_la,Perso* ptombe){
    char a[256];
    short b;
    short c = 0;
    int fin = clock() +1000;
     affichage(pperso,matrice,fin);
    do{
        do{
            c=0;
            vide_buffer();
            c=scanf("%s",a);
            if(strlen(a) >= 254){
                exit(85);
                printf("problème trop de lettres");
            }
        }while(c != 1);
        b = queltouche(a,matrice);
        if(b<21 && b>=0){
            actionafaire(b,pperso,ptombe,matrice,donj,nbS,nbSmax,nbspotentielle,nbcaillou,nbstot,bobby_la,fin);
            deplacement_monstre_salle(matrice,&(donj[(*pperso).num_salle]),pperso);
        }
        if((*pperso).PV <1){
            Perso perso=*pperso;
            creation_tombe(pperso,ptombe,matrice);
             affichage(pperso,matrice,fin);
        }
        if((*pperso).nb_caillou_depose ==4){
            b=5;
            printf("Bien joué votre partie est TERMINÉE votre score est de %d",(*pperso).xp *100);
        }
    }while(b != 5 );
}

int num_s_perso(Salle* donj,Perso* j,int nbs){

  for(int i=0;i<nbs;i++){
    if(( (*j).xy.x >= donj[i].ox && (*j).xy.x <= donj[i].ox + donj[i].l -1) && ( (*j).xy.y >= donj[i].oy && (*j).xy.y <= donj[i].oy + donj[i].L-1)){
      (*j).num_salle = i;
    }
  }
}
