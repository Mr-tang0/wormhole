#ifndef CHECK_H
#define CHECK_H

#include <QWidget>

namespace Ui {
class Check;
}

class Check : public QWidget
{
    Q_OBJECT

public:
    explicit Check(QWidget *parent = nullptr);
    ~Check();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Check *ui;
signals:
    void yes();
    void exit();
};

#endif // CHECK_H
