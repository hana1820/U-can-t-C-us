#include "fonctions.h"



int Animer_Personnage(int *frametime ,int nmb_frame,int frame )
{
int FPS=60;

							if (FPS/(*frametime)==5)
							{(*frametime)=0;
							frame++;
							if (frame==nmb_frame)
							{frame=0;}}
							return frame;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Collision_Parfaite(SDL_Surface *Background,Coordinate C)
{int collision=0;
SDL_Color color;

color=GetPixel(Background,C);

if (color.r==0 && color.g==0 && color.b==0)
{collision=1;}

return collision;

}





SDL_Color GetPixel(SDL_Surface *Background ,Coordinate C)
{


SDL_Color color;
//int bpp = background->format->BytesPerPixel;
Uint32 col=0;

char* pPosition=(char* ) Background->pixels;

pPosition+= (Background->pitch * C.Y);
pPosition+= (Background->format->BytesPerPixel * C.X);

memcpy(&col ,pPosition ,Background->format->BytesPerPixel);
/*
    Uint8 *p = (Uint8 *)background->pixels + C.Y * background->pitch + C.X * bpp;
 	col=*(Uint32*)p;*/
SDL_GetRGB(col,Background->format, &color.r, &color.g, &color.b);


return (color);




}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

