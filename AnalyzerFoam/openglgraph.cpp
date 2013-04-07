#include "openglgraph.h"


#include <sys/types.h>
#include <stdio.h>

#include <QtGui>

const static float pi=3.141593, k=pi/180; // ���������� ����������

OpenglGraph::OpenglGraph(ImageProcessing *worker, QWidget *parent): QGLWidget(parent)
{
  this->worker = worker;
  setFormat(QGLFormat(QGL::DoubleBuffer | QGL::DepthBuffer));
  xRot=0; yRot=0; zRot=0; zTra=-2; nSca=1;
  k = 1;


  pol = (myPoints *) malloc(max_cnt*sizeof(myPoints));
  for (int i = 0; i < max_cnt; i++) {
    pol[i].x =40;
    pol[i].y = 40;

  }

}

void OpenglGraph::showEvent (QShowEvent *event)
{
  this->defaultScene ();
  for (int i=0; i < max_cnt-1; i++) {
    pol[i].x = 0.0;
    pol[i].y = 0.0;
    for (int j=0; j<10;j++)
      {
        if(j%2==0)
          pol[i].k[j]=2;
        else
          pol[i].k[j]=5;
      }
  }
}

void OpenglGraph::initializeGL()
{
  qglClearColor(Qt::black);
  glEnable(GL_DEPTH_TEST);
  glShadeModel(GL_FLAT);
  //  glEnable(GL_CULL_FACE) ;
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_COLOR_MATERIAL);


}

void OpenglGraph::resizeGL(int width, int height)
{
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glTranslatef(0.2, 0.0, 0.0);
  GLfloat x = GLfloat(width)/height;
  glFrustum(-x, x, -1.0, 1.0, 4.0, 100.0);
  glMatrixMode(GL_MODELVIEW);
}

void OpenglGraph::paintGL()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(-5, zTra, -15);    // ����������
  glRotatef(xRot, 1.0f, 0.0f, 0.0f); // ������� ������ ��� X
  glRotatef(yRot, 0.0f, 1.0f, 0.0f); // ������� ������ ��� Y
  glRotatef(zRot, 0.0f, 0.0f, 1.0f); // ������� ������ ��� Z
  glScalef(nSca, nSca, nSca);        // ���������������
  glLineWidth(2.0);
  this->drawAxis ();
  glLineWidth(4.0);

}

