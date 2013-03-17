#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
        ui->setupUi(this);
        this->initValues();
        this->createWindows();
        this->initialConnections();
        this->elementHide();
        worker->start(); // start exec()

}
MainWindow::~MainWindow()
{
        this->infoFrame->destroyThis();
        this->setSartStopImegeGetting(false);
        this->worker->working (false);
        delete ui;
}
// events
void MainWindow::showEvent(QShowEvent *event){
        ui->label->setText ("Камера вимкнена");
        this->initPalette ();
        this->readSettingCaprure();
        if(ui->processingImageShow->isChecked ()) // show capture frame
                {
                        this->setSartStopImegeGetting (true);
                }

}
void MainWindow::closeEvent(QCloseEvent *event= NULL){

        this->worker->setCalculation (false);
        this->worker->working(false);
        this->setSartStopImegeGetting(false);




}
//signal getting
void MainWindow::imageGetting(IplImage *img)
{
        uchar* data = NULL;
        delete this->dataToDelete;
        QImage* qt_img = IplImageToQImage(img, &data, 0.0, 0.0);
        ui->capturePicture->setPixmap(QPixmap::fromImage(*qt_img));
        delete qt_img;
        this->dataToDelete= data;


}
void MainWindow::infoGetting(double count, double diametr, double *arr)
{

        if (gr->isVisible ())
                {
                        this->gr->genCoords(count,diametr,arr);
                }

}

// init
void MainWindow::initValues()
{
        this->worker = new ImageProcessing();
        this->timeToWork = 100;
        ui->spinBox->setRange(1,this->timeToWork);
        ui->horizontalSlider->setRange(1,this->timeToWork);
        this->showImage();

}
void MainWindow::initialMenuCapture()
{
        this->numberOfCapture = this->findCapture();
        this->testFrame->setNumberCapture (this->numberOfCapture);
        this->ui->menuChoise_capture->clear();

        for (int i=0 ;i<this->numberOfCapture;i++){
                this->menuCaptureArray.append( new QAction (QString::number(i+1), this->ui->menuChoise_capture));
                ui->comboBox->addItem (QString::number (i+1));
        }
        ui->menuChoise_capture->addActions(this->menuCaptureArray);
}
void MainWindow::initialConnections()
{
        connect(ui->spinBox,SIGNAL(valueChanged(int)),ui->horizontalSlider,SLOT(setValue(int))); // spinBox => slider
        connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),ui->spinBox,SLOT(setValue(int)));//slider =>spinBoox
        connect(ui->actionDisable_capture,SIGNAL(triggered()),this,SLOT (captureStop())); // menu =>disable capture
        connect(ui->actionHide_capture,SIGNAL(triggered()),this,SLOT(hideCapture()));//menu => hide capture
        connect(ui->actionShow_capture,SIGNAL(triggered()),this,SLOT(showCapture()));// menu =>show capture
        connect( ui->processingImageShow,SIGNAL(toggled(bool)),this,SLOT(setSartStopImegeGetting(bool))); // show/hide capture
        connect(ui->actionInformation,SIGNAL(triggered()),this,SLOT(showInfoFrame()));// ??????????????????????????????????????????????????????????
        connect(ui->actionStart_testing,SIGNAL(triggered()),this,SLOT(showTestingFrame()));
        connect(ui->actionConfiguration_of_program,SIGNAL(triggered()),this ,SLOT(showSettingFrame()));// menu => setting Frame
        connect(ui->actionConfiguration_of_capture,SIGNAL(triggered()),this,SLOT(showSettingCapture()));//menu capture Frame
        connect (ui->actionTo_graphik,SIGNAL(triggered()),SLOT (showOpenGLGraph()));//menu =? OpenGL
        connect(ui->buttonCaptureStart,SIGNAL(clicked()),this,SLOT(captureStart()));
        connect (ui->buttonCaptureStart, SIGNAL(clicked()), this->worker,SLOT(getImage())); // starting getting capture frame
        connect(this->ui->comboBox,SIGNAL(currentIndexChanged(int)),this->worker,SLOT(setChoisedCpture(int)));//set choised capture in worker
        connect (ui->buttonAnalizStart,SIGNAL(clicked()),this,SLOT(calculateImagesStart())); //start analiz=> (set no gui)
        connect (ui->buttonAnalizStop,SIGNAL(clicked()),this,SLOT(calculateImageStop()));//stop analiz =>(set no gui)


}
void MainWindow::initPalette ()
{
        this->setPalette(configInformation::getpalleteAllWindows());
        this->setFont(configInformation::getfont());
        this->repaint();
}
void MainWindow::createWindows()//create windows  + menu capture
{
        this->testFrame = new testingFrame(this->worker, this);
        this-> gr = new OpenglGraph(this->worker);
        this->infoFrame=new InfoFrame(this);
        this->settingMainFrames = new SettingMainFrames(this);
        this->settingCaptureFrame = new SettingCaptureFrame(this->worker, this);
        this->initialMenuCapture();
}

