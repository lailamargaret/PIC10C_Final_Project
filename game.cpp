#include "game.h"
#include "player.h"
#include "ball.h"
#include "block.h"

Game::Game(QWidget *parent): QGraphicsView(parent){

    scene = new QGraphicsScene(0,0,800,600);
    setFixedSize(800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(scene);

   for (int i = 20; i < 680; i+=120){
       for (int j = 20; j < 200; j+=50){
       Block * block = new Block();
       block -> setPos(i, j);
       scene -> addItem(block);
   }
   }

}

void Game::play(){
    Player* player = new Player();
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    player-> setPos(250,550);
    scene->addItem(player);

    Ball * ball = new Ball();
    ball -> setPos(290, 530);
    scene -> addItem(ball);


}
