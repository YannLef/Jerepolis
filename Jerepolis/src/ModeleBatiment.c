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
#include "../headers/Batiment.h"

/**
 * Includes correspondant
 * */
#include "../headers/ModeleBatiment.h"

char* getCheminFichierBatiment(char* nom){
	debug("<initBatiment> begin");
	
	if(nom == NULL || strcmp(nom, "") == 0){
		error("Le nom est invalid");
		debug("<initBatiment> end : nom invalide");
		return NULL;
	}
	
	char* nomFichier;
	nomFichier = malloc(sizeof(char)*(strlen(nom) + strlen("../Jerepolis/ressources/batiments/") + strlen(".csv") + 1)); // Le nom + le chemin + l'extension + \n
	if(nomFichier == NULL){
		error("Erreur de malloc sur le nom du fichier de batiment");
		debug("<initBatiment> end : erreur malloc nom fichier batiment");
		return NULL;
	}
	
	strcpy(nomFichier, "../Jerepolis/ressources/batiments/");
	strcat(nomFichier, nom);
	strcat(nomFichier, ".csv");
	
	debug("<initBatiment> end");
	return nomFichier;
}

void initModeleBatiment(ModeleBatiment** m, char* nom, typeBatiment type){
	debug("<initBatiment> begin");

	char* nomFichier = getCheminFichierBatiment(nom);
	if(nomFichier == NULL || strcmp(nomFichier, "") == 0){
		error("Erreur lors de la génération du nom du fichier de batiment");
		debug("<initBatiment> end : erreur génération nom du fichier de batiment");
	}
	
	FILE* fichier = fopen(nomFichier, "rt");
	if(fichier == NULL){
		error("Erreur lors de l'ouverture du fichier");
		debug("<initBatiment> end : erreur ouverture du fichier");
		return;
	}
	
	char line[1024];
	fgets(line, 1024, fichier);
	
	int niveau = 0;
	int populationMax = 0;
	int prixAmeliorationBois = 0;
	int prixAmeliorationPierre = 0;
	int prixAmeliorationArgent = 0;
	int tempsAmelioration = 0;
	char image[20];
	
	if(type == BATIMENT_PRODUCTION){
		int production = 0;
		while(fscanf(fichier,"%d;%d;%d;%d;%d;%d;%s;%d;", &niveau, &populationMax, &prixAmeliorationBois, &prixAmeliorationPierre, &prixAmeliorationArgent, &tempsAmelioration, image, &production) != EOF){
			ModeleBatiment* lvl;
			initNiveauBatiment(&lvl, nom, type, niveau, populationMax, prixAmeliorationBois, prixAmeliorationPierre, prixAmeliorationArgent, tempsAmelioration, image, production);
			ajouteNiveauBatiment(m, lvl);
		}
		
	}else{
		while(fscanf(fichier,"%d;%d;%d;%d;%d;%d;%s", &niveau, &populationMax, &prixAmeliorationBois, &prixAmeliorationPierre, &prixAmeliorationArgent, &tempsAmelioration, image) != EOF){
			ModeleBatiment* lvl;
			initNiveauBatiment(&lvl, nom, type, niveau, populationMax, prixAmeliorationBois, prixAmeliorationPierre, prixAmeliorationArgent, tempsAmelioration, image, 0);
			ajouteNiveauBatiment(m, lvl);
		}
	}
	
	fclose(fichier);
	
	debug("<initBatiment> end");
}

