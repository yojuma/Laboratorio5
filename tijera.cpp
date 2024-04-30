#include "tijera.h"

Tijera::Tijera(QObject *parent)
    : QObject{parent}
{
    rowPixmap = 0;
    colPixmap = 0;
    posX=0;
    posY=0;
    width = 96;
    height = 60;
    stripe = new QPixmap(":/tijera.png");
    timer = new QTimer;
    timer->start(200);

    connect(timer, &QTimer::timeout, this, &Tijera::actualizarEscena);
}

QRectF Tijera::boundingRect() const{
    return QRectF(0, 0, width, height);
}

void Tijera::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
     //QPixmap scaled = stripe->scaled(QSize(66.7,36.8));
     painter->drawPixmap(0,0, *stripe, colPixmap, rowPixmap, width, height);
     painter->setBrush(Qt::transparent);
     painter->drawRect(boundingRect());

     Q_UNUSED(option);
     Q_UNUSED(widget);
}

void Tijera::actualizarEscena(){
    update(0, 0, width, height);
    moveRight();
}

void Tijera::moveRight(){
    rowPixmap = 0;
    colPixmap += width;
    if(colPixmap >= 667){
        colPixmap = 0;
    }
    posX += 20;
    setPos(posX, posY);
}

void Tijera::moveLeft(){

}
