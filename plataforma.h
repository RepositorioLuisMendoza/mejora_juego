#ifndef PLATAFORMA_H
#define PLATAFORMA_H

#include <QGraphicsItem>
#include <QPainter>

class plataforma:public QObject, public QGraphicsRectItem
{
    int w,h;
    int posx, posy;
public:
    plataforma(int x, int y,int w_, int h_);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    int getPosy() const;
    int getH() const;

};

#endif // PLATAFORMA_H
