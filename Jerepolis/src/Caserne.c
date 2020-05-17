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
#include "../../CustomGfxComponents/headers/Couleur.h"
#include "../../CustomGfxComponents/headers/Image.h"

/**
 * Includes Jerepolis
 * */
#include "../headers/structures.h"
#include "../headers/Batiment.h"

/**
 * Includes correspondant
 * */
#include "../headers/Caserne.h"

extern CouleurTab c;

void initUnite(Unite* u, int prixBois, int prixPierre, int prixArgent, int prixFaveur, int population, int temps, int attaque, int vitesse, int capacite){
	u->prixBois = prixBois;
	u->prixPierre = prixPierre;
	u->prixArgent = prixArgent;
	u->prixFaveur = prixFaveur;
	u->population = population;
	u->temps = temps;
	u->attaque = attaque;
	u->vitesse = vitesse;
	u->capacite = capacite;
}

void initUnites(Unite* epee, Unite* frondeur, Unite* archer, Unite* hoplite, Unite* cavalier, Unite* charr, Unite* catapulte){
	initUnite(epee, 95, 0, 85, 0, 1, 270000, 5, 48, 16);
	initUnite(frondeur, 55, 100, 40, 0, 1, 300000, 23, 84, 8);
	initUnite(archer, 120, 0, 75, 0, 1, 285000, 8, 36, 24);
	initUnite(hoplite, 0, 75, 150, 0, 1, 345000, 16, 18, 8);
	initUnite(cavalier, 240, 120, 360, 0, 3, 1080000, 60, 66, 72);
	initUnite(charr, 200, 440, 320, 0, 4, 1440000, 56, 54, 64);
	initUnite(catapulte, 700, 700, 700, 0, 15, 3150000, 100, 6, 400);
}

void chargeAffichageUnite(char prixBois[100], char prixPierre[100], char prixArgent[100], char prixFaveur[100], char population[100], char temps[100], char attaque[100], char vitesse[100],
char capacite[100], Unite u, int nb_troupe){
	// Bois
	sprintf(prixBois, "%d", u.prixBois*nb_troupe);

	// Pierre
	sprintf(prixPierre, "%d", u.prixPierre*nb_troupe);

	// Argent
	sprintf(prixArgent, "%d", u.prixArgent*nb_troupe);

	// Faveur
	sprintf(prixFaveur, "%d", u.prixFaveur*nb_troupe);

	// Population
	sprintf(population, "%d", u.population*nb_troupe);

	// Temps
	int h, m, s;
	int t = (u.temps*nb_troupe)/1000;
	
	h = (t/3600);
	m = (t - h*3600)/60;
	s = (t - h*3600 - m*60);
	sprintf(temps, "%dh %dmin %dsec", h, m , s);
	
	// Attaque
	sprintf(attaque, "%d", u.attaque);
	
	// Vitesse
	sprintf(vitesse, "%d", u.vitesse);
	
	// Capacite
	sprintf(capacite, "%d", u.capacite);
};

void affichePopupCaserne(Popups popups, Batiment caserne, Troupe troupe, int nb_troupe, Unite epee, Unite frondeur, Unite archer, Unite hoplite, Unite cavalier, Unite charr, Unite catapulte){
	char prixBois[100];
	char prixPierre[100];
	char prixArgent[100];
	char prixFaveur[100];
	char population[100];
	char temps[100];
	char attaque[100];
	char vitesse[100];
	char capacite[100];
	
	if(popups.actuel == POPUP_CASERNE){
		if(caserne.popup != NULL){ ecrisImage(167, 90, caserne.popup->largeurImage, caserne.popup->hauteurImage, caserne.popup->donneesRGB);}
		
		// Epee
		if(troupe == TROUPE_EPEE){
			chargeAffichageUnite(prixBois, prixPierre, prixArgent, prixFaveur, population, temps, attaque, vitesse, capacite, epee, nb_troupe);
		}
		
		// Frondeur
		if(troupe == TROUPE_FRONDEUR){
			chargeAffichageUnite(prixBois, prixPierre, prixArgent, prixFaveur, population, temps, attaque, vitesse, capacite, frondeur, nb_troupe);
		}
		
		// Archer
		if(troupe == TROUPE_ARCHER){
			chargeAffichageUnite(prixBois, prixPierre, prixArgent, prixFaveur, population, temps, attaque, vitesse, capacite, archer, nb_troupe);
		}
		
		// Hoplite
		if(troupe == TROUPE_HOPLITE){
			chargeAffichageUnite(prixBois, prixPierre, prixArgent, prixFaveur, population, temps, attaque, vitesse, capacite, hoplite, nb_troupe);
		}
		
		// Cavalier
		if(troupe == TROUPE_CAVALIER){
			chargeAffichageUnite(prixBois, prixPierre, prixArgent, prixFaveur, population, temps, attaque, vitesse, capacite, cavalier, nb_troupe);
		}
		
		// Char
		if(troupe == TROUPE_CHAR){
			chargeAffichageUnite(prixBois, prixPierre, prixArgent, prixFaveur, population, temps, attaque, vitesse, capacite, charr, nb_troupe);
		}
		
		// Catapulte
		if(troupe == TROUPE_CATAPULTE){
			chargeAffichageUnite(prixBois, prixPierre, prixArgent, prixFaveur, population, temps, attaque, vitesse, capacite, catapulte, nb_troupe);
		}
		
		changeColor(c.noir);
		afficheChaine(prixBois, 15, 500, 450);
		afficheChaine(prixPierre, 15, 500, 417);
		afficheChaine(prixArgent, 15, 500, 385);
		afficheChaine(prixFaveur, 15, 620, 450);
		afficheChaine(population, 15, 620, 417);
		afficheChaine(temps, 12, 620, 385);
		afficheChaine(attaque, 12, 812, 453);
		afficheChaine(vitesse, 12, 812, 419);
		afficheChaine(capacite, 12, 812, 383);
		
		char nbTroupe[100];
		sprintf(nbTroupe, "%d", nb_troupe);
		afficheChaine(nbTroupe, 17, 380, 440);
	}
}

