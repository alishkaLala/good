/****************************************************************************
** Meta object code from reading C++ file 'imageprocessing.h'
**
** Created: Sun 7. Apr 13:16:19 2013
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
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   17,   16,   16, 0x05,
      45,   17,   16,   16, 0x05,
      94,   76,   16,   16, 0x05,
     132,  129,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
     157,   16,   16,   16, 0x0a,
     171,   16,   16,   16, 0x0a,
     191,  182,   16,   16, 0x0a,
     217,   16,   16,   16, 0x2a,
     244,  238,   16,   16, 0x0a,
     258,  238,   16,   16, 0x0a,
     272,  238,   16,   16, 0x0a,
     317,  291,   16,   16, 0x0a,
     356,  238,   16,   16, 0x0a,
     378,  238,   16,   16, 0x0a,
     395,  238,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ImageProcessing[] = {
    "ImageProcessing\0\0img\0imageIsReady(IplImage*)\0"
    "imageCalculateReady(IplImage*)\0"
    "count,diametr,arr\0infoIsReady(double,double,double*)\0"
    ",,\0captureProp(int,int,int)\0working(bool)\0"
    "getImage()\0,writing\0setCalculation(bool,bool)\0"
    "setCalculation(bool)\0value\0setK1(double)\0"
    "setK2(double)\0setWindowSize(int)\0"
    ",x1,y1,widthROI,heigthROI\0"
    "setEnabledResize(bool,int,int,int,int)\0"
    "setChoisedCpture(int)\0setTesting(bool)\0"
    "setDelay(int)\0"
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
        case 0: imageIsReady((*reinterpret_cast< IplImage*(*)>(_a[1]))); break;
        case 1: imageCalculateReady((*reinterpret_cast< IplImage*(*)>(_a[1]))); break;
        case 2: infoIsReady((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double*(*)>(_a[3]))); break;
        case 3: captureProp((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: working((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: getImage(); break;
        case 6: setCalculation((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 7: setCalculation((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: setK1((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: setK2((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: setWindowSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: setEnabledResize((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 12: setChoisedCpture((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: setTesting((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: setDelay((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void ImageProcessing::imageIsReady(IplImage * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ImageProcessing::imageCalculateReady(IplImage * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ImageProcessing::infoIsReady(double _t1, double _t2, double * _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ImageProcessing::captureProp(int _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
