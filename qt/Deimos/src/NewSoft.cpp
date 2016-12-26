
#include "NewSoft.h"
#include "windows.h"

NewSoft::NewSoft( QWidget *parent, Qt::WFlags f )
         : QDialog( parent, f )
{
   ui.setupUi(this);
   connect(ui.startCapture, SIGNAL(clicked()), this, SLOT(slotStartCapture()) );
}


void NewSoft::slotStartCapture()
{
   HWND hFore;
   int nbTchar;
   wchar_t *buff = new wchar_t(256);

   Sleep(5000);
   hFore = GetForegroundWindow();
   nbTchar = GetClassName(hFore, buff, 256);
   ui.className->setText(QString::fromStdWString(buff));

}

QString NewSoft::getClassName()
{
   return(ui.className->text());
}

QString NewSoft::getSoftName()
{
   return(ui.applicationName->text());
}


// Fin fichier
