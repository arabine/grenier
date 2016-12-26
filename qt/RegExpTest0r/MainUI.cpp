/****************************************************************************
** Form implementation generated from reading ui file '.\MainUI.ui'
**
** Created: jeu. 1. avr. 13:53:27 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.2.1   edited May 19 14:22 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "MainUI.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a MainUI as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
MainUI::MainUI( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "MainUI" );
    setSizeGripEnabled( TRUE );
    MainUILayout = new QVBoxLayout( this, 11, 6, "MainUILayout"); 

    layout15 = new QHBoxLayout( 0, 0, 6, "layout15"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout15->addWidget( textLabel2 );

    patternText = new QLineEdit( this, "patternText" );
    patternText->setFrameShape( QLineEdit::LineEditPanel );
    patternText->setFrameShadow( QLineEdit::Sunken );
    layout15->addWidget( patternText );
    MainUILayout->addLayout( layout15 );

    layout14 = new QHBoxLayout( 0, 0, 6, "layout14"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setAlignment( int( QLabel::AlignTop ) );
    layout14->addWidget( textLabel1 );

    searchText = new QTextEdit( this, "searchText" );
    layout14->addWidget( searchText );
    MainUILayout->addLayout( layout14 );

    btnTest = new QPushButton( this, "btnTest" );
    btnTest->setAutoDefault( TRUE );
    btnTest->setDefault( TRUE );
    MainUILayout->addWidget( btnTest );

    layout17 = new QHBoxLayout( 0, 0, 6, "layout17"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    textLabel3->setAlignment( int( QLabel::AlignTop ) );
    layout17->addWidget( textLabel3 );

    resultText = new QTextEdit( this, "resultText" );
    resultText->setPaletteBackgroundColor( QColor( 221, 221, 221 ) );
    resultText->setFrameShape( QTextEdit::StyledPanel );
    resultText->setFrameShadow( QTextEdit::Plain );
    resultText->setReadOnly( TRUE );
    layout17->addWidget( resultText );
    MainUILayout->addLayout( layout17 );

    Layout1 = new QHBoxLayout( 0, 0, 6, "Layout1"); 
    QSpacerItem* spacer = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout1->addItem( spacer );

    buttonOk = new QPushButton( this, "buttonOk" );
    buttonOk->setAutoDefault( TRUE );
    Layout1->addWidget( buttonOk );
    MainUILayout->addLayout( Layout1 );
    languageChange();
    resize( QSize(378, 456).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( buttonOk, SIGNAL( clicked() ), this, SLOT( accept() ) );
}

/*
 *  Destroys the object and frees any allocated resources
 */
MainUI::~MainUI()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void MainUI::languageChange()
{
    setCaption( tr( "RegExpTest0r" ) );
    textLabel2->setText( tr( "Pattern" ) );
    textLabel1->setText( tr( "Search" ) );
    btnTest->setText( tr( "Test regular expression pattern" ) );
    btnTest->setAccel( QKeySequence( QString::null ) );
    textLabel3->setText( tr( "Result" ) );
    buttonOk->setCaption( QString::null );
    buttonOk->setText( tr( "&OK" ) );
    buttonOk->setAccel( QKeySequence( tr( "Alt+O" ) ) );
}

