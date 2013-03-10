#include "imageprocessing.h"

ImageProcessing::ImageProcessing(QObject *parent) :
        QThread(parent)
{
        this->choisedCapture= 0;
        this->isWorking=false;
        this->calculateImage= false;
        this->kadrProssesd = 0;
        k1= 0.027;
        k2 = 0.65;
        width = 389,heigth = 292;
        this->widthROI= 100;
        this->heigthROI= 100;
        this->delay= 1;
}

void ImageProcessing::run()
{
        exec();
}

//main working funktion
void ImageProcessing::getImage()
{
        IplImage* frame =0;
        capture = cvCreateCameraCapture (this->choisedCapture);
        cvNamedWindow("capture", CV_WINDOW_AUTOSIZE);
        this->realyWork= true;
        // frame = cvLoadImage("4.jpg",CV_LOAD_IMAGE_COLOR);
        this->captureWidth=  cvGetCaptureProperty (this->capture,3);
        this->captureHeight= cvGetCaptureProperty (this->capture,4);
        this->fps= cvGetCaptureProperty (this->capture,CV_CAP_PROP_FPS);

        if (this->testing)
                {
                       emit captureProp (this->captureWidth,this->captureHeight,this->fps);
                       this->setWindowSize (this->captureWidth/2);


                }
        qDebug ()<< "capture size : "<< this->captureWidth<<"*"<<this->captureHeight;
        this->kadrProssesd =0;
        while(isWorking){
                frame = cvQueryFrame( capture );
                if (frame ==NULL)
                        {
                                qDebug ()<<" capture broken";
                                this->isWorking = false;
                                break;
                        }
                IplImage *src = cvCreateImage(cvSize(width,heigth),frame->depth,frame->nChannels);
                cvResize(frame,src,CV_INTER_LINEAR);
                if (this->enabledResize)
                        {
                                cvSetImageROI (src,
                                               cvRect(x1,y1,this->widthROI,this->heigthROI)
                                               );
                        }
                cvShowImage("capture", src);
                if (this->calculateImage)
                        {
                                int countBell=0;
                                double averageDiametr =0;
                                IplImage* h_plane = cvCreateImage( cvGetSize(src), 8, 1 );// ����� H
                                IplImage* s_plane = cvCreateImage( cvGetSize(src), 8, 1 );// ����� S
                                IplImage* v_plane = cvCreateImage( cvGetSize(src), 8, 1 );// ����� V
                                IplImage* h_can = cvCreateImage( cvGetSize(src), 8, 1 ); // ����� ������
                                IplImage* s_can = cvCreateImage( cvGetSize(src), 8, 1 ); // ����� ������
                                IplImage* v_can = cvCreateImage( cvGetSize(src), 8, 1 ); // ����� ������
                                IplImage* sum_can = cvCreateImage( cvGetSize(src), 8, 1 ); // ����� ������
                                int b=0,a=0;
                                cvCvtPixToPlane( src, h_plane, s_plane, v_plane, 0 ); //RGB  ������
                                this->kadrProssesd++;
                                qDebug ()<<"kadr :"<<this->kadrProssesd<<"CAPURE SIZE :"<<width<<"*"<<heigth<< " use k1= "<<k1 <<"k2 =  "<<k2 << "with delay: "<<this->delay;
                                Canal_contur * pr1 = new Canal_contur(v_plane,v_can,11,a,b,k1,k2);//��������� �������� ��������
                                Canal_contur * pr2 = new Canal_contur(h_plane,h_can,11,a,b,k1,k2);//��������� �������� ��������
                                Canal_contur *pr3 = new Canal_contur(s_plane,s_can,11,a,b,k1,k2);//��������� �������� ��������
                                pr1->wait();
                                pr2->wait();
                                pr3->wait();
                                cvReleaseImage(&h_plane);cvReleaseImage(&s_plane);cvReleaseImage(&v_plane);
                                cvOr(v_can,h_can,sum_can);
                                cvOr(sum_can,s_can,sum_can);
                                cvReleaseImage(&h_can);cvReleaseImage(&s_can);cvReleaseImage(&v_can);
                                cvShowImage("summa_first",sum_can);
                                CvMemStorage* storage = cvCreateMemStorage(0);CvSeq* contours=0;
                                cvFindContours( sum_can, storage,&contours,sizeof(CvContour),CV_RETR_EXTERNAL,CV_CHAIN_APPROX_SIMPLE,cvPoint(0,0));
                                for(CvSeq* seq0 = contours;seq0!=0;seq0 = seq0->h_next)
                                        {
                                                int count = seq0->total; if( count < 10 ) continue;
                                                cvDrawContours(sum_can, seq0, cvScalar(255), cvScalar(255), 0, CV_FILLED, 8); // ������ ������
                                        }
                                cvReleaseMemStorage( &storage );//� ��������� ������ contours �� ���������????
                                cvShowImage("summa_x",sum_can);
                                int radius = 1,iterations=1;
                                IplConvKernel* Kern = cvCreateStructuringElementEx(radius*2+1, radius*2+1, radius, radius, CV_SHAPE_ELLIPSE);
                                cvErode(sum_can, sum_can, Kern, iterations);
                                cvDilate(sum_can, sum_can, Kern, iterations);
                                cvReleaseStructuringElement(&Kern);//---------
                                cvShowImage("summa_s",sum_can);
                                storage = cvCreateMemStorage(0); contours=0;
                                cvFindContours( sum_can, storage,&contours,sizeof(CvContour),CV_RETR_EXTERNAL,CV_CHAIN_APPROX_SIMPLE,cvPoint(0,0));
                                for(CvSeq* seq0 = contours;seq0!=0;seq0 = seq0->h_next){
                                        int count = seq0->total;
                                        CvPoint center;CvSize size;CvBox2D box;
                                        if( count < 10 ) continue;
                                        CvMat* points_f = cvCreateMat( 1, count, CV_32FC2 );
                                        CvMat points_i = cvMat( 1, count, CV_32SC2, points_f->data.ptr );
                                        cvCvtSeqToArray( seq0, points_f->data.ptr, CV_WHOLE_SEQ );
                                        cvConvert( &points_i, points_f );
                                        box = cvFitEllipse2( points_f );
                                        center = cvPointFrom32f(box.center);
                                        size.width = cvRound(box.size.width*0.5);
                                        size.height = cvRound(box.size.height*0.5);
                                        cvCircle(src,center,(size.width+size.height)/2,CV_RGB(0,0,255),1, CV_AA, 0);
                                        double diametr = size.width+size.height;
                                        averageDiametr+=diametr;
                                        countBell++;
                                        cvReleaseMat(&points_f);
                                }
                                cvShowImage("7kontur",src);
                                emit this->imageCalculateReady (src);
                                delete  pr1;
                                delete  pr2;
                                delete  pr3;
                                cvReleaseImage(&sum_can);
                                cvReleaseMemStorage( &storage );
                                emit infoIsReady (countBell*0.1,2.0 *averageDiametr/countBell);
                                qDebug ()<<"count Bell "<< countBell<<"average diametr = " <<3*averageDiametr/countBell;
                                /*
                                                max value 40*40
                                          GET :  count Bell  281 average diametr =  11.0071

                                          400 count Bell  - 40
                                          1count Bell  -  0.1

                                        20  average diametr - 40
                                        1 average diametr - 2
                                */

                        }
                emit imageIsReady(src);
                //emit infoIsReady (qrand ()%40,qrand ()%40);
                cvWaitKey(delay);
                cvReleaseImage(&src);
        }
        realyWork= false;
        cvReleaseCapture(&capture);
        cvReleaseImage(&frame);
}

