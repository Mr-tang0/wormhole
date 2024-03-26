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
    int i = 0;



private:
    Ui::Widget *ui;
    QList <myDesktop> myDesktopList;
    QTimer *timer = new QTimer;
    QTimer *findWindowTimer = new QTimer;
    QTimer *exitTimer = new QTimer;


protected:
    void CreateSystemTrayIcon();
    void initThis();
    bool checked = false;



signals:
    void reachWindow(int windowNum,QPoint geo);
};




#endif // WIDGET_H
