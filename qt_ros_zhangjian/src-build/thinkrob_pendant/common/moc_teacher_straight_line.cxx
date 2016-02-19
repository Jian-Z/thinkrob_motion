/****************************************************************************
** Meta object code from reading C++ file 'teacher_straight_line.hpp'
**
** Created: Fri Feb 19 10:29:56 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/thinkrob_pendant/common/teacher_straight_line.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'teacher_straight_line.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Teacher_Straight_Line[] = {

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

static const char qt_meta_stringdata_Teacher_Straight_Line[] = {
    "Teacher_Straight_Line\0\0"
    "on_cancel_button_pressed()\0"
    "on_ok_button_pressed()\0"
};

void Teacher_Straight_Line::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Teacher_Straight_Line *_t = static_cast<Teacher_Straight_Line *>(_o);
        switch (_id) {
        case 0: _t->on_cancel_button_pressed(); break;
        case 1: _t->on_ok_button_pressed(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Teacher_Straight_Line::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Teacher_Straight_Line::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Teacher_Straight_Line,
      qt_meta_data_Teacher_Straight_Line, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Teacher_Straight_Line::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Teacher_Straight_Line::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Teacher_Straight_Line::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Teacher_Straight_Line))
        return static_cast<void*>(const_cast< Teacher_Straight_Line*>(this));
    return QDialog::qt_metacast(_clname);
}

int Teacher_Straight_Line::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
