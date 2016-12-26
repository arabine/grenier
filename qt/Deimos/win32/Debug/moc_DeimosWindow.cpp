/****************************************************************************
** Meta object code from reading C++ file 'DeimosWindow.h'
**
** Created: dim. 28. mai 16:23:19 2006
**      by: The Qt Meta Object Compiler version 59 (Qt 4.1.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/DeimosWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DeimosWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.1.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_DeimosWindow[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      34,   13,   13,   13, 0x0a,
      51,   13,   13,   13, 0x0a,
      69,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_DeimosWindow[] = {
    "DeimosWindow\0\0slotMenuNewConfig()\0slotExitDeimos()\0"
    "slotAboutDeimos()\0slotTestDeimos()\0"
};

const QMetaObject DeimosWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_DeimosWindow,
      qt_meta_data_DeimosWindow, 0 }
};

const QMetaObject *DeimosWindow::metaObject() const
{
    return &staticMetaObject;
}

void *DeimosWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DeimosWindow))
	return static_cast<void*>(const_cast<DeimosWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int DeimosWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: slotMenuNewConfig(); break;
        case 1: slotExitDeimos(); break;
        case 2: slotAboutDeimos(); break;
        case 3: slotTestDeimos(); break;
        }
        _id -= 4;
    }
    return _id;
}
