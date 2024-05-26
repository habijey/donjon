#include "define.h"
#include "perso.h"
#include "salle.h"





void gen_elt_s(int mat[DTAILLE][DTAILLE],Salle* s,int* num_salle,int* nbcaillou,int nbstot, int* bobby_la,Perso* j){
  printf("   --- GEN ELT S ---   \n");

  printf("num salle %d\n",*num_salle);
  //exit(1);

  //int bobby_la = 0;

  int elt = 0;
  s->nbm = 0;




  //GENERATION DES CAILLOUX
  if(*nbcaillou < 4){

    int proba_caillou = rand()%20;
    if(5-*nbcaillou == nbstot - *num_salle+1 || proba_caillou == 0){ //crée un caillou si le nombre de salle
      int cx,cy;
      do{
        cx = s->ox +1 +rand()%(s->l-2);
        cy = s->oy +1 +rand()%(s->L-2);
      }while(mat[cx+CST][cy+CST] != 7); //verifie que le caillou est bien sur du sol

      mat[cx+CST][cy+CST] = 100;
      *nbcaillou += 1;
      elt = 1;

      printf("\n\nCAILLOUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU\n\n");
    }



    else{
    int proba_caillou = rand()%10;
    if(proba_caillou == 0 && *nbcaillou-4 != *num_salle){

      int cx,cy;
      do{
        cx = s->ox +1 +rand()%(s->l-2);
        cy = s->oy +1 +rand()%(s->L-2);
      }while(mat[cx+CST][cy+CST] != 7); //verifie que le caillou est bien sur du sol

      mat[cx+CST][cy+CST] = 100;
      printf("COORD CAILLOU : %d %d\n",cx,cy);
      *nbcaillou += 1;
      elt = 1;

      printf("\n\nCAILLOUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU\n\n");
    }
    }
  }



   //GENERATION DE BOBBY
  if(*bobby_la == 0 && elt == 0){
    int proba_bobby = rand()%20;

    if(proba_bobby == 0){
      Bobby bobby;

      do{
        bobby.xy.x = s->ox +1 +rand()%(s->l-2);
        bobby.xy.y = s->oy +1 +rand()%(s->L-2);
      }while(mat[bobby.xy.x+CST][bobby.xy.y+CST] != 7); //verifie que le caillou est bien sur du sol

      mat[bobby.xy.x+CST][bobby.xy.y+CST] = 666;
      *bobby_la = 1;
      elt = 1;

      j->bobby = bobby;
    }

  }



  //GENERATION D'UN MONSTRE
  if(((s->l >=8 && s->L >= 6) || (s->l >=6 && s->L >= 8)) && elt == 0){
    int proba_m = rand()%2;
    printf("IF MONSTRE\n");
    //int app = 1;

    if(proba_m == 0){ //PLACE MONSTRE + STAT DU MONSTRE DANS SALLE
      s->nbm = rand()%4 +1;
      printf("NBM : %d\n",s->nbm);
      //int nbmonstre = 10;
      for(int i=0;i<s->nbm;i++){

        Monstre m;

        m.pv = 10;
        m.attaque = 2;

        //printf("FOR MONSTRE\n");

        do{
          m.xy.x = s->ox +1 +rand()%(s->l-2);
          m.xy.y = s->oy +1 +rand()%(s->L-2);
          printf("WHILE COORD MONSTRE : %d %d\n",m.xy.x,m.xy.y);
        }while(mat[m.xy.x+CST][m.xy.y+CST] != 7);// || mat[m.x+CST][m.y+CST] != 7);

        m.num_s = *num_salle;
        //printf("NUM SALLE MONSTRE : %d\n",m.num_salle);
        mat[m.xy.x+CST][m.xy.y+CST] = 9;

        s->m[i] = m;

        printf(" I : %d\n",i);
        printf("           COORD MONSTRE    : %d %d NUM S %d\n",m.xy.x,m.xy.y,m.num_s);
        printf("           COORD MONSTRE S  : %d %d NUM S %d\n",s->m[i].xy.x,s->m[i].xy.y,s->m[i].num_s);


      }
      elt = 1;
    }
  }
  
  
  


    //generation des objets
    int proba_objet = rand()%5;
    printf("OBJET :::::::::::::::         %d %d\n",proba_objet,elt);
    if(elt == 0 && proba_objet == 0){

      int x,y;
      do{
        x = s->ox +1 +rand()%(s->l-2);
        y = s->oy +1 +rand()%(s->L-2);
      }while(mat[x+CST][y+CST] != 7);

      mat[x+CST][y+CST] = rand()%12 + 101;

      elt = 1;


    }




  //GENERATION DE COFFRE
  int proba_coffre = rand()%20;

  if(proba_coffre == 0 && (s->l >5 && s->L>5) && elt ==0){
    int xcoffre, ycoffre;
    do{
      xcoffre = s->ox +2 +rand()%(s->l-4);
      ycoffre = s->oy +2 +rand()%(s->L-4);
    }while(mat[xcoffre+CST][ycoffre+CST] != 7); //verifie que le caillou est bien sur du sol
    mat[xcoffre+CST][ycoffre+CST] = 4;
    elt = 1;
  }

  





  int proba_s_feu = rand()%8;
  //int proba_s_feu = 0;
  //printf("OULOUUUUUUUUU\n");
  if(proba_s_feu == 0 && elt == 0){// && elt == 0){
    for(int i=0;i<s->l-2;i++){
      for(int j=0;j<s->L-2;j++){
        mat[s->ox+1+i+CST][s->oy+1+j+CST] = 71;
      }
    }
    elt = 1;
  }

  int proba_s_ral = rand()%10;
  if(proba_s_ral == 0 && elt == 0){// && elt == 0){
    for(int i=0;i<s->l-2;i++){
      for(int j=0;j<s->L-2;j++){
        mat[s->ox+1+i+CST][s->oy+1+j+CST] = 72;
      }
    }
    elt = 1;
  }




  printf("   --- FIN GEN ELT S ---   \n");

}












