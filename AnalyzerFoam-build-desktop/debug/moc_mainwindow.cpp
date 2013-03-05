/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Tue 5. Mar 20:51:43 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AnalyzerFoam/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      29,   11,   11,   11, 0x08,
      53,   11,   11,   11, 0x08,
      78,   11,   11,   11, 0x08,
     102,   11,   11,   11, 0x08,
     115,   11,   11,   11, 0x08,
     129,   11,   11,   11, 0x08,
     143,   11,   11,   11, 0x08,
     162,   11,   11,   11, 0x08,
     178,   11,   11,   11, 0x08,
     197,   11,   11,   11, 0x08,
     218,   11,   11,   11, 0x08,
     240,  236,   11,   11, 0x08,
     272,  264,   11,   11, 0x08,
     316,  302,   11,   11, 0x08,
     343,   11,   11,   11, 0x08,
     369,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0captureChoised()\0"
    "on_pushButton_clicked()\0"
    "on_buttonStart_clicked()\0"
    "on_buttonStop_clicked()\0captureOff()\0"
    "hideCapture()\0showCapture()\0"
    "showAboutProgram()\0showInfoFrame()\0"
    "showSettingFrame()\0showSettingCapture()\0"
    "showOpenGLGraph()\0img\0imageGetting(IplImage*)\0"
    "enabled\0setSartStopImegeGetting(bool)\0"
    "count,diametr\0infoGetting(double,double)\0"
    "on_pushButton_2_clicked()\0"
    "on_startCalculation_clicked()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: captureChoised(); break;
        case 1: on_pushButton_clicked(); break;
        case 2: on_buttonStart_clicked(); break;
        case 3: on_buttonStop_clicked(); break;
        case 4: captureOff(); break;
        case 5: hideCapture(); break;
        case 6: showCapture(); break;
        case 7: showAboutProgram(); break;
        case 8: showInfoFrame(); break;
        case 9: showSettingFrame(); break;
        case 10: showSettingCapture(); break;
        case 11: showOpenGLGraph(); break;
        case 12: imageGetting((*reinterpret_cast< IplImage*(*)>(_a[1]))); break;
        case 13: setSartStopImegeGetting((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: infoGetting((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 15: on_pushButton_2_clicked(); break;
        case 16: on_startCalculation_clicked(); break;
        default: ;
        }
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
