
#ifndef DEFINES_H
#define DEFINES_H

#define AMORCE50_VERSION "0.3"

typedef enum {
   DISQUALIFIE = -3, // diqualification sur demande
   NON_CLASSE = -2,  // n'a pas effectué le nombre minimum de tours requis
   ABANDON = -1,     // a eu un accident, n'a pas franchi la ligne d'arrivée
   ARRIVE = 0        // le pilote est bien arrivé
} STATUT_PILOTE;


// Définitions des tables de la base
#define TABLE_SAISONS "(Id_saison INTEGER PRIMARY KEY, \
						nom VARCHAR(255) NOT NULL )"

#define TABLE_PILOTES "(Id_pilote INTEGER PRIMARY KEY, \
						nom VARCHAR(255) NOT NULL, \
						numero INTEGER NOT NULL, \
						club VARCHAR(255) NOT NULL, \
						id_categorie INTEGER NOT NULL )"

#define TABLE_COURSES "(Id_course INTEGER PRIMARY KEY, \
						id_saison INTEGER NOT NULL, \
						nom VARCHAR(255) NOT NULL, \
						date VARCHAR(255) NOT NULL )"

#define TABLE_CATEGORIES "(	Id_categorie INTEGER PRIMARY KEY, \
                     id_cat_parent INTEGER, \
							nom VARCHAR(255) NOT NULL)"

#define TABLE_EPREUVES "(	Id_epreuve INTEGER PRIMARY KEY, \
							id_manche INTEGER NOT NULL, \
							id_pilote INTEGER NOT NULL, \
							place INTEGER NOT NULL, \
							tours INTEGER NOT NULL, \
							statut INTEGER NOT NULL )"
/*
Statut :
	0 : pilote arrivé
	1 : pilote n'a pas franchi l'arrivée (abandon)
	2 : pilote disqualifié
	3 : pilote hors catégorie (ne figure pas dans le classement)
*/


#define TABLE_MANCHES "(Id_manche INTEGER PRIMARY KEY, \
						id_course INTEGER NOT NULL, \
						id_categorie INTEGER NOT NULL, \
						numero INTEGER NOT NULL, \
						statut TINYINT NOT NULL, \
						pointage TEXT NOT NULL, \
						premier INTEGER NOT NULL )"

#define TABLE_POINTS "(	position INTEGER PRIMARY KEY, \
						points INTEGER )"

// Stocke des infos générales et des paramètres utilisateurs
#define TABLE_INFOS "(	version VARCHAR(255) NOT NULL )"


/** 
 * Cette table gère les ID uniques des tables de la base amorce50.dat
 * 
 * Remarque : Id_categories initialisé à 1 car cet Id est réservé pour 
 * les pilotes sans catégories (pilotes fantômes)
 */
#define TABLE_IDS "(Id_saisons INTEGER NOT NULL, \
					Id_pilotes INTEGER NOT NULL, \
					Id_courses INTEGER NOT NULL, \
					Id_categories INTEGER NOT NULL, \
					Id_epreuves INTEGER NOT NULL, \
					Id_manches INTEGER NOT NULL	)"


#endif // DEFINES_H

//=============================================================================
// Fin du fichier defines.h
//=============================================================================
