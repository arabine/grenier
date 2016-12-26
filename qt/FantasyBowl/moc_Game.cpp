/****************************************************************************
** Game meta object code from reading C++ file 'Game.h'
**
** Created: Wed Apr 16 23:20:09 2003
**      by: The Qt MOC ($Id: moc_Game.cpp,v 1.1 2003/12/03 14:10:35 belegar Exp $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#define Q_MOC_Game
#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 8
#elif Q_MOC_OUTPUT_REVISION != 8
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "Game.h"
#include <qmetaobject.h>
#include <qapplication.h>

#if defined(Q_SPARCWORKS_FUNCP_BUG)
#define Q_AMPERSAND
#else
#define Q_AMPERSAND &
#endif


const char *Game::className() const
{
    return "Game";
}

QMetaObject *Game::metaObj = 0;

void Game::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QObject::className(), "QObject") != 0 )
	badSuperclassWarning("Game","QObject");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString Game::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("Game",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* Game::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QObject::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    QMetaData::Access *slot_tbl_access = 0;
    typedef void(Game::*m2_t0)(QString);
    m2_t0 v2_0 = Q_AMPERSAND Game::sgnlSetError;
    QMetaData *signal_tbl = QMetaObject::new_metadata(1);
    signal_tbl[0].name = "sgnlSetError(QString)";
    signal_tbl[0].ptr = *((QMember*)&v2_0);
    metaObj = QMetaObject::new_metaobject(
	"Game", "QObject",
	0, 0,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    metaObj->set_slot_access( slot_tbl_access );
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    return metaObj;
}

// SIGNAL sgnlSetError
void Game::sgnlSetError( QString t0 )
{
    activate_signal_string( "sgnlSetError(QString)", t0 );
}
