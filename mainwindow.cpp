#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPointF>
#include <QRectF>
#include "papel.h"
#include "piedra.h"
#include "tijera.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    scene = new QGraphicsScene(this);
    papel = new Papel;



    scene->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());
    ui->graphicsView->setScene(scene);
    ui->graphicsView->resize(scene->width()+5, scene->height()+5);
    this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);

}

MainWindow::~MainWindow(){
    delete piedra;
    delete papel;
    delete tijera;
    delete ui;

}

void MainWindow::actualizarEscena(){
    tijera->actualizarEscena();
    piedra->actualizarEscena();
}


void MainWindow::on_tijera_clicked(){
    if(tijeras<5){
        tijera = new Tijera;
        scene->addItem(tijera);
        switch(tijeras){
        case 0:
            tijera->setPos(10,100);
            tijera->setPosY(100);
            break;
        case 1:
            tijera->setPos(10,200);
            tijera->setPosY(200);
            break;
        case 2:
            tijera->setPos(10,300);
            tijera->setPosY(300);
            break;
        case 3:
            tijera->setPos(10,400);
            tijera->setPosY(400);
            break;
        case 4:
            tijera->setPos(10,500);
            tijera->setPosY(500);
            break;
        case 5:
            tijera->setPos(10,600);
            tijera->setPosY(600);
            break;
        }
        tijeras++;
        ui->cantidadTijeras->display(tijeras);

    }else{
        QMessageBox msgBox;
        msgBox.setText("Maximo de tijeras alcanzado.");
        msgBox.exec();
    }
    tijera->on_pushButton_clicked();
}

void MainWindow::on_piedra_clicked(){
    if(piedras<5){
        piedra = new Piedra;
        scene->addItem(piedra);
        switch(piedras){
        case 0:
            piedra->setPos(100,10);
            piedra->setPosX(100);
            break;
        case 1:
            piedra->setPos(200,10);
            piedra->setPosX(200);
            break;
        case 2:
            piedra->setPos(300,10);
            piedra->setPosX(300);
            break;
        case 3:
            piedra->setPos(400,10);
            piedra->setPosX(400);
            break;
        case 4:
            piedra->setPos(500,10);
            piedra->setPosX(500);
            break;
        case 5:
            piedra->setPos(600,10);
            piedra->setPosX(600);
            break;
        }
        piedras++;
        ui->cantidadPiedras->display(piedras);

    }else{
        QMessageBox msgBox;
        msgBox.setText("Maximo de piedras alcanzado.");
        msgBox.exec();
    }
    piedra->on_pushButton_clicked();
}


void MainWindow::on_papel_clicked(){
    if(papeles<5){
        papel = new Papel;
        scene->addItem(papel);
        switch(papeles){
        case 0:
            papel->setPos(10,10);
            papel->setPosX(10);
            break;
        case 1:
            papel->setPos(200,10);
            papel->setPosX(200);
            break;
        case 2:
            papel->setPos(300,10);
            papel->setPosX(300);
            break;
        case 3:
            papel->setPos(400,10);
            papel->setPosX(400);
            break;
        case 4:
            papel->setPos(500,10);
            papel->setPosX(500);
            break;
        case 5:
            papel->setPos(600,10);
            papel->setPosX(600);
            break;
        }
        piedras++;
        ui->cantidadPapeles->display(piedras);

    }else{
        QMessageBox msgBox;
        msgBox.setText("Maximo de papeles alcanzado.");
        msgBox.exec();
    }
    papel->on_pushButton_clicked();

}

