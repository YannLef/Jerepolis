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
	
	(*fileDeConstructions)->timer = (*fileDeConstructions)->timer - 20;
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

void afficheFileDeConstructions(ameliorationBatiment* fileDeConstructions){
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
		courant = courant->next;
		cpt++;
	}
	
	debug("<afficheFileDeConstructions> end");
}
