/********************************************************************************
** Form generated from reading UI file 'infoframe.ui'
**
** Created: Mon 1. Apr 17:08:44 2013
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOFRAME_H
#define UI_INFOFRAME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InfoFrame
{
public:
    QGridLayout *gridLayout;
    QTextBrowser *textBrowser;
    QPushButton *pushButton;

    void setupUi(QWidget *InfoFrame)
    {
        if (InfoFrame->objectName().isEmpty())
            InfoFrame->setObjectName(QString::fromUtf8("InfoFrame"));
        InfoFrame->resize(400, 300);
        gridLayout = new QGridLayout(InfoFrame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textBrowser = new QTextBrowser(InfoFrame);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        gridLayout->addWidget(textBrowser, 0, 0, 1, 1);

        pushButton = new QPushButton(InfoFrame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);


        retranslateUi(InfoFrame);

        QMetaObject::connectSlotsByName(InfoFrame);
    } // setupUi

    void retranslateUi(QWidget *InfoFrame)
    {
        InfoFrame->setWindowTitle(QApplication::translate("InfoFrame", "Form", 0, QApplication::UnicodeUTF8));
        textBrowser->setHtml(QApplication::translate("InfoFrame", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"justify\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; color:#000000;\">\320\243 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\321\226 \320\277\321\200\320\276\320\262\320\265\320\264\320\265\320\275\320\270\321\205 \320\264\320\276\321\201\320\273\321\226\320\264\320\266\320\265\320\275\321\214 \320\261\321\203\320\273\320\276 \320\262\320\270\321\217\320\262\320\273\320\265\320\275\320\276, \320\275\320\260 \321\201\321\214\320\276\320\263\320\276\320\264\320\275\321\226 \320\275\320\265 \321\226\321\201\320\275\321\203\321\224 \320"
                        "\260\320\262\321\202\320\276\320\274\320\260\321\202\320\270\321\207\320\275\320\270\321\205 \321\207\320\270 \320\260\320\262\321\202\320\276\320\274\320\260\321\202\320\270\320\267\320\276\320\262\320\260\320\275\320\270\321\205 \320\267\320\260\321\201\320\276\320\261\321\226\320\262 \320\276\321\202\321\200\320\270\320\274\320\260\320\275\320\275\321\217 \321\205\320\260\321\200\320\260\320\272\321\202\320\265\321\200\320\270\321\201\321\202\320\270\320\272 \320\277\321\226\320\275\320\270.</span><span style=\" font-size:14pt;\"> </span></p>\n"
"<p align=\"justify\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; color:#000000;\">\320\236\320\264\320\275\320\260\320\272, \320\262\320\270\320\272\320\276\321\200\320\270\321\201\321\202\320\260\320\275\320\275\321\217 \321\202\320\265\321\205\320\275\320\276\320\273\320\276\320\263\321\226\320\271 \320\272\320\276\320\274\320\277\342\200\231\321\216\321\202"
                        "\320\265\321\200\320\275\320\276\320\263\320\276 \320\267\320\276\321\200\321\203 \320\264\320\276\320\267\320\262\320\276\320\273\321\217\321\224 \320\267\320\274\320\265\320\275\321\210\320\270\321\202\320\270 \321\207\320\260\321\201 \320\276\321\202\321\200\320\270\320\274\320\260\320\275\320\275\321\217 \320\262\321\205\321\226\320\264\320\275\320\270\321\205 \320\264\320\260\320\275\320\270\321\205 \321\202\320\260 \320\277\321\226\320\264\320\262\320\270\321\211\320\270\321\202\320\270 \321\227\321\205 \320\264\320\276\321\201\321\202\320\276\320\262\321\226\321\200\320\275\321\226\321\201\321\202\321\214, \320\275\320\260 \320\262\321\226\320\264\320\274\321\226\320\275\321\203 \320\262\321\226\320\264 \321\200\321\203\321\207\320\275\320\270\321\205 \320\267\320\260\321\201\320\276\320\261\321\226\320\262 \320\260\320\275\320\260\320\273\321\226\320\267\321\203 \321\202\320\260 \320\262\320\262\320\276\320\264\321\203 \320\264\320\260\320\275\320\270\321\205.</span><span style=\" font-size:14pt;\"> </"
                        "span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("InfoFrame", "\320\224\320\276\320\261\321\200\320\265", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class InfoFrame: public Ui_InfoFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOFRAME_H
