#ifndef BLOCKDOWN_H
#define BLOCKDOWN_H
#include <list>
#include "block.h"
#include <cstdlib>
#include <iostream>
using namespace std;

class BlockDown : public Block
{
        public:
        BlockDown();
        BlockDown(float x, float y, int width, int height,
              SDL_Surface *image, SDL_Surface *screen,
              Dot *dot,list <Block*> blockList);
        list <Block*> blockList;
        bool activado;
        void logic();
        void refBlocks();
        virtual ~BlockDown();
    protected:
    private:
};

#endif // BLOCKDOWN_H