void OpenglGraph::drawAxis ()
{
  float bb = 1.0/8.0;
  float ll;
  for (int i = 0; i <40*k; i++) // ������� ������������
    {
      //  glColor3f(1.0, bb*(8-i), 0.0);
      glColor3f(255,255, 255);
      glBegin(GL_LINES);
      glVertex3f(-0.5, (i+1)*0.3, 0.0);
      glVertex3f(20.0, (i+1)*0.3, 0.0);
      glEnd();
    }
  for (int i = 0; i < 64; i++)  // ������� ��������������
    {
      glBegin(GL_LINES);
      if ((i+1) % 3 == 0)
        ll = -0.3;
      else
        ll = 0.0;
      glVertex3f((i+1)*0.3, ll, 0.0);
      glVertex3f((i+1)*0.3, 12.0*k, 0.0);
      glEnd();
    }

  bb = 1.0/8.0;   //������� Yz
  for (int i = 0; i < 0; i++)
    {
      // glColor3f((8-i)*bb, 1.0, 0.0);
      glColor3f(255,255, 255);
      glBegin(GL_LINES);
      glVertex3f(0.0, (i+1)*0.3, 0.0);
      glVertex3f(0.0, (i+1)*0.3, 12.0);
      glEnd();
    }
  for (int i = 0; i < 40; i++) {
    glBegin(GL_LINES);
    //   glColor3f(1.0, 1.0, 0.0);
    glColor3f(255,255, 255);
    glVertex3f(0.0, 0.0, (i+1)*0.3);
    //glColor3f(0.0, 1.0, 0.0);
    glColor3f(255,255, 255);
    glVertex3f(0.0, 12.0, (i+1)*0.3);
    glEnd();
  }

  for (int i = 0; i < 64; i++) //Xy
    {
      glBegin(GL_LINES);
      //   glColor3f(0.0, 1.0, 1.0);
      glColor3f(255,255, 255);
      glVertex3f((i+1)*0.3, 0.0, 0.0);
      //    glColor3f(0.0, 0.0, 1.0);
      glColor3f(255,255, 255);
      glVertex3f((i+1)*0.3, 0.0, 12.0);
      glEnd();
    }
  bb = 1.0/8.0;
  for (int i = 0; i < 38; i+=8)  // ������� ������� �����
    {
      qglColor(Qt::green);
      glBegin(GL_QUADS);
      glVertex3f(0.0, 0.0, (i)*0.3);
      glVertex3f(20.0, 0.0, (i)*0.3);
      glVertex3f(20.0, 0.0, (i+4)*0.3);
      glVertex3f(0.0, 0.0, (i+4)*0.3);
      glEnd();
    }
  this->setFont(QFont("Times", 12, QFont::Bold));
  for (int i = 1; i < 38; i+=4)  //������� �����������
    {
      qglColor(Qt::blue);
      this->renderText(-0.5,0,(i+1)*0.3,"�."+ QString::number(i/4 + 1));
    }
  this->setFont(QFont("Times", 14, QFont::Bold));
  for (int i = 0; i <40*k; i+=4) // ������� �����
    {
      qglColor(Qt::magenta);
      this->renderText(-1, (i+1)*0.3, 0.0,"n="+ QString::number(i*10/3));
      glEnd();
    }

  for (int i = 0; i < 40; i++)  //����� xY
    {
      // glColor3f(0.0, (8-i)*bb, 1.0);
      glColor3f(255,255, 255);
      glBegin(GL_LINES);
      glVertex3f(0.0, 0.0, (i+1)*0.3);
      glVertex3f(20.0, 0.0, (i+1)*0.3);
      glEnd();
    }
  qglColor(Qt::cyan);
  glLineWidth(3.0);  // ������
  // glColor3f(255,255, 255);
  glBegin(GL_LINES);
  glVertex3f(0.0, 0.0, 0.0);
  glVertex3f(20.0, 0.0, 0.0);
  glEnd();
  glBegin(GL_LINES);
  glVertex3f(19.8, 0.2, 0.0);
  glVertex3f(20.0, 0.0, 0.0);
  glEnd();
  glBegin(GL_LINES);
  glVertex3f(20.0, 0.0, 0.0);
  glVertex3f(20, -0.2, 0.0);
  glEnd();
  this->renderText(20,0,0,"���");

  //glColor3f(255,255, 255); //������� �����
  glBegin(GL_LINES);
  glVertex3f(0.0, 0.0, 0.0);
  glVertex3f(0.0, 12.0, 0.0);
  glEnd();
  glBegin(GL_LINES);
  glVertex3f(0.0, 11.8, -0.2);
  glVertex3f(0.0, 12.0, 0.0);
  glEnd();
  glBegin(GL_LINES);
  glVertex3f(0.0, 12.0, 0.0);
  glVertex3f(0.0, 12.0, 0.2);
  glEnd();

  this->renderText(-1,0,12,"�������");
  this->renderText(-1,12,0,"ʳ������");
  //glColor3f(255,255, 255);// � ������������
  glBegin(GL_LINES);
  glVertex3f(0.0, 0.0, 0.0);
  glVertex3f(0.0, 0.0, 12.0);
  glEnd();
  glBegin(GL_LINES);
  glVertex3f(-0.2, 0.0, 11.8);
  glVertex3f(0.0, 0.0, 12.0);
  glEnd();
  glBegin(GL_LINES);
  glVertex3f(0.0, 0.0, 12);
  glVertex3f(0.2, 0.0, 11.8);
  glEnd();

  glLineWidth(4.0);
  //glColor4f(0.0, 0.7, 0.1, 0.75);

  int z=0;
  for (int i=0; i < max_cnt-1; i++) {
    z=2;
    for (int j =0; j<10;j++)
      {
        if(j%2==0)
          glColor3f(50,0, 0);
        else
          glColor3f(255,255, 0);

        glBegin(GL_LINES);

        glVertex3f(i*0.1, pol[i].k[j], z*0.3);
        glVertex3f((i+1)*0.1, pol[i+1].k[j], z*0.3);
        glEnd();
        z+=4;
      }





  }

}



