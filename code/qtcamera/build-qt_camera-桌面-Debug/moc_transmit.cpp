/****************************************************************************
** Meta object code from reading C++ file 'transmit.h'
**
** Created: Fri Jun 21 23:38:55 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qt_camera/transmit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'transmit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_transmit[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      28,    9,    9,    9, 0x05,
      41,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      62,   60,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_transmit[] = {
    "transmit\0\0recived(QPixmap*)\0tcpConnect()\0"
    "tcpConnectFailed()\0,\0"
    "setAddress(QHostAddress*,uint*)\0"
};

void transmit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        transmit *_t = static_cast<transmit *>(_o);
        switch (_id) {
        case 0: _t->recived((*reinterpret_cast< QPixmap*(*)>(_a[1]))); break;
        case 1: _t->tcpConnect(); break;
        case 2: _t->tcpConnectFailed(); break;
        case 3: _t->setAddress((*reinterpret_cast< QHostAddress*(*)>(_a[1])),(*reinterpret_cast< uint*(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData transmit::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject transmit::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_transmit,
      qt_meta_data_transmit, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &transmit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *transmit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *transmit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_transmit))
        return static_cast<void*>(const_cast< transmit*>(this));
    return QThread::qt_metacast(_clname);
}

int transmit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void transmit::recived(QPixmap * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void transmit::tcpConnect()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void transmit::tcpConnectFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
