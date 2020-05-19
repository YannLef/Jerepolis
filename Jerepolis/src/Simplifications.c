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
#include "../../CustomGfxComponents/headers/Image.h"

/**
 * Includes Jerepolis
 * */
#include "../headers/structures.h"
#include "../headers/Batiment.h"
#include "../headers/ModeleBatiment.h"

/**
 * Includes correspondant
 * */
#include "../headers/Simplifications.h"

extern int vitesse;

void chargeImages(DonneesImageRGB** accueilBackground, DonneesImageRGB** background, DonneesImageRGB** backgroundZeus, DonneesImageRGB** backgroundPoseidon, DonneesImageRGB** backgroundHades, DonneesImageRGB** ameliorer,
DonneesImageRGB** construire, DonneesImageRGB** impossible, DonneesImageRGB** maximum, DonneesImageRGB** infosBatiment, DonneesImageRGB** annuler){
	*accueilBackground = lisBMPRGB("../Jerepolis/ressources/images/accueil.bmp");
	*background = lisBMPRGB("../Jerepolis/ressources/images/background.bmp");
	*backgroundZeus = lisBMPRGB("../Jerepolis/ressources/images/backgroundZeus.bmp");
	*backgroundPoseidon = lisBMPRGB("../Jerepolis/ressources/images/backgroundPoseidon.bmp");
	*backgroundHades = lisBMPRGB("../Jerepolis/ressources/images/backgroundHades.bmp");
	*ameliorer = lisBMPRGB("../Jerepolis/ressources/images/boutons/ameliorer.bmp");
	*construire = lisBMPRGB("../Jerepolis/ressources/images/boutons/construire.bmp");
	*impossible = lisBMPRGB("../Jerepolis/ressources/images/boutons/impossible.bmp");
	*maximum = lisBMPRGB("../Jerepolis/ressources/images/boutons/maximum.bmp");
	*infosBatiment = lisBMPRGB("../Jerepolis/ressources/images/batiments/infos.bmp");
	*annuler = lisBMPRGB("../Jerepolis/ressources/images/boutons/annuler.bmp");
}

void initPopups(Popups* popups){
	popups->actuel = POPUP_NONE;
	popups->final = POPUP_NONE;
}

void initBatiments(ModeleBatiment** modeleSenat, Batiment* senat, ModeleBatiment** modeleFerme, Batiment* ferme, ModeleBatiment** modeleCarriere, Batiment* carriere, ModeleBatiment** modeleScierie,
Batiment* scierie, ModeleBatiment** modeleMine, Batiment* mine, ModeleBatiment** modeleEntrepot, Batiment* entrepot, ModeleBatiment** modeleTemple, Batiment* temple, ModeleBatiment** modeleCaserne,
Batiment* caserne){
	*modeleSenat = NULL;
	initModeleBatiment(modeleSenat, "senat", BATIMENT_NORMAL);
	initBatiment(senat, *modeleSenat, 610, 370, 605, 720, 380, 445, POPUP_SENAT);
	
	*modeleFerme = NULL;
	initModeleBatiment(modeleFerme, "ferme", BATIMENT_NORMAL);
	initBatiment(ferme, *modeleFerme, 706, 400, 730, 830, 400, 460, POPUP_FERME);
	
	*modeleCarriere = NULL;
	initModeleBatiment(modeleCarriere, "carriere", BATIMENT_PRODUCTION);
	initBatiment(carriere, *modeleCarriere, 414, 314, 425, 535, 320, 370, POPUP_CARRIERE);
	
	*modeleScierie = NULL;
	initModeleBatiment(modeleScierie, "scierie", BATIMENT_PRODUCTION);
	initBatiment(scierie, *modeleScierie, 645, 238, 645, 705, 240, 290, POPUP_SCIERIE);
	
	*modeleMine = NULL;
	initModeleBatiment(modeleMine, "mine", BATIMENT_PRODUCTION);
	initBatiment(mine, *modeleMine, 435, 460, 453, 490, 472, 500, POPUP_MINE);
	
	*modeleEntrepot = NULL;
	initModeleBatiment(modeleEntrepot, "entrepot", BATIMENT_NORMAL);
	initBatiment(entrepot, *modeleEntrepot, 577, 326, 580, 660, 330, 370, POPUP_ENTREPOT);
	
	*modeleTemple = NULL;
	initModeleBatiment(modeleTemple, "temple", BATIMENT_PRODUCTION);
	initBatiment(temple, *modeleTemple, 398, 420, 400, 480, 420, 470, POPUP_TEMPLE);
	
	*modeleCaserne = NULL;
	initModeleBatiment(modeleCaserne, "caserne", BATIMENT_NORMAL);
	initBatiment(caserne, *modeleCaserne, 480, 378, 483, 580, 382, 437, POPUP_CASERNE);
}

