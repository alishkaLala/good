#include "testingframe.h"
#include "ui_testingframe.h"

testingFrame::testingFrame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::testingFrame)
{
    ui->setupUi(this);
}

testingFrame::~testingFrame()
{
    delete ui;
}

void testingFrame::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
