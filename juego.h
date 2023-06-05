#ifndef JUEGO_H
#define JUEGO_H

#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include <QKeyEvent>
#include <QDebug>
#include "comida.h"
#include "cuchillo.h"
#include "personaje.h"
#include "plataforma.h"
#include <iostream>

using namespace std;


class juego : public QGraphicsScene
{
    Q_OBJECT
public:
    juego();
    void paredes_ ();
    void cuchillos_ ();
    personaje *cuerpo;



private:
    float dt;

    //cuchillo *cuchi;
    void AplicarGravedad();


    QTimer* timer;


    QList <plataforma *> paredes;
    void crear_pared(int x, int y, int ancho, int alto);

    void crear_cuchillos(int Pos_x, int Pos_y);
    QList <cuchillo *> *cuchillos;
protected:
    void keyPressEvent(QKeyEvent *evento);
private slots:
    void actualizar();


};

#endif // JUEGO_H
