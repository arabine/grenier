/****************************************************************************
** BaseList meta object code from reading C++ file 'BaseList.h'
**
** Created: Fri Dec 6 23:48:58 2002
**      by: The Qt MOC ($Id: //depot/qt/main/src/moc/moc.y#178 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#define Q_MOC_BaseList
#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 8
#elif Q_MOC_OUTPUT_REVISION != 8
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "BaseList.h"
#include <qmetaobject.h>
#include <qapplication.h>

#if defined(Q_SPARCWORKS_FUNCP_BUG)
#define Q_AMPERSAND
#else
#define Q_AMPERSAND &
#endif


const char *BaseList::className() const
{
    return "BaseList";
}

QMetaObject *BaseList::metaObj = 0;

void BaseList::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QDialog::className(), "QDialog") != 0 )
	badSuperclassWarning("BaseList","QDialog");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString BaseList::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("BaseList",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* BaseList::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QDialog::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void(BaseList::*m1_t0)();
    typedef void(BaseList::*m1_t1)();
    m1_t0 v1_0 = Q_AMPERSAND BaseList::deleteSelectedAuthor;
    m1_t1 v1_1 = Q_AMPERSAND BaseList::openSelectedAuthor;
    QMetaData *slot_tbl = QMetaObject::new_metadata(2);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(2);
    slot_tbl[0].name = "deleteSelectedAuthor()";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    slot_tbl_access[0] = QMetaData::Public;
    slot_tbl[1].name = "openSelectedAuthor()";
    slot_tbl[1].ptr = *((QMember*)&v1_1);
    slot_tbl_access[1] = QMetaData::Public;
    typedef void(BaseList::*m2_t0)(const char*);
    typedef void(BaseList::*m2_t1)(const char*);
    m2_t0 v2_0 = Q_AMPERSAND BaseList::signalDeleteAuthor;
    m2_t1 v2_1 = Q_AMPERSAND BaseList::signalOpenAuthor;
    QMetaData *signal_tbl = QMetaObject::new_metadata(2);
    signal_tbl[0].name = "signalDeleteAuthor(const char*)";
    signal_tbl[0].ptr = *((QMember*)&v2_0);
    signal_tbl[1].name = "signalOpenAuthor(const char*)";
    signal_tbl[1].ptr = *((QMember*)&v2_1);
    metaObj = QMetaObject::new_metaobject(
	"BaseList", "QDialog",
	slot_tbl, 2,
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

// SIGNAL signalDeleteAuthor
void BaseList::signalDeleteAuthor( const char* t0 )
{
    activate_signal( "signalDeleteAuthor(const char*)", t0 );
}

// SIGNAL signalOpenAuthor
void BaseList::signalOpenAuthor( const char* t0 )
{
    activate_signal( "signalOpenAuthor(const char*)", t0 );
}
