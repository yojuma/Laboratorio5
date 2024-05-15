#ifndef JUGADOR_H
#define JUGADOR_H

#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <QTimer>


class Jugador : public QObject, public QGraphicsItem{
    Q_OBJECT
public:
    explicit Jugador(QObject *parent = nullptr);
    QRectF boundingRect() const override;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*)override;
    void setInitialPosition(qreal, qreal);
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
    qreal getAncho();
    qreal getAlto();
    qreal getPosX();
    qreal getPosY();

public slots:
    void actualizarPersonaje();
private:
    QTimer* timer;
    qreal posX, posY, rowPixmap, colPixmap, width, height;
    QPixmap* stripe;
};

#endif // JUGADOR_H
