#include "hole_horizontal.h"
#include "ui_hole_horizontal.h"

hole_horizontal::hole_horizontal(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::hole_horizontal)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Tool|Qt::WindowStaysOnTopHint);
    this->setAttribute(Qt::WA_TranslucentBackground,true);


    img->setStyleSheet("background:transparent;");
    pix = QPixmap(":/new/prefix1/Horizontal.png");
    img->setPixmap(pix);

    connect(displayTimer,&QTimer::timeout,this,[=](){
        msec+=1;
        if(msec>250 && msec<1500)
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
}

hole_horizontal::~hole_horizontal()
{
    delete ui;
}
void hole_horizontal::moveTo(QPoint geo)
{
    this->move(geo);
}

void hole_horizontal::display()
{
    this->show();
    if(!displayTimer->isActive())
    {
        displayTimer->start(2);
    }

}

void hole_horizontal::undisplay()
{
    if(!displayTimer->isActive())
        displayTimer->start(2);
}

void hole_horizontal::setWhite(int rate)
{
    img->setPixmap(pix);
    this->layout()->addWidget(img);
}
