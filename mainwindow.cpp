#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPointF>
#include <QRectF>
#include <QMessageBox>
#include "papel.h"
#include "piedra.h"
#include "tijera.h"
#include "explosion.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());
    ui->graphicsView->setScene(scene);
    ui->graphicsView->resize(scene->width()+5, scene->height()+5);
    this->resize(ui->graphicsView->width()+250, ui->graphicsView->height()+100);
    timer = new QTimer;
    timer->start(20);

    connect(timer, &QTimer::timeout, this, &MainWindow::actualizarColision);

}

MainWindow::~MainWindow(){
    delete piedra;
    delete papel;
    delete tijera;
    delete ui;
}

void MainWindow::on_tijera_clicked(){
    if(tijeras<5){
        tijera = new Tijera;
        scene->addItem(tijera);
        switch(tijeras){
        case 0:
            tijera->setPos(10,100);
            tijera->setPosY(100);
            ntijeras.push_back(tijera);
            break;
        case 1:
            tijera->setPos(10,200);
            tijera->setPosY(200);
            ntijeras.push_back(tijera);
            break;
        case 2:
            tijera->setPos(10,300);
            tijera->setPosY(300);
            ntijeras.push_back(tijera);
            break;
        case 3:
            tijera->setPos(10,400);
            tijera->setPosY(400);
            ntijeras.push_back(tijera);
            break;
        case 4:
            tijera->setPos(10,500);
            tijera->setPosY(500);
            ntijeras.push_back(tijera);
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
            npiedras.push_back(piedra);
            break;
        case 1:
            piedra->setPos(300,10);
            piedra->setPosX(300);
            npiedras.push_back(piedra);
            break;
        case 2:
            piedra->setPos(500,10);
            piedra->setPosX(500);
            npiedras.push_back(piedra);
            break;
        case 3:
            piedra->setPos(700,10);
            piedra->setPosX(700);
            npiedras.push_back(piedra);
            break;
        case 4:
            piedra->setPos(900,10);
            piedra->setPosX(900);
            npiedras.push_back(piedra);
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
            papel->setPosY(10);
            npapeles.push_back(papel);
            break;
        case 1:
            papel->setPos(1100,10);
            papel->setPosX(1100);
            papel->setPosY(10);
            npapeles.push_back(papel);
            break;
        case 2:
            papel->setPos(10,500);
            papel->setPosX(10);
            papel->setPosY(500);
            npapeles.push_back(papel);
            break;
        case 3:
            papel->setPos(1100,500);
            papel->setPosX(1100);
            papel->setPosY(500);
            npapeles.push_back(papel);
            break;
        case 4:
            papel->setPos(10,10);
            papel->setPosX(10);
            papel->setPosY(10);
            npapeles.push_back(papel);
            break;
        }
        papeles++;
        ui->cantidadPapeles->display(papeles);

    }else{
        QMessageBox msgBox;
        msgBox.setText("Maximo de papeles alcanzado.");
        msgBox.exec();
    }
    papel->on_pushButton_clicked();
}

void MainWindow::actualizarColision(){
    //verificar colision entre piedras y papeles
    for(auto e : npiedras){
        QList<QGraphicsItem*> colisiones = scene->collidingItems(e);
        if(!colisiones.isEmpty()){
            for(auto c : colisiones){
                Papel *choque = dynamic_cast<Papel *>(c);
                if(choque){
                    qreal x = e->getPosX();
                    qreal y = e->getPosY();
                    auto exp = new Explosion(x, y);
                    scene->removeItem(e);
                    piedras--;
                    puntosPapel++;
                    ui->cantidadPiedras->display(piedras);
                    ui->puntosPapeles->display(puntosPapel);
                    npiedras.removeOne(e);
                    scene->addItem(exp);
                    exp->setPos(x,y);
                }
            }
        }
    }
    //verificar colision entre papeles y tijeras
    for(auto f : npapeles){
        QList<QGraphicsItem*> colisiones = scene->collidingItems(f);
        if(!colisiones.isEmpty()){
            for(auto c : colisiones){
                Tijera *choque = dynamic_cast<Tijera *>(c);
                if(choque){
                    qreal x = f->getPosX();
                    qreal y = f->getPosY();
                    auto exp = new Explosion(x, y);
                    scene->removeItem(f);
                    papeles--;
                    puntosTijera++;
                    ui->cantidadPapeles->display(papeles);
                    ui->puntosTijeras->display(puntosTijera);
                    npapeles.removeOne(f);
                    scene->addItem(exp);
                    exp->setPos(x,y);
                }
            }
        }
    }
    //verificar colision entre tijeras y piedras
    for(auto g : ntijeras){
        QList<QGraphicsItem*> colisiones = scene->collidingItems(g);
        if(!colisiones.isEmpty()){
            for(auto c : colisiones){
                Piedra *choque = dynamic_cast<Piedra *>(c);
                if(choque){
                    qreal x = g->getPosX();
                    qreal y = g->getPosY();
                    auto exp = new Explosion(x, y);
                    scene->removeItem(g);
                    tijeras--;
                    puntosPiedra++;
                    ui->cantidadTijeras->display(tijeras);
                    ui->puntosPiedras->display(puntosPiedra);
                    ntijeras.removeOne(g);
                    scene->addItem(exp);
                    exp->setPos(x,y);
                }
            }
        }
    }
}

void MainWindow::on_IniciarConJugador_clicked()
{

}

