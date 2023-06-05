#include "comida.h"

comida::comida(int x, int y, int w_, int h_)
{
    posx = x;
    posy = y;
    w = w_;
    h = h_;
}

QRectF comida::boundingRect() const
{
    return QRectF(posx,posy,w,h);
}

void comida::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
}
