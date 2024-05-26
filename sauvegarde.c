#include "define.h"
#include "sauvegarde.h"


int sauvegarde(char nomJoueur[], int graine, int nbSalle, int chrono, int nbSalleMax, int boby_la, int nbCaillou, Salle* donjon, Perso* pperso, int matrice[DTAILLE][DTAILLE], Perso* ptombe){ // La sauvegarde permet d'enregistrer la progression de la partie
    FILE* fichier=NULL;
    int a,v=VERSION;
    if(nomJoueur==NULL||donjon==NULL||pperso==NULL|| nbSalle==0){
      printf("Erreur des paramètres de sauvegarde\n");
      exit(10);
  }
    fichier= fopen(nomJoueur,"wb");// Création de la sauvegarde avec le nom du joueur
    if (fichier==NULL){
     printf("erreur_fichier\n");
     exit(11);
    }

    //Enregistrement des élements du main
    a=fwrite(&v, sizeof(int), 1, fichier);
    a+=fwrite(&graine, sizeof(int), 1, fichier);
    a+=fwrite(&nbSalle, sizeof(int), 1, fichier);
    a+=fwrite(&nbSalleMax, sizeof(int), 1, fichier);
    a+=fwrite(&boby_la, sizeof(int), 1, fichier);
    a+=fwrite(&nbCaillou, sizeof(int), 1, fichier);
    a+=fwrite(&chrono, sizeof(int), 1, fichier);
    if(a!=7){
     printf("Erreur d'écriture\n");
     return -1;
    }
    a=fwrite(donjon, sizeof(Salle), nbSalle, fichier);
    if(a!=nbSalle){
     printf("Erreur d'écriture\n");
     return -1;
    }
    a=fwrite(pperso, sizeof(Perso), 1, fichier);
    if(a!=1){
     printf("Erreur d'écriture\n");
     return -1;
    }
    a=fwrite(ptombe, sizeof(Perso), 1, fichier);
    if(a!=1){
     printf("Erreur d'écriture\n");
     return -1;
    }

    a=fwrite(matrice, sizeof(int), DTAILLE*DTAILLE, fichier);
    if(a!=DTAILLE*DTAILLE){
     printf("Erreur d'écriture\n");
     return -1;
    }

    fclose(fichier);
  return 1;
}




int lecture(char nomJoueur[], int* graine, int* pNbSalle, int* pChrono, int* nbSalleMax, int* boby_la, int* nbCaillou, Salle* donjon, Perso* pperso, int matrice[DTAILLE][DTAILLE], Perso* ptombe){
  //si le nom n'existe pas redemander le choix dans l'acceuil

    FILE* fichier=NULL;
    int a,v;
    if(nomJoueur==NULL||graine==NULL||pNbSalle==NULL||pChrono==NULL||nbSalleMax==NULL||donjon==NULL||pperso==NULL||matrice==NULL){
      printf("Erreur des paramètres de lecture\n");
      exit(12);
     }


    do{
      fichier= fopen(nomJoueur,"rb");
      if (fichier==NULL){
     printf("Je ne vous connais pas! Hors de ma vue vile chenapan !\n");
     sleep(2);
     return 0;

      }
    }while(fichier==NULL);





    a=fread(&v, sizeof(int), 1, fichier);
    a+=fread(graine, sizeof(int), 1, fichier);
    a+=fread(pNbSalle, sizeof(int), 1, fichier);
    a+=fread(nbSalleMax, sizeof(int), 1, fichier);
    a+=fread(boby_la, sizeof(int), 1, fichier);
    a+=fread(nbCaillou, sizeof(int), 1, fichier);
    a+=fread(pChrono, sizeof(int), 1, fichier);
    if(a!=7){
     printf("Erreur de lecture\n");
     return -1;
    }else if(v!=VERSION){
     printf("Erreur de version\n");
     exit(14);
    }
    a=fread(donjon, sizeof(Salle), *pNbSalle, fichier);
    if(a!=*pNbSalle){
     printf("Erreur de lecture\n");
     return -1;
    }
    a=fread(pperso, sizeof(Perso), 1, fichier);
    if(a!=1){
     printf("Erreur de lecture\n");
     return -1;
    }
    a=fread(ptombe, sizeof(Perso), 1, fichier);
    if(a!=1){
     printf("Erreur d'écriture\n");
     return -1;
    }
    a=fread(matrice, sizeof(int), DTAILLE*DTAILLE, fichier);
    if(a!=DTAILLE*DTAILLE){
     printf("Erreur de lecture\n");
     return -1;
    }
    fclose(fichier);


  return 1;
}



