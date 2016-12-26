/****************************************************************************
** MyQTable meta object code from reading C++ file 'MyQTable.h'
**
** Created: Thu Jul 24 22:18:47 2003
**      by: The Qt MOC ($Id: moc_MyQTable.cpp,v 1.1 2003/12/03 14:10:35 belegar Exp $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#define Q_MOC_MyQTable
#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 8
#elif Q_MOC_OUTPUT_REVISION != 8
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "MyQTable.h"
#include <qmetaobject.h>
#include <qapplication.h>

#if defined(Q_SPARCWORKS_FUNCP_BUG)
#define Q_AMPERSAND
#else
#define Q_AMPERSAND &
#endif


const char *MyQTable::className() const
{
    return "MyQTable";
}

QMetaObject *MyQTable::metaObj = 0;

void MyQTable::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QTable::className(), "QTable") != 0 )
	badSuperclassWarning("MyQTable","QTable");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString MyQTable::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("MyQTable",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* MyQTable::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QTable::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void(MyQTable::*m1_t0)(int,int);
    m1_t0 v1_0 = Q_AMPERSAND MyQTable::checkValue;
    QMetaData *slot_tbl = QMetaObject::new_metadata(1);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(1);
    slot_tbl[0].name = "checkValue(int,int)";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    slot_tbl_access[0] = QMetaData::Public;
    typedef void(MyQTable::*m2_t0)();
    m2_t0 v2_0 = Q_AMPERSAND MyQTable::recalcTotal;
    QMetaData *signal_tbl = QMetaObject::new_metadata(1);
    signal_tbl[0].name = "recalcTotal()";
    signal_tbl[0].ptr = *((QMember*)&v2_0);
    metaObj = QMetaObject::new_metaobject(
	"MyQTable", "QTable",
	slot_tbl, 1,
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

// SIGNAL recalcTotal
void MyQTable::recalcTotal()
{
    activate_signal( "recalcTotal()" );
}
