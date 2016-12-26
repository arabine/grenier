/****************************************************************************
** NewAuthorFrame meta object code from reading C++ file 'NewAuthorFrame.h'
**
** Created: Fri Dec 6 00:23:13 2002
**      by: The Qt MOC ($Id: //depot/qt/main/src/moc/moc.y#178 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#define Q_MOC_NewAuthorFrame
#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 8
#elif Q_MOC_OUTPUT_REVISION != 8
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "NewAuthorFrame.h"
#include <qmetaobject.h>
#include <qapplication.h>

#if defined(Q_SPARCWORKS_FUNCP_BUG)
#define Q_AMPERSAND
#else
#define Q_AMPERSAND &
#endif


const char *NewAuthorFrame::className() const
{
    return "NewAuthorFrame";
}

QMetaObject *NewAuthorFrame::metaObj = 0;

void NewAuthorFrame::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QDialog::className(), "QDialog") != 0 )
	badSuperclassWarning("NewAuthorFrame","QDialog");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString NewAuthorFrame::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("NewAuthorFrame",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* NewAuthorFrame::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QDialog::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void(NewAuthorFrame::*m1_t0)();
    typedef void(NewAuthorFrame::*m1_t1)(QShowEvent*);
    m1_t0 v1_0 = Q_AMPERSAND NewAuthorFrame::save_entry;
    m1_t1 v1_1 = Q_AMPERSAND NewAuthorFrame::showEvent;
    QMetaData *slot_tbl = QMetaObject::new_metadata(2);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(2);
    slot_tbl[0].name = "save_entry()";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    slot_tbl_access[0] = QMetaData::Public;
    slot_tbl[1].name = "showEvent(QShowEvent*)";
    slot_tbl[1].ptr = *((QMember*)&v1_1);
    slot_tbl_access[1] = QMetaData::Public;
    metaObj = QMetaObject::new_metaobject(
	"NewAuthorFrame", "QDialog",
	slot_tbl, 2,
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
