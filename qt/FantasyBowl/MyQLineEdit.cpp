


#include "MyQLineEdit.h"

MyQLineEdit::MyQLineEdit(QWidget * parent, const char * name)
				 : QLineEdit(parent, name) 
{
	// Enlever les commentaires si Qt >= 3.0 , QLineEdit h�rite alors de QFrame
	// Ce qui n'est pas le cas avec Qt 2.3

	// C'est juste pour que �a soit plus zoli :)

//	setFrameStyle(QFrame::Box | QFrame::Plain );
//	setLineWidth(1);

}