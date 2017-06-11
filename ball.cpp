#include "game.h"
#include "ball.h"
#include "player.h"
#include "block.h"
#include <QTimer>

extern Game* game;

Ball::Ball(QGraphicsItem * parent) : QGraphicsEllipseItem(parent), QObject(){
    setRect(0,0,20,20);

    x_velocity = 0;
    y_velocity = -5;

    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer -> start(15);
}

double Ball::getCenterX(){
    return x()+ rect().width()/2;
}

void Ball::move(){
    moveBy(x_velocity, y_velocity);
    hit_wall();
    hit_block();

}

void Ball::hit_wall()
{
   double screenW = 800;//game->width();
  // double screenH = game->height();

   //hitting the left side
   if (mapToScene(rect().topLeft()).x() <= 0){
       x_velocity = -1*x_velocity;
   }

   //hitting the right side
   if (mapToScene(rect().topRight()).x() >= screenW){
       x_velocity = -1*x_velocity;
   }

   //hitting the top
   if (mapToScene(rect().topLeft()).y() <= 0){
       y_velocity = -1*y_velocity;
   }

}

void Ball::hit_block(){
  QList <QGraphicsItem *> colliding_items = collidingItems();
  for (int i = 0, n = colliding_items.size(); i < n; ++i){
      Block * block = dynamic_cast<Block*>(colliding_items[i]);
      if (block){
           // game -> scene ->removeItem(block);
            delete colliding_items[i];
           y_velocity *=-1;
            return;
        }
  }

}






