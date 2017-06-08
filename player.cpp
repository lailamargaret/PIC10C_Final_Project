#include "player.h"
#include "ball.h"
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QGraphicsScene>

Player::Player(QGraphicsItem *parent)
{
    setRect(0,0,100,20);

}

void Player::keyPressEvent(QKeyEvent * event)
{
   if (event -> key() == Qt::Key_Left){
       if(pos().x() > 10)
            setPos(x()-20, y());
   }

   else if (event -> key() == Qt::Key_Right){
       if(pos().x() +100 < 790)
            setPos(x()+20, y());
   }
}
