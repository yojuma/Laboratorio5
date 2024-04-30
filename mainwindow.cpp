#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPointF>
#include <QRectF>
#include "papel.h"
#include "piedra.h"
#include "tijera.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    scene = new QGraphicsScene(this);
    piedra = new Piedra;
    papel = new Papel;
    tijera = new Tijera;

    timer->stop();

    scene->setSceneRect(0, 0, 1200, 700);
    scene->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());
    ui->graphicsView->setScene(scene);
    ui->graphicsView->resize(scene->width()+5, scene->height()+5);
    this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);

    //scene->addItem(piedra);
    //piedra->setPos(0,0);
    //scene->addItem(papel);
    //papel->setPos(500,700);
    scene->addItem(tijera);
    tijera->setPos(10,300);
    connect(timer, SIGNAL(timeout()), this, SLOT(actualizarEscena()));


}

MainWindow::~MainWindow()
{
    delete piedra;
    delete papel;
    delete tijera;
    delete ui;

}





void MainWindow::on_pushButton_clicked(){
    timer->start(20);
}

