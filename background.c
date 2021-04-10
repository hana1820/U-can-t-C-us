#include "background.h"

void init_back(background *bg, int x){

//common


  bg->pos_back.w=1500;
  bg->pos_back.h=350;

  bg->camera.x=0;
  bg->camera.w=1100;

//bg 1
if(x==1){
bg->image_back=IMG_Load("res/bg.jpg");
bg->camera.y=0;
bg->camera.h=350;
}

//bg 2
if(x==2){
bg->image_back=IMG_Load("res/bg2.jpg");
  bg->camera.y=-350;
  bg->camera.h=700;
}

}

void init_music(music *m, int volume){

  //init back music
  m->music= Mix_LoadMUS("res/music.mp3");
  Mix_VolumeMusic(volume);
}



void afficher_back(background bg,SDL_Surface *screen){
SDL_BlitSurface(bg.image_back,&bg.camera,screen,NULL);
}

void scroll_right (background *bg){
if(bg->camera.x+bg->camera.w<bg->pos_back.w){
bg->camera.x+=5;
}
}

void scroll_left (background *bg){
if (bg->camera.x>0){
bg->camera.x-=5;
}
}

void play_music(music *m){
  Mix_PlayMusic(m->music,-1);
}
