#include "game.h"
#include "player.h"

Game::Game(QWidget *parent): QGraphicsView(parent){

    scene = new QGraphicsScene(0,0,800,600);
    setFixedSize(800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(scene);
}

void Game::play(){
    Player* player = new Player();
    player-> setPos(250,400);
    scene->addItem(player);

}
