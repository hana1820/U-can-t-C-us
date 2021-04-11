#include <stdio.h> 
#include <stdlib.h> 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
//#include <SDL/SDL_mixer.h>
//#include <SDL/SDL_ttf.h> 
#include "ennemi.h"
/* constantes */
#define LARGEUR_FENETRE 1500//largeur fenetre 
#define HAUTEUR_FENETRE 700 //hauteur fenetre 
#define VITESSE_INIT_VOIT 30// vitesse de ennemi

#define NB_VOIES 4 //combien de animation de l'ennemi
#define LARG_ennemi 175
#define LONG_ennemi 166

#define MAX_ennemi  1900 //
int main(int argc ,char *argv[]) 
{ 
 //struct perso perso ; 
int framej=0,frame=0,aux=0;
SDL_Init(SDL_INIT_VIDEO) ; 
 fprintf(stderr,"EROOR SDL ;%s\n",SDL_GetError()) ; 
SDL_Surface *screen=NULL ,*back=NULL,*astronaute=NULL,*ennemii=NULL ; 
screen=SDL_SetVideoMode(1500,700,24,SDL_HWSURFACE|SDL_DOUBLEBUF) ; 
back=IMG_Load("sprite.png") ; 
 //SDL_Rect rectss [9][4] ;
 //setrectss(rectss) ;
 
 //astronaute
 astronaute=IMG_Load("astronaute.png") ;   
 //SDL_Rect  poss ; 
// perso.poss.x=580 ;  
 //perso.poss.y=400 ; 
  
  
 

int continuer=1,/* boucle infinie*/ framee=0;  
//int c=3 ;  
SDL_Rect pos ; 
Uint32 starttick;
pos.x=0; 
pos.y=0 ; 

   //struct astronaute astronaute;
	
    struct enemi ennemis [MAX_ennemi];
    
    
     initEnnemi(ennemis);
//SDL_Flip(screen) ; 
const int fps=10;
int n ;
int nbre_vie=3  ; 
int score=3; 
 while(continuer) 
 { 
  
   starttick = SDL_GetTicks();

deplaceranimer(ennemis)  ;
  
 SDL_BlitSurface(astronaute,NULL, screen, &ennemis->poss);
 
  
SDL_Event event;
  
while (SDL_PollEvent(&event))  
{ 
switch(event.type) 
{ 
 case SDL_QUIT  : 
 { 
 return 0 ; 
 break; 
 } 
  case SDL_KEYDOWN :
 { if(event.key.keysym.sym==SDLK_ESCAPE)
 
return 0 ;  
}  

// effzfzgzg

if (event.key.keysym.sym==SDLK_RIGHT)
{ 
ennemis->poss.x+=450;
//aux++;
//if (aux==3) 
{
//poss.y+=50 ;
//poss.x=-300 ;
//system("PAUSE") ;   
}

 //SDL_BlitSurface(image,&rects[framej][frame],screen,&pos) ;

 //SDL_Flip(screen) ; 
} else if (event.key.keysym.sym=SDLK_LEFT)
{
ennemis->poss.x-=450;
if  (collision (ennemis->poss,ennemis)) 
               {
               continuer=0 ; 
                                      
               }else 
               {
               continuer=1 ;
  
               } //  SDL_Flip(screen);

//if (perso.poss.x==700) 
//{
//perso.poss.x+=300;
//}
}



  
}
}


 SDL_BlitSurface(back,NULL,screen,&pos) ;
SDL_BlitSurface(astronaute,NULL, screen, &ennemis->poss);
afficher(screen,ennemis) ;
    

     
         if  (collision (ennemis->poss,ennemis)) 
               {
               continuer=0 ; 
               }else 
               {
               continuer=1 ;
               }


		  SDL_Flip(screen);
		  if(1000/fps>SDL_GetTicks()-starttick)
{
SDL_Delay( 1000/fps-(SDL_GetTicks()-starttick) );
} 
}
SDL_FreeSurface(back) ; 
SDL_FreeSurface(astronaute) ; 
SDL_FreeSurface(ennemii) ; 
SDL_FreeSurface(screen) ; 
SDL_Quit() ;
return  0;   
} 

