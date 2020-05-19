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

/**
 * Includes correspondant
 * */
#include "../headers/AmeliorationBatiment.h"

extern int vitesse;

void initAmeliorationBatiment(ameliorationBatiment** amelioration, Batiment* batiment){
	debug("<initAmeliorationBatiment> begin");
	
	if(amelioration == NULL){
		error("Le pointeur ameliration ne doit pas être à NULL");
		debug("<initAmeliorationBatiment> end : le pointeur amelioration est à NULL");
		return;
	}
	
	if(batiment == NULL){
		error("Le pointeur batiment ne doit pas être à NULL");
		debug("<initAmeliorationBatiment> end : le pointeur batiment est à NULL");
		return;
	}
	
	*amelioration = malloc(sizeof(ameliorationBatiment));
	if(*amelioration == NULL){
		error("Echec du malloc de l'amélioration");
		debug("<initAmeliorationBatiment> end : erreur malloc amelioration");
		return;
	}
	
	(*amelioration)->batiment = batiment;
	(*amelioration)->timer = batiment->tempsAmelioration;
	(*amelioration)->niveauPrecedent = batiment->niveau + batiment->nbAmeliorationsEnCours;
	(*amelioration)->niveauSuivant = batiment->niveau + batiment->nbAmeliorationsEnCours + 1;
	(*amelioration)->next = NULL;
	
	debug("<initAmeliorationBatiment> end");
}

int getTailleFileDeConstruction(ameliorationBatiment* fileDeConstructions){
	debug("<getTailleFileDeConstruction> begin");
	
	if(fileDeConstructions == NULL){
		debug("<getTailleFileDeConstruction> end : pointeur de file de constructions vide = pas de constructions en cours");
		return 0;
	}
	
	ameliorationBatiment* current = fileDeConstructions;
	int cpt = 0;
	while(current != NULL){
		cpt++;
		current = current->next;
	}
	
	debug("<getTailleFileDeConstruction> end");
	return cpt;
}

void ajouteAmeliorationBatiment(ameliorationBatiment** fileDeConstructions, ameliorationBatiment* amelioration){
	debug("<ajouteAmeliorationBatiment> begin");
	
	if(fileDeConstructions == NULL){
		error("Le pointeur de la file de constructions ne doit pas être à NULL");
		debug("<ajouteAmeliorationBatiment> end : le pointeur de la file de constructions est à NULL");
		return;
	}
	
	if(amelioration == NULL){
		error("Le pointeur de l'amélioration ne doit pas être à NULL");
		debug("<ajouteAmeliorationBatiment> end : le pointeur de l'amélioration est à NULL");
		return;
	}
	
	if(*fileDeConstructions == NULL){
		*fileDeConstructions = amelioration;
	}else{
		ameliorationBatiment* courant = *fileDeConstructions;
		while(courant->next != NULL){
			courant = courant->next;
		}
		courant->next = amelioration;
	}
	
	debug("<ajouteAmeliorationBatiment> end");
}

void gereFileDeConstructions(ameliorationBatiment** fileDeConstructions){
	debug("<gereFileDeConstructions> begin");
	
	if(fileDeConstructions == NULL){
		error("Le pointeur de file de constructions ne doit pas être à NULL");
		debug("<gereFileDeConstructions> end : le pointeur de file de constructions est à NULL");
		return;
	}
	
	if(*fileDeConstructions == NULL){
		debug("<gereFileDeConstructions> end");
		return;
	}
	
	(*fileDeConstructions)->timer = (*fileDeConstructions)->timer - 20*vitesse;
	if((*fileDeConstructions)->timer <= 0){
		(*fileDeConstructions)->batiment->nbAmeliorationsEnCours--;
		(*fileDeConstructions)->batiment->niveau = (*fileDeConstructions)->niveauSuivant;
		(*fileDeConstructions)->batiment->image = getModeleNiveauBatiment((*fileDeConstructions)->batiment->modele,(*fileDeConstructions)->niveauSuivant)->image;
		
		ameliorationBatiment* tmp = *fileDeConstructions;
		printf("L'amélioration du batiment %s est terminée\n", tmp->batiment->nom);
		*fileDeConstructions = (*fileDeConstructions)->next;
		free(tmp);
		tmp = NULL;
	}
	
	debug("<gereFileDeConstructions> end");
}

void printAmeliorationBatiment(ameliorationBatiment* amelioration){
	debug("<printAmeliorationBatiment> begin");
	
	printf("Batiment amélioré : %s\n", amelioration->batiment->nom);
	printf("Niveau précédent : %d\n", amelioration->niveauPrecedent);
	printf("Niveau suivant : %d\n", amelioration->niveauSuivant);
	printf("Timer : %d\n", amelioration->timer);
	
	debug("<printAmeliorationBatiment> end");
}

void printFileDeConstructions(ameliorationBatiment* fileDeConstructions){
	debug("<printFileDeConstructions> begin");
	
	printf("\nFile de construction :\n");
	
	if(fileDeConstructions == NULL){
		printf("La file de constructions est vide\n");
		return;
	}
	
	ameliorationBatiment* courant = fileDeConstructions;
	
	while(courant != NULL){
		printf("-----\n");
		printAmeliorationBatiment(courant);
		printf("-----\n");
		courant = courant->next;
	}
	
	debug("<printFileDeConstructions> end");
}

