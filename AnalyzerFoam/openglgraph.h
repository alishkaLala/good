#ifndef OPENGLGRAPH_H
#define OPENGLGRAPH_H


#include <QMouseEvent>
#include <QGLWidget>
#include <QColorDialog>
#include <QTimer>
#include <QtOpenGL>
#include <QtGui>
#include <imageprocessing.h>
#include <QEvent>

const int max_cnt = 200;

struct myPoints {
        double x;
        double y;
};

class OpenglGraph : public QGLWidget
{

public:
        myPoints * pol;
        GLfloat jjj;
        OpenglGraph(ImageProcessing *worker, QWidget *parent = 0);
        void showEvent(QShowEvent *event);
protected:
        virtual void initializeGL();
        virtual void resizeGL(int width, int height);
        virtual void paintGL();
        virtual void mousePressEvent(QMouseEvent *event);
        virtual void mouseMoveEvent(QMouseEvent *event);
        virtual void wheelEvent(QWheelEvent* pe);
        virtual  void keyPressEvent(QKeyEvent* pe);


private:
        ImageProcessing *worker;
        QPoint ptrMousePosition;
        GLfloat xRot; // ���������� ������ ���� �������� ������ ��� X
        GLfloat yRot; // ���������� ������ ���� �������� ������ ��� Y
        GLfloat zRot; // ���������� ������ ���� �������� ������ ��� Z

        void scale_plus();     // ���������� �����
        void scale_minus();    // ��������� �� �����
        void rotate_up();      // ��������� ����� �����
        void rotate_down();    // ��������� ����� ����
        void rotate_left();    // ��������� ����� �����
        void rotate_right();   // ��������� ����� ������
        void translate_down(); // ������������� ����� ����
        void translate_up();   // ������������� ����� �����
        void defaultScene();   // ���������� ����� �� ���������
        void drawAxis();
        void draw();

        GLfloat zTra; // ���������� ������ �������� ���������� ��� Z
        GLfloat nSca; // ���������� �������� �� ��������������� �������


        QPoint lastPos;

public slots:
        void genCoords(double k,double m);
};

#endif // OPENGLGRAPH_H
