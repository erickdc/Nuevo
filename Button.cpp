#include "Button.h"

Button::Button(int x,int y, int x2, int y2,int x3, int y3, int w, int h,SDL_Surface *screen)
{
    this->screen = screen;
    showImages();
    this->image=IMG_Load( "MENU/background2.png" );
    buttonClick = Mix_LoadWAV( "select.wav" );
    activeIns=false;
    this->current_frame=0;
    this->current_frame2=2;
    this->current_frame3=4;
    this->x2= x2;
    this->y2= y2;
    this->x3=x3;
    this->y3=y3;
    this->x=x;
    this->y= y ;
    this->w= w;
    this->h=h;
    this->primero=true;
    this->segundo=false;
    this->tercero=false;
    this->termino=false;
    this->quitProgram=false;

}

Button::~Button()
{
    SDL_FreeSurface( images[0] );
    SDL_FreeSurface( images[1] );
    SDL_FreeSurface( images[2] );
    SDL_FreeSurface( images[3] );
    SDL_FreeSurface( images[4] );
    SDL_FreeSurface( images[5] );

}
void Button::Controles(){
SDL_Event event;
 //If there's an event to handle
      if(!this->activeIns){
        if( SDL_PollEvent( &event ) )
        {

            //If a key was pressed
            if( event.type == SDL_KEYDOWN )
            {
                //Set the proper message surface
                switch( event.key.keysym.sym )
                {
                   // case SDLK_ESCAPE: quit = true; break;
                    case SDLK_DOWN:
                        if(!segundo || !tercero){
                            if(primero){
                              primero=false;
                              segundo=true;
                             Mix_PlayChannel( -1, buttonClick, 0 );
                            }else if(segundo){
                                segundo=false;
                                tercero=true;
                            Mix_PlayChannel( -1, buttonClick, 0 );
                            }

                        }
                        break;
                    case SDLK_UP:
                         if(!segundo || !primero){
                            if(tercero){
                              tercero=false;
                              segundo=true;
                             Mix_PlayChannel( -1, buttonClick, 0 );
                            }else if(segundo){
                                segundo=false;
                                primero=true;
                                Mix_PlayChannel( -1, buttonClick, 0 );
                            }

                        }
                        break;
                    case SDLK_SPACE:
                        if(current_frame==1){
                            termino=true;
                        }else if(current_frame2==3){
                            activeIns=true;
                            dissapear();
                        }else if(current_frame3==5){
                            quitProgram=true;
                            }else{
                        this->quitProgram=true;
                        }
                        break;
                }
            }
           // If the user has Xed out the window
           else if( event.type == SDL_QUIT )
            {

            quitProgram= true;

        }

    }
 }else{
 showIns();
 }
}
void Button::render()
{
    SDL_Rect offset;

     if(primero){
    current_frame=1;
    current_frame2=2;
    current_frame3=4;
     }else if(segundo){
     current_frame=0;
    current_frame2=3;
    current_frame3=4;
    }else {
    current_frame=0;
    current_frame2=2;
    current_frame3=5;
    }


    offset.x = x - images[current_frame]->w/2;
    offset.y = y - images[current_frame]->h/2;

    SDL_BlitSurface( images[current_frame], NULL, screen, &offset );

    offset.x = x2 - images[current_frame2]->w/2;
    offset.y = y2 - images[current_frame2]->h/2;

    SDL_BlitSurface( images[current_frame2], NULL, screen, &offset );

    offset.x = x3 - images[current_frame3]->w/2;
    offset.y = y3 - images[current_frame3]->h/2;

    SDL_BlitSurface( images[current_frame3], NULL, screen, &offset );

}
void Button::showIns(){
    SDL_Rect offset;
    offset.x = 0;
    offset.y = 0;

    SDL_BlitSurface( image, NULL, screen, &offset );

    SDL_Event event;

    if( SDL_PollEvent( &event ) )
        {

            //If a key was pressed
            if( event.type == SDL_KEYDOWN )
            {
                //Set the proper message surface
                switch( event.key.keysym.sym )
                {
                    case SDLK_ESCAPE: activeIns = false; original();break;


                }
            }
           // If the user has Xed out the window
           else if( event.type == SDL_QUIT )
            {

            quitProgram= true;

        }
    }
}

void Button::showImages(){
    this->images[0]= IMG_Load("MENU/start.png");
    this->images[1]= IMG_Load("MENU/start1.png");
    this->images[2]= IMG_Load("MENU/instruction.png");
    this->images[3]= IMG_Load("MENU/instruction1.png");
    this->images[4]= IMG_Load("MENU/exit.png");
     this->images[5]= IMG_Load("MENU/exit1.png");
}
void Button::dissapear(){
   x=x+3000;
   y=y+3000;
   x2=x2+3000;
   y2=y2+3000;
   x3=x3+3000;
   y3=y3+3000;
}
void Button::original(){
    x=x-3000;
   y=y-3000;
   x2=x2-3000;
   y2=y2-3000;
   x3=x3-3000;
   y3=y3-3000;
}
void Button::backMenu(){
    this->current_frame=1;
    this->current_frame2=2;
    this->current_frame3=4;
    this->primero=true;
    this->segundo=false;
    this->tercero=false;
    this->termino=false;
    this->quitProgram=false;
}
