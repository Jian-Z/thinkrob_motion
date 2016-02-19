/****************************************************************************
** Meta object code from reading C++ file 'input_number.hpp'
**
** Created: Fri Feb 19 10:29:57 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/thinkrob_pendant/common/input_number.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'input_number.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Input_Number[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      36,   13,   13,   13, 0x08,
      58,   13,   13,   13, 0x08,
      80,   13,   13,   13, 0x08,
     102,   13,   13,   13, 0x08,
     124,   13,   13,   13, 0x08,
     146,   13,   13,   13, 0x08,
     168,   13,   13,   13, 0x08,
     190,   13,   13,   13, 0x08,
     212,   13,   13,   13, 0x08,
     234,   13,   13,   13, 0x08,
     261,   13,   13,   13, 0x08,
     280,   13,   13,   13, 0x08,
     300,   13,   13,   13, 0x08,
     322,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Input_Number[] = {
    "Input_Number\0\0on_number_1_pressed()\0"
    "on_number_2_pressed()\0on_number_3_pressed()\0"
    "on_number_4_pressed()\0on_number_5_pressed()\0"
    "on_number_6_pressed()\0on_number_7_pressed()\0"
    "on_number_8_pressed()\0on_number_9_pressed()\0"
    "on_number_0_pressed()\0on_decimal_point_pressed()\0"
    "on_clear_pressed()\0on_reduce_pressed()\0"
    "on_negative_pressed()\0on_enter_pressed()\0"
};

void Input_Number::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Input_Number *_t = static_cast<Input_Number *>(_o);
        switch (_id) {
        case 0: _t->on_number_1_pressed(); break;
        case 1: _t->on_number_2_pressed(); break;
        case 2: _t->on_number_3_pressed(); break;
        case 3: _t->on_number_4_pressed(); break;
        case 4: _t->on_number_5_pressed(); break;
        case 5: _t->on_number_6_pressed(); break;
        case 6: _t->on_number_7_pressed(); break;
        case 7: _t->on_number_8_pressed(); break;
        case 8: _t->on_number_9_pressed(); break;
        case 9: _t->on_number_0_pressed(); break;
        case 10: _t->on_decimal_point_pressed(); break;
        case 11: _t->on_clear_pressed(); break;
        case 12: _t->on_reduce_pressed(); break;
        case 13: _t->on_negative_pressed(); break;
        case 14: _t->on_enter_pressed(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Input_Number::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Input_Number::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Input_Number,
      qt_meta_data_Input_Number, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Input_Number::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Input_Number::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Input_Number::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Input_Number))
        return static_cast<void*>(const_cast< Input_Number*>(this));
    return QDialog::qt_metacast(_clname);
}

int Input_Number::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
