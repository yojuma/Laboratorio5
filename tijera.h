#ifndef TIJERA_H
#define TIJERA_H

#include <QObject>
#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include <QTimer>

class Tijera : public QObject, public QGraphicsItem {
    Q_OBJECT
public:
    explicit Tijera(QObject *parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void moveLeft();
    void moveRight();

public slots:
    void actualizarEscena();

private:
    QTimer *timer;
    QPixmap* stripe;
    qreal rowPixmap, colPixmap, width, height, posX, posY;
};

#endif // TIJERA_H
