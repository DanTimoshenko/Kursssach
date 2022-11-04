/****************************************************************************
** Meta object code from reading C++ file 'paddle.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Game/paddle.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'paddle.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Paddle_t {
    uint offsetsAndSizes[14];
    char stringdata0[7];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[6];
    char stringdata5[8];
    char stringdata6[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Paddle_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_Paddle_t qt_meta_stringdata_Paddle = {
    {
        QT_MOC_LITERAL(0, 6),  // "Paddle"
        QT_MOC_LITERAL(7, 10),  // "resetState"
        QT_MOC_LITERAL(18, 0),  // ""
        QT_MOC_LITERAL(19, 4),  // "move"
        QT_MOC_LITERAL(24, 5),  // "setDx"
        QT_MOC_LITERAL(30, 7),  // "getRect"
        QT_MOC_LITERAL(38, 8)   // "getImage"
    },
    "Paddle",
    "resetState",
    "",
    "move",
    "setDx",
    "getRect",
    "getImage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Paddle[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x0a,    1 /* Public */,
       3,    0,   45,    2, 0x0a,    2 /* Public */,
       4,    1,   46,    2, 0x0a,    3 /* Public */,
       5,    0,   49,    2, 0x0a,    5 /* Public */,
       6,    0,   50,    2, 0x0a,    6 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::QRect,
    QMetaType::Void,

       0        // eod
};

void Paddle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Paddle *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->resetState(); break;
        case 1: _t->move(); break;
        case 2: _t->setDx((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: { QRect _r = _t->getRect();
            if (_a[0]) *reinterpret_cast< QRect*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->getImage(); break;
        default: ;
        }
    }
}

const QMetaObject Paddle::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Paddle.offsetsAndSizes,
    qt_meta_data_Paddle,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Paddle_t
, QtPrivate::TypeAndForceComplete<Paddle, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QRect, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Paddle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Paddle::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Paddle.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Paddle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