//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////


int verif_s(int mat[DTAILLE][DTAILLE],Salle s){

  printf("   ---VERIF S---   \n");

  //VERIF SI PORTES x2 SUR COTE
  int cpt0 = 0;
  int cpt1 = 0;
  int cpt2 = 0;
  int cpt3 = 0;

  for(int i=0;i<s.l;i++){//LIGNES
    if(mat[s.ox+i+CST][s.oy+CST] == 2){
      cpt0 += 1;
    }
    if(mat[s.ox+i+CST][s.oy+s.L-1+CST] == 2){
      cpt2 += 1;
    }
  }
  for(int i=0;i<s.L;i++){//COLONES
    if(mat[s.ox+CST][s.oy+i+CST] == 2){
      cpt3 += 1;
    }
    if(mat[s.ox+s.l-1+CST][s.oy+i+CST] == 2){
      cpt1 += 1;
    }
  }

  if((cpt0 > 1 || cpt1 > 1) || (cpt2 > 1 || cpt3 > 1)){//REGARDE LE NOMBRE DE PORTES PAR COTE
    printf("ERREUR : 2 PORTES SUR UN MUR\n");
    return 1;
  }
  ////////////

  //VERIF SI PORTE DANS COIN
  if(mat[s.ox+CST][s.oy+CST] == 2){
    printf("ERREUR : PORTE DANS COIN\n");
    return 1;
  }
  if(mat[s.ox+CST][s.oy+CST+s.L-1] == 2){
    printf("ERREUR : PORTE DANS COIN\n");
    return 1;
  }
  if(mat[s.ox+CST+s.l-1][s.oy+CST] == 2){
    printf("ERREUR : PORTE DANS COIN\n");
    return 1;
  }
  if(mat[s.ox+CST+s.l-1][s.oy+CST+s.L-1] == 2){
    printf("ERREUR : PORTE DANS COIN\n");
    return 1;
  }

  //VERIF SI PAS SUPERPOSITION DES MURS AVEC UN SOL D'UNE SAlLE EXISTANTE
  for(int i=0;i<s.l;i++){//LIGNES
    if(mat[s.ox+i+CST][s.oy+CST] == 7 || mat[s.ox+i+CST][s.oy+CST] == 71 || mat[s.ox+i+CST][s.oy+CST] == 72){
      printf("ERREUR : SUPERPOSITION\n");
      return 1;
    }
    if(mat[s.ox+i+CST][s.oy+s.L-1+CST] == 7 || mat[s.ox+i+CST][s.oy+s.L-1+CST] == 71 || mat[s.ox+i+CST][s.oy+s.L-1+CST] == 72){
      printf("ERREUR : SUPERPOSITION\n");
      return 1;
    }
  }
  for(int y=0;y<s.L;y++){//COLONES
    if(mat[s.ox+CST][s.oy+y+CST] == 7 || mat[s.ox+CST][s.oy+y+CST] == 71 || mat[s.ox+CST][s.oy+y+CST] == 72){
      printf("ERREUR : SUPERPOSITION\n");
      return 1;
    }
    if(mat[s.ox+s.l-1+CST][s.oy+y+CST] == 7 || mat[s.ox+s.l-1+CST][s.oy+y+CST] == 71 || mat[s.ox+s.l-1+CST][s.oy+y+CST] == 72){
      printf("ERREUR : SUPERPOSITION\n");
      return 1;
    }
  }

  //VERIFIE SI LA SALLE CONTIENT UNE SALLE EXISTANTE (RECOUVRE ENTIEREMENT UNE SALLE EXISTANTE)
  for(int x=1;x<s.l-1;x++){
    for(int y=1;y<s.l-1;y++){
      if(mat[s.ox+x+CST][s.oy+y+CST] == 7){
        return 1;
      }
    }
  }




  //VERIFIE SI UN MUR EST COLLE A UNE PORTE EXISTANTE
  //(VOIR SI CA MARCHE VRM)

  for(int x=0;x<s.l+2;x++){//LIGNES
    if(mat[s.ox+x +CST][s.oy-1 +CST] == 2 && mat[s.ox+x +CST][s.oy-1-1 +CST] != 8){
      printf("ERREUR 0 : PORTE COLLE A UN MUR DE LA SALLE\n\n");
      return 1;
    }
    if(mat[s.ox+x +CST][s.oy+s.L-1 +1 +CST] == 2 && mat[s.ox+x +CST][s.oy+s.L-1 +1-1 +CST] != 8){
      printf("ERREUR 1 : PORTE COLLE A UN MUR DE LA SALLE\n\n");
      return 1;
    }
  }

  for(int y=0;y<s.L+2;y++){//COLONES
    if(mat[s.ox-1 +CST][s.oy+y +CST] == 2 && mat[s.ox-1-1 +CST][s.oy+y +CST] != 8){
      printf("ERREUR 2 : PORTE COLLE A UN MUR DE LA SALLE\n\n");
      return 1;
    }
    if(mat[s.ox+s.l-1+1 +CST][s.oy+y +CST] == 2 && mat[s.ox+s.l-1+1+1 +CST][s.oy+y +CST] != 8){
      printf("ERREUR 3 : PORTE COLLE A UN MUR DE LA SALLE\n\n");
      return 1;
    }
  }


  printf("OK FIN VERIF S\n");
  return 0;
}


int verif_p(int mat[DTAILLE][DTAILLE],Salle s,int num_p){

  printf("   ---VERIF P---   \n");

  //VERIFIE SI LA CASE JUSTE APRES LA PORTE EST LIBRE
  switch(s.p[num_p].c){
    case 0:
      if(mat[s.p[num_p].x +CST][s.p[num_p].y +1 +CST] == 8){
        printf("IMPOSSIBLE DE CREER SALLE DERRIERE PORTE\n");
        return 1;
      }
    break;
    case 1:
      if(mat[s.p[num_p].x +1 +CST][s.p[num_p].y +CST] == 8){
        printf("IMPOSSIBLE DE CREER SALLE DERRIERE PORTE\n");
        return 1;
      }
      break;
      case 2:
        if(mat[s.p[num_p].x +CST][s.p[num_p].y -1 +CST] == 8){
          printf("IMPOSSIBLE DE CREER SALLE DERRIERE PORTE\n");
          return 1;
        }
      break;
      case 3:
        if(mat[s.p[num_p].x -1 +CST][s.p[num_p].y +CST] == 8){
        printf("IMPOSSIBLE DE CREER SALLE DERRIERE PORTE\n");
          return 1;
        }
      break;
    }


  //VERIF SI PORTE N'EST PAS SUR UN MUR DEJA EXISTANT
  if(mat[s.p[num_p].x+CST][s.p[num_p].y+CST] == 8){
    return 1;
  }


  printf("PORTE OK : PEUT GENERER SALLE\n\n");
  return 0;
}




