#ifndef PAPEL_H
#define PAPEL_H

#include <QObject>
#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include <QTimer>
#include <QDebug>

const float HORZLIMIT = 1200;
const float VERTLIMIT = 700;

class Papel : public QObject, public QGraphicsItem {
    Q_OBJECT
public:
    explicit Papel(QObject *parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool direccion;
    void checkCollision();
    float getPosX();
    float getPosY();
    float getWidth();
    float getHeight();
    void setPosX(int newX);
    void setPosY(int newY);
    void move();
    void moveDown1();
    void moveDown2();
    void moveUp1();
    void moveUp2();
    int getColisiones();
    int colisiones=0;

public slots:
    void actualizarEscena();
    void on_pushButton_clicked();

private:
    QTimer *timer;
    QPixmap* stripe;
    qreal rowPixmap, colPixmap, width, height, posX, posY,posXtmp, posYtmp;
};

#endif // PAPEL_H
