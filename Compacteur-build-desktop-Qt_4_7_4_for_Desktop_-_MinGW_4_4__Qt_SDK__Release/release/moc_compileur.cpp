/****************************************************************************
** Meta object code from reading C++ file 'compileur.h'
**
** Created: Thu 31. May 14:43:16 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Compacteur/compileur.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'compileur.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_compilClass[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      27,   12,   12,   12, 0x08,
      43,   12,   12,   12, 0x08,
      57,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_compilClass[] = {
    "compilClass\0\0selectImage()\0selectArchive()\0"
    "selectResul()\0execCopy()\0"
};

const QMetaObject compilClass::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_compilClass,
      qt_meta_data_compilClass, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &compilClass::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *compilClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *compilClass::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_compilClass))
        return static_cast<void*>(const_cast< compilClass*>(this));
    return QWidget::qt_metacast(_clname);
}

int compilClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: selectImage(); break;
        case 1: selectArchive(); break;
        case 2: selectResul(); break;
        case 3: execCopy(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
