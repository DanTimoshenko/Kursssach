/****************************************************************************
** Meta object code from reading C++ file 'ball.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Game/ball.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ball.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Ball_t {
    uint offsetsAndSizes[20];
    char stringdata0[5];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[8];
    char stringdata5[8];
    char stringdata6[8];
    char stringdata7[8];
    char stringdata8[8];
    char stringdata9[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Ball_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_Ball_t qt_meta_stringdata_Ball = {
    {
        QT_MOC_LITERAL(0, 4),  // "Ball"
        QT_MOC_LITERAL(5, 10),  // "resetState"
        QT_MOC_LITERAL(16, 0),  // ""
        QT_MOC_LITERAL(17, 8),  // "autoMove"
        QT_MOC_LITERAL(26, 7),  // "setXDir"
        QT_MOC_LITERAL(34, 7),  // "setYDir"
        QT_MOC_LITERAL(42, 7),  // "getXDir"
        QT_MOC_LITERAL(50, 7),  // "getYDir"
        QT_MOC_LITERAL(58, 7),  // "getRect"
        QT_MOC_LITERAL(66, 8)   // "getImage"
    },
    "Ball",
    "resetState",
    "",
    "autoMove",
    "setXDir",
    "setYDir",
    "getXDir",
    "getYDir",
    "getRect",
    "getImage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Ball[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x0a,    1 /* Public */,
       3,    0,   63,    2, 0x0a,    2 /* Public */,
       4,    1,   64,    2, 0x0a,    3 /* Public */,
       5,    1,   67,    2, 0x0a,    5 /* Public */,
       6,    0,   70,    2, 0x0a,    7 /* Public */,
       7,    0,   71,    2, 0x0a,    8 /* Public */,
       8,    0,   72,    2, 0x0a,    9 /* Public */,
       9,    0,   73,    2, 0x0a,   10 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::QRect,
    QMetaType::Void,

       0        // eod
};

void Ball::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Ball *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->resetState(); break;
        case 1: _t->autoMove(); break;
        case 2: _t->setXDir((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->setYDir((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: { int _r = _t->getXDir();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: { int _r = _t->getYDir();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 6: { QRect _r = _t->getRect();
            if (_a[0]) *reinterpret_cast< QRect*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->getImage(); break;
        default: ;
        }
    }
}

const QMetaObject Ball::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Ball.offsetsAndSizes,
    qt_meta_data_Ball,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Ball_t
, QtPrivate::TypeAndForceComplete<Ball, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QRect, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Ball::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Ball::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Ball.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Ball::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
