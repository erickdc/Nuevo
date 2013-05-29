#ifndef BLOCKGHOST_H
#define BLOCKGHOST_H

#include "block.h"


class BlockGhost : public Block
{
   public:
        BlockGhost();
        BlockGhost(float x, float y, int width, int height,
              SDL_Surface *image, SDL_Surface *screen,
              Dot *dot);
        bool activado;
        bool tocado;
        int vidas;
        float posicionOriginal;
        void logic();
        virtual ~BlockGhost();
    protected:
    private:
};

#endif // BLOCKGHOST_H
