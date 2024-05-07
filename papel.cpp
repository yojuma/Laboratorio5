#include "papel.h"

Papel::Papel(QObject *parent)
   : QObject{parent}
{
    rowPixmap = 0;
    colPixmap = 0;
    posXtmp=20;
    posYtmp=20;
    width = 78;
    height = 90;
    direccion=true;
    stripe = new QPixmap(":/papel.png");
    timer = new QTimer;
    timer->stop();
    connect(timer, SIGNAL(timeout()), this, SLOT(actualizarEscena()));
}

QRectF Papel::boundingRect() const{
    return QRectF(0, 0, width, height);
}

void Papel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QPixmap scaled = stripe->scaled(QSize(640,100));
    painter->drawPixmap(0,0,scaled, colPixmap, rowPixmap, width, height);
    painter->setBrush(Qt::transparent);
    painter->drawRect(boundingRect());
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Papel::actualizarEscena(){
    move();
    checkCollision();
    update(0, 0, width, height);
}

void Papel::checkCollision(){
    qDebug()<<"posX: "<<getPosX();

    // colision con el borde superior o el inferior
    if(getPosY() >= VERTLIMIT - getHeight()){ //inferior
        posYtmp=-20;
    }
    else if(getPosY() <= 0){
       posYtmp=20;
    }
    else if(getPosX() >= HORZLIMIT - getHeight()){
        posXtmp=-20;
    }
    else if(getPosX() <= 0){
       posXtmp=20;
    }

}

void Papel::on_pushButton_clicked(){
    timer->start(200);
}

float Papel::getPosX(){
    return posX;
}

float Papel::getPosY(){
    return posY;
}

float Papel::getWidth(){
    return width;
}

float Papel::getHeight(){
    return height;
}

void Papel::setPosX(int newX){
    posX=newX;
}

void Papel::setPosY(int newY){
    posY=newY;
}

void Papel::move(){
    rowPixmap = 0;
    colPixmap += width;
    if(colPixmap >= 624){
        colPixmap = 0;
    }
    posX+=posXtmp;
    posY+=posYtmp;
    setPos(posX,posY);
}

