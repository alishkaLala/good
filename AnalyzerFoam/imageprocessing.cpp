#include "imageprocessing.h"

ImageProcessing::ImageProcessing(QObject *parent) :
        QThread(parent)
{

        // emit test();
        this->choisedCapture= 0;
        this->isWorking=false;
        this->calculateImage= false;
        this->kadrProssesd = 0;
        k1= 0.027;
        k2 = 0.65;

}




void ImageProcessing::setCalculation (bool value)
{
        this->calculateImage= value;
        this->kadrProssesd = 0;
}
void ImageProcessing::setChoisedCpture (int value)
{
        this->choisedCapture =  value;
}
void ImageProcessing::run()
{
        exec();
}
void ImageProcessing::getImage()
{
        int number = this->choisedCapture;
        CvCapture* capture =0;
        IplImage* frame =0;
        char filename[512];
        capture = cvCreateCameraCapture(number);
        assert(capture);
        cvNamedWindow("capture", CV_WINDOW_AUTOSIZE);
        frame = cvLoadImage("4.jpg",CV_LOAD_IMAGE_COLOR);
        int x = 389,y = 292;//2592*1944 ->389*292
        while(isWorking){
               frame = cvQueryFrame( capture );

                //frame = cvLoadImage("4.jpg",CV_LOAD_IMAGE_COLOR);
                if (frame ==NULL)
                        {
                                qDebug ()<<" capture broken";
                                this->isWorking = false;
                                break;
                        }
                IplImage *src = cvCreateImage(cvSize(x,y),frame->depth,frame->nChannels);

                cvResize(frame,src,CV_INTER_LINEAR);
                cvShowImage("capture", src);
                emit imageIsReady(src);
                if (true)
                        {
                                IplImage* hsv = cvCreateImage( cvGetSize(src), 8, 3 );// ���������� � ������ HSV
                                IplImage* h_plane = cvCreateImage( cvGetSize(src), 8, 1 );// ����� H
                                IplImage* s_plane = cvCreateImage( cvGetSize(src), 8, 1 );// ����� S
                                IplImage* v_plane = cvCreateImage( cvGetSize(src), 8, 1 );// ����� V

                                IplImage* h_can = cvCreateImage( cvGetSize(src), 8, 1 ); // ����� ������
                                IplImage* s_can = cvCreateImage( cvGetSize(src), 8, 1 ); // ����� ������
                                IplImage* v_can = cvCreateImage( cvGetSize(src), 8, 1 ); // ����� ������

                                IplImage* sum_can = cvCreateImage( cvGetSize(src), 8, 1 ); // ����� ������
                                IplImage* s = cvCreateImage( cvGetSize(src), 8, 1 ); // ����� ������

                                //  ������������ � HSV
                                //cvCvtColor( src, hsv, CV_RGB2HSV );

                                // ��������� �� ������
                                //cvCvtPixToPlane( hsv, h_plane, s_plane, v_plane, 0 );
                                // ��� ������� ������������� ����� V
                                    //cvShowImage("1v_chanal",v_plane );
                                int b=0,a=0;
                                //canal_contur(v_plane,v_can,11,a,b);//��������� �������� ��������
                                //canal_contur(h_plane,h_can,11,a,b);//��������� �������� ��������
                                //canal_contur(s_plane,s_can,11,a,b);//��������� �������� ��������

                                //    cvShowImage("6canny_v",v_can);    cvShowImage("6canny_h",h_can);    cvShowImage("6canny_c",s_can);

                                //cvOr(h_can,v_can,sum_can);cvOr(sum_can,s_can,sum_can);//������� ����������

                                cvCvtPixToPlane( src, h_plane, s_plane, v_plane, 0 ); //RGB  ������

                               /* canal_contur(v_plane,v_can,11,a,b);//��������� �������� ��������
                                canal_contur(h_plane,h_can,11,a,b);//��������� �������� ��������
                                canal_contur(s_plane,s_can,11,a,b);//��������� �������� ��������*/
                                double k1= 0.027, k2= 0.075;
                               Canal_contur * pr1 = new Canal_contur(v_plane,v_can,11,a,b,k1,k2);//��������� �������� ��������
                               Canal_contur * pr2 = new Canal_contur(h_plane,h_can,11,a,b,k1,k2);//��������� �������� ��������
                                Canal_contur *pr3 = new Canal_contur(s_plane,s_can,11,a,b,k1,k2);//��������� �������� ��������

                                pr1->wait();
                                pr2->wait();
                                pr3->wait();


                                //cvShowImage("6canny_r",v_can);    cvShowImage("6canny_g",h_can);    cvShowImage("6canny_b",s_can);
                                sum_can=v_can;
                                cvOr(sum_can,v_can,sum_can);cvOr(sum_can,h_can,sum_can);cvOr(sum_can,s_can,sum_can);

                                cvShowImage("summa_first",sum_can);

                                //������������� �������

                                CvMemStorage* storage = cvCreateMemStorage(0);CvSeq* contours=0;

                                cvFindContours( sum_can, storage,&contours,sizeof(CvContour),CV_RETR_EXTERNAL,CV_CHAIN_APPROX_SIMPLE,cvPoint(0,0));
                                //���������� �������
                                for(CvSeq* seq0 = contours;seq0!=0;seq0 = seq0->h_next){
                                                int count = seq0->total; if( count < 10 ) continue;
                                                cvDrawContours(sum_can, seq0, cvScalar(255), cvScalar(255), 0, CV_FILLED, 8); // ������ ������
                                        }
                                cvShowImage("summa_x",sum_can);
                                int radius = 1,iterations=1;
                                    IplConvKernel* Kern = cvCreateStructuringElementEx(radius*2+1, radius*2+1, radius, radius, CV_SHAPE_ELLIPSE);

                                    cvErode(sum_can, sum_can, Kern, iterations);
                                    cvDilate(sum_can, sum_can, Kern, iterations);

                                //cvShowImage("summa",sum_can);
                                //cvDilate(sum_can, s, Kern, iterations);
                                //cvSub(s,sum_can,sum_can);
                                 cvShowImage("summa_s",sum_can);


                                storage = cvCreateMemStorage(0); contours=0;
                                cvFindContours( sum_can, storage,&contours,sizeof(CvContour),CV_RETR_EXTERNAL,CV_CHAIN_APPROX_SIMPLE,cvPoint(0,0));

                                //���������� �������
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


                                                //cvEllipse(src, center, size,-box.angle, 0, 360,CV_RGB(0,0,255), -1, CV_AA, 0);
                                                //cvDrawContours(src, seq0, CV_RGB(0,0,0), CV_RGB(0,0,250), 0, CV_FILLED, 8); // ������ ������
                                                cvCircle(src,center,(size.width+size.height)/2,CV_RGB(0,0,255),1, CV_AA, 0);
                                                //double diametr = size.width+size.height;

                                                cvReleaseMat(&points_f);
                                        }


                                cvShowImage("7kontur",src);




                                emit this->imageCalculateReady (src);





                                delete  pr1;
                                delete  pr2;
                                delete  pr3;

                        }


                emit infoIsReady (qrand ()%40,qrand ()%40);


                cvWaitKey(1000);
                cvReleaseImage(&src);


        }


        cvReleaseCapture(&capture);
        cvReleaseImage(&frame);

}
void ImageProcessing::working(bool setting){

        this->isWorking = setting;
        qDebug ()<<"getValue"<<setting;
}
