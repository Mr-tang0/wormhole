#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QFile>
#include <QDir>

namespace Ui {
class menu;
}

class menu : public QWidget
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();
    QString filePath = "";
    int choose = 0;

private slots:
    void on_pushButton_clicked();

private:
    Ui::menu *ui;
};

#endif // MENU_H
