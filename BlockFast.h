#ifndef BLOCKFAST_H
#define BLOCKFAST_H

#include "block.h"


class BlockFast : public Block
{
   public:
        BlockFast();
        BlockFast(float x, float y, int width, int height,
              SDL_Surface *image, SDL_Surface *screen,
              Dot *dot);
        bool activado;
        void logic();
        virtual ~BlockFast();
    protected:
    private:
};

#endif // BLOCKFAST_H
