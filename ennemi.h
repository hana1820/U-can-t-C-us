#ifndef ENNEMY_H_INCLUDED
#define ENNEMY_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
//#include "player.h"
#define LARGEUR_FENETRE 1500
#define HAUTEUR_FENETRE 700
#define VITESSE_INIT_VOIT 70// vitesse de ennemi 
#define NB_VOIES 3//combien de animation d'astronaute 
#define LARG_enemi 175
#define LONG_enemi 175
#define MAX_enemi   1900
/**
*@struct entite secondaire
*@brief struct for entite secondaire
*/
typedef enum STATE STATE;
enum STATE{
WAITING,
FOLLOWING,
//ATTACKING
};


typedef struct 
{
SDL_Surface *Animation_G[3];
SDL_Surface *Animation_D[3];
SDL_Surface *image;
int Animation;
SDL_Rect Position;
//bool Direction;
STATE state;
int distance;
//int distance_a;
int vitesse ;
int xvoies[NB_VOIES];
int voie ; 
int ys ; //on place la ennemi à l'origine 0
int visible ; 

}Ennemy;

typedef struct 
{ 
SDL_Rect poss ; 
} perso ; 
int  collision(SDL_Rect poss,Ennemy *e) ;
//int collision (SDL_Rect position1,SDL_Rect position2) ;
void Initialisation_Ennemy(Ennemy * e,perso * perso);
void Display_Ennemy(Ennemy *e,SDL_Surface *ecran);
void Animation_Ennemy(Ennemy *e,perso * perso);
void Free_Ennemy(Ennemy *e);
//void setrectss(SDL_Rect clips[9][4]) ;


#endif
