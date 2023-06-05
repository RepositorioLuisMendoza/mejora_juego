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

#define Angulo (float) 1.5708 // Equivalente de 90° en radianes.
#define G (float) 9.81 // Valor promedio de la gravedad.

class personaje : public QObject, public QGraphicsRectItem
{
private:
    float V0;
    float Vx;
    float Vy;
    float t;




public:
    personaje(int posicionInicialX,int posicionInicialY);

    void colicionparedes(const QList<plataforma *> &paredes);
    void aplicaraceleracion(QPointF Acel,QList<plataforma *> &paredes);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    //personaje(int r_, int x, int y);

   /* void select_sprite(int x, int y);
    void saltar();
    void bajar();
    void adelantar();
    void timerOn();
    void timerOff();
    float getPosicionX() const;
    float getPosicionY() const;
    float getT() const;
    void setY0(float value);
    void setPosicionX(float value);*/




public slots:
    void actualizarMParabolico();
};

#endif // PERSONAJE_H
