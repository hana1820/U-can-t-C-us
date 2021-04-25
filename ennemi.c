/**
*@file ennemi.c
*@brief tache entite secondaire
*@author Ahmed Mtibaa
*@version 1
*@date Apr 01 ,2021
*
*Testing program for entite secondaire*
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "ennemi.h"
#include <time.h>
#include<unistd.h>
#define LARGEUR_FENETRE 1500
#define HAUTEUR_FENETRE 700
#define VITESSE_INIT_VOIT 70// vitesse de ennemi 
#define NB_VOIES 3//combien de animation de voiture 
#define LARG_enemi 175
#define LONG_enemi 175
#define MAX_enemi   1900 
int  collision(SDL_Rect poss,Ennemy *e)
{
  
//int nb=3 ;
if 
((poss.y>e->Position.y + e->Position.h ) ||( poss.y+poss.h< e->Position.y )||(poss.x+poss.w<e->Position.x) || (poss.x>e->Position.x + e->Position.w ))
 {

  return 0 ;
 // return 0 ;
 }else
 {
 return 1 ;
 } 
 /*else
 { 
 return 1 ; 
  //return 1 ; 
 }*/
}
void Initialisation_Ennemy(Ennemy * e,perso * perso)
{
int n  ; 
//Ennemy en [MAX_enemi] ; 
   srand(time(NULL)) ; 
e->Position.x=750;
e->Position.y=0;

//e->Direction=true;
e->Animation=1;
e->state=WAITING;//tache blanche
e->distance=300;
//e->distance_a=300;

//e->image=IMG_ Load("voiture") ; 
e->Animation_D[1]=IMG_Load("1g.png");
e->Animation_D[2]=IMG_Load("2g.png");
e->Animation_D[3]=IMG_Load("3g.png");

//e->Animation_G[1]=IMG_Load("1g.png");
//e->Animation_G[2]=IMG_Load("2g.png");
//e->Animation_G[3]=IMG_Load("3g.png");
/*for (n=0; n<NB_VOIES; n++) 
    
        e->xvoies[n] = (LARGEUR_FENETRE / NB_VOIES /2) + ((LARGEUR_FENETRE / NB_VOIES) * n)- (LARG_enemi/ 3); // 2= position de l'ennemi par rapp au perso
    
    e->vitesse = VITESSE_INIT_VOIT;
    e->y = 0; // 0= pos de descente de ennemi
 for (n=0; n<MAX_enemi; n++) {
        en[n].voie = rand() % NB_VOIES;
        en[n].y = (LONG_enemi + (LONG_enemi * 4) ) *(n + 1); // la descente dans chaque voie
        en[n].Position.w = LARG_enemi;
        en[n].Position.h = LONG_enemi;
    }*/
}

void Display_Ennemy(Ennemy *e,SDL_Surface *ecran)
{
/*if(e->Direction)
{
SDL_BlitSurface(e->Animation_D[e->Animation], NULL, ecran, &e->Position);
//SDL_Flip(ecran);
}
else
{*/ // e->Animation++ ; 
SDL_BlitSurface(e->Animation_D[e->Animation], NULL, ecran, &e->Position);
//SDL_Flip(ecran);
//}
}

void Animation_Ennemy(Ennemy *e ,perso * perso)
{
int n ; 
   srand(time(NULL)) ; 
//Ennemy en[MAX_enemi] ; 
 /*e->y += e->vitesse;
    for (n=0; n<MAX_enemi ; n++) {
     

      if (abs(e[n].y - e->y) < HAUTEUR_FENETRE) {
          e[n].visible = 1;
          e[n].Position.x = e->xvoies[e[n].voie];//position aleatoire enemi
            e[n].Position.y = HAUTEUR_FENETRE - (e[n].ys - e->y);//enemi deplacemnt aleatoire descend
            
       } else
            e[n].visible = 0;
    }*/
  for (n=0; n<NB_VOIES; n++) 
{

       e->xvoies[n] = (LARGEUR_FENETRE / NB_VOIES /2) + ((LARGEUR_FENETRE / NB_VOIES) * n) ;// 2= position de l'ennemi par rapp au perso
}
if (e->Position.y==0)
{
 e->voie = rand() % 3;
  //e->Position.y = (LONG_enemi + (LONG_enemi * 1) ) *(n + 1);
         e->Position.x = e->xvoies[e->voie];
       }
      if( collision(perso->poss,e)==0)
      {
      e->Position.y==0 ;
      }
int dist = (perso->poss.x - e->Position.x);
//position aleatoire enemi
if   ((dist > - e->distance) && (dist <  e->distance))
{
e->state=FOLLOWING;
}
else
{
e->state=WAITING;
}
switch(e->state)
{
case WAITING:
{
if (e->Position.y==300) 
{ 
e->Position.y-=20 ; 
}
e->Animation++;

if(e->Animation==4)
{
e->Animation=1;
}
/*if(e->Direction)
{
e->Direction=true;
}
else
{
e->Direction=false;

}*/

//if(e->Direction)
//{

e->Position.y-=20;


//e->Position.y-=200;
//sleep(1) ;
//}*/
/*else
{
e->Position.y+=20;

}

*/
break;
}


case FOLLOWING:
{
if (e->Position.y==300) 
{ 
e->Position.y-=20 ; 
}
e->Animation++;

if(e->Animation==4)
{
e->Animation=1;
}
if(dist<0)
{
e->Position.y+=20;

}
else
{
e->Position.y-=20;
/*if(e->Position.y==300)
{
e->Position.y+=20 ; 
} */
}

break;
}

}
}
/*int collision (SDL_Rect position1,SDL_Rect position2)
{
if( (position1.x > (position2.x+position2.w)) || (position2.x > (position1.x + position1.w)) ||
(position1.y > (position2.y + position2.h)) || (position2.y > (position1.y + position1.h)) )
{
return 0 ;
}
else
{
return 1 ; 
}
}*/



/*void setrectss(SDL_Rect clips[9][4])
{
int j,i ;
  for(int j=0;j<8;j++)
  {
    for (int i=0;i<4;i++)
    {
      clips[j][i].x=i*1536;
      clips[j][i].y=j*864;
      clips[j][i].h=864;
      clips[j][i].w=1536;
    }
  }
  for (int i=0;i<4;i++)
  {
    clips[8][i].x=i*1536;
    clips[8][i].y=j*864;
    clips[8][i].h=864;
    clips[8][i].w=1536;
  }
}
void Free_Ennemy(Ennemy *e)
{
for(int i=1;i<4;i++)
{
SDL_FreeSurface(e->Animation_D[i]);
SDL_FreeSurface(e->Animation_G[i]);
}
}*/
