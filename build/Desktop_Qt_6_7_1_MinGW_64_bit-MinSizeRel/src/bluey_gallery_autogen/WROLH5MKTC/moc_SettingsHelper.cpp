/****************************************************************************
** Meta object code from reading C++ file 'SettingsHelper.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/src/helper/SettingsHelper.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SettingsHelper.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSSettingsHelperENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSSettingsHelperENDCLASS = QtMocHelpers::stringData(
    "SettingsHelper",
    "saveDarkMode",
    "",
    "darkModel",
    "getDarkMode",
    "saveUseSystemAppBar",
    "useSystemAppBar",
    "getUseSystemAppBar",
    "saveLanguage",
    "language",
    "getLanguage"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSettingsHelperENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x02,    1 /* Public */,
       4,    0,   53,    2, 0x02,    3 /* Public */,
       5,    1,   54,    2, 0x02,    4 /* Public */,
       7,    0,   57,    2, 0x02,    6 /* Public */,
       8,    1,   58,    2, 0x02,    7 /* Public */,
      10,    0,   61,    2, 0x02,    9 /* Public */,

 // methods: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::QString,

       0        // eod
};

Q_CONSTINIT const QMetaObject SettingsHelper::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSSettingsHelperENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSettingsHelperENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSettingsHelperENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SettingsHelper, std::true_type>,
        // method 'saveDarkMode'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getDarkMode'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'saveUseSystemAppBar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'getUseSystemAppBar'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'saveLanguage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'getLanguage'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>
    >,
    nullptr
} };

void SettingsHelper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SettingsHelper *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->saveDarkMode((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: { int _r = _t->getDarkMode();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->saveUseSystemAppBar((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: { bool _r = _t->getUseSystemAppBar();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->saveLanguage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: { QString _r = _t->getLanguage();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *SettingsHelper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SettingsHelper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSettingsHelperENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SettingsHelper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
    }
    return _id;
}
QT_WARNING_POP
