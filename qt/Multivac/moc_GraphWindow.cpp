/****************************************************************************
** GraphWindow meta object code from reading C++ file 'GraphWindow.h'
**
** Created: Sun Feb 23 20:37:38 2003
**      by: The Qt MOC ($Id: //depot/qt/main/src/moc/moc.y#178 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#define Q_MOC_GraphWindow
#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 8
#elif Q_MOC_OUTPUT_REVISION != 8
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "GraphWindow.h"
#include <qmetaobject.h>
#include <qapplication.h>

#if defined(Q_SPARCWORKS_FUNCP_BUG)
#define Q_AMPERSAND
#else
#define Q_AMPERSAND &
#endif


const char *GraphWindow::className() const
{
    return "GraphWindow";
}

QMetaObject *GraphWindow::metaObj = 0;

void GraphWindow::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QMainWindow::className(), "QMainWindow") != 0 )
	badSuperclassWarning("GraphWindow","QMainWindow");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString GraphWindow::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("GraphWindow",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* GraphWindow::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QMainWindow::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void(GraphWindow::*m1_t0)();
    typedef void(GraphWindow::*m1_t1)();
    typedef void(GraphWindow::*m1_t2)();
    typedef void(GraphWindow::*m1_t3)();
    typedef void(GraphWindow::*m1_t4)();
    typedef void(GraphWindow::*m1_t5)(unsigned long int,unsigned long);
    typedef void(GraphWindow::*m1_t6)(QString);
    m1_t0 v1_0 = Q_AMPERSAND GraphWindow::openSoundFile;
    m1_t1 v1_1 = Q_AMPERSAND GraphWindow::aboutBox;
    m1_t2 v1_2 = Q_AMPERSAND GraphWindow::setupAnalyse;
    m1_t3 v1_3 = Q_AMPERSAND GraphWindow::startFFT;
    m1_t4 v1_4 = Q_AMPERSAND GraphWindow::testFREQ;
    m1_t5 v1_5 = Q_AMPERSAND GraphWindow::recepIntervalle;
    m1_t6 v1_6 = Q_AMPERSAND GraphWindow::setMessage;
    QMetaData *slot_tbl = QMetaObject::new_metadata(7);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(7);
    slot_tbl[0].name = "openSoundFile()";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    slot_tbl_access[0] = QMetaData::Public;
    slot_tbl[1].name = "aboutBox()";
    slot_tbl[1].ptr = *((QMember*)&v1_1);
    slot_tbl_access[1] = QMetaData::Public;
    slot_tbl[2].name = "setupAnalyse()";
    slot_tbl[2].ptr = *((QMember*)&v1_2);
    slot_tbl_access[2] = QMetaData::Public;
    slot_tbl[3].name = "startFFT()";
    slot_tbl[3].ptr = *((QMember*)&v1_3);
    slot_tbl_access[3] = QMetaData::Public;
    slot_tbl[4].name = "testFREQ()";
    slot_tbl[4].ptr = *((QMember*)&v1_4);
    slot_tbl_access[4] = QMetaData::Public;
    slot_tbl[5].name = "recepIntervalle(unsigned long int,unsigned long)";
    slot_tbl[5].ptr = *((QMember*)&v1_5);
    slot_tbl_access[5] = QMetaData::Public;
    slot_tbl[6].name = "setMessage(QString)";
    slot_tbl[6].ptr = *((QMember*)&v1_6);
    slot_tbl_access[6] = QMetaData::Public;
    metaObj = QMetaObject::new_metaobject(
	"GraphWindow", "QMainWindow",
	slot_tbl, 7,
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
