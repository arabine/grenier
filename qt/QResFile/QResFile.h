
#include <qfile.h>
#include <qvaluelist.h>

#include "Chunk.h"


class QResFile
{

private:

	// Header
	Q_UINT8		version;
	Q_UINT8		type;
	Q_UINT32	checksum;
	

	QValueList<Chunk>	chunks;


public:
	QResFile();

	int		addFiles( QString & );
	int		loadResFile( QString & );
	int		extractResFile( QString & );
	int		saveResFile( QString & );
};