Salle gen_p(int mat[DTAILLE][DTAILLE],Salle s,int nbS,int nbSmax,int* nbspotentielle){

  printf("   ---GEN P---   \n");

  //DETERMINE LE NOMBRE DE PORTE A AJOUTER AVEC LE NOMBRE DE SALLE ET LES PORTES NON OUVERTES

  /*
  do{
    ajtp = rand()%(4-s.nbp);
    printf("AJTP = %d\n",ajtp);
    printf("MAX portes = %d\n",nbSmax -nbS -*nbspotentielle -1);
    printf("nbspotentielle (sans new portes) = %d\n\n",*nbspotentielle);

    if(nbSmax -nbS -*nbspotentielle -1 < 0){
      exit(1);
    }

  }while(ajtp > nbSmax -nbS -*nbspotentielle -1);
  //exit(1);
  //int ajtp = rand()%(4-s.nbp);
  //int ajtp = 2;
  */
  /*
  while(ajtp > nbSmax-nbS){
    int ajtp = rand()%(4-s.nbp);
  }
  */
  ////////////////////////////////////////



  //FAIT UNE LISTE DES COTE DES PORTES, -1 POUR DES COTES NON REMPLIS
  int tab_c[4];
  tab_c[0] = -1;
  tab_c[1] = -1;
  tab_c[2] = -1;
  tab_c[3] = -1;

  //AFFICHE POUR DEBUG
  int long_tab_c = 0;
  /*
  for(int i=0;i<s.nbp;i++){
    tab_c[i] = s.p[i].c;
    long_tab_c += 1;
    printf("tab_c -> %d\n",tab_c[i]);
  }
  printf("\n");
  //DEBUG
  */

  //VERIF SI COTE POSSIBLES (non notés dans tab_c) PEUVENT ACCEUILLIR PORTE (pas de mur d'autres salles)
  //VERIF SI PRESENCE MUR AUX COTES
  //VERIF SI case libre après

  int cpt0=0,cpt1=0,cpt2=0,cpt3=0;

  for(int x=1;x<s.l-1;x++){//lIGNES
    printf("%d\n",mat[s.ox+x+CST][s.oy+CST]);
    if(mat[s.ox+x+CST][s.oy+CST] == 8 || mat[s.ox+x+CST][s.oy-1+CST] != 0){
      cpt2+=1;
      printf("cpt2 +1---------\n");
    }
    if(mat[s.ox+x+CST][s.oy+s.L-1+CST] == 8 || mat[s.ox+x+CST][s.oy+s.L-1+1+CST] != 0){
      cpt0+=1;
      printf("cpt0 +1---------\n");
    }
  }
  printf("\n");
  for(int y=1;y<s.L-1;y++){//COLONES
    printf("%d\n",mat[s.ox+CST][s.oy+y+CST]);
    if(mat[s.ox+CST][s.oy+y+CST] == 8 || mat[s.ox-1+CST][s.oy+y+CST] != 0){
      cpt3+=1;
      printf("cpt3 +1---------\n");
    }
    if(mat[s.ox+s.l-1+CST][s.oy+y+CST] == 8 || mat[s.ox+s.l-1+1+CST][s.oy+y+CST] != 0){
      cpt1+=1;
      printf("cpt1 +1---------\n");
    }
  }

  int cpt_cote_impossible = 0;
  if(cpt0 == s.l-2){
    tab_c[long_tab_c] = 0;
    printf("0 tab_c -> %d   ,%d\n",tab_c[long_tab_c],long_tab_c);
    long_tab_c += 1;
    cpt_cote_impossible += 1;
  }
  if(cpt2 == s.l-2){
    tab_c[long_tab_c] = 2;
    printf("2 tab_c -> %d   ,%d\n",tab_c[long_tab_c],long_tab_c);
    long_tab_c += 1;
    cpt_cote_impossible += 1;
  }
  if(cpt1 == s.L-2){
    tab_c[long_tab_c] = 1;
    printf("1 tab_c -> %d   ,%d\n",tab_c[long_tab_c],long_tab_c);
    long_tab_c += 1;
    cpt_cote_impossible +=1;
  }
  if(cpt3 == s.L-2){
    tab_c[long_tab_c] = 3;
    printf("3 tab_c -> %d   ,%d\n",tab_c[long_tab_c],long_tab_c);
    long_tab_c += 1;
    cpt_cote_impossible += 1;
  }


  //PLUS IDEM COTE QUE PORTE ORIGINE OU PORTES DEJA EXISTANTES
  printf("S NBP %d\n",s.nbp);
  for(int i=0;i<s.nbp;i++){
    if((s.p[i].c != tab_c[0] || s.p[i].c != tab_c[1]) || (s.p[i].c != tab_c[2] || s.p[i].c != tab_c[3])){ //verifie si cote p pas ajoute
      tab_c[long_tab_c] = s.p[i].c;
      long_tab_c += 1;
      cpt_cote_impossible += 1;
      printf("tab_c -> %d\n",tab_c[i]);
    }
  }
  
  
  if(long_tab_c == 0){
    tab_c[long_tab_c] = s.p[0].c;
    long_tab_c += 1;
  }


  //DEBUG
  printf("                           TAB C -> APRES AJT COTE IMPOSSIBLES\n");
  for(int i=0;i<long_tab_c;i++){
    printf("aff tab_c -> %d\n",tab_c[i]);
  }
  printf("\n");
  printf("NB COTE IMPOSSIBLE : %d\n",cpt_cote_impossible);
  //DEBUG


  ////DET NBP A AJOUTER A LA SALLE
  int ajtp;
  do{
    //ajtp = rand()%(5-cpt_cote_impossible);
    ajtp = rand()%(5)-cpt_cote_impossible;
    printf("nbsmax %d\n",nbSmax);
    printf("nbs %d\n",nbS);
    printf("nbsp %d\n",*nbspotentielle);
    printf("max %d\n\n",nbSmax-nbS-*nbspotentielle-1);

    printf("nb porte fermes %d\n",ajtp+*nbspotentielle);
    //printf("nbsp %d\n",*nbspotentielle);
  }while(ajtp>(nbSmax-nbS-*nbspotentielle-1) || (ajtp+*nbspotentielle == 0 && nbS+1 != nbSmax) || ajtp > 3);



  //ajtp = 3;
  printf("AJTP : %d\n\n",ajtp);


  //////////

  //DETERMINE LE COTE DE LA FUTURE PORTE
  for(int i=0;i<ajtp;i++){//POUR CHAQUE SALLE A AJOUTER

    //ON DETERMINE UN COTE LIBRE (qui n'est pas dans la liste des cotés déjà occupés)
    do{
    s.p[s.nbp].c = rand()%4;
    printf("cote rd : %d\n",s.p[s.nbp].c);
    printf("%d %d %d %d\n",tab_c[0],tab_c[1],tab_c[2],tab_c[3]);
    }while(((s.p[s.nbp].c == tab_c[0]) || (s.p[s.nbp].c == tab_c[1])) || ((s.p[s.nbp].c == tab_c[2]) || (s.p[s.nbp].c == tab_c[3])));


    tab_c[long_tab_c] = s.p[s.nbp].c;
    printf("\ntab_c ajt -> %d\n",tab_c[long_tab_c]);
    long_tab_c += 1;

    printf("\ncote definitif %d\n",s.p[s.nbp].c);
    //exit(1);
    /*
    if(i == 1 && nbS==4){
      exit(1);
    }
    */

    switch(s.p[s.nbp].c){//ON DETERMINE LES COORDONEES DE LA PORTE

      case 0:
        do{
        s.p[s.nbp].x = s.ox+1 + rand()%(s.l-2);
        s.p[s.nbp].y = s.oy +s.L-1;
        printf("NEW PORTE %d %d    DE COTE %d\n",s.p[s.nbp].x,s.p[s.nbp].y,s.p[s.nbp].c);
        }while(verif_p(mat,s,s.nbp) == 1);
      break;
      case 1:
        do{
        s.p[s.nbp].x = s.ox + s.l-1;
        s.p[s.nbp].y = s.oy+1 + rand()%(s.L-2);
        printf("NEW PORTE %d %d    DE COTE %d\n",s.p[s.nbp].x,s.p[s.nbp].y,s.p[s.nbp].c);
        }while(verif_p(mat,s,s.nbp) == 1);
      break;
      case 2:
        do{
        s.p[s.nbp].x = s.ox+1 + rand()%(s.l-2);
        s.p[s.nbp].y = s.oy;
        printf("NEW PORTE %d %d    DE COTE %d\n",s.p[s.nbp].x,s.p[s.nbp].y,s.p[s.nbp].c);
        printf("COORD S :%d %d l:%d L:%d\n",s.ox,s.oy,s.l,s.L);
        }while(verif_p(mat,s,s.nbp) == 1);
      break;
      case 3:
        do{
        s.p[s.nbp].x = s.ox;
        s.p[s.nbp].y = s.oy+1 + rand()%(s.L-2);
        printf("NEW PORTE %d %d    DE COTE %d \n",s.p[s.nbp].x,s.p[s.nbp].y,s.p[s.nbp].c);
        }while(verif_p(mat,s,s.nbp) == 1);
      break;
    }

    //ATTENTION POTENTIELLE BOUCLE INFINIE
    //A REGLER /!\
    //EXCLURE LES COORD DEJA TESTEES -> MODIF NBP
    /*
    if(verif_p(mat,s,s.nbp) == 1){
      i -= 1;
    }

    else{
      s.nbp += 1;
      *nbspotentielle += 1;
    }
    */
    s.nbp += 1;
    *nbspotentielle += 1;
  }




  //DEBUG
  for(int i=0;i<long_tab_c;i++){
    printf("tab_c -> %d\n",tab_c[i]);
  }
  //DEBUG

  //DEBUG
  printf("NBP : %d\n",s.nbp);
  printf("PORTE 0 : %d %d cote %d\n",s.p[0].x,s.p[0].y,s.p[0].c);
  printf("PORTE 1 : %d %d cote %d\n",s.p[1].x,s.p[1].y,s.p[1].c);
  printf("PORTE 2 : %d %d cote %d\n",s.p[2].x,s.p[2].y,s.p[2].c);
  printf("FIN GEN PORTE\n\n");
  return s;
}


