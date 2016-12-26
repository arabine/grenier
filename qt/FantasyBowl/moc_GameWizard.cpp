/****************************************************************************
** GameWizard meta object code from reading C++ file 'GameWizard.h'
**
** Created: Thu Jul 24 22:18:47 2003
**      by: The Qt MOC ($Id: moc_GameWizard.cpp,v 1.1 2003/12/03 14:10:35 belegar Exp $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#define Q_MOC_GameWizard
#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 8
#elif Q_MOC_OUTPUT_REVISION != 8
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "GameWizard.h"
#include <qmetaobject.h>
#include <qapplication.h>

#if defined(Q_SPARCWORKS_FUNCP_BUG)
#define Q_AMPERSAND
#else
#define Q_AMPERSAND &
#endif


const char *GameWizard::className() const
{
    return "GameWizard";
}

QMetaObject *GameWizard::metaObj = 0;

void GameWizard::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QWizard::className(), "QWizard") != 0 )
	badSuperclassWarning("GameWizard","QWizard");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString GameWizard::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("GameWizard",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* GameWizard::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QWizard::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void(GameWizard::*m1_t0)();
    typedef void(GameWizard::*m1_t1)();
    typedef QString(GameWizard::*m1_t2)();
    typedef QString(GameWizard::*m1_t3)();
    m1_t0 v1_0 = Q_AMPERSAND GameWizard::clickTeam1;
    m1_t1 v1_1 = Q_AMPERSAND GameWizard::clickTeam2;
    m1_t2 v1_2 = Q_AMPERSAND GameWizard::getTeam1;
    m1_t3 v1_3 = Q_AMPERSAND GameWizard::getTeam2;
    QMetaData *slot_tbl = QMetaObject::new_metadata(4);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(4);
    slot_tbl[0].name = "clickTeam1()";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    slot_tbl_access[0] = QMetaData::Public;
    slot_tbl[1].name = "clickTeam2()";
    slot_tbl[1].ptr = *((QMember*)&v1_1);
    slot_tbl_access[1] = QMetaData::Public;
    slot_tbl[2].name = "getTeam1()";
    slot_tbl[2].ptr = *((QMember*)&v1_2);
    slot_tbl_access[2] = QMetaData::Public;
    slot_tbl[3].name = "getTeam2()";
    slot_tbl[3].ptr = *((QMember*)&v1_3);
    slot_tbl_access[3] = QMetaData::Public;
    metaObj = QMetaObject::new_metaobject(
	"GameWizard", "QWizard",
	slot_tbl, 4,
	0, 0,
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
