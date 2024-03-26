#include "donate.h"
#include "ui_donate.h"

donate::donate(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::donate)
{
    ui->setupUi(this);
    this->setWindowTitle("WormHole");
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);

}

donate::~donate()
{
    delete ui;
}

void donate::on_pushButton_2_clicked()
{
    this->hide();
    emit no();
}


void donate::on_pushButton_clicked()
{
    this->hide();
    emit yes();
}