Salle creerS(Salle* donj,Salle sorigine,int num_p,int nbS,int nbSmax,int mat[DTAILLE][DTAILLE],int* nbspotentielle,int* nbcaillou,int nbstot){

  printf("   ---CREER S---   \n");

  *nbspotentielle -= 1;

  Salle s;
  /*
  s.p[0].x = sorigine.p[num_p].x;//+DET COTE PORTE
  s.p[0].y = sorigine.p[num_p].y;
  s.p[0].c = (sorigine.p[num_p].c+2)%4;
  s.nbp = 1;
  */

  s.nbp = 0;

  s.l = rand()%(LONGMAX-3) +3;//determine une longueur aleatoire
  s.L = rand()%(LARGMAX-3) +3;//determine une largeur aleatoire
  printf("l:%d   L:%d\n",s.l,s.L);

  switch(sorigine.p[num_p].c){//le switch détermine le ox et oy de la salle
    case 0://si la porte est en HAUT
      s.ox = sorigine.p[num_p].x -1 -rand()%(s.l -2);
      s.oy = sorigine.oy +sorigine.L-1;//ok
      printf("HAUT\n");
    break;
    case 1://si la porte est à DROITE
      s.ox = sorigine.ox +sorigine.l-1;//ok
      s.oy = sorigine.p[num_p].y -1 -rand()%(s.L -2);
      printf("DROIT\n");
    break;
    case 2://si la porte est en BAS
      s.ox = sorigine.p[num_p].x  -1 -rand()%(s.l -2);
      s.oy = sorigine.oy -s.L +1;//ok
      printf("BAS %d:%d\n",s.ox,s.oy);
    break;
    case 3://si la porte est à GAUCHE
      s.ox = sorigine.ox -s.l +1;//ok
      s.oy = sorigine.p[num_p].y -1 -rand()%(s.L -2);
      printf("GAUCHE\n");
    break;
  }

  printf("ox:%d   oy:%d\n\n",s.ox,s.oy);





  //AJOUTE LES PORTES EXISTANTES DANS LES MURS DE LA SALLE
  for(int i=1;i<s.l-1;i++){//LIGNES
    if(mat[s.ox+i+CST][s.oy+CST] == 2){
      s.p[s.nbp].x = s.ox+i;
      s.p[s.nbp].y = s.oy;
      s.p[s.nbp].c = 2;
      printf("IFFF1 %d %d\n",s.p[s.nbp].x,s.p[s.nbp].y);
      s.nbp += 1;
      *nbspotentielle -= 1;//OUI MAIS AUSSI PORTE ORIGINE
    }
    if(mat[s.ox+i+CST][s.oy+CST+s.L-1] == 2){
      s.p[s.nbp].x = s.ox+i;
      s.p[s.nbp].y = s.oy+s.L-1;
      s.p[s.nbp].c = 0;
      printf("IFFF2 %d %d\n",s.p[s.nbp].x,s.p[s.nbp].y);
      s.nbp += 1;
      *nbspotentielle -= 1;
    }
  }
  for(int i=1;i<s.L-1;i++){//COLONES
    if(mat[s.ox+CST][s.oy+i+CST] == 2){
      s.p[s.nbp].x = s.ox;
      s.p[s.nbp].y = s.oy+i;
      s.p[s.nbp].c = 3;
      printf("IFFF3 %d %d\n",s.p[s.nbp].x,s.p[s.nbp].y);
      s.nbp += 1;
      *nbspotentielle -= 1;
    }
    if(mat[s.ox+s.l-1+CST][s.oy+i+CST] == 2){
      s.p[s.nbp].x = s.ox+s.l-1;
      s.p[s.nbp].y = s.oy+i;
      s.p[s.nbp].c = 1;
      printf("IFFF4 %d %d\n",s.p[s.nbp].x,s.p[s.nbp].y);
      s.nbp += 1;
      *nbspotentielle -= 1;
    }
  }


  /*
  do{
    s = gen_porte(donj,s,nbS,nbSmax);//CREE LES PORTES
    printf("WHILE GEN PORTE\n");
  }while(verif_p(donj,s,nbS,nbSmax == 1));
  */

  //VERIFIE QUE LES DIMENSIONS DE LA SALLE SOIENT POSSIBLES
  printf("nbp déjà existantes : %d\n\n",s.nbp);



  /*
  s.nbp=3;
  s.p[2].x=3;
  s.p[2].y=3;
  */
  //s.p[3].x=4;
  //s.p[3].y=4;
  printf("SALLE GENEREE\n");


  //GENERE DES PORTES SUPLEMENTAIRES A LA SALLE
  /*
  if(s.nbp<4){
    s = gen_p(mat,s,nbS,nbSmax,nbspotentielle);
  }
  */
  /*
   while(verif_s(mat,s) == 1){
    //nbspotentielle += 1;
    s = creerS(donj,sorigine,num_p,nbS,nbSmax,mat,nbspotentielle);
  }
  */

  return s;
}





