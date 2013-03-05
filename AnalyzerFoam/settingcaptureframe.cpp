#include "settingcaptureframe.h"
#include "ui_settingcaptureframe.h"




SettingCaptureFrame *SettingCaptureFrame::obj ;

SettingCaptureFrame::SettingCaptureFrame(ImageProcessing *worker, QWidget *parent) :
        QWidget(0),
        ui(new Ui::SettingCaptureFrame)
{
        ui->setupUi(this);
        this->worker = worker;
        SettingCaptureFrame::obj = this; //   need  for right work callback
        this->father=parent;
        this->initialConnections();
}

//Events

void SettingCaptureFrame::showEvent(QShowEvent *event){
        connect (this->worker,SIGNAL(imageIsReady( IplImage*)),this,SLOT(imageGetting( IplImage*)));
        this->worker->working (true);
        this->worker->setCalculation (true);
        connect(this->worker,SIGNAL(imageCalculateReady(IplImage*)),this,SLOT(imageCalculatingGetting(IplImage*)));
        this->setPalette(configInformation::getpalleteAllWindows());
        this->setFont(configInformation::getfont());
        this->repaint();
        this->initialize();
        this->hideAllBoxes();
        this->ui->groupBox_3->setEnabled(true);
        this->enabledResize = false;
        this->startCalculateDistance = false;
        this->startResize=false;



}
void SettingCaptureFrame::hideAllBoxes(){
        ui->groupBox->setEnabled(false);
        ui->groupBox_2->setEnabled(false);
        ui->groupBox_3->setEnabled(false);
        //ui->groupBox_4->setEnabled(false);
        //ui->groupBox_5->setEnabled(false);
        ui->groupBox_6->setEnabled(false);
}
void SettingCaptureFrame::closeEvent(QCloseEvent *event = NULL)
{
        this->father->show();
        disconnect (this->worker,SIGNAL(imageIsReady( IplImage*)),this,SLOT(imageGetting( IplImage*)));
        disconnect(this->worker,SIGNAL(imageCalculateReady(IplImage*)),this,SLOT(imageCalculatingGetting(IplImage*)));
        this->worker->setCalculation (false);
        this->stopWork();


}
void SettingCaptureFrame::stopWork()
{
        cvDestroyWindow(this->nameCaptureFrame.toAscii().constData());
}


//Initialize
void SettingCaptureFrame::initialize()
{
        this->initSetting();

        ui->lineEdit->setValidator(new QDoubleValidator(0.0,100.0,3,this));
        ui->lineEdit->setText(QString::number(this->distanceInMM));
        ui->pixels->setText(QString::number(this->distanceInPixels));
        ui->widthCaptureWindow->setSingleStep(10);
        this->nameCaptureFrame="Capture to work";
        this->timerPeriod=40;
        cvNamedWindow(this->nameCaptureFrame.toAscii().constData(), CV_WINDOW_AUTOSIZE);
        this->showBoxes();
        this->startResize=false;
        this->startCalculateDistance=false;

}
void SettingCaptureFrame::initSetting()
{
        this->readSetting();
        ui->spinBox->setRange(10,100);
        ui->widthCaptureWindow->setRange(300,1000);
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
        connect(ui->widthCaptureWindow,SIGNAL(valueChanged(int)),this,SLOT(calculateCaptureSizeFrame(int)))  ;
        cvSetMouseCallback( this->nameCaptureFrame.toAscii().constData(),myMouseCallback, (void*)this->frame);
        connect(this,SLOT(hide()),this,SLOT(stopWork()));
        connect (this,SIGNAL(resizing(bool,int,int,int,int)),this->worker,SLOT(setEnabledResize(bool,int,int,int,int)));

}
void  SettingCaptureFrame::imageCalculatingGetting (IplImage *img)
{
        cvNamedWindow("calculation image", CV_WINDOW_AUTOSIZE);
        cvShowImage("calculation image",img);


}

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


//coords

void SettingCaptureFrame::clearCoords(){
        this->x1=0;
        this->x2=0;
        this->y1=0;
        this->y2=0;
}
void SettingCaptureFrame::clearResize(){
        this->x1Resize=0;
        this->x2Resize=0;
        this->y1Resize=0;
        this->y2Resize=0;
}



//timer&&timerEvent
void SettingCaptureFrame::imageGetting(IplImage *img)
{
        this->frame = img;
        cvShowImage(this->nameCaptureFrame.toAscii().constData(),this->frame);
        cvSetMouseCallback( this->nameCaptureFrame.toAscii().constData(),myMouseCallback, (void*)this->frame);






}




