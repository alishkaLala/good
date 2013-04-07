/********************************************************************************
** Form generated from reading UI file 'settingmainframes.ui'
**
** Created: Sun 7. Apr 13:15:14 2013
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGMAINFRAMES_H
#define UI_SETTINGMAINFRAMES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingMainFrames
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_11;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QCheckBox *checkBox_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QPushButton *pushButton_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QPushButton *pushButton_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QPushButton *pushButton_7;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QPushButton *pushButton_8;
    QVBoxLayout *verticalLayout_3;
    QPushButton *SaveSetting;
    QPushButton *CanselSetting;
    QPushButton *Standart;

    void setupUi(QWidget *SettingMainFrames)
    {
        if (SettingMainFrames->objectName().isEmpty())
            SettingMainFrames->setObjectName(QString::fromUtf8("SettingMainFrames"));
        SettingMainFrames->resize(417, 318);
        gridLayout_2 = new QGridLayout(SettingMainFrames);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox_2 = new QGroupBox(SettingMainFrames);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_2 = new QLineEdit(groupBox_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEchoMode(QLineEdit::Normal);
        lineEdit_2->setReadOnly(true);

        horizontalLayout->addWidget(lineEdit_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout_4->addWidget(pushButton_3);

        pushButton_11 = new QPushButton(groupBox_2);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));

        verticalLayout_4->addWidget(pushButton_11);


        horizontalLayout->addLayout(verticalLayout_4);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        checkBox_2 = new QCheckBox(groupBox_2);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        gridLayout->addWidget(checkBox_2, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);


        gridLayout_2->addWidget(groupBox_2, 0, 0, 1, 2);

        groupBox = new QGroupBox(SettingMainFrames);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        horizontalLayout_5->addWidget(pushButton_5);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        pushButton_6 = new QPushButton(groupBox);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        horizontalLayout_6->addWidget(pushButton_6);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_7->addWidget(label_7);

        pushButton_7 = new QPushButton(groupBox);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        horizontalLayout_7->addWidget(pushButton_7);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_8->addWidget(label_8);

        pushButton_8 = new QPushButton(groupBox);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        horizontalLayout_8->addWidget(pushButton_8);


        verticalLayout_2->addLayout(horizontalLayout_8);


        gridLayout_2->addWidget(groupBox, 1, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        SaveSetting = new QPushButton(SettingMainFrames);
        SaveSetting->setObjectName(QString::fromUtf8("SaveSetting"));

        verticalLayout_3->addWidget(SaveSetting);

        CanselSetting = new QPushButton(SettingMainFrames);
        CanselSetting->setObjectName(QString::fromUtf8("CanselSetting"));

        verticalLayout_3->addWidget(CanselSetting);

        Standart = new QPushButton(SettingMainFrames);
        Standart->setObjectName(QString::fromUtf8("Standart"));

        verticalLayout_3->addWidget(Standart);


        gridLayout_2->addLayout(verticalLayout_3, 1, 1, 1, 1);


        retranslateUi(SettingMainFrames);

        QMetaObject::connectSlotsByName(SettingMainFrames);
    } // setupUi

    void retranslateUi(QWidget *SettingMainFrames)
    {
        SettingMainFrames->setWindowTitle(QApplication::translate("SettingMainFrames", "Form", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("SettingMainFrames", "file setting", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SettingMainFrames", "\320\244\320\260\320\271\320\273 \321\226\320\274\320\277\320\276\321\200\321\202\321\203", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("SettingMainFrames", "\320\276\320\261\321\200\320\260\321\202\320\270", 0, QApplication::UnicodeUTF8));
        pushButton_11->setText(QApplication::translate("SettingMainFrames", "\321\201\321\202\320\262\320\276\321\200\320\270\321\202\320\270", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SettingMainFrames", "\320\227\320\260\320\277\320\270\321\201\321\203\320\262\320\260\321\202\320\270 \320\264\320\260\321\202\321\203 \320\275\320\260 \320\277\320\276\321\207\320\260\321\202\320\272\321\203 \321\204\320\260\320\271\320\273\321\203", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("SettingMainFrames", "\320\242\320\260\320\272", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("SettingMainFrames", "Colors", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("SettingMainFrames", "\320\272\320\276\320\273\321\226\321\200 \321\202\320\265\320\272\321\201\321\202\321\203", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("SettingMainFrames", "\320\276\320\261\321\200\320\260\321\202\320\270", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("SettingMainFrames", "\320\272\320\276\320\273\321\226\321\200 \321\204\320\276\321\200\320\274\320\270", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("SettingMainFrames", "\320\276\320\261\321\200\320\260\321\202\320\270", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("SettingMainFrames", "\320\272\320\276\320\273\321\226\321\200 \320\272\320\275\320\276\320\277\320\272\320\270", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("SettingMainFrames", "\320\276\320\261\321\200\320\260\321\202\320\270", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("SettingMainFrames", "\320\272\320\276\320\273\321\226\321\200 \321\202\320\265\320\272\321\201\321\202\321\203 \320\272\320\275\320\276\320\272\320\270", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("SettingMainFrames", "\320\276\320\261\321\200\320\260\321\202\320\270", 0, QApplication::UnicodeUTF8));
        SaveSetting->setText(QApplication::translate("SettingMainFrames", "\320\227\320\261\320\265\321\200\320\265\320\263\321\202\320\270", 0, QApplication::UnicodeUTF8));
        CanselSetting->setText(QApplication::translate("SettingMainFrames", "\320\222\321\226\320\264\320\274\321\226\320\275\320\270\321\202\320\270", 0, QApplication::UnicodeUTF8));
        Standart->setText(QApplication::translate("SettingMainFrames", "\320\237\320\276 \320\267\320\260\320\274\320\276\320\262\321\207\321\203\320\262\320\260\320\275\320\275\321\216", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SettingMainFrames: public Ui_SettingMainFrames {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGMAINFRAMES_H
