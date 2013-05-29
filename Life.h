#ifndef LIFE_H
#define LIFE_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Dot.h"
#include "paddle.h"
#include "block.h"
#include <list>

using namespace std;
class Life
{
    public:
        Life(int cant,SDL_Surface *screen, Dot *dot, Paddle *p,list <Block*> blockList);
        void Render();
        void logic();
        void ganar();
        bool termino;
        virtual ~Life();
    protected:
    private:
        int cantidadVidas;
        Paddle *paddle;
        SDL_Surface *screen;
        SDL_Surface *image;
        Dot *dot;
        int x;
        int y;
        int cantidadMover;
        list <Block*> blockList;
};

#endif // LIFE_H
