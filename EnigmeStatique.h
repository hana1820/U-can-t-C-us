typedef struct enigme
{
    SDL_Surface;
    SDL_Rect;
    int etat;
};

void InitEnigme(enigme *e);
void AfficherEnigme(enigme *e);
void ResoudreEnigme(enigme *e);
