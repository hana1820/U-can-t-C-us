typedef struct Hero Hero ;
struct Hero
{

SDL_Surface *image;

SDL_Rect positionimage;

float score ;
float vies ;

};
void initPerso(Hero* hero) ; 
void animePersog (SDL_Rect animepos[],int *frame) ; 
void animePersod (SDL_Rect animepos[],int *frame) ;
void deplacerPerso(int* test,SDL_Rect animepos[],int *frame,SDL_Rect* poshero) ;
void saut(SDL_Rect *positionimage,double v_x,double* v_y,double v_grav) ;

