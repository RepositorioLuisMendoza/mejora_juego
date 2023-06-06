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

    cuerpo = new personaje (30,50);
    cuchillos = new QList<cuchillo*>;
    monedas=new QList<comida*>;

    addItem(cuerpo);


    //cuerpo->select_sprite(0,0);
    paredes_();
    cuchillos_();
    comida_();
    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(actualizar()));
    timer->start(10);


}


void juego::cuchillos_()
{
    crear_cuchillos(20, 0);
    crear_cuchillos(100,0);
    crear_cuchillos(200, 0);
    crear_cuchillos(300, 0);
}





void juego::keyPressEvent(QKeyEvent *evento)
{    
    if(evento->key()==Qt::Key_D){
            cuerpo->aplicaraceleracion({200,0},paredes);
            for (int i = 0;i < monedas->size();i++) {
                 if(cuerpo->collidesWithItem(monedas->at(i))){
                    // puntaje_->incremento(); // incremento de puntaje
                     removeItem(monedas->at(i)); // eliminar moneda de esena
                     monedas->removeAt(i);

                     i--;
                    }
                }
    }

    if(evento->key()==Qt::Key_A){
        cuerpo->aplicaraceleracion({-200,0},paredes);
    }

    if(evento->key()==Qt::Key_W){

        //if(cuepor->variablesalto==true)
        //   cuerpo->variablesalto=false;
            cuerpo->aplicaraceleracion({0,-200},paredes);

    }

    if(evento->key()==Qt::Key_S){
        cuerpo->aplicaraceleracion({0,200},paredes);

    }
    if(evento->key()==Qt::Key_L){
        cuerpo->aplicaraceleracion({0,-400},paredes);
        cuerpo->aplicaraceleracion({10,-300},paredes);
        cuerpo->aplicaraceleracion({10,-200},paredes);
        cuerpo->aplicaraceleracion({10,-100},paredes);
        cuerpo->aplicaraceleracion({10,-50},paredes);





    }

}

void juego::actualizar()
{
    AplicarGravedad();
}
void juego::AplicarGravedad()
{
    cuerpo->aplicaraceleracion({0,10},paredes);
    for(cuchillo *Cuchillo__ : *cuchillos)
    {
        Cuchillo__->aplicaraceleracion({0,10});
    }
}

void juego::crear_monedas(int x, int y, int ancho, int alto)
{
    monedas->push_back(new comida(x,y,ancho,alto));
    addItem(monedas->back());
}
void juego::crear_pared(int x, int y, int ancho, int alto)
{
    paredes->push_back(new plataforma (x,y,ancho,alto));
    addItem(paredes->back());
}

void juego::crear_cuchillos(int Pos_x, int Pos_y)
{
    int ancho = 15;
    int alto = 15;
    cuchillos->push_back(new cuchillo (Pos_x,Pos_y,ancho, alto));
    addItem(cuchillos->back());
}



