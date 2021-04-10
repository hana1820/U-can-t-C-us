#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

struct enigme
{
	SDL_Rect posneptune,possaturn,posmars,posintero,postext,posreponse,postsaturn,postmars,postneptune,positioncur,posconti;
	SDL_Surface *neptune,*saturn,*mars,*intero,*text,*reponse,*tneptune,*tsaturn,*tmars,*conti;
};
typedef struct enigme enigme;

void initEnigme(enigme *e);
void afficherEnigme(enigme e,SDL_Surface *screen);
void afficherEnigme2(enigme e,SDL_Surface *screen);
