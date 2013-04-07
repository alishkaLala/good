/********************************************************************************
** Form generated from reading UI file 'settingcaptureframe.ui'
**
** Created: Sun 7. Apr 13:15:14 2013
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGCAPTUREFRAME_H
#define UI_SETTINGCAPTUREFRAME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingCaptureFrame
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QSpinBox *widthCaptureWindow;
    QPushButton *buttonSizeApply;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QPushButton *buttonSetROI;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *buttonSetDistance;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLabel *pixels;
    QLabel *label_13;
    QVBoxLayout *verticalLayout_5;
    QPushButton *buttonRestartTrySet;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_4;
    QLabel *label_15;
    QLabel *labelX1;
    QLabel *labelY1;
    QLabel *label_16;
    QLabel *labelX2;
    QLabel *labelY2;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label;
    QSpinBox *spinBox;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QLabel *label_14;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_2;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_2;
    QPushButton *SettingApply;
    QPushButton *SettingCansel;
    QPushButton *SettingStandart;

    void setupUi(QWidget *SettingCaptureFrame)
    {
        if (SettingCaptureFrame->objectName().isEmpty())
            SettingCaptureFrame->setObjectName(QString::fromUtf8("SettingCaptureFrame"));
        SettingCaptureFrame->resize(481, 425);
        gridLayout = new QGridLayout(SettingCaptureFrame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBox_3 = new QGroupBox(SettingCaptureFrame);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        QFont font;
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        groupBox_3->setFont(font);
        horizontalLayout_3 = new QHBoxLayout(groupBox_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_3->addWidget(label_5);

        widthCaptureWindow = new QSpinBox(groupBox_3);
        widthCaptureWindow->setObjectName(QString::fromUtf8("widthCaptureWindow"));

        horizontalLayout_3->addWidget(widthCaptureWindow);

        buttonSizeApply = new QPushButton(groupBox_3);
        buttonSizeApply->setObjectName(QString::fromUtf8("buttonSizeApply"));

        horizontalLayout_3->addWidget(buttonSizeApply);


        verticalLayout_4->addWidget(groupBox_3);

        groupBox = new QGroupBox(SettingCaptureFrame);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        buttonSetROI = new QPushButton(groupBox);
        buttonSetROI->setObjectName(QString::fromUtf8("buttonSetROI"));

        verticalLayout->addWidget(buttonSetROI);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout->addWidget(label_7);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout->addWidget(label_8);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout->addWidget(label_9);


        verticalLayout_4->addWidget(groupBox);

        groupBox_2 = new QGroupBox(SettingCaptureFrame);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        buttonSetDistance = new QPushButton(groupBox_2);
        buttonSetDistance->setObjectName(QString::fromUtf8("buttonSetDistance"));

        verticalLayout_3->addWidget(buttonSetDistance);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_3->addWidget(label_11);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_3->addWidget(label_12);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_3->addWidget(label_10);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        pixels = new QLabel(groupBox_2);
        pixels->setObjectName(QString::fromUtf8("pixels"));

        horizontalLayout_2->addWidget(pixels);


        verticalLayout_3->addLayout(horizontalLayout_2);

        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_13->setFont(font1);

        verticalLayout_3->addWidget(label_13);


        verticalLayout_4->addWidget(groupBox_2);


        gridLayout->addLayout(verticalLayout_4, 0, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        buttonRestartTrySet = new QPushButton(SettingCaptureFrame);
        buttonRestartTrySet->setObjectName(QString::fromUtf8("buttonRestartTrySet"));

        verticalLayout_5->addWidget(buttonRestartTrySet);

        pushButton_2 = new QPushButton(SettingCaptureFrame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout_5->addWidget(pushButton_2);

        groupBox_6 = new QGroupBox(SettingCaptureFrame);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        gridLayout_4 = new QGridLayout(groupBox_6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_15 = new QLabel(groupBox_6);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_4->addWidget(label_15, 0, 0, 1, 1);

        labelX1 = new QLabel(groupBox_6);
        labelX1->setObjectName(QString::fromUtf8("labelX1"));

        gridLayout_4->addWidget(labelX1, 0, 1, 1, 1);

        labelY1 = new QLabel(groupBox_6);
        labelY1->setObjectName(QString::fromUtf8("labelY1"));

        gridLayout_4->addWidget(labelY1, 0, 2, 1, 1);

        label_16 = new QLabel(groupBox_6);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_4->addWidget(label_16, 1, 0, 1, 1);

        labelX2 = new QLabel(groupBox_6);
        labelX2->setObjectName(QString::fromUtf8("labelX2"));

        gridLayout_4->addWidget(labelX2, 1, 1, 1, 1);

        labelY2 = new QLabel(groupBox_6);
        labelY2->setObjectName(QString::fromUtf8("labelY2"));

        gridLayout_4->addWidget(labelY2, 1, 2, 1, 1);


        verticalLayout_5->addWidget(groupBox_6);

        groupBox_5 = new QGroupBox(SettingCaptureFrame);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_3 = new QGridLayout(groupBox_5);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_2 = new QLabel(groupBox_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 0, 0, 1, 1);

        lineEdit = new QLineEdit(groupBox_5);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_3->addWidget(lineEdit, 0, 1, 1, 1);

        label = new QLabel(groupBox_5);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 1, 0, 1, 1);

        spinBox = new QSpinBox(groupBox_5);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        gridLayout_3->addWidget(spinBox, 1, 1, 1, 1);


        verticalLayout_5->addWidget(groupBox_5);

        frame = new QFrame(SettingCaptureFrame);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_14 = new QLabel(frame);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_2->addWidget(label_14, 1, 0, 1, 4);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(frame);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setDecimals(3);
        doubleSpinBox->setMaximum(3);
        doubleSpinBox->setSingleStep(0.001);
        doubleSpinBox->setValue(0.03);

        gridLayout_2->addWidget(doubleSpinBox, 2, 1, 1, 1);

        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 2, 2, 1, 1);

        doubleSpinBox_2 = new QDoubleSpinBox(frame);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setDecimals(3);
        doubleSpinBox_2->setMaximum(3);
        doubleSpinBox_2->setSingleStep(0.001);
        doubleSpinBox_2->setValue(0.75);

        gridLayout_2->addWidget(doubleSpinBox_2, 2, 3, 1, 1);


        verticalLayout_5->addWidget(frame);

        groupBox_4 = new QGroupBox(SettingCaptureFrame);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_2 = new QVBoxLayout(groupBox_4);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        SettingApply = new QPushButton(groupBox_4);
        SettingApply->setObjectName(QString::fromUtf8("SettingApply"));

        verticalLayout_2->addWidget(SettingApply);

        SettingCansel = new QPushButton(groupBox_4);
        SettingCansel->setObjectName(QString::fromUtf8("SettingCansel"));

        verticalLayout_2->addWidget(SettingCansel);

        SettingStandart = new QPushButton(groupBox_4);
        SettingStandart->setObjectName(QString::fromUtf8("SettingStandart"));

        verticalLayout_2->addWidget(SettingStandart);


        verticalLayout_5->addWidget(groupBox_4);


        gridLayout->addLayout(verticalLayout_5, 0, 1, 1, 1);


        retranslateUi(SettingCaptureFrame);

        QMetaObject::connectSlotsByName(SettingCaptureFrame);
    } // setupUi

    void retranslateUi(QWidget *SettingCaptureFrame)
    {
        SettingCaptureFrame->setWindowTitle(QApplication::translate("SettingCaptureFrame", "Form", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("SettingCaptureFrame", "\320\225\321\202\320\260\320\277 1:\320\262\320\270\320\267\320\275\320\260\321\207\320\265\320\275\320\275\321\217  \321\200\320\276\320\267\320\274\321\226\321\200\321\203", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("SettingCaptureFrame", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261", 0, QApplication::UnicodeUTF8));
        buttonSizeApply->setText(QApplication::translate("SettingCaptureFrame", "\320\267\320\260\321\201\321\202\320\276\321\201\321\203\320\262\320\260\321\202\320\270", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("SettingCaptureFrame", "\320\225\321\202\320\260\320\277 2: \320\262\320\270\320\267\320\275\320\260\321\207\320\265\320\275\320\275\321\217 \320\275\320\265\320\276\320\261\321\205\321\226\320\264\320\275\320\276\321\227 \320\276\320\261\320\273\320\260\321\201\321\202\321\226", 0, QApplication::UnicodeUTF8));
        buttonSetROI->setText(QApplication::translate("SettingCaptureFrame", "\320\262\320\270\320\267\320\275\320\260\321\207\320\270\321\202\320\270 \320\275\320\265\320\276\320\261\321\205\321\226\320\264\320\275\321\203 \320\276\320\261\320\273\320\260\321\201\321\202\321\214 \320\272\320\260\320\274\320\265\321\200\320\270", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("SettingCaptureFrame", "1) \320\235\320\260\321\202\320\270\321\201\320\275\321\226\321\202\321\214 \320\273\321\226\320\262\321\203 \320\272\320\273\320\260\320\262\321\226\321\210\321\203 \320\274\320\270\321\210\321\226 \n"
"\321\203 \320\262\320\265\321\205\320\275\321\214\320\274\321\203 \320\273\321\226\320\262\320\276\320\274\321\203 \320\272\321\203\321\202\321\226 ", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("SettingCaptureFrame", "2)\320\235\320\260\321\202\320\270\321\201\320\275\321\226\321\202\321\214 \320\277\321\200\320\260\320\262\321\203 \320\272\320\273\320\260\320\262\321\226\321\210\321\203 \320\274\320\270\321\210\321\226 \n"
" \321\203 \320\275\320\270\320\266\320\275\321\214\320\276\320\274\321\203 \320\277\321\200\320\260\320\262\320\276\320\274\321\203 \320\272\321\203\321\202\321\226 ", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("SettingCaptureFrame", "3) \320\267\320\274\321\226\320\275\320\270 \320\261\321\203\320\264\321\203\321\202\321\214 \320\262\320\275\320\265\321\201\320\265\320\275\321\226 \320\260\320\262\321\202\320\276\320\274\320\260\321\202\320\270\321\207\320\275\320\276", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("SettingCaptureFrame", "\320\225\321\202\320\260\320\277 3 : \320\262\320\270\320\267\320\275\320\260\321\207\320\265\320\275\320\275\321\217 \320\277\321\226\320\272\321\201\320\265\320\273\321\226\320\262", 0, QApplication::UnicodeUTF8));
        buttonSetDistance->setText(QApplication::translate("SettingCaptureFrame", "\320\262\320\270\320\267\320\275\320\260\321\207\320\270\321\202\320\270 \320\272\321\226\320\273\321\214\320\272\321\226\321\201\321\202\321\214 \320\277\321\226\320\272\321\201\320\265\320\273\321\226\320\262", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("SettingCaptureFrame", "1) \320\235\320\260\321\202\320\270\321\201\320\275\321\226\321\202\321\214 \320\273\321\226\320\262\321\203 \320\272\320\273\320\260\320\262\321\226\321\210\321\203 \320\274\320\270\321\210\321\226 \n"
" \320\275\320\260 \320\277\320\276\321\207\320\260\321\202\320\272\321\203 \320\262\321\226\320\264\320\273\321\226\320\272\321\203", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("SettingCaptureFrame", "2)\320\235\320\260\321\202\320\270\321\201\320\275\321\226\321\202\321\214 \320\277\321\200\320\260\320\262\321\203 \320\272\320\273\320\260\320\262\321\226\321\210\321\203 \320\274\320\270\321\210\321\226 \n"
" \320\275\320\260\320\277\321\200\320\270\320\272\321\226\320\275\321\206\321\226 \320\262\321\226\320\264\320\273\321\226\320\272\321\203", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("SettingCaptureFrame", "3)\320\237\320\265\321\200\320\265\321\200\320\260\321\205\321\203\320\275\320\276\320\272 \320\261\321\203\320\264\320\265 \320\267\320\264\321\226\321\201\320\275\320\265\320\275\320\270\320\271 \320\260\320\262\321\202\320\276\320\274\320\260\321\202\320\270\321\207\320\275\320\276", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("SettingCaptureFrame", "\320\272\321\226\320\273\321\214\320\272\321\226\321\201\321\202\321\214 \320\277\321\226\320\272\321\201\320\265\320\273\321\226\320\262 ", 0, QApplication::UnicodeUTF8));
        pixels->setText(QApplication::translate("SettingCaptureFrame", "53748757", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("SettingCaptureFrame", "\320\243\320\262\320\260\320\263\320\260! \320\237\321\200\320\270 \320\267\320\274\321\226\320\275\321\226 \321\200\320\276\320\267\320\274\321\226\321\200\321\203 \320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\275\321\217 \n"
" \320\275\320\265\320\276\320\261\321\205\321\226\320\264\320\275\320\276 \320\277\320\265\321\200\320\265\320\275\320\260\320\273\320\260\321\210\321\202\321\203\320\262\320\260\321\202\320\270!", 0, QApplication::UnicodeUTF8));
        buttonRestartTrySet->setText(QApplication::translate("SettingCaptureFrame", "\320\240\320\276\320\267\320\277\320\260\321\207\320\260\321\202\320\270 \321\201\320\277\320\276\321\207\320\260\321\202\320\272\321\203", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("SettingCaptureFrame", "\320\262\320\270\320\274\320\272\320\275\321\203\321\202\320\270 \321\200\320\276\320\267\320\274\321\226\321\202\320\272\321\203 \320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\275\321\217", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("SettingCaptureFrame", "\320\232\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\320\270", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("SettingCaptureFrame", "\320\233\321\226\320\262\320\260 \320\272\320\273\320\260\320\262\321\226\321\210\320\260 \320\274\320\270\321\210\321\226", 0, QApplication::UnicodeUTF8));
        labelX1->setText(QApplication::translate("SettingCaptureFrame", "x1=", 0, QApplication::UnicodeUTF8));
        labelY1->setText(QApplication::translate("SettingCaptureFrame", "y1=", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("SettingCaptureFrame", "\320\237\321\200\320\260\320\262\320\260 \320\272\320\273\320\260\320\262\321\226\321\210\320\260 \320\274\320\270\321\210\321\226", 0, QApplication::UnicodeUTF8));
        labelX2->setText(QApplication::translate("SettingCaptureFrame", "x2=", 0, QApplication::UnicodeUTF8));
        labelY2->setText(QApplication::translate("SettingCaptureFrame", "y2=", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QString());
        label_2->setText(QApplication::translate("SettingCaptureFrame", "\320\272\321\226\320\273\321\214\320\272\321\226\321\201\321\202\321\214 \320\274\321\226\320\273\321\226\320\274\320\265\321\202\321\200\321\226\320\262", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SettingCaptureFrame", "\320\267\320\260\321\202\321\200\320\274\320\272\320\260 \320\267\320\260\321\205\320\276\320\277\320\273\320\265\320\275\320\275 \320\272\320\260\320\264\321\200\321\203", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("SettingCaptureFrame", "\320\232\320\276\320\276\321\204\321\226\321\206\321\226\321\224\320\275\321\202\320\270 \320\264\320\273\321\217 \321\200\320\276\320\267\321\200\320\260\321\205\321\203\320\275\320\272\321\226\320\262", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SettingCaptureFrame", "k1=", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("SettingCaptureFrame", "k2=", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QString());
        SettingApply->setText(QApplication::translate("SettingCaptureFrame", "\320\267\320\260\321\201\321\202\320\276\321\201\321\203\320\262\320\260\321\202\320\270 \320\275\320\260\320\273\320\260\321\210\321\202\321\203\320\262\320\260\320\275\320\275\321\217", 0, QApplication::UnicodeUTF8));
        SettingCansel->setText(QApplication::translate("SettingCaptureFrame", "\320\262\321\226\320\264\320\274\321\226\320\275\320\270\321\202\320\270 \320\275\320\260\320\273\320\260\321\210\321\202\321\203\320\262\320\260\320\275\320\275\321\217", 0, QApplication::UnicodeUTF8));
        SettingStandart->setText(QApplication::translate("SettingCaptureFrame", "\320\277\320\276 \320\267\320\260\320\274\320\276\320\262\321\207\321\203\320\262\320\260\320\275\320\275\321\216", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SettingCaptureFrame: public Ui_SettingCaptureFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGCAPTUREFRAME_H