void initNiveauBatiment(ModeleBatiment** lvl, char* nom, typeBatiment type, int niveau, int populationMax, int prixAmeliorationBois, int prixAmeliorationPierre, int prixAmeliorationArgent, int tempsAmelioration, char image[10], int production){
	debug("<initNiveauBatiment> begin");
	
	if(lvl == NULL){
		error("Le pointeur du niveau à initialiser ne doit pas être à NULL");
		debug("<initNiveauBatiment> end : le pointeur du niveau est à NULL");
	}
	
	if(nom == NULL || strcmp(nom, "") == 0){
		error("Le nom du batiment ne doit pas être à NULL");
		debug("<initNiveauBatiment> end : le nom du batiment est invalide");
	}
	
	*lvl = (ModeleBatiment*)malloc(sizeof(ModeleBatiment));
	if(*lvl == NULL){
		error("Erreur lors du malloc du niveau du batiment");
		debug("<initNiveauBatiment> end : erreur malloc niveau batiment");
		return;
	}
	
	(*lvl)->nom = nom;
	(*lvl)->type = type;
	(*lvl)->niveau = niveau;
	(*lvl)->populationMax = populationMax;
	(*lvl)->prixAmeliorationBois = prixAmeliorationBois;
	(*lvl)->prixAmeliorationPierre = prixAmeliorationPierre;
	(*lvl)->prixAmeliorationArgent = prixAmeliorationArgent;
	(*lvl)->tempsAmelioration = tempsAmelioration;
	(*lvl)->production = production;
	(*lvl)->dernier = 1;
	(*lvl)->suivant = NULL;
	
	char tmp[100];
	strcpy(tmp, "../Jerepolis/ressources/images/batiments/");
	strcat(tmp, (*lvl)->nom);
	strcat(tmp, "/");
	strcat(tmp, image);
	strcat(tmp, ".bmp");
	
	(*lvl)->image = lisBMPRGB(tmp);
	if((*lvl)->image == NULL){
		error("Erreur lors de l'ouverture de l'image du batiment");
	}
	
	debug("<initNiveauBatiment> end");
}

void ajouteNiveauBatiment(ModeleBatiment** m, ModeleBatiment* lvl){
	debug("<ajouteNiveauBatiment> begin");
	
	if(m == NULL){
		error("La tete de liste du modèle de batiment ne dois pas être à NULL");
		debug("<ajouteNiveauBatiment> end : la tete de liste du modèle de batiment est à NULL");
	}
	
	if(lvl == NULL){
		error("Le niveau du batiment à ajouter au modèle ne dois pas être à NULL");
		debug("<ajouteNiveauBatiment> end : le niveau du batiment à ajouter au modèle est à NULL");
	}
	
	if(*m == NULL){
		*m = lvl;
	}else{
		ModeleBatiment* courant = *m;
		while(courant->suivant != NULL){
			courant = courant->suivant;
		}
		courant->dernier = 0;
		courant->suivant = lvl;
	}
	
	debug("<ajouteNiveauBatiment> end");
}

void printNiveauBatiment(ModeleBatiment* lvl){
	debug("<printNiveauBatiment> begin");
	
	if(lvl == NULL){
		error("Le niveau de batiment à afficher ne doit pas être à NULL");
		debug("<printNiveauBatiment> end : le niveau de batiment à afficher est à NULL");
		return;
	}
	
	printf("Nom : %s\n", lvl->nom);
	printf("Type : %s\n", getBatimentTypeName(lvl->type));
	printf("Niveau : %d\n", lvl->niveau);
	printf("PopulationMax : %d\n", lvl->populationMax);
	printf("Prix Amélioration Bois : %d\n", lvl->prixAmeliorationBois);
	printf("Prix Amélioration Pierre : %d\n", lvl->prixAmeliorationPierre);
	printf("Prix Amélioration Argent : %d\n", lvl->prixAmeliorationArgent);
	printf("Temps Amelioration : %d\n", lvl->tempsAmelioration);
	
	if(lvl->type == BATIMENT_PRODUCTION){
		printf("Production : %d\n",lvl->production);
	}
	
	debug("<printNiveauBatiment> end");
}

void printModeleBatiment(ModeleBatiment* m){
	debug("<printModeleBatiment> begin");
	
	if(m == NULL){
		error("Le modèle de batiment à afficher ne doit pas être à NULL");
		debug("<printModeleBatiment> end : le modèle de batiment à afficher est à NULL");
		return;
	}
	
	ModeleBatiment* courant = m;
	
	while(courant != NULL){
		printf("-----\n");
		printNiveauBatiment(courant);
		printf("-----\n");
		courant = courant->suivant;
	}
	
	debug("<printModeleBatiment> end");
}

ModeleBatiment* getModeleNiveauBatiment(ModeleBatiment* m, int niveau){
	debug("<getModeleNiveauBatiment> begin");
	
	if(m == NULL){
		error("Le modèle de batiment ne doit pas être à NULL");
		debug("<getModeleNiveauBatiment> end : le modèle de batiment est à NULL");
		return NULL;
	}
	
	ModeleBatiment* courant = m;
	
	while(courant != NULL && courant->niveau != niveau){
		courant = courant->suivant;
	}
	
	if(courant == NULL){
		error("Le niveau demandé n'existe pas pour ce batiment\n");
		debug("<getModeleNiveauBatiment> end : return NULL");
		return NULL;
	}
	
	debug("<getModeleNiveauBatiment> end");
	return courant;
}
