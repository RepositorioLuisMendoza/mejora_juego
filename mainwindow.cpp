#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new juego;
    ui->graphicsView->setFixedSize(700,700);
    scene->setSceneRect(0,0,ui->graphicsView->width()-2,ui->graphicsView->height()-2);
    ui->graphicsView->setScene(scene);
    setWindowTitle("Ladroncito");
}



MainWindow::~MainWindow()
{
    delete ui;
}
