/****************************************************************************
** Meta object code from reading C++ file 'settingcaptureframe.h'
**
** Created: Sun 10. Mar 22:50:31 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AnalyzerFoam/settingcaptureframe.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settingcaptureframe.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SettingCaptureFrame[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      39,   21,   20,   20, 0x05,
      70,   20,   20,   20, 0x05,

 // slots: signature, parameters, type, tag, flags
      86,   82,   20,   20, 0x08,
     110,   20,   20,   20, 0x08,
     137,   20,   20,   20, 0x08,
     166,   20,   20,   20, 0x08,
     192,   20,   20,   20, 0x08,
     225,   20,   20,   20, 0x08,
     254,   20,   20,   20, 0x08,
     280,   20,   20,   20, 0x08,
     311,   20,   20,   20, 0x08,
     323,   20,   20,   20, 0x08,
     339,   20,   20,   20, 0x08,
     353,   20,   20,   20, 0x08,
     377,   20,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SettingCaptureFrame[] = {
    "SettingCaptureFrame\0\0value,x1,y1,x2,y2\0"
    "resizing(bool,int,int,int,int)\0"
    "needStart()\0img\0imageGetting(IplImage*)\0"
    "on_SettingCansel_clicked()\0"
    "on_SettingStandart_clicked()\0"
    "on_SettingApply_clicked()\0"
    "on_buttonRestartTrySet_clicked()\0"
    "on_buttonSizeApply_clicked()\0"
    "on_buttonSetROI_clicked()\0"
    "on_buttonSetDistance_clicked()\0"
    "toolTipMm()\0validMmAndSet()\0workerStart()\0"
    "on_pushButton_clicked()\0"
    "on_widthCaptureWindow_valueChanged(int)\0"
};

const QMetaObject SettingCaptureFrame::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SettingCaptureFrame,
      qt_meta_data_SettingCaptureFrame, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SettingCaptureFrame::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SettingCaptureFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SettingCaptureFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SettingCaptureFrame))
        return static_cast<void*>(const_cast< SettingCaptureFrame*>(this));
    return QWidget::qt_metacast(_clname);
}

int SettingCaptureFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: resizing((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 1: needStart(); break;
        case 2: imageGetting((*reinterpret_cast< IplImage*(*)>(_a[1]))); break;
        case 3: on_SettingCansel_clicked(); break;
        case 4: on_SettingStandart_clicked(); break;
        case 5: on_SettingApply_clicked(); break;
        case 6: on_buttonRestartTrySet_clicked(); break;
        case 7: on_buttonSizeApply_clicked(); break;
        case 8: on_buttonSetROI_clicked(); break;
        case 9: on_buttonSetDistance_clicked(); break;
        case 10: toolTipMm(); break;
        case 11: validMmAndSet(); break;
        case 12: workerStart(); break;
        case 13: on_pushButton_clicked(); break;
        case 14: on_widthCaptureWindow_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void SettingCaptureFrame::resizing(bool _t1, int _t2, int _t3, int _t4, int _t5)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SettingCaptureFrame::needStart()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
