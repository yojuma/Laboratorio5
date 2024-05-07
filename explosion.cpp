#include "explosion.h"

Explosion::Explosion(qreal x, qreal y){
    posX = x;
    posY = y;
    rowPixmap = 0;
    colPixmap = 0;
    width = 130;
    height = 130;
    stripe = new QPixmap(":/explosion.png");
    timer = new QTimer;
    timer->start(120);

    connect(timer, &QTimer::timeout, this, &Explosion::actualizar);
}

void Explosion::actualizar(){
    colPixmap += width;
    if(colPixmap >= 650){
        colPixmap = 0;
        rowPixmap += height;
        if(rowPixmap >= 650){
            //detenga la animacion de la explosion
            timer->stop();
        }
    }

    update(0, 0, width, height);
}

QRectF Explosion::boundingRect() const{
    return QRectF(0, 0, width, height);
}

void Explosion::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget){
    painter->drawPixmap(0, 0, *stripe, colPixmap, rowPixmap, width, height);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Explosion::setInitialPosition(qreal a, qreal b){
    posX = a;
    posY = b;
    setPos(posX, posY);
}

qreal Explosion::getPosX(){
    return posX;
}
qreal Explosion::getPosY(){
    return posY;
}

