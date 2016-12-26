

#include <iostream.h>
#include <conio.h>

#include <qfile.h>
#include <qstring.h>

#include "QResFile.h"
#include "defines.h"

void usage();

int main( int argc, char **argv )
{	
	if( argc != 3 )
	{
		usage();
		return 0;
	}

	if( strlen(argv[1]) != 2 )
	{
		usage();
		return 0;
	}

	if( argv[1][0] != '-' )
	{
		usage();
		return 0;
	}

	if( argv[1][1] != 'c' && argv[1][1] != 'x' )
	{
		usage();
		return 0;
	}


	// Création d'une archive
	if( argv[1][1] == 'c' )
	{
		cout << "Adding all files of directory : " << argv[2] << " ..." << endl;
		QResFile  res;
		res.addFiles( QString(argv[2]) );
		cout << "Saving resource file ..." << endl;
		res.saveResFile( QString("out$$.tac") );
	}
	else // extraction de l'archive
	{
		cout << "Extracting archive : " << argv[2] << " ..." << endl;
		QResFile  res;
		res.extractResFile( QString(argv[2]) );
	}


	cout << "Done." << endl;
	return 0;
}


void usage()
{
	cout << "Tac - resources file manager." << endl << endl;
	cout << "usage : tac -c/x [directory]/[archive.tac]" << endl;

}

