#ifndef MYDESKTOP_H
#define MYDESKTOP_H

#include <QObject>
#include "hole_wertical.h"
#include "hole_horizontal.h"
#include <qDebug>

class myDesktop
{
    // Q_OBJECT
public:
    explicit myDesktop();

    hole_wertical *my_hole_wertical = new hole_wertical;
    hole_horizontal *my_hole_horizontal = new hole_horizontal;

    QTimer *timer = new QTimer;

    int top;
    int bottom;
    int left;
    int right;
    int width;
    int height;

    void displayWerticalHole(float windowRate,bool leftFlag);
    void displayHorizontalHole(float windowRate,bool topFlag);


};

#endif // MYDESKTOP_H
