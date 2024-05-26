int sauvegarde(char nomJoueur[], int graine, int nbSalle, int chrono, int nbSalleMax, int boby_la, int nbCaillou, Salle* donjon, Perso* pperso, int matrice[DTAILLE][DTAILLE], Perso* ptombe);

int lecture(char nomJoueur[], int* graine, int* pNbSalle, int* pChrono, int* nbSalleMax, int* boby_la, int* nbCaillou, Salle* donjon, Perso* pperso, int matrice[DTAILLE][DTAILLE], Perso* ptombe);


void defile_txt(char txt[1000]);
int intro(char* nom_j,int* graine);

void vide_buffer();
int accueil();
