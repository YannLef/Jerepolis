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
 * Includes CustomGfxComponents
 * */
#include "../../CustomGfxComponents/headers/structures.h"
#include "../../CustomGfxComponents/headers/Couleur.h"

/**
 * Includes Jerepolis
 * */
#include "../headers/structures.h"

/**
 * Includes correspondant
 * */
#include "../headers/Ennemi.h"

extern int vitesse;

void initEnnemi(Ennemi* e, char* nom, unsigned long distance){
	e->nom = nom;
	e->distance = distance;
	e->nbEpee = 0;
	e->nbFrondeur = 0;
	e->nbArcher = 0;
	e->nbHoplite = 0;
	e->nbCavalier = 0;
	e->nbChar = 0;
	e->nbCatapulte = 0;
}

void gereArmeeEnnemi(Ennemi* e, Unite epee, Unite frondeur, Unite archer, Unite hoplite, Unite cavalier, Unite charr, Unite catapulte, Batiment ferme){
	int populationOccupee = e->nbEpee*epee.population + e->nbFrondeur*frondeur.population + e->nbArcher*archer.population + e->nbHoplite*hoplite.population + e->nbCavalier*cavalier.population +
	e->nbChar*charr.population + e->nbCatapulte*catapulte.population;
	
	if( populationOccupee + epee.population < ferme.population * 10){
		e->nbEpee = e->nbEpee + randTroupe(2);
	}
	
	if( populationOccupee + frondeur.population < ferme.population * 10){
		e->nbFrondeur = e->nbFrondeur + randTroupe(1);
	}
	
	if( populationOccupee + archer.population < ferme.population * 10){
		e->nbArcher = e->nbArcher + randTroupe(1);
	}
	
	if( populationOccupee + hoplite.population < ferme.population * 10){
		e->nbHoplite = e->nbHoplite + randTroupe(1);
	}
	
	if( populationOccupee + cavalier.population < ferme.population * 10){
		e->nbCavalier = e->nbCavalier + randTroupe(1);
	}
	
	if( populationOccupee + charr.population < ferme.population * 10){
		e->nbChar = e->nbChar + randTroupe(1);
	}
	
	if( populationOccupee + catapulte.population < ferme.population * 10){
		e->nbCatapulte = e->nbCatapulte + randTroupe(1);
	}		
}

int randTroupe(float chanceSurMille){
	int r = rand()%1000;
	
	if(r < chanceSurMille*vitesse){
		return 1;
	}
	
	return 0;
}

void printArmeeEnnemi(Ennemi e){
	printf("Armée :\n");
	printf("nbEpee : %d\n", e.nbEpee);
	printf("nbFrondeur : %d\n", e.nbFrondeur);
	printf("nbArcher : %d\n", e.nbArcher);
	printf("nbHoplite : %d\n", e.nbHoplite);
	printf("nbCavalier : %d\n", e.nbCavalier);
	printf("nbChar : %d\n", e.nbChar);
	printf("nbCatapulte : %d\n", e.nbCatapulte);
	
	printf("\n");
}
