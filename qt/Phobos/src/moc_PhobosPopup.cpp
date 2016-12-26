/****************************************************************************
** PhobosPopup meta object code from reading C++ file 'PhobosPopup.h'
**
** Created: sam. 14. août 13:28:08 2004
**      by: The Qt MOC ($Id: $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "PhobosPopup.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *PhobosPopup::className() const
{
    return "PhobosPopup";
}

QMetaObject *PhobosPopup::metaObj = 0;
static QMetaObjectCleanUp cleanUp_PhobosPopup( "PhobosPopup", &PhobosPopup::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString PhobosPopup::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PhobosPopup", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString PhobosPopup::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PhobosPopup", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* PhobosPopup::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QPopupMenu::staticMetaObject();
    static const QUMethod slot_0 = {"ajouteNote", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ "id", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"sauverNote", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "itemId", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"menuClicked", 1, param_slot_2 };
    static const QUMethod slot_3 = {"quitter", 0, 0 };
    static const QUParameter param_slot_4[] = {
	{ "id", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"detruireNote", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ "id", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"renommerNote", 1, param_slot_5 };
    static const QUMethod slot_6 = {"saveParams", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "ajouteNote()", &slot_0, QMetaData::Public },
	{ "sauverNote(int)", &slot_1, QMetaData::Public },
	{ "menuClicked(int)", &slot_2, QMetaData::Public },
	{ "quitter()", &slot_3, QMetaData::Public },
	{ "detruireNote(int)", &slot_4, QMetaData::Public },
	{ "renommerNote(int)", &slot_5, QMetaData::Public },
	{ "saveParams()", &slot_6, QMetaData::Public }
    };
    static const QUMethod signal_0 = {"signalQuitter", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "signalQuitter()", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"PhobosPopup", parentObject,
	slot_tbl, 7,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_PhobosPopup.setMetaObject( metaObj );
    return metaObj;
}

void* PhobosPopup::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "PhobosPopup" ) )
	return this;
    return QPopupMenu::qt_cast( clname );
}

// SIGNAL signalQuitter
void PhobosPopup::signalQuitter()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

bool PhobosPopup::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: ajouteNote(); break;
    case 1: sauverNote((int)static_QUType_int.get(_o+1)); break;
    case 2: menuClicked((int)static_QUType_int.get(_o+1)); break;
    case 3: quitter(); break;
    case 4: detruireNote((int)static_QUType_int.get(_o+1)); break;
    case 5: renommerNote((int)static_QUType_int.get(_o+1)); break;
    case 6: saveParams(); break;
    default:
	return QPopupMenu::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool PhobosPopup::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: signalQuitter(); break;
    default:
	return QPopupMenu::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool PhobosPopup::qt_property( int id, int f, QVariant* v)
{
    return QPopupMenu::qt_property( id, f, v);
}

bool PhobosPopup::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
