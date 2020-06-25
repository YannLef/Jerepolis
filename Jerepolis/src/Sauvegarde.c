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
#include "../headers/Evenement.h"

/**
 * Includes correspondant
 * */
#include "../headers/Sauvegarde.h"

extern int vitesse;

void sauvegarde(InputText* nomVille, float* bois, float* pierre, float* argent, float* faveur, Divinite* divinite, Batiment* senat, Batiment* ferme, Batiment* entrepot, Batiment* caserne,
Batiment* temple, Batiment* scierie, Batiment* carriere, Batiment* mine, ameliorationBatiment** fileDeConstructions, int* nbEpee, int* nbFrondeur, int* nbArcher, int* nbHoplite,
int* nbCavalier, int* nbChar, int* nbCatapulte, EvenementTroupe** listeEvenementTroupe, RecrutementUnite** fileDeRecrutement){
	
	char sauve[200];
	strcpy(sauve, "sauvegardes/");
	strcat(sauve, nomVille->string);
	FILE* fichier = fopen(sauve, "wb");
	
	int tmpInt;
	int tmpInt2;
	
	// Sauvegarde le nom de la ville
	fwrite(&(nomVille->size), 1, sizeof(int), fichier);
	fwrite(nomVille->string, nomVille->size, sizeof(char), fichier);
	
	// Sauvegarde les ressources
	fwrite(bois, 1, sizeof(float), fichier);
	fwrite(pierre, 1, sizeof(float), fichier);
	fwrite(argent, 1, sizeof(float), fichier);
	fwrite(faveur, 1, sizeof(float), fichier);
	
	// Sauvegarde la divinité de la ville
	switch(*divinite){
		case DIVINITE_NONE:
			tmpInt = 0;
			break;
		case DIVINITE_ZEUS:
			tmpInt = 1;
			break;
		case DIVINITE_POSEIDON:
			tmpInt = 2;
			break;
		case DIVINITE_HADES:
			tmpInt = 3;
			break;
	}
	fwrite(&tmpInt, 1, sizeof(int), fichier);
	
	// Sauvegarde la vitesse du jeu
	fwrite(&vitesse, 1, sizeof(int), fichier);
	
	// Sauvegarde les informations du sénat
	fwrite(&(senat->niveau), 1, sizeof(int), fichier);
	fwrite(&(senat->population), 1, sizeof(int), fichier);
	
	// Sauvegarde les informations de la ferme
	fwrite(&(ferme->niveau), 1, sizeof(int), fichier);
	fwrite(&(ferme->population), 1, sizeof(int), fichier);
	
	// Sauvegarde les informations de l'entrepôt
	fwrite(&(entrepot->niveau), 1, sizeof(int), fichier);
	fwrite(&(entrepot->population), 1, sizeof(int), fichier);
	
	// Sauvegarde les informations de la caserne
	fwrite(&(caserne->niveau), 1, sizeof(int), fichier);
	fwrite(&(caserne->population), 1, sizeof(int), fichier);
	
	// Sauvegarde les informations du temple
	fwrite(&(temple->niveau), 1, sizeof(int), fichier);
	fwrite(&(temple->population), 1, sizeof(int), fichier);
	
	// Sauvegarde les informations de la scierie
	fwrite(&(scierie->niveau), 1, sizeof(int), fichier);
	fwrite(&(scierie->population), 1, sizeof(int), fichier);
	
	// Sauvegarde les informations de la carriere
	fwrite(&(carriere->niveau), 1, sizeof(int), fichier);
	fwrite(&(carriere->population), 1, sizeof(int), fichier);
	
	// Sauvegarde les informations de la mine
	fwrite(&(mine->niveau), 1, sizeof(int), fichier);
	fwrite(&(mine->population), 1, sizeof(int), fichier);
	
	// Sauvegarde la file de constructions
	tmpInt = getTailleFileDeConstruction(*fileDeConstructions);
	fwrite(&tmpInt, 1, sizeof(int), fichier);
	ameliorationBatiment* courant = *fileDeConstructions;
	for(int i=0; i<tmpInt; i++){
		fwrite(&(courant->timer), 1, sizeof(int), fichier);
		if(strcmp(courant->batiment->nom,"senat") == 0){
			tmpInt2 = 1;
		}else if(strcmp(courant->batiment->nom,"ferme") == 0){
			tmpInt2 = 2;
		}else if(strcmp(courant->batiment->nom,"entrepot") == 0){
			tmpInt2 = 3;
		}else if(strcmp(courant->batiment->nom,"caserne") == 0){
			tmpInt2 = 4;
		}else if(strcmp(courant->batiment->nom,"temple") == 0){
			tmpInt2 = 5;
		}else if(strcmp(courant->batiment->nom,"scierie") == 0){
			tmpInt2 = 6;
		}else if(strcmp(courant->batiment->nom,"carriere") == 0){
			tmpInt2 = 7;
		}else if(strcmp(courant->batiment->nom,"mine") == 0){
			tmpInt2 = 8;
		}
		fwrite(&tmpInt2, 1, sizeof(int), fichier);
		
		courant = courant->next;
	}
	
	// Sauvegarde la file de recrutement
	RecrutementUnite* courant3 = *fileDeRecrutement;
	tmpInt = 0;
	while(courant3 != NULL){
		tmpInt++;
		courant3 = courant3->next;
	}
	fwrite(&tmpInt, 1, sizeof(int), fichier);
	
	courant3 = *fileDeRecrutement;
	while(courant3 != NULL){
		fwrite(&(courant3->timer), 1, sizeof(int), fichier);
		fwrite(&(courant3->nbUnite), 1, sizeof(int), fichier);
		switch(courant3->u->type){
			case TROUPE_EPEE:
				tmpInt = 0;
				break;
			case TROUPE_FRONDEUR:
				tmpInt = 1;
				break;
			case TROUPE_ARCHER:
				tmpInt = 2;
				break;
			case TROUPE_HOPLITE:
				tmpInt = 3;
				break;
			case TROUPE_CAVALIER:
				tmpInt = 4;
				break;
			case TROUPE_CHAR:
				tmpInt = 5;
				break;
			case TROUPE_CATAPULTE:
				tmpInt = 6;
				break;
		}
		fwrite(&tmpInt, 1, sizeof(int), fichier);
		courant3 = courant3->next;
	}
	
	// Sauvegarde l'armée actuelle
	fwrite(nbEpee, 1, sizeof(int), fichier);
	fwrite(nbFrondeur, 1, sizeof(int), fichier);
	fwrite(nbArcher, 1, sizeof(int), fichier);
	fwrite(nbHoplite, 1, sizeof(int), fichier);
	fwrite(nbCavalier, 1, sizeof(int), fichier);
	fwrite(nbChar, 1, sizeof(int), fichier);
	fwrite(nbCatapulte, 1, sizeof(int), fichier);
	
	// Sauvegarde les evenements de troupe
	EvenementTroupe* courant2 = *listeEvenementTroupe;
	tmpInt = 0;
	while(courant2 != NULL){
		tmpInt++;
		courant2 = courant2->next;
	}
	fwrite(&tmpInt, 1, sizeof(int), fichier);
	
	courant2 = *listeEvenementTroupe;
	while(courant2 != NULL){
		fwrite(&(courant2->victoire), 1, sizeof(int), fichier);
		fwrite(&(courant2->timer), 1, sizeof(int), fichier);
		switch(courant2->type){
			case EVENEMENT_ATTAQUE_SORTANTE :
				tmpInt = 1;
				break;
			case EVENEMENT_RETOUR_TROUPE:
				tmpInt = 2;
				break;
		}
		fwrite(&tmpInt, 1, sizeof(int), fichier);
		fwrite(&(courant2->nbEpee), 1, sizeof(int), fichier);
		fwrite(&(courant2->nbFrondeur), 1, sizeof(int), fichier);
		fwrite(&(courant2->nbArcher), 1, sizeof(int), fichier);
		fwrite(&(courant2->nbHoplite), 1, sizeof(int), fichier);
		fwrite(&(courant2->nbCavalier), 1, sizeof(int), fichier);
		fwrite(&(courant2->nbChar), 1, sizeof(int), fichier);
		fwrite(&(courant2->nbCatapulte), 1, sizeof(int), fichier);
		
		courant2 = courant2->next;
	}
	
	fclose(fichier);
}

