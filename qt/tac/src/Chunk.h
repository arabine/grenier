
#include <qstring.h>
#include <qcstring.h>

class Chunk
{

public:
	Chunk();
	Chunk( Q_UINT32, QByteArray &, QString & );
	~Chunk();

	Q_UINT32	type;
	QByteArray	data;
	QString		name;

};

