/****************************************************************************
** Meta object code from reading C++ file 'brick.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Game/brick.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'brick.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Brick_t {
    uint offsetsAndSizes[14];
    char stringdata0[6];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[13];
    char stringdata4[8];
    char stringdata5[8];
    char stringdata6[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Brick_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_Brick_t qt_meta_stringdata_Brick = {
    {
        QT_MOC_LITERAL(0, 5),  // "Brick"
        QT_MOC_LITERAL(6, 11),  // "isDestroyed"
        QT_MOC_LITERAL(18, 0),  // ""
        QT_MOC_LITERAL(19, 12),  // "setDestroyed"
        QT_MOC_LITERAL(32, 7),  // "getRect"
        QT_MOC_LITERAL(40, 7),  // "setRect"
        QT_MOC_LITERAL(48, 8)   // "getImage"
    },
    "Brick",
    "isDestroyed",
    "",
    "setDestroyed",
    "getRect",
    "setRect",
    "getImage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Brick[] = {

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
       3,    1,   45,    2, 0x0a,    2 /* Public */,
       4,    0,   48,    2, 0x0a,    4 /* Public */,
       5,    1,   49,    2, 0x0a,    5 /* Public */,
       6,    0,   52,    2, 0x0a,    7 /* Public */,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::QRect,
    QMetaType::Void, QMetaType::QRect,    2,
    QMetaType::Void,

       0        // eod
};

void Brick::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Brick *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { bool _r = _t->isDestroyed();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->setDestroyed((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: { QRect _r = _t->getRect();
            if (_a[0]) *reinterpret_cast< QRect*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->setRect((*reinterpret_cast< std::add_pointer_t<QRect>>(_a[1]))); break;
        case 4: _t->getImage(); break;
        default: ;
        }
    }
}

const QMetaObject Brick::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Brick.offsetsAndSizes,
    qt_meta_data_Brick,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Brick_t
, QtPrivate::TypeAndForceComplete<Brick, std::true_type>
, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<QRect, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QRect, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Brick::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Brick::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Brick.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Brick::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
