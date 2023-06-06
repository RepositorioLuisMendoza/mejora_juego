#include "personaje.h"

personaje::personaje(int posicionInicialX, int posicionInicialY)
{
    Vx=0;
    Vy=0;

    setPos(posicionInicialX,posicionInicialY);
}





void personaje::aplicaraceleracion(QPointF Acel, QList<plataforma *> *paredes)
{
    QPointF posi_inicial=pos();
    float dt=0.1;

    Vx+=dt*Acel.x();
    Vy+=Acel.y();
    setX(pos().x()+Vx*dt+Acel.x()*0.5*dt*dt);
    setPos(pos());
    for (int i=0;i<paredes->size();i++)
    {
        QRectF Personaje=boundingRect();
        Personaje.moveTo(pos());
        QRectF Pared=paredes->at(i)->boundingRect();
        Pared.moveTo(paredes->at(i)->pos());
        if(Personaje.intersects(Pared))
        {
            setX(posi_inicial.x());
        }
    }

    setY(pos().y()+Vy*dt+Acel.y()*0.5*dt*dt);
    setPos(pos());
    for (int i=0;i<paredes->size();i++)
    {
        QRectF Personaje=boundingRect();
        Personaje.moveTo(pos());
        QRectF Pared=paredes->at(i)->boundingRect();
        Pared.moveTo(paredes->at(i)->pos());
        if(Personaje.intersects(Pared))
        {
            setY(posi_inicial.y());
        }
    }
   /* for (int i=0;i<monedas->size();i++)
    {
        QRectF Personaje=boundingRect();
        Personaje.moveTo((pos()));
        QRectF Moneda=monedas->at(i)->boundingRect();
        Moneda.moveTo(monedas->at(i)->pos());
        if(Personaje.intersects(Moneda))
        {                             monedas->removeAt(i);}
    }*/

    setPos(pos());
    Vx*=0.5;
    Vy*=0.5;
}

QRectF personaje::boundingRect() const
{
    return QRectF(0,0,10,10);
}

void personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  painter->setBrush(QBrush(Qt::red));
  painter->drawRect(0,0,10,10);
}
