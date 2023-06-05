#include "cuchillo.h"


cuchillo::cuchillo(int posicionInicialX, int posicionInicialY, int ancho_, int alto_)
{
    posicionX=posicionInicialX;
    posicionY=posicionInicialY;
    ancho = ancho_;
    alto = alto_ ;
    //posicionInicialX=posicionInicialX;
    //posicionInicialY=posicionInicialY;
    setPos(posicionX, posicionY);
    /*V = v;
    V0 = 78;
    Vx = V0 * cos(Angulo);
    Vy = V0 * sin(Angulo);

    X0 = posicionInicialX;
    Y0 = posicionInicialY;

delta = del ;

  setRect(0, 0, 10, 10);
    setPos(X0, Y0);

    //connect(timer, &QTimer::timeout, this, &cuchillo::actulalizarMparabolico);
    //timer->start(15);*/
}

//void cuchillo::actulalizarMparabolico()
//{
//    posicionX = X0 - Vx*t;
//    posicionY = Y0 - Vy*t + ((G*t*t)/2);
//    setPos(posicionX, posicionY);
//    t += 0.1;
//}


float cuchillo::getPosicionX() const
{
    return posicionX;
}

float cuchillo::getPosicionY() const
{
    return posicionY;
}


QRectF cuchillo::boundingRect() const
{
    return QRectF(0,0,alto,ancho);
}

void cuchillo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(boundingRect());
}

void cuchillo::aplicaraceleracion(QPointF Acel)
{
    float dt=0.1;
    Vx+=dt*Acel.x();
    Vy+=Acel.y();
    posicionX+=Vx*dt+Acel.x()*0.5*dt*dt;
    posicionY+=Vy*dt+Acel.y()*0.5*dt*dt;
    setPos(posicionX,posicionY);
}

//void cuchillo::calcularVelocidad()
//{
//    Vx = v*cos(angulo);
//   // Vy = v*sin(angulo)-G*del;
//    angulo = atan2(Vy,Vx);
//    v = sqrt(Vx*velocidad_x+Vy*Vy);
//}
