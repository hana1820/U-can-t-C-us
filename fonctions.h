#ifndef ANIMER_PERSONNAGE_H_INCLUDED
#define ANIMER_PERSONNAGE_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>



int Animer_Personnage(int *frametime ,int nmb_frame,int frame);

typedef struct 
{

int X;
int Y;

}Coordinate;


int Collision_Parfaite();
SDL_Color GetPixel(SDL_Surface *background ,Coordinate C);



#endif

