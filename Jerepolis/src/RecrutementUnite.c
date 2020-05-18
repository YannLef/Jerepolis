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
 * Includes CustomGfxComponents
 * */
#include "../../CustomGfxComponents/headers/structures.h"
#include "../../CustomGfxComponents/headers/Couleur.h"

/**
 * Includes correspondant
 * */
#include "../headers/RecrutementUnite.h"

extern CouleurTab c;

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

void afficheFileDeRecrutement(RecrutementUnite* fileDeRecrutement, DonneesImageRGB* annuler){
	
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
		if(annuler != NULL){ ecrisImage(x, y, annuler->largeurImage, annuler->hauteurImage, annuler->donneesRGB);}
		char tmp[100];
		sprintf(tmp, "%d", courant->nbUnite);
		changeColor(c.blanc);
		epaisseurDeTrait(3);
		afficheChaine(tmp, 15, x+30, y+2);
		epaisseurDeTrait(1);
		
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

void gereClicFileDeRecrutement(int x, int y, RecrutementUnite** fileDeRecrutement, Popups popups, float* bois, float* pierre, float* argent, float* faveur){
	if(popups.actuel == POPUP_CASERNE){
		// Clic sur le recrutement 0
		if(x > 216 && x < 216+17 && y > 269 && y < 269+17 && getTailleFileDeRecrutement(*fileDeRecrutement) >= 1){
			annulerRecrutement(0, fileDeRecrutement, bois, pierre, argent, faveur);
		}
		
		// Clic sur le recrutement 1
		if(x > 286 && x < 286+17 && y > 269 && y < 269+17 && getTailleFileDeRecrutement(*fileDeRecrutement) >= 2){
			annulerRecrutement(1, fileDeRecrutement, bois, pierre, argent, faveur);
		}
		
		// Clic sur le recrutement 2
		if(x > 356 && x < 356+17 && y > 269 && y < 269+17 && getTailleFileDeRecrutement(*fileDeRecrutement) >= 3){
			annulerRecrutement(2, fileDeRecrutement, bois, pierre, argent, faveur);
		}
		
		// Clic sur le recrutement 3
		if(x > 426 && x < 426+17 && y > 269 && y < 269+17 && getTailleFileDeRecrutement(*fileDeRecrutement) >= 4){
			annulerRecrutement(3, fileDeRecrutement, bois, pierre, argent, faveur);
		}
		
		// Clic sur le recrutement 4
		if(x > 496 && x < 496+17 && y > 269 && y < 269+17 && getTailleFileDeRecrutement(*fileDeRecrutement) >= 5){
			annulerRecrutement(4, fileDeRecrutement, bois, pierre, argent, faveur);
		}
		
		// Clic sur le recrutement 5
		if(x > 565 && x < 565+17 && y > 269 && y < 269+17 && getTailleFileDeRecrutement(*fileDeRecrutement) >= 6){
			annulerRecrutement(5, fileDeRecrutement, bois, pierre, argent, faveur);
		}
		
		// Clic sur le recrutement 6
		if(x > 637 && x < 637+17 && y > 269 && y < 269+17 && getTailleFileDeRecrutement(*fileDeRecrutement) >= 7){
			annulerRecrutement(6, fileDeRecrutement, bois, pierre, argent, faveur);
		}
	}
}

void annulerRecrutement(int numero, RecrutementUnite** fileDeRecrutement, float* bois, float* pierre, float* argent, float* faveur){
	
	if(fileDeRecrutement == NULL){
		return;
	}
	
	if(numero == 0){
		RecrutementUnite* tmp = *fileDeRecrutement;
		*fileDeRecrutement = tmp->next;
		
		// Remboursement à hauteur de 75%
		*bois += tmp->nbUnite*tmp->u->prixBois*0.75;
		*pierre += tmp->nbUnite*tmp->u->prixPierre*0.75;
		*argent += tmp->nbUnite*tmp->u->prixArgent*0.75;
		
		// Libération mémoire
		free(tmp);
		tmp = NULL;
		
		return;
	}
	
	RecrutementUnite* courant = *fileDeRecrutement;
	RecrutementUnite* precedent = NULL;
	RecrutementUnite* tmp = NULL;
	int cpt = 0;
	
	while(courant != NULL){
		if(cpt == numero-1){
			precedent = courant;
		}
		
		if(cpt == numero){
			tmp = courant;
			precedent->next = tmp->next;
			
			// Remboursement à hauteur de 75%
			*bois += tmp->nbUnite*tmp->u->prixBois*0.75;
			*pierre += tmp->nbUnite*tmp->u->prixPierre*0.75;
			*argent += tmp->nbUnite*tmp->u->prixArgent*0.75;
			
			// Libération mémoire
			free(tmp);
			tmp = NULL;
			
			return;
		}
		
		courant = courant->next;
		cpt++;
	}
}