void juego::comida_()
{

    monedas = new QList<comida*>;

    crear_monedas(50,50,5,5);
     crear_monedas(159,46,10,10);
     crear_monedas(210,46,10,10);
     crear_monedas(260,46,10,10);
     crear_monedas(305,46,10,10);
     crear_monedas(380,46,10,10);
     crear_monedas(430,46,10,10);
     crear_monedas(470,46,10,10);
     crear_monedas(528,46,10,10);
     crear_monedas(580,46,10,10);
     crear_monedas(638,46,10,10);
     crear_monedas(50,78,10,10);
     crear_monedas(159,78,10,10);
     crear_monedas(305,78,10,10);
     crear_monedas(380,78,10,10);
     crear_monedas(528,78,10,10);
     crear_monedas(638,78,10,10);
     crear_monedas(50,110,10,10);
     crear_monedas(103,110,10,10);
     crear_monedas(159,110,10,10);
     crear_monedas(210,110,10,10);
     crear_monedas(260,110,10,10);
     crear_monedas(305,110,10,10);
     crear_monedas(380,110,10,10);
     crear_monedas(430,110,10,10);
     crear_monedas(483,110,10,10);
     crear_monedas(531,110,10,10);
     crear_monedas(580,110,10,10);
     crear_monedas(644,110,10,10);
     crear_monedas(50,145,10,10);
     crear_monedas(159,145,10,10);
     crear_monedas(531,145,10,10);
     crear_monedas(644,145,10,10);
     crear_monedas(50,176,10,10);
     crear_monedas(103,176,10,10);
     crear_monedas(159,176,10,10);
     crear_monedas(260,176,10,10);
     crear_monedas(305,176,10,10);
     crear_monedas(380,176,10,10);
     crear_monedas(430,176,10,10);
     crear_monedas(531,176,10,10);
     crear_monedas(580,176,10,10);
     crear_monedas(644,176,10,10);
     crear_monedas(305,212,10,10);
     crear_monedas(380,212,10,10);
     crear_monedas(531,212,10,10);
     crear_monedas(260,244,10,10);
     crear_monedas(305,244,10,10);
     crear_monedas(380,244,10,10);
     crear_monedas(430,244,10,10);
     crear_monedas(531,244,10,10);
     crear_monedas(50,308,10,10);
     crear_monedas(103,308,10,10);
     crear_monedas(159,308,10,10);
     crear_monedas(531,308,10,10);
     crear_monedas(580,308,10,10);
     crear_monedas(644,308,10,10);
     crear_monedas(531,342,10,10);
     crear_monedas(260,375,10,10);
     crear_monedas(305,375,10,10);
     crear_monedas(380,375,10,10);
     crear_monedas(430,375,10,10);
     crear_monedas(531,375,10,10);
     crear_monedas(531,408,10,10);
     crear_monedas(50,444,10,10);
     crear_monedas(103,444,10,10);
     crear_monedas(159,444,10,10);
     crear_monedas(210,444,10,10);
     crear_monedas(260,444,10,10);
     crear_monedas(305,444,10,10);
     crear_monedas(380,444,10,10);
     crear_monedas(430,444,10,10);
     crear_monedas(483,444,10,10);
     crear_monedas(531,444,10,10);
     crear_monedas(580,444,10,10);
     crear_monedas(644,444,10,10);
     crear_monedas(50,474,10,10);
     crear_monedas(159,474,10,10);
     crear_monedas(305,474,10,10);
     crear_monedas(380,474,10,10);
     crear_monedas(531,474,10,10);
     crear_monedas(644,474,10,10);
     crear_monedas(50,510,10,10);
     crear_monedas(159,510,10,10);
     crear_monedas(210,510,10,10);
     crear_monedas(260,510,10,10);
     crear_monedas(305,510,10,10);
     crear_monedas(380,510,10,10);
     crear_monedas(430,510,10,10);
     crear_monedas(483,510,10,10);
     crear_monedas(531,510,10,10);
     crear_monedas(644,510,10,10);
     crear_monedas(159,540,10,10);
     crear_monedas(531,540,10,10);
     crear_monedas(50,574,10,10);
     crear_monedas(103,574,10,10);
     crear_monedas(159,574,10,10);
     crear_monedas(260,574,10,10);
     crear_monedas(305,574,10,10);
     crear_monedas(380,574,10,10);
     crear_monedas(430,574,10,10);
     crear_monedas(531,574,10,10);
     crear_monedas(580,574,10,10);
     crear_monedas(644,574,10,10);
     crear_monedas(50,608,10,10);
     crear_monedas(305,608,10,10);
     crear_monedas(380,608,10,10);
     crear_monedas(644,608,10,10);
     crear_monedas(50,642,10,10);
     crear_monedas(103,642,10,10);
     crear_monedas(159,642,10,10);
     crear_monedas(210,642,10,10);
     crear_monedas(260,642,10,10);
     crear_monedas(305,642,10,10);
     crear_monedas(380,642,10,10);
     crear_monedas(430,642,10,10);
     crear_monedas(483,642,10,10);
     crear_monedas(531,642,10,10);
     crear_monedas(580,642,10,10);
     crear_monedas(644,642,10,10);
}




