
#include <qfile.h>
#include <qdir.h>
#include <qvaluelist.h>
#include <qfileinfo.h>

#include "Chunk.h"

class QResFile
{

private:

	// Header
	Q_UINT8		version;
	Q_UINT8		type;
	Q_UINT32	checksum;
	QString		mainPath;	

	QValueList<Chunk>	chunks;


public:
	QResFile();

	int		addFiles( QString & );
	int		loadResFile( QString & );
	int		extractResFile( QString & );
	int		saveResFile( QString & );
};

