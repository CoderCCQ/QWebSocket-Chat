/****************************************************************************
** Meta object code from reading C++ file 'echoserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../echoserver/echoserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'echoserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EchoServer_t {
    QByteArrayData data[15];
    char stringdata0[177];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EchoServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EchoServer_t qt_meta_stringdata_EchoServer = {
    {
QT_MOC_LITERAL(0, 0, 10), // "EchoServer"
QT_MOC_LITERAL(1, 11, 6), // "closed"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 15), // "onNewConnection"
QT_MOC_LITERAL(4, 35, 18), // "processTextMessage"
QT_MOC_LITERAL(5, 54, 7), // "message"
QT_MOC_LITERAL(6, 62, 20), // "processBinaryMessage"
QT_MOC_LITERAL(7, 83, 18), // "socketDisconnected"
QT_MOC_LITERAL(8, 102, 11), // "textMessage"
QT_MOC_LITERAL(9, 114, 6), // "sender"
QT_MOC_LITERAL(10, 121, 4), // "json"
QT_MOC_LITERAL(11, 126, 7), // "loginIn"
QT_MOC_LITERAL(12, 134, 15), // "getCurrentUsers"
QT_MOC_LITERAL(13, 150, 10), // "getHistory"
QT_MOC_LITERAL(14, 161, 15) // "newRegistration"

    },
    "EchoServer\0closed\0\0onNewConnection\0"
    "processTextMessage\0message\0"
    "processBinaryMessage\0socketDisconnected\0"
    "textMessage\0sender\0json\0loginIn\0"
    "getCurrentUsers\0getHistory\0newRegistration"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EchoServer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   65,    2, 0x08 /* Private */,
       4,    1,   66,    2, 0x08 /* Private */,
       6,    1,   69,    2, 0x08 /* Private */,
       7,    0,   72,    2, 0x08 /* Private */,
       8,    2,   73,    2, 0x08 /* Private */,
      11,    2,   78,    2, 0x08 /* Private */,
      12,    2,   83,    2, 0x08 /* Private */,
      13,    2,   88,    2, 0x08 /* Private */,
      14,    2,   93,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QByteArray,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QObjectStar, QMetaType::QJsonObject,    9,   10,
    QMetaType::Void, QMetaType::QObjectStar, QMetaType::QJsonObject,    9,   10,
    QMetaType::Void, QMetaType::QObjectStar, QMetaType::QJsonObject,    9,   10,
    QMetaType::Void, QMetaType::QObjectStar, QMetaType::QJsonObject,    9,   10,
    QMetaType::Void, QMetaType::QObjectStar, QMetaType::QJsonObject,    9,   10,

       0        // eod
};

void EchoServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EchoServer *_t = static_cast<EchoServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closed(); break;
        case 1: _t->onNewConnection(); break;
        case 2: _t->processTextMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->processBinaryMessage((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 4: _t->socketDisconnected(); break;
        case 5: _t->textMessage((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< const QJsonObject(*)>(_a[2]))); break;
        case 6: _t->loginIn((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< const QJsonObject(*)>(_a[2]))); break;
        case 7: _t->getCurrentUsers((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< const QJsonObject(*)>(_a[2]))); break;
        case 8: _t->getHistory((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< const QJsonObject(*)>(_a[2]))); break;
        case 9: _t->newRegistration((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< const QJsonObject(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (EchoServer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EchoServer::closed)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject EchoServer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_EchoServer.data,
      qt_meta_data_EchoServer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *EchoServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EchoServer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_EchoServer.stringdata0))
        return static_cast<void*>(const_cast< EchoServer*>(this));
    return QObject::qt_metacast(_clname);
}

int EchoServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void EchoServer::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