void juego::paredes_()
{
    paredes = new QList<plataforma*>;


    crear_pared(0,-30,700,50);
    crear_pared(0,0,20,700);
    crear_pared(680,0,20,700);
    crear_pared(0,680,700,20);

    crear_pared(20,20,20,20);
    crear_pared(60, 20, 20, 20);
    crear_pared(100, 20, 20, 20);
    crear_pared(140, 20, 20, 20);
    crear_pared(180, 20, 20, 20);
    crear_pared(220, 20, 20, 20);
    crear_pared(260, 20, 20, 20);
    crear_pared(300, 20, 20, 20);
    crear_pared(340, 20, 20, 20);
    crear_pared(380, 20, 20, 20);
    crear_pared(420, 20, 20, 20);
    crear_pared(460, 20, 20, 20);
    crear_pared(500, 20, 20, 20);
    crear_pared(540, 20, 20, 20);
    crear_pared(580, 20, 20, 20);
    crear_pared(620, 20, 20, 20);
    crear_pared(660, 20, 20, 20);
    crear_pared(700, 20, 20, 20);

    crear_pared(20, 60, 20, 20);
    crear_pared(60, 60, 20, 20);
    crear_pared(100, 60, 20, 20);
    crear_pared(140, 60, 20, 20);
    crear_pared(180, 60, 20, 20);
    crear_pared(220, 60, 20, 20);
    crear_pared(260, 60, 20, 20);
    crear_pared(300, 60, 20, 20);
    crear_pared(340, 60, 20, 20);
    crear_pared(380, 60, 20, 20);
    crear_pared(420, 60, 20, 20);
    crear_pared(460, 60, 20, 20);
    crear_pared(500, 60, 20, 20);
    crear_pared(540, 60, 20, 20);
    crear_pared(580, 60, 20, 20);
    crear_pared(620, 60, 20, 20);
    crear_pared(660, 60, 20, 20);

    crear_pared(20, 100, 20, 20);
    crear_pared(60, 100, 20, 20);
    crear_pared(100, 100, 20, 20);
    crear_pared(140, 100, 20, 20);
    crear_pared(180, 100, 20, 20);
    crear_pared(220, 100, 20, 20);
    crear_pared(260, 100, 20, 20);
    crear_pared(300, 100, 20, 20);
    crear_pared(340, 100, 20, 20);
    crear_pared(380, 100, 20, 20);
    crear_pared(420, 100, 20, 20);
    crear_pared(460, 100, 20, 20);
    crear_pared(500, 100, 20, 20);
    crear_pared(540, 100, 20, 20);
    crear_pared(580, 100, 20, 20);
    crear_pared(620, 100, 20, 20);
    crear_pared(660, 100, 20, 20);

    crear_pared(20, 140, 20, 20);
    crear_pared(60, 140, 20, 20);
    crear_pared(100, 140, 20, 20);
    crear_pared(140, 140, 20, 20);
    crear_pared(180, 140, 20, 20);
    crear_pared(220, 140, 20, 20);
    crear_pared(260, 140, 20, 20);
    crear_pared(300, 140, 20, 20);
    crear_pared(340, 140, 20, 20);
    crear_pared(380, 140, 20, 20);
    crear_pared(420, 140, 20, 20);
    crear_pared(460, 140, 20, 20);
    crear_pared(500, 140, 20, 20);
    crear_pared(540, 140, 20, 20);
    crear_pared(580, 140, 20, 20);
    crear_pared(620, 140, 20, 20);
    crear_pared(660, 140, 20, 20);

    crear_pared(20, 180, 20, 20);
    crear_pared(60, 180, 20, 20);
    crear_pared(100, 180, 20, 20);
    crear_pared(140, 180, 20, 20);
    crear_pared(180, 180, 20, 20);
    crear_pared(220, 180, 20, 20);
    crear_pared(260, 180, 20, 20);
    crear_pared(300, 180, 20, 20);
    crear_pared(340, 180, 20, 20);
    crear_pared(380, 180, 20, 20);
    crear_pared(420, 180, 20, 20);
    crear_pared(460, 180, 20, 20);
    crear_pared(500, 180, 20, 20);
    crear_pared(540, 180, 20, 20);
    crear_pared(580, 180, 20, 20);
    crear_pared(620, 180, 20, 20);
    crear_pared(660, 180, 20, 20);
    crear_pared(20, 180, 20, 20);
    crear_pared(60, 180, 20, 20);
    crear_pared(100, 180, 20, 20);
    crear_pared(140, 180, 20, 20);
    crear_pared(180, 180, 20, 20);
    crear_pared(220, 180, 20, 20);
    crear_pared(260, 180, 20, 20);
    crear_pared(300, 180, 20, 20);
    crear_pared(340, 180, 20, 20);
    crear_pared(380, 180, 20, 20);
    crear_pared(420, 180, 20, 20);
    crear_pared(460, 180, 20, 20);
    crear_pared(500, 180, 20, 20);
    crear_pared(540, 180, 20, 20);
    crear_pared(580, 180, 20, 20);
    crear_pared(620, 180, 20, 20);
    crear_pared(660, 180, 20, 20);

    crear_pared(20, 220, 20, 20);
    crear_pared(60, 220, 20, 20);
    crear_pared(100, 220, 20, 20);
    crear_pared(140, 220, 20, 20);
    crear_pared(180, 220, 20, 20);
    crear_pared(220, 220, 20, 20);
    crear_pared(260, 220, 20, 20);
    crear_pared(300, 220, 20, 20);
    crear_pared(340, 220, 20, 20);
    crear_pared(380, 220, 20, 20);
    crear_pared(420, 220, 20, 20);
    crear_pared(460, 220, 20, 20);
    crear_pared(500, 220, 20, 20);
    crear_pared(540, 220, 20, 20);
    crear_pared(580, 220, 20, 20);
    crear_pared(620, 220, 20, 20);
    crear_pared(660, 220, 20, 20);


    crear_pared(20, 260, 20, 20);
    crear_pared(60, 260, 20, 20);
    crear_pared(100, 260, 20, 20);
    crear_pared(140, 260, 20, 20);
    crear_pared(180, 260, 20, 20);
    crear_pared(220, 260, 20, 20);
    crear_pared(260, 260, 20, 20);
    crear_pared(300, 260, 20, 20);
    crear_pared(340, 260, 20, 20);
    crear_pared(380, 260, 20, 20);
    crear_pared(420, 260, 20, 20);
    crear_pared(460, 260, 20, 20);
    crear_pared(500, 260, 20, 20);
    crear_pared(540, 260, 20, 20);
    crear_pared(580, 260, 20, 20);
    crear_pared(620, 260, 20, 20);
    crear_pared(660, 260, 20, 20);


    crear_pared(20, 300, 20, 20);
    crear_pared(60, 300, 20, 20);
    crear_pared(100, 300, 20, 20);
    crear_pared(140, 300, 20, 20);
    crear_pared(180, 300, 20, 20);
    crear_pared(220, 300, 20, 20);
    crear_pared(260, 300, 20, 20);
    crear_pared(300, 300, 20, 20);
    crear_pared(340, 300, 20, 20);
    crear_pared(380, 300, 20, 20);
    crear_pared(420, 300, 20, 20);
    crear_pared(460, 300, 20, 20);
    crear_pared(500, 300, 20, 20);
    crear_pared(540, 300, 20, 20);
    crear_pared(580, 300, 20, 20);
    crear_pared(620, 300, 20, 20);
    crear_pared(660, 300, 20, 20);


    crear_pared(20, 340, 20, 20);
    crear_pared(60, 340, 20, 20);
    crear_pared(100, 340, 20, 20);
    crear_pared(140, 340, 20, 20);
    crear_pared(180, 340, 20, 20);
    crear_pared(220, 340, 20, 20);
    crear_pared(260, 340, 20, 20);
    crear_pared(300, 340, 20, 20);
    crear_pared(340, 340, 20, 20);
    crear_pared(380, 340, 20, 20);
    crear_pared(420, 340, 20, 20);
    crear_pared(460, 340, 20, 20);
    crear_pared(500, 340, 20, 20);
    crear_pared(540, 340, 20, 20);
    crear_pared(580, 340, 20, 20);
    crear_pared(620, 340, 20, 20);
    crear_pared(660, 340, 20, 20);

    crear_pared(20, 380, 20, 20);
    crear_pared(60, 380, 20, 20);
    crear_pared(100, 380, 20, 20);
    crear_pared(140, 380, 20, 20);
    crear_pared(180, 380, 20, 20);
    crear_pared(220, 380, 20, 20);
    crear_pared(260, 380, 20, 20);
    crear_pared(300, 380, 20, 20);
    crear_pared(340, 380, 20, 20);
    crear_pared(380, 380, 20, 20);
    crear_pared(420, 380, 20, 20);
    crear_pared(460, 380, 20, 20);
    crear_pared(500, 380, 20, 20);
    crear_pared(540, 380, 20, 20);
    crear_pared(580, 380, 20, 20);
    crear_pared(620, 380, 20, 20);
    crear_pared(660, 380, 20, 20);

    crear_pared(20, 420, 20, 20);
    crear_pared(60, 420, 20, 20);
    crear_pared(100, 420, 20, 20);
    crear_pared(140, 420, 20, 20);
    crear_pared(180, 420, 20, 20);
    crear_pared(220, 420, 20, 20);
    crear_pared(260, 420, 20, 20);
    crear_pared(300, 420, 20, 20);
    crear_pared(340, 420, 20, 20);
    crear_pared(380, 420, 20, 20);
    crear_pared(420, 420, 20, 20);
    crear_pared(460, 420, 20, 20);
    crear_pared(500, 420, 20, 20);
    crear_pared(540, 420, 20, 20);
    crear_pared(580, 420, 20, 20);
    crear_pared(620, 420, 20, 20);
    crear_pared(660, 420, 20, 20);

    crear_pared(20, 460, 20, 20);
    crear_pared(60, 460, 20, 20);
    crear_pared(100, 460, 20, 20);
    crear_pared(140, 460, 20, 20);
    crear_pared(180, 460, 20, 20);
    crear_pared(220, 460, 20, 20);
    crear_pared(260, 460, 20, 20);
    crear_pared(300, 460, 20, 20);
    crear_pared(340, 460, 20, 20);
    crear_pared(380, 460, 20, 20);
    crear_pared(420, 460, 20, 20);
    crear_pared(460, 460, 20, 20);
    crear_pared(500, 460, 20, 20);
    crear_pared(540, 460, 20, 20);
    crear_pared(580, 460, 20, 20);
    crear_pared(620, 460, 20, 20);
    crear_pared(660, 460, 20, 20);

    crear_pared(20, 500, 20, 20);
    crear_pared(60, 500, 20, 20);
    crear_pared(100, 500, 20, 20);
    crear_pared(140, 500, 20, 20);
    crear_pared(180, 500, 20, 20);
    crear_pared(220, 500, 20, 20);
    crear_pared(260, 500, 20, 20);
    crear_pared(300, 500, 20, 20);
    crear_pared(340, 500, 20, 20);
    crear_pared(380, 500, 20, 20);
    crear_pared(420, 500, 20, 20);
    crear_pared(460, 500, 20, 20);
    crear_pared(500, 500, 20, 20);
    crear_pared(540, 500, 20, 20);
    crear_pared(580, 500, 20, 20);
    crear_pared(620, 500, 20, 20);
    crear_pared(660, 500, 20, 20);


    crear_pared(20, 540, 20, 20);
    crear_pared(60, 540, 20, 20);
    crear_pared(100, 540, 20, 20);
    crear_pared(140, 540, 20, 20);
    crear_pared(180, 540, 20, 20);
    crear_pared(220, 540, 20, 20);
    crear_pared(260, 540, 20, 20);
    crear_pared(300, 540, 20, 20);
    crear_pared(340, 540, 20, 20);
    crear_pared(380, 540, 20, 20);
    crear_pared(420, 540, 20, 20);
    crear_pared(460, 540, 20, 20);
    crear_pared(500, 540, 20, 20);
    crear_pared(540, 540, 20, 20);
    crear_pared(580, 540, 20, 20);
    crear_pared(620, 540, 20, 20);
    crear_pared(660, 540, 20, 20);


    crear_pared(20, 580, 20, 20);
    crear_pared(60, 580, 20, 20);
    crear_pared(100, 580, 20, 20);
    crear_pared(140, 580, 20, 20);
    crear_pared(180, 580, 20, 20);
    crear_pared(220, 580, 20, 20);
    crear_pared(260, 580, 20, 20);
    crear_pared(300, 580, 20, 20);
    crear_pared(340, 580, 20, 20);
    crear_pared(380, 580, 20, 20);
    crear_pared(420, 580, 20, 20);
    crear_pared(460, 580, 20, 20);
    crear_pared(500, 580, 20, 20);
    crear_pared(540, 580, 20, 20);
    crear_pared(580, 580, 20, 20);
    crear_pared(620, 580, 20, 20);
    crear_pared(660, 580, 20, 20);

    crear_pared(20, 620, 20, 20);
    crear_pared(60, 620, 20, 20);
    crear_pared(100, 620, 20, 20);
    crear_pared(140, 620, 20, 20);
    crear_pared(180, 620, 20, 20);
    crear_pared(220, 620, 20, 20);
    crear_pared(260, 620, 20, 20);
    crear_pared(300, 620, 20, 20);
    crear_pared(340, 620, 20, 20);
    crear_pared(380, 620, 20, 20);
    crear_pared(420, 620, 20, 20);
    crear_pared(460, 620, 20, 20);
    crear_pared(500, 620, 20, 20);
    crear_pared(540, 620, 20, 20);
    crear_pared(580, 620, 20, 20);
    crear_pared(620, 620, 20, 20);
    crear_pared(660, 620, 20, 20);

    crear_pared(20, 660, 20, 20);
    crear_pared(60, 660, 20, 20);
    crear_pared(100, 660, 20, 20);
    crear_pared(140, 660, 20, 20);
    crear_pared(180, 660, 20, 20);
    crear_pared(220, 660, 20, 20);
    crear_pared(260, 660, 20, 20);
    crear_pared(300, 660, 20, 20);
    crear_pared(340, 660, 20, 20);
    crear_pared(380, 660, 20, 20);
    crear_pared(420, 660, 20, 20);
    crear_pared(460, 660, 20, 20);
    crear_pared(500, 660, 20, 20);
    crear_pared(540, 660, 20, 20);
    crear_pared(580, 660, 20, 20);
    crear_pared(620, 660, 20, 20);
    crear_pared(660, 660, 20, 20);


}


/*
void juego::cuchillos_()
{
    int random_num;
    random_num = rand()%700;
    crear_cuchillos(random_num,0);

   // qDebug () << "cuerpo agregado a lista";


}
*/

/*
void juego::colision_cuchillos()
{
    for (int j = 0; j < cuchillos->size(); j++) {
        //if (paredes[i]->collidesWithItem((*cuchillos)[j]))
        cuchillo *cuchilloActual = (*cuchillos)[j];
        if (cuchilloActual->getPosicionY()>700 && cuchilloActual->getPosicionX() != 0){
            cuchillos->removeAt(j);
            cuchillos_();
            qDebug() << "Cantidad de cuchillos:" << cuchillos->size();
        }

}   }
*/

QList<comida *> juego::eliminarMonedas(QList<comida *> monedas, int pos)
{
    QList<comida *> aux;
    for (int i = 0;i < monedas.size() ; i++) {
        if(i != pos){
            aux.push_back(monedas.at(i));
        }
    }
    return aux;
    if (monedas.isEmpty())
    {
        //personaje->ganaste();
        timer->stop();
        qDebug ()<< "que viva la chucha";
    }
}
