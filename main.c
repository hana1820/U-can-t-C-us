#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "function.h"



int main (void)
{
SDL_Surface *screen =NULL;
SDL_Init(SDL_INIT_VIDEO);
//SDL_EnableKeyRepeat(10,40);
int continuer=1;
screen = SDL_SetVideoMode(1500,480,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
SDL_Surface *fond=NULL/*,*image=NULL*/;
SDL_Rect positionfond;

//SDL_Rect positionimage;
SDL_Rect animepos[8];
SDL_Event event;
int frame=4;
Hero hero;
initPerso(&hero);
animepos[0].x=0;
animepos[0].y=0;
animepos[0].w=128;
animepos[0].h=180;

animepos[1].x=128;
animepos[1].y=0;
animepos[1].w=109;
animepos[1].h=180;

animepos[2].x=237;
animepos[2].y=0;
animepos[2].w=167;
animepos[2].h=180;

animepos[3].x=404;
animepos[3].y=0;
animepos[3].w=130;
animepos[3].h=180;

animepos[4].x=534;
animepos[4].y=0;
animepos[4].w=127;
animepos[4].h=180;

animepos[5].x=661;
animepos[5].y=0;
animepos[5].w=109;
animepos[5].h=180;

animepos[6].x=770;
animepos[6].y=0;
animepos[6].w=167;
animepos[6].h=180;

animepos[7].x=937;
animepos[7].y=0;
animepos[7].w=129;
animepos[7].h=180;



positionfond.x=0;
positionfond.y=0;
fond= IMG_Load("background.png");



double v_x=4;
double v_y;
double v_saut = -13;
double v_grav = 0.5;
 v_y = v_saut;

int test=0;

while (continuer == 1)
    {


deplacerPerso(&test,animepos,&frame,&hero.positionimage);

        SDL_PollEvent(&event);
        switch(event.type)
        {



            case SDL_QUIT:
                continuer = 0;

SDL_Quit();
                break;



                 
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {  


   case SDLK_ESCAPE:
continuer=0;
break;
   case SDLK_UP:


if (hero.positionimage.y >= 265)
             v_y = v_saut;
     do
     {
     saut(&hero.positionimage,v_x,&v_y,v_grav);

SDL_BlitSurface(fond,NULL,screen, &positionfond);
if(v_x>0)
SDL_BlitSurface(hero.image,&animepos[7],screen,&hero.positionimage);

if(v_x<0)
SDL_BlitSurface(hero.image,&animepos[3],screen,&hero.positionimage);
        SDL_Flip(screen);
}while (hero.positionimage.y < 265);



 break;
                   
                    case SDLK_RIGHT:


v_x=4;



                             animePersod(animepos,&frame);

hero.positionimage.x+=20;


   break;

                    case SDLK_LEFT:

 v_x=-4;

animePersog(animepos,&frame);


hero.positionimage.x-=20;


                        break;
     
                }
               

               
}
 
SDL_BlitSurface(fond,NULL,screen, &positionfond);


SDL_BlitSurface(hero.image,&animepos[frame],screen,&hero.positionimage);

SDL_Flip(screen);

}

}