void OpenglGraph::mousePressEvent(QMouseEvent *event)
{

  ptrMousePosition = event->pos();
}

void OpenglGraph::mouseMoveEvent(QMouseEvent *pe)
{
  xRot += 180/nSca*(GLfloat)(pe->y()-ptrMousePosition.y())/height(); // ���������� ����� ��������
  yRot += 180/nSca*(GLfloat)(pe->x()-ptrMousePosition.x())/width();
  ptrMousePosition = pe->pos();
  updateGL(); // ���������� �����������

}

void OpenglGraph::wheelEvent (QWheelEvent *pe)
{
  if ((pe->delta())>0) scale_plus();
  else if ((pe->delta())<0) scale_minus();
  updateGL(); // ���������� �����������
}

void OpenglGraph::keyPressEvent (QKeyEvent *pe)
{
  switch (pe->key())
    {
  case Qt::Key_Plus:
      scale_plus();     // ���������� �����
      break;

    case Qt::Key_Equal:
      scale_plus();     // ���������� �����
      break;

    case Qt::Key_Minus:
      scale_minus();    // ��������� �� �����
      break;

    case Qt::Key_Up:
      rotate_up();      // ��������� ����� �����
      break;

    case Qt::Key_Down:
      rotate_down();    // ��������� ����� ����
      break;

    case Qt::Key_Left:
      rotate_left();     // ��������� ����� �����
      break;

    case Qt::Key_Right:
      rotate_right();   // ��������� ����� ������
      break;

    case Qt::Key_Z:
      translate_down(); // ������������� ����� ����
      break;

    case Qt::Key_X:
      translate_up();   // ������������� ����� �����
      break;

    case Qt::Key_Space:  // ������� �������
      defaultScene();   // ����������� �������� �� ���������
      break;

    case Qt::Key_Escape: // ������� "������"
      this->close();    // ��������� ����������
      break;
    }

  updateGL(); // ���������� �����������
}

int r(int max)
{
  return (int)(((float)max)*(rand()/(RAND_MAX+1.0)));
}

void OpenglGraph::genCoords(double k,double m,double *arr)
{
  for (int i=max_cnt-1; i>0; i--) {
    pol[i] = pol[i-1];
  }
  pol[0].x = k;
  pol[0].y = m;
  for(int j=0;j<10;j++)
    {
      pol[0].k[j]=arr[j]*0.3;
      qDebug()<<"n = "<< pol[0].k[j] << "k = "<<this->k*12;
      if (pol[0].k[j] >this->k*12)
        {
            this->k = pol[0].k[j]/12.0 +0.05;

        }
    }
  updateGL();
}

void OpenglGraph::scale_plus() // ���������� �����
{
  nSca = nSca*1.1;
}

void OpenglGraph::scale_minus() // ��������� �� �����
{
  nSca = nSca/1.1;
}


void OpenglGraph::rotate_up() // ��������� ����� �����
{
  xRot += 1.0;
}

void OpenglGraph::rotate_down() // ��������� ����� ����
{
  xRot -= 1.0;
}

void OpenglGraph::rotate_left() // ��������� ����� �����
{
  zRot += 1.0;
}

void OpenglGraph::rotate_right() // ��������� ����� ������
{
  zRot -= 1.0;
}

void OpenglGraph::translate_down() // ������������� ����� ����
{
  zTra -= 0.05;
}

void OpenglGraph::translate_up() // ������������� ����� �����
{
  zTra += 0.05;
}

void OpenglGraph::defaultScene() // ���������� ����� �� ���������
{

  xRot=0; yRot=0; zRot=0; zTra=-2; nSca=1;
}
