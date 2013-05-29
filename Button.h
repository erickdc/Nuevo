#ifndef BUTTON_H
#define BUTTON_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include <string>

class Button
{
    public:

    SDL_Surface *images[6];
    SDL_Surface *screen;
    int x;
    int y;
    int x2;
    int y2;
    int x3;
    int y3;
    int w;
    int h;

    Mix_Chunk *buttonClick;
    bool quitProgram;
    int current_frame;
    int current_frame2;
    int current_frame3;
    bool primero;
    bool segundo;
    bool tercero;
    bool termino;
    void Controles();
    void backMenu();
    Button(int x, int y,int x2,int y2,int x3,int y3,int w, int h,SDL_Surface *screen);
    void  render();

    virtual ~Button();
    private:


};

#endif // BUTTON_H
