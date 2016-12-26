/****************************************************************************
** FrmMain meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sun Sep 15 21:31:20 2002
**      by: The Qt MOC ($Id: //depot/qt/main/src/moc/moc.y#178 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#define Q_MOC_FrmMain
#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 8
#elif Q_MOC_OUTPUT_REVISION != 8
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "mainwindow.h"
#include <qmetaobject.h>
#include <qapplication.h>

#if defined(Q_SPARCWORKS_FUNCP_BUG)
#define Q_AMPERSAND
#else
#define Q_AMPERSAND &
#endif


const char *FrmMain::className() const
{
    return "FrmMain";
}

QMetaObject *FrmMain::metaObj = 0;

void FrmMain::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QWidget::className(), "QWidget") != 0 )
	badSuperclassWarning("FrmMain","QWidget");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString FrmMain::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("FrmMain",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* FrmMain::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void(FrmMain::*m1_t0)();
    typedef void(FrmMain::*m1_t1)();
    typedef void(FrmMain::*m1_t2)();
    m1_t0 v1_0 = Q_AMPERSAND FrmMain::aboutBox;
    m1_t1 v1_1 = Q_AMPERSAND FrmMain::genBruit;
    m1_t2 v1_2 = Q_AMPERSAND FrmMain::afficheBruit;
    QMetaData *slot_tbl = QMetaObject::new_metadata(3);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(3);
    slot_tbl[0].name = "aboutBox()";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    slot_tbl_access[0] = QMetaData::Public;
    slot_tbl[1].name = "genBruit()";
    slot_tbl[1].ptr = *((QMember*)&v1_1);
    slot_tbl_access[1] = QMetaData::Public;
    slot_tbl[2].name = "afficheBruit()";
    slot_tbl[2].ptr = *((QMember*)&v1_2);
    slot_tbl_access[2] = QMetaData::Public;
    metaObj = QMetaObject::new_metaobject(
	"FrmMain", "QWidget",
	slot_tbl, 3,
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
