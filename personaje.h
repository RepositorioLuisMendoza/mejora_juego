#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <math.h>
#include <QPainter>
#include <plataforma.h>
#include <QDebug>
#include <comida.h>

class personaje : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    personaje(int posicionInicialX,int posicionInicialY);
    float V0;
    float Vx;
    float Vy;
    float t;

    //void colicionparedes(const QList<plataforma *> *paredes,const  QList<comida *>*monedas);
    void aplicaraceleracion(QPointF Acel, QList<plataforma *> *paredes);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

public slots:
    void actualizarMParabolico();
};

#endif // PERSONAJE_H
