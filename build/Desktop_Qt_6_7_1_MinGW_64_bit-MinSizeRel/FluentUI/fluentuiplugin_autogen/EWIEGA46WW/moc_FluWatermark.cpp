/****************************************************************************
** Meta object code from reading C++ file 'FluWatermark.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../FluentUI/FluWatermark.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FluWatermark.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSFluWatermarkENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSFluWatermarkENDCLASS = QtMocHelpers::stringData(
    "FluWatermark",
    "QML.Element",
    "textChanged",
    "",
    "gapChanged",
    "offsetChanged",
    "textColorChanged",
    "rotateChanged",
    "textSizeChanged",
    "text",
    "gap",
    "offset",
    "textColor",
    "rotate",
    "textSize"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSFluWatermarkENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       1,   14, // classinfo
       6,   16, // methods
       6,   58, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // classinfo: key, value
       1,    0,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       2,    0,   52,    3, 0x06,    7 /* Public */,
       4,    0,   53,    3, 0x06,    8 /* Public */,
       5,    0,   54,    3, 0x06,    9 /* Public */,
       6,    0,   55,    3, 0x06,   10 /* Public */,
       7,    0,   56,    3, 0x06,   11 /* Public */,
       8,    0,   57,    3, 0x06,   12 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       9, QMetaType::QString, 0x00015003, uint(0), 0,
      10, QMetaType::QPoint, 0x00015003, uint(1), 0,
      11, QMetaType::QPoint, 0x00015003, uint(2), 0,
      12, QMetaType::QColor, 0x00015003, uint(3), 0,
      13, QMetaType::Int, 0x00015003, uint(4), 0,
      14, QMetaType::Int, 0x00015003, uint(5), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject FluWatermark::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickPaintedItem::staticMetaObject>(),
    qt_meta_stringdata_CLASSFluWatermarkENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSFluWatermarkENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_metaTypeArray<
        // property 'text'
        QString,
        // property 'gap'
        QPoint,
        // property 'offset'
        QPoint,
        // property 'textColor'
        QColor,
        // property 'rotate'
        int,
        // property 'textSize'
        int,
        // Q_OBJECT / Q_GADGET
        FluWatermark,
        // method 'textChanged'
        void,
        // method 'gapChanged'
        void,
        // method 'offsetChanged'
        void,
        // method 'textColorChanged'
        void,
        // method 'rotateChanged'
        void,
        // method 'textSizeChanged'
        void
    >,
    nullptr
} };

void FluWatermark::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FluWatermark *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->textChanged(); break;
        case 1: _t->gapChanged(); break;
        case 2: _t->offsetChanged(); break;
        case 3: _t->textColorChanged(); break;
        case 4: _t->rotateChanged(); break;
        case 5: _t->textSizeChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FluWatermark::*)();
            if (_t _q_method = &FluWatermark::textChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FluWatermark::*)();
            if (_t _q_method = &FluWatermark::gapChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FluWatermark::*)();
            if (_t _q_method = &FluWatermark::offsetChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (FluWatermark::*)();
            if (_t _q_method = &FluWatermark::textColorChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (FluWatermark::*)();
            if (_t _q_method = &FluWatermark::rotateChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (FluWatermark::*)();
            if (_t _q_method = &FluWatermark::textSizeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<FluWatermark *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->_text; break;
        case 1: *reinterpret_cast< QPoint*>(_v) = _t->_gap; break;
        case 2: *reinterpret_cast< QPoint*>(_v) = _t->_offset; break;
        case 3: *reinterpret_cast< QColor*>(_v) = _t->_textColor; break;
        case 4: *reinterpret_cast< int*>(_v) = _t->_rotate; break;
        case 5: *reinterpret_cast< int*>(_v) = _t->_textSize; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<FluWatermark *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0:
            if (_t->_text != *reinterpret_cast< QString*>(_v)) {
                _t->_text = *reinterpret_cast< QString*>(_v);
                Q_EMIT _t->textChanged();
            }
            break;
        case 1:
            if (_t->_gap != *reinterpret_cast< QPoint*>(_v)) {
                _t->_gap = *reinterpret_cast< QPoint*>(_v);
                Q_EMIT _t->gapChanged();
            }
            break;
        case 2:
            if (_t->_offset != *reinterpret_cast< QPoint*>(_v)) {
                _t->_offset = *reinterpret_cast< QPoint*>(_v);
                Q_EMIT _t->offsetChanged();
            }
            break;
        case 3:
            if (_t->_textColor != *reinterpret_cast< QColor*>(_v)) {
                _t->_textColor = *reinterpret_cast< QColor*>(_v);
                Q_EMIT _t->textColorChanged();
            }
            break;
        case 4:
            if (_t->_rotate != *reinterpret_cast< int*>(_v)) {
                _t->_rotate = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->rotateChanged();
            }
            break;
        case 5:
            if (_t->_textSize != *reinterpret_cast< int*>(_v)) {
                _t->_textSize = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->textSizeChanged();
            }
            break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
    (void)_a;
}

const QMetaObject *FluWatermark::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FluWatermark::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSFluWatermarkENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QQuickPaintedItem::qt_metacast(_clname);
}

int FluWatermark::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickPaintedItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void FluWatermark::textChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void FluWatermark::gapChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void FluWatermark::offsetChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void FluWatermark::textColorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void FluWatermark::rotateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void FluWatermark::textSizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
