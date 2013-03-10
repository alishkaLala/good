#include "testingframe.h"
#include "ui_testingframe.h"



testingFrame::testingFrame(ImageProcessing *worker, QWidget *parent) :
        QWidget(0),
        ui(new Ui::testingFrame)
{
        this->worker = worker;
        this->father=parent;
        ui->setupUi(this);



}
testingFrame::~testingFrame()
{
        delete ui;
}

void testingFrame::showEvent(QShowEvent *event){
        connect (this->worker,SIGNAL(imageCalculateReady(IplImage*)),this,SLOT(imageGetting(IplImage*)));
        connect (this->worker,SIGNAL(captureProp(int,int,int)),this,SLOT(setCaptureProp(int,int,int)));
        this->father->close ();
        this->worker->setTesting (true);


}
void testingFrame::closeEvent(QCloseEvent *event= NULL){
        disconnect (this->worker,SIGNAL(imageCalculateReady(IplImage*)),this,SLOT(imageGetting(IplImage*)));
        disconnect (this->worker,SIGNAL(captureProp(int,int,int)),this,SLOT(setCaptureProp(int,int,int)));
        this->worker->setCalculation (false);
        this->worker->working(false);
        this->worker->setTesting (false);
        this->father->show ();


}


void testingFrame::setChoisedCapture (int value)
{
        this->choisedCapture = value;
        this->ui->comboBox->setCurrentIndex (value);
}
void testingFrame::setNumberCapture (int value)
{
        this->numberCaptures = value;
        ui->comboBox->clear ();
        for (int i=0; i<this->numberCaptures;i++)
                ui->comboBox->addItem (QString::number (i+1));
}
void testingFrame::setCaptureProp (int w, int h , int fps)
{
        this->w=w;
        this->h=h;
        this->fps= fps;
        qDebug ()<<"get capture prop. :" <<w<<" "<<h<<" "<<fps;

}
void testingFrame::imageGetting(IplImage *img)
{

        uchar* data = NULL;
        delete this->dataToDelete;
        QImage* qt_img = IplImageToQImage(img, &data, 0.0, 0.0);
        ui->label_5->setPixmap(QPixmap::fromImage(*qt_img));
        delete qt_img;
        this->dataToDelete= data;


}
QImage* testingFrame::IplImageToQImage(const IplImage * iplImage, uchar **data,
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
void testingFrame::on_pushButton_clicked()
{
        worker->setCalculation (true);
        worker->working (true);
        worker->getImage ();
}