void resetBatiments(ModeleBatiment* modeleSenat, Batiment* senat, ModeleBatiment* modeleFerme, Batiment* ferme, ModeleBatiment* modeleCarriere, Batiment* carriere, ModeleBatiment* modeleScierie,
Batiment* scierie, ModeleBatiment* modeleMine, Batiment* mine, ModeleBatiment* modeleEntrepot, Batiment* entrepot, ModeleBatiment* modeleTemple, Batiment* temple, ModeleBatiment* modeleCaserne,
Batiment* caserne){
	initBatiment(senat, modeleSenat, 610, 370, 605, 720, 380, 445, POPUP_SENAT);
	
	initBatiment(ferme, modeleFerme, 706, 400, 730, 830, 400, 460, POPUP_FERME);
	
	initBatiment(carriere, modeleCarriere, 414, 314, 425, 535, 320, 370, POPUP_CARRIERE);
	
	initBatiment(scierie, modeleScierie, 645, 238, 645, 705, 240, 290, POPUP_SCIERIE);
	
	initBatiment(mine, modeleMine, 435, 460, 453, 490, 472, 500, POPUP_MINE);
	
	initBatiment(entrepot, modeleEntrepot, 577, 326, 580, 660, 330, 370, POPUP_ENTREPOT);
	
	initBatiment(temple, modeleTemple, 398, 420, 400, 480, 420, 470, POPUP_TEMPLE);
	
	initBatiment(caserne, modeleCaserne, 480, 378, 483, 580, 382, 437, POPUP_CASERNE);
}

void afficheBatiments(Batiment senat, Batiment ferme, Batiment carriere, Batiment scierie, Batiment mine, Batiment entrepot, Batiment temple, Batiment caserne){
	afficheBatiment(senat);
	afficheBatiment(ferme);
	afficheBatiment(carriere);
	afficheBatiment(scierie);
	afficheBatiment(mine);
	afficheBatiment(entrepot);
	afficheBatiment(temple);
	afficheBatiment(caserne);
}

void afficheBackground(Divinite divinite, DonneesImageRGB* background, DonneesImageRGB* backgroundZeus, DonneesImageRGB* backgroundPoseidon, DonneesImageRGB* backgroundHades){
	switch(divinite){
		case DIVINITE_NONE:
			if(background != NULL){ ecrisImage(0, 0, background->largeurImage, background->hauteurImage, background->donneesRGB);}
			break;
		case DIVINITE_ZEUS:
			if(backgroundZeus != NULL){ ecrisImage(0, 0, backgroundZeus->largeurImage, backgroundZeus->hauteurImage, backgroundZeus->donneesRGB);}
			break;
		case DIVINITE_POSEIDON:
			if(backgroundPoseidon != NULL){ ecrisImage(0, 0, backgroundPoseidon->largeurImage, backgroundPoseidon->hauteurImage, backgroundPoseidon->donneesRGB);}
			break;
		case DIVINITE_HADES:
			if(backgroundHades != NULL){ ecrisImage(0, 0, backgroundHades->largeurImage, backgroundHades->hauteurImage, backgroundHades->donneesRGB);}
			break;
	}	
}

void gereClicVitesse(int x, int y){
	
	if(x > 1055 && x < 1080 && y > 645 && y < 670){
		vitesse = 1;
		printf("La vitesse a été définie sur x1\n");
	}
	
	if(x > 1086 && x < 1111 && y > 645 && y < 670){
		vitesse = 2;
		printf("La vitesse a été définie sur x2\n");
	}
	
	if(x > 1115 && x < 1142 && y > 645 && y < 670){
		vitesse = 3;
		printf("La vitesse a été définie sur x3\n");
	}
}

void gereClicQuitter(int x, int y, Pages* p){
	if(x > 989 && x < 1012 && y > 646 && y < 667){
		if(p->pActuel == p->pFinal){
			p->pFinal = accueil;
		}
	}
}

