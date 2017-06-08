#ifndef BALL_H
#define BALL_H

#include <QGraphicsItem>
#include <QGraphicsRectItem>

class Ball : public QObject, public QGraphicsRectItem{

public:
    Ball();

private:
    int x_velocity;
    int y_velocity;
};




#endif // BALL_H
