#ifndef HOLE_HORIZONTAL_H
#define HOLE_HORIZONTAL_H

#include <QWidget>
#include <QLabel>
#include <QTimer>

namespace Ui {
class hole_horizontal;
}

class hole_horizontal : public QWidget
{
    Q_OBJECT

public:
    explicit hole_horizontal(QWidget *parent = nullptr);
    ~hole_horizontal();

    void moveTo(QPoint geo);
    void display();
    void undisplay();


    void changeSize();
    void setWhite(int rate);

protected:
    QPixmap pix;
    QLabel *img = new QLabel(this);

private:
    Ui::hole_horizontal *ui;
    QTimer *displayTimer = new QTimer;
    QTimer *disappareTimer = new QTimer;
    int msec = 0;
};

#endif // HOLE_HORIZONTAL_H