void MainWindow::readSettingCaprure(){
        /* this->enabledResize = configInformation::getEnabledResize();
        this->x1Resize=configInformation::getX1Resize();
        this->y1Resize=configInformation::getY1Resize();
        this->frameWidth=configInformation::getframeWidth();
        this->frameHight=configInformation::getframeHight();
        this->frameWidthResize=configInformation::getframeWidthResize();
        this->frameHightResize=configInformation::getframeHightResize();
        this->coefficient = configInformation::getcoefficient();
        this->coefficientResize = configInformation::getcoefficientResize();
*/
}


//first hide/show element
void MainWindow::elementHide()
{



        // ui->menuExport->setEnabled(false);
}
void MainWindow::elemetShow(){
        ui->menuExport->setVisible(true);
}

// function to call
void MainWindow::showCapture()//  show captureframe
{

        this->ui->processingImageShow->setChecked (true);
}
void MainWindow::hideCapture() //hide capture frame
{
        ui->processingImageShow->setChecked (false);
}
void MainWindow::setSartStopImegeGetting(bool enabled)//calling function
{
        if (enabled){
                qDebug ()<<"enable gettin image";
                connect(this->worker,SIGNAL(imageIsReady(IplImage*)),this,SLOT(imageGetting(IplImage*)));

        }
        else {
                qDebug ()<<"disable gettin image";
                disconnect(this->worker,SIGNAL(imageIsReady( IplImage*)),this,SLOT(imageGetting( IplImage*)));
                this->showImage();
        }
}
void MainWindow::showImage()//show image from resourse
{
        ui->capturePicture->setPixmap(QPixmap(":/image/4x.jpg"));
}
void MainWindow::captureStop()
{
        this->worker->working (false);
         ui->label->setText ("Було вимкнено камеру");
}
void MainWindow::captureStart ()
{
        this->worker->working(true);
        this->worker->setCalculation (false);

}
void MainWindow::calculateImagesStart ()
{

        this->workingTime= 1000*60*ui->spinBox->value ();
        this->workingTimeDelta = qCeil (this->workingTime/100.0);
        this->worker->setCalculation (true);
        connect(this->worker,SIGNAL(infoIsReady(double,double,double*)),this,SLOT(infoGetting(double,double,double*)));
        QTimer::singleShot (this->workingTimeDelta,this,SLOT(progressBarChange()));

}
void MainWindow::calculateImageStop ()
{
        this->captureStop ();

}
void MainWindow::progressBarChange ()
{
        if (this->workingTime==-1)
                {
                        return;
                }
        this->workingTime-=this->workingTimeDelta;
        qDebug ()<<this->workingTime;
        if ( this->workingTime>this->workingTimeDelta)
                {
                        ui->progressBar->setValue (ui->progressBar->value ()-1);
                        QTimer::singleShot (this->workingTimeDelta,this,SLOT(progressBarChange()));

                }
        else
                {
                        ui->progressBar->setValue (0);
                        this-> calculateImageStop();
                        this->on_buttonAnalizStop_clicked ();
                }
}

//frames
void MainWindow::showAboutProgram()
{

}
void MainWindow::showInfoFrame(){
        this->infoFrame->show();
        this->close();
}
void MainWindow::showSettingFrame(){
        this->settingMainFrames->show();
        this->close();

}
void MainWindow::showSettingCapture(){

        this->close();
        this->setSartStopImegeGetting(false);
        this->settingCaptureFrame->show();


}
void MainWindow::showOpenGLGraph(){

        gr->setWindowTitle("3d");
        gr->show();

}
void MainWindow::showTestingFrame ()
{
        this->testFrame->show ();

}

