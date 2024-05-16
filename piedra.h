#ifndef PIEDRA_H
#define PIEDRA_H

#include <QObject>
#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include <QTimer>
#include <QDebug>

const float VERTLIM = 700;

class Piedra : public QObject, public QGraphicsItem {
    Q_OBJECT
public:
    explicit Piedra(QObject *parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void moveUp();
    void moveDown();
    void checkCollision();
    float getPosX();
    float getPosY();
    float getWidth();
    float getHeight();
    bool direccion;
    void setPosX(int newX);
    void setPosY(int newY);

public slots:
    void actualizarEscena();
    void on_pushButton_clicked();
private:
    QTimer *timer;
    QPixmap* stripe;
    qreal rowPixmap, colPixmap, width, height, posX, posY;
};

#endif // PIEDRA_H
