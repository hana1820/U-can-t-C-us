#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "enigme.h"

int main (void)
{
int continuer = 1;
enigme e;
SDL_Surface *screen =NULL,*fond = NULL,*text,*reponse;
SDL_Rect positionfond,posneptune,possaturn,posmars,posintero,postext,posreponse,postsaturn,postmars,postneptune,posconti;
SDL_Event event;
SDL_Init(SDL_INIT_VIDEO);
if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("Unable to initialize SDL : %s\n", SDL_GetError());
		return 1;
	}
SDL_EnableKeyRepeat(10,60);

positionfond.x = 0;
positionfond.y = 0;
fond = IMG_Load("background.jpg");

while (continuer == 1)
    {
screen = SDL_SetVideoMode(1500,700,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
if (screen == NULL)
	{
		printf("Unable to set video mode : %s\n", SDL_GetError());
		return 1;
	}
SDL_WaitEvent(&event);

        switch (event.type)
	{
	case SDL_QUIT: 
		continuer= 0;
	        SDL_Quit();
		break;
	case SDL_KEYDOWN:
	 switch(event.key.keysym.sym)
                {   
		    case SDLK_ESCAPE:
		    		continuer=0;
		    		break; 
		    case SDLK_RETURN:
		    		afficherEnigme(e,screen);
		    		break;
                }
                break;
}

SDL_BlitSurface(fond,NULL,screen, &positionfond);
SDL_Flip(screen);

}
}

