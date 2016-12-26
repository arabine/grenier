/****************************************************************************
** Interface meta object code from reading C++ file 'Interface.h'
**
** Created: Mon Aug 4 21:25:37 2003
**      by: The Qt MOC ($Id: moc_Interface.cpp,v 1.1 2003/12/03 14:10:35 belegar Exp $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#define Q_MOC_Interface
#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 8
#elif Q_MOC_OUTPUT_REVISION != 8
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "Interface.h"
#include <qmetaobject.h>
#include <qapplication.h>

#if defined(Q_SPARCWORKS_FUNCP_BUG)
#define Q_AMPERSAND
#else
#define Q_AMPERSAND &
#endif


const char *Interface::className() const
{
    return "Interface";
}

QMetaObject *Interface::metaObj = 0;

void Interface::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QMainWindow::className(), "QMainWindow") != 0 )
	badSuperclassWarning("Interface","QMainWindow");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString Interface::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("Interface",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* Interface::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QMainWindow::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef int(Interface::*m1_t0)(int,int);
    typedef void(Interface::*m1_t1)();
    typedef void(Interface::*m1_t2)(Joueur*);
    typedef void(Interface::*m1_t3)();
    typedef void(Interface::*m1_t4)();
    typedef void(Interface::*m1_t5)(int);
    typedef void(Interface::*m1_t6)();
    typedef void(Interface::*m1_t7)();
    typedef void(Interface::*m1_t8)(int);
    typedef void(Interface::*m1_t9)(QString);
    typedef void(Interface::*m1_t10)(QString);
    typedef void(Interface::*m1_t11)(int,int,int);
    m1_t0 v1_0 = Q_AMPERSAND Interface::groundClicked;
    m1_t1 v1_1 = Q_AMPERSAND Interface::effaceJoueur;
    m1_t2 v1_2 = Q_AMPERSAND Interface::afficheJoueur;
    m1_t3 v1_3 = Q_AMPERSAND Interface::newGame;
    m1_t4 v1_4 = Q_AMPERSAND Interface::manageTeams;
    m1_t5 v1_5 = Q_AMPERSAND Interface::showDugout;
    m1_t6 v1_6 = Q_AMPERSAND Interface::showDug;
    m1_t7 v1_7 = Q_AMPERSAND Interface::showDug2;
    m1_t8 v1_8 = Q_AMPERSAND Interface::closeDug;
    m1_t9 v1_9 = Q_AMPERSAND Interface::showErrorMsg;
    m1_t10 v1_10 = Q_AMPERSAND Interface::showLogMsg;
    m1_t11 v1_11 = Q_AMPERSAND Interface::dugClicked;
    QMetaData *slot_tbl = QMetaObject::new_metadata(12);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(12);
    slot_tbl[0].name = "groundClicked(int,int)";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    slot_tbl_access[0] = QMetaData::Public;
    slot_tbl[1].name = "effaceJoueur()";
    slot_tbl[1].ptr = *((QMember*)&v1_1);
    slot_tbl_access[1] = QMetaData::Public;
    slot_tbl[2].name = "afficheJoueur(Joueur*)";
    slot_tbl[2].ptr = *((QMember*)&v1_2);
    slot_tbl_access[2] = QMetaData::Public;
    slot_tbl[3].name = "newGame()";
    slot_tbl[3].ptr = *((QMember*)&v1_3);
    slot_tbl_access[3] = QMetaData::Public;
    slot_tbl[4].name = "manageTeams()";
    slot_tbl[4].ptr = *((QMember*)&v1_4);
    slot_tbl_access[4] = QMetaData::Public;
    slot_tbl[5].name = "showDugout(int)";
    slot_tbl[5].ptr = *((QMember*)&v1_5);
    slot_tbl_access[5] = QMetaData::Public;
    slot_tbl[6].name = "showDug()";
    slot_tbl[6].ptr = *((QMember*)&v1_6);
    slot_tbl_access[6] = QMetaData::Public;
    slot_tbl[7].name = "showDug2()";
    slot_tbl[7].ptr = *((QMember*)&v1_7);
    slot_tbl_access[7] = QMetaData::Public;
    slot_tbl[8].name = "closeDug(int)";
    slot_tbl[8].ptr = *((QMember*)&v1_8);
    slot_tbl_access[8] = QMetaData::Public;
    slot_tbl[9].name = "showErrorMsg(QString)";
    slot_tbl[9].ptr = *((QMember*)&v1_9);
    slot_tbl_access[9] = QMetaData::Public;
    slot_tbl[10].name = "showLogMsg(QString)";
    slot_tbl[10].ptr = *((QMember*)&v1_10);
    slot_tbl_access[10] = QMetaData::Public;
    slot_tbl[11].name = "dugClicked(int,int,int)";
    slot_tbl[11].ptr = *((QMember*)&v1_11);
    slot_tbl_access[11] = QMetaData::Public;
    typedef void(Interface::*m2_t0)(int);
    m2_t0 v2_0 = Q_AMPERSAND Interface::sgnlShowDug;
    QMetaData *signal_tbl = QMetaObject::new_metadata(1);
    signal_tbl[0].name = "sgnlShowDug(int)";
    signal_tbl[0].ptr = *((QMember*)&v2_0);
    metaObj = QMetaObject::new_metaobject(
	"Interface", "QMainWindow",
	slot_tbl, 12,
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

// SIGNAL sgnlShowDug
void Interface::sgnlShowDug( int t0 )
{
    activate_signal( "sgnlShowDug(int)", t0 );
}