// aditional function
qint8 MainWindow::findCapture(){
        CvCapture *cap_temp;
        int   tmpNumberOfCapture  =0;
        while (1)
                {
                        cap_temp=cvCreateCameraCapture(tmpNumberOfCapture++);
                        if (cap_temp==NULL) break;
                        cvReleaseCapture(&cap_temp);
                }
        tmpNumberOfCapture--;
        return tmpNumberOfCapture;
}
bool MainWindow::okToContinue(QString Msg){
        qint32 answer = QMessageBox::warning(this,tr("Увага!"),Msg.toLocal8Bit().constData(),
                                             QMessageBox::Yes,QMessageBox::No);
        if (answer== QMessageBox::Yes) return true;
        return false;
}
IplImage* MainWindow::QImageToIplImage(const QImage * qImage)
{
        int width = qImage->width();
        int height = qImage->height();
        CvSize Size;
        Size.height = height;
        Size.width = width;
        IplImage *charIplImageBuffer = cvCreateImage(Size, IPL_DEPTH_8U, 1);
        char *charTemp = (char *) charIplImageBuffer->imageData;

        for (int y = 0; y < height; y++)
                {
                        for (int x = 0; x < width; x++)
                                {
                                        int index = y * width + x;
                                        charTemp[index] = (char) qGray(qImage->pixel(x, y));
                                }
                }
        return charIplImageBuffer;
}
QImage* MainWindow::IplImageToQImage(const IplImage * iplImage, uchar **data,
                                     double mini, double maxi)
{
        uchar *qImageBuffer = NULL;
        int width = iplImage->width;

        // Note here that OpenCV image is stored so that each lined is
        // 32-bits aligned thus * explaining the necessity to "skip"
        // the few last bytes of each line of OpenCV image buffer.
        int widthStep = iplImage->widthStep;
        int height = iplImage->height;

        switch (iplImage->depth)
                {
        case IPL_DEPTH_8U:
                        if (iplImage->nChannels == 1)
                                {
                                        // IplImage is stored with one byte grey pixel.
                                        // We convert it to an 8 bit depth QImage.
                                        qImageBuffer = (uchar *) malloc(width*height*sizeof(uchar));
                                        uchar *QImagePtr = qImageBuffer;
                                        const uchar *iplImagePtr = (const uchar *)iplImage->imageData;
                                        for (int y = 0; y < height; y++)
                                                {
                                                        // Copy line by line
                                                        memcpy(QImagePtr, iplImagePtr, width);
                                                        QImagePtr += width;
                                                        iplImagePtr += widthStep;
                                                }
                                }
                        else if (iplImage->nChannels == 3)
                                {
                                        // IplImage is stored with 3 byte color pixels (3 channels).
                                        // We convert it to a 32 bit depth QImage.
                                        qImageBuffer = (uchar *) malloc(width*height*4*sizeof(uchar));
                                        uchar *QImagePtr = qImageBuffer;
                                        const uchar *iplImagePtr = (const uchar *) iplImage->imageData;

                                        for (int y = 0; y < height; y++)
                                                {
                                                        for (int x = 0; x < width; x++)
                                                                {
                                                                        // We cannot help but copy manually.
                                                                        QImagePtr[0] = iplImagePtr[0];
                                                                        QImagePtr[1] = iplImagePtr[1];
                                                                        QImagePtr[2] = iplImagePtr[2];
                                                                        QImagePtr[3] = 0;

                                                                        QImagePtr += 4;
                                                                        iplImagePtr += 3;
                                                                }
                                                        iplImagePtr += widthStep-3*width;
                                                }
                                }
                        else
                                {
                                        qDebug("IplImageToQImage: image format is not supported:\
                                               depth=8U and %d channels\n", iplImage->nChannels);
                                }
                        break;

                case IPL_DEPTH_16U:
                        if (iplImage->nChannels == 1)
                                {
                                        // IplImage is stored with 2 bytes grey pixel.
                                        // We convert it to an 8 bit depth QImage.
                                        qImageBuffer = (uchar *) malloc(width*height*sizeof(uchar));
                                        uchar *QImagePtr = qImageBuffer;
                                        const uint16_t *iplImagePtr = (const uint16_t *)iplImage->imageData;

                                        for (int y = 0; y < height; y++)
                                                {
                                                        for (int x = 0; x < width; x++)
                                                                {
                                                                        // We take only the highest part of the 16 bit value.
                                                                        // It is similar to dividing by 256.
                                                                        *QImagePtr++ = ((*iplImagePtr++) >> 8);
                                                                }
                                                        iplImagePtr += widthStep/sizeof(uint16_t)-width;
                                                }
                                }
                        else
                                {
                                        qDebug("IplImageToQImage: image format is not supported:\
                                               depth=16U and %d channels\n", iplImage->nChannels);
                                }
                        break;

                case IPL_DEPTH_32F:
                        if (iplImage->nChannels == 1)
                                {
                                        // IplImage is stored with float (4 bytes) grey pixel.
                                        // We convert it to an 8 bit depth QImage.
                                        qImageBuffer = (uchar *) malloc(width*height*sizeof(uchar));
                                        uchar *QImagePtr = qImageBuffer;
                                        const float *iplImagePtr = (const float *) iplImage->imageData;

                                        for (int y = 0; y < height; y++)
                                                {
                                                        for (int x = 0; x < width; x++)
                                                                {
                                                                        uchar p;
                                                                        float pf = 255 * ((*iplImagePtr++) - mini) / (maxi - mini);

                                                                        if (pf < 0) p = 0;
                                                                        else if (pf > 255) p = 255;
                                                                        else p = (uchar) pf;

                                                                        *QImagePtr++ = p;
                                                                }
                                                        iplImagePtr += widthStep/sizeof(float)-width;
                                                }
                                }
                        else
                                {
                                        qDebug("IplImageToQImage: image format is not supported:\
                                               depth=32F and %d channels\n", iplImage->nChannels);
                                }
                        break;

                case IPL_DEPTH_64F:
                        if (iplImage->nChannels == 1)
                                {
                                        // OpenCV image is stored with double (8 bytes) grey pixel.
                                        // We convert it to an 8 bit depth QImage.
                                        qImageBuffer = (uchar *) malloc(width*height*sizeof(uchar));
                                        uchar *QImagePtr = qImageBuffer;
                                        const double *iplImagePtr = (const double *) iplImage->imageData;

                                        for (int y = 0; y < height; y++)
                                                {
                                                        for (int x = 0; x < width; x++)
                                                                {
                                                                        uchar p;
                                                                        double pf = 255 * ((*iplImagePtr++) - mini) / (maxi - mini);

                                                                        if (pf < 0) p = 0;
                                                                        else if (pf > 255) p = 255;
                                                                        else p = (uchar) pf;

                                                                        *QImagePtr++ = p;
                                                                }
                                                        iplImagePtr += widthStep/sizeof(double)-width;
                                                }
                                }
                        else
                                {
                                        qDebug("IplImageToQImage: image format is not supported:\
                                               depth=64F and %d channels\n", iplImage->nChannels);
                                }
                        break;

                default:
                        qDebug("IplImageToQImage: image format is not supported: depth=%d\
                               and %d channels\n", iplImage->depth, iplImage->nChannels);
                }

        QImage *qImage;
        if (iplImage->nChannels == 1)
                {
                        QVector<QRgb> colorTable;
                        for (int i = 0; i < 256; i++)
                                {
                                        colorTable.push_back(qRgb(i, i, i));
                                }
                        qImage = new QImage(qImageBuffer, width, height, QImage::Format_Indexed8);
                        qImage->setColorTable(colorTable);
                }
        else
                {
                        qImage = new QImage(qImageBuffer, width, height, QImage::Format_RGB32);
                }
        *data = qImageBuffer;

        return qImage;
}

