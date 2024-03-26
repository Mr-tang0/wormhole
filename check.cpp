#include "check.h"
#include "ui_check.h"
#include "donate.h"

Check::Check(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Check)
{
    ui->setupUi(this);
    this->setWindowTitle("WormHole");
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);

}

Check::~Check()
{
    delete ui;
}

void Check::on_pushButton_clicked()
{
    donate *myDonate = new donate;
    myDonate->show();
    this->hide();
    connect(myDonate,&donate::yes,this,[=](){
        emit yes();
    });
    connect(myDonate,&donate::no,this,[=](){
        this->show();
    });
}


void Check::on_pushButton_2_clicked()
{
    emit exit();
}

