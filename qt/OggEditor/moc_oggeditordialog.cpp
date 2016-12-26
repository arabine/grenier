/****************************************************************************
** OggEditorDialog meta object code from reading C++ file 'oggeditordialog.h'
**
** Created: Thu Nov 13 12:00:35 2003
**      by: The Qt MOC ($Id: //depot/qt/main/src/moc/moc.y#178 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#define Q_MOC_OggEditorDialog
#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 8
#elif Q_MOC_OUTPUT_REVISION != 8
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "oggeditordialog.h"
#include <qmetaobject.h>
#include <qapplication.h>

#if defined(Q_SPARCWORKS_FUNCP_BUG)
#define Q_AMPERSAND
#else
#define Q_AMPERSAND &
#endif


const char *OggEditorDialog::className() const
{
    return "OggEditorDialog";
}

QMetaObject *OggEditorDialog::metaObj = 0;

void OggEditorDialog::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(MainForm::className(), "MainForm") != 0 )
	badSuperclassWarning("OggEditorDialog","MainForm");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION
QString OggEditorDialog::tr(const char* s)
{
    return ((QNonBaseApplication*)qApp)->translate("OggEditorDialog",s);
}

#endif // QT_NO_TRANSLATION
QMetaObject* OggEditorDialog::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) MainForm::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void(OggEditorDialog::*m1_t0)();
    typedef void(OggEditorDialog::*m1_t1)();
    m1_t0 v1_0 = Q_AMPERSAND OggEditorDialog::openOggFile;
    m1_t1 v1_1 = Q_AMPERSAND OggEditorDialog::saveOggFile;
    QMetaData *slot_tbl = QMetaObject::new_metadata(2);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(2);
    slot_tbl[0].name = "openOggFile()";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    slot_tbl_access[0] = QMetaData::Public;
    slot_tbl[1].name = "saveOggFile()";
    slot_tbl[1].ptr = *((QMember*)&v1_1);
    slot_tbl_access[1] = QMetaData::Public;
    metaObj = QMetaObject::new_metaobject(
	"OggEditorDialog", "MainForm",
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
