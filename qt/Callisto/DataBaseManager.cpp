/*=============================================================================
 * DataBaseManager.cpp
 *=============================================================================
 * Classe de gestion des bases de données
 *=============================================================================
 * (c) Anthony RABINE - 2002
 * Environment : VC++ 6.0
 * Build : Anthony RABINE - 27/10/2002
 *=============================================================================
 */

#include "DataBaseManager.h"


DataBaseManager::DataBaseManager()
{
	IP = "127.0.0.1";
	port = 3306;
	user = "root";
	password = "abcd";
	db = mysql_init((MYSQL*) 0);

}

/*
void DataBaseManager::newDataBase()
{


}*/

// retourne faux si la connexion au serveur échoue
bool DataBaseManager::initDataBase()
{
	bool ret = true;

	QString SQL;
	if (!mysql_real_connect(db, IP, user, password, NULL, port, NULL, CLIENT_SSL | CLIENT_COMPRESS))
    {
        ret = false; // impossible de se connecter au serveur MySQL
    }
	else
	{

        // La base de données existe-t-elle ?
        if (mysql_select_db(db, "Callisto") != 0) // non
        {
            mysql_query(db, "CREATE DATABASE Callisto");
            mysql_select_db(db, "Callisto");

			SQL = "CREATE TABLE auteurs " TABLE_AUTEURS;
            mysql_query(db, SQL);

			SQL = "CREATE TABLE livres " TABLE_LIVRES;
            mysql_query(db, SQL);

			SQL = "CREATE TABLE nouvelles " TABLE_NOUVELLES;
            mysql_query(db, SQL);

        }
		else // oui, on crée les tables si elles n'existent pas
		{
			SQL = "CREATE TABLE IF NOT EXISTS auteurs " TABLE_AUTEURS;
            mysql_query(db, SQL);

			SQL = "CREATE TABLE IF NOT EXISTS livres " TABLE_LIVRES;
            mysql_query(db, SQL);

			SQL = "CREATE TABLE nouvelles " TABLE_NOUVELLES;
            mysql_query(db, SQL);
        }

    }
	
	return ret;
}


// retourne 0 en cas de succès, !=0 sinon
bool DataBaseManager::setNewAuthor(QString nom, QString description)
{
	QString SQL;
	
	SQL = "INSERT INTO auteurs VALUES (null,'" + nom + "','" + description + "')";
		
	if(mysql_query(db,SQL)==0)
		return true;
	else
		return false;
}

// Compte le nombre de lignes de la table <tableName>
bool DataBaseManager::numberOfElements(const char *tableName, unsigned int *nombre)
{
	MYSQL_RES *result;
	MYSQL_ROW row;
	QString SQL;
	bool ok;

	SQL = "SELECT COUNT(*) FROM " + QString(tableName);

	if(mysql_query(db,SQL)==0)
	{
		result = mysql_store_result(db);
		row = mysql_fetch_row(result);
		*nombre = QString(row[0]).toUInt(&ok);
		mysql_free_result(result);
		return true;
	}
	else
		return false;

}

// Capture les données de la colonne <columnName> de la table <tableName>
bool DataBaseManager::getElements(const char* tableName, const char *columnName, char **values, unsigned int nb)
{
	MYSQL_RES *result;
	MYSQL_ROW row;
	QString SQL;
	int i=0;

	SQL = "SELECT " + QString(columnName) + " FROM " + QString(tableName);

	if(mysql_query(db,SQL)==0)
	{
		result = mysql_store_result(db);
		
		while(row = mysql_fetch_row(result))
		{
			strcpy(values[i], row[0]);
			i++;
		}

		mysql_free_result(result);
		return true;
	}
	else
		return false;

}

bool DataBaseManager::deleteEntry(const char *tableName, const char *columnName, const char *text)
{
	QString SQL;

	SQL = "DELETE FROM " + QString(tableName) + " WHERE " + QString(columnName) + "='" + QString(text) + "'";

	if(mysql_query(db,SQL)==0)
		return true;
	else
		return false;

}

bool DataBaseManager::getInfos(const char *tableName, const char *columnName, char **values, const char *auteur)
{
	MYSQL_RES *result;
	MYSQL_ROW row;
	QString SQL;
	int i=0;
	bool ok;
	int ID;
/*
	// on choppe l'ID de l'auteur
	SQL = "SELECT Id_auteur FROM auteurs WHERE nom='" + auteur + "'";

	if(mysql_query(db,SQL)==0)
	{
		result = mysql_store_result(db);
		row = mysql_fetch_row(result);
		ID = QString(row[0]).toUInt(&ok);
		mysql_free_result(result);
	}
	else
		return false;

	SQL = "SELECT " + QString(columnName) + " FROM " + QString(tableName) + " WHERE Id_auteur='" + ID + "'"; ;

	if(mysql_query(db,SQL)==0)
	{
		result = mysql_store_result(db);
		
		while(row = mysql_fetch_row(result))
		{
			strcpy(values[i], row[0]);
			i++;
		}

		mysql_free_result(result);
		return true;
	}
	else
		return false;
*/
	return true;



}

//=============================================================================
// End of DataBaseManager.cpp
//=============================================================================