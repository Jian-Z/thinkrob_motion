/****************************************************************************
** Meta object code from reading C++ file 'programmer_run_thread.hpp'
**
** Created: Fri Feb 19 10:29:58 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/thinkrob_pendant/common/programmer_run_thread.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'programmer_run_thread.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Programmer_Run_Thread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      35,   23,   22,   22, 0x05,
      75,   64,   22,   22, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_Programmer_Run_Thread[] = {
    "Programmer_Run_Thread\0\0execute_row\0"
    "get_command_execute_row(int)\0error_type\0"
    "programmer_run_error_type(int)\0"
};

void Programmer_Run_Thread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Programmer_Run_Thread *_t = static_cast<Programmer_Run_Thread *>(_o);
        switch (_id) {
        case 0: _t->get_command_execute_row((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->programmer_run_error_type((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Programmer_Run_Thread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Programmer_Run_Thread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_Programmer_Run_Thread,
      qt_meta_data_Programmer_Run_Thread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Programmer_Run_Thread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Programmer_Run_Thread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Programmer_Run_Thread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Programmer_Run_Thread))
        return static_cast<void*>(const_cast< Programmer_Run_Thread*>(this));
    return QThread::qt_metacast(_clname);
}

int Programmer_Run_Thread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void Programmer_Run_Thread::get_command_execute_row(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Programmer_Run_Thread::programmer_run_error_type(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
