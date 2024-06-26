/****************************************************************************
** Meta object code from reading C++ file 'FluTextStyle.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../FluentUI/FluTextStyle.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FluTextStyle.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSFluTextStyleENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSFluTextStyleENDCLASS = QtMocHelpers::stringData(
    "FluTextStyle",
    "QML.Element",
    "QML.Singleton",
    "true",
    "familyChanged",
    "",
    "CaptionChanged",
    "BodyChanged",
    "BodyStrongChanged",
    "SubtitleChanged",
    "TitleChanged",
    "TitleLargeChanged",
    "DisplayChanged",
    "family",
    "Caption",
    "Body",
    "BodyStrong",
    "Subtitle",
    "Title",
    "TitleLarge",
    "Display"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSFluTextStyleENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       2,   14, // classinfo
       8,   18, // methods
       8,   74, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // classinfo: key, value
       1,    0,
       2,    3,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   66,    5, 0x06,    9 /* Public */,
       6,    0,   67,    5, 0x06,   10 /* Public */,
       7,    0,   68,    5, 0x06,   11 /* Public */,
       8,    0,   69,    5, 0x06,   12 /* Public */,
       9,    0,   70,    5, 0x06,   13 /* Public */,
      10,    0,   71,    5, 0x06,   14 /* Public */,
      11,    0,   72,    5, 0x06,   15 /* Public */,
      12,    0,   73,    5, 0x06,   16 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      13, QMetaType::QString, 0x00015003, uint(0), 0,
      14, QMetaType::QFont, 0x00015003, uint(1), 0,
      15, QMetaType::QFont, 0x00015003, uint(2), 0,
      16, QMetaType::QFont, 0x00015003, uint(3), 0,
      17, QMetaType::QFont, 0x00015003, uint(4), 0,
      18, QMetaType::QFont, 0x00015003, uint(5), 0,
      19, QMetaType::QFont, 0x00015003, uint(6), 0,
      20, QMetaType::QFont, 0x00015003, uint(7), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject FluTextStyle::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSFluTextStyleENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSFluTextStyleENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_metaTypeArray<
        // property 'family'
        QString,
        // property 'Caption'
        QFont,
        // property 'Body'
        QFont,
        // property 'BodyStrong'
        QFont,
        // property 'Subtitle'
        QFont,
        // property 'Title'
        QFont,
        // property 'TitleLarge'
        QFont,
        // property 'Display'
        QFont,
        // Q_OBJECT / Q_GADGET
        FluTextStyle,
        // method 'familyChanged'
        void,
        // method 'CaptionChanged'
        void,
        // method 'BodyChanged'
        void,
        // method 'BodyStrongChanged'
        void,
        // method 'SubtitleChanged'
        void,
        // method 'TitleChanged'
        void,
        // method 'TitleLargeChanged'
        void,
        // method 'DisplayChanged'
        void
    >,
    nullptr
} };

void FluTextStyle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FluTextStyle *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->familyChanged(); break;
        case 1: _t->CaptionChanged(); break;
        case 2: _t->BodyChanged(); break;
        case 3: _t->BodyStrongChanged(); break;
        case 4: _t->SubtitleChanged(); break;
        case 5: _t->TitleChanged(); break;
        case 6: _t->TitleLargeChanged(); break;
        case 7: _t->DisplayChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FluTextStyle::*)();
            if (_t _q_method = &FluTextStyle::familyChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FluTextStyle::*)();
            if (_t _q_method = &FluTextStyle::CaptionChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FluTextStyle::*)();
            if (_t _q_method = &FluTextStyle::BodyChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (FluTextStyle::*)();
            if (_t _q_method = &FluTextStyle::BodyStrongChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (FluTextStyle::*)();
            if (_t _q_method = &FluTextStyle::SubtitleChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (FluTextStyle::*)();
            if (_t _q_method = &FluTextStyle::TitleChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (FluTextStyle::*)();
            if (_t _q_method = &FluTextStyle::TitleLargeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (FluTextStyle::*)();
            if (_t _q_method = &FluTextStyle::DisplayChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<FluTextStyle *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->_family; break;
        case 1: *reinterpret_cast< QFont*>(_v) = _t->_Caption; break;
        case 2: *reinterpret_cast< QFont*>(_v) = _t->_Body; break;
        case 3: *reinterpret_cast< QFont*>(_v) = _t->_BodyStrong; break;
        case 4: *reinterpret_cast< QFont*>(_v) = _t->_Subtitle; break;
        case 5: *reinterpret_cast< QFont*>(_v) = _t->_Title; break;
        case 6: *reinterpret_cast< QFont*>(_v) = _t->_TitleLarge; break;
        case 7: *reinterpret_cast< QFont*>(_v) = _t->_Display; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<FluTextStyle *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0:
            if (_t->_family != *reinterpret_cast< QString*>(_v)) {
                _t->_family = *reinterpret_cast< QString*>(_v);
                Q_EMIT _t->familyChanged();
            }
            break;
        case 1:
            if (_t->_Caption != *reinterpret_cast< QFont*>(_v)) {
                _t->_Caption = *reinterpret_cast< QFont*>(_v);
                Q_EMIT _t->CaptionChanged();
            }
            break;
        case 2:
            if (_t->_Body != *reinterpret_cast< QFont*>(_v)) {
                _t->_Body = *reinterpret_cast< QFont*>(_v);
                Q_EMIT _t->BodyChanged();
            }
            break;
        case 3:
            if (_t->_BodyStrong != *reinterpret_cast< QFont*>(_v)) {
                _t->_BodyStrong = *reinterpret_cast< QFont*>(_v);
                Q_EMIT _t->BodyStrongChanged();
            }
            break;
        case 4:
            if (_t->_Subtitle != *reinterpret_cast< QFont*>(_v)) {
                _t->_Subtitle = *reinterpret_cast< QFont*>(_v);
                Q_EMIT _t->SubtitleChanged();
            }
            break;
        case 5:
            if (_t->_Title != *reinterpret_cast< QFont*>(_v)) {
                _t->_Title = *reinterpret_cast< QFont*>(_v);
                Q_EMIT _t->TitleChanged();
            }
            break;
        case 6:
            if (_t->_TitleLarge != *reinterpret_cast< QFont*>(_v)) {
                _t->_TitleLarge = *reinterpret_cast< QFont*>(_v);
                Q_EMIT _t->TitleLargeChanged();
            }
            break;
        case 7:
            if (_t->_Display != *reinterpret_cast< QFont*>(_v)) {
                _t->_Display = *reinterpret_cast< QFont*>(_v);
                Q_EMIT _t->DisplayChanged();
            }
            break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
    (void)_a;
}

const QMetaObject *FluTextStyle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FluTextStyle::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSFluTextStyleENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FluTextStyle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void FluTextStyle::familyChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void FluTextStyle::CaptionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void FluTextStyle::BodyChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void FluTextStyle::BodyStrongChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void FluTextStyle::SubtitleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void FluTextStyle::TitleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void FluTextStyle::TitleLargeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void FluTextStyle::DisplayChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
