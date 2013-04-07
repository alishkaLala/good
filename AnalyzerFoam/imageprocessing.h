#ifndef IMAGEPROCESSING_H
#define IMAGEPROCESSING_H

#include <QThread>
#include <QTime>
#include <QMessageBox>
#include <QDebug>
#include <QDate>


#include <cv.h>
#include <highgui.h>

#include <iostream>


#include "canal_contur.h"
#include "configinformation.h"
#include "filewriteread.h"
class ImageProcessing : public QThread
{
  Q_OBJECT
  void run ();
public:
  explicit ImageProcessing(QObject *parent = 0);

  bool isRealyWork();
  int wishWindowsize;

signals:
  void imageIsReady( IplImage *img);
  void imageCalculateReady( IplImage *img);
  void infoIsReady(double count, double diametr,double *arr);
  void captureProp(int ,int ,int);

public slots:

  void working(bool);
  void getImage();
  void setCalculation(bool,bool writing = true);
  void setK1(double value);
  void setK2(double value);
  void setWindowSize(int value);
  void setEnabledResize(bool,int x1,int y1,int widthROI,int heigthROI);
  void setChoisedCpture(int value);
  void setTesting(bool value);
  void setDelay(int value);






private:
  //values

  bool realyWork;
  bool isWorking;
  bool calculateImage;
  bool enabledResize;
  bool testing;
  unsigned long int  kadrProssesd;
  int choisedCapture;
  double k1,k2;
  int width,heigth ;
  int captureWidth,captureHeight;
  CvCapture* capture;
  qint32 x1,y1,widthROI,heigthROI;
  int delay;
  int fps;

  FileWriteRead *file;
  QTime *time;

  bool checkCapture();

  int intervals[10];


};

#endif // IMAGEPROCESSING_H
