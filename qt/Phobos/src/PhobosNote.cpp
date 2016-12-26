/*=============================================================================
 * Phobos 1.0 - PhobosNote.cpp
 *=============================================================================
 * Post-it (interface + popup menu)
 *=============================================================================
 * (c) Anthony RABINE - 2003
 * arabine@programmationworld.com
 * http://www.programmationworld.com
 * Environment : VC++ 6.0 - Windows seulement
 * 
 *=============================================================================
 */

#include "PhobosNote.h"

/*****************************************************************************/
MyQMultiLineEdit::MyQMultiLineEdit( QWidget * parent, const char * name)
	 : QMultiLineEdit(parent, name)
{
	connect(this, SIGNAL(signalShowPopup()), parent, SLOT(affichePopup()));
}
/*****************************************************************************/
void MyQMultiLineEdit::mousePressEvent( QMouseEvent *me )
{
	if(me->button() == RightButton)
		emit signalShowPopup();
}
/*****************************************************************************/
PhobosNote::PhobosNote( QWidget* parent,  const char* name , int id)
    : QDialog( parent, name, false, 
	WStyle_Dialog | WStyle_Customize | WStyle_NoBorderEx | WStyle_Title | WStyle_SysMenu )
{
    if ( !name )
	setName( "PhobosNote" );
    resize( 321, 221 ); 
    setMaximumSize( QSize( 321, 221 ) );
	setTitle("Note " + QString().setNum(id-99));

	noteId = id;

	popup = new QPopupMenu(this);

	popup->insertItem("Effacer", this, SLOT(effacer()));
	popup->insertItem("Copier", this, SLOT(copier()));
	popup->insertItem("Coller", this, SLOT(coller()));
	popup->insertItem("Défaire", this, SLOT(defaire()));
	popup->insertItem("Refaire", this, SLOT(refaire()));
	popup->insertSeparator();
	popup->insertItem("Cacher", this, SLOT(cacherNote()));
	popup->insertItem("Sauver", this, SLOT(sauverNote()));
	popup->insertItem("Détruire", this, SLOT(detruireNote()));
	popup->insertItem("Renommer", this, SLOT(renommerNote()));
	
    MultiLineEdit1 = new MyQMultiLineEdit( this, "MultiLineEdit1" );
    MultiLineEdit1->setGeometry( QRect( 0, 0, 320, 220 ) ); 

	// Plein de truc générés automatiquement par QtDesigner
	// tout ça pour avoir juste le fond jaune.
	// Pas grave, on touche à rien, ça marche très bien.

    QPalette pal;
    QColorGroup cg;
    cg.setColor( QColorGroup::Foreground, black );
    cg.setColor( QColorGroup::Button, QColor( 212, 208, 200) );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, QColor( 233, 231, 227) );
    cg.setColor( QColorGroup::Dark, QColor( 106, 104, 100) );
    cg.setColor( QColorGroup::Mid, QColor( 141, 138, 133) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, QColor( 255, 255, 0) );
    cg.setColor( QColorGroup::Background, QColor( 212, 208, 200) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 10, 36, 106) );
    cg.setColor( QColorGroup::HighlightedText, white );
    pal.setActive( cg );
    cg.setColor( QColorGroup::Foreground, black );
    cg.setColor( QColorGroup::Button, QColor( 212, 208, 200) );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, QColor( 243, 239, 230) );
    cg.setColor( QColorGroup::Dark, QColor( 106, 104, 100) );
    cg.setColor( QColorGroup::Mid, QColor( 141, 138, 133) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, QColor( 255, 255, 0) );
    cg.setColor( QColorGroup::Background, QColor( 212, 208, 200) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 10, 36, 106) );
    cg.setColor( QColorGroup::HighlightedText, white );
    pal.setInactive( cg );
    cg.setColor( QColorGroup::Foreground, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Button, QColor( 212, 208, 200) );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, QColor( 243, 239, 230) );
    cg.setColor( QColorGroup::Dark, QColor( 106, 104, 100) );
    cg.setColor( QColorGroup::Mid, QColor( 141, 138, 133) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Base, QColor( 255, 255, 0) );
    cg.setColor( QColorGroup::Background, QColor( 212, 208, 200) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 10, 36, 106) );
    cg.setColor( QColorGroup::HighlightedText, white );
    pal.setDisabled( cg );
    MultiLineEdit1->setPalette( pal );

    connect(this, SIGNAL(signalDetruireNote(int)), parent, SLOT(detruireNote(int)));
	connect(this, SIGNAL(signalSauverNote(int)), parent, SLOT(sauverNote(int)));
	connect(this, SIGNAL(signalRenommerNote(int)), parent, SLOT(renommerNote(int)));
}
/*****************************************************************************/
/**
 * Redéfinition du bouton fermer pour chacher sans détruire l'objet
 */
void PhobosNote::closeEvent(QCloseEvent *)
{
	this->hide();
}
/*****************************************************************************/
void PhobosNote::cacherNote()
{
	this->hide();
}
/*****************************************************************************/
void PhobosNote::renommerNote()
{
	bool ok = FALSE;
	QString text = QInputDialog::getText( tr( "Phobos" ), tr( "Nouveau nom :" ), QString::null, &ok, this );
	if ( !ok || text.isEmpty() )
      return;
	
	setCaption("Qt - " + text);
	titreNote = text;
	emit signalRenommerNote(noteId);
}
/*****************************************************************************/
void PhobosNote::sauverNote()
{
	emit signalSauverNote(noteId);
}
/*****************************************************************************/
void PhobosNote::detruireNote()
{
	this->hide();
	emit signalDetruireNote(noteId);
}
/*****************************************************************************/
void PhobosNote::affichePopup()
{
	popup->exec(QCursor::pos()); // affiche le popup sous le curseur
}
/*****************************************************************************/
void PhobosNote::effacer()
{
	MultiLineEdit1->clear();
}
/*****************************************************************************/
void PhobosNote::copier()
{
	MultiLineEdit1->copy();
}
/*****************************************************************************/
void PhobosNote::couper()
{
	MultiLineEdit1->cut();
}
/*****************************************************************************/
void PhobosNote::coller()
{
	MultiLineEdit1->paste();
}
/*****************************************************************************/
void PhobosNote::defaire()
{
	MultiLineEdit1->undo();
}
/*****************************************************************************/
void PhobosNote::refaire()
{
	MultiLineEdit1->redo();
}
/*****************************************************************************/
QString PhobosNote::getText()
{
	return MultiLineEdit1->text();
}
/*****************************************************************************/
void PhobosNote::setText(QString txt)
{
	MultiLineEdit1->setText(txt);
}
/*****************************************************************************/
QString PhobosNote::getTitle()
{
	return titreNote;
}
/*****************************************************************************/
void PhobosNote::setTitle(QString name)
{
	titreNote = name;
	setCaption( tr("Qt - " + name) );
}

//=============================================================================
// Fin du fichier PhobosNote.cpp
//=============================================================================