void MainWindow::on_startCalculation_clicked()
{
        if (true)
                {
                        this->worker->working (true);

                        ui->menuSetting->setEnabled(false);
                        ui->menuCapture->setEnabled(false);

                        //    ui->startCalculation->setText ("Зупинити аналіз");
                        this->worker->getImage ();
                        /*  QTimer::singleShot (this->ui->spinBox->value (),this,SLOT(on_startCalculation_clicked));*/



                }
        else{
                this->worker->setCalculation (false);
                this->worker->working(false);
                this->setSartStopImegeGetting(false);
                ui->menuSetting->setEnabled(true);
                ui->menuCapture->setEnabled(true);

                //  ui->startCalculation->setText ("Розпочати аналіз");

        }


}

// button click f.
void MainWindow::on_buttonAnalizStart_clicked()
{
        ui->buttonAnalizStop->setEnabled (true);
        ui->buttonAnalizStart->setEnabled (false);
        ui->label->setText ("Було увімкнено аналіз зображення");
        ui->buttonCaptureStart->setEnabled (false);


}
void MainWindow::on_buttonAnalizStop_clicked()
{
        ui->frame->setEnabled (false);
        ui->progressBar->setValue (100);
        this->workingTime = -1;
        ui->label->setText ("Було вимкнено камеру");
          ui->buttonCaptureStart->setEnabled (true);
}
void MainWindow::on_buttonCaptureStart_clicked()
{

        ui->frame->setEnabled (true);
        ui->buttonAnalizStart->setEnabled (true);
        this->ui->buttonAnalizStop->setEnabled (false);
        ui->label->setText ("Було увімкнено камеру");
}
