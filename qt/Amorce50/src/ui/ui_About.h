/********************************************************************************
** Form generated from reading ui file 'About.ui'
**
** Created: Sat 14. Apr 01:57:13 2007
**      by: Qt User Interface Compiler version 4.2.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <Qt3Support/Q3MimeSourceFactory>

class Ui_About
{
public:
    QGridLayout *gridLayout;
    QLabel *textLabel1;
    QPushButton *pushButton129;

    void setupUi(QDialog *About)
    {
    About->setObjectName(QString::fromUtf8("About"));
    gridLayout = new QGridLayout(About);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(9);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    textLabel1 = new QLabel(About);
    textLabel1->setObjectName(QString::fromUtf8("textLabel1"));
    textLabel1->setWordWrap(false);

    gridLayout->addWidget(textLabel1, 0, 0, 1, 1);

    pushButton129 = new QPushButton(About);
    pushButton129->setObjectName(QString::fromUtf8("pushButton129"));

    gridLayout->addWidget(pushButton129, 1, 0, 1, 1);


    retranslateUi(About);

    QSize size(392, 287);
    size = size.expandedTo(About->minimumSizeHint());
    About->resize(size);

    QObject::connect(pushButton129, SIGNAL(clicked()), About, SLOT(accept()));

    QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QDialog *About)
    {
    About->setWindowTitle(QApplication::translate("About", "Qt - \303\200 propos ...", 0, QApplication::UnicodeUTF8));
    textLabel1->setText(QApplication::translate("About", "Amorce50 est un logiciel de pointage manuel pour courses amateurs de 50cm3\n"
"Copyright (C) 2004-2007  Anthony Rabine\n"
"anthony@ooso.org\n"
"\n"
"This program is free software; you can redistribute it and/or\n"
"modify it under the terms of the GNU General Public License\n"
"as published by the Free Software Foundation; either version 2\n"
"of the License, or any later version.\n"
"\n"
"This program is distributed in the hope that it will be useful,\n"
"but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
"GNU General Public License for more details.\n"
"\n"
"You should have received a copy of the GNU General Public License\n"
"along with this program; if not, write to the Free Software\n"
"Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA", 0, QApplication::UnicodeUTF8));
    pushButton129->setText(QApplication::translate("About", "&Ok", 0, QApplication::UnicodeUTF8));
    pushButton129->setShortcut(QApplication::translate("About", "Alt+O", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(About);
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

#endif // UI_ABOUT_H
