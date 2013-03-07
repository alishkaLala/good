/****************************************************************************
** Meta object code from reading C++ file 'settingcaptureframe.h'
**
** Created: Wed 6. Mar 23:21:15 2013
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
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      39,   21,   20,   20, 0x05,

 // slots: signature, parameters, type, tag, flags
      70,   20,   20,   20, 0x08,
      81,   20,   20,   20, 0x08,
      93,   20,   20,   20, 0x08,
     109,   20,   20,   20, 0x08,
     130,   20,   20,   20, 0x08,
     159,   20,   20,   20, 0x08,
     185,   20,   20,   20, 0x08,
     211,   20,   20,   20, 0x08,
     238,   20,   20,   20, 0x08,
     267,   20,   20,   20, 0x08,
     293,   20,   20,   20, 0x08,
     322,   20,   20,   20, 0x08,
     352,  348,   20,   20, 0x0a,
     376,  348,   20,   20, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SettingCaptureFrame[] = {
    "SettingCaptureFrame\0\0value,x1,y1,x2,y2\0"
    "resizing(bool,int,int,int,int)\0"
    "stopWork()\0toolTipMm()\0validMmAndSet()\0"
    "on_defRect_clicked()\0on_defDistInPixels_clicked()\0"
    "on_pushButton_7_clicked()\0"
    "on_pushButton_8_clicked()\0"
    "on_SettingCansel_clicked()\0"
    "on_SettingStandart_clicked()\0"
    "on_SettingApply_clicked()\0"
    "on_pushButtonStart_clicked()\0"
    "on_pushButtonOk_clicked()\0img\0"
    "imageGetting(IplImage*)\0"
    "imageCalculatingGetting(IplImage*)\0"
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
        case 1: stopWork(); break;
        case 2: toolTipMm(); break;
        case 3: validMmAndSet(); break;
        case 4: on_defRect_clicked(); break;
        case 5: on_defDistInPixels_clicked(); break;
        case 6: on_pushButton_7_clicked(); break;
        case 7: on_pushButton_8_clicked(); break;
        case 8: on_SettingCansel_clicked(); break;
        case 9: on_SettingStandart_clicked(); break;
        case 10: on_SettingApply_clicked(); break;
        case 11: on_pushButtonStart_clicked(); break;
        case 12: on_pushButtonOk_clicked(); break;
        case 13: imageGetting((*reinterpret_cast< IplImage*(*)>(_a[1]))); break;
        case 14: imageCalculatingGetting((*reinterpret_cast< IplImage*(*)>(_a[1]))); break;
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
QT_END_MOC_NAMESPACE
