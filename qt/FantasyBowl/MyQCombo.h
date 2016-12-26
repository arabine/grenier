

#ifndef MYQCOMBO_H
#define MYQCOMBO_H

// Librairies Qt
#include <qcombobox.h>
#include <qmap.h>

#include "Title.h"

class MyQCombo : public QComboBox
{

public:
	MyQCombo(QWidget *parent, const QMap<int, Title> &theTitleList);

};

#endif // MYQCOMBO_H

//=============================================================================
// Fin du fichier MyQCombo.h
//=============================================================================