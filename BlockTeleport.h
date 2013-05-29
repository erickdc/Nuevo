#ifndef BLOCKTELEPORT_H
#define BLOCKTELEPORT_H

#include "block.h"


class BlockTeleport : public Block
{
    public:
        BlockTeleport();
        BlockTeleport(float x, float y, int width, int height,
              SDL_Surface *image, SDL_Surface *screen,
              Dot *dot);
        bool activado;
        void logic();
        virtual ~BlockTeleport();
    protected:
    private:
};

#endif // BLOCKTELEPORT_H
