/****************************************************************************
** Meta object code from reading C++ file 'sport_instruction_window.hpp'
**
** Created: Fri Feb 19 10:29:58 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/thinkrob_pendant/common/sport_instruction_window.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sport_instruction_window.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Sport_Instruction_Window[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      26,   25,   25,   25, 0x08,
      69,   25,   25,   25, 0x08,
     113,   25,   25,   25, 0x08,
     156,   25,   25,   25, 0x08,
     183,   25,   25,   25, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Sport_Instruction_Window[] = {
    "Sport_Instruction_Window\0\0"
    "on_first_point_textEdit_selectionChanged()\0"
    "on_second_point_textEdit_selectionChanged()\0"
    "on_third_point_textEdit_selectionChanged()\0"
    "on_cancel_button_pressed()\0"
    "on_ok_button_pressed()\0"
};

void Sport_Instruction_Window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Sport_Instruction_Window *_t = static_cast<Sport_Instruction_Window *>(_o);
        switch (_id) {
        case 0: _t->on_first_point_textEdit_selectionChanged(); break;
        case 1: _t->on_second_point_textEdit_selectionChanged(); break;
        case 2: _t->on_third_point_textEdit_selectionChanged(); break;
        case 3: _t->on_cancel_button_pressed(); break;
        case 4: _t->on_ok_button_pressed(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Sport_Instruction_Window::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Sport_Instruction_Window::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Sport_Instruction_Window,
      qt_meta_data_Sport_Instruction_Window, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Sport_Instruction_Window::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Sport_Instruction_Window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Sport_Instruction_Window::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Sport_Instruction_Window))
        return static_cast<void*>(const_cast< Sport_Instruction_Window*>(this));
    return QDialog::qt_metacast(_clname);
}

int Sport_Instruction_Window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