void charger(InputText* nomVille, float* bois, float* pierre, float* argent, float* faveur, Divinite* divinite, Batiment* senat, ModeleBatiment* modeleSenat, Batiment* ferme,
ModeleBatiment* modeleFerme, Batiment* entrepot, ModeleBatiment* modeleEntrepot, Batiment* caserne, ModeleBatiment* modeleCaserne, Batiment* temple, ModeleBatiment* modeleTemple,
Batiment* scierie, ModeleBatiment* modeleScierie, Batiment* carriere, ModeleBatiment* modeleCarriere, Batiment* mine, ModeleBatiment* modeleMine, ameliorationBatiment** fileDeConstructions,
int* nbEpee, int* nbFrondeur, int* nbArcher, int* nbHoplite, int* nbCavalier, int* nbChar, int* nbCatapulte, EvenementTroupe** listeEvenementTroupe, Ennemi* ennemi,
RecrutementUnite** fileDeRecrutement, Unite* epee, Unite* frondeur, Unite* archer, Unite* hoplite, Unite* cavalier, Unite* charr, Unite* catapulte, char* sauvegarde){
	
	FILE* fichier = fopen(sauvegarde, "rb");
	
	char tmpString[1000];
	int tmpInt;
	int tmpInt2;
	int tmpInt3;
	
	// Charge le nom de la ville
	fread(&tmpInt, 1, sizeof(int), fichier);
	fread(tmpString, tmpInt, sizeof(char), fichier);
	setString(nomVille, tmpString);
	
	printf("%s\n", sauvegarde);
	
	// Charge les ressources
	fread(bois, 1, sizeof(float), fichier);
	fread(pierre, 1, sizeof(float), fichier);
	fread(argent, 1, sizeof(float), fichier);
	fread(faveur, 1, sizeof(float), fichier);
	
	// Charge la divinité de la ville
	fread(&tmpInt, 1, sizeof(int), fichier);
	switch(tmpInt){
		case 0:
			*divinite = DIVINITE_NONE;
			break;
		case 1:
			*divinite = DIVINITE_ZEUS;
			break;
		case 2:
			*divinite = DIVINITE_POSEIDON;
			break;
		case 3:
			*divinite = DIVINITE_HADES;
			break;
	}
	
	// Charge la vitesse de jeu
	fread(&vitesse, 1, sizeof(int), fichier);
	
	// Charge les informations du sénat
	fread(&tmpInt, 1, sizeof(int), fichier); // niveau sénat
	ModeleBatiment* lvl = modeleSenat;
	for(int i=1; i<tmpInt; i++){
		lvl = lvl->suivant;
	}
	initBatiment(senat, lvl, 610, 370, 605, 720, 380, 445, POPUP_SENAT);
	fread(&(senat->population), 1, sizeof(int), fichier); // population sénat
	
	// Charge les informations de la ferme
	fread(&tmpInt, 1, sizeof(int), fichier); // niveau ferme
	lvl = modeleFerme;
	for(int i=1; i<tmpInt; i++){
		lvl = lvl->suivant;
	}
	initBatiment(ferme, lvl, 706, 400, 730, 830, 400, 460, POPUP_FERME);
	fread(&(ferme->population), 1, sizeof(int), fichier); // population ferme
	
	// Charge les informations de l'entrepot
	fread(&tmpInt, 1, sizeof(int), fichier); // niveau entrepot
	lvl = modeleEntrepot;
	for(int i=1; i<tmpInt; i++){
		lvl = lvl->suivant;
	}
	initBatiment(entrepot, lvl, 577, 326, 580, 660, 330, 370, POPUP_ENTREPOT);
	fread(&(entrepot->population), 1, sizeof(int), fichier); // population ferme
	
	// Charge les informations de la caserne
	fread(&tmpInt, 1, sizeof(int), fichier); // niveau caserne
	lvl = modeleCaserne;
	for(int i=0; i<tmpInt; i++){
		lvl = lvl->suivant;
	}
	initBatiment(caserne, lvl, 480, 378, 483, 580, 382, 437, POPUP_CASERNE);
	fread(&(caserne->population), 1, sizeof(int), fichier); // population caserne
	
	// Charge les informations du temple
	fread(&tmpInt, 1, sizeof(int), fichier); // niveau temple
	lvl = modeleTemple;
	for(int i=0; i<tmpInt; i++){
		lvl = lvl->suivant;
	}
	initBatiment(temple, lvl, 398, 420, 400, 480, 420, 470, POPUP_TEMPLE);
	fread(&(temple->population), 1, sizeof(int), fichier); // population temple
	
	// Charge les informations de la scierie
	fread(&tmpInt, 1, sizeof(int), fichier); // niveau scierie
	lvl = modeleScierie;
	for(int i=0; i<tmpInt; i++){
		lvl = lvl->suivant;
	}
	initBatiment(scierie, lvl, 645, 238, 645, 705, 240, 290, POPUP_SCIERIE);
	fread(&(scierie->population), 1, sizeof(int), fichier); // population scierie
	
	// Charge les informations de la carriere
	fread(&tmpInt, 1, sizeof(int), fichier); // niveau carriere
	lvl = modeleCarriere;
	for(int i=0; i<tmpInt; i++){
		lvl = lvl->suivant;
	}
	initBatiment(carriere, lvl, 414, 314, 425, 535, 320, 370, POPUP_CARRIERE);
	fread(&(carriere->population), 1, sizeof(int), fichier); // population carriere
	
	// Charge les informations de la mine
	fread(&tmpInt, 1, sizeof(int), fichier); // niveau mine
	lvl = modeleMine;
	for(int i=0; i<tmpInt; i++){
		lvl = lvl->suivant;
	}
	initBatiment(mine, lvl, 435, 460, 453, 490, 472, 500, POPUP_MINE);
	fread(&(mine->population), 1, sizeof(int), fichier); // population mine
	
	// Charge la file de constructions
	fread(&tmpInt, 1, sizeof(int), fichier);
	for(int i=0; i<tmpInt; i++){
		fread(&tmpInt2, 1, sizeof(int), fichier); // timer
		fread(&tmpInt3, 1, sizeof(int), fichier); // batiment
		ameliorationBatiment* amelioration;
		float bois = 100000;
		float pierre = 100000;
		float argent = 100000;
		switch(tmpInt3){
			case 1:
				amelioreBatiment(senat, &bois, &pierre, &argent, fileDeConstructions);
				break;
			case 2:
				amelioreBatiment(ferme, &bois, &pierre, &argent, fileDeConstructions);
				break;
			case 3:
				amelioreBatiment(entrepot, &bois, &pierre, &argent, fileDeConstructions);
				break;
			case 4:
				amelioreBatiment(caserne, &bois, &pierre, &argent, fileDeConstructions);
				break;
			case 5:
				amelioreBatiment(temple, &bois, &pierre, &argent, fileDeConstructions);
				break;
			case 6:
				amelioreBatiment(scierie, &bois, &pierre, &argent, fileDeConstructions);
				break;
			case 7:
				amelioreBatiment(carriere, &bois, &pierre, &argent, fileDeConstructions);
				break;
			case 8:
				amelioreBatiment(mine, &bois, &pierre, &argent, fileDeConstructions);
				break;
		}
		ameliorationBatiment* courant = *fileDeConstructions;
		while(courant->next != NULL){
			courant = courant->next;
		}
		courant->timer = tmpInt2;
	}
	
	// Charge la file de recrutement
	
	fread(&tmpInt, 1, sizeof(int), fichier);
	
	for(int i=0; i<tmpInt; i++){
		int timer;
		fread(&timer, 1, sizeof(int), fichier);
		int nbUnite;
		fread(&nbUnite, 1, sizeof(int), fichier);
		Unite* u;
		fread(&tmpInt2, 1, sizeof(int), fichier);
		switch(tmpInt2){
			case 0:
				u = epee;
				break;
			case 1:
				u = frondeur;
				break;
			case 2:
				u = archer;
				break;
			case 3:
				u = hoplite;
				break;
			case 4:
				u = cavalier;
				break;
			case 5:
				u = charr;
				break;
			case 6:
				u = catapulte;
				break;
		}
		
		RecrutementUnite* recrutement;
		initRecrutementUnite(&recrutement, nbUnite, u);
		recrutement->timer = timer;
		ajouteRecrutementUnite(fileDeRecrutement, recrutement);
	}
	
	// Charge l'armée actuelle
	fread(nbEpee, 1, sizeof(int), fichier);
	fread(nbFrondeur, 1, sizeof(int), fichier);
	fread(nbArcher, 1, sizeof(int), fichier);
	fread(nbHoplite, 1, sizeof(int), fichier);
	fread(nbCavalier, 1, sizeof(int), fichier);
	fread(nbChar, 1, sizeof(int), fichier);
	fread(nbCatapulte, 1, sizeof(int), fichier);
	
	// Charge les evenements de troupe
	
	fread(&tmpInt, 1, sizeof(int), fichier);
	
	for(int i=0; i<tmpInt; i++){
		
		int victoire;
		fread(&victoire, 1, sizeof(int), fichier);
		int timer;
		fread(&timer, 1, sizeof(int), fichier);
		TypeEvenement type;
		fread(&tmpInt2, 1, sizeof(int), fichier);
		switch(tmpInt2){
			case 1:
				type = EVENEMENT_ATTAQUE_SORTANTE;
				break;
			case 2:
				type = EVENEMENT_RETOUR_TROUPE;
				break;
		}
		int nbEpeeAtt;
		fread(&nbEpeeAtt, 1, sizeof(int), fichier);
		int nbFrondeurAtt;
		fread(&nbFrondeurAtt, 1, sizeof(int), fichier);
		int nbArcherAtt;
		fread(&nbArcherAtt, 1, sizeof(int), fichier);
		int nbHopliteAtt;
		fread(&nbHopliteAtt, 1, sizeof(int), fichier);
		int nbCavalierAtt;
		fread(&nbCavalierAtt, 1, sizeof(int), fichier);
		int nbCharAtt;
		fread(&nbCharAtt, 1, sizeof(int), fichier);
		int nbCatapulteAtt;
		fread(&nbCatapulteAtt, 1, sizeof(int), fichier);
		
		EvenementTroupe* e;	
		initEvenementTroupe(&e, timer, type, ennemi, nbEpeeAtt, nbFrondeurAtt, nbArcherAtt, nbHopliteAtt, nbCavalierAtt, nbCharAtt, nbCatapulteAtt, victoire);
		insertEvenementTroupe(e, listeEvenementTroupe);	
	}
	
	fclose(fichier);
}
