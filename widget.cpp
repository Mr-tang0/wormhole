#include "widget.h"
#include "ui_widget.h"
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Tool|Qt::WindowStaysOnTopHint);

    this->setAttribute(Qt::WA_TranslucentBackground,true);

    //添加屏幕

    connect(findWindowTimer,&QTimer::timeout,this,[=](){

        myDesktopList.clear();
        QDesktopWidget *desktop = QApplication::desktop();
        for (int i = 0; i < desktop->screenCount(); ++i)
        {
            myDesktop *desk = new myDesktop;

            QRect screenRect = desktop->screenGeometry(i);
            QPoint topLeftCorner = screenRect.topLeft();

            int width,height;
            width = screenRect.width();
            height = screenRect.height();

            desk->top = topLeftCorner.y();
            top = topLeftCorner.y()<top?topLeftCorner.y():top;

            desk->left = topLeftCorner.x();
            left = topLeftCorner.x()<left?topLeftCorner.x():left;

            desk->bottom = topLeftCorner.y()+height;
            bottom = topLeftCorner.y()+height>bottom?topLeftCorner.y()+height:bottom;

            desk->right = topLeftCorner.x()+width;
            right = topLeftCorner.x()+width>right?topLeftCorner.x()+width:right;

            desk->width = width;
            desk->height = height;

            if (i > 0) {
                QRect previousScreenRect = desktop->screenGeometry(0);
                QPoint relativePosition = topLeftCorner - previousScreenRect.topLeft();
                desk->top = relativePosition.y();
                desk->left = relativePosition.x();
                desk->bottom = relativePosition.y()+height;
                desk->right = relativePosition.x()+width;
            }

            myDesktopList.append(*desk);
        }
    });

    findWindowTimer->start(6000);



    connect(timer,&QTimer::timeout,this,[=](){
        i++;
        if(i >500)ui->label->setText("");
        QPoint screenPos = QCursor::pos();
        int x = screenPos.rx();
        int y = screenPos.ry();


        for (int i = 0 ; i<myDesktopList.length();i++)
        {
            // if(myDesktopList.length()==1)break;


            //判断在哪个屏幕
            if(x>myDesktopList[i].left && x<myDesktopList[i].right)
            {
                if(y>myDesktopList[i].top && y<myDesktopList[i].bottom)
                {
                    //判断屏幕边缘
                    //如果旁边没有屏幕，不显示

                    //左右
                    if(x- myDesktopList[i].left<50 && myDesktopList[i].left!=left)
                    {
                        float rate = float(y)/float(myDesktopList[i].height);

                        myDesktopList[i].displayWerticalHole(rate,true);
                    }
                    else if(myDesktopList[i].right-x <50 && myDesktopList[i].right!=right)
                    {
                        float rate = float(y)/float(myDesktopList[i].height);

                        myDesktopList[i].displayWerticalHole(rate,false);
                    }
                    //上下

                    if(y- myDesktopList[i].top<50 && myDesktopList[i].top!=top)
                    {
                        float rate = float(x-150)/float(myDesktopList[i].width);

                        myDesktopList[i].displayHorizontalHole(rate,true);
                    }
                    else if(myDesktopList[i].bottom-y <50 && myDesktopList[i].bottom!=bottom)
                    {
                        float rate = float(x-150)/float(myDesktopList[i].width);

                        myDesktopList[i].displayHorizontalHole(rate,false);
                    }
                }
            }
        }



    });

    timer->start(10);

    // connect(exitTimer,&QTimer::timeout,this,[=](){
    //     if(keyPressed){
    //         time +=10;
    //         qDebug()<<time;
    //         if(time>5000){
    //             qDebug()<<"quit";
    //             exitTimer->stop();
    //             qApp->quit();
    //         }
    //     }
    //     else{
    //         time = 0;
    //         exitTimer->stop();
    //     }
    // });



}

Widget::~Widget()
{

    delete ui;
}

