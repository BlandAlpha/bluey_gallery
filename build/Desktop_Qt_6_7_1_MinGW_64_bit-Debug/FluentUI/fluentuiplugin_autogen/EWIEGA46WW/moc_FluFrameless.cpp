/****************************************************************************
** Meta object code from reading C++ file 'FluFrameless.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../FluentUI/FluFrameless.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FluFrameless.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSFluFramelessENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSFluFramelessENDCLASS = QtMocHelpers::stringData(
    "FluFrameless",
    "QML.Element",
    "appbarChanged",
    "",
    "maximizeButtonChanged",
    "minimizedButtonChanged",
    "closeButtonChanged",
    "topmostChanged",
    "disabledChanged",
    "fixSizeChanged",
    "showFullScreen",
    "showMaximized",
    "showMinimized",
    "showNormal",
    "setHitTestVisible",
    "QQuickItem*",
    "onDestruction",
    "appbar",
    "maximizeButton",
    "minimizedButton",
    "closeButton",
    "topmost",
    "disabled",
    "fixSize"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSFluFramelessENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       1,   14, // classinfo
      13,   16, // methods
       7,  109, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // classinfo: key, value
       1,    0,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       2,    0,   94,    3, 0x06,    8 /* Public */,
       4,    0,   95,    3, 0x06,    9 /* Public */,
       5,    0,   96,    3, 0x06,   10 /* Public */,
       6,    0,   97,    3, 0x06,   11 /* Public */,
       7,    0,   98,    3, 0x06,   12 /* Public */,
       8,    0,   99,    3, 0x06,   13 /* Public */,
       9,    0,  100,    3, 0x06,   14 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      10,    0,  101,    3, 0x02,   15 /* Public */,
      11,    0,  102,    3, 0x02,   16 /* Public */,
      12,    0,  103,    3, 0x02,   17 /* Public */,
      13,    0,  104,    3, 0x02,   18 /* Public */,
      14,    1,  105,    3, 0x02,   19 /* Public */,
      16,    0,  108,    3, 0x02,   21 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,    3,
    QMetaType::Void,

 // properties: name, type, flags
      17, 0x80000000 | 15, 0x0001500b, uint(0), 0,
      18, 0x80000000 | 15, 0x0001500b, uint(1), 0,
      19, 0x80000000 | 15, 0x0001500b, uint(2), 0,
      20, 0x80000000 | 15, 0x0001500b, uint(3), 0,
      21, QMetaType::Bool, 0x00015003, uint(4), 0,
      22, QMetaType::Bool, 0x00015003, uint(5), 0,
      23, QMetaType::Bool, 0x00015003, uint(6), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject FluFrameless::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickItem::staticMetaObject>(),
    qt_meta_stringdata_CLASSFluFramelessENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSFluFramelessENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_metaTypeArray<
        // property 'appbar'
        QQuickItem*,
        // property 'maximizeButton'
        QQuickItem*,
        // property 'minimizedButton'
        QQuickItem*,
        // property 'closeButton'
        QQuickItem*,
        // property 'topmost'
        bool,
        // property 'disabled'
        bool,
        // property 'fixSize'
        bool,
        // Q_OBJECT / Q_GADGET
        FluFrameless,
        // method 'appbarChanged'
        void,
        // method 'maximizeButtonChanged'
        void,
        // method 'minimizedButtonChanged'
        void,
        // method 'closeButtonChanged'
        void,
        // method 'topmostChanged'
        void,
        // method 'disabledChanged'
        void,
        // method 'fixSizeChanged'
        void,
        // method 'showFullScreen'
        void,
        // method 'showMaximized'
        void,
        // method 'showMinimized'
        void,
        // method 'showNormal'
        void,
        // method 'setHitTestVisible'
        void,
        QQuickItem *,
        // method 'onDestruction'
        void
    >,
    nullptr
} };

