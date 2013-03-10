/********************************************************************************
** Form generated from reading UI file 'testingframe.ui'
**
** Created: Sun 10. Mar 18:01:47 2013
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTINGFRAME_H
#define UI_TESTINGFRAME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_testingFrame
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *spinBox;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QProgressBar *progressBar;
    QPushButton *pushButton;
    QLabel *label_5;

    void setupUi(QWidget *testingFrame)
    {
        if (testingFrame->objectName().isEmpty())
            testingFrame->setObjectName(QString::fromUtf8("testingFrame"));
        testingFrame->resize(582, 318);
        gridLayout = new QGridLayout(testingFrame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame = new QFrame(testingFrame);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(frame);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout_2->addWidget(label_3);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        spinBox = new QSpinBox(frame);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(1);
        spinBox->setValue(1);

        horizontalLayout_2->addWidget(spinBox);


        verticalLayout->addLayout(horizontalLayout_2);

        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setEnabled(false);

        verticalLayout->addWidget(pushButton_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        progressBar = new QProgressBar(frame);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(100);

        horizontalLayout_3->addWidget(progressBar);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_3->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addWidget(frame, 0, 0, 1, 1);

        label_5 = new QLabel(testingFrame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(300, 300));
        label_5->setFrameShape(QFrame::Box);
        label_5->setFrameShadow(QFrame::Sunken);
        label_5->setLineWidth(4);
        label_5->setMidLineWidth(4);
        label_5->setText(QString::fromUtf8(""));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/image/4x.jpg")));
        label_5->setScaledContents(true);

        gridLayout->addWidget(label_5, 0, 1, 1, 1);


        retranslateUi(testingFrame);

        QMetaObject::connectSlotsByName(testingFrame);
    } // setupUi

    void retranslateUi(QWidget *testingFrame)
    {
        testingFrame->setWindowTitle(QApplication::translate("testingFrame", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("testingFrame", "\342\204\226 \320\272\320\260\320\274\320\265\321\200\320\270", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("testingFrame", "\320\247\320\260\321\201 \321\202\320\265\321\201\321\202\321\203\320\262\320\260\320\275\320\275\321\217", 0, QApplication::UnicodeUTF8));
        label_4->setText(QString());
        pushButton_2->setText(QApplication::translate("testingFrame", "\320\267\321\203\320\277\320\270\320\275\320\270\321\202\320\270(\320\261\320\265\320\267 \320\267\320\261\320\265\321\200\320\265\320\266\320\265\320\275\320\275\321\217 \320\267\320\274\321\226\320\275)", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("testingFrame", "\321\200\320\276\320\267\320\277\320\276\321\207\320\260\321\202\320\270", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class testingFrame: public Ui_testingFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTINGFRAME_H
