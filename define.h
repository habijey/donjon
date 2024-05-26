#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#define LONGMIN 3
#define LARGMIN 3
#define LONGMAX 10
#define LARGMAX 10
#define NBSMAX 20
#define NBSMIN 6
#define DTAILLE 38
#define CST DTAILLE/2
#define VERSION 2
#define TAILLEJ 31


typedef struct{
    short x;
    short y;
}Position;

typedef struct{
	Position xy;
    int action;
    Position ancienne_pj;
}Bobby;

typedef struct{
    short epee_en_bois;
    short dague;
    short epee_en_fer;
    short armure_fer;
    short armure_cuire;
    short demi_armure_fer;
    short demi_armure_cuire;
    int pomme;
    int clee;
    int torche;
    int potion;
    int fiole_de_xp;
    int roche;
}Inventaire;

typedef struct{
    short PV;
    short case_joueur;
    int num_salle;
    int num_porte;
    int xp;
    Position xy;
    Inventaire inventaire;
    Bobby bobby;
	char objet_en_main[256];
    int attaque;
    int defense;
    int nb_caillou_depose;
}Perso;

typedef struct{
    Position haut;
    Position bas;
    Position droite;
    Position gauche;
}Position_Autour;

typedef struct{
  int pv;
  int attaque;
  Position xy;
  int num_s;
}Monstre;

typedef enum{
    H,D,B,G
}Cote;

typedef struct{
    int x,y;
    Cote c;
    //Statut_porte s;
}Porte;

typedef struct{
    int l, L; //longueur et largeur des salles
    int ox,oy;//coordonnée du coin bas gauche de la salle
    int nbp;
    Porte p[4]; //pointeur vers la liste des portes de la salle
    int nbm;
    Monstre m[4];
}Salle;

typedef struct{
    Salle* donj;
    int nbS;
    int nbSmax;
    int nbspotentielle;
    int nbcaillou;
    int nbstot;
    int bobby_la;
    int chrono;
}Info;
