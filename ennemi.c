#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include "ennemi.h"
/* constantes */
#define LARGEUR_FENETRE 1500
#define HAUTEUR_FENETRE 700
#define VITESSE_INIT_VOIT 30// vitesse de ennemi 
#define NB_VOIES 4//combien de animation de voiture 
#define LARG_ennemi 175
#define LONG_ennemi 175


#define MAX_ennemi   1900 
int  collision(SDL_Rect poss,struct enemi ennemis[])
{
int n , p  ; 
SDL_Surface *ecran  ;
// ennemis->nbre_vie=3 ;  ; 
int debut=0 ;
//debut : 
    for (n=0; n<1900 ; n++) {
     //p=MAX_ennemi-n ;
     debut++ ; 
if 
((poss.y>ennemis[n].coord.y + ennemis[n].coord.h) ||( poss.y+poss.h<ennemis[n].coord.y)||(poss.x+poss.w<ennemis[n].coord.x) || (poss.x>ennemis[n].coord.x + ennemis[n].coord.w))
 {
return 0 ; 


//ennemis->nbre_vie-- ;
 } else 
//(!(poss.y>ennemis[n].coord.y + ennemis[n].coord.h) ||(poss.x+poss.w<ennemis[n].coord.x) || (poss.x>ennemis[n].coord.x + ennemis[n].coord.w))
 {
 
// initEnnemi(ennemis) ; 
 //deplaceranimer(ennemis) ;
  //afficher(  ecran ,ennemis);
  if(debut != 1900) 
  {
  return 1;
  }
  //return 1 ; 
   
 }
 
/*if (ennemis->nbre_vie==0) 
{
return 1; 
}else 
{
return 0 ; 
} */
 //return debut  ;  
}
/*if (vie==0)
{ 
return 0 ;
}else 
{
return 1  ;
} */

}

 
 
void initEnnemi( struct enemi ennemis[]) 
{
 
    int i,n;
   srand(time(NULL)) ; 
  
ennemis->Animation_D[1]=IMG_Load("SS.png");

//enemis->Animation_D[2]=IMG_Load("2g.png");
//enemis->Animation_D[3]=IMG_Load("3g.png");

ennemis->poss.y=400 ; 
ennemis->poss.x=580  ;   
ennemis->poss.h=392  ; 
ennemis->poss.w=386 ; 

    for (n=0; n<NB_VOIES; n++) 

       ennemis->xvoies[n] = (LARGEUR_FENETRE / NB_VOIES /2) + ((LARGEUR_FENETRE / NB_VOIES) * n)- (LARG_ennemi/ 3); // 2= position de l'ennemi par rapp au perso
       //collision(enemis->poss,enemis) ;
    ennemis->vite = VITESSE_INIT_VOIT;
    ennemis->ys = 0; // 0= pos de descente de ennemi

    /* init ennemi */
    for (n=0; n<MAX_ennemi; n++) {
 
        ennemis[n].voie = rand() % NB_VOIES;
     ennemis[n].y = (LONG_ennemi + (LONG_ennemi * 4) ) *(n + 1); // la descente dans chaque voie
        ennemis[n].coord.w = LARG_enemi;
        ennemis[n].coord.h = LONG_enemi;

    }
}
/*void app (SDL_Rect* cl ) 
{
//cl[0].x=0 ; 
//cl[0].y=0 ; 
cl[0].w=339 ; 
cl[0].h=243

}*/

void deplaceranimer( struct enemi ennemis[]) 
{
    int n;
  
    ennemis->ys += ennemis->vite;
    for (n=0; n<MAX_ennemi ; n++) {
    
   if (abs(ennemis[n].y - ennemis->ys) < HAUTEUR_FENETRE) {

     // if (ennemis[n].y - ennemis->ys < HAUTEUR_FENETRE) {
          ennemis[n].visible = 1;
          ennemis[n].coord.x = ennemis->xvoies[ennemis[n].voie];//position aleatoire enemi
           ennemis[n].coord.y = HAUTEUR_FENETRE - (ennemis[n].y - ennemis->ys);//enemi deplacemnt aleatoire descend
          
       } else
            ennemis[n].visible = 0;
    }

} 


