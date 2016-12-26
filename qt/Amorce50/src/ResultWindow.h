/*=============================================================================
 * Amorce50 - ResultWindow.h
 *=============================================================================
 * ResultWindow : résultat des courses sous forme imprimable
 *=============================================================================
 * Amorce50 est un logiciel de pointage manuel pour courses amateurs de 50cm3
 * Copyright (C) 2004-2007  Anthony Rabine
 * anthony@ooso.org
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *=============================================================================
 */

#ifndef _RESULTWINDOW_H
#define _RESULTWINDOW_H

// Includes Qt
#include <QDialog>
#include <QString>
#include <QPushbutton>

// Includes locales
#include "ui/ui_Result.h"
#include "Classes.h"

/****************************************************************************/
class ResultWindow : public QDialog
{
	Q_OBJECT

private:
   Ui::Result  ui;

public:
	ResultWindow();
   void setText( QString &txt );

public slots:
	void print();
};

#endif // _RESULTWINDOW_H

//=============================================================================
// Fin du fichier ResultWindow.h
//=============================================================================
