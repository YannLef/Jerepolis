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
 * Includes Jerepolis
 * */
#include "../headers/structures.h"
#include "../headers/ModeleBatiment.h"
#include "../headers/AmeliorationBatiment.h"

/**
 * Includes correspondant
 * */
#include "../headers/Batiment.h"


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

void initBatiment(Batiment* b, ModeleBatiment* m, int x, int y){
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
	
	ModeleBatiment* lvl = getModeleNiveauBatiment(m, 1);
	if(lvl == NULL){
		error("Le niveau demandé n'est pas disponnible dans le modèle. Impossible d'initialiser le batiment");
		debug("<initBatiment> end : niveau indisponible dans le modèle");
		return;
	}
	
	b->nom = lvl->nom;
	b->type = lvl->type;
	b->niveau = 1;
	b->nbAmeliorationsEnCours = 0;
	b->prixAmeliorationBois = lvl->prixAmeliorationBois;
	b->prixAmeliorationPierre = lvl->prixAmeliorationPierre;
	b->prixAmeliorationArgent = lvl->prixAmeliorationArgent;
	b->tempsAmelioration = lvl->tempsAmelioration;
	b->max = lvl->dernier;
	b->modele = m;
	b->x = x;
	b->y = y;
	b->image = lvl->image;
	
	debug("<initBatiment> end");
}

void amelioreBatiment(Batiment* batiment, int* bois, int* pierre, int* argent, ameliorationBatiment** fileDeConstructions){
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
	if(batiment->prixAmeliorationBois > *bois){
		printf("Vous n'avez pas assez de bois\n");
		return;
	}
	if(batiment->prixAmeliorationPierre > *pierre){
		printf("Vous n'avez pas assez de pierre\n");
		return;
	}
	if(batiment->prixAmeliorationArgent > *argent){
		printf("Vous n'avez pas assez de argent\n");
		return;
	}
	if(getTailleFileDeConstruction(*fileDeConstructions) > 4){
		printf("Votre file de constructions est pleine\n");
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
	
	//~ DonneesImageRGB *image = NULL;
	//~ image = lisBMPRGB(b.image);
	if(b.image != NULL){ ecrisImage(b.x, b.y, b.image->largeurImage, b.image->hauteurImage, b.image->donneesRGB);}
	
	debug("<afficheBatiment> end");
}

void gereClicBatiment(Batiment*  b, int x, int y, int* bois, int* pierre, int* argent, ameliorationBatiment** fileDeConstructions){
	if(x > b->x && x < b->x + b->image->largeurImage && y > b->y && y < b->y + b->image->hauteurImage){
		amelioreBatiment(b, bois, pierre, argent, fileDeConstructions);
	}
}


