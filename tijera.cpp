#include "tijera.h"

Tijera::Tijera(QObject *parent)
    : QObject{parent}
{
    rowPixmap = 0;
    colPixmap = 0;
    posX=10;
    posY=getPosY();
    width = 96;
    height = 60;
    direccion = true;
    stripe = new QPixmap(":/tijera.png");
    timer = new QTimer;
    timer->stop();
    connect(timer, SIGNAL(timeout()), this, SLOT(actualizarEscena()));
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
    if(direccion){
        moveRight();
    }else{
        moveLeft();
    }
    checkCollision();
    update(0, 0, width, height);
}

float Tijera::getPosX(){
    return posX;
}

float Tijera::getPosY(){
    return posY;
}

float Tijera::getWidth(){
    return width;
}

float Tijera::getHeight(){
    return height;
}

void Tijera::setPosY(int newY){
    posY=newY;
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
    rowPixmap = 195;
    colPixmap += width;
    if(colPixmap >= 667){
        colPixmap = 0;
    }
    posX -= 20;
    setPos(posX, posY);

}

void Tijera::checkCollision(){
    //qDebug()<<"posX: "<<getPosX();
    // colision con el borde izquierdo o el derecho
    if(getPosX() >= HORZLIM - getWidth()){
        direccion=false;
    }
    if(getPosX() < 0){
        direccion=true;
    }
}

void Tijera::on_pushButton_clicked(){
    timer->start(200);
}

