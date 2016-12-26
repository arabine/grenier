/*=============================================================================
 * MyButton.cpp
 *=============================================================================
 * Bouton personalisé (plat avec un rollover)
 *=============================================================================
 * (c) Anthony RABINE - 2002
 * Environment : VC++ 6.0
 * Build : Anthony RABINE - 27/10/2002
 *=============================================================================
 */

#include "MyButton.h"

MyButton::MyButton(const QString & text, QWidget *parent, const char * name)
		: QPushButton(text, parent, name)
{

//	background_color = backgroundColor();
//	mouse_over_color = QColor(177,169,155);
//	border_color = QColor(105,98,87);
	setFlat(TRUE);
}

void MyButton::enterEvent( QEvent *ev )
{
//	setPalette(QPalette(mouse_over_color));
//	setBackgroundColor(mouse_over_color);
	setFlat(FALSE);

}

void MyButton::leaveEvent( QEvent *ev )
{
//	setPalette(QPalette(background_color));
//	setBackgroundColor(background_color);
	setFlat(TRUE);
}

//=============================================================================
// End of MyButton.cpp
//=============================================================================