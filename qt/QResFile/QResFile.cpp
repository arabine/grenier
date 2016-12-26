

#include "QResFile.h"

QResFile::QResFile()
{
	version = 1;

}


int	QResFile::addFiles( QString &s )
{
	bool ret;

	QFile f( s );
	ret = f.open( IO_ReadOnly );

	if( ret == false )
		return 1;

	chunks.append( Chunk( 0, f.readAll(), f.name() ) );


	f.close();
	return 0;
}


int QResFile::loadResFile( QString &s )
{
	bool ret;

	QFile f( s );
	ret = f.open( IO_ReadOnly );

	if( ret == false )
		return 1;


	return 0;
}

int QResFile::extractResFile( QString &s )
{

	return 0;
}


int QResFile::saveResFile( QString &s )
{
	bool ret;

	if( chunks.count() == 0 )
		return 2;


	QFile f( s );
	ret = f.open( IO_WriteOnly );

	if( ret == false )
		return 1;

	QByteArray block;
	QDataStream out( block, IO_WriteOnly );

	// Le header
	out << (Q_UINT8)'T' << (Q_UINT8)'A' << (Q_UINT8)'R' << (Q_UINT8)'C'; 
	out << (Q_UINT8)version;
	out << (Q_UINT8)type;
	out << (Q_UINT8)0 << (Q_UINT8)0 << (Q_UINT8)0 << (Q_UINT8)0;	// checksum, on l'insèrera à la fin
	out << (Q_UINT16)chunks.count();
	
	// les éléments
	QValueList<Chunk>::Iterator it;
	for( it=chunks.begin(); it != chunks.end(); ++it )
	{
		out << (Q_UINT32)(*it).name.length();
		for( int i=0; i< (*it).name.length(); i++ )
			out << (Q_UINT8)(*it).name[i].latin1();
		out << (Q_UINT32)(*it).data.size();
		out.writeRawBytes( (*it).data.data(), (*it).data.size() );
	}

	// TODO : compression optionnelle
//	block = qCompress( block ); // compresse avec zlib

	f.writeBlock( block.data(), block.size() );
	f.close();
	return 0;
}


