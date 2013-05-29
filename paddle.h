#ifndef PADDLE_H
#define PADDLE_H
#include "SDL.h"
#include "SDL_image.h"
#include "Utility.h"
#include "Dot.h"

#include "block.h"


class Paddle
{
        public:
        bool isColliding;
        bool wasColliding;
        Paddle();
        bool termino;
        void Controles();
        float x, y;
        void moveRightLeft();
        int width,height;
        SDL_Surface *image;
        SDL_Surface *screen;

        Dot *dot;
        Paddle(float x, float y, int width, int height,
              SDL_Surface *image, SDL_Surface *screen,
              Dot *dot);
        int collisionType();
        bool isPointInside(float pointX, float pointY);
        void show();
        void logic();

        virtual ~Paddle();
};

#endif // PADDLE_H
