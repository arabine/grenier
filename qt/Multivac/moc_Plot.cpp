/****************************************************************************
** Plot meta object code from reading C++ file 'Plot.h'
**
** Created: Sun Feb 23 20:37:38 2003
**      by: The Qt MOC ($Id: //depot/qt/main/src/moc/moc.y#178 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#define Q_MOC_Plot
#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 8
#elif Q_MOC_OUTPUT_REVISION != 8
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "Plot.h"
#include <qmetaobject.h>
#include <qapplication.h>

#if defined(Q_SPARCWORKS_FUNCP_BUG)
#define Q_AMPERSAND
#else
#define Q_AMPERSAND &
#endif


const char *Plot::className() const
{
    return "Plot";
}

QMetaObject *Plot::metaObj = 0;

void Plot::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QWidget::className(), "QWidget") != 0 )
	badSuperclassWarning("Plot","QWidget");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString Plot::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("Plot",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* Plot::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    QMetaData::Access *slot_tbl_access = 0;
    typedef void(Plot::*m2_t0)();
    typedef void(Plot::*m2_t1)(QString);
    m2_t0 v2_0 = Q_AMPERSAND Plot::signalOpenNewWave;
    m2_t1 v2_1 = Q_AMPERSAND Plot::signalStatusMessage;
    QMetaData *signal_tbl = QMetaObject::new_metadata(2);
    signal_tbl[0].name = "signalOpenNewWave()";
    signal_tbl[0].ptr = *((QMember*)&v2_0);
    signal_tbl[1].name = "signalStatusMessage(QString)";
    signal_tbl[1].ptr = *((QMember*)&v2_1);
    metaObj = QMetaObject::new_metaobject(
	"Plot", "QWidget",
	0, 0,
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

// SIGNAL signalOpenNewWave
void Plot::signalOpenNewWave()
{
    activate_signal( "signalOpenNewWave()" );
}

// SIGNAL signalStatusMessage
void Plot::signalStatusMessage( QString t0 )
{
    activate_signal_string( "signalStatusMessage(QString)", t0 );
}
