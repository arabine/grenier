class Neurone
{
private:
	double	*Xi,	// Entrées analogiques (dendrites), ou motif
			*Wi,	// Poids synaptiques de chaque entrée
			Bias,	// Bias (ou seuil)
			Sum,	// Somme pondérée du neuronne
			Y;		// Sortie (axone), vecteur de sortie désiré
	unsigned int	NbEntrees;	// Nombre d'entrées du neurone
public:
	Neurone(unsigned int NbrInputs);	// Création du neurone, on spécifie le nombre d'entrées
	~Neurone(){}
	
	void	VecteurEntrees(double *Vecteur);

	// Calcul de la sortie Y avec les fonctions d'activation du neurone, à utiliser au choix.
	void	Sigmoide();
	double	Unitaire();

	// Sommation des entrées et soustraction du bias
	void	Sommation();

	// Modification des poids synaptiques
	void	Synapses(double *Poids, double Seuil);
};

void Neurone::Synapses (double *Poids,double Seuil)
{
	unsigned int i;
	for(i=0;i<NbEntrees;i++)
		Wi[i]=Poids[i];
	Bias=Seuil;
}

void Neurone::VecteurEntrees (double *Vecteur)
{
	unsigned int i;
	for(i=0;i<NbEntrees;i++)
		Xi[i]=Vecteur[i];
}

Neurone::Neurone(unsigned int NbrInputs)
{
	// on initialise toutes les données membres
	Xi = new double[NbrInputs];
	Wi = new double[NbrInputs];
	NbEntrees=NbrInputs;
	Bias=0.0;
	Y=0.0;
	Sum=0.0;
}

void Neurone::Sigmoide ()
{
	/*
		La fonction sigmoide peut être modélisée par la fonction tangente hyperbolique :
		
		  y(x)=tanh(x)
		
		On utilise donc la librairie Math.h.
		Notons que l'on peut également utiliser la fonction suivante :

			y(x)=1/(1+exp(-x))

		Mais des études ont démontrées que la fonction tangente hyperbolique permet de 
		converger vers le résultat plus rapidement
	*/
	Sommation();
	Y=tanh(Sum);
	
	return;
}

double Neurone::Unitaire ()
{
	/*
		La fonction unitaire (ou Heaveside) est très simple :
		
		  y(x)=		0 si x < 0
				ou	1 si x >= 0

		Cette fonction est utile pour simuler des portes logiques ou pour classifier
		des éléments.
	*/
	Sommation();
	if(Sum<0)
		Y=0.0;
	else
		Y=1.0;
	return Y;
}

void Neurone::Sommation ()
{
	unsigned int i;
	double	Somme=0.0;
	
	for(i=0; i<NbEntrees; i++)
		Somme=Somme+(Xi[i]*Wi[i]);	// on additionne toutes les entrées pondérées

	Sum=Somme-Bias;	// on soustrait le Bias

	return;
}