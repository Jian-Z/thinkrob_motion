/****************************************************************************
** Meta object code from reading C++ file 'teacher_point_to_point.hpp'
**
** Created: Fri Feb 19 10:29:57 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/thinkrob_pendant/common/teacher_point_to_point.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'teacher_point_to_point.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_teacher_point_to_point[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   23,   23,   23, 0x08,
      51,   23,   23,   23, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_teacher_point_to_point[] = {
    "teacher_point_to_point\0\0"
    "on_cancel_button_pressed()\0"
    "on_ok_button_pressed()\0"
};

void teacher_point_to_point::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        teacher_point_to_point *_t = static_cast<teacher_point_to_point *>(_o);
        switch (_id) {
        case 0: _t->on_cancel_button_pressed(); break;
        case 1: _t->on_ok_button_pressed(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData teacher_point_to_point::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject teacher_point_to_point::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_teacher_point_to_point,
      qt_meta_data_teacher_point_to_point, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &teacher_point_to_point::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *teacher_point_to_point::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *teacher_point_to_point::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_teacher_point_to_point))
        return static_cast<void*>(const_cast< teacher_point_to_point*>(this));
    return QDialog::qt_metacast(_clname);
}

int teacher_point_to_point::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE