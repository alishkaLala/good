#ifndef IMAGEPROCESSING_H
#define IMAGEPROCESSING_H

#include <QThread>
#include <QMessageBox>
#include <QDebug>


#include <cv.h>
#include <highgui.h>

#include <iostream>


#include "canal_contur.h"
class ImageProcessing : public QThread
{
        Q_OBJECT
        void run ();
public:
        explicit ImageProcessing(QObject *parent = 0);

        bool isRealyWork();

signals:
        void imageIsReady( IplImage *img);
        void imageCalculateReady( IplImage *img);
        void infoIsReady(double count, double diametr);

public slots:

        void working(bool);
        void getImage();
        void setCalculation(bool);
        void setK1(double value);
        void setK2(double value);
        void setWindowSize(int value);
        void setEnabledResize(bool,int x1,int y1,int widthROI,int heigthROI);
        void setChoisedCpture(int value);




private:
        //values

        bool realyWork;
        bool isWorking;
        bool calculateImage;
        bool enabledResize;
        unsigned long int  kadrProssesd;
        int choisedCapture;
        double k1,k2;
        int width,heigth ;
        int captureWidth,captureHeight;
        CvCapture* capture;
        qint32 x1,y1,widthROI,heigthROI;
        int delay;


};

#endif // IMAGEPROCESSING_H
