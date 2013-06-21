/****************************************************************************
** Meta object code from reading C++ file 'qt_camera.h'
**
** Created: Fri Jun 21 23:39:00 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qt_camera/qt_camera.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qt_camera.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_qt_camera[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   11,   10,   10, 0x05,
      45,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      61,   10,   10,   10, 0x0a,
      81,   10,   10,   10, 0x0a,
     100,   10,   10,   10, 0x0a,
     117,   10,   10,   10, 0x0a,
     124,   10,   10,   10, 0x0a,
     160,   10,   10,   10, 0x0a,
     176,   10,   10,   10, 0x0a,
     193,   10,   10,   10, 0x0a,
     208,   10,   10,   10, 0x0a,
     223,   10,   10,   10, 0x0a,
     235,   10,   10,   10, 0x0a,
     247,   10,   10,   10, 0x0a,
     260,   10,   10,   10, 0x0a,
     273,   10,   10,   10, 0x0a,
     289,   10,   10,   10, 0x0a,
     305,   10,   10,   10, 0x0a,
     322,   10,   10,   10, 0x0a,
     339,   10,   10,   10, 0x0a,
     356,   10,   10,   10, 0x0a,
     370,   10,   10,   10, 0x0a,
     384,   10,   10,   10, 0x0a,
     399,   10,   10,   10, 0x0a,
     414,   10,   10,   10, 0x0a,
     432,   10,   10,   10, 0x0a,
     450,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_qt_camera[] = {
    "qt_camera\0\0,\0gotAddress(QHostAddress*,uint*)\0"
    "recv_response()\0showImage(QPixmap*)\0"
    "connected_action()\0connect_failed()\0"
    "quit()\0error(QAbstractSocket::SocketError)\0"
    "connectToHost()\0cheek_response()\0"
    "goForwardBeg()\0goForwardEnd()\0goLeftBeg()\0"
    "goLeftEnd()\0goRightBeg()\0goRightEnd()\0"
    "goBackwardBeg()\0goBackwardEnd()\0"
    "speedChange(int)\0HoldForwardBeg()\0"
    "HoldForwardEnd()\0HoldLeftBeg()\0"
    "HoldLeftEnd()\0HoldRightBeg()\0"
    "HoldRightEnd()\0HoldBackwardBeg()\0"
    "HoldBackwardEnd()\0HoldChange(int)\0"
};

void qt_camera::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        qt_camera *_t = static_cast<qt_camera *>(_o);
        switch (_id) {
        case 0: _t->gotAddress((*reinterpret_cast< QHostAddress*(*)>(_a[1])),(*reinterpret_cast< uint*(*)>(_a[2]))); break;
        case 1: _t->recv_response(); break;
        case 2: _t->showImage((*reinterpret_cast< QPixmap*(*)>(_a[1]))); break;
        case 3: _t->connected_action(); break;
        case 4: _t->connect_failed(); break;
        case 5: _t->quit(); break;
        case 6: _t->error((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 7: _t->connectToHost(); break;
        case 8: _t->cheek_response(); break;
        case 9: _t->goForwardBeg(); break;
        case 10: _t->goForwardEnd(); break;
        case 11: _t->goLeftBeg(); break;
        case 12: _t->goLeftEnd(); break;
        case 13: _t->goRightBeg(); break;
        case 14: _t->goRightEnd(); break;
        case 15: _t->goBackwardBeg(); break;
        case 16: _t->goBackwardEnd(); break;
        case 17: _t->speedChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->HoldForwardBeg(); break;
        case 19: _t->HoldForwardEnd(); break;
        case 20: _t->HoldLeftBeg(); break;
        case 21: _t->HoldLeftEnd(); break;
        case 22: _t->HoldRightBeg(); break;
        case 23: _t->HoldRightEnd(); break;
        case 24: _t->HoldBackwardBeg(); break;
        case 25: _t->HoldBackwardEnd(); break;
        case 26: _t->HoldChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData qt_camera::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject qt_camera::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_qt_camera,
      qt_meta_data_qt_camera, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &qt_camera::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *qt_camera::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *qt_camera::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_qt_camera))
        return static_cast<void*>(const_cast< qt_camera*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int qt_camera::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    }
    return _id;
}

// SIGNAL 0
void qt_camera::gotAddress(QHostAddress * _t1, uint * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void qt_camera::recv_response()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
