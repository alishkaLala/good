#include <QtGui/QApplication>
#include "mainwindow.h"
#include <settingmainframes.h>
#include "settingcaptureframe.h"
#include <configinformation.h>
#include <calculation.h>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec *codec = QTextCodec::codecForName("Windows-1251"); //*****************************************************
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForCStrings (codec);
    configInformation::initialize(a.applicationDirPath());
    configInformation::readFromFile();
    MainWindow w;
     w.show();


    return a.exec();



}
