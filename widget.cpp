#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QProcess>
#include <QDir>
#include "check.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Tool);
    CreateSystemTrayIcon();
    setWindowTitle("WormHole");


    QProcess process;
    process.setReadChannel(QProcess::StandardOutput);
    process.setProcessChannelMode(QProcess::MergedChannels);
    process.start("wmic CPU get ProcessorID");
    process.waitForFinished();
    QString result = process.readAllStandardOutput();
    process.close();
    result.remove(" ");
    result.remove("ProcessorId");
    result.remove("\r");
    result.remove("\n");


    QString filePath = QCoreApplication::applicationDirPath()+QDir::separator()+"res/user.user";
    QFile file(filePath);
    QString content;
    if(file.open(QIODevice::ReadOnly))
    {
        content = QString::fromUtf8(file.readAll());
        file.close();
    }
    qDebug()<<result<<content.left(16)<<content;

    if(content.left(16) == result){
        initThis();
    }
    else{
        Check *check = new Check;
        check->show();
        connect(check,&Check::yes,this,[=](){
            QString filePath = QCoreApplication::applicationDirPath()+QDir::separator()+"res/user.user";
            QFile file(filePath);
            file.open(QIODevice::WriteOnly);
            char *temp = (result+"1").toLatin1().data();
            file.write(temp);
            file.close();
            initThis();

        });
        connect(check,&Check::exit,this,[=](){
            QApplication::exit(0);
        });

    }



}

Widget::~Widget()
{

    delete ui;
}

void Widget::initThis()
{
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Tool|Qt::WindowStaysOnTopHint);
    this->setAttribute(Qt::WA_TranslucentBackground,true);
    this->show();
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
        if(i >500)
        {
            this->hide();
            i=0;
        }
        QPoint screenPos = QCursor::pos();
        int x = screenPos.rx();
        int y = screenPos.ry();
        // qDebug()<<screenPos;

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
                    // //上下

                    // if(y- myDesktopList[i].top<50 && myDesktopList[i].top!=top)
                    // {
                    //     float rate = float(x-150)/float(myDesktopList[i].width);

                    //     myDesktopList[i].displayHorizontalHole(rate,true);
                    // }
                    // else if(myDesktopList[i].bottom-y <50 && myDesktopList[i].bottom!=bottom)
                    // {
                    //     float rate = float(x-150)/float(myDesktopList[i].width);

                    //     myDesktopList[i].displayHorizontalHole(rate,false);
                    // }
                }
            }
        }



    });

    timer->start(10);

}

void Widget::CreateSystemTrayIcon()
{
    QAction* showAction = new QAction(QStringLiteral("状态"));//项1
    QAction* setAction = new QAction(QStringLiteral("菜单"));//项2
    QAction* exitAction = new QAction(QStringLiteral("退出"));//项3
    //项1的点击槽函数
    connect(showAction, &QAction::triggered, this, [=]()
    {
        this->show();
    });
    //项2的点击槽函数
    connect(setAction, &QAction::triggered, this, [=]()
    {
        Menu->show();
    });

    connect(exitAction , &QAction::triggered, this, [=]()
    {
        qDebug()<<"exit";
        QApplication::exit(0);
    });

    //初始化菜单并添加项
    QMenu* trayMenu = new QMenu(this);//菜单
    trayMenu->addAction(showAction);
    trayMenu->addAction(setAction );
    trayMenu->addAction(exitAction );


    QSystemTrayIcon* trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon(":/new/prefix1/res/icon.ico")); //设置托盘图标
    trayIcon->setContextMenu(trayMenu); //设置菜单
    trayIcon->show();
}

