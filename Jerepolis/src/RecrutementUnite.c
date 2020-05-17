/**
 * Includes Classiques
 * */
#include <stdlib.h>
#include <stdio.h>

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

/**
 * Includes correspondant
 * */
#include "../headers/RecrutementUnite.h"

void initRecrutementUnite(RecrutementUnite** recrutement, int nbUnite, Unite* u){
	
	*recrutement = malloc(sizeof(RecrutementUnite));
	
	(*recrutement)->u = u;
	
	(*recrutement)->nbUnite = nbUnite;
	(*recrutement)->timer = nbUnite*u->temps;
	(*recrutement)->next = NULL;
}

void ajouteRecrutementUnite(RecrutementUnite** fileDeRecrutement, RecrutementUnite* recrutement){
	
	if(*fileDeRecrutement == NULL){
		*fileDeRecrutement = recrutement;
	}else{
		RecrutementUnite* courant = *fileDeRecrutement;
		while(courant->next != NULL){
			courant = courant->next;
		}
		courant->next = recrutement;
	}
	
}

void afficheFileDeRecrutement(RecrutementUnite* fileDeRecrutement){
	
	RecrutementUnite* courant = fileDeRecrutement;
	int cpt = 0;
	int x = 0;
	int y = 0;
	
	while(courant != NULL){
		switch(cpt){
			case 0:
				x = 216;
				y = 269;
				break;
			case 1:
				x = 286;
				y = 269;
				break;
			case 2:
				x = 356;
				y = 269;
				break;
			case 3:
				x = 426;
				y = 269;
				break;
			case 4:
				x = 496;
				y = 269;
				break;
			case 5:
				x = 565;
				y = 269;
				break;
			case 6:
				x = 637;
				y = 269;
				break;
		}
		
		
		if(courant->u->icon != NULL){ ecrisImage(x, y, courant->u->icon->largeurImage, courant->u->icon->hauteurImage, courant->u->icon->donneesRGB);}
		courant = courant->next;
		cpt++;
	}
}

int getTailleFileDeRecrutement(RecrutementUnite* fileDeRecrutement){
	
	if(fileDeRecrutement == NULL){
		return 0;
	}
	
	RecrutementUnite* current = fileDeRecrutement;
	int cpt = 0;
	while(current != NULL){
		cpt++;
		current = current->next;
	}
	
	return cpt;
}

void printRecrutementUnite(RecrutementUnite recrutement){
	
	printf("Unité : %s\n", recrutement.u->nom);
	printf("Nombre : %d\n", recrutement.nbUnite);
	printf("Timer : %d\n", recrutement.timer);
}
