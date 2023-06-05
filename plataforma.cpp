#include "plataforma.h"


plataforma::plataforma(int x, int y, int w_, int h_)
{
    posx = x;
    posy = y;
    w = w_;
    h = h_;
}

QRectF plataforma::boundingRect() const
{
    return QRectF(posx,posy,w,h);
}

void plataforma::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::white);
    painter->drawRect(boundingRect());
}

int plataforma::getPosy() const
{
    return posy;
}

int plataforma::getH() const
{
    return h;
}
