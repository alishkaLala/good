/****************************************************************************
** Meta object code from reading C++ file 'imageprocessing.h'
**
** Created: Tue 5. Mar 19:41:22 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AnalyzerFoam/imageprocessing.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imageprocessing.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ImageProcessing[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,
      28,   24,   16,   16, 0x05,
      52,   24,   16,   16, 0x05,
      97,   83,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
     124,   16,   16,   16, 0x0a,
     138,   16,   16,   16, 0x0a,
     149,   16,   16,   16, 0x0a,
     176,  170,   16,   16, 0x0a,
     190,  170,   16,   16, 0x0a,
     204,  170,   16,   16, 0x0a,
     255,  223,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ImageProcessing[] = {
    "ImageProcessing\0\0test()\0img\0"
    "imageIsReady(IplImage*)\0"
    "imageCalculateReady(IplImage*)\0"
    "count,diametr\0infoIsReady(double,double)\0"
    "working(bool)\0getImage()\0setCalculation(bool)\0"
    "value\0setK1(double)\0setK2(double)\0"
    "setWindowSize(int)\0,x1,y1,widthResize,heigthResize\0"
    "setEnabledResize(bool,int,int,int,int)\0"
};

const QMetaObject ImageProcessing::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ImageProcessing,
      qt_meta_data_ImageProcessing, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ImageProcessing::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ImageProcessing::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ImageProcessing::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ImageProcessing))
        return static_cast<void*>(const_cast< ImageProcessing*>(this));
    return QThread::qt_metacast(_clname);
}

int ImageProcessing::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: test(); break;
        case 1: imageIsReady((*reinterpret_cast< IplImage*(*)>(_a[1]))); break;
        case 2: imageCalculateReady((*reinterpret_cast< IplImage*(*)>(_a[1]))); break;
        case 3: infoIsReady((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 4: working((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: getImage(); break;
        case 6: setCalculation((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: setK1((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: setK2((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: setWindowSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: setEnabledResize((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void ImageProcessing::test()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ImageProcessing::imageIsReady(IplImage * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ImageProcessing::imageCalculateReady(IplImage * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ImageProcessing::infoIsReady(double _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