void FluFrameless::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FluFrameless *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->appbarChanged(); break;
        case 1: _t->maximizeButtonChanged(); break;
        case 2: _t->minimizedButtonChanged(); break;
        case 3: _t->closeButtonChanged(); break;
        case 4: _t->topmostChanged(); break;
        case 5: _t->disabledChanged(); break;
        case 6: _t->fixSizeChanged(); break;
        case 7: _t->showFullScreen(); break;
        case 8: _t->showMaximized(); break;
        case 9: _t->showMinimized(); break;
        case 10: _t->showNormal(); break;
        case 11: _t->setHitTestVisible((*reinterpret_cast< std::add_pointer_t<QQuickItem*>>(_a[1]))); break;
        case 12: _t->onDestruction(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QQuickItem* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FluFrameless::*)();
            if (_t _q_method = &FluFrameless::appbarChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FluFrameless::*)();
            if (_t _q_method = &FluFrameless::maximizeButtonChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FluFrameless::*)();
            if (_t _q_method = &FluFrameless::minimizedButtonChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (FluFrameless::*)();
            if (_t _q_method = &FluFrameless::closeButtonChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (FluFrameless::*)();
            if (_t _q_method = &FluFrameless::topmostChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (FluFrameless::*)();
            if (_t _q_method = &FluFrameless::disabledChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (FluFrameless::*)();
            if (_t _q_method = &FluFrameless::fixSizeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
        case 2:
        case 1:
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QQuickItem* >(); break;
        }
    }  else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<FluFrameless *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QQuickItem**>(_v) = _t->_appbar; break;
        case 1: *reinterpret_cast< QQuickItem**>(_v) = _t->_maximizeButton; break;
        case 2: *reinterpret_cast< QQuickItem**>(_v) = _t->_minimizedButton; break;
        case 3: *reinterpret_cast< QQuickItem**>(_v) = _t->_closeButton; break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->_topmost; break;
        case 5: *reinterpret_cast< bool*>(_v) = _t->_disabled; break;
        case 6: *reinterpret_cast< bool*>(_v) = _t->_fixSize; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<FluFrameless *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0:
            if (_t->_appbar != *reinterpret_cast< QQuickItem**>(_v)) {
                _t->_appbar = *reinterpret_cast< QQuickItem**>(_v);
                Q_EMIT _t->appbarChanged();
            }
            break;
        case 1:
            if (_t->_maximizeButton != *reinterpret_cast< QQuickItem**>(_v)) {
                _t->_maximizeButton = *reinterpret_cast< QQuickItem**>(_v);
                Q_EMIT _t->maximizeButtonChanged();
            }
            break;
        case 2:
            if (_t->_minimizedButton != *reinterpret_cast< QQuickItem**>(_v)) {
                _t->_minimizedButton = *reinterpret_cast< QQuickItem**>(_v);
                Q_EMIT _t->minimizedButtonChanged();
            }
            break;
        case 3:
            if (_t->_closeButton != *reinterpret_cast< QQuickItem**>(_v)) {
                _t->_closeButton = *reinterpret_cast< QQuickItem**>(_v);
                Q_EMIT _t->closeButtonChanged();
            }
            break;
        case 4:
            if (_t->_topmost != *reinterpret_cast< bool*>(_v)) {
                _t->_topmost = *reinterpret_cast< bool*>(_v);
                Q_EMIT _t->topmostChanged();
            }
            break;
        case 5:
            if (_t->_disabled != *reinterpret_cast< bool*>(_v)) {
                _t->_disabled = *reinterpret_cast< bool*>(_v);
                Q_EMIT _t->disabledChanged();
            }
            break;
        case 6:
            if (_t->_fixSize != *reinterpret_cast< bool*>(_v)) {
                _t->_fixSize = *reinterpret_cast< bool*>(_v);
                Q_EMIT _t->fixSizeChanged();
            }
            break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *FluFrameless::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FluFrameless::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSFluFramelessENDCLASS.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QAbstractNativeEventFilter"))
        return static_cast< QAbstractNativeEventFilter*>(this);
    return QQuickItem::qt_metacast(_clname);
}

int FluFrameless::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void FluFrameless::appbarChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void FluFrameless::maximizeButtonChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void FluFrameless::minimizedButtonChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void FluFrameless::closeButtonChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void FluFrameless::topmostChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void FluFrameless::disabledChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void FluFrameless::fixSizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
