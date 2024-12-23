// /qt/qml/FluentUI/Controls/FluImageButton.qml
#include <QtQml/qqmlprivate.h>
#include <QtCore/qdatetime.h>
#include <QtCore/qobject.h>
#include <QtCore/qstring.h>
#include <QtCore/qstringlist.h>
#include <QtCore/qtimezone.h>
#include <QtCore/qurl.h>
#include <QtCore/qvariant.h>
#include <QtQml/qjsengine.h>
#include <QtQml/qjsprimitivevalue.h>
#include <QtQml/qjsvalue.h>
#include <QtQml/qqmlcomponent.h>
#include <QtQml/qqmlcontext.h>
#include <QtQml/qqmlengine.h>
#include <QtQml/qqmllist.h>
#include <type_traits>
namespace QmlCacheGeneratedCode {
namespace _qt_qml_FluentUI_Controls_FluImageButton_qml {
extern const unsigned char qmlData alignas(16) [];
extern const unsigned char qmlData alignas(16) [] = {

0x71,0x76,0x34,0x63,0x64,0x61,0x74,0x61,
0x3f,0x0,0x0,0x0,0x1,0x7,0x6,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0xd8,0x7,0x0,0x0,0x34,0x30,0x34,0x63,
0x33,0x61,0x66,0x64,0x66,0x39,0x30,0x37,
0x31,0x36,0x32,0x65,0x32,0x63,0x61,0x32,
0x34,0x66,0x62,0x36,0x35,0x39,0x38,0x63,
0x34,0x37,0x38,0x66,0x64,0x31,0x30,0x66,
0x31,0x39,0x66,0x65,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x46,0x7,0x95,0xa8,
0x81,0xed,0xf7,0xe6,0xc,0x31,0xb,0x25,
0x0,0xa1,0xf8,0x58,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x23,0x0,0x0,0x0,
0x17,0x0,0x0,0x0,0xf0,0x1,0x0,0x0,
0x2,0x0,0x0,0x0,0xf8,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,
0xb,0x0,0x0,0x0,0x0,0x1,0x0,0x0,
0x0,0x0,0x0,0x0,0x2c,0x1,0x0,0x0,
0x1,0x0,0x0,0x0,0x30,0x1,0x0,0x0,
0x0,0x0,0x0,0x0,0x38,0x1,0x0,0x0,
0x0,0x0,0x0,0x0,0x38,0x1,0x0,0x0,
0x0,0x0,0x0,0x0,0x38,0x1,0x0,0x0,
0x0,0x0,0x0,0x0,0x38,0x1,0x0,0x0,
0x0,0x0,0x0,0x0,0x38,0x1,0x0,0x0,
0x0,0x0,0x0,0x0,0x38,0x1,0x0,0x0,
0x0,0x0,0x0,0x0,0x38,0x1,0x0,0x0,
0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0xf8,0x4,0x0,0x0,
0x38,0x1,0x0,0x0,0xa0,0x1,0x0,0x0,
0x63,0x0,0x0,0x0,0x40,0x1,0x0,0x0,
0x63,0x0,0x0,0x0,0x50,0x1,0x0,0x0,
0x63,0x0,0x0,0x0,0x90,0x0,0x0,0x0,
0x63,0x0,0x0,0x0,0x80,0x0,0x0,0x0,
0x63,0x0,0x0,0x0,0x70,0x0,0x0,0x0,
0x63,0x1,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x40,0xdd,0x3f,
0x44,0x0,0x0,0x0,0x1f,0x0,0x0,0x0,
0x12,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x38,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x38,0x0,0x0,0x0,0x0,0x0,0x1,0x0,
0xff,0xff,0xff,0xff,0x7,0x0,0x0,0x0,
0x10,0x0,0xd0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x7,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x10,0x0,0x0,0x0,
0x1,0x0,0x0,0x0,0x2e,0x0,0x3c,0x1,
0x50,0x12,0x2e,0x2,0x3c,0x3,0x50,0x6,
0x2e,0x4,0x3c,0x5,0x4c,0x4,0x2e,0x6,
0x3c,0x7,0x4c,0x4,0x2e,0x8,0x3c,0x9,
0x18,0x6,0x2,0x0,0x0,0x0,0x0,0x0,
0x44,0x0,0x0,0x0,0x5,0x0,0x0,0x0,
0x10,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x38,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x38,0x0,0x0,0x0,0x0,0x0,0x1,0x0,
0xff,0xff,0xff,0xff,0x7,0x0,0x0,0x0,
0xf,0x0,0xd0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x7,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0xf,0x0,0x0,0x0,
0x1,0x0,0x0,0x0,0x2e,0xa,0x18,0x6,
0x2,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x50,0x2,0x0,0x0,0x58,0x2,0x0,0x0,
0x70,0x2,0x0,0x0,0x98,0x2,0x0,0x0,
0xd0,0x2,0x0,0x0,0xe8,0x2,0x0,0x0,
0x0,0x3,0x0,0x0,0x18,0x3,0x0,0x0,
0x38,0x3,0x0,0x0,0x58,0x3,0x0,0x0,
0x78,0x3,0x0,0x0,0x88,0x3,0x0,0x0,
0xb0,0x3,0x0,0x0,0xd0,0x3,0x0,0x0,
0xf0,0x3,0x0,0x0,0x8,0x4,0x0,0x0,
0x18,0x4,0x0,0x0,0x48,0x4,0x0,0x0,
0x60,0x4,0x0,0x0,0x90,0x4,0x0,0x0,
0xb0,0x4,0x0,0x0,0xc8,0x4,0x0,0x0,
0xe0,0x4,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x7,0x0,0x0,0x0,0x51,0x0,0x74,0x0,
0x51,0x0,0x75,0x0,0x69,0x0,0x63,0x0,
0x6b,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x10,0x0,0x0,0x0,0x51,0x0,0x74,0x0,
0x51,0x0,0x75,0x0,0x69,0x0,0x63,0x0,
0x6b,0x0,0x2e,0x0,0x43,0x0,0x6f,0x0,
0x6e,0x0,0x74,0x0,0x72,0x0,0x6f,0x0,
0x6c,0x0,0x73,0x0,0x0,0x0,0x0,0x0,
0x16,0x0,0x0,0x0,0x51,0x0,0x74,0x0,
0x51,0x0,0x75,0x0,0x69,0x0,0x63,0x0,
0x6b,0x0,0x2e,0x0,0x43,0x0,0x6f,0x0,
0x6e,0x0,0x74,0x0,0x72,0x0,0x6f,0x0,
0x6c,0x0,0x73,0x0,0x2e,0x0,0x42,0x0,
0x61,0x0,0x73,0x0,0x69,0x0,0x63,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x8,0x0,0x0,0x0,0x46,0x0,0x6c,0x0,
0x75,0x0,0x65,0x0,0x6e,0x0,0x74,0x0,
0x55,0x0,0x49,0x0,0x0,0x0,0x0,0x0,
0x6,0x0,0x0,0x0,0x42,0x0,0x75,0x0,
0x74,0x0,0x74,0x0,0x6f,0x0,0x6e,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x7,0x0,0x0,0x0,0x63,0x0,0x6f,0x0,
0x6e,0x0,0x74,0x0,0x72,0x0,0x6f,0x0,
0x6c,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0xb,0x0,0x0,0x0,0x6e,0x0,0x6f,0x0,
0x72,0x0,0x6d,0x0,0x61,0x0,0x6c,0x0,
0x49,0x0,0x6d,0x0,0x61,0x0,0x67,0x0,
0x65,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0xc,0x0,0x0,0x0,0x68,0x0,0x6f,0x0,
0x76,0x0,0x65,0x0,0x72,0x0,0x65,0x0,
0x64,0x0,0x49,0x0,0x6d,0x0,0x61,0x0,
0x67,0x0,0x65,0x0,0x0,0x0,0x0,0x0,
0xb,0x0,0x0,0x0,0x70,0x0,0x75,0x0,
0x73,0x0,0x68,0x0,0x65,0x0,0x64,0x0,
0x49,0x0,0x6d,0x0,0x61,0x0,0x67,0x0,
0x65,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x4,0x0,0x0,0x0,0x49,0x0,0x74,0x0,
0x65,0x0,0x6d,0x0,0x0,0x0,0x0,0x0,
0xe,0x0,0x0,0x0,0x69,0x0,0x6d,0x0,
0x70,0x0,0x6c,0x0,0x69,0x0,0x63,0x0,
0x69,0x0,0x74,0x0,0x48,0x0,0x65,0x0,
0x69,0x0,0x67,0x0,0x68,0x0,0x74,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0xd,0x0,0x0,0x0,0x69,0x0,0x6d,0x0,
0x70,0x0,0x6c,0x0,0x69,0x0,0x63,0x0,
0x69,0x0,0x74,0x0,0x57,0x0,0x69,0x0,
0x64,0x0,0x74,0x0,0x68,0x0,0x0,0x0,
0xb,0x0,0x0,0x0,0x42,0x0,0x6f,0x0,
0x72,0x0,0x64,0x0,0x65,0x0,0x72,0x0,
0x49,0x0,0x6d,0x0,0x61,0x0,0x67,0x0,
0x65,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x7,0x0,0x0,0x0,0x61,0x0,0x6e,0x0,
0x63,0x0,0x68,0x0,0x6f,0x0,0x72,0x0,
0x73,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x4,0x0,0x0,0x0,0x66,0x0,0x69,0x0,
0x6c,0x0,0x6c,0x0,0x0,0x0,0x0,0x0,
0x13,0x0,0x0,0x0,0x65,0x0,0x78,0x0,
0x70,0x0,0x72,0x0,0x65,0x0,0x73,0x0,
0x73,0x0,0x69,0x0,0x6f,0x0,0x6e,0x0,
0x20,0x0,0x66,0x0,0x6f,0x0,0x72,0x0,
0x20,0x0,0x66,0x0,0x69,0x0,0x6c,0x0,
0x6c,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x6,0x0,0x0,0x0,0x73,0x0,0x6f,0x0,
0x75,0x0,0x72,0x0,0x63,0x0,0x65,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x15,0x0,0x0,0x0,0x65,0x0,0x78,0x0,
0x70,0x0,0x72,0x0,0x65,0x0,0x73,0x0,
0x73,0x0,0x69,0x0,0x6f,0x0,0x6e,0x0,
0x20,0x0,0x66,0x0,0x6f,0x0,0x72,0x0,
0x20,0x0,0x73,0x0,0x6f,0x0,0x75,0x0,
0x72,0x0,0x63,0x0,0x65,0x0,0x0,0x0,
0xa,0x0,0x0,0x0,0x62,0x0,0x61,0x0,
0x63,0x0,0x6b,0x0,0x67,0x0,0x72,0x0,
0x6f,0x0,0x75,0x0,0x6e,0x0,0x64,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x7,0x0,0x0,0x0,0x68,0x0,0x6f,0x0,
0x76,0x0,0x65,0x0,0x72,0x0,0x65,0x0,
0x64,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x7,0x0,0x0,0x0,0x70,0x0,0x72,0x0,
0x65,0x0,0x73,0x0,0x73,0x0,0x65,0x0,
0x64,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x6,0x0,0x0,0x0,0x70,0x0,0x61,0x0,
0x72,0x0,0x65,0x0,0x6e,0x0,0x74,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x4,0x0,0x0,0x0,0x10,0x0,0x0,0x0,
0x4,0x0,0x0,0x0,0x60,0x0,0x0,0x0,
0x1,0x0,0x0,0x0,0x1,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x1,0x0,0x10,0x0,
0xff,0xff,0x0,0x0,0x1,0x0,0x0,0x0,
0x2,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x2,0x0,0x10,0x0,0xff,0xff,0x0,0x0,
0x1,0x0,0x0,0x0,0x3,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x3,0x0,0x10,0x0,
0xff,0xff,0x0,0x0,0x1,0x0,0x0,0x0,
0x4,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x4,0x0,0x10,0x0,0xff,0xff,0x0,0x0,
0x70,0x0,0x0,0x0,0x48,0x1,0x0,0x0,
0xe8,0x1,0x0,0x0,0x70,0x2,0x0,0x0,
0x5,0x0,0x0,0x0,0x6,0x0,0x0,0x0,
0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,
0x0,0x0,0x3,0x0,0x54,0x0,0x0,0x0,
0x54,0x0,0x0,0x0,0x78,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x78,0x0,0x0,0x0,
0x78,0x0,0x0,0x0,0x0,0x0,0x4,0x0,
0x78,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0xd8,0x0,0x0,0x0,0x6,0x0,0x10,0x0,
0x7,0x0,0x50,0x0,0xd8,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0xd8,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x7,0x0,0x0,0x0,
0x5,0x0,0x0,0x20,0x8,0x0,0x50,0x0,
0x8,0x0,0x0,0x0,0x5,0x0,0x0,0x20,
0x9,0x0,0x50,0x0,0x9,0x0,0x0,0x0,
0x5,0x0,0x0,0x20,0xa,0x0,0x50,0x0,
0x13,0x0,0x0,0x0,0x0,0x0,0x8,0x0,
0x1,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0xb,0x0,0x50,0x0,0xb,0x0,0x10,0x1,
0x9,0x0,0x0,0x0,0x0,0x0,0x3,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0xa,0x0,0x50,0x1,0xa,0x0,0x20,0x2,
0x8,0x0,0x0,0x0,0x0,0x0,0x3,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x9,0x0,0x50,0x1,0x9,0x0,0x30,0x2,
0x7,0x0,0x0,0x0,0x0,0x0,0x3,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x8,0x0,0x50,0x1,0x8,0x0,0x20,0x2,
0xa,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,
0x0,0x0,0x0,0x0,0x54,0x0,0x0,0x0,
0x54,0x0,0x0,0x0,0x54,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x54,0x0,0x0,0x0,
0x54,0x0,0x0,0x0,0x0,0x0,0x3,0x0,
0x54,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x9c,0x0,0x0,0x0,0xb,0x0,0x10,0x1,
0x0,0x0,0x0,0x0,0x9c,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x9c,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0xc,0x0,0x0,0x0,
0x0,0x0,0x2,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0xd,0x0,0x90,0x0,
0xd,0x0,0x80,0x1,0xb,0x0,0x0,0x0,
0x0,0x0,0x2,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0xc,0x0,0x90,0x0,
0xc,0x0,0x90,0x1,0x0,0x0,0x0,0x0,
0x0,0x0,0x8,0x0,0x2,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0xe,0x0,0x90,0x0,
0xe,0x0,0x90,0x0,0x0,0x0,0x0,0x0,
0xd,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,
0x0,0x0,0x0,0x0,0x54,0x0,0x0,0x0,
0x54,0x0,0x0,0x0,0x54,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x54,0x0,0x0,0x0,
0x54,0x0,0x0,0x0,0x0,0x0,0x2,0x0,
0x54,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x84,0x0,0x0,0x0,0xe,0x0,0x90,0x0,
0x0,0x0,0x0,0x0,0x84,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x84,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x11,0x0,0x0,0x0,
0x0,0x0,0x7,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x10,0x0,0xd0,0x0,
0x10,0x0,0x50,0x1,0xe,0x0,0x0,0x0,
0x0,0x0,0xa,0x0,0x3,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0xf,0x0,0xd0,0x0,
0xf,0x0,0x50,0x1,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,
0x0,0x0,0x0,0x0,0x54,0x0,0x0,0x0,
0x54,0x0,0x0,0x0,0x54,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x54,0x0,0x0,0x0,
0x54,0x0,0x0,0x0,0x0,0x0,0x1,0x0,
0x54,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x6c,0x0,0x0,0x0,0xf,0x0,0xd0,0x0,
0x0,0x0,0x0,0x0,0x6c,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x6c,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0xf,0x0,0x0,0x0,
0x0,0x0,0x7,0x0,0x1,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0xf,0x0,0x50,0x1,
0xf,0x0,0xb0,0x1,0x0,0x0,0x0,0x0
};
QT_WARNING_PUSH
QT_WARNING_DISABLE_MSVC(4573)

template <typename Binding>
void wrapCall(const QQmlPrivate::AOTCompiledContext *aotContext, void *dataPtr, void **argumentsPtr, Binding &&binding)
{
    using return_type = std::invoke_result_t<Binding, const QQmlPrivate::AOTCompiledContext *, void **>;
    if constexpr (std::is_same_v<return_type, void>) {
       Q_UNUSED(dataPtr)
       binding(aotContext, argumentsPtr);
    } else {
        if (dataPtr) {
           *static_cast<return_type *>(dataPtr) = binding(aotContext, argumentsPtr);
        } else {
           binding(aotContext, argumentsPtr);
        }
    }
}
extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[] = {
{ 0, QMetaType::fromType<QUrl>(), {  }, 
    [](const QQmlPrivate::AOTCompiledContext *context, void *data, void **argv) {
        wrapCall(context, data, argv, [](const QQmlPrivate::AOTCompiledContext *aotContext, void **argumentsPtr) {
Q_UNUSED(aotContext)
Q_UNUSED(argumentsPtr)
// expression for source at line 16, column 13
QUrl r2_7;
QUrl r2_5;
QObject *r2_2;
QObject *r2_9;
QUrl r2_8;
QObject *r2_6;
QObject *r2_0;
QUrl r2_10;
bool r2_1;
bool r2_3;
QObject *r2_4;
// generate_LoadQmlContextPropertyLookup
#ifndef QT_NO_DEBUG
aotContext->setInstructionPointer(2);
#endif
while (!aotContext->loadContextIdLookup(0, &r2_0)) {
#ifdef QT_NO_DEBUG
aotContext->setInstructionPointer(2);
#endif
aotContext->initLoadContextIdLookup(0);
if (aotContext->engine->hasError())
    return QUrl();
}
{
}
// generate_GetLookup
#ifndef QT_NO_DEBUG
aotContext->setInstructionPointer(4);
#endif
while (!aotContext->getObjectLookup(1, r2_0, &r2_1)) {
#ifdef QT_NO_DEBUG
aotContext->setInstructionPointer(4);
#endif
aotContext->initGetObjectLookup(1, r2_0, QMetaType::fromType<bool>());
if (aotContext->engine->hasError())
    return QUrl();
}
{
}
// generate_JumpFalse
if (!r2_1) {
    goto label_0;
}
{
}
// generate_LoadQmlContextPropertyLookup
#ifndef QT_NO_DEBUG
aotContext->setInstructionPointer(8);
#endif
while (!aotContext->loadContextIdLookup(2, &r2_2)) {
#ifdef QT_NO_DEBUG
aotContext->setInstructionPointer(8);
#endif
aotContext->initLoadContextIdLookup(2);
if (aotContext->engine->hasError())
    return QUrl();
}
{
}
// generate_GetLookup
#ifndef QT_NO_DEBUG
aotContext->setInstructionPointer(10);
#endif
while (!aotContext->getObjectLookup(3, r2_2, &r2_3)) {
#ifdef QT_NO_DEBUG
aotContext->setInstructionPointer(10);
#endif
aotContext->initGetObjectLookup(3, r2_2, QMetaType::fromType<bool>());
if (aotContext->engine->hasError())
    return QUrl();
}
{
}
// generate_JumpFalse
if (!r2_3) {
    goto label_1;
}
{
}
// generate_LoadQmlContextPropertyLookup
#ifndef QT_NO_DEBUG
aotContext->setInstructionPointer(14);
#endif
while (!aotContext->loadContextIdLookup(4, &r2_4)) {
#ifdef QT_NO_DEBUG
aotContext->setInstructionPointer(14);
#endif
aotContext->initLoadContextIdLookup(4);
if (aotContext->engine->hasError())
    return QUrl();
}
{
}
// generate_GetLookup
{
QString retrieved;
#ifndef QT_NO_DEBUG
aotContext->setInstructionPointer(16);
#endif
while (!aotContext->getObjectLookup(5, r2_4, &retrieved)) {
#ifdef QT_NO_DEBUG
aotContext->setInstructionPointer(16);
#endif
aotContext->initGetObjectLookup(5, r2_4, QMetaType::fromType<QString>());
if (aotContext->engine->hasError())
    return QUrl();
}
r2_5 = QUrl(std::move(retrieved));
}
{
}
// generate_Jump
{
r2_8 = r2_5;
    goto label_2;
}
label_1:;
// generate_LoadQmlContextPropertyLookup
#ifndef QT_NO_DEBUG
aotContext->setInstructionPointer(20);
#endif
while (!aotContext->loadContextIdLookup(6, &r2_6)) {
#ifdef QT_NO_DEBUG
aotContext->setInstructionPointer(20);
#endif
aotContext->initLoadContextIdLookup(6);
if (aotContext->engine->hasError())
    return QUrl();
}
{
}
// generate_GetLookup
{
QString retrieved;
#ifndef QT_NO_DEBUG
aotContext->setInstructionPointer(22);
#endif
while (!aotContext->getObjectLookup(7, r2_6, &retrieved)) {
#ifdef QT_NO_DEBUG
aotContext->setInstructionPointer(22);
#endif
aotContext->initGetObjectLookup(7, r2_6, QMetaType::fromType<QString>());
if (aotContext->engine->hasError())
    return QUrl();
}
r2_7 = QUrl(std::move(retrieved));
}
{
r2_8 = std::move(r2_7);
}
label_2:;
// generate_Jump
{
    goto label_3;
}
label_0:;
// generate_LoadQmlContextPropertyLookup
#ifndef QT_NO_DEBUG
aotContext->setInstructionPointer(26);
#endif
while (!aotContext->loadContextIdLookup(8, &r2_9)) {
#ifdef QT_NO_DEBUG
aotContext->setInstructionPointer(26);
#endif
aotContext->initLoadContextIdLookup(8);
if (aotContext->engine->hasError())
    return QUrl();
}
{
}
// generate_GetLookup
{
QString retrieved;
#ifndef QT_NO_DEBUG
aotContext->setInstructionPointer(28);
#endif
while (!aotContext->getObjectLookup(9, r2_9, &retrieved)) {
#ifdef QT_NO_DEBUG
aotContext->setInstructionPointer(28);
#endif
aotContext->initGetObjectLookup(9, r2_9, QMetaType::fromType<QString>());
if (aotContext->engine->hasError())
    return QUrl();
}
r2_10 = QUrl(std::move(retrieved));
}
{
r2_8 = std::move(r2_10);
}
label_3:;
{
}
// generate_Ret
return r2_8;
});}
 },{ 1, QMetaType::fromType<QObject*>(), {  }, 
    [](const QQmlPrivate::AOTCompiledContext *context, void *data, void **argv) {
        wrapCall(context, data, argv, [](const QQmlPrivate::AOTCompiledContext *aotContext, void **argumentsPtr) {
Q_UNUSED(aotContext)
Q_UNUSED(argumentsPtr)
// expression for fill at line 15, column 13
QObject *r2_0;
// generate_LoadQmlContextPropertyLookup
#ifndef QT_NO_DEBUG
aotContext->setInstructionPointer(2);
#endif
while (!aotContext->loadScopeObjectPropertyLookup(10, &r2_0)) {
#ifdef QT_NO_DEBUG
aotContext->setInstructionPointer(2);
#endif
aotContext->initLoadScopeObjectPropertyLookup(10, []() { static const auto t = QMetaType::fromName("QQuickItem*"); return t; }());
if (aotContext->engine->hasError())
    return static_cast<QObject *>(nullptr);
}
{
}
{
}
// generate_Ret
return r2_0;
});}
 },{ 0, QMetaType::fromType<void>(), {}, nullptr }};
QT_WARNING_POP
}
}
