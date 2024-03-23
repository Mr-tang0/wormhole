#include "hole_wertical.h"
#include "ui_hole_wertical.h"
#include <QDebug>
hole_wertical::hole_wertical(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::hole_wertical)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Tool|Qt::WindowStaysOnTopHint);
    this->setAttribute(Qt::WA_TranslucentBackground,true);




    img->setStyleSheet("background:transparent;");
    pix = QPixmap(":/new/prefix1/Wertical.png");
    img->setPixmap(pix);
    this->layout()->addWidget(img);

    connect(displayTimer,&QTimer::timeout,this,[=](){
        msec+=1;
        if(msec>500 && msec<1500)
        {
            double rate =(1499-msec)/1000.0;
            setWindowOpacity(rate);
        }
        else if(msec>1500)
        {
            msec = 0;
            this->hide();
            displayTimer->stop();
        }
    });

    connect(displayTimer,&QTimer::timeout,this,[=](){
        msec+=1;
        displayFlag = true;
        if(msec>250 && msec<500)
        {
            double rate =(499-msec)/500.0;


            setWindowOpacity(rate);
        }
        else if(msec>500)
        {
            msec = 0;
            this->hide();
            displayFlag = false;
            displayTimer->stop();
        }
    });

}

hole_wertical::~hole_wertical()
{
    delete ui;
}

void hole_wertical::moveTo(QPoint geo)
{
    this->move(geo);
}

void hole_wertical::display()
{
    this->show();
    if(!displayTimer->isActive())
    {
        displayTimer->start(2);
    }

}

void hole_wertical::undisplay()
{
    if(!displayTimer->isActive())
    displayTimer->start(2);
}
