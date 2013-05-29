#include "Life.h"

Life::Life(int cant,SDL_Surface *screen, Dot *dot, Paddle *p,list <Block*> blockList)
{
    this->cantidadVidas=cant;
    this->screen=screen;
    this->image = IMG_Load( "life.png" );
    this->dot=dot;
    this->x=700;
    this->y=5;
    this->cantidadMover=25;
    this->paddle=p;
    termino=false;
    this->blockList=blockList;
}

void Life::ganar(){
    if(this->blockList.empty()){
        termino=true;
    }
}

void Life::Render(){
    SDL_Rect offset;


    for(int i=0; i<cantidadVidas;i++){
     offset.x = x+(cantidadMover*i);
     offset.y = y;

    SDL_BlitSurface( image, NULL, screen, &offset );
    }
}

void Life::logic(){
    if(this->dot->y>=580){
        cantidadVidas--;
        this->dot->x=paddle->x;
        this->dot->y=paddle->y-25;;
        this->dot->angle=70;

    }
    if(cantidadVidas==0)
        termino=true;

}
Life::~Life()
{
    //dtor
}
