#ifndef DONATE_H
#define DONATE_H

#include <QWidget>

namespace Ui {
class donate;
}

class donate : public QWidget
{
    Q_OBJECT

public:
    explicit donate(QWidget *parent = nullptr);
    ~donate();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::donate *ui;
signals:
    void yes();
    void no();
};

#endif // DONATE_H
