#include "personaje.h"

personaje::personaje(int posicionInicialX, int posicionInicialY)
{
    V0 = 50;
    Vx = V0 * cos(Angulo);
    Vy = V0 * sin(Angulo);



    setPos(posicionInicialX,posicionInicialY);


}





void personaje::aplicaraceleracion(QPointF Acel, QList<plataforma *> &paredes)
{

    QPointF posi_inicial=pos();
    float dt=0.1;
    Vx+=dt*Acel.x();
    Vy+=Acel.y();
    setX(pos().x()+Vx*dt+Acel.x()*0.5*dt*dt);
    setPos(pos());
    for (int i=0;i<paredes.size();i++)
    {
        if (collidesWithItem(paredes.at(i)))
        {
            setX(posi_inicial.x());

        }
    }

    setY(pos().y()+Vy*dt+Acel.y()*0.5*dt*dt);
    setPos(pos());
    for (int i=0;i<paredes.size();i++)
    {
        if (collidesWithItem(paredes.at(i)))
        {
            setY(posi_inicial.y());
            qDebug ()<<"si entra";

        }
    }
    setPos(pos());


}

QRectF personaje::boundingRect() const
{
  return QRectF(0,0,10,10);
}

void personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  painter->setBrush(QBrush(Qt::blue));
  painter->drawEllipse(boundingRect());
}

/*
personaje::personaje(int r_, int x, int y)
{
    r = r_;
    posx = x;
    posy = y;
    setPos(posx, posy);
}
*/

//no se esta usando
/*
void personaje::select_sprite(int x, int y)
{

}
*/

/*
void personaje::actualizarMParabolico()
{
    posicionX = X0 + Vx*t;
    posicionY = Y0 - Vy*t + ((G*t*t)/2);
    setPos(posicionX, posicionY);
    t += 0.1;
}
*/

/*
void personaje::saltar()
{
    Y0 = y();
    t = 0;
    timerOn();
}
*/
/*
void personaje::bajar()
{
    t = 10.7;
    timerOn();
}
*/

/*
void personaje::adelantar()
{
    posicionX+=1;
    setPos(posicionX, y());
}
*/
/*
void personaje::timerOn()
{
    timer->start(5);
}
*/
/*
float personaje::getPosicionX() const
{
   // posicionX = value;
}
*/

/*
float personaje::getPosicionY() const
{
    //posicionY = value;
}
*/
/*
float personaje::getT() const
{
     return t;
}
*/
/*
void personaje::setY0(float value)
{
    Y0 = value;
    setPos(x(), Y0);
}
*/
/*
void personaje::timerOff()
{
    timer->stop();
}
*/
/*
void personaje::setPosicionX(float value)
{
    Y0 = value;
    setPos(x(), Y0);
}
*/
