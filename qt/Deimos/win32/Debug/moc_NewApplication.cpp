/****************************************************************************
** Meta object code from reading C++ file 'NewApplication.h'
**
** Created: sam. 27. mai 13:49:55 2006
**      by: The Qt Meta Object Compiler version 59 (Qt 4.1.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/NewApplication.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NewApplication.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.1.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_NewApplication[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_NewApplication[] = {
    "NewApplication\0\0languageChange()\0"
};

const QMetaObject NewApplication::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_NewApplication,
      qt_meta_data_NewApplication, 0 }
};

const QMetaObject *NewApplication::metaObject() const
{
    return &staticMetaObject;
}

void *NewApplication::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NewApplication))
	return static_cast<void*>(const_cast<NewApplication*>(this));
    return QDialog::qt_metacast(_clname);
}

int NewApplication::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
