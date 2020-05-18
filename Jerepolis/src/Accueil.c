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

/**
 * Includes Jerepolis
 * */
#include "../headers/structures.h"

/**
 * Includes correspondant
 * */
#include "../headers/Accueil.h"

void gereClicAccueil(int x, int y, DonneesImageRGB** accueilBackground, DonneesImageRGB** background, DonneesImageRGB** backgroundZeus, DonneesImageRGB** backgroundPoseidon, DonneesImageRGB** backgroundHades, DonneesImageRGB** ameliorer,
DonneesImageRGB** construire, DonneesImageRGB** impossible, DonneesImageRGB** maximum, DonneesImageRGB** infosBatiment, DonneesImageRGB** annuler, Pages* p){
	
	// Gère clic sur le bouton Nouvelle Partie
	if(x > 333 && x < 812 && y > 434 && y < 548){
		if(p->pActuel == p->pFinal){
			p->pFinal = partie;
		}
	}
	
	// Gère clic sur le bouton Quitter
	if(x > 333 && x < 812 && y > 165 && y < 278){
		quitteProgramme(accueilBackground, background, backgroundZeus, backgroundPoseidon, backgroundHades, ameliorer, construire, impossible, maximum, infosBatiment, annuler);
	}
}

void freeImage(DonneesImageRGB** img){
	if(img != NULL){
		if(*img != NULL){
			libereDonneesImageRGB(img);
			*img = NULL;
		}
	}
}

void quitteProgramme(DonneesImageRGB** accueilBackground, DonneesImageRGB** background, DonneesImageRGB** backgroundZeus, DonneesImageRGB** backgroundPoseidon, DonneesImageRGB** backgroundHades, DonneesImageRGB** ameliorer,
DonneesImageRGB** construire, DonneesImageRGB** impossible, DonneesImageRGB** maximum, DonneesImageRGB** infosBatiment, DonneesImageRGB** annuler){

	// Libère la mémoire des images
	freeImage(accueilBackground);
	freeImage(background);
	freeImage(backgroundZeus);
	freeImage(backgroundPoseidon);
	freeImage(backgroundHades);
	freeImage(ameliorer);
	freeImage(construire);
	freeImage(impossible);
	freeImage(maximum);
	freeImage(infosBatiment);
	freeImage(annuler);
	
	// Termine le programme
	termineBoucleEvenements();
}
