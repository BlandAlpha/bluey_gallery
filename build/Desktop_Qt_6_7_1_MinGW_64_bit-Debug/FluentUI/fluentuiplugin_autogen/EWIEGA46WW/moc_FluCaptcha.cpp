/****************************************************************************
** Meta object code from reading C++ file 'FluCaptcha.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../FluentUI/FluCaptcha.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FluCaptcha.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSFluCaptchaENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSFluCaptchaENDCLASS = QtMocHelpers::stringData(
    "FluCaptcha",
    "QML.Element",
    "fontChanged",
    "",
    "ignoreCaseChanged",
    "refresh",
    "verify",
    "code",
    "font",
    "ignoreCase"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSFluCaptchaENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       1,   14, // classinfo
       4,   16, // methods
       2,   46, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // classinfo: key, value
       1,    0,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       2,    0,   40,    3, 0x06,    3 /* Public */,
       4,    0,   41,    3, 0x06,    4 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   42,    3, 0x02,    5 /* Public */,
       6,    1,   43,    3, 0x02,    6 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,    7,

 // properties: name, type, flags
       8, QMetaType::QFont, 0x00015003, uint(0), 0,
       9, QMetaType::Bool, 0x00015003, uint(1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject FluCaptcha::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickPaintedItem::staticMetaObject>(),
    qt_meta_stringdata_CLASSFluCaptchaENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSFluCaptchaENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_metaTypeArray<
        // property 'font'
        QFont,
        // property 'ignoreCase'
        bool,
        // Q_OBJECT / Q_GADGET
        FluCaptcha,
        // method 'fontChanged'
        void,
        // method 'ignoreCaseChanged'
        void,
        // method 'refresh'
        void,
        // method 'verify'
        bool,
        const QString &
    >,
    nullptr
} };

void FluCaptcha::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FluCaptcha *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->fontChanged(); break;
        case 1: _t->ignoreCaseChanged(); break;
        case 2: _t->refresh(); break;
        case 3: { bool _r = _t->verify((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FluCaptcha::*)();
            if (_t _q_method = &FluCaptcha::fontChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FluCaptcha::*)();
            if (_t _q_method = &FluCaptcha::ignoreCaseChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<FluCaptcha *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QFont*>(_v) = _t->_font; break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->_ignoreCase; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<FluCaptcha *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0:
            if (_t->_font != *reinterpret_cast< QFont*>(_v)) {
                _t->_font = *reinterpret_cast< QFont*>(_v);
                Q_EMIT _t->fontChanged();
            }
            break;
        case 1:
            if (_t->_ignoreCase != *reinterpret_cast< bool*>(_v)) {
                _t->_ignoreCase = *reinterpret_cast< bool*>(_v);
                Q_EMIT _t->ignoreCaseChanged();
            }
            break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *FluCaptcha::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FluCaptcha::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSFluCaptchaENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QQuickPaintedItem::qt_metacast(_clname);
}

int FluCaptcha::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickPaintedItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void FluCaptcha::fontChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void FluCaptcha::ignoreCaseChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
