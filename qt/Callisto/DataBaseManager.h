/*=============================================================================
 * DataBaseManager.h
 *=============================================================================
 * Classe de gestion des bases de données
 *=============================================================================
 * (c) Anthony RABINE - 2002
 * Environment : VC++ 6.0
 * Build : Anthony RABINE - 27/10/2002
 *=============================================================================
 */

#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H


// Librairies QT
#include <qstring.h>
#include <qapplication.h>

// Librairies MySQL
#include <winsock.h>
#include <mysql.h>

// Macros
#define TABLE_AUTEURS "(Id_auteur SMALLINT UNSIGNED PRIMARY KEY AUTO_INCREMENT, nom VARCHAR(255) NOT NULL, infos TEXT)"
#define TABLE_LIVRES "(Id_livre MEDIUMINT UNSIGNED PRIMARY KEY AUTO_INCREMENT, Id_auteur SMALLINT UNSIGNED, date_pub DATE NOT NULL, titre VARCHAR(255) NOT NULL, type TINYINT UNSIGNED, titre_vo VARCHAR(255) NOT NULL, commentaire TEXT)"
#define TABLE_NOUVELLES "(Id_nouvelle MEDIUMINT UNSIGNED PRIMARY KEY AUTO_INCREMENT, Id_livre MEDIUMINT UNSIGNED, date_pub DATE NOT NULL, titre VARCHAR(255) NOT NULL, titre_vo VARCHAR(255) NOT NULL, commentaire TEXT)"

/*
Type de livre
--------------
numéro	type
--------------
0		roman
1		recueil de nouvelles

*/


class DataBaseManager
{
private:
	QString IP,user,password;
	long int port;
	MYSQL *db;

public:
	DataBaseManager();
	~DataBaseManager()
	{
		mysql_close(db);
	}

	bool initDataBase();
	bool setNewAuthor(QString nom, QString description);
	bool numberOfElements(const char *tableName, unsigned int *nombre);
	bool getElements(const char *tableName, const char *columnName, char **values, unsigned int nb);
	bool deleteEntry(const char *tableName, const char *columnName, const char *text);
	bool getInfos(const char *tableName, const char *columnName, char **values, const char *auteur);

};

#endif
//=============================================================================
// End of DataBaseManager.h
//=============================================================================