void gereClicGauchePopupCaserne(Popups* popups, int x, int y, Batiment* caserne, float* bois, float* pierre, float* argent, float* faveur, Troupe* troupe, int* nb_troupe, Unite epee, 
Unite frondeur, Unite archer, Unite hoplite, Unite cavalier, Unite charr, Unite catapulte){
	
	Unite u;
	// Epee
	if(*troupe == TROUPE_EPEE){
		u = epee;
	}
	
	// Frondeur
	if(*troupe == TROUPE_FRONDEUR){
		u = frondeur;
	}
	
	// Archer
	if(*troupe == TROUPE_ARCHER){
		u = archer;
	}
	
	// Hoplite
	if(*troupe == TROUPE_HOPLITE){
		u = hoplite;
	}
	
	// Cavalier
	if(*troupe == TROUPE_CAVALIER){
		u = cavalier;
	}
	
	// Char
	if(*troupe == TROUPE_CHAR){
		u = charr;
	}
	
	// Catapulte
	if(*troupe == TROUPE_CATAPULTE){
		u = catapulte;
	}
	
	
	if(popups->actuel == POPUP_CASERNE){
		// Gère clic sur la croix
		if(x > 958 && x < 978 && y > 628 && y < 647){
			if(popups->actuel == popups->final){
				popups->final = POPUP_NONE;
				*nb_troupe = 0;
			}
		}
		
		// Gère clic sur épée
		if(x > 184 && x < 237 && y > 518 && y < 605){
			setPopupImage(caserne, "popup");
			*troupe = TROUPE_EPEE;
			*nb_troupe = 0;
		}
		
		// Gère clic sur frondeur
		if(x > 240 && x < 295 && y > 518 && y < 605){
			setPopupImage(caserne, "popupFrondeur");
			*troupe = TROUPE_FRONDEUR;
			*nb_troupe = 0;
		}
		
		// Gère clic sur archer
		if(x > 299 && x < 353 && y > 518 && y < 605){
			setPopupImage(caserne, "popupArcher");
			*troupe = TROUPE_ARCHER;
			*nb_troupe = 0;
		}
		
		// Gère clic sur hoplite
		if(x > 357 && x < 411 && y > 518 && y < 605){
			setPopupImage(caserne, "popupHoplite");
			*troupe = TROUPE_HOPLITE;
			*nb_troupe = 0;
		}
		
		// Gère clic sur cavalier
		if(x > 415 && x < 468 && y > 518 && y < 605){
			setPopupImage(caserne, "popupCavalier");
			*troupe = TROUPE_CAVALIER;
			*nb_troupe = 0;
		}
		
		// Gère clic sur char
		if(x > 472 && x < 527 && y > 518 && y < 605){
			setPopupImage(caserne, "popupChar");
			*troupe = TROUPE_CHAR;
			*nb_troupe = 0;
		}
		
		// Gère clic sur catapulte
		if(x > 531 && x < 584 && y > 518 && y < 605){
			setPopupImage(caserne, "popupCatapulte");
			*troupe = TROUPE_CATAPULTE;
			*nb_troupe = 0;
		}
		
		// Gère clic sur -
		if(x > 327 && x < 357 && y > 387 && y < 419){
			if(*nb_troupe > 0){
				(*nb_troupe) --;
			}
		}
		
		// Gère clic sur +
		if(x > 366 && x < 396 && y > 387 && y < 419){
			if(*bois >= (*nb_troupe + 1)*(u.prixBois) && *pierre >= (*nb_troupe + 1)*(u.prixPierre) && *argent >= (*nb_troupe + 1)*(u.prixArgent) && *faveur >= (*nb_troupe + 1)*(u.prixFaveur)){
				(*nb_troupe) ++;
			}
		}
		
		// Gère clic sur valider
		if(x > 407 && x < 437 && y > 387 && y < 419){
			printf("ok\n");
			*nb_troupe = 0;
		}
		
	}
}
