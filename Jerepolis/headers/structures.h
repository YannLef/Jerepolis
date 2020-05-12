#define BATIMENT_NIVEAU_MAX 25

/**
 * Enumération permettant de différencier les batiments normaux des batiments servant à produire des ressources.
 * Permet de leur appliquer des comportements différents dasn le code
 * @author Yann LEFEVRE
 * */
typedef enum{ BATIMENT_NORMAL, BATIMENT_PRODUCTION} typeBatiment;

typedef enum Popup{ NONE, POPUP_SENAT }Popup;

/**
 * Permet de matérialiser un modèle de batiment : pouvant être chargé à partir d'un fichier .csv et permettant de déterminer le coportement d'un batiment.
 * @author Yann LEFEVRE
 * */
typedef struct ModeleBatiment{
	
	char* nom;
	typeBatiment type;
	int niveau;
	int populationMax;
	int prixAmeliorationBois;
	int prixAmeliorationPierre;
	int prixAmeliorationArgent;
	unsigned int tempsAmelioration;
	DonneesImageRGB *image;

	float production;
	
	int dernier;
	
	struct ModeleBatiment* suivant;
	
}ModeleBatiment;

/**
 * Permet de matérialiser un batiment
 * @author Yann LEFEVRE
 * */
typedef struct Batiment{
	
	// Informations courantes
	char* nom;
	typeBatiment type;
	int niveau;
	int populationMax;
	int population;
	int nbAmeliorationsEnCours;
	int prixAmeliorationBois;
	int prixAmeliorationPierre;
	int prixAmeliorationArgent;
	int tempsAmelioration;
	int max;
	float production;
	
	// Modèle du batiment
	ModeleBatiment* modele;
	
	// Graphique
	int x;
	int y;
	DonneesImageRGB *image;
	DonneesImageRGB *icon;
	DonneesImageRGB *popup;
	Popup popupValue;
	int xDebutHitBox;
	int xFinHitBox;
	int yDebutHitBox;
	int yFinHitBox;
}Batiment;

/**
 * Permet de matérialiser une amélioration de batiment, regroupant le batiment à améliorer et le temps restant avant la fin de l'amélioration
 * @author Yann LEFEVRE
 * */
typedef struct ameliorationBatiment{
	int timer; // Temps d'amélioration restant
	Batiment* batiment;
	
	int niveauPrecedent;
	int niveauSuivant;
	
	struct ameliorationBatiment* next; // Amélioration suivante dans la liste
	
}ameliorationBatiment;
