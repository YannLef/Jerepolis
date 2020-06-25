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
#include "../headers/Sauvegarde.h"

/**
 * Includes correspondant
 * */
#include "../headers/Simplifications.h"

extern int vitesse;
extern CouleurTab c;

void chargeImages(DonneesImageRGB** accueilBackground, DonneesImageRGB** background, DonneesImageRGB** backgroundZeus, DonneesImageRGB** backgroundPoseidon, DonneesImageRGB** backgroundHades,
DonneesImageRGB** ameliorer, DonneesImageRGB** construire, DonneesImageRGB** impossible, DonneesImageRGB** maximum, DonneesImageRGB** infosBatiment, DonneesImageRGB** annuler,
DonneesImageRGB** attaquer, DonneesImageRGB** attaqueSortante, DonneesImageRGB** retourTroupe){
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
	*attaquer = lisBMPRGB("../Jerepolis/ressources/images/attaque.bmp");
	*attaqueSortante = lisBMPRGB("../Jerepolis/ressources/images/attaqueSortante.bmp");
	*retourTroupe = lisBMPRGB("../Jerepolis/ressources/images/retourTroupe.bmp");
}

void initPopups(Popups* popups){
	popups->actuel = POPUP_NONE;
	popups->final = POPUP_NONE;
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
	
	if(x > 957 && x < 980 && y > 645 && y < 670){
		vitesse = 0;
		printf("La vitesse a été définie sur x0\n");
	}
}

void gereClicSauvegarder(int x, int y, Pages* p, InputText* nomVille, float* bois, float* pierre, float* argent, float* faveur, Divinite* divinite, Batiment* senat, Batiment* ferme, Batiment* entrepot,
Batiment* caserne, Batiment* temple, Batiment* scierie, Batiment* carriere, Batiment* mine, ameliorationBatiment** fileDeConstructions, int* nbEpee, int* nbFrondeur, int* nbArcher, int* nbHoplite,
int* nbCavalier, int* nbChar, int* nbCatapulte, EvenementTroupe** listeEvenementTroupe, RecrutementUnite** fileDeRecrutement){
	if(x > 1022 && x < 1045 && y > 646 && y < 667){
		if(p->pActuel == p->pFinal){
			sauvegarde(nomVille, bois, pierre, argent, faveur, divinite, senat, ferme, entrepot, caserne, temple, scierie, carriere, mine, fileDeConstructions, nbEpee, nbFrondeur, nbArcher,
			nbHoplite, nbCavalier, nbChar, nbCatapulte, listeEvenementTroupe, fileDeRecrutement);
		}
	}
}

void gereClicQuitter(int x, int y, Pages* p){
	if(x > 989 && x < 1012 && y > 646 && y < 667){
		if(p->pActuel == p->pFinal){
			p->pFinal = accueil;
		}
	}
}

void afficheArmee(int nbEpee, int nbFrondeur, int nbArcher, int nbHoplite, int nbCavalier, int nbChar, int nbCatapulte){
char txt[100];
	epaisseurDeTrait(3);
	
	// Eppee
	sprintf(txt,"%d", nbEpee);
	afficheChaine(txt, 15, 1010, 560);
	
	// Frondeur
	sprintf(txt,"%d", nbFrondeur);
	afficheChaine(txt, 15, 1062, 560);
	
	// Archer
	sprintf(txt,"%d", nbArcher);
	afficheChaine(txt, 15, 1110, 560);
	
	// Hoplite
	sprintf(txt,"%d", nbHoplite);
	afficheChaine(txt, 15, 1010, 510);
	
	// Cavalier
	sprintf(txt,"%d", nbCavalier);
	afficheChaine(txt, 15, 1062, 510);
	
	// Char
	sprintf(txt,"%d", nbChar);
	afficheChaine(txt, 15, 1110, 510);
	
	// Catapulte
	sprintf(txt,"%d", nbCatapulte);
	afficheChaine(txt, 15, 1010, 460);
	
	epaisseurDeTrait(1);
}

void afficheRessources(float faveur, float bois, float pierre, float argent, int capacitePopulationRestante){
	changeColor(c.blanc);
	char txt[100];
	
	sprintf(txt,"%.0f", faveur);
	afficheChaine(txt, 20, 94, 520);
	
	sprintf(txt,"%.0f", bois);
	afficheChaine(txt, 20, 70, 460);
	
	sprintf(txt,"%.0f", pierre);
	afficheChaine(txt, 20, 70, 403);
	
	sprintf(txt,"%.0f", argent);
	afficheChaine(txt, 20, 70, 345);
	
	sprintf(txt,"%d", capacitePopulationRestante);
	afficheChaine(txt, 20, 70, 287);
}
