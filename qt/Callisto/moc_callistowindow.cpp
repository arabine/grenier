/****************************************************************************
** CallistoWindow meta object code from reading C++ file 'callistowindow.h'
**
** Created: Fri Dec 6 23:59:37 2002
**      by: The Qt MOC ($Id: //depot/qt/main/src/moc/moc.y#178 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#define Q_MOC_CallistoWindow
#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 8
#elif Q_MOC_OUTPUT_REVISION != 8
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "callistowindow.h"
#include <qmetaobject.h>
#include <qapplication.h>

#if defined(Q_SPARCWORKS_FUNCP_BUG)
#define Q_AMPERSAND
#else
#define Q_AMPERSAND &
#endif


const char *CallistoWindow::className() const
{
    return "CallistoWindow";
}

QMetaObject *CallistoWindow::metaObj = 0;

void CallistoWindow::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QMainWindow::className(), "QMainWindow") != 0 )
	badSuperclassWarning("CallistoWindow","QMainWindow");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString CallistoWindow::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("CallistoWindow",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* CallistoWindow::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QMainWindow::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void(CallistoWindow::*m1_t0)();
    typedef void(CallistoWindow::*m1_t1)();
    typedef void(CallistoWindow::*m1_t2)();
    typedef void(CallistoWindow::*m1_t3)();
    typedef void(CallistoWindow::*m1_t4)(const char*);
    typedef void(CallistoWindow::*m1_t5)(const char*);
    m1_t0 v1_0 = Q_AMPERSAND CallistoWindow::aboutBox;
    m1_t1 v1_1 = Q_AMPERSAND CallistoWindow::newAuthor;
    m1_t2 v1_2 = Q_AMPERSAND CallistoWindow::newBook;
    m1_t3 v1_3 = Q_AMPERSAND CallistoWindow::listDataBase;
    m1_t4 v1_4 = Q_AMPERSAND CallistoWindow::openDataBase;
    m1_t5 v1_5 = Q_AMPERSAND CallistoWindow::deleteAuthor;
    QMetaData *slot_tbl = QMetaObject::new_metadata(6);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(6);
    slot_tbl[0].name = "aboutBox()";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    slot_tbl_access[0] = QMetaData::Public;
    slot_tbl[1].name = "newAuthor()";
    slot_tbl[1].ptr = *((QMember*)&v1_1);
    slot_tbl_access[1] = QMetaData::Public;
    slot_tbl[2].name = "newBook()";
    slot_tbl[2].ptr = *((QMember*)&v1_2);
    slot_tbl_access[2] = QMetaData::Public;
    slot_tbl[3].name = "listDataBase()";
    slot_tbl[3].ptr = *((QMember*)&v1_3);
    slot_tbl_access[3] = QMetaData::Public;
    slot_tbl[4].name = "openDataBase(const char*)";
    slot_tbl[4].ptr = *((QMember*)&v1_4);
    slot_tbl_access[4] = QMetaData::Public;
    slot_tbl[5].name = "deleteAuthor(const char*)";
    slot_tbl[5].ptr = *((QMember*)&v1_5);
    slot_tbl_access[5] = QMetaData::Public;
    metaObj = QMetaObject::new_metaobject(
	"CallistoWindow", "QMainWindow",
	slot_tbl, 6,
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
