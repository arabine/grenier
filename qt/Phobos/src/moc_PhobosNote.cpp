/****************************************************************************
** MyQMultiLineEdit meta object code from reading C++ file 'PhobosNote.h'
**
** Created: sam. 14. août 13:28:08 2004
**      by: The Qt MOC ($Id: $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "PhobosNote.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *MyQMultiLineEdit::className() const
{
    return "MyQMultiLineEdit";
}

QMetaObject *MyQMultiLineEdit::metaObj = 0;
static QMetaObjectCleanUp cleanUp_MyQMultiLineEdit( "MyQMultiLineEdit", &MyQMultiLineEdit::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString MyQMultiLineEdit::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "MyQMultiLineEdit", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString MyQMultiLineEdit::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "MyQMultiLineEdit", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* MyQMultiLineEdit::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QMultiLineEdit::staticMetaObject();
    static const QUMethod signal_0 = {"signalShowPopup", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "signalShowPopup()", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"MyQMultiLineEdit", parentObject,
	0, 0,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_MyQMultiLineEdit.setMetaObject( metaObj );
    return metaObj;
}

void* MyQMultiLineEdit::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "MyQMultiLineEdit" ) )
	return this;
    return QMultiLineEdit::qt_cast( clname );
}

// SIGNAL signalShowPopup
void MyQMultiLineEdit::signalShowPopup()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

bool MyQMultiLineEdit::qt_invoke( int _id, QUObject* _o )
{
    return QMultiLineEdit::qt_invoke(_id,_o);
}

bool MyQMultiLineEdit::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: signalShowPopup(); break;
    default:
	return QMultiLineEdit::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool MyQMultiLineEdit::qt_property( int id, int f, QVariant* v)
{
    return QMultiLineEdit::qt_property( id, f, v);
}

bool MyQMultiLineEdit::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *PhobosNote::className() const
{
    return "PhobosNote";
}

QMetaObject *PhobosNote::metaObj = 0;
static QMetaObjectCleanUp cleanUp_PhobosNote( "PhobosNote", &PhobosNote::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString PhobosNote::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PhobosNote", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString PhobosNote::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PhobosNote", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* PhobosNote::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUMethod slot_0 = {"cacherNote", 0, 0 };
    static const QUMethod slot_1 = {"sauverNote", 0, 0 };
    static const QUMethod slot_2 = {"detruireNote", 0, 0 };
    static const QUMethod slot_3 = {"renommerNote", 0, 0 };
    static const QUMethod slot_4 = {"affichePopup", 0, 0 };
    static const QUMethod slot_5 = {"effacer", 0, 0 };
    static const QUMethod slot_6 = {"copier", 0, 0 };
    static const QUMethod slot_7 = {"couper", 0, 0 };
    static const QUMethod slot_8 = {"coller", 0, 0 };
    static const QUMethod slot_9 = {"defaire", 0, 0 };
    static const QUMethod slot_10 = {"refaire", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "cacherNote()", &slot_0, QMetaData::Public },
	{ "sauverNote()", &slot_1, QMetaData::Public },
	{ "detruireNote()", &slot_2, QMetaData::Public },
	{ "renommerNote()", &slot_3, QMetaData::Public },
	{ "affichePopup()", &slot_4, QMetaData::Public },
	{ "effacer()", &slot_5, QMetaData::Public },
	{ "copier()", &slot_6, QMetaData::Public },
	{ "couper()", &slot_7, QMetaData::Public },
	{ "coller()", &slot_8, QMetaData::Public },
	{ "defaire()", &slot_9, QMetaData::Public },
	{ "refaire()", &slot_10, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"signalDetruireNote", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"signalSauverNote", 1, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_2 = {"signalRenommerNote", 1, param_signal_2 };
    static const QMetaData signal_tbl[] = {
	{ "signalDetruireNote(int)", &signal_0, QMetaData::Public },
	{ "signalSauverNote(int)", &signal_1, QMetaData::Public },
	{ "signalRenommerNote(int)", &signal_2, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"PhobosNote", parentObject,
	slot_tbl, 11,
	signal_tbl, 3,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_PhobosNote.setMetaObject( metaObj );
    return metaObj;
}

void* PhobosNote::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "PhobosNote" ) )
	return this;
    return QDialog::qt_cast( clname );
}

// SIGNAL signalDetruireNote
void PhobosNote::signalDetruireNote( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

// SIGNAL signalSauverNote
void PhobosNote::signalSauverNote( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 1, t0 );
}

// SIGNAL signalRenommerNote
void PhobosNote::signalRenommerNote( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 2, t0 );
}

bool PhobosNote::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: cacherNote(); break;
    case 1: sauverNote(); break;
    case 2: detruireNote(); break;
    case 3: renommerNote(); break;
    case 4: affichePopup(); break;
    case 5: effacer(); break;
    case 6: copier(); break;
    case 7: couper(); break;
    case 8: coller(); break;
    case 9: defaire(); break;
    case 10: refaire(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool PhobosNote::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: signalDetruireNote((int)static_QUType_int.get(_o+1)); break;
    case 1: signalSauverNote((int)static_QUType_int.get(_o+1)); break;
    case 2: signalRenommerNote((int)static_QUType_int.get(_o+1)); break;
    default:
	return QDialog::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool PhobosNote::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool PhobosNote::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
