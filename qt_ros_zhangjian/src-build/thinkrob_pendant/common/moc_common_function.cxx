/****************************************************************************
** Meta object code from reading C++ file 'common_function.hpp'
**
** Created: Fri Feb 19 10:29:57 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/thinkrob_pendant/common/common_function.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'common_function.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Common_Function[] = {

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
      17,   16,   16,   16, 0x08,
      54,   16,   16,   16, 0x08,
      91,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Common_Function[] = {
    "Common_Function\0\0on_prog_design_exit_button_pressed()\0"
    "on_prog_design_wait_button_pressed()\0"
    "on_prog_design_goto_instruction_button_pressed()\0"
};

void Common_Function::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Common_Function *_t = static_cast<Common_Function *>(_o);
        switch (_id) {
        case 0: _t->on_prog_design_exit_button_pressed(); break;
        case 1: _t->on_prog_design_wait_button_pressed(); break;
        case 2: _t->on_prog_design_goto_instruction_button_pressed(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Common_Function::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Common_Function::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Common_Function,
      qt_meta_data_Common_Function, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Common_Function::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Common_Function::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Common_Function::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Common_Function))
        return static_cast<void*>(const_cast< Common_Function*>(this));
    return QDialog::qt_metacast(_clname);
}

int Common_Function::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
