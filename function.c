#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "function.h"

void animePersod (SDL_Rect animepos[],int *frame)
{
if(*frame<4)
*frame=3;
(*frame)++;


if(*frame>7)
*frame=4;


}
 
void animePersog (SDL_Rect animepos[],int *frame)
{
if (*frame>=4)
*frame=-1;
(*frame)++;
if (*frame==2)
*frame=3;


if(*frame>3)
*frame=0;
}
void initPerso(Hero* hero)
{
SDL_Surface* tmp  ;
         tmp = IMG_Load("anim.png");
hero->image = tmp;
SDL_Rect pos;
pos.x=0;
pos.y=265;
hero->positionimage=pos;
hero->score=0;
hero->vies=10;
}

void deplacerPerso(int* test,SDL_Rect animepos[],int *frame,SDL_Rect* poshero)
{

if (*test==1)
                  {  animePersod(animepos,frame);

poshero->x+=20;
 
}




if (*test==2)
                  {  
                  animePersog(animepos,frame);

poshero->x-=20;




}
}
void saut(SDL_Rect *positionimage,double v_x,double* v_y,double v_grav)
{    

if(v_x>0)
 
            positionimage->x += v_x;
if(v_x<0)

            positionimage->x += v_x;

            positionimage->y += (*v_y);
               (*v_y) += v_grav;
}


