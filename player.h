#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QKeyEvent>


class Player : public QGraphicsRectItem{
public:
    Player(QGraphicsItem* parent = nullptr);

    void keyPressEvent (QKeyEvent* event);

};


#endif // PLAYER_H
