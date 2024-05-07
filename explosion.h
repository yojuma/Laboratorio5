#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <QTimer>

class Explosion : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Explosion(qreal, qreal);
    QRectF boundingRect() const;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
    void setInitialPosition(qreal, qreal);
    qreal getPosX();
    qreal getPosY();

public slots:
    void actualizar();

private:
    QTimer* timer;
    qreal posX, posY, rowPixmap, colPixmap, width, height;
    QPixmap* stripe;
};

#endif // EXPLOSION_H

