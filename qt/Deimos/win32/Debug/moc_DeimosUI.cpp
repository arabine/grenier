/****************************************************************************
** Meta object code from reading C++ file 'DeimosUI.h'
**
** Created: sam. 27. mai 13:49:54 2006
**      by: The Qt Meta Object Compiler version 59 (Qt 4.1.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/DeimosUI.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DeimosUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.1.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_DeimosUI[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_DeimosUI[] = {
    "DeimosUI\0\0languageChange()\0"
};

const QMetaObject DeimosUI::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_DeimosUI,
      qt_meta_data_DeimosUI, 0 }
};

const QMetaObject *DeimosUI::metaObject() const
{
    return &staticMetaObject;
}

void *DeimosUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DeimosUI))
	return static_cast<void*>(const_cast<DeimosUI*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int DeimosUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: languageChange(); break;
        }
        _id -= 1;
    }
    return _id;
}
