/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun 7. Apr 13:15:14 2013
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionHelper;
    QAction *actionDisable_capture;
    QAction *actionConfiguration_of_program;
    QAction *actionConfiguration_of_capture;
    QAction *actionOf_export;
    QAction *actionStart_testing;
    QAction *actionTo_fail;
    QAction *actionTo_graphik;
    QAction *actionPrint;
    QAction *actionInformation;
    QAction *action1;
    QAction *actionHide_capture;
    QAction *actionShow_capture;
    QAction *actionShowFile;
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QLabel *capturePicture;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QSlider *horizontalSlider;
    QSpinBox *spinBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QComboBox *comboBox;
    QPushButton *buttonCaptureStart;
    QCheckBox *processingImageShow;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QPushButton *buttonAnalizStop;
    QProgressBar *progressBar;
    QPushButton *buttonAnalizStart;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuExport;
    QMenu *menuCapture;
    QMenu *menuChoise_capture;
    QMenu *menuSetting;
    QMenu *menuInformation;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(661, 391);
        actionHelper = new QAction(MainWindow);
        actionHelper->setObjectName(QString::fromUtf8("actionHelper"));
        actionDisable_capture = new QAction(MainWindow);
        actionDisable_capture->setObjectName(QString::fromUtf8("actionDisable_capture"));
        actionConfiguration_of_program = new QAction(MainWindow);
        actionConfiguration_of_program->setObjectName(QString::fromUtf8("actionConfiguration_of_program"));
        actionConfiguration_of_capture = new QAction(MainWindow);
        actionConfiguration_of_capture->setObjectName(QString::fromUtf8("actionConfiguration_of_capture"));
        actionOf_export = new QAction(MainWindow);
        actionOf_export->setObjectName(QString::fromUtf8("actionOf_export"));
        actionStart_testing = new QAction(MainWindow);
        actionStart_testing->setObjectName(QString::fromUtf8("actionStart_testing"));
        actionTo_fail = new QAction(MainWindow);
        actionTo_fail->setObjectName(QString::fromUtf8("actionTo_fail"));
        actionTo_graphik = new QAction(MainWindow);
        actionTo_graphik->setObjectName(QString::fromUtf8("actionTo_graphik"));
        actionPrint = new QAction(MainWindow);
        actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
        actionInformation = new QAction(MainWindow);
        actionInformation->setObjectName(QString::fromUtf8("actionInformation"));
        action1 = new QAction(MainWindow);
        action1->setObjectName(QString::fromUtf8("action1"));
        actionHide_capture = new QAction(MainWindow);
        actionHide_capture->setObjectName(QString::fromUtf8("actionHide_capture"));
        actionShow_capture = new QAction(MainWindow);
        actionShow_capture->setObjectName(QString::fromUtf8("actionShow_capture"));
        actionShowFile = new QAction(MainWindow);
        actionShowFile->setObjectName(QString::fromUtf8("actionShowFile"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        capturePicture = new QLabel(centralWidget);
        capturePicture->setObjectName(QString::fromUtf8("capturePicture"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(50);
        sizePolicy.setVerticalStretch(100);
        sizePolicy.setHeightForWidth(capturePicture->sizePolicy().hasHeightForWidth());
        capturePicture->setSizePolicy(sizePolicy);
        capturePicture->setMinimumSize(QSize(300, 300));
        capturePicture->setMaximumSize(QSize(16777215, 16777215));
        capturePicture->setFrameShape(QFrame::WinPanel);
        capturePicture->setScaledContents(true);

        gridLayout_4->addWidget(capturePicture, 0, 1, 4, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(500, 16777215));
        groupBox_2->setFlat(false);
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSlider = new QSlider(groupBox_2);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSlider);

        spinBox = new QSpinBox(groupBox_2);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_2->addWidget(spinBox);


        gridLayout_3->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_3->addWidget(label_6);

        comboBox = new QComboBox(groupBox_2);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_3->addWidget(comboBox);

        buttonCaptureStart = new QPushButton(groupBox_2);
        buttonCaptureStart->setObjectName(QString::fromUtf8("buttonCaptureStart"));

        horizontalLayout_3->addWidget(buttonCaptureStart);


        gridLayout_3->addLayout(horizontalLayout_3, 3, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 1, 0, 1, 1);

        processingImageShow = new QCheckBox(centralWidget);
        processingImageShow->setObjectName(QString::fromUtf8("processingImageShow"));

        gridLayout_4->addWidget(processingImageShow, 2, 0, 1, 1);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setEnabled(false);
        frame->setFrameShape(QFrame::WinPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        buttonAnalizStop = new QPushButton(frame);
        buttonAnalizStop->setObjectName(QString::fromUtf8("buttonAnalizStop"));

        gridLayout_2->addWidget(buttonAnalizStop, 0, 1, 1, 1);

        progressBar = new QProgressBar(frame);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(100);

        gridLayout_2->addWidget(progressBar, 1, 0, 1, 2);

        buttonAnalizStart = new QPushButton(frame);
        buttonAnalizStart->setObjectName(QString::fromUtf8("buttonAnalizStart"));

        gridLayout_2->addWidget(buttonAnalizStart, 0, 0, 1, 1);


        gridLayout_4->addWidget(frame, 3, 0, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QFont font;
        font.setPointSize(10);
        groupBox->setFont(font);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 661, 18));
        menuExport = new QMenu(menuBar);
        menuExport->setObjectName(QString::fromUtf8("menuExport"));
        menuCapture = new QMenu(menuBar);
        menuCapture->setObjectName(QString::fromUtf8("menuCapture"));
        menuChoise_capture = new QMenu(menuCapture);
        menuChoise_capture->setObjectName(QString::fromUtf8("menuChoise_capture"));
        menuSetting = new QMenu(menuBar);
        menuSetting->setObjectName(QString::fromUtf8("menuSetting"));
        menuInformation = new QMenu(menuBar);
        menuInformation->setObjectName(QString::fromUtf8("menuInformation"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuCapture->menuAction());
        menuBar->addAction(menuExport->menuAction());
        menuBar->addAction(menuSetting->menuAction());
        menuBar->addAction(menuInformation->menuAction());
        menuExport->addAction(actionTo_fail);
        menuExport->addAction(actionTo_graphik);
        menuExport->addSeparator();
        menuExport->addAction(actionShowFile);
        menuCapture->addAction(menuChoise_capture->menuAction());
        menuCapture->addSeparator();
        menuCapture->addAction(actionDisable_capture);
        menuCapture->addSeparator();
        menuCapture->addAction(actionHide_capture);
        menuCapture->addAction(actionShow_capture);
        menuChoise_capture->addAction(action1);
        menuSetting->addAction(actionConfiguration_of_program);
        menuSetting->addAction(actionConfiguration_of_capture);
        menuSetting->addSeparator();
        menuSetting->addAction(actionStart_testing);
        menuInformation->addAction(actionHelper);
        menuInformation->addAction(actionInformation);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionHelper->setText(QApplication::translate("MainWindow", "\320\264\320\276\320\277\320\276\320\274\320\276\320\263\320\260", 0, QApplication::UnicodeUTF8));
        actionDisable_capture->setText(QApplication::translate("MainWindow", "\320\262\320\270\320\274\320\272\320\275\321\203\321\202\320\270 \320\272\320\260\320\274\320\265\321\200\321\203", 0, QApplication::UnicodeUTF8));
        actionConfiguration_of_program->setText(QApplication::translate("MainWindow", "\320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\270...", 0, QApplication::UnicodeUTF8));
        actionConfiguration_of_capture->setText(QApplication::translate("MainWindow", "\320\272\320\260\320\274\320\265\321\200\320\270... ", 0, QApplication::UnicodeUTF8));
        actionOf_export->setText(QApplication::translate("MainWindow", "of export", 0, QApplication::UnicodeUTF8));
        actionStart_testing->setText(QApplication::translate("MainWindow", "\321\200\320\276\320\267\320\277\320\276\321\207\320\260\321\202\320\270 \321\202\320\265\321\201\321\202\321\203\320\262\320\260\320\275\320\275\321\217..", 0, QApplication::UnicodeUTF8));
        actionTo_fail->setText(QApplication::translate("MainWindow", "\320\264\320\276 \321\204\320\260\320\271\320\273\321\203", 0, QApplication::UnicodeUTF8));
        actionTo_graphik->setText(QApplication::translate("MainWindow", "\320\264\320\276 \320\263\321\200\320\260\321\204\321\226\320\272\321\203", 0, QApplication::UnicodeUTF8));
        actionPrint->setText(QApplication::translate("MainWindow", "print ", 0, QApplication::UnicodeUTF8));
        actionInformation->setText(QApplication::translate("MainWindow", "\321\226\320\275\321\204\320\276\321\200\320\274\320\260\321\206\321\226\321\217", 0, QApplication::UnicodeUTF8));
        action1->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        actionHide_capture->setText(QApplication::translate("MainWindow", "\320\275\320\265 \320\277\320\276\320\272\320\260\320\267\321\203\320\262\320\260\321\202\320\270 \320\272\320\260\320\274\320\265\321\200\321\203", 0, QApplication::UnicodeUTF8));
        actionShow_capture->setText(QApplication::translate("MainWindow", "\320\277\320\276\320\272\320\260\320\267\321\203\320\262\320\260\321\202\320\270 \320\272\320\260\320\274\320\265\321\200\321\203", 0, QApplication::UnicodeUTF8));
        actionShowFile->setText(QApplication::translate("MainWindow", "\320\277\320\276\320\272\320\260\320\267\320\260\321\202\320\270 \321\204\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
        capturePicture->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QString());
        label_6->setText(QApplication::translate("MainWindow", "\320\272\320\260\320\274\320\265\321\200\320\260 \342\204\226", 0, QApplication::UnicodeUTF8));
        buttonCaptureStart->setText(QApplication::translate("MainWindow", "\320\267\320\260\320\277\321\203\321\201\321\202\320\270\321\202\320\270 \321\202\320\260 \320\277\320\265\321\200\320\265\320\262\321\226\321\200\320\270\321\202\320\270 \320\272\320\260\320\274\320\265\321\200\321\203", 0, QApplication::UnicodeUTF8));
        processingImageShow->setText(QApplication::translate("MainWindow", "\320\262\320\270\320\262\320\276\320\264\320\270  \320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\275\321\217, \321\211\320\276 \320\276\320\261\321\200\320\276\320\261\320\273\321\217\321\224\321\202\321\214\321\201\321\217", 0, QApplication::UnicodeUTF8));
        buttonAnalizStop->setText(QApplication::translate("MainWindow", "\320\267\321\203\320\277\320\270\320\275\320\270\321\202\320\270 \320\260\320\275\320\260\320\273\321\226\320\267", 0, QApplication::UnicodeUTF8));
        buttonAnalizStart->setText(QApplication::translate("MainWindow", "\321\200\320\276\320\267\320\277\320\276\321\207\320\260\321\202\320\270 \320\260\320\275\320\260\320\273\321\226\320\267", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\206\320\275\321\204\320\276\321\200\320\274\320\260\321\206\321\226\321\217", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        menuExport->setTitle(QApplication::translate("MainWindow", "\320\225\320\272\321\201\320\277\320\276\321\200\321\202", 0, QApplication::UnicodeUTF8));
        menuCapture->setTitle(QApplication::translate("MainWindow", "\320\232\320\260\320\274\320\265\321\200\320\260", 0, QApplication::UnicodeUTF8));
        menuChoise_capture->setTitle(QApplication::translate("MainWindow", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\277\321\226\320\264\320\272\321\216\321\207\320\265\320\275\320\270\321\205 \320\272\320\260\320\274\320\265\321\200", 0, QApplication::UnicodeUTF8));
        menuSetting->setTitle(QApplication::translate("MainWindow", "\320\235\320\260\320\273\320\260\321\210\321\202\321\203\320\262\320\260\320\275\320\275\321\217", 0, QApplication::UnicodeUTF8));
        menuInformation->setTitle(QApplication::translate("MainWindow", "\320\206\320\275\321\204\320\276\321\200\320\274\320\260\321\206\321\226\321\217", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