int ajts_matrice(int mat[DTAILLE][DTAILLE],Salle s){
  //int* mat[DTAILLE][DTAILLE] = {mat_x,mat_y};

  printf("   ---AJTS MAT---   \n");


  int cst = DTAILLE/2;

  //PLACE LES MURS
  for(int x=0;x<s.l;x++){
    mat[s.ox+x+cst][s.oy+cst] = 8;
    printf("y%d  x%d\n",s.oy,s.ox+x);
    mat[s.ox+x+cst][s.oy+s.L-1+cst] = 8;
  }
  for(int y=0;y<s.L;y++){
    mat[s.ox+cst][s.oy+y+cst] = 8;
    mat[s.ox+s.l-1+cst][s.oy+y+cst] = 8;
  }
  //mat[0][0] = 7;

  //SOL DE LA SALLE
  for(int i=1;i<s.l-1;i++){
    for(int j=1;j<s.L-1;j++){
      mat[s.ox+i+cst][s.oy+j+cst] = 7;
    }
  }

  //PORTES
  printf("\ndebut porte (MATRICE)\n");
  printf("NBP : %d\n",s.nbp);
  for(int n=0;n<s.nbp;n++){

    printf("bcl porte %d\n",n);
    printf("PORTE %d   %d cote %d\n",s.p[n].x,s.p[n].y,s.p[n].c);

    mat[s.p[n].x+cst][s.p[n].y+cst] = 2;
  }
  printf("FIN AJTS MATRICE \n");

}

int det_nbs(){
  int nbs = rand()%(NBSMAX-NBSMIN)+NBSMIN;
  printf("NBS DONJ = %d\n",nbs);
  return nbs;
}







Salle creer_s_valide(Salle* donj,Salle sorigine,int num_p,int* nbS,int nbSmax,int mat[DTAILLE][DTAILLE],int* nbspotentielle,int* nbcaillou,int nbstot,int* bobby_la,Perso* j){

  printf("   ---CREER S VALIDE---   \n");

  Salle s;


  int savnbsp = *nbspotentielle;
  do{
    s = creerS(donj,sorigine,num_p,*nbS,nbSmax,mat,nbspotentielle,nbcaillou,nbstot);
    printf("UNE SALLE EST CREEE\n");
    if(verif_s(mat,s) == 1){
      *nbspotentielle = savnbsp;
    }
  }while(verif_s(mat,s) == 1);

  //s = gen_porte(donj,s,nbS,nbSmax,nbspotentielle);//CREE LES PORTES
  if(s.nbp<4){
    s = gen_p(mat,s,*nbS,nbSmax,nbspotentielle);
  }
  printf("\n\n%d\n",*nbS);
  //exit(1);
  ajts_matrice(mat,s);
  gen_elt_s(mat,&s,nbS,nbcaillou,nbstot,bobby_la,j); //gen_elt_s(int mat[DTAILLE][DTAILLE],Salle* s,int num_salle)

  //ajts_matrice(mat,s);

  *nbS += 1;

  printf("   ---FIN CREER S VALIDE---   \n");
  return s;
}



