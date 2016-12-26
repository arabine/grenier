


#include "Chunk.h"

Chunk::Chunk()
{


}


Chunk::Chunk( Q_UINT32 t, QByteArray &d, QString &n )
{
	type = t;
	data = d.copy();
	name = n;
}

Chunk::~Chunk()
{


}

