#ifndef PIEDRA_H
#define PIEDRA_H

#include <QObject>
#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include <QTimer>

class Piedra : public QObject, public QGraphicsItem {
    Q_OBJECT
public:
    explicit Piedra(QObject *parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

public slots:
    void actualizarPersonaje();

private:
    QTimer *timer;
    QPixmap* stripe;
    qreal rowPixmap, colPixmap, width, height, posX, posY;
};

#endif // PIEDRA_H