void creer_s_origine(Salle* donj,int mat[DTAILLE][DTAILLE],int* nbS,int* nbspotentielle){

  for(int i=0;i<DTAILLE;i++){
    for(int j=0;j<DTAILLE;j++){
      mat[i][j] = 0;
    }
  }

  Salle s;
  s.ox = 0;
  s.oy = 0;
  s.l = 11;
  s.L = 11;
  s.nbp = 4;

  s.p[0].x = 9;
  s.p[0].y = 10;
  s.p[0].c = 0;

  s.p[1].x = 10;
  s.p[1].y = 9;
  s.p[1].c = 1;

  s.p[2].x = 2;
  s.p[2].y = 0;
  s.p[2].c = 2;

  s.p[3].x = 0;
  s.p[3].y = 1;
  s.p[3].c = 3;

  donj[0] = s;

  *nbS = 1;
  *nbspotentielle = 4;

  ajts_matrice(mat,donj[0]);


  mat[5 +CST][3 +CST] = 51;
  mat[3 +CST][5 +CST] = 51;
  mat[7 +CST][5 +CST] = 51;
  mat[5 +CST][7 +CST] = 51;


}


int num_p(int mat[DTAILLE][DTAILLE],Salle s,int x,int y){

  for(int i=0;i<s.nbp;i++){
    if(s.p[i].x == x && s.p[i].y == y){
      return i;
    }
  }

  //printf("ERREUR : COORD PORTE PAS EXISTANTE");
  //exit(1);
}
