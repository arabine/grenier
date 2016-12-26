
#ifndef TITLE_H
#define TITLE_H

#include <qstring.h>

class Title
{

private:
	QString name;
	QString pawn;

public:
	Title() {}
	Title(QString n, QString p);

	QString getName();
	QString getPawn();

};

#endif // TITLE_H