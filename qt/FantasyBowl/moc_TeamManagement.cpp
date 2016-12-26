/****************************************************************************
** MyLogo meta object code from reading C++ file 'TeamManagement.h'
**
** Created: Mon Aug 4 22:05:08 2003
**      by: The Qt MOC ($Id: moc_TeamManagement.cpp,v 1.1 2003/12/03 14:10:35 belegar Exp $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#define Q_MOC_MyLogo
#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 8
#elif Q_MOC_OUTPUT_REVISION != 8
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "TeamManagement.h"
#include <qmetaobject.h>
#include <qapplication.h>

#if defined(Q_SPARCWORKS_FUNCP_BUG)
#define Q_AMPERSAND
#else
#define Q_AMPERSAND &
#endif


const char *MyLogo::className() const
{
    return "MyLogo";
}

QMetaObject *MyLogo::metaObj = 0;

void MyLogo::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QFrame::className(), "QFrame") != 0 )
	badSuperclassWarning("MyLogo","QFrame");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString MyLogo::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("MyLogo",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* MyLogo::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QFrame::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    QMetaData::Access *slot_tbl_access = 0;
    typedef void(MyLogo::*m2_t0)();
    m2_t0 v2_0 = Q_AMPERSAND MyLogo::sigDblClick;
    QMetaData *signal_tbl = QMetaObject::new_metadata(1);
    signal_tbl[0].name = "sigDblClick()";
    signal_tbl[0].ptr = *((QMember*)&v2_0);
    metaObj = QMetaObject::new_metaobject(
	"MyLogo", "QFrame",
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

// SIGNAL sigDblClick
void MyLogo::sigDblClick()
{
    activate_signal( "sigDblClick()" );
}


const char *TeamManagement::className() const
{
    return "TeamManagement";
}

QMetaObject *TeamManagement::metaObj = 0;

void TeamManagement::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QMainWindow::className(), "QMainWindow") != 0 )
	badSuperclassWarning("TeamManagement","QMainWindow");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString TeamManagement::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("TeamManagement",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* TeamManagement::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QMainWindow::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void(TeamManagement::*m1_t0)();
    typedef void(TeamManagement::*m1_t1)();
    typedef void(TeamManagement::*m1_t2)();
    typedef void(TeamManagement::*m1_t3)();
    typedef int(TeamManagement::*m1_t4)();
    typedef void(TeamManagement::*m1_t5)();
    typedef void(TeamManagement::*m1_t6)(int,int);
    typedef void(TeamManagement::*m1_t7)();
    m1_t0 v1_0 = Q_AMPERSAND TeamManagement::newRoster;
    m1_t1 v1_1 = Q_AMPERSAND TeamManagement::openRoster;
    m1_t2 v1_2 = Q_AMPERSAND TeamManagement::saveRoster;
    m1_t3 v1_3 = Q_AMPERSAND TeamManagement::saveRosterAs;
    m1_t4 v1_4 = Q_AMPERSAND TeamManagement::closeRoster;
    m1_t5 v1_5 = Q_AMPERSAND TeamManagement::calculTotal;
    m1_t6 v1_6 = Q_AMPERSAND TeamManagement::showPlayerSkills;
    m1_t7 v1_7 = Q_AMPERSAND TeamManagement::loadLogo;
    QMetaData *slot_tbl = QMetaObject::new_metadata(8);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(8);
    slot_tbl[0].name = "newRoster()";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    slot_tbl_access[0] = QMetaData::Public;
    slot_tbl[1].name = "openRoster()";
    slot_tbl[1].ptr = *((QMember*)&v1_1);
    slot_tbl_access[1] = QMetaData::Public;
    slot_tbl[2].name = "saveRoster()";
    slot_tbl[2].ptr = *((QMember*)&v1_2);
    slot_tbl_access[2] = QMetaData::Public;
    slot_tbl[3].name = "saveRosterAs()";
    slot_tbl[3].ptr = *((QMember*)&v1_3);
    slot_tbl_access[3] = QMetaData::Public;
    slot_tbl[4].name = "closeRoster()";
    slot_tbl[4].ptr = *((QMember*)&v1_4);
    slot_tbl_access[4] = QMetaData::Public;
    slot_tbl[5].name = "calculTotal()";
    slot_tbl[5].ptr = *((QMember*)&v1_5);
    slot_tbl_access[5] = QMetaData::Public;
    slot_tbl[6].name = "showPlayerSkills(int,int)";
    slot_tbl[6].ptr = *((QMember*)&v1_6);
    slot_tbl_access[6] = QMetaData::Public;
    slot_tbl[7].name = "loadLogo()";
    slot_tbl[7].ptr = *((QMember*)&v1_7);
    slot_tbl_access[7] = QMetaData::Public;
    metaObj = QMetaObject::new_metaobject(
	"TeamManagement", "QMainWindow",
	slot_tbl, 8,
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
