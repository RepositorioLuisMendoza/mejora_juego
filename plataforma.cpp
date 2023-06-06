#include "plataforma.h"


plataforma::plataforma(int x, int y, int w_, int h_)
{
    posx = x;
    posy = y;
    w = w_;
    h = h_;
    setPos(posx, posy);
}

QRectF plataforma::boundingRect() const
{
    return QRectF(0,0,w,h);
}

void plataforma::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::white);
    QRectF Rectangulo(0,0,w,h);
    painter->drawRect(Rectangulo);
}

int plataforma::getPosy() const
{
    return posy;
}

int plataforma::getH() const
{
    return h;
}