void vide_buffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}





void defile_txt(char txt[1000]){

  int nbc = strlen(txt);
  int timer = 0;
  int cpt = 0;

  //printf("nbchar : %d\n",nbc);

  char a;
  int sec;
  while(timer<=nbc){


    sec = (clock()*20/ CLOCKS_PER_SEC);

    if(sec > timer){
      system("clear");
      for(int i=0;i<timer;i++){
        printf("%c",txt[i]);
      }
      printf("\n");
      timer += 1;

    }
  }
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////


int intro(char* nom_j,int* graine){

  system("clear");

  char txt[1000] = "Vous étiez allé au village de Taefravhz pour acheter des daaps. Des petites baies que votre mère grand raffole. Combien vouliez vous lui en prendre ?\n";
  defile_txt(txt);



  int i=0;
  do{
    if(i==1){
      system("clear");
      printf("ARGHhh vous ne pourrez jamais avoir tant de baies car vous êtes pauvre !\nCombien voulez vous lui en prendre ?\n");
      vide_buffer();
    }
    i=1;
  }while(scanf("%d",graine)!=1||*graine<0 || *graine > 10);


  /*
  do{
    scanf("%d",graine);
  }while(*graine<0 || *graine > 1000000000000);
  getc(stdin);
  system("clear");
  */

  char txt2[1000] = "...";
  defile_txt(txt2);
  getc(stdin);
  system("clear");


  char txt3[1000] = "Norbertine Patricia Catherine (alias NPC) vous a demandé comment vous alliez depuis hier. Vous avez répondu\n - 'Haha j'adore les pommes de chez Paul. Et vous, comment ça va depuis trois semaines ?'\n";
  defile_txt(txt3);
  getc(stdin);

  printf("...\n");
  getc(stdin);
  system("clear");


  char txt5[1000] = "Nicolas Phillipe Christian (alias NPC_49) vous a rendu votre <truelle à tout faire> que vous lui aviez prêté après demain. Pour vous remercier, il vous a aussi donné 3 <pain surprise de Gertanbolg>.\n";
  defile_txt(txt5);
  getc(stdin);

  printf("...\n");
  getc(stdin);
  system("clear");


  char txt7[1000] = "Sur le chemin du retour, vous avez croisé un paysan qui vous a lancé : \n- 'Salut ! Je suis Pierre Natanaël Jean mais tout le monde m'appelle PNJ. Quel est votre nom ?'";
  defile_txt(txt7);


  i=0;
  int a;
  do{
    //printf("saissez votre nom d'emprunt chevalresque!\n");
    if(i){
    //printf("Il doit y avoir erreur messir vous n'avez malheureusement droit qu'a seulement 30\n");
    }
    a = scanf("%s", nom_j);
    i=1;
  }while(a!=1||strlen(nom_j)>TAILLEJ-1);




  if(strcmp(nom_j,"J'ai_la_peste_PNJ")==0){

    printf("\n\nVous n'avez pas parlé à PNJ (Pierre Natanaël Jean) et n'êtes pas allé dans la Forêt Sombre. Fécilitation vous n'entrez pas dans le donjon !\n");
    return 4;
  }



  getc(stdin);

  printf("- 'Merveilleux %s ! C'est un nom originalement banal dis donc.'\n",nom_j);
  getc(stdin);

  char txt9[1000] = "Ce brave paysan vous explique qu'il a perdu sa chèvre dans la Colline Fleurie. Affolé il vous a demandé de l'aider à la retrouver. Vous avez bien entendu accepté.\n";
  defile_txt(txt9);
  getc(stdin);
  system("clear");



  char txt10[1000] = "PNJ (Pierre Nathanaël Jean) est resté immobile sur le chemin alors que vous partiez à la recherche de Blanchette (sa chèvre).\n";
  defile_txt(txt10);
  getc(stdin);
  system("clear");

  char txt11[1000] = "Vous avez parcouru la prairie de long en large et avez fini par trouver des traces de pattes sur le sol. Elles se joignaient un peu plus loin à des traces de bottes rouges.\n'Mais qui ici a pu oser voler une chèvre à un honnête citoyen ?'. Vous avez donc pisté cet odieux personnage jusque dans la Forêt Sombre.\n";
  defile_txt(txt11);
  getc(stdin);
  system("clear");

  char txt12[1000] = "<< La Foret Sombre : De nombreuses légendes entourent ce lieu. Certains racontent que les soirs sans lune, tout est silencieux, trop silencieux. Jusqu'a ce qu'enfin un grand cri retantisse. Il est dit que ceux qui entendraient ce son, tout droit sortit des plus sombres cauchemars, deviendraient fou et se mettraient à errer dans ces bois. Toute tentative de communication avec ces pauvres malheureux serait alors vaine. Mais bien sur cela ne viendrait jamais à l'esprit de toute personne sensée de pénétrer dans cette forêt maudite. >>\n";
  defile_txt(txt12);
  getc(stdin);
  system("clear");

  printf("... ... ...\n");
  getc(stdin);
  system("clear");

  char txt13[1000] = "Un grand cri sortit des méandres les plus obscures inimaginables ! Ce son vous fit tomber au sol, inconsient.\n";
  defile_txt(txt13);
  getc(stdin);
  system("clear");


  printf("...\n");
  getc(stdin);

  printf("...\n");
  getc(stdin);

  printf("...\n");
  getc(stdin);


  char txt14[1000] = "Vous vous réveillez dans une salle éclairée par des torches accrochées aux murs de pierres. Il y a quatres portes anciennes sur chacun des côtés de la salle. Vous êtres au centre de quatres piédestraux. Il semble qu'un petit objet y était placé sur chacun d'entre eux...\n";
  defile_txt(txt14);

  return 1;
}












int accueil(char nomJoueur[], int* graine){// soit metre les pointeur direct ou faire la recherche de save dans main

    int scenar=-1;

    int i=0;
    int a,b;
    int choix=-1;
    system("clear");
    printf("*************************************\n");
    printf("*  Salut à toi, jeune aventurier !  *\n");
    printf("*************************************\n\n");
    printf("choisis ta destinée en actionnant un des pistons contenant les mêmes symboles\n");
    
    do{
        system("clear");
        printf("*************************************\n");
        printf("*           MENU PRINCIPAL          *\n");
        printf("*************************************\n");
        printf("1: commencer une nouvelle partie\n2: reprendre l'aventure\n3: Quitter cette aventure  \n\n");

        if(i){
            printf("Erreur de saisie, veuillez réessayer !\n");
        vide_buffer();

        }


        i=1;
    }while(scanf("%d", &choix)!=1||choix<1||choix>3);

    if(choix==3){
      return 3;
    }

    i=0;





    if(choix==1){ //demande de la graine et du nom
      do{
       system("clear");
       printf("*************************************\n");
       printf("*          NOUVELLE PARTIE          *\n");
       printf("*************************************\n");
       printf("1: Commencer avec le scénario\n2: Passer l'introduction\n3: Revenir en arrière\n\n");
       vide_buffer();
      }while(scanf("%d",&scenar)!=1||scenar < 1 || scenar > 3);




      if(scenar == 1){
        choix = intro(nomJoueur,graine);
      }else if(scenar == 2){   //pas d'intro
        i=0;
        do{
            system("clear");

            printf("Votre mère grand raffole de baies. Combien voulez-vous lui en prendre ?\n");
          if(i==1){
                printf("ARGHhh vous ne pourrez jamais prendre tant de baies car vous êtes pauvre !\nCombien voulez-vous lui en prendre ?\n");
                vide_buffer();
            }



            i=1;
        }while(scanf("%d", graine)!=1||*graine<1||*graine>10);

      }else if(scenar==3){
        system("clear");
        return accueil(nomJoueur, graine);

      }







    }
     if(choix==2||(choix==1 && scenar == 2)){
      i=0;
        do{
          system("clear");
          printf("*************************************\n");
          printf("*           NOM DU JOUEUR           *\n");
          printf("*************************************\n");
          printf("saissez votre nom d'emprunt chevalresque!\n");
          if(i){
          printf("\nIl doit y avoir erreur messir, vous n'avez malheureusement droit qu'à seulement 30 caractères.\n");
          }
          a=scanf("%s", nomJoueur);

          i=1;
       }while(a!=1||strlen(nomJoueur)>TAILLEJ-1);

      }


    return choix;

}
