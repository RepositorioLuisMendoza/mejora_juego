#include "juego.h"

juego::juego()
{
    // get obtener set modificar
    QBrush l; // imagen de fondo
    QImage r;
    r.load(":/imagenes/fondo.jpg");
    l.setTextureImage(r);
    setBackgroundBrush(l);
    //cuchi=new cuchillo(100,100);

    cuerpo = new personaje (500,50);
    cuchillos = new QList<cuchillo*>;

    addItem(cuerpo);


    //cuerpo->select_sprite(0,0);
    paredes_();
    cuchillos_();
    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(actualizar()));
    timer->start(10);

}

void juego::paredes_()
{
    crear_pared(0,680,700,20);
    crear_pared(0,0,700,5);
    crear_pared(0,0,5,700);
    crear_pared(694,0,5,700);
    crear_pared(0,685,700,10);

    crear_pared(0,670,320,5);
    crear_pared(350,680,320,5);
    crear_pared(670,640,40,5);
    crear_pared(30,610,100,5);
    crear_pared(0,550,15,5);





}

void juego::cuchillos_()
{
    crear_cuchillos(20, 0);
    crear_cuchillos(100,0);
    crear_cuchillos(200, 0);
    crear_cuchillos(300, 0);
}




void juego::crear_pared(int x, int y, int ancho, int alto)
{
    paredes.push_back(new plataforma (x,y,ancho,alto));
    addItem(paredes.back());
}

void juego::crear_cuchillos(int Pos_x, int Pos_y)
{
    int ancho = 15;
    int alto = 15;
    cuchillos->push_back(new cuchillo (Pos_x,Pos_y,ancho, alto));
    addItem(cuchillos->back());
}

void juego::keyPressEvent(QKeyEvent *evento)
{

    if(evento->key()==Qt::Key_D){
        cuerpo->aplicaraceleracion({100,0},paredes);


    }

    if(evento->key()==Qt::Key_A){
        cuerpo->aplicaraceleracion({-100,0},paredes);
    }

    if(evento->key()==Qt::Key_W){
        cuerpo->aplicaraceleracion({0,-100},paredes);
    }

    if(evento->key()==Qt::Key_S){
        cuerpo->aplicaraceleracion({0,100},paredes);
    }


}

void juego::actualizar()
{
    AplicarGravedad();
}
void juego::AplicarGravedad()
{
    /*QList<QGraphicsItem*> Items = this->items();
    for(QGraphicsItem *Item : Items)
    {
        cuchillo *Cuchillo = dynamic_cast<cuchillo*>(Item);
        if(Cuchillo)
        {
            QPointF Pos=Cuchillo->pos();
            throw 0;
        }
    }*/
    cuerpo->aplicaraceleracion({0,10},paredes);
    for(cuchillo *Cuchillo__ : *cuchillos)
    {
        Cuchillo__->aplicaraceleracion({0,10});
    }
}
