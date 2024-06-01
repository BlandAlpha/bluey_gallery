/****************************************************************************
** Meta object code from reading C++ file 'FluAccentColor.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../FluentUI/FluAccentColor.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FluAccentColor.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSFluAccentColorENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSFluAccentColorENDCLASS = QtMocHelpers::stringData(
    "FluAccentColor",
    "QML.Element",
    "darkestChanged",
    "",
    "darkerChanged",
    "darkChanged",
    "normalChanged",
    "lightChanged",
    "lighterChanged",
    "lightestChanged",
    "darkest",
    "darker",
    "dark",
    "normal",
    "light",
    "lighter",
    "lightest"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSFluAccentColorENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       1,   14, // classinfo
       7,   16, // methods
       7,   65, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // classinfo: key, value
       1,    0,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       2,    0,   58,    3, 0x06,    8 /* Public */,
       4,    0,   59,    3, 0x06,    9 /* Public */,
       5,    0,   60,    3, 0x06,   10 /* Public */,
       6,    0,   61,    3, 0x06,   11 /* Public */,
       7,    0,   62,    3, 0x06,   12 /* Public */,
       8,    0,   63,    3, 0x06,   13 /* Public */,
       9,    0,   64,    3, 0x06,   14 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      10, QMetaType::QColor, 0x00015003, uint(0), 0,
      11, QMetaType::QColor, 0x00015003, uint(1), 0,
      12, QMetaType::QColor, 0x00015003, uint(2), 0,
      13, QMetaType::QColor, 0x00015003, uint(3), 0,
      14, QMetaType::QColor, 0x00015003, uint(4), 0,
      15, QMetaType::QColor, 0x00015003, uint(5), 0,
      16, QMetaType::QColor, 0x00015003, uint(6), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject FluAccentColor::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSFluAccentColorENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSFluAccentColorENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_metaTypeArray<
        // property 'darkest'
        QColor,
        // property 'darker'
        QColor,
        // property 'dark'
        QColor,
        // property 'normal'
        QColor,
        // property 'light'
        QColor,
        // property 'lighter'
        QColor,
        // property 'lightest'
        QColor,
        // Q_OBJECT / Q_GADGET
        FluAccentColor,
        // method 'darkestChanged'
        void,
        // method 'darkerChanged'
        void,
        // method 'darkChanged'
        void,
        // method 'normalChanged'
        void,
        // method 'lightChanged'
        void,
        // method 'lighterChanged'
        void,
        // method 'lightestChanged'
        void
    >,
    nullptr
} };

void FluAccentColor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FluAccentColor *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->darkestChanged(); break;
        case 1: _t->darkerChanged(); break;
        case 2: _t->darkChanged(); break;
        case 3: _t->normalChanged(); break;
        case 4: _t->lightChanged(); break;
        case 5: _t->lighterChanged(); break;
        case 6: _t->lightestChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FluAccentColor::*)();
            if (_t _q_method = &FluAccentColor::darkestChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FluAccentColor::*)();
            if (_t _q_method = &FluAccentColor::darkerChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FluAccentColor::*)();
            if (_t _q_method = &FluAccentColor::darkChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (FluAccentColor::*)();
            if (_t _q_method = &FluAccentColor::normalChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (FluAccentColor::*)();
            if (_t _q_method = &FluAccentColor::lightChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (FluAccentColor::*)();
            if (_t _q_method = &FluAccentColor::lighterChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (FluAccentColor::*)();
            if (_t _q_method = &FluAccentColor::lightestChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<FluAccentColor *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QColor*>(_v) = _t->_darkest; break;
        case 1: *reinterpret_cast< QColor*>(_v) = _t->_darker; break;
        case 2: *reinterpret_cast< QColor*>(_v) = _t->_dark; break;
        case 3: *reinterpret_cast< QColor*>(_v) = _t->_normal; break;
        case 4: *reinterpret_cast< QColor*>(_v) = _t->_light; break;
        case 5: *reinterpret_cast< QColor*>(_v) = _t->_lighter; break;
        case 6: *reinterpret_cast< QColor*>(_v) = _t->_lightest; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<FluAccentColor *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0:
            if (_t->_darkest != *reinterpret_cast< QColor*>(_v)) {
                _t->_darkest = *reinterpret_cast< QColor*>(_v);
                Q_EMIT _t->darkestChanged();
            }
            break;
        case 1:
            if (_t->_darker != *reinterpret_cast< QColor*>(_v)) {
                _t->_darker = *reinterpret_cast< QColor*>(_v);
                Q_EMIT _t->darkerChanged();
            }
            break;
        case 2:
            if (_t->_dark != *reinterpret_cast< QColor*>(_v)) {
                _t->_dark = *reinterpret_cast< QColor*>(_v);
                Q_EMIT _t->darkChanged();
            }
            break;
        case 3:
            if (_t->_normal != *reinterpret_cast< QColor*>(_v)) {
                _t->_normal = *reinterpret_cast< QColor*>(_v);
                Q_EMIT _t->normalChanged();
            }
            break;
        case 4:
            if (_t->_light != *reinterpret_cast< QColor*>(_v)) {
                _t->_light = *reinterpret_cast< QColor*>(_v);
                Q_EMIT _t->lightChanged();
            }
            break;
        case 5:
            if (_t->_lighter != *reinterpret_cast< QColor*>(_v)) {
                _t->_lighter = *reinterpret_cast< QColor*>(_v);
                Q_EMIT _t->lighterChanged();
            }
            break;
        case 6:
            if (_t->_lightest != *reinterpret_cast< QColor*>(_v)) {
                _t->_lightest = *reinterpret_cast< QColor*>(_v);
                Q_EMIT _t->lightestChanged();
            }
            break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
    (void)_a;
}

const QMetaObject *FluAccentColor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FluAccentColor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSFluAccentColorENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FluAccentColor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void FluAccentColor::darkestChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void FluAccentColor::darkerChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void FluAccentColor::darkChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void FluAccentColor::normalChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void FluAccentColor::lightChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void FluAccentColor::lighterChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void FluAccentColor::lightestChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
