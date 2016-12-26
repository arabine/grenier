/****************************************************************************
** Form interface generated from reading ui file '.\MainForm.ui'
**
** Created: Thu Nov 13 00:31:01 2003
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#ifndef MAINFORM_H
#define MAINFORM_H

#include <qvariant.h>
#include <qdialog.h>
class QVBoxLayout; 
class QHBoxLayout; 
class QGridLayout; 
class QComboBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QListBox;
class QListBoxItem;
class QMultiLineEdit;
class QPushButton;

class MainForm : public QDialog
{ 
    Q_OBJECT

public:
    MainForm( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~MainForm();

    QGroupBox* GroupBox2;
    QLineEdit* lneTrack;
    QLabel* lblTrack;
    QLabel* lblTitle;
    QLabel* lblArtist;
    QLabel* lblAlbum;
    QLabel* lblDate;
    QLabel* lblComment;
    QLineEdit* lneDate;
    QLineEdit* lneAlbum;
    QLineEdit* lneArtist;
    QLineEdit* lneTitle;
    QLabel* lblGenre;
    QComboBox* ComboBox1;
    QMultiLineEdit* mlneComment;
    QGroupBox* GroupBox3;
    QPushButton* btnAddNew;
    QPushButton* btnDelete;
    QPushButton* btnDeleteAll;
    QListBox* listBoxOther;
    QPushButton* btnUpdate;
    QPushButton* btnClose;
    QPushButton* btnFile;
    QLabel* PixmapLabel1;
    QLabel* lblFile;
    QLineEdit* lneFile;
    QGroupBox* GroupBox1;
    QLabel* lblVendor;
    QLabel* lblVersion;
    QLabel* lblSerial;
    QLabel* lblSamplingRate;
    QLabel* lblChannels;
    QLabel* lblNominalBitrate;
    QLabel* lblLength;
    QLabel* lblAvgBitrate;
    QLabel* lblFileSize;
    QLabel* TextLabel1;

protected:
    QVBoxLayout* Layout2;
};

#endif // MAINFORM_H
