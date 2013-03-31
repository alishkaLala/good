#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QTimer>
#include <QMessageBox>
#include <QEvent>

#include "filewriteread.h"
#include "infoframe.h"
#include "openglgraph.h"
#include "imageprocessing.h"
#include "testingframe.h"
#include <settingmainframes.h>
#include <settingcaptureframe.h>


#include <cv.h>
#include <highgui.h>

#include <algorithm>
#include <iostream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  void showEvent(QShowEvent *event);
  void closeEvent(QCloseEvent *event);
  explicit MainWindow(QWidget *parent = 0);
  FileWriteRead *tmp ;
  bool showingSettingCapture;
  ~MainWindow();
private slots:

  //signal getting :
  void imageGetting( IplImage *img);
  void infoGetting(double count,double diametr,double  *arr);

  //connect/disconnect image getting
  void captureStop(); //disable capture
  void hideCapture();
  void showCapture();
  void setSartStopImegeGetting(bool enabled);
  void captureStart();
  void calculateImagesStart();
  void calculateImageStop();
  void progressBarChange();


  //show frames
  void showAboutProgram();
  void showInfoFrame();
  void showSettingFrame();
  void showSettingCapture();
  void showOpenGLGraph();
  void showTestingFrame();

  //buttons (gui)
  void on_startCalculation_clicked();
  void on_buttonAnalizStart_clicked();
  void on_buttonAnalizStop_clicked();
  void on_buttonCaptureStart_clicked();

private:
  qint64 workingTime;
  qint64 workingTimeDelta;

  //windows
  InfoFrame *infoFrame;
  SettingMainFrames *settingMainFrames;
  SettingCaptureFrame *settingCaptureFrame;
  OpenglGraph *gr ;
  testingFrame *testFrame;

  ImageProcessing *worker; //working thread for capture
  Ui::MainWindow *ui;
  QList<QAction*>  menuCaptureArray;
  qint8 numberOfCapture;   // кількість  підключенних камер
  qint32 timeToWork;
  uchar* dataToDelete;


  // setting for working with capture
  /*    IplImage* resize;
        bool enabledResize;
        qint32 x1Resize,y1Resize;
        qint32 frameWidth,frameHight;
        qint32 frameWidthResize,frameHightResize;
        double coefficient;
        double coefficientResize;*/
  void readSettingCaprure(); /// void for worker

  // show image from resourses
  void showImage();
  bool showImageJpg;
  // functions for initialize
  void initialMenuCapture();
  void initialConnections();
  void initValues();
  void initPalette();
  void createWindows();
  qint8 findCapture();


  //aditional f.
  bool okToContinue(QString Msg);
  IplImage* QImageToIplImage(const QImage * qImage);
  QImage* IplImageToQImage(const IplImage * iplImage, uchar **data,
                           double mini, double maxi);
  void elemetShow();
  void elementHide();









};

#endif // MAINWINDOW_H
