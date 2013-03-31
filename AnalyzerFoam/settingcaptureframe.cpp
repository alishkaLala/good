#include "settingcaptureframe.h"
#include "ui_settingcaptureframe.h"

SettingCaptureFrame *SettingCaptureFrame::obj ;  // static object : need for callback

SettingCaptureFrame::SettingCaptureFrame(ImageProcessing *worker, QWidget *parent) :
  QWidget(0),
  ui(new Ui::SettingCaptureFrame)
{
  ui->setupUi(this);
  this->worker = worker;  // thread for working with capture
  SettingCaptureFrame::obj = this; //   need  for right work callback
  this->father=parent;
  this->initialConnections();
}
SettingCaptureFrame::~SettingCaptureFrame()
{
  cvDestroyWindow(this->nameCaptureFrame.toAscii().constData());
  delete ui;
}
//Events
void SettingCaptureFrame::showEvent(QShowEvent *event){
  connect (this->worker,SIGNAL(imageIsReady( IplImage*)),this,SLOT(imageGetting( IplImage*)));
  this->worker->setCalculation (true);
  if(this->worker->isRealyWork ())
    {
      ui->pushButton->setEnabled (false);
    }
  else
    {
      ui->pushButton->setEnabled (true);
    }

  //this->worker->working (true);
  this->setPalette(configInformation::getpalleteAllWindows());
  this->setFont(configInformation::getfont());
  this->repaint();
  this->initialize();
  this->hideAllBoxes();
  this->ui->groupBox_3->setEnabled(true);
  this->enabledResize = configInformation::getEnabledResize ();
  this->startCalculateDistance = false;
  this->startResize=false;
  this->resizeX=0;
  this->resizeY=0;
  this->resizeW=0;
  this->resizeH=0;

}
void SettingCaptureFrame::closeEvent(QCloseEvent *event = NULL)
{
  this->father->show();
  disconnect (this->worker,SIGNAL(imageIsReady( IplImage*)),this,SLOT(imageGetting( IplImage*)));
  this->worker->setCalculation (false);
  this->worker->working (false);
  cvDestroyWindow(this->nameCaptureFrame.toAscii().constData());


}
//Initialize
void SettingCaptureFrame::initialize()
{
  this->initSetting(); //  порядок имеет значение  - сначала читаем настройки, потом заполняем гуи

  ui->lineEdit->setValidator(new QDoubleValidator(0.0,100.0,3,this));
  ui->lineEdit->setText(QString::number(this->distanceInMM));
  ui->pixels->setText(QString::number(this->distanceInPixels));
  ui->widthCaptureWindow->setSingleStep(10);
  this->nameCaptureFrame="Capture to work";
  cvNamedWindow(this->nameCaptureFrame.toAscii().constData(), CV_WINDOW_AUTOSIZE);
  this->showBoxes();
  this->startResize=false;
  this->startCalculateDistance=false;

}
void SettingCaptureFrame::initSetting()
{
  this->readSetting();
  ui->spinBox->setRange(configInformation::getperiodCaptureMinimum (),configInformation::getperiodCaptureMaximun ());
  qDebug ()<<configInformation::getperiodCaptureMinimum ()<<" period "<<configInformation::getperiodCaptureMaximun ();
  ui->widthCaptureWindow->setRange(configInformation::getSizeWindowCaptureMinimum (),configInformation::getSizeWindowCaptureMaximum ());
  ui->widthCaptureWindow->setValue(configInformation::getSizeWindowCapture());
  ui->spinBox->setValue(configInformation::getperiodCapture());
}
void SettingCaptureFrame::initialConnections()
{

  connect(ui->lineEdit,SIGNAL(textEdited(QString)),this,SLOT(validMmAndSet()));
  connect(ui->lineEdit,SIGNAL(cursorPositionChanged(int,int)),this,SLOT(toolTipMm()));
  connect(ui->doubleSpinBox,SIGNAL(valueChanged(double)), this->worker,SLOT(setK1(double)));
  connect(ui->doubleSpinBox_2,SIGNAL(valueChanged(double)), this->worker,SLOT(setK2(double)));
  connect(ui->widthCaptureWindow,SIGNAL(valueChanged(int)), this->worker,SLOT(setWindowSize(int)));
  cvSetMouseCallback( this->nameCaptureFrame.toAscii().constData(),myMouseCallback, (void*)this->frame);
  connect (this,SIGNAL(resizing(bool,int,int,int,int)),this->worker,SLOT(setEnabledResize(bool,int,int,int,int)));
  connect(ui->pushButton,SIGNAL(clicked()),this->worker,SLOT(getImage()));//menu capture Frame
}

//Callback to work with mouse&capture frame
void SettingCaptureFrame::myMouseCallback( int event, int x, int y, int flags, void* param)
{
  SettingCaptureFrame::obj->myMouseCallbackDelegated(event,x,y,flags,param);

}
void SettingCaptureFrame::myMouseCallbackDelegated( int event, int x, int y, int flags, void* param)
{
  IplImage* img = (IplImage*) param;
  switch( event )
    {

  case CV_EVENT_LBUTTONDOWN:
      if (this->startResize)
        {
          qDebug ()<<"resize" <<x <<" "<<y;
          this->X1 = x;
          this->Y1 = y;
          ui->labelX1->setText("x1= " + QString::number(x));
          ui->labelY1->setText("y1= " + QString::number(y));
        }
      if ( this->startCalculateDistance)
        {
          qDebug ()<<"distance"<<x<<"  "<<y;
          this->x1=x; ui->labelX1->setText("x2= " + QString::number(x));
          this->y1=y; ui->labelY1->setText("y2= " + QString::number(y));
        }
      break;

    case CV_EVENT_RBUTTONDOWN:
      if (this->startResize)
        {
          this->X2 = x;
          this->Y2 = y;
          ui->labelX2->setText("x1= " + QString::number(x));
          ui->labelY2->setText("y1= " + QString::number(y));
          this->enabledResize = true;
          this->startResize=false;
          this->hideAllBoxes();
          this->ui->groupBox_2->setEnabled(true);
          emit resizing(true, this->X1,this->Y1,this->X2,this->Y2);
          resizeX= this->X1;
          resizeY= this->Y1;
          resizeW= qAbs(this->X2- this->X1);
          resizeH=qAbs(this->Y2-this->Y1);
          resizeEnabled= true;

        }



      if ( this->startCalculateDistance)
        {

          this->x2=x; ui->labelX2->setText("x2= " + QString::number(x));
          this->y2=y; ui->labelY2->setText("y2= " + QString::number(y));
          this->calculateDistanceInPixels();
          this->ui->groupBox_4->setVisible(true);

        }


      break;
    case CV_EVENT_MOUSEMOVE:
      QToolTip::showText(QCursor::pos(),
                         tr(" x= ")+ QString::number(x) +
                         tr(" y= ")+ QString::number(y) );



      break;



    }

}
void SettingCaptureFrame::imageGetting(IplImage *img)//slot for geting image
{
  this->frame = img;
  cvShowImage(this->nameCaptureFrame.toAscii().constData(),this->frame);
  cvSetMouseCallback( this->nameCaptureFrame.toAscii().constData(),myMouseCallback, (void*)this->frame);






}

// Setting read & write ini
void SettingCaptureFrame::readSetting()
{


  this->distanceInMM=configInformation::getdistanceInMm();
  this->distanceInPixels=configInformation::getdistanceInPixels();


}
void SettingCaptureFrame::writeSetting()
{
  configInformation::setSizeWindowCapture(ui->widthCaptureWindow->value());
  configInformation::setperiodCapture(ui->spinBox->value());
  configInformation::setdistanceInMm(this->distanceInMM);
  configInformation::setdistanceInPixels(this->distanceInPixels);
  configInformation::setX1ResizeCoord(this->resizeX,resizeY);
  configInformation::setEnabledResize (this->resizeEnabled);
  configInformation::setframeWidthResizeAndframeHightResize (this->resizeW,this->resizeH);
  configInformation::setK1K2 (this->ui->doubleSpinBox->value (),this->ui->doubleSpinBox_2->value ());
  configInformation::writeToFile();


}

// buttons : Apply-Cansel -def
void SettingCaptureFrame::on_SettingApply_clicked()
{
  if (ui->lineEdit->text().trimmed()=="")
    if (QMessageBox::Yes == QMessageBox::warning(this,tr("Кількість міліметрів  не визначена"),
                                                 tr("Застосувати раніше встановлені налаштування?"),
                                                 QMessageBox::Yes,QMessageBox::No)){
      ui->lineEdit->setText(QString::number(configInformation::getdistanceInMm()));
    }
    else {
      QMessageBox::information(this,tr (""),tr("Визначте їх"), QMessageBox::Ok);
      return;
    }
  this->writeSetting();
  this->close();


}
void SettingCaptureFrame::on_SettingCansel_clicked()
{
  this->close();
}
void SettingCaptureFrame::on_SettingStandart_clicked()
{

}

