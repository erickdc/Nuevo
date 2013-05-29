#include "Level.h"

Level::Level(Paddle *paddle,SDL_Surface *screen,Dot *dot)
{
    this->paddle=paddle;
    this->screen=screen;
    this->dot=dot;
    fullArray();
    termino=false;
    this->life=new Life(3,screen,dot,paddle,this->blockList);
}

void Level::logic(){
this->life->logic();
this->life->Render();
if(this->blockList.empty())
    termino=true;

}
void Level::deleteBlock(){

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
}

void Level::show(){
list<Block*>::iterator blocki3 =blockList.begin();
        while(blocki3!=blockList.end()){
            Block* blockTemp = *blocki3;
            blockTemp->show();
            blocki3++;
            }
}
void Level::fullArray(){
SDL_Surface *block_image = load_image("block.png");
int posX[42]={350,350,275,250,250,175,150,100,50,50,25,25,50,75,75,125,175,200,225,250,275,350,425,450,475,500,550,575,625,625,650,675,675,650,600,550,525,450,450,425};
int posY[42]={125,150,100,75,50,25,50,75,100,125,150,175,200,225,250,275,300,325,350,375,400,425,400,375,350,325,300,275,250,225,200,175,150,125,100,75,50,25,50,75,100};
int sizeX=100;
int sizeY=25;

   for(int i =0; i<42;i++){
    Block *blocks= new Block(posX[i],posY[i],sizeX,sizeY,block_image,screen,dot);
    this->blockList.push_back(blocks);
   }

  // this->life(3,this->screen,dot,paddle,blockList);

}
Level::~Level()
{
    //dtor
}
