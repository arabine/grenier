class Neurone
{
private:
	double	*Xi,	// Entr�es analogiques (dendrites), ou motif
			*Wi,	// Poids synaptiques de chaque entr�e
			Bias,	// Bias (ou seuil)
			Sum,	// Somme pond�r�e du neuronne
			Y;		// Sortie (axone), vecteur de sortie d�sir�
	unsigned int	NbEntrees;	// Nombre d'entr�es du neurone
public:
	Neurone(unsigned int NbrInputs);	// Cr�ation du neurone, on sp�cifie le nombre d'entr�es
	~Neurone(){}
	
	void	VecteurEntrees(double *Vecteur);

	// Calcul de la sortie Y avec les fonctions d'activation du neurone, � utiliser au choix.
	void	Sigmoide();
	double	Unitaire();

	// Sommation des entr�es et soustraction du bias
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
	// on initialise toutes les donn�es membres
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
		La fonction sigmoide peut �tre mod�lis�e par la fonction tangente hyperbolique :
		
		  y(x)=tanh(x)
		
		On utilise donc la librairie Math.h.
		Notons que l'on peut �galement utiliser la fonction suivante :

			y(x)=1/(1+exp(-x))

		Mais des �tudes ont d�montr�es que la fonction tangente hyperbolique permet de 
		converger vers le r�sultat plus rapidement
	*/
	Sommation();
	Y=tanh(Sum);
	
	return;
}

double Neurone::Unitaire ()
{
	/*
		La fonction unitaire (ou Heaveside) est tr�s simple :
		
		  y(x)=		0 si x < 0
				ou	1 si x >= 0

		Cette fonction est utile pour simuler des portes logiques ou pour classifier
		des �l�ments.
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
		Somme=Somme+(Xi[i]*Wi[i]);	// on additionne toutes les entr�es pond�r�es

	Sum=Somme-Bias;	// on soustrait le Bias

	return;
}