#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QPixmap>


class Player : public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Player(QGraphicsItem* parent = 0);
    void keyPressEvent (QKeyEvent* event);

};


#endif // PLAYER_H
