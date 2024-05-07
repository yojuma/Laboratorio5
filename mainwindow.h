#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <piedra.h>
#include <papel.h>
#include <tijera.h>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    bool collidesWithObjects(qreal x, qreal y);
    void actualizarColision();
    int tijeras=0;
    int piedras=0;
    int papeles=0;
    int puntosPapel=0;
    int puntosPiedra=0;
    int puntosTijera=0;
    ~MainWindow();

private slots:
    void on_tijera_clicked();
    void on_piedra_clicked();
    void on_papel_clicked();
    void on_IniciarConJugador_clicked();

private:

    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    QVector<Piedra*> npiedras;
    QVector<Papel*> npapeles;
    QVector<Tijera*> ntijeras;
    QTimer* timer;
    Piedra* piedra;
    Papel* papel;
    Tijera* tijera;
};
#endif // MAINWINDOW_H
