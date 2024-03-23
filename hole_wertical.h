#ifndef HOLE_WERTICAL_H
#define HOLE_WERTICAL_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
namespace Ui {
class hole_wertical;
}

class hole_wertical : public QWidget
{
    Q_OBJECT

public:
    explicit hole_wertical(QWidget *parent = nullptr);
    ~hole_wertical();

    void moveTo(QPoint geo);


    void display();
    void undisplay();

    void setWhite(int rate);

protected:
    QPixmap pix;
    QLabel *img = new QLabel(this);
private:
    Ui::hole_wertical *ui;
    QTimer *displayTimer = new QTimer;
    QTimer *disappareTimer = new QTimer;
    int msec = 0;
    bool displayFlag = false;
};

#endif // HOLE_WERTICAL_H