//status of working
bool ImageProcessing::isRealyWork ()
{
        return realyWork;
}

// setting capture pref.
//working:
void ImageProcessing::working(bool setting){

        this->isWorking = setting;
        qDebug ()<<"set value working "<<setting;
}
void ImageProcessing::setCalculation (bool value)
{
        this->calculateImage= value;
        this->kadrProssesd = 0;
        qDebug ()<<"get Signal to calculate :  "<<value;
}
// set values
void ImageProcessing::setChoisedCpture (int value)
{
        this->choisedCapture =  value;
}
void ImageProcessing::setK1 (double value)
{

        k1= value;
        qDebug ()<<"get value k1= "<<k1;
}
void ImageProcessing::setK2(double value)
{
        this->k2= value;
        qDebug ()<<"get value k2= "<<k2;
}
void ImageProcessing::setWindowSize (int value)
{
        this->wishWindowsize= value;
        double k;
        if (this ->captureWidth!=0&& this ->captureHeight!=0)
                {
                        k = qMin( value*1.0/this->captureWidth, value *1.0/ captureHeight);
                }
        this->width = this->captureWidth*k;
        this->heigth= this->captureHeight*k;
        qDebug ()<<"resize to "<<width <<"*"<<heigth ;


}
void ImageProcessing::setEnabledResize (bool value, int x1=0, int y1=0, int x2=0, int y2=0)
{
        this->enabledResize= value;
        this->x1= x1;
        this->y1 = y1;
        this->widthROI = qAbs(x2-x1);
        this->heigthROI =qAbs(y2-y1);
}
void ImageProcessing::setTesting (bool value)
{
        this->testing=value;
}
