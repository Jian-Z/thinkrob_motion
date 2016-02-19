/****************************************************************************
** Meta object code from reading C++ file 'modify_point_position.hpp'
**
** Created: Fri Feb 19 10:29:58 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/thinkrob_pendant/common/modify_point_position.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modify_point_position.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Modify_Point_Position[] = {

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
      23,   22,   22,   22, 0x08,
      50,   22,   22,   22, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Modify_Point_Position[] = {
    "Modify_Point_Position\0\0"
    "on_cancel_button_pressed()\0"
    "on_ok_button_pressed()\0"
};

void Modify_Point_Position::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Modify_Point_Position *_t = static_cast<Modify_Point_Position *>(_o);
        switch (_id) {
        case 0: _t->on_cancel_button_pressed(); break;
        case 1: _t->on_ok_button_pressed(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Modify_Point_Position::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Modify_Point_Position::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Modify_Point_Position,
      qt_meta_data_Modify_Point_Position, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Modify_Point_Position::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Modify_Point_Position::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Modify_Point_Position::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Modify_Point_Position))
        return static_cast<void*>(const_cast< Modify_Point_Position*>(this));
    return QDialog::qt_metacast(_clname);
}

int Modify_Point_Position::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
