#include "enigme.h"

void initEnigme(enigme* e)
{
e->intero = IMG_Load("intero.jpg");
e->posintero.x=0;
e->posintero.y=0;
e->neptune= IMG_Load("neptune.jpg");
e->posneptune.x=350;
e->posneptune.y=200;
e->saturn = IMG_Load("mars.jpg");
e->possaturn.x=650;
e->possaturn.y=200;
e->mars = IMG_Load("saturn.jpg");
e->posmars.x=950;
e->posmars.y=200;
}

void afficherEnigme(enigme e,SDL_Surface *screen)
{
int continuer=1,x,y,test2=0;
SDL_Surface *text,*reponse,*conti;
SDL_Rect postext,posreponse,posconti;
SDL_Event event;
initEnigme(&e);
TTF_Init();
TTF_Font *police = NULL;
police = TTF_OpenFont("Bubblegum.ttf",40);
SDL_Color bleumarine = {0,20,80};
SDL_Color bleu = {25,25,112};
SDL_Color rouge = {220,0,30};
SDL_Color vert = {20,220,30};

text=TTF_RenderText_Solid(police," LAQUELLE EST LA PLANETE NEPTUNE ? ",bleumarine);
postext.x=400;
postext.y=50;

posreponse.x=700;
posreponse.y=450;

SDL_BlitSurface(e.neptune,NULL,screen,&e.posneptune);
SDL_BlitSurface(e.saturn,NULL,screen,&e.possaturn);
SDL_BlitSurface(e.mars,NULL,screen,&e.posmars);
SDL_Flip(screen);

while (continuer)
{
      SDL_WaitEvent(&event); 

switch (event.type)
{
  case SDL_QUIT: 
{
  continuer=0;
	SDL_Quit();
}
  		case SDL_MOUSEMOTION:
  			x = event.motion.x;
 			y = event.motion.y;

if(( x > e.posneptune.x ) && ( x < e.posneptune.x + e.posneptune.w ) && ( y > e.posneptune.y ) && ( y < e.posneptune.y + e.posneptune.h ))
{e.neptune = IMG_Load("neptune2.jpg");}
else
{e.neptune = IMG_Load("neptune.jpg");}

if(( x > e.possaturn.x ) && ( x < e.possaturn.x + e.possaturn.w ) && ( y > e.possaturn.y ) && ( y < e.possaturn.y + e.possaturn.h ))
{e.saturn = IMG_Load("saturn2.jpg");}
else
{e.saturn = IMG_Load("saturn.jpg");}

if(( x > e.posmars.x ) && ( x <  e.posmars.x +  e.posmars.w ) && ( y >  e.posmars.y ) && ( y <  e.posmars.y +  e.posmars.h ))
{e.mars = IMG_Load("mars2.jpg");}
else
{e.mars = IMG_Load("mars.jpg");}

		break;
		case SDL_MOUSEBUTTONUP:
			
			if(( x > e.posneptune.x ) && ( x < e.posneptune.x + e.posneptune.w ) && ( y > e.posneptune.y ) && ( y < e.posneptune.y + e.posneptune.h ))
			{continuer=0;
									afficherEnigme2(e,screen);
			}
			
			if(( x > e.possaturn.x ) && ( x < e.possaturn.x + e.possaturn.w ) && ( y > e.possaturn.y ) && ( y < e.possaturn.y + e.possaturn.h ))
			{reponse=TTF_RenderText_Solid(police," FAUX ! ",rouge);}
			
			if(( x > e.posmars.x ) && ( x < e.posmars.x + e.posmars.w ) && ( y > e.posmars.y ) && ( y < e.posmars.y + e.posmars.h ))
			{reponse = TTF_RenderText_Solid(police," FAUX ! ",rouge);} 
		break;
}

SDL_BlitSurface(e.intero,NULL,screen, &e.posintero);
SDL_BlitSurface(text,NULL,screen, &postext);
SDL_BlitSurface(reponse,NULL,screen, &posreponse);
SDL_BlitSurface(e.neptune,NULL,screen, &e.posneptune);
SDL_BlitSurface(e.saturn,NULL,screen, &e.possaturn);
SDL_BlitSurface(e.mars,NULL,screen, &e.posmars);
SDL_Flip(screen);
}

}

void afficherEnigme2(enigme e,SDL_Surface *screen)
{
int x,y,continuer=1,test=0,test2=0;
SDL_Rect posneptune,posintero,possaturn,posmars,posreponse,posconti,postext,positioncur,postsaturn,postmars,postneptune;
SDL_Surface *neptune,*intero,*saturn,*mars,*text,*tneptune,*tsaturn,*tmars,*reponse,*conti;
SDL_Event event;

screen = SDL_SetVideoMode(1200,700,32,SDL_HWSURFACE | SDL_DOUBLEBUF);

TTF_Init();
TTF_Font *police = NULL;
police = TTF_OpenFont("Bubblegum.ttf",40);
SDL_Color bleumarine = {0,25,85};
SDL_Color bleu = {25,25,112};
SDL_Color rouge = {220,0,30};
SDL_Color vert = {20,220,30};

postext.x = 250;
postext.y = 25;
text = TTF_RenderText_Solid(police," DEPLACER LES IMAGES SOUS LEUR NOMS  ",bleumarine);

posintero.x = 0;
posintero.y = 0;
intero = IMG_Load("intero.jpg");

postneptune.x = 940;
postneptune.y = 80;
tneptune = TTF_RenderText_Solid(police," neptune ",bleu);

postsaturn.x = 540;
postsaturn.y = 80;
tsaturn = TTF_RenderText_Solid(police," saturn ",bleu);

postmars.x = 140;
postmars.y = 80;
tmars = TTF_RenderText_Solid(police," mars ",bleu);

posneptune.x = 500;
posneptune.y = 150;
neptune = IMG_Load("neptune.jpg");

possaturn.x = 500;
possaturn.y = 325;
saturn = IMG_Load("saturn.jpg");

posmars.x = 500;
posmars.y = 500;
mars = IMG_Load("mars.jpg");

while (continuer)
{      
	SDL_WaitEvent(&event); 
switch (event.type)
{
	case SDL_QUIT: 
			{
				continuer= 0;
				SDL_Quit();
			}

	case SDL_MOUSEBUTTONDOWN:
					x = event.motion.x;
 					y = event.motion.y;
 					
					if(( x > posneptune.x ) && ( x < posneptune.x + posneptune.w ) && ( y > posneptune.y ) && ( y < posneptune.y + posneptune.h ))
					test = 1;
					
					if(( x > possaturn.x ) && ( x < possaturn.x + possaturn.w ) && ( y > possaturn.y ) && ( y < possaturn.y + possaturn.h ))
					test = 2;
					
					if(( x > posmars.x ) && ( x < posmars.x + posmars.w ) && ( y > posmars.y ) && ( y < posmars.y + posmars.h ))
					test = 3;
					
					if(test2)
					{
						if(( x > posconti.x ) && ( x < posconti.x + posconti.w ) && ( y > posconti.y ) && ( y < posconti.y + posconti.h ))
						continuer = 0;
					}
				break;
	case SDL_MOUSEMOTION:
				x = event.motion.x;
				y = event.motion.y;
				
				positioncur.x = x;
				positioncur.y = y;
				
				if(test==1)
				{posneptune=positioncur;}
				
				if(test==2)
 				{possaturn=positioncur;}

				if(test==3)
 				{posmars=positioncur;}
 				
			        break;
				
	case SDL_MOUSEBUTTONUP:
				test=0;
			break;
}

if (posmars.x<120 && (possaturn.x>screen->w/3 && possaturn.x+possaturn.w<2*screen->w/3 ) && posneptune.x>2*screen->w/3+55)
{
posreponse.x=400;
posreponse.y=450;
reponse=TTF_RenderText_Solid(police," ****** BRAVO ****** ",vert);

posconti.x=900;
posconti.y=600;
conti = IMG_Load("conti.png");

test2=1;
}
else
{
reponse=NULL;
conti=NULL;
}

SDL_BlitSurface(intero,NULL,screen, &posintero);
SDL_BlitSurface(conti,NULL,screen, &posconti);
SDL_BlitSurface(neptune,NULL,screen, &posneptune);
SDL_BlitSurface(saturn,NULL,screen, &possaturn);
SDL_BlitSurface(mars,NULL,screen, &posmars);
SDL_BlitSurface(text,NULL,screen, &postext);
SDL_BlitSurface(tneptune,NULL,screen, &postneptune);
SDL_BlitSurface(tsaturn,NULL,screen, &postsaturn);
SDL_BlitSurface(tmars,NULL,screen, &postmars);
SDL_BlitSurface(reponse,NULL,screen, &posreponse);
SDL_Flip(screen);
}

SDL_FreeSurface(intero);
SDL_FreeSurface(neptune);
SDL_FreeSurface(saturn);
SDL_FreeSurface(mars);
SDL_FreeSurface(text);
SDL_FreeSurface(tneptune);
SDL_FreeSurface(tsaturn);
SDL_FreeSurface(tmars);
SDL_FreeSurface(reponse);

}

