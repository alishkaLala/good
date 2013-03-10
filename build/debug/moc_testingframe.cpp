/****************************************************************************
** Meta object code from reading C++ file 'testingframe.h'
**
** Created: Sun 10. Mar 17:34:46 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AnalyzerFoam/testingframe.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testingframe.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_testingFrame[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   14,   13,   13, 0x0a,
      47,   43,   13,   13, 0x08,
      71,   13,   13,   13, 0x08,
      98,   95,   13,   13, 0x08,
     126,   13,   13,   13, 0x08,
     146,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_testingFrame[] = {
    "testingFrame\0\0value\0setChoisedCapture(int)\0"
    "img\0imageGetting(IplImage*)\0"
    "on_pushButton_clicked()\0,,\0"
    "setCaptureProp(int,int,int)\0"
    "progressBarChange()\0on_pushButton_2_clicked()\0"
};

const QMetaObject testingFrame::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_testingFrame,
      qt_meta_data_testingFrame, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &testingFrame::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *testingFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *testingFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_testingFrame))
        return static_cast<void*>(const_cast< testingFrame*>(this));
    return QWidget::qt_metacast(_clname);
}

int testingFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setChoisedCapture((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: imageGetting((*reinterpret_cast< IplImage*(*)>(_a[1]))); break;
        case 2: on_pushButton_clicked(); break;
        case 3: setCaptureProp((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: progressBarChange(); break;
        case 5: on_pushButton_2_clicked(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
