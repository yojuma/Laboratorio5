#include "papel.h"

Papel::Papel(QObject *parent)
   : QObject{parent}
{
    rowPixmap = 0;
    colPixmap = 0;
    posX=0;
    posY=0;
    width = 600;
    height = 500;
    stripe = new QPixmap(":/papel.png");
    timer = new QTimer;
    //timer->start(200);

    connect(timer, &QTimer::timeout, this, &Papel::actualizarPersonaje);
}

QRectF Papel::boundingRect() const{
    return QRectF(0, 0, width, height);
}

void Papel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    //QPixmap scaled = stripe->scaled(QSize(254,320));
    painter->drawPixmap(0,0, *stripe, colPixmap, rowPixmap, width, height);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Papel::actualizarPersonaje(){
    update(0, 0, width, height);
}
