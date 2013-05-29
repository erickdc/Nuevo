#include "Paddle.h"

Paddle::Paddle(){

}
Paddle::~Paddle(){

}

Paddle::Paddle(float x, float y, int width, int height,SDL_Surface *image,SDL_Surface *screen, Dot *dot){
this->x = x;
this->y = y;
this->termino=false;
this->width = width;
this->height = height;
this->screen = screen;
this->image = image;
this->dot = dot;
this->isColliding = false;
this->wasColliding = false;

}

void Paddle::show(){

    apply_surface( x, y, image, screen);

}

void Paddle::logic(){
        int collision = collisionType();
        if(!wasColliding){
        switch(collision){
        case 0:
        break;

        case TOP:
                dot->angle = -dot->angle;
                dot->angle += rand()%10 - 20;

            break;
        case BOT:
            dot->angle = -dot->angle;
            dot->angle += rand()%10 - 20;

            break;

        case RIGHT: case LEFT:
            dot->angle = -dot->angle+180;
            dot->angle += rand()%10 - 20;

            break;
         case CORNERUL:
             dot->velocity = abs(dot->velocity);
             dot->angle = 315;
             dot->angle += rand()%5-10;

             break;
        case CORNERUR:
            dot->velocity = abs(dot->velocity);
             dot->angle = 225;
             dot->angle += rand()%5-10;
             break;
        case CORNERDR:
            dot->velocity = abs(dot->velocity);
             dot->angle = 135;
             dot->angle += rand()%5-10;

             break;
        case CORNERDL:
            dot->velocity = abs(dot->velocity);
             dot->angle = 45;
             dot->angle += rand()%5-10;

        }

        }

}

void Paddle::Controles(){
    Uint8 *keystates = SDL_GetKeyState( NULL );

        //If left is pressed
        if( keystates[ SDLK_LEFT ] )
        {
            if(x>0)
          x-=8;
        }

        //If right is pressed
        if( keystates[ SDLK_RIGHT ] )
        {
            if(x<670)
            x+=8;
        }


}
void Paddle::moveRightLeft(){

    if(x<500 && !termino ){
        x+=2;
        if(x==500)
            termino=true;
    }else if(x>30 && termino){
        x-=2;
        if(x==30)
            termino=false;
    }

}
bool Paddle::isPointInside(float pointX, float pointY){
if(    pointX > this->x
       && pointX < this->x+this->width
       && pointY > this->y
       && pointY < this->y + this->height){
       return true;
       }
       return false;
}

int Paddle::collisionType(){

        float posX = dot->x;
        float posXMid = dot->x + (dot->DOT_WIDTH/2);
        float posXEnd = dot->x + dot->DOT_WIDTH;
        float posY = dot->y, posYMid = dot->y+ dot->DOT_HEIGHT/2, posYEnd = dot->y + dot->DOT_HEIGHT;

        if(this->isColliding){
            this->wasColliding = true;
        } else {
        this->wasColliding =false;
        }

        this->isColliding = false;
        if (!this->wasColliding){
        if(    isPointInside(posX,posY)
                &&
                isPointInside(posXMid,posY)
                ||
               isPointInside(posXMid,posY)
                &&
                 isPointInside(posXEnd,posY)
                ){
                    this->isColliding = true;
                    return TOP;
        } else if (
                   isPointInside(posX,posYEnd)
                && isPointInside(posXMid,posYEnd)
                ||
                 isPointInside(posXMid,posYEnd)
                && isPointInside(posXEnd,posYEnd)

                ){
                    this->isColliding = true;
                    return BOT;

        }else if (

                  isPointInside(posX,posY)
            &&
                isPointInside(posX,posYMid)
                ||
                 isPointInside(posX,posYMid)
               && isPointInside(posX,posYEnd)

                   ){
                        this->isColliding = true;
                        return LEFT;
        }else if (

                  isPointInside(posXEnd,posY)
                &&
                isPointInside(posXEnd,posYMid)
                ||
                 isPointInside(posXEnd,posYMid)
                && isPointInside(posXEnd,posYEnd)

                   ){
                    this->isColliding = true;
                    return RIGHT;
        }else if (isPointInside(posX,posY)){
        return CORNERUL;
        }else if(isPointInside(posX,posYEnd)){
        return CORNERDL;
        }else if(isPointInside(posXEnd,posY)){
        return CORNERUR;
        }else if(isPointInside(posXEnd,posYEnd)){
        return CORNERDR;
        }

        }

        return 0;
}


