/****************************************************************************
** ParamPanel meta object code from reading C++ file 'ParamPanel.h'
**
** Created: Sun Feb 23 20:37:38 2003
**      by: The Qt MOC ($Id: //depot/qt/main/src/moc/moc.y#178 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#define Q_MOC_ParamPanel
#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 8
#elif Q_MOC_OUTPUT_REVISION != 8
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "ParamPanel.h"
#include <qmetaobject.h>
#include <qapplication.h>

#if defined(Q_SPARCWORKS_FUNCP_BUG)
#define Q_AMPERSAND
#else
#define Q_AMPERSAND &
#endif


const char *ParamPanel::className() const
{
    return "ParamPanel";
}

QMetaObject *ParamPanel::metaObj = 0;

void ParamPanel::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QDialog::className(), "QDialog") != 0 )
	badSuperclassWarning("ParamPanel","QDialog");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString ParamPanel::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("ParamPanel",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* ParamPanel::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QDialog::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void(ParamPanel::*m1_t0)();
    typedef void(ParamPanel::*m1_t1)();
    typedef void(ParamPanel::*m1_t2)();
    typedef void(ParamPanel::*m1_t3)();
    m1_t0 v1_0 = Q_AMPERSAND ParamPanel::saveParam;
    m1_t1 v1_1 = Q_AMPERSAND ParamPanel::calculTaille;
    m1_t2 v1_2 = Q_AMPERSAND ParamPanel::errorOfSize;
    m1_t3 v1_3 = Q_AMPERSAND ParamPanel::errorOfBoundary;
    QMetaData *slot_tbl = QMetaObject::new_metadata(4);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(4);
    slot_tbl[0].name = "saveParam()";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    slot_tbl_access[0] = QMetaData::Public;
    slot_tbl[1].name = "calculTaille()";
    slot_tbl[1].ptr = *((QMember*)&v1_1);
    slot_tbl_access[1] = QMetaData::Public;
    slot_tbl[2].name = "errorOfSize()";
    slot_tbl[2].ptr = *((QMember*)&v1_2);
    slot_tbl_access[2] = QMetaData::Public;
    slot_tbl[3].name = "errorOfBoundary()";
    slot_tbl[3].ptr = *((QMember*)&v1_3);
    slot_tbl_access[3] = QMetaData::Public;
    typedef void(ParamPanel::*m2_t0)(unsigned long int,unsigned long);
    m2_t0 v2_0 = Q_AMPERSAND ParamPanel::signalSaveParam;
    QMetaData *signal_tbl = QMetaObject::new_metadata(1);
    signal_tbl[0].name = "signalSaveParam(unsigned long int,unsigned long)";
    signal_tbl[0].ptr = *((QMember*)&v2_0);
    metaObj = QMetaObject::new_metaobject(
	"ParamPanel", "QDialog",
	slot_tbl, 4,
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

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL signalSaveParam
void ParamPanel::signalSaveParam( unsigned long int t0, unsigned long t1 )
{
    // No builtin function for signal parameter type unsigned long int,unsigned long
    QConnectionList *clist = receivers("signalSaveParam(unsigned long int,unsigned long)");
    if ( !clist || signalsBlocked() )
	return;
    typedef void (QObject::*RT0)();
    typedef RT0 *PRT0;
    typedef void (QObject::*RT1)(unsigned long int);
    typedef RT1 *PRT1;
    typedef void (QObject::*RT2)(unsigned long int,unsigned long);
    typedef RT2 *PRT2;
    RT0 r0;
    RT1 r1;
    RT2 r2;
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
	}
    }
}
