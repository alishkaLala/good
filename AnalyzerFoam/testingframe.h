#ifndef TESTINGFRAME_H
#define TESTINGFRAME_H

#include <QWidget>

namespace Ui {
    class testingFrame;
}

class testingFrame : public QWidget
{
    Q_OBJECT

public:
    explicit testingFrame(QWidget *parent = 0);
    ~testingFrame();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::testingFrame *ui;
};

#endif // TESTINGFRAME_H
