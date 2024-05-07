#ifndef TIJERA_H
#define TIJERA_H

#include <QObject>
#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include <QTimer>
#include <QDebug>

const float HORZLIM = 1200;

class Tijera : public QObject, public QGraphicsItem {
    Q_OBJECT
public:
    explicit Tijera(QObject *parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void moveLeft();
    void moveRight();
    void checkCollision();
    float getPosX();
    float getPosY();
    float getWidth();
    float getHeight();
    bool direccion;
    void setPosY(int newY);

public slots:
    void actualizarEscena();
    void on_pushButton_clicked();

private:
    QTimer *timer;
    QPixmap* stripe;
    qreal rowPixmap, colPixmap, width, height, posX, posY;
};

#endif // TIJERA_H
