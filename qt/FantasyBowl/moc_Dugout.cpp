/****************************************************************************
** Dugout meta object code from reading C++ file 'Dugout.h'
**
** Created: Wed Apr 23 23:16:46 2003
**      by: The Qt MOC ($Id: moc_Dugout.cpp,v 1.1 2003/12/03 14:10:35 belegar Exp $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#define Q_MOC_Dugout
#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 8
#elif Q_MOC_OUTPUT_REVISION != 8
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "Dugout.h"
#include <qmetaobject.h>
#include <qapplication.h>

#if defined(Q_SPARCWORKS_FUNCP_BUG)
#define Q_AMPERSAND
#else
#define Q_AMPERSAND &
#endif


const char *Dugout::className() const
{
    return "Dugout";
}

QMetaObject *Dugout::metaObj = 0;

void Dugout::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QDialog::className(), "QDialog") != 0 )
	badSuperclassWarning("Dugout","QDialog");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString Dugout::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("Dugout",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* Dugout::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QDialog::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void(Dugout::*m1_t0)(int,int);
    m1_t0 v1_0 = Q_AMPERSAND Dugout::groundClicked;
    QMetaData *slot_tbl = QMetaObject::new_metadata(1);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(1);
    slot_tbl[0].name = "groundClicked(int,int)";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    slot_tbl_access[0] = QMetaData::Public;
    typedef void(Dugout::*m2_t0)(int);
    typedef void(Dugout::*m2_t1)(int,int,int);
    m2_t0 v2_0 = Q_AMPERSAND Dugout::sgnlCloseDug;
    m2_t1 v2_1 = Q_AMPERSAND Dugout::sgnlDugClicked;
    QMetaData *signal_tbl = QMetaObject::new_metadata(2);
    signal_tbl[0].name = "sgnlCloseDug(int)";
    signal_tbl[0].ptr = *((QMember*)&v2_0);
    signal_tbl[1].name = "sgnlDugClicked(int,int,int)";
    signal_tbl[1].ptr = *((QMember*)&v2_1);
    metaObj = QMetaObject::new_metaobject(
	"Dugout", "QDialog",
	slot_tbl, 1,
	signal_tbl, 2,
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

// SIGNAL sgnlCloseDug
void Dugout::sgnlCloseDug( int t0 )
{
    activate_signal( "sgnlCloseDug(int)", t0 );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL sgnlDugClicked
void Dugout::sgnlDugClicked( int t0, int t1, int t2 )
{
    // No builtin function for signal parameter type int,int,int
    QConnectionList *clist = receivers("sgnlDugClicked(int,int,int)");
    if ( !clist || signalsBlocked() )
	return;
    typedef void (QObject::*RT0)();
    typedef RT0 *PRT0;
    typedef void (QObject::*RT1)(int);
    typedef RT1 *PRT1;
    typedef void (QObject::*RT2)(int,int);
    typedef RT2 *PRT2;
    typedef void (QObject::*RT3)(int,int,int);
    typedef RT3 *PRT3;
    RT0 r0;
    RT1 r1;
    RT2 r2;
    RT3 r3;
    QConnectionListIt it(*clist);
    QConnection   *c;
    QSenderObject *object;
    while ( (c=it.current()) ) {
	++it;
	object = (QSenderObject*)c->object();
	object->setSender( this );
	switch ( c->numArgs() ) {
	    case 0:
		r0 = *((PRT0)(c->member()));
		(object->*r0)();
		break;
	    case 1:
		r1 = *((PRT1)(c->member()));
		(object->*r1)(t0);
		break;
	    case 2:
		r2 = *((PRT2)(c->member()));
		(object->*r2)(t0, t1);
		break;
	    case 3:
		r3 = *((PRT3)(c->member()));
		(object->*r3)(t0, t1, t2);
		break;
	}
    }
}
