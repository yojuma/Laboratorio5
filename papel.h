#ifndef PAPEL_H
#define PAPEL_H

#include <QObject>
#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include <QTimer>

class Papel : public QObject, public QGraphicsItem {
    Q_OBJECT
public:
    explicit Papel(QObject *parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

public slots:
    void actualizarPersonaje();

private:
    QTimer *timer;
    QPixmap* stripe;
    qreal rowPixmap, colPixmap, width, height, posX, posY;
};

#endif // PAPEL_H