/*int  collision (SDL_Rect posh ,struct enemi enemis[])  
{
int nb;
nb=3 ;  

if 
{

return false ;  
}else 
{ 
return true ; 
}
}*/

void afficher(  SDL_Surface *ecran,  struct enemi ennemis[])
{
    int p,n,i=0;
p=HAUTEUR_FENETRE/2 ; 


   for (n=0; n<MAX_ennemi; n++) 
    {
   i++  ;
  
         if (ennemis[n].visible)
        {
  //SDL_Delay(500) ; 
                         SDL_BlitSurface(ennemis->Animation_D[1],NULL, ecran, &ennemis[n].coord);
                                     
                         // SDL_Flip(ecran); 
        //if(ennemis[n].coord.y=100 ) 

        //{  
        //ennemis[n].coord.x = game->xvoies[enemis[n].voie];       
         //ennemis[n].coord.y = HAUTEUR_FENETRE - (ennemis[n].y - car->y);      
               //SDL_BlitSurface(ennemis->Animation_D[1],NULL, ecran, &ennemis[n].coord);
             //SDL_BlitSurface(ennemis->Animation_D[2],NULL, ecran, &ennemis[n].coord);

                           //   SDL_Flip(ecran);
                            //    SDL_BlitSurface(ennemis->Animation_D[2],NULL, ecran, &ennemis[n].coord);
                                   //   SDL_BlitSurface(ennemis->Animation_D[2],NULL, ecran, &ennemis[n].coord)
       // }else if (ennemis[n].coord.y=400) 
        //{
                   
               // ennemis[n].coord.x = game->xvoies[ennemis[n].voie];
              //  ennemis[n].coord.y = HAUTEUR_FENETRE - (ennemis[n].y - car->y);
                // SDL_Flip(ecran);
                      //SDL_BlitSurface(ennemis->Animation_D[2],NULL, ecran, &ennemis[n].coord);
//                  SDL_BlitSurface(ennemis->Animation_D[3],NULL, ecran, &ennemis[n].coord);


    
  //      }
      }

        }
       /* i++ ;
        if (i==1)
        {


           //         SDL_BlitSurface(ennemis->Animation_D[3],NULL, ecran, &ennemis[n].coord);
       } else if (i==2)
       {
              SDL_BlitSurface(ennemis->Animation_D[i],NULL, ecran, &ennemis[n].coord);
               //SDL_BlitSurface(ennemis->Animation_D[1],NULL, ecran, &ennemis[n].coord);
                                  // SDL_BlitSurface(ennemis->Animation_D[3],NULL, ecran, &ennemis[n].coord);

       }else 
       { 
       i++ ; 
             SDL_BlitSurface(ennemis->Animation_D[i],NULL, ecran, &ennemis[n].coord);
               i==0 ; 
       } 
       
       }
       
       }*/
           /*else if (i==2)
     {
            SDL_BlitSurface(enemis->Animation_D[2],NULL, ecran, &ennemis[n].coord);
      }else 
      {
            SDL_BlitSurface(enemis->Animation_D[3],NULL, ecran, &ennemis[n].coord); 
           }*/
    
   SDL_Flip(ecran);
    }
 

/*void setrectss(SDL_Rect clips[9][4])
{
int j,i ;
  for(int j=0;j<8;j++)
  {
    for (int i=0;i<4;i++)
    {
      clips[j][i].x=i*1536;
      clips[j][i].y=j*864;
      clips[j][i].h=864;
      clips[j][i].w=1536;
    }
  }
  for (int i=0;i<4;i++)
  {
    clips[8][i].x=i*1536;
    clips[8][i].y=j*864;
    clips[8][i].h=864;
    clips[8][i].w=1536;
  }
}

/*void freeEnnemi(Ennemi *E)
{
	SDL_FreeSurface(E->image);
}*/

