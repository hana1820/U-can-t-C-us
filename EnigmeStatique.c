#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include<SDL/SDL_ttf.h>
#include"EnigmeStatique.h"

void InitEnigme(enigme *e)
{
e->e1=IMG_Load("images/e1.jpg");

e->pos1.x=0;
e->pos1.y=0;

e->postrue.x=0;
e->postrue.y=0;

e->postry.x=0;
e->postry.y=0;

e->posfalse.x=0;
e->posfalse.y=0;

}

void AfficherEnigme(enigme *e)
{

}

void ResoudreEnigme(enigme *e)
{

}


