/****************************************************************************
** Form interface generated from reading ui file '.\MainUI.ui'
**
** Created: jeu. 1. avr. 13:53:27 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.2.1   edited May 19 14:22 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef MAINUI_H
#define MAINUI_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QLabel;
class QLineEdit;
class QTextEdit;
class QPushButton;

class MainUI : public QDialog
{
    Q_OBJECT

public:
    MainUI( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~MainUI();

    QLabel* textLabel2;
    QLineEdit* patternText;
    QLabel* textLabel1;
    QTextEdit* searchText;
    QPushButton* btnTest;
    QLabel* textLabel3;
    QTextEdit* resultText;
    QPushButton* buttonOk;

protected:
    QVBoxLayout* MainUILayout;
    QHBoxLayout* layout15;
    QHBoxLayout* layout14;
    QHBoxLayout* layout17;
    QHBoxLayout* Layout1;

protected slots:
    virtual void languageChange();

};

#endif // MAINUI_H
