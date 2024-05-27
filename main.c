#include "define.h"
#include "salle.h"
#include "perso.h"
#include "bobby.h"
#include "sauvegarde.h"
#include "monstre.h"

int main(){

    char nomJoueur[31];
    int graine;
    int chrono=1000;

    int bobby_la = 0;
    int nbs = 0;
    int nbstot = det_nbs();
    int nbspotentielle = 0;
    int nbcaillou = 0;
    Salle donj[nbstot];
    int matrice[DTAILLE][DTAILLE];
    int a;
    int choix=-1;
    int i=0;
    /// partie aug à completer
    Perso perso;
    Perso* pperso = NULL;
    pperso = &perso;
    if(pperso == NULL){
        printf("pperso probléme");
        exit(2);
    }
    Perso tombe;
    Perso* ptombe = NULL;
    ptombe = &tombe;
    if(ptombe == NULL){
        exit(21);
        printf("ptombe probléme");
    }


    do{
        creer_s_origine(donj, matrice, &nbs, &nbspotentielle);
        perso = initialisation_perso();
        matrice[perso.xy.x+CST][perso.xy.y+CST] = 1;
        a=accueil(nomJoueur, &graine);
        switch(a){
            case 1:  //commencement d'une nouvelle partie
            break;

            case 2:  // récupération de la sauvegarde
                a=lecture(nomJoueur, &graine, &nbs, &chrono, &nbstot, &bobby_la, &nbcaillou, donj, pperso, matrice, ptombe);
                if(a==0||a==-1){
                    a=0;
                }else{
                    a=2;
                }
            break;
            case 4:
                pperso->nb_caillou_depose=4;
            break;
            default:
                return 0;
            break;
        }
        if(a==1||a==2){
            srand(graine);
            enchainement(pperso,matrice, donj,&nbs,nbstot,&nbspotentielle,&nbcaillou,nbstot,&bobby_la, ptombe);
            sauvegarde(nomJoueur, graine, nbs, chrono, nbstot, bobby_la, nbcaillou, donj, pperso, matrice, ptombe); 
        }
        
        if(pperso->nb_caillou_depose==4){

            do{
                system("clear");
                printf("\n1: revenir au menu   2: sortir du jeu \n");
                if(i==1){
                    printf("Erreur de saisie\n");
                    vide_buffer();
                }
                i=1;
            }while(scanf("%d", &choix)!=1||choix!=1 && choix!=2);
            if(choix==2){
                return 0;
            }
        }


    }while(a!=3);
}
