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
#include "jugador.h"
#include "QKeyEvent"
#include "QTimer"

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
    QMessageBox msgBox;
    msgBox.setText("--Bienvenido al juego-- \n"
                   "El juego viene con 2 modos incluidos, el primero se juega en automático, el usuario solo debe añadir elementos.\n"
                   "Con el segundo modo podrás controlar una mira con las teclas WASD y la tecla space para eliminar objetos de la pantalla.\n"
                   "Buena suerte");
    msgBox.exec();
    connect(timer, &QTimer::timeout, this, &MainWindow::actualizarColision);



}

MainWindow::~MainWindow(){
    delete piedra;
    delete papel;
    delete tijera;
    delete mira;
    delete ui;
}

void MainWindow::on_ButtomTijera_clicked(){
    //agregar las tijeras a la escena presionando el botón
    if(tijeras<5){
        tijera = new Tijera;
        scene->addItem(tijera);
        switch(tijeras){
        case 0:
            tijera->setPos(10,200);
            tijera->setPosY(200);
            ntijeras.push_back(tijera);
            break;
        case 1:
            tijera->setPos(10,300);
            tijera->setPosY(300);
            ntijeras.push_back(tijera);
            break;
        case 2:
            tijera->setPos(10,400);
            tijera->setPosY(400);
            ntijeras.push_back(tijera);
            break;
        case 3:
            tijera->setPos(10,500);
            tijera->setPosY(500);
            ntijeras.push_back(tijera);
            break;
        case 4:
            tijera->setPos(10,600);
            tijera->setPosY(600);
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

void MainWindow::on_ButtomPiedra_clicked(){
     //agregar las piedras a la escena presionando el botón
    if(piedras<5){
        piedra = new Piedra;
        scene->addItem(piedra);
        switch(piedras){
        case 0:
            piedra->setPos(200,600);
            piedra->setPosX(200);

            npiedras.push_back(piedra);
            break;
        case 1:
            piedra->setPos(400,600);
            piedra->setPosX(400);
            npiedras.push_back(piedra);
            break;
        case 2:
            piedra->setPos(600,600);
            piedra->setPosX(600);
            npiedras.push_back(piedra);
            break;
        case 3:
            piedra->setPos(800,600);
            piedra->setPosX(800);
            npiedras.push_back(piedra);
            break;
        case 4:
            piedra->setPos(1000,600);
            piedra->setPosX(1000);
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

void MainWindow::on_ButtomPapel_clicked(){
     //agregar los papeles a la escena presionando el botón
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

void MainWindow::activarTimer(){
    tiempo--;
    if(tiempo==499){
        tiempo=459;
    }
    else if(tiempo==399){
        tiempo=359;
    }
    else if(tiempo==299){
        tiempo=259;
    }
    else if(tiempo==199){
        tiempo=159;
    }
    else if(tiempo==99){
        tiempo=59;
    }
    ui->contadorJuego->display(tiempo);
    if(tiempo==0){
        if(puntosPiedra>puntosPapel && puntosPiedra>puntosTijera && puntosPiedra>puntosJugador){
            QMessageBox msgBox;
            msgBox.setText("Tiempo terminado.\n"
                           "El ganador es Piedra.");
            msgBox.exec();
            timer->stop();
            delete piedra;
            delete papel;
            delete tijera;
            delete mira;
            delete ui;
        }
        else if(puntosPapel>puntosPiedra && puntosPapel>puntosTijera && puntosPapel>puntosJugador){
            QMessageBox msgBox;
            msgBox.setText("Tiempo terminado.\n"
                           "El ganador es Papel.");
            msgBox.exec();
            timer->stop();
            delete piedra;
            delete papel;
            delete tijera;
            delete mira;
            delete ui;
        }
        else if(puntosTijera>puntosPapel && puntosTijera>puntosPiedra && puntosTijera>puntosJugador){
            QMessageBox msgBox;
            msgBox.setText("Tiempo terminado.\n"
                           "El ganador es Tijera.");
            msgBox.exec();
            timer->stop();
            delete piedra;
            delete papel;
            delete tijera;
            delete mira;
            delete ui;
        }
        else if(puntosJugador>puntosPapel && puntosJugador>puntosTijera && puntosJugador>puntosPiedra){
            QMessageBox msgBox;
            msgBox.setText("Tiempo terminado.\n"
                           "El ganador es el Jugador.");
            msgBox.exec();
            timer->stop();
            delete piedra;
            delete papel;
            delete tijera;
            delete mira;
            delete ui;
        }
        else{
            QMessageBox msgBox;
            msgBox.setText("Tiempo terminado.\n"
                           "No hay ganador.");
            msgBox.exec();
            timer->stop();
            delete piedra;
            delete papel;
            delete tijera;
            delete mira;
            delete ui;
        }

    }
}

void MainWindow::on_IniciarConJugador_clicked(){
    scene->addItem(mira);
    mira->setPos(600,350);
    ui->contadorJuego->display(tiempo);
    QTimer *cronometro= new QTimer(this);
    connect(cronometro, &QTimer::timeout, this, &MainWindow::activarTimer);
    cronometro->start(1000);
    ui->ButtomTijera->setEnabled(false);
    ui->ButtomPiedra->setEnabled(false);
    ui->ButtomPapel->setEnabled(false);
    ui->IniciarConJugador->setEnabled(false);


    if(piedras<5){
        QTimer *timerPiedras=new QTimer(this);
        connect(timerPiedras, &QTimer::timeout, this, &MainWindow::on_ButtomPiedra_clicked);
        timerPiedras->start(10000);
    }
    timer->start(100);
    if(papeles<5){
        QTimer *timerPapeles=new QTimer(this);
        connect(timerPapeles, &QTimer::timeout, this, &MainWindow::on_ButtomPapel_clicked);
        timerPapeles->start(12000);
    }
    timer->start(100);
    if(tijeras<5){
        QTimer *timerTijeras=new QTimer(this);
        connect(timerTijeras, &QTimer::timeout, this, &MainWindow::on_ButtomTijera_clicked);
        timerTijeras->start(14000);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    if(mira != nullptr){
        if(event->key() == Qt::Key_A){
            mira->moveLeft();
        }
        else if(event->key() == Qt::Key_D){
            mira->moveRight();
        }
        else if(event->key() == Qt::Key_W){
            mira->moveUp();
        }
        else if(event->key() == Qt::Key_S){
            mira->moveDown();
        }
        else if(event->key() == Qt::Key_Space){
            // Obtener la lista de objetos debajo de la posición del objeto mira
            QList<QGraphicsItem*> items = scene->items(mira->pos());
            for(auto item : items){
                if(item != mira){
                    if(auto piedra = dynamic_cast<Piedra*>(item)){
                        // Reducir el contador de piedras y eliminar el objeto
                        scene->removeItem(piedra);
                        delete piedra;
                        npiedras.removeOne(piedra);
                        piedras--;
                        ui->cantidadPiedras->display(piedras);
                        puntosJugador++;
                        ui->puntosJugador->display(puntosJugador);
                        qreal a=mira->getPosX();
                        qreal b=mira->getPosY();
                        auto exp = new Explosion(a,b);
                        scene->addItem(exp);
                        exp->setPos(a,b);
                    }
                    else if(auto papel = dynamic_cast<Papel*>(item)){
                        // Reducir el contador de papeles y eliminar el objeto
                        scene->removeItem(papel);
                        delete papel;
                        npapeles.removeOne(papel);
                        papeles--;
                        ui->cantidadPapeles->display(papeles);
                        puntosJugador++;
                        ui->puntosJugador->display(puntosJugador);
                        qreal a=mira->getPosX();
                        qreal b=mira->getPosY();
                        auto exp = new Explosion(a,b);
                        scene->addItem(exp);
                        exp->setPos(a,b);
                    }
                    else if(auto tijera = dynamic_cast<Tijera*>(item)){
                        // Reducir el contador de tijeras y eliminar el objeto
                        scene->removeItem(tijera);
                        delete tijera;
                        ntijeras.removeOne(tijera);
                        tijeras--;
                        ui->cantidadTijeras->display(tijeras);
                        puntosJugador++;
                        ui->puntosJugador->display(puntosJugador);
                        qreal a=mira->getPosX();
                        qreal b=mira->getPosY();
                        auto exp = new Explosion(a,b);
                        scene->addItem(exp);
                        exp->setPos(a,b);
                    }
                }
            }
        }
    }
}



