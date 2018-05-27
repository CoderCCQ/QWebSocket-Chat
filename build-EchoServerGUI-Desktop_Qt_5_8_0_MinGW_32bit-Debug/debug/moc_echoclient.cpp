/****************************************************************************
** Meta object code from reading C++ file 'echoclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../EchoServerGUI/echoclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'echoclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EchoClient_t {
    QByteArrayData data[13];
    char stringdata0[189];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EchoClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EchoClient_t qt_meta_stringdata_EchoClient = {
    {
QT_MOC_LITERAL(0, 0, 10), // "EchoClient"
QT_MOC_LITERAL(1, 11, 6), // "closed"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 14), // "newTextMessage"
QT_MOC_LITERAL(4, 34, 15), // "gotCurrentUsers"
QT_MOC_LITERAL(5, 50, 14), // "QList<QString>"
QT_MOC_LITERAL(6, 65, 10), // "gotHistory"
QT_MOC_LITERAL(7, 76, 27), // "registrationRequestAnswered"
QT_MOC_LITERAL(8, 104, 11), // "onConnected"
QT_MOC_LITERAL(9, 116, 21), // "onTextMessageReceived"
QT_MOC_LITERAL(10, 138, 7), // "message"
QT_MOC_LITERAL(11, 146, 23), // "onBinaryMessageReceived"
QT_MOC_LITERAL(12, 170, 18) // "socketDisconnected"

    },
    "EchoClient\0closed\0\0newTextMessage\0"
    "gotCurrentUsers\0QList<QString>\0"
    "gotHistory\0registrationRequestAnswered\0"
    "onConnected\0onTextMessageReceived\0"
    "message\0onBinaryMessageReceived\0"
    "socketDisconnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EchoClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    1,   60,    2, 0x06 /* Public */,
       4,    1,   63,    2, 0x06 /* Public */,
       6,    1,   66,    2, 0x06 /* Public */,
       7,    2,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   74,    2, 0x08 /* Private */,
       9,    1,   75,    2, 0x08 /* Private */,
      11,    1,   78,    2, 0x08 /* Private */,
      12,    0,   81,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QByteArray,   10,
    QMetaType::Void,

       0        // eod
};

void EchoClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EchoClient *_t = static_cast<EchoClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closed(); break;
        case 1: _t->newTextMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->gotCurrentUsers((*reinterpret_cast< QList<QString>(*)>(_a[1]))); break;
        case 3: _t->gotHistory((*reinterpret_cast< QList<QString>(*)>(_a[1]))); break;
        case 4: _t->registrationRequestAnswered((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->onConnected(); break;
        case 6: _t->onTextMessageReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->onBinaryMessageReceived((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 8: _t->socketDisconnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (EchoClient::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EchoClient::closed)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (EchoClient::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EchoClient::newTextMessage)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (EchoClient::*_t)(QList<QString> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EchoClient::gotCurrentUsers)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (EchoClient::*_t)(QList<QString> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EchoClient::gotHistory)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (EchoClient::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EchoClient::registrationRequestAnswered)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject EchoClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_EchoClient.data,
      qt_meta_data_EchoClient,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *EchoClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EchoClient::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_EchoClient.stringdata0))
        return static_cast<void*>(const_cast< EchoClient*>(this));
    return QObject::qt_metacast(_clname);
}

int EchoClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void EchoClient::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void EchoClient::newTextMessage(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void EchoClient::gotCurrentUsers(QList<QString> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void EchoClient::gotHistory(QList<QString> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void EchoClient::registrationRequestAnswered(QString _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
