#ifndef TESTINGFRAME_H
#define TESTINGFRAME_H

#include <QWidget>
#include <QEvent>
#include <QTime>
#include <QDebug>

#include "imageprocessing.h"

namespace Ui {
class testingFrame;
}

class testingFrame : public QWidget
{
        Q_OBJECT

public:
        explicit testingFrame(ImageProcessing *worker,QWidget *parent = 0);
        void setNumberCapture(int value);

        ~testingFrame();
 public slots:
         void setChoisedCapture(int value);
protected:
        void showEvent(QShowEvent *event);
        void closeEvent(QCloseEvent *event);


private:
        qint16 numberCaptures;
        qint16 choisedCapture;
        Ui::testingFrame *ui;
        QWidget  *father;
        ImageProcessing *worker;
        uchar* dataToDelete;
        QImage* IplImageToQImage(const IplImage * iplImage, uchar **data,
                                 double mini, double maxi);
        int w,h,fps; //capture width,heigth,fps
        int timedelta,time1,time2;
private slots:
        void imageGetting( IplImage *img);
        void on_pushButton_clicked();
        void setCaptureProp(int,int,int);
};

#endif // TESTINGFRAME_H
