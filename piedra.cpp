#include "piedra.h"

Piedra::Piedra(QObject *parent)
    : QObject{parent}
{
     rowPixmap = 0;
     colPixmap = 0;
     posY=600;
     width = 93;
     height = 92;
     direccion = true;
     stripe = new QPixmap(":/piedra.png");
     timer = new QTimer;
     timer->stop();
     connect(timer, SIGNAL(timeout()), this, SLOT(actualizarEscena()));
}

QRectF Piedra::boundingRect() const{
    return QRectF(0, 0, width, height);
}

void Piedra::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
     //QPixmap scaled = stripe->scaled(QSize(254,320));
     painter->drawPixmap(0,0, *stripe, colPixmap, rowPixmap, width, height);
     painter->setBrush(Qt::transparent);
     painter->drawRect(boundingRect());
     Q_UNUSED(option);
     Q_UNUSED(widget);
}
void Piedra::actualizarEscena(){
    if(direccion){
        moveDown();
    }else{
        moveUp();
    }
    checkCollision();
    update(0, 0, width, height);
}

float Piedra::getPosX(){
    return posX;
}

float Piedra::getPosY(){
    return posY;
}

float Piedra::getWidth(){
    return width;
}

float Piedra::getHeight(){
    return height;
}

void Piedra::setPosX(int newX){
    posX=newX;
}

void Piedra::setPosY(int newY){
    posY=newY;
}


void Piedra::moveDown(){
    rowPixmap = 0;
    colPixmap += width;
    if(colPixmap >= 372){
        colPixmap = 0;
    }
    posY += 20;
    setPos(posX, posY);

}

void Piedra::moveUp(){
    rowPixmap = 0;
    colPixmap += width;
    if(colPixmap >= 372){
        colPixmap = 0;
    }
    posY -= 20;
    setPos(posX, posY);

}

void Piedra::checkCollision(){
    //qDebug()<<"posX: "<<getPosX();
    // colision con el borde superior o el inferior
    if(getPosY() >= VERTLIM - getHeight()){
        direccion=false;
    }
    if(getPosY() < 0){
        direccion=true;
    }
}

void Piedra::on_pushButton_clicked(){
    timer->start(200);
}
