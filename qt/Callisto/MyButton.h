/*=============================================================================
 * MyButton.h
 *=============================================================================
 * Bouton personalisé (plat avec un rollover)
 *=============================================================================
 * (c) Anthony RABINE - 2002
 * Environment : VC++ 6.0
 * Build : Anthony RABINE - 27/10/2002
 *=============================================================================
 */

#ifndef MYBUTTON_H
#define MYBUTTON_H

// Librairies QT
#include <qpushbutton.h> 
#include <qcolor.h>

class MyButton : public QPushButton
{

private:
//	QColor background_color, mouse_over_color, border_color;

public:
	MyButton(const QString & text, QWidget *parent, const char * name);

public slots:
	void enterEvent ( QEvent * );
	void leaveEvent ( QEvent * );
};

#endif

//=============================================================================
// End of MyButton.h
//=============================================================================