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
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:

    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    QTimer* timer;
    Piedra* piedra;
    Papel* papel;
    Tijera* tijera;
};
#endif // MAINWINDOW_H
