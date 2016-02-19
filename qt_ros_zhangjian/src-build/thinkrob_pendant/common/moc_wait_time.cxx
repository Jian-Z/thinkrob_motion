/****************************************************************************
** Meta object code from reading C++ file 'wait_time.hpp'
**
** Created: Fri Feb 19 10:29:57 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/thinkrob_pendant/common/wait_time.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wait_time.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Wait_Time[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      38,   10,   10,   10, 0x08,
      61,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Wait_Time[] = {
    "Wait_Time\0\0on_cancel_button_pressed()\0"
    "on_ok_button_pressed()\0"
    "on_wait_time_value_selectionChanged()\0"
};

void Wait_Time::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Wait_Time *_t = static_cast<Wait_Time *>(_o);
        switch (_id) {
        case 0: _t->on_cancel_button_pressed(); break;
        case 1: _t->on_ok_button_pressed(); break;
        case 2: _t->on_wait_time_value_selectionChanged(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Wait_Time::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Wait_Time::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Wait_Time,
      qt_meta_data_Wait_Time, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Wait_Time::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Wait_Time::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Wait_Time::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Wait_Time))
        return static_cast<void*>(const_cast< Wait_Time*>(this));
    return QDialog::qt_metacast(_clname);
}

int Wait_Time::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
