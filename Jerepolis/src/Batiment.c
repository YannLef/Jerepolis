/**
 * Includes Classiques
 * */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Includes GfxLib
 * */
#include "../../GfxLib/headers/GfxLib.h"
#include "../../GfxLib/headers/BmpLib.h"

/**
 * Includes Logger
 * */
#include "../../Logger/headers/Logger.h"

/**
 * Includes CustomGfxComponents
 * */
#include "../../CustomGfxComponents/headers/structures.h"
#include "../../CustomGfxComponents/headers/Couleur.h"
#include "../../CustomGfxComponents/headers/Image.h"

/**
 * Includes Jerepolis
 * */
#include "../headers/structures.h"
#include "../headers/ModeleBatiment.h"
#include "../headers/AmeliorationBatiment.h"

/**
 * Includes correspondant
 * */
#include "../headers/Batiment.h"

extern CouleurTab c;
extern int vitesse;


char* getBatimentTypeName(typeBatiment type){
	debug("<getBatimentTypeName> begin");
	
	switch(type){
		case BATIMENT_NORMAL:
			return "BATIMENT_NORMAL";
			break;
		case BATIMENT_PRODUCTION:
			return "BATIMENT_PRODUCTION";
			break;
	}
	
	debug("<getBatimentTypeName> end");
}

void printBatiment(Batiment batiment){
	debug("<printBatiment> begin");
	
	printf("Nom : %s\n", batiment.nom);
	printf("Type : %s\n", getBatimentTypeName(batiment.type));
	printf("Niveau : %d\n", batiment.niveau);
	printf("Ameliorations en cours : %d\n", batiment.nbAmeliorationsEnCours);
	printf("Prix Amelioration Bois : %d\n", batiment.prixAmeliorationBois);
	printf("Prix Amelioration Pierre : %d\n", batiment.prixAmeliorationPierre);
	printf("Prix Amelioration Argent : %d\n", batiment.prixAmeliorationArgent);
	printf("Temps Amelioration : %d\n", batiment.tempsAmelioration);
	printf("Max : %d\n", batiment.max);
	
	debug("<printBatiment> end");
}

void initBatiment(Batiment* b, ModeleBatiment* m, int x, int y, int xDebutHitBox, int xFinHitBox, int yDebutHitBox, int yFinHitBox, Popup popup){
	debug("<initBatiment> begin");
	
	if(b == NULL){
		error("Le pointeur vers le bâtiment ne peut doit pas être à NULL");
		debug("<initBatiment> end : pointeur vers batiment invalide");
		return;
	}
	
	if(m == NULL){
		error("Le pointeur vers le modèle ne peut doit pas être à NULL");
		debug("<initBatiment> end : pointeur vers modèle invalide");
		return;
	}
	
	ModeleBatiment* lvl = m;
	if(lvl == NULL){
		error("Le niveau demandé n'est pas disponnible dans le modèle. Impossible d'initialiser le batiment");
		debug("<initBatiment> end : niveau indisponible dans le modèle");
		return;
	}
	
	b->nom = lvl->nom;
	b->type = lvl->type;
	b->niveau = lvl->niveau;
	b->nbAmeliorationsEnCours = 0;
	b->population = 0;
	b->populationMax = lvl->populationMax;
	b->prixAmeliorationBois = lvl->prixAmeliorationBois;
	b->prixAmeliorationPierre = lvl->prixAmeliorationPierre;
	b->prixAmeliorationArgent = lvl->prixAmeliorationArgent;
	b->tempsAmelioration = lvl->tempsAmelioration;
	b->max = lvl->dernier;
	b->modele = m;
	b->x = x;
	b->y = y;
	b->image = lvl->image;
	b->production = lvl->production;

	setIconImage(b, "icon");
	
	setPopupImage(b, "popup");
	
	b->popupValue = popup;
	
	b->xDebutHitBox = xDebutHitBox;
	b->xFinHitBox = xFinHitBox;
	b->yDebutHitBox = yDebutHitBox;
	b->yFinHitBox = yFinHitBox;
	
	debug("<initBatiment> end");
}

void setIconImage(Batiment* b, char* iconImageName){
	char tmp[100];
	
	strcpy(tmp, "../Jerepolis/ressources/images/batiments/");
	strcat(tmp, b->nom);
	strcat(tmp, "/");
	strcat(tmp, iconImageName);
	strcat(tmp, ".bmp");
	
	if(b->icon != NULL){
		warn("Un icon est déjà défini dans cette variable. Il sera écrasé.");
		libereDonneesImageRGB(&(b->icon));
		b->icon = NULL;
	}
	
	b->icon = lisBMPRGB(tmp);
	if(b->icon == NULL){
		error("Erreur lors de l'ouverture de l'icon du batiment");
	}
}

void setPopupImage(Batiment* b, char* popupImageName){
	char tmp[100];
	
	strcpy(tmp, "../Jerepolis/ressources/images/batiments/");
	strcat(tmp, b->nom);
	strcat(tmp, "/");
	strcat(tmp, popupImageName);
	strcat(tmp, ".bmp");
	
	if(b->popup != NULL){
		warn("Une popup est déjà définie dans cette variable. Elle sera écrasée.");
		libereDonneesImageRGB(&(b->popup));
		b->popup = NULL;
	}
	
	b->popup = lisBMPRGB(tmp);
	if(b->popup == NULL){
		error("Erreur lors de l'ouverture de la popup du batiment");
	}
}

void amelioreBatiment(Batiment* batiment, float* bois, float* pierre, float* argent, ameliorationBatiment** fileDeConstructions){
	debug("<amelioreBatiment> begin");
	
	if(fileDeConstructions == NULL){
		error("le pointeur de la file de constructions ne doit pas être à NULL");
		debug("<amelioreBatiment> end : le pointeur de la file de constructions est invalide");
		return;
	}
	if(batiment == NULL){
		error("le pointeur du batiment à améliorer ne doit pas être à NULL");
		debug("<amelioreBatiment> end : le pointeur du batiment à améliorer est invalide");
		return;
	}
	if(bois == NULL){
		error("le pointeur du stock de bois ne doit pas être à NULL");
		debug("<amelioreBatiment> end : le pointeur du stock de bois est invalide");
		return;
	}
	if(pierre == NULL){
		error("le pointeur du stock de pierre ne doit pas être à NULL");
		debug("<amelioreBatiment> end : le pointeur du pierre de bois est invalide");
		return;
	}
	if(argent == NULL){
		error("le pointeur du stock d'argent ne doit pas être à NULL");
		debug("<amelioreBatiment> end : le pointeur du stock d'argent est invalide");
		return;
	}
	
	if(batiment->max){
		printf("Ce bâtiment est déjà au niveau maximum\n");
		return;
	}
	if(batiment->prixAmeliorationBois > *bois || batiment->prixAmeliorationPierre > *pierre || batiment->prixAmeliorationArgent > *argent){
		printf("Vous n'avez pas assez de ressources\n");
		return;
	}
	if(getTailleFileDeConstruction(*fileDeConstructions) >= 4){
		printf("La file de constructions est pleine\n");
		return;
	}
	
	*bois = *bois - batiment->prixAmeliorationBois;
	*pierre = *pierre - batiment->prixAmeliorationPierre;
	*argent = *argent - batiment->prixAmeliorationArgent;
	ameliorationBatiment* amelioration;
	initAmeliorationBatiment(&amelioration, batiment);
	if(amelioration == NULL){
		error("Erreur : l'initialisation de l'amélioration pour le batiment %s n'a pas fonctionnée", batiment->nom);
		debug("<amelioreBatiment> end : erreur lors de l'initialisation de l'amélioration");
		return;
	}
	ajouteAmeliorationBatiment(fileDeConstructions, amelioration);
	
	batiment->nbAmeliorationsEnCours++;
	
	ModeleBatiment* niveauSuivant = getModeleNiveauBatiment(batiment->modele, batiment->niveau + batiment->nbAmeliorationsEnCours);
	if(niveauSuivant == NULL){
		error("Erreur : le niveau supérieur n'a pas été trouvé pour le bâtiment %s", batiment->nom);
		debug("<amelioreBatiment> end : le niveau supérieur n'a pas été trouvé");
		return;
	}
	
	batiment->prixAmeliorationBois = niveauSuivant->prixAmeliorationBois;
	batiment->prixAmeliorationPierre = niveauSuivant->prixAmeliorationPierre;
	batiment->prixAmeliorationArgent = niveauSuivant->prixAmeliorationArgent;
	batiment->tempsAmelioration = niveauSuivant->tempsAmelioration;
	
	if(niveauSuivant->dernier){
		batiment->max = 1;
		batiment->prixAmeliorationBois = 0;
		batiment->prixAmeliorationPierre = 0;
		batiment->prixAmeliorationArgent = 0;
	}
	
	printf("L'amélioration du bâtiment %s a été lancée\n", batiment->nom);
	
	debug("<amelioreBatiment> end");
}

void afficheBatiment(Batiment b){
	debug("<afficheBatiment> begin");
	
	couleur magenta;
	magenta.r = 255;
	magenta.v = 0;
	magenta.b = 255;
	if(b.image != NULL){ ecrisImageSansFond(b.x, b.y, b.image->largeurImage, b.image->hauteurImage, b.image->donneesRGB, magenta);}
	
	// Affichage des Hitboxes :
	//~ couleurCourante(255, 0, 0);
	//~ rectangle(b.xDebutHitBox, b.yDebutHitBox, b.xFinHitBox, b.yFinHitBox);
	
	debug("<afficheBatiment> end");
}

void gereClicDroitBatiment(Batiment*  b, int x, int y){
	debug("<gereClicDroitBatiment> begin");
	
	if(x > b->xDebutHitBox && x < b->xFinHitBox && y > b->yDebutHitBox && y < b->yFinHitBox){
		peupleBatiment(b, 1);
	}
	
	debug("<gereClicDroitBatiment> end");
}

void peupleBatiment(Batiment* b, int nouvellePopulation){
	debug("<peupleBatiment> begin");
	
	if(b->populationMax >= b->population + nouvellePopulation){
		b->population += nouvellePopulation;
	}else{
		printf("Population maximale atteinte pour %s, améliorez la batiment pour augmenter la limite\n", b->nom);
	}
	
	debug("<peupleBatiment> end");
}

void genereRessource(Batiment b, float* ressource, int stockageEntrepot){
	debug("<genereRessource> begin");

	*ressource += b.production*vitesse*(1 + 0.3*b.population);
	
	if(*ressource > stockageEntrepot){
		*ressource = stockageEntrepot;
	}
	
	debug("<genereRessource> end");
}

void gereClicGaucheBatiment(Batiment*  b, int x, int y, Popups* popups){
	debug("<gereClicGaucheBatiment> begin");
	
	if(x > b->xDebutHitBox && x < b->xFinHitBox && y > b->yDebutHitBox && y < b->yFinHitBox && b->niveau > 0){
		if(popups->actuel == popups->final){
				popups->final = b->popupValue;
		}
	}
	
	debug("<gereClicGaucheBatiment> end");
}

void afficheInfosBatiment(Batiment senat, DonneesImageRGB* infosBatiment, Batiment ferme, Batiment scierie, Batiment entrepot, Batiment carriere, Batiment caserne, Batiment temple, Batiment mine){
	
	couleur magenta;
	magenta.r = 255;
	magenta.v = 0;
	magenta.b = 255;
	
	char population[100];
	char niveau[100];
	int x = 0;
	int y = 0;
	changeColor(c.blanc);
	
	// Senat
	x = 620;
	y = 420;
	if(infosBatiment != NULL){ ecrisImageSansFond(x, y, infosBatiment->largeurImage, infosBatiment->hauteurImage, infosBatiment->donneesRGB, magenta);}
	sprintf(population,"%d/%d", senat.population, senat.populationMax);
	afficheChaine(population, 10, x+30, y+5);
	sprintf(population,"%d", senat.niveau);
	afficheChaine(population, 10, x+30, y+25);
	
	// Ferme
	x = 740;
	y = 450;
	if(infosBatiment != NULL){ ecrisImageSansFond(x, y, infosBatiment->largeurImage, infosBatiment->hauteurImage, infosBatiment->donneesRGB, magenta);}
	sprintf(population,"%d/%d", ferme.population, ferme.populationMax);
	afficheChaine(population, 10, x+30, y+5);
	sprintf(population,"%d", ferme.niveau);
	afficheChaine(population, 10, x+30, y+25);
	
	// Scierie
	x = 640;
	y = 220;
	if(infosBatiment != NULL){ ecrisImageSansFond(x, y, infosBatiment->largeurImage, infosBatiment->hauteurImage, infosBatiment->donneesRGB, magenta);}
	sprintf(population,"%d/%d", scierie.population, scierie.populationMax);
	afficheChaine(population, 10, x+30, y+5);
	sprintf(population,"%d", scierie.niveau);
	afficheChaine(population, 10, x+30, y+25);
	
	// Entrepot
	x = 570;
	y = 305;
	if(infosBatiment != NULL){ ecrisImageSansFond(x, y, infosBatiment->largeurImage, infosBatiment->hauteurImage, infosBatiment->donneesRGB, magenta);}
	sprintf(population,"%d/%d", entrepot.population, entrepot.populationMax);
	afficheChaine(population, 10, x+30, y+5);
	sprintf(population,"%d", entrepot.niveau);
	afficheChaine(population, 10, x+30, y+25);
	
	// Carriere
	x = 435;
	y = 290;
	if(infosBatiment != NULL){ ecrisImageSansFond(x, y, infosBatiment->largeurImage, infosBatiment->hauteurImage, infosBatiment->donneesRGB, magenta);}
	sprintf(population,"%d/%d", carriere.population, carriere.populationMax);
	afficheChaine(population, 10, x+30, y+5);
	sprintf(population,"%d", carriere.niveau);
	afficheChaine(population, 10, x+30, y+25);
	
	// Caserne
	x = 490;
	y = 360;
	if(infosBatiment != NULL){ ecrisImageSansFond(x, y, infosBatiment->largeurImage, infosBatiment->hauteurImage, infosBatiment->donneesRGB, magenta);}
	sprintf(population,"%d/%d", caserne.population, caserne.populationMax);
	afficheChaine(population, 10, x+30, y+5);
	sprintf(population,"%d", caserne.niveau);
	afficheChaine(population, 10, x+30, y+25);
	
	// Temple
	x = 400;
	y = 380;
	if(infosBatiment != NULL){ ecrisImageSansFond(x, y, infosBatiment->largeurImage, infosBatiment->hauteurImage, infosBatiment->donneesRGB, magenta);}
	sprintf(population,"%d/%d", temple.population, temple.populationMax);
	afficheChaine(population, 10, x+30, y+5);
	sprintf(population,"%d", temple.niveau);
	afficheChaine(population, 10, x+30, y+25);
	
	// Mine
	x = 390;
	y = 480;
	if(infosBatiment != NULL){ ecrisImageSansFond(x, y, infosBatiment->largeurImage, infosBatiment->hauteurImage, infosBatiment->donneesRGB, magenta);}
	sprintf(population,"%d/%d", mine.population, mine.populationMax);
	afficheChaine(population, 10, x+30, y+5);
	sprintf(population,"%d", mine.niveau);
	afficheChaine(population, 10, x+30, y+25);
}


