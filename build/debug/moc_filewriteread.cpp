/****************************************************************************
** Meta object code from reading C++ file 'filewriteread.h'
**
** Created: Tue 12. Mar 00:22:13 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AnalyzerFoam/filewriteread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filewriteread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FileWriteRead[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,
      27,   14,   22,   14, 0x0a,
      45,   40,   22,   14, 0x0a,
      67,   62,   22,   14, 0x0a,
      82,   14,   22,   14, 0x0a,
      97,   14,   22,   14, 0x0a,
     137,  120,  105,   14, 0x0a,
     170,   14,  162,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FileWriteRead[] = {
    "FileWriteRead\0\0test()\0bool\0isFileOpen()\0"
    "kode\0tryOpen(QString)\0data\0write(QString)\0"
    "closeAndSave()\0close()\0FileWriteRead*\0"
    "fileName,rewrite\0changeFile(QString,bool)\0"
    "QString\0read()\0"
};

const QMetaObject FileWriteRead::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_FileWriteRead,
      qt_meta_data_FileWriteRead, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FileWriteRead::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FileWriteRead::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FileWriteRead::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FileWriteRead))
        return static_cast<void*>(const_cast< FileWriteRead*>(this));
    return QThread::qt_metacast(_clname);
}

int FileWriteRead::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: test(); break;
        case 1: { bool _r = isFileOpen();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: { bool _r = tryOpen((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: { bool _r = write((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: { bool _r = closeAndSave();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: { bool _r = close();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: { FileWriteRead* _r = changeFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< FileWriteRead**>(_a[0]) = _r; }  break;
        case 7: { QString _r = read();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
