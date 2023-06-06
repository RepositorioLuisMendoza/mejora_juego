#include "comida.h"


comida::comida(int x, int y, int w_, int h_)
{
    posx = x;
    posy = y;
    w = w_;
    h = h_;
    setPos(posx, posy);
}

QRectF comida::boundingRect() const
{
    return QRectF(0,0,w,h);
}

void comida::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::green);
    QRectF rectangulo_peque(0,0,w,h);
    painter->drawRect(rectangulo_peque);
}

int comida::getPosy() const
{
    return posy;
}

int comida::getH() const
{
    return h;
}
