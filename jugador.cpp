#include "jugador.h"

Jugador::Jugador(QObject *parent)
    : QObject{parent}
{
    rowPixmap = 0;
    colPixmap = 0;
    posX = 600;
    posY = 350;
    width = 99.66;
    height = 99.66;
    stripe = new QPixmap(":/mira.png");
    timer = new QTimer;
    timer->start(200);

    connect(timer, &QTimer::timeout, this, &Jugador::actualizarPersonaje);
}

void Jugador::actualizarPersonaje(){
    update(0, 0, width, height);
}

QRectF Jugador::boundingRect() const{
    return QRectF(0, 0, width, height);
}

void Jugador::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget){
    QPixmap scaled = stripe->scaled(QSize(299/3,299/3));
    painter->drawPixmap(0, 0, scaled, colPixmap, rowPixmap, width, height);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Jugador::moveLeft(){
    posX -= 20;
    setPos(posX, posY);
}

void Jugador::moveRight(){
    posX += 20;
    setPos(posX, posY);
}

void Jugador::moveUp(){
    posY -= 20;
    setPos(posX, posY);
}

void Jugador::moveDown(){
    posY += 20;
    setPos(posX, posY);
}

qreal Jugador::getAlto(){
    return height;
}

qreal Jugador::getAncho(){
    return width;
}

qreal Jugador::getPosX(){
    return posX;
}

qreal Jugador::getPosY(){
    return posY;
}


