/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/

//The headers
#include "SDL.h"
#include "SDL_image.h"
#include "Timer.h"
#include "SDL/SDL_mixer.h"
#include "Particle.h"
#include "Dot.h"
#include <string>
#include <cstdlib>
#include "block.h"
#define PI 3.14159265
#include <list>
#include "paddle.h"
#include <iostream>
#include "BlockSlow.h"
#include "BlockDown.h"
#include "BlockTeleport.h"
#include "BlockGhost.h"
#include "Menu.h"
#include "Button.h"
#include "life.h"
#include "Level.h"

//The surfaces
using namespace std;
const int SCREEN_BPP = 32;
int veces=0;
//The frame rate
const int FRAMES_PER_SECOND = 60;

//The surfaces
SDL_Surface *screen = NULL;

//The event structure
SDL_Event event;

bool init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }
      if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        return false;
    }
    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return false;
    }

    //Set the window caption
    SDL_WM_SetCaption( "Semana 5", NULL );

    //Seed random
    srand( SDL_GetTicks() );

    //If everything initialized fine
    return true;
}

void clean_up()
{
    SDL_Quit();
}

int main( int argc, char* args[] )
{
    //Quit flag
    bool quit = false;

    //The frame rate regulator
    Timer fps;

    //Initialize
    if( init() == false )
    {
        return 1;
    }


    //The dot that will be used
    Dot myDot(screen);
    Menu menu(screen);

    Button button(412,200,412,300,412,400,261,50,screen);
    SDL_Surface *block_image = load_image("block.png");
    SDL_Surface *blockSlow_image = load_image("blockSlow.png");
    SDL_Surface *blockGhost_image = load_image("blockGhost.png");
    SDL_Surface *blockDown_image = load_image("blockDown.png");
    SDL_Surface *blockTeleport_image = load_image("blockTeleport.png");
    SDL_Surface *tabla_image= load_image("Tabla.png");


    Block *block6= new Block(350,125,100,25,block_image,screen, &myDot);
    Block *block = new Block(350,150,100,25,block_image,screen,&myDot);
    Block *block2 = new Block(275,100,100,25,block_image,screen,&myDot);
    Block *block7 = new Block(250,75,100,25,block_image,screen,&myDot);
    Block *block9 = new Block(250,50,100,25,block_image,screen,&myDot);
    Block *block10 = new Block(175,25,100,25,block_image,screen,&myDot);
    Block *block11 = new Block(150,50,100,25,block_image,screen,&myDot);
    Block *block12 = new Block(100,75,100,25,block_image,screen,&myDot);
    Block *block13 = new Block(50,100,100,25,block_image,screen,&myDot);
    Block *block14 = new Block(50,125,100,25,block_image,screen,&myDot);
    Block *block8= new Block(25,150,100,25,block_image,screen,&myDot);
    Block *block3= new Block(25,175,100,25,block_image,screen,&myDot);
    Block *block5= new Block(50,200,100,25,block_image,screen,&myDot);
    Block *block15 = new Block(75,225,100,25,block_image,screen,&myDot);
    Block *block16 = new Block(75,250,100,25,block_image,screen,&myDot);
    Block *block17 = new Block(125,275,100,25,block_image,screen,&myDot);
    Block *block18 = new Block(175,300,100,25,block_image,screen,&myDot);
    Block *block19 = new Block(200,325,100,25,block_image,screen,&myDot);
    Block *block20 = new Block(225,350,100,25,block_image,screen,&myDot);
    Block *block21 = new Block(250,375,100,25,block_image,screen,&myDot);
    Block *block22 = new Block(275,400,100,25,block_image,screen,&myDot);
    Block *block23 = new Block(350,425,100,25,block_image,screen,&myDot);
    Block *block24 = new Block(425,400,100,25,block_image,screen,&myDot);
    Block *block25 = new Block(450,375,100,25,block_image,screen,&myDot);
    Block *block26 = new Block(475,350,100,25,block_image,screen,&myDot);
    Block *block27 = new Block(500,325,100,25,block_image,screen,&myDot);
    Block *block28 = new Block(550,300,100,25,block_image,screen,&myDot);
    Block *block29 = new Block(575,275,100,25,block_image,screen,&myDot);
    Block *block30= new Block(625,250,100,25,block_image,screen,&myDot);
    Block *block31= new Block(625,225,100,25,block_image,screen,&myDot);
    Block *block32= new Block(650,200,100,25,block_image,screen,&myDot);
    Block *block33 = new Block(675,175,100,25,block_image,screen,&myDot);
    Block *block34 = new Block(675,150,100,25,block_image,screen,&myDot);
    Block *block35 = new Block(650,125,100,25,block_image,screen,&myDot);
    Block *block36 = new Block(650,100,100,25,block_image,screen,&myDot);
    Block *block37 = new Block(600,75,100,25,block_image,screen,&myDot);
    Block *block38 = new Block(550,50,100,25,block_image,screen,&myDot);
    Block *block39 = new Block(525,25,100,25,block_image,screen,&myDot);
    Block *block40 = new Block(450,50,100,25,block_image,screen,&myDot);
    Block *block41 = new Block(450,75,100,25,block_image,screen,&myDot);
    Block *block42 = new Block(425,100,100,25,block_image,screen,&myDot);

    Paddle *paddle = new Paddle(250,575,100,20,tabla_image,screen,&myDot);

    //bloques Especiales
    Block *block44= new BlockTeleport(300,200,100,25,blockTeleport_image,screen,&myDot);
    Block *block45= new BlockTeleport(40,300,100,25,blockTeleport_image,screen,&myDot);
    Block *block46= new BlockTeleport(300,275,100,25,blockTeleport_image,screen,&myDot);
    Block *block43= new BlockTeleport(300,300,100,25,blockTeleport_image,screen,&myDot);
    Block *block47=new BlockGhost(300,250,100,25,blockGhost_image,screen,&myDot);
    Block *block48=new BlockGhost(400,225,100,25,blockGhost_image,screen,&myDot);
    Block *block49=new BlockGhost(400,250,100,25,blockGhost_image,screen,&myDot);
    // block2->life =3;
    list <Block*> blockList;
    blockList.push_back(block49);
    blockList.push_back(block48);
    blockList.push_back(block47);
    blockList.push_back(block46);
    blockList.push_back(block45);
    blockList.push_back(block44);
    blockList.push_back(block43);
    blockList.push_back(block);
    blockList.push_back(block2);
    blockList.push_back(block6);
    blockList.push_back(block3);
    blockList.push_back(block7);
    blockList.push_back(block8);
    blockList.push_back(block5);
    blockList.push_back(block9);
    blockList.push_back(block10);
    blockList.push_back(block11);
    blockList.push_back(block12);
    blockList.push_back(block13);
    blockList.push_back(block14);
    blockList.push_back(block15);
     blockList.push_back(block16);
    blockList.push_back(block17);
    blockList.push_back(block18);
    blockList.push_back(block19);
    blockList.push_back(block20);
    blockList.push_back(block21);
    blockList.push_back(block22);
    blockList.push_back(block23);
    blockList.push_back(block24);
    blockList.push_back(block25);
    blockList.push_back(block26);
    blockList.push_back(block27);
    blockList.push_back(block28);
    blockList.push_back(block29);
    blockList.push_back(block30);
    blockList.push_back(block31);
    blockList.push_back(block32);
    blockList.push_back(block33);
    blockList.push_back(block34);
    blockList.push_back(block35);
    blockList.push_back(block36);
    blockList.push_back(block37);
    blockList.push_back(block38);
    blockList.push_back(block39);
    blockList.push_back(block40);
    blockList.push_back(block41);
    blockList.push_back(block42);


    Block *block4= new BlockDown(400,300,100,25,blockDown_image,screen,&myDot,blockList);
    blockList.push_back(block4);

     Life life(3,screen,&myDot,paddle, blockList);
    //While the user hasn't quit

   // Level *level1= new Level(paddle,screen,&myDot);
    while( quit == false )
    {
        if(!button.termino){
            menu.render();
            button.Controles();
            button.render();
            SDL_Flip(screen);

            if(button.quitProgram)
                quit=true;
        }else{
        //Start the frame timer
        fps.start();

        //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {
            //Handle events for the dot
            myDot.handle_input();

            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }

        //Move the dot
       myDot.move();
        //level1->logic();
        //level1->deleteBlock();

        list<Block*>::iterator blocki =blockList.begin();
        while(blocki!=blockList.end()){
            Block* blockTemp = *blocki;
            blockTemp->logic();
            if(blockTemp->life<=0){
                blockList.erase(blocki);
                blocki--;
            }
            blocki++;
        }



        //Fill the screen white
        SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );

        //Show the dot on the screen
        myDot.show();

        paddle->logic();
        paddle->Controles();
        paddle->show();

        //level1->show();
        life.logic();

        life.Render();

        list<Block*>::iterator blocki3 =blockList.begin();
        while(blocki3!=blockList.end()){
            Block* blockTemp = *blocki3;
            blockTemp->show();
            blocki3++;
            }






        //Update the screen
        if(life.termino)
            quit=true;

            if(blockList.empty())
              quit=true;

        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }

        //Cap the frame rate
        if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
        {
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
        }
        }
    }

    //Clean up
    clean_up();

    return 0;

}
