/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Mon 1. Apr 17:09:51 2013
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
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   12,   11,   11, 0x08,
      58,   40,   11,   11, 0x08,
      93,   11,   11,   11, 0x08,
     107,   11,   11,   11, 0x08,
     121,   11,   11,   11, 0x08,
     143,  135,   11,   11, 0x08,
     173,   11,   11,   11, 0x08,
     188,   11,   11,   11, 0x08,
     211,   11,   11,   11, 0x08,
     232,   11,   11,   11, 0x08,
     252,   11,   11,   11, 0x08,
     271,   11,   11,   11, 0x08,
     287,   11,   11,   11, 0x08,
     306,   11,   11,   11, 0x08,
     327,   11,   11,   11, 0x08,
     345,   11,   11,   11, 0x08,
     364,   11,   11,   11, 0x08,
     394,   11,   11,   11, 0x08,
     425,   11,   11,   11, 0x08,
     455,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0img\0imageGetting(IplImage*)\0"
    "count,diametr,arr\0infoGetting(double,double,double*)\0"
    "captureStop()\0hideCapture()\0showCapture()\0"
    "enabled\0setSartStopImegeGetting(bool)\0"
    "captureStart()\0calculateImagesStart()\0"
    "calculateImageStop()\0progressBarChange()\0"
    "showAboutProgram()\0showInfoFrame()\0"
    "showSettingFrame()\0showSettingCapture()\0"
    "showOpenGLGraph()\0showTestingFrame()\0"
    "on_startCalculation_clicked()\0"
    "on_buttonAnalizStart_clicked()\0"
    "on_buttonAnalizStop_clicked()\0"
    "on_buttonCaptureStart_clicked()\0"
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
        case 0: imageGetting((*reinterpret_cast< IplImage*(*)>(_a[1]))); break;
        case 1: infoGetting((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double*(*)>(_a[3]))); break;
        case 2: captureStop(); break;
        case 3: hideCapture(); break;
        case 4: showCapture(); break;
        case 5: setSartStopImegeGetting((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: captureStart(); break;
        case 7: calculateImagesStart(); break;
        case 8: calculateImageStop(); break;
        case 9: progressBarChange(); break;
        case 10: showAboutProgram(); break;
        case 11: showInfoFrame(); break;
        case 12: showSettingFrame(); break;
        case 13: showSettingCapture(); break;
        case 14: showOpenGLGraph(); break;
        case 15: showTestingFrame(); break;
        case 16: on_startCalculation_clicked(); break;
        case 17: on_buttonAnalizStart_clicked(); break;
        case 18: on_buttonAnalizStop_clicked(); break;
        case 19: on_buttonCaptureStart_clicked(); break;
        default: ;
        }
        _id -= 20;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
