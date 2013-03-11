#include "infoframe.h"
#include "ui_infoframe.h"

InfoFrame::InfoFrame(QWidget *parent) :
    QWidget(0),
    ui(new Ui::InfoFrame)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(close()));
    p= parent;

}

InfoFrame::~InfoFrame()
{
    delete ui;
}
void InfoFrame::destroyThis(){
    destroy();
}
void InfoFrame::showEvent(QShowEvent *event)
{

}

void InfoFrame::closeEvent(QCloseEvent *event)
{
        p->show ();
}

void InfoFrame::on_pushButton_clicked()
{

}
