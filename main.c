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
    int* pnbs = NULL;
    int nbstot = det_nbs();
    int nbspotentielle = 0;
    int nbcaillou = 0;
    Salle donj[nbstot];
    int matrice[DTAILLE][DTAILLE];

    /// partie aug à completer
    Perso perso;
    Perso* pperso = NULL;
    pperso = &perso;
    if(pperso == NULL){
    	printf("pperso probléme");
    	exit(2);
    }

    perso = initialisation_perso();
    ///
	creer_s_origine(donj, matrice, &nbs, &nbspotentielle);
    matrice[perso.xy.x+CST][perso.xy.y+CST] = 1;

    switch(accueil(nomJoueur, &graine)){
        case 1:  //commencement d'une nouvelle partie
            srand(graine);
            enchainement(pperso,matrice,donj,&nbs,nbstot,&nbspotentielle,&nbcaillou,nbstot,&bobby_la);
            sauvegarde(nomJoueur, graine, nbs, chrono, nbstot, bobby_la, nbcaillou, donj, pperso, matrice);
        break;

        case 2:  // récupération de la sauvegarde
            lecture(nomJoueur, &graine, &nbs, &chrono, &nbstot, &bobby_la, &nbcaillou, donj, pperso, matrice);
            enchainement(pperso,matrice,donj,&nbs,nbstot,&nbspotentielle,&nbcaillou,nbstot,&bobby_la);
        break;
        default:
            return 0;
        break;
    }


}
