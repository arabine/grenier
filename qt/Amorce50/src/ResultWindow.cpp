/*=============================================================================
 * Amorce50 - ResultWindow.cpp
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

#include <QPrinter>
#include <QTextDocument>
#include "ResultWindow.h"

/*****************************************************************************/
ResultWindow::ResultWindow() : QDialog()
{
   ui.setupUi(this);
	connect( ui.btnPrint, SIGNAL(clicked()), this, SLOT(print()) );
}
/*****************************************************************************/
void ResultWindow::print()
{
	QPrinter printer;
   QTextDocument *doc = ui.resultView->document();

   doc->print(&printer);
}
/*****************************************************************************/
void ResultWindow::setText( QString &txt )
{
   ui.resultView->setText(txt);
}

//=============================================================================
// Fin du fichier ResultWindow.cpp
//=============================================================================
