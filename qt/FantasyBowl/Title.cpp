
#include "Title.h"

Title::Title(QString n, QString p)
{
	name = n;
	pawn = p;
}

QString Title::getName()
{
	return name;
}

QString Title::getPawn()
{
	return pawn;
}