//buttons:
void SettingCaptureFrame::on_buttonRestartTrySet_clicked()//button function - Start setting
{
  this->restartTrySet ();
}
void SettingCaptureFrame::on_buttonSizeApply_clicked() // button function - Apply Size of frame capture
{
  this->sizeApply ();
}
void SettingCaptureFrame::on_buttonSetROI_clicked()//button function - start set roi
{
  this->worker->setEnabledResize (false,0,0,0,0);
  this->setROI ();


}
void SettingCaptureFrame::on_buttonSetDistance_clicked()
{
  this->setDistance();
}

// function that calls on batton click
//... gui enable/disable
void SettingCaptureFrame::hideBoxes()//disable all boxes and set labels
{
  ui->groupBox->setEnabled(false);
  ui->groupBox_2->setEnabled(false);
  ui->groupBox_3->setEnabled(false);
  ui->labelX2->setText("x2= " );
  ui->labelY2->setText("y2= " );
  ui->labelX1->setText("x1= " );
  ui->labelY1->setText("y1= " );
  this->ui->groupBox_6->setEnabled(true);
}
void SettingCaptureFrame::showBoxes() //enabled all boxes
{
  ui->groupBox->setEnabled(true);
  ui->groupBox_2->setEnabled(true);
  ui->groupBox_3->setEnabled(true);
  ui->groupBox_4->setEnabled(true);
  ui->groupBox_6->setEnabled(false);
}
void SettingCaptureFrame::hideAllBoxes()// disable all group box
{
  ui->groupBox->setEnabled(false);
  ui->groupBox_2->setEnabled(false);
  ui->groupBox_3->setEnabled(false);
  ui->groupBox_6->setEnabled(false);
}
//..else
void SettingCaptureFrame::restartTrySet () // function to reset setting of resizing
{
  this->hideAllBoxes();
  this->ui->groupBox_3->setEnabled(true);
  this->enabledResize= false;
  emit resizing(false, 0,0,0,0);
}
void SettingCaptureFrame::sizeApply () // button function - set size Window (jusn next step)
{
  ui->groupBox_3->setEnabled(false);
  ui->groupBox->setEnabled(true);

}
void SettingCaptureFrame::setROI()// button function - start set roi
{
  this->hideBoxes();
  this->enabledResize=false;
  this->startResize= true;
  emit resizing(false, 0,0,0,0);
}
void SettingCaptureFrame::setDistance()
{
  this->hideBoxes();
  this->clearCoords();
  this->startCalculateDistance = true;
}
//aditional
void SettingCaptureFrame::toolTipMm()//tool tip of size mm(line edit)
{
  QToolTip::showText(ui->lineEdit->mapToGlobal(QPoint()), tr("1..100"));
}
void SettingCaptureFrame::validMmAndSet()  //valid-function for float(line edit)
{
  if (!ui->lineEdit->hasAcceptableInput())
    {
      ui->lineEdit->clear();
      ui->lineEdit->setFocus();
    }
  else
    {
      this->distanceInMM = ui->lineEdit->text().toDouble();
    }

}
void SettingCaptureFrame::clearCoords()
{
  this->x1=0;
  this->x2=0;
  this->y1=0;
  this->y2=0;
}
bool SettingCaptureFrame::calculateDistanceInPixels()
{
  qint32 tmpDist =std::abs(
        std::sqrt(
          std::pow(this->x2-this->x1,2)+
          std::pow(this->y2-this->y1,2)
          )
        );
  if (tmpDist>0)
    {
      distanceInPixels=tmpDist;
      ui->pixels->setText(QString::number(this->distanceInPixels));
      this->startCalculateDistance= false;
      return true;
    }
  else {
    return false;
  }


}
void SettingCaptureFrame::workerStart ()
{

}


void SettingCaptureFrame::on_pushButton_clicked()
{
  ui->pushButton->setEnabled (false);
}
void SettingCaptureFrame::on_widthCaptureWindow_valueChanged(int )
{
  this->worker->setEnabledResize (false,0,0,0,0);
}

void SettingCaptureFrame::on_pushButton_2_clicked()
{
  worker->setEnabledResize (false,0,0,0,0);
  this->enabledResize= false;
}
