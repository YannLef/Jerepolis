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
#include "../../CustomGfxComponents/headers/InputText.h"

/**
 * Includes Jerepolis
 * */
#include "../headers/structures.h"
#include "../headers/AmeliorationBatiment.h"
#include "../headers/RecrutementUnite.h"
#include "../headers/Batiment.h"
#include "../headers/Simplifications.h"
#include "../headers/Sauvegarde.h"

/**
 * Includes correspondant
 * */
#include "../headers/Accueil.h"

extern int vitesse;

void gereClicAccueil(int x, int y, DonneesImageRGB** accueilBackground, DonneesImageRGB** background, DonneesImageRGB** backgroundZeus, DonneesImageRGB** backgroundPoseidon,
DonneesImageRGB** backgroundHades, DonneesImageRGB** ameliorer, DonneesImageRGB** construire, DonneesImageRGB** impossible, DonneesImageRGB** maximum, DonneesImageRGB** infosBatiment,
DonneesImageRGB** annuler, Pages* p, ModeleBatiment* modeleSenat, Batiment* senat, ModeleBatiment* modeleFerme, Batiment* ferme, ModeleBatiment* modeleCarriere, Batiment* carriere,
ModeleBatiment* modeleScierie, Batiment* scierie, ModeleBatiment* modeleMine, Batiment* mine, ModeleBatiment* modeleEntrepot, Batiment* entrepot, ModeleBatiment* modeleTemple,
Batiment* temple, ModeleBatiment* modeleCaserne, Batiment* caserne, float* bois, float* pierre, float* argent, float* faveur, int* nbEpee, int* nbFrondeur, int* nbArcher,
int* nbHoplite, int* nbCavalier, int* nbChar, int* nbCatapulte, ameliorationBatiment** fileDeConstructions, RecrutementUnite** fileDeRecrutement, Divinite* divinite, Popups* popups,
Divinite* divinite_selec, Troupe* troupe, int* nb_troupe, InputText* nomVille, EvenementTroupe** listeEvenementTroupe, Ennemi* ennemi){
	
	// Gère clic sur le bouton Nouvelle Partie
	if(x > 333 && x < 812 && y > 434 && y < 548){
		if(p->pActuel == p->pFinal){
			p->pFinal = partie;
			popups->actuel = POPUP_NONE;
			popups->final = POPUP_NONE;
			*divinite_selec = DIVINITE_NONE;
			*troupe = TROUPE_EPEE;
			*nb_troupe = 0;
			vitesse = 1;
			setString(nomVille, "Nom de la ville");
			
			// On remet à 0 les batiments
			resetBatiments(modeleSenat, senat, modeleFerme, ferme, modeleCarriere, carriere, modeleScierie, scierie, modeleMine, mine, modeleEntrepot, entrepot, modeleTemple, temple, modeleCaserne,
			caserne);
			
			// On remet à 0 les ressources
			*bois = 200;
			*pierre = 200;
			*argent = 200;
			*faveur = 0;
			
			// On remet à 0 la divinité
			*divinite = DIVINITE_NONE;
			
			// On remet à 0 les unités
			*nbEpee = 0;
			*nbFrondeur = 0;
			*nbArcher = 0;
			*nbHoplite = 0;
			*nbCavalier = 0;
			*nbChar = 0;
			*nbCatapulte = 0;
			
			// On remet à 0 la file de constructions
			resetFileDeConstructions(fileDeConstructions);
			
			// On remet à 0 la file de recrutement
			resetFileDeRecrutement(fileDeRecrutement);
		}
	}
	
	// Gère clic sur le bouton charger
	if(x > 333 && x < 812 && y > 300 && y < 412){
		if(p->pActuel == p->pFinal){
			
			p->pFinal = partie;
			popups->actuel = POPUP_NONE;
			popups->final = POPUP_NONE;
			*divinite_selec = DIVINITE_NONE;
			*troupe = TROUPE_EPEE;
			*nb_troupe = 0;
			
			// On remet à 0 la file de constructions
			resetFileDeConstructions(fileDeConstructions);
			
			// On remet à 0 la file de recrutement
			resetFileDeRecrutement(fileDeRecrutement);
			
			// On charge la sauvegarde
			charger(nomVille, bois, pierre, argent, faveur, divinite, senat, modeleSenat, ferme, modeleFerme, entrepot, modeleEntrepot, caserne, modeleCaserne, temple, modeleTemple,
			scierie, modeleScierie, carriere, modeleCarriere, mine, modeleMine, fileDeConstructions, nbEpee, nbFrondeur, nbArcher, nbHoplite, nbCavalier, nbChar, nbCatapulte,
			listeEvenementTroupe, ennemi);
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
