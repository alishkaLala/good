#ifndef SETTINGCAPTUREFRAME_H
#define SETTINGCAPTUREFRAME_H

#include <QWidget>
#include <QTimer>
#include <QDoubleValidator>
#include <QToolTip>
#include <QMessageBox>
#include <QCloseEvent>
#include <QApplication>
#include <QDebug>


#include <iostream>
#include<cmath>

#include <cv.h>
#include <highgui.h>


#include <configinformation.h>
#include <imageprocessing.h>

namespace Ui {
class SettingCaptureFrame;
}

class SettingCaptureFrame : public QWidget
{
  Q_OBJECT
  static SettingCaptureFrame *obj;
public:
  explicit SettingCaptureFrame(ImageProcessing *worker, QWidget *parent = 0);
  ~SettingCaptureFrame();
  void showEvent(QShowEvent *event);
  void closeEvent(QCloseEvent *event);

signals:
  void resizing(bool value, int x1, int y1, int x2, int y2);
  void needStart();

private:
  // values:
  Ui::SettingCaptureFrame *ui;
  QWidget  *father;
  ImageProcessing *worker;
  QString nameCaptureFrame;
  bool startResize;
  bool startCalculateDistance;
  bool enabledResize;
  IplImage* frame;
  qint32 distanceInPixels;
  double distanceInMM;
  qint32 x1,y1,x2,y2;
  qint32 X1,Y1;
  qint32 X2,Y2;
  qint32 resizeX,resizeY,resizeW,resizeH;
  bool resizeEnabled;


  //Functions:

  static void myMouseCallback( int event, int x, int y, int flags, void* param);
  void myMouseCallbackDelegated( int event, int x, int y, int flags, void* param);

  //init
  void initialize();
  void initSetting();
  void initialConnections();
  //work with ini
  void readSetting();
  void writeSetting();


  // function to call:
  //gui
  void hideBoxes();
  void hideAllBoxes();
  void showBoxes();
  //else
  void setROI();
  void setDistance();
  void restartTrySet();
  void sizeApply();
  //aditional
  void clearCoords();
  bool checkCoords();
  bool calculateDistanceInPixels();

private slots:
  void imageGetting(IplImage *img);
  // buttons: Apply - cans- def
  void on_SettingCansel_clicked();
  void on_SettingStandart_clicked();
  void on_SettingApply_clicked();
  // buttoms slots
  void on_buttonRestartTrySet_clicked();
  void on_buttonSizeApply_clicked();
  void on_buttonSetROI_clicked();
  void on_buttonSetDistance_clicked();
  //aditional
  void toolTipMm();
  void validMmAndSet();
  void workerStart();



  void on_pushButton_clicked();
  void on_widthCaptureWindow_valueChanged(int );
  void on_pushButton_2_clicked();
};

#endif // SETTINGCAPTUREFRAME_H
