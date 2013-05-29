#ifndef LEVEL_H
#define LEVEL_H
#include <list>
#include "block.h"
#include "Dot.h"
#include "paddle.h"
#include "Life.h"
#include <iostream>

using namespace std;

class Level
{
    public:
        Level( Paddle *paddle,SDL_Surface *screen,Dot *dot);
        void fullArray();
        void deleteBlock();
        void show();
        void logic();
        bool termino;
        ~Level();

    protected:

    private:
          Paddle *paddle;
        Dot *dot;
        SDL_Surface *screen;
        list <Block*> blockList;
        Life *life;

};

#endif // LEVEL_H
