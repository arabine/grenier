
#include <QDialog>
#include "ui_NewApplication.h"


class NewSoft : public QDialog
{
	Q_OBJECT

private:
   Ui::NewApplication ui;

public:
   NewSoft( QWidget * parent = 0, Qt::WFlags f = 0 );
   QString getClassName();
   QString getSoftName();

public slots:
   void slotStartCapture();
   
};

// Fin fichier
