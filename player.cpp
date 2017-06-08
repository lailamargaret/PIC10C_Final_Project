#include "player.h"
#include <QGraphicsRectItem>
#include <QKeyEvent>

Player::Player(QGraphicsItem *parent)
{
    setRect(0,0,100,100);
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event -> key() == Qt::Key_Left){
        if(pos().x() > 0)
             setPos(x()-10, y());
    }

    else if (event -> key() == Qt::Key_Right){
        if(pos().x() +100 < 800)
             setPos(x()+10, y());
    }
}
