#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include "hole_wertical.h"
#include "hole_horizontal.h"
#include <qDebug>
#include <QDesktopWidget>
#include <mydesktop.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int top = 0;
    int bottom =0;
    int left =0;
    int right = 0;



private:
    Ui::Widget *ui;
    QList <myDesktop> myDesktopList;
    QTimer *timer = new QTimer;
    QTimer *findWindowTimer = new QTimer;
    QTimer *exitTimer = new QTimer;


protected:
    // bool keyPressed = false;
    // int time = 0;
    // void keyPressEvent(QKeyEvent *event) override
    // {
    //     switch (event->key()) {
    //     case Qt::Key_Enter:
    //         qDebug()<<"pressing";
    //         keyPressed = true;
    //         if(!exitTimer->isActive())
    //         exitTimer->start(10);
    //         break;
    //     default:
    //         break;
    //     }
    // }



signals:
    void reachWindow(int windowNum,QPoint geo);
};




#endif // WIDGET_H
