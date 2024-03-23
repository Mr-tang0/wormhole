#include "mydesktop.h"

myDesktop::myDesktop()
{

}

void myDesktop::displayWerticalHole(float windowRate,bool leftFlag)
{
    QPoint newPoint;
    if(leftFlag)
    {
        newPoint = QPoint(left-20,height*windowRate-120);
    }
    else
    {
        newPoint = QPoint(right-100,height*windowRate-120);
    }
    my_hole_wertical->moveTo(newPoint);
    my_hole_wertical->display();
}

void myDesktop::displayHorizontalHole(float windowRate,bool topFlag)
{
    QPoint newPoint;
    if(topFlag)
    {
        newPoint = QPoint(width*windowRate,top-50);
    }
    else
    {
        newPoint = QPoint(width*windowRate,bottom-100);
    }
    my_hole_horizontal->moveTo(newPoint);
    my_hole_horizontal->display();
}
