#ifndef BALL_H
#define BALL_H

#include <QGraphicsItem>
#include <QGraphicsRectItem>

class Ball : public QObject, public QGraphicsEllipseItem{
    Q_OBJECT
public:
    Ball(QGraphicsItem* parent = 0);

    double getCenterX();

public slots:
    void move();


private:
    double x_velocity;
    double y_velocity;

    void hit_wall();
    void hit_player();
    void hit_block();
};




#endif // BALL_H