void afficheFileDeConstructions(ameliorationBatiment* fileDeConstructions, DonneesImageRGB* annuler){
	debug("<afficheFileDeConstructions> begin");
	
	ameliorationBatiment* courant = fileDeConstructions;
	int cpt = 0;
	int x = 0;
	int y = 0;
	
	while(courant != NULL){
		switch(cpt){
			case 0:
				x = 435;
				y = 27;
				break;
			case 1:
				x = 535;
				y = 27;
				break;
			case 2:
				x = 635;
				y = 27;
				break;
			case 3:
				x = 735;
				y = 27;
				break;
		}
		
		
		if(courant->batiment->icon != NULL){ ecrisImage(x, y, courant->batiment->icon->largeurImage, courant->batiment->icon->hauteurImage, courant->batiment->icon->donneesRGB);}
		if(annuler != NULL){ ecrisImage(x, y, annuler->largeurImage, annuler->hauteurImage, annuler->donneesRGB);}
		courant = courant->next;
		cpt++;
	}
	
	debug("<afficheFileDeConstructions> end");
}

void gereClicFileDeConstruction(int x, int y, ameliorationBatiment** fileDeConstructions, float* bois, float* pierre, float* argent){
	
	// Clic sur la construction 0
	if(x > 435 && x < 435+17 && y > 27 && y < 27+17 && getTailleFileDeConstruction(*fileDeConstructions) >= 1){
		annulerConstruction(0, fileDeConstructions, bois, pierre, argent);
	}
	
	// Clic sur la construction 1
	if(x > 535 && x < 535+17 && y > 27 && y < 27+17 && getTailleFileDeConstruction(*fileDeConstructions) >= 2){
		annulerConstruction(1, fileDeConstructions, bois, pierre, argent);
	}
	
	// Clic sur la construction 2
	if(x > 635 && x < 635+17 && y > 27 && y < 27+17 && getTailleFileDeConstruction(*fileDeConstructions) >= 3){
		annulerConstruction(2, fileDeConstructions, bois, pierre, argent);
	}
	
	// Clic sur la construction 3
	if(x > 735 && x < 735+17 && y > 27 && y < 27+17 && getTailleFileDeConstruction(*fileDeConstructions) >= 4){
		annulerConstruction(3, fileDeConstructions, bois, pierre, argent);
	}
}

void annulerConstruction(int numero, ameliorationBatiment** fileDeConstructions, float* bois, float* pierre, float* argent){
	
	if(fileDeConstructions == NULL){
		return;
	}
	
	if(numero == 0){
		ameliorationBatiment* tmp = *fileDeConstructions;
		
		// Vérifie qu'il n'y a pas d'autres améliorations du même batiment plus loins dans la file de constructions
		if(ameliorationsBatimentSuiteFile(tmp)){
			printf("Annulation imposible car le batiment a d'autre améliorations en cours\n");
			return;
		}
		
		
		*fileDeConstructions = tmp->next;
		
		// Remboursement à hauteur de 75%
		ModeleBatiment* lvl = getModeleNiveauBatiment(tmp->batiment->modele, tmp->niveauPrecedent);
		*bois += (lvl->prixAmeliorationBois)*0.75;
		*pierre += (lvl->prixAmeliorationPierre)*0.75;
		*argent += (lvl->prixAmeliorationArgent)*0.75;
		
		// Libération mémoire
		free(tmp);
		tmp = NULL;
		
		return;
	}
	
	ameliorationBatiment* courant = *fileDeConstructions;
	ameliorationBatiment* precedent = NULL;
	ameliorationBatiment* tmp = NULL;
	int cpt = 0;
	
	while(courant != NULL){
		if(cpt == numero-1){
			precedent = courant;
		}
		
		if(cpt == numero){
			tmp = courant;
			// Vérifie qu'il n'y a pas d'autres améliorations du même batiment plus loins dans la file de constructions
			if(ameliorationsBatimentSuiteFile(tmp)){
				printf("Annulation imposible car le batiment a d'autre améliorations en cours\n");
				return;
			}
			
			precedent->next = tmp->next;
			
			// Remboursement à hauteur de 75%
			ModeleBatiment* lvl = getModeleNiveauBatiment(tmp->batiment->modele, tmp->niveauPrecedent);
			*bois += (lvl->prixAmeliorationBois)*0.75;
			*pierre += (lvl->prixAmeliorationPierre)*0.75;
			*argent += (lvl->prixAmeliorationArgent)*0.75;
			
			// Libération mémoire
			free(tmp);
			tmp = NULL;
			
			return;
		}
		
		courant = courant->next;
		cpt++;
	}
}

int ameliorationsBatimentSuiteFile(ameliorationBatiment* amelioration){
	ameliorationBatiment* tmp = amelioration;
	
	if(tmp == NULL){
		return 0;
	}
	
	tmp = tmp->next;
	
	while(tmp != NULL){
		if(tmp->batiment->type == amelioration->batiment->type){
			return 1;
		}
		
		tmp = tmp->next;
	}
	
	return 0;
}

void resetFileDeConstructions(ameliorationBatiment** fileDeConstructions){
	if(fileDeConstructions == NULL){
		error("Le pointeur de file de constructions ne doit pas être à NULL");
		debug("<resetFileDeConstructions> end : le pointeur de file de constructions est à NULL");
		return;
	}
	
	if(*fileDeConstructions == NULL){
		debug("<resetFileDeConstructions> end");
		return;
	}
	
	ameliorationBatiment* courant = *fileDeConstructions;
	ameliorationBatiment* tmp;
	while(courant != NULL){
		tmp = courant->next;
		free(courant);
		courant = tmp;
	}
	
	*fileDeConstructions = NULL;
}
