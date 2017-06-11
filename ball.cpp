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
    hit_player();

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

   //out of bounds, bottom, stop NOT WORKING
       if(mapToScene(rect().bottomRight()).y() > 100){
           x_velocity = 0;
           y_velocity = 0;
       }
   }

}

void Ball::hit_block(){
  QList <QGraphicsItem *> colliding_items = collidingItems();
  for (int i = 0, n = colliding_items.size(); i < n; ++i){
      Block * block = dynamic_cast<Block*>(colliding_items[i]);
      if (block){
            //cases for where it hits the block
          //hits the bottom
          if (pos().y() > block->pos().y() + 10 && y_velocity < 0)
              y_velocity*=-1;
          //hits the top
          if (block->pos().y() > pos().y() + 10 && y_velocity > 0)
              y_velocity*=-1;
         //hits the right side
          if (pos().x() > block->pos().x() + 10 && x_velocity < 0)
              x_velocity*=-1;
         //hits the left side
          if (block->pos().x() > pos().x() + 10 && x_velocity > 0)
              x_velocity*=-1;

          // game -> scene ->removeItem(block);
           delete colliding_items[i];
            return;
        }
  }

}

void Ball::hit_player(){
    QList <QGraphicsItem*> CI = collidingItems();
    for (int i = 0, n = CI.size(); i < n; ++i){
        Player * player = dynamic_cast<Player*>(CI[i]);
        if(player){
            y_velocity*=-1;

            double change_in_x = (getCenterX() - player->getCenterX());
            x_velocity = (x_velocity + change_in_x)/15;
            return;
        }
    }
}
