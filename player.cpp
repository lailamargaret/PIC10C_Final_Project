#include "player.h"
#include "ball.h"
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QGraphicsScene>

Player::Player(QGraphicsItem *parent)
{
    setRect(0,0,1000,20);

}

void Player::keyPressEvent(QKeyEvent * event)
{
  // bool is_launched = false;
  // if (event -> key() == Qt::Key_Space)
    //   is_launched = true;
   if (event -> key() == Qt::Key_Left){// && is_launched){
       if(pos().x() > 10)
            setPos(x()-20, y());
   }

   if (event -> key() == Qt::Key_Right){// && is_launched){
       if(pos().x() +100 < 790)
            setPos(x()+20, y());
   }
}

double Player::getCenterX()
{
    return pos().x()/2;
}