//resizing+distance
void SettingCaptureFrame::startingResize(){
        this->hideBoxes();
        this->enabledResize=false;
        this->clearResize();
        this->startResize= true;
        emit resizing(false, 0,0,0,0);
}
void SettingCaptureFrame::startingCalculateDistance()
{
        this->hideBoxes();
        this->clearCoords();
        this->startCalculateDistance = true;
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

//boxes

void SettingCaptureFrame::hideBoxes()
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
void SettingCaptureFrame::showBoxes(){
        ui->groupBox->setEnabled(true);
        ui->groupBox_2->setEnabled(true);
        ui->groupBox_3->setEnabled(true);
        ui->groupBox_4->setEnabled(true);
        this->ui->groupBox_6->setEnabled(false);
}


//adding

void SettingCaptureFrame::toolTipMm()
{
        QToolTip::showText(ui->lineEdit->mapToGlobal(QPoint()), tr("1..100"));
}
void SettingCaptureFrame::validMmAndSet(){
        if (!ui->lineEdit->hasAcceptableInput())
                {
                        ui->lineEdit->clear();
                        ui->lineEdit->setFocus();
                }
        else{
                this->distanceInMM = ui->lineEdit->text().toDouble();
        }

}

SettingCaptureFrame::~SettingCaptureFrame()
{

        cvReleaseCapture (&this->capture);
        cvDestroyWindow(this->nameCaptureFrame.toAscii().constData());
        delete ui;
}

//buttons
void SettingCaptureFrame::on_defRect_clicked()
{

        this->startingResize();
}
void SettingCaptureFrame::on_defDistInPixels_clicked()
{
        this->startingCalculateDistance();

}
void SettingCaptureFrame::on_pushButton_7_clicked()
{
        this->stopWork();

}
void SettingCaptureFrame::on_pushButton_8_clicked()
{
        this->stopWork();
}


// Setting
void SettingCaptureFrame::readSetting()
{

        this->captureNumber= configInformation::getCaptureNumber();

        this->distanceInMM=configInformation::getdistanceInMm();
        this->distanceInPixels=configInformation::getdistanceInPixels();

        this->enabledResize = configInformation::getEnabledResize();
        this->X1=configInformation::getX1Resize();
        this->Y1=configInformation::getY1Resize();
        //this->frameWidth=configInformation::getframeWidth();
        //    this->frameHight=configInformation::getframeHight();
        this->frameWidthResize=configInformation::getframeWidthResize();
        this->frameHightResize=configInformation::getframeHightResize();
        this->coefficient = configInformation::getcoefficient();
        this->coefficientResize = configInformation::getcoefficientResize();

}
void SettingCaptureFrame::writeSetting()
{
        configInformation::setSizeWindowCapture(ui->widthCaptureWindow->value());
        configInformation::setperiodCapture(ui->spinBox->value());
        configInformation::setcoefficient(this->coefficient);
        configInformation::setcoefficientResize(this->coefficientResize);
        configInformation::setdistanceInMm(this->distanceInMM);
        configInformation::setdistanceInPixels(this->distanceInPixels);
        configInformation::setEnabledResize(this->enabledResize);
        //configInformation::setframeWidthAndFrameHight(this->frameWidth,this->frameHight);
        configInformation::setframeWidthResizeAndframeHightResize(this->frameWidthResize,this->frameHightResize);
        configInformation::setX1ResizeCoord(this->X1,this->Y1);
        configInformation::writeToFile();

}
void SettingCaptureFrame::backSetting()
{


}



void SettingCaptureFrame::on_SettingApply_clicked()
{
        if (ui->lineEdit->text().trimmed()=="")
                if (QMessageBox::Yes == QMessageBox::warning(this,tr("MM not defined"),
                                                             tr("Set dedault?"),
                                                             QMessageBox::Yes,QMessageBox::No)){
                        ui->lineEdit->setText(QString::number(configInformation::getdistanceInMm()));
                }
                else {
                        QMessageBox::information(this,tr (""),tr("then define it"), QMessageBox::Ok);
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
void SettingCaptureFrame::on_pushButtonStart_clicked()
{
        this->hideAllBoxes();
        this->ui->groupBox_3->setEnabled(true);
        this->enabledResize= false;
         emit resizing(false, 0,0,0,0);

}

void SettingCaptureFrame::on_pushButtonOk_clicked()
{
        ui->groupBox_3->setEnabled(false);
        ui->groupBox->setEnabled(true);
}
