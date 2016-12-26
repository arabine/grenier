


#include "MyQLineEdit.h"

MyQLineEdit::MyQLineEdit(QWidget * parent, const char * name)
				 : QLineEdit(parent, name) 
{
	// Enlever les commentaires si Qt >= 3.0 , QLineEdit hérite alors de QFrame
	// Ce qui n'est pas le cas avec Qt 2.3

	// C'est juste pour que ça soit plus zoli :)

//	setFrameStyle(QFrame::Box | QFrame::Plain );
//	setLineWidth(1);

}