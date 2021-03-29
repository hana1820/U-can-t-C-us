#ifndef EnigmeStatique_H_
#define EnigmeStatique_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

typedef struct enigme
{
    SDL_Surface *e1;
    SDL_Rect pos1;
    int etat;
};

void InitEnigme(enigme *e);
void AfficherEnigme(enigme *e);
void ResoudreEnigme(enigme *e);
