#include "menu.h"
#include "ui_menu.h"
#include<QDebug>

menu::menu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::menu)
{
    ui->setupUi(this);

    QString filePath = QCoreApplication::applicationDirPath()+QDir::separator()+"res/user.user";
    QFile file(filePath);
    file.open(QIODevice::ReadOnly);
    QString content =file.readAll();
    file.close();

    choose = content.right(1).toInt();
    switch (choose) {
    case 1:
        filePath = ":/new/prefix1/res/Wertical.png";
        ui->choose_1->setChecked(true);

        break;
    case 2:
        filePath = "";
        ui->choose_5->setChecked(true);
        break;
    case 3:
        filePath = "";
        ui->choose_6->setChecked(true);
        break;
    case 4:
        filePath = "";
        ui->choose_7->setChecked(true);
        break;
    default:
        break;
    }
    connect(ui->buttonGroup,&QButtonGroup::idReleased,this,[=](int i){
        if(i==-5) i = -1;
        choose = i;
        qDebug()<<i;
    });
}

menu::~menu()
{
    delete ui;
}

void menu::on_pushButton_clicked()
{
    QString filePath = QCoreApplication::applicationDirPath()+QDir::separator()+"res/user.user";
    QFile file(filePath);
    file.open(QIODevice::ReadOnly);
    QString content =file.readAll();
    file.close();

    file.open(QIODevice::WriteOnly);


    char *temp = (content.left(16)+QString::number(choose)).toLatin1().data();
    file.write(temp);




}

