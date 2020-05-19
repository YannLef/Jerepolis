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
#include "../headers/RecrutementUnite.h"

/**
 * Includes correspondant
 * */
#include "../headers/Caserne.h"

extern CouleurTab c;
extern int vitesse;

void initUnite(Unite* u, char* nom, int prixBois, int prixPierre, int prixArgent, int prixFaveur, int population, int temps, int attaque, int vitesseTrp, int capacite, Troupe type){
	u->prixBois = prixBois;
	u->prixPierre = prixPierre;
	u->prixArgent = prixArgent;
	u->prixFaveur = prixFaveur;
	u->population = population;
	u->temps = temps;
	u->attaque = attaque;
	u->vitesse = vitesseTrp;
	u->capacite = capacite;
	u->nom = nom;
	u->type = type;
	char tmp[100];
	
	strcpy(tmp, "../Jerepolis/ressources/images/unites/");
	strcat(tmp, nom);
	strcat(tmp, ".bmp");
	u->icon = lisBMPRGB(tmp);
	if(u->icon == NULL){
		error("Erreur lors de l'ouverture de l'icon de l'unité");
	}
	
}

void initUnites(Unite* epee, Unite* frondeur, Unite* archer, Unite* hoplite, Unite* cavalier, Unite* charr, Unite* catapulte){
	initUnite(epee, "epee", 95, 0, 85, 0, 1, 10000, 5, 48, 16, TROUPE_EPEE);
	initUnite(frondeur, "frondeur", 55, 100, 40, 0, 1, 300000, 23, 84, 8, TROUPE_FRONDEUR);
	initUnite(archer, "archer", 120, 0, 75, 0, 1, 285000, 8, 36, 24, TROUPE_ARCHER);
	initUnite(hoplite, "hoplite", 0, 75, 150, 0, 1, 345000, 16, 18, 8, TROUPE_HOPLITE);
	initUnite(cavalier, "cavalier", 240, 120, 360, 0, 3, 1080000, 60, 66, 72, TROUPE_CAVALIER);
	initUnite(charr, "char", 200, 440, 320, 0, 4, 1440000, 56, 54, 64, TROUPE_CHAR);
	initUnite(catapulte, "catapulte", 700, 700, 700, 0, 15, 3150000, 100, 6, 400, TROUPE_CATAPULTE);
}

void chargeAffichageUnite(Batiment caserne, char prixBois[100], char prixPierre[100], char prixArgent[100], char prixFaveur[100], char population[100], char temps[100], char attaque[100], char vitesseTrp[100],
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
	int t = ((u.temps*nb_troupe)/1000)/vitesse*(1 + 0.1*caserne.population);
	
	h = (t/3600);
	m = (t - h*3600)/60;
	s = (t - h*3600 - m*60);
	sprintf(temps, "%dh %dmin %dsec", h, m , s);
	
	// Attaque
	sprintf(attaque, "%d", u.attaque);
	
	// Vitesse
	sprintf(vitesseTrp, "%d", u.vitesse);
	
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
	char vitesseTrp[100];
	char capacite[100];
	
	if(popups.actuel == POPUP_CASERNE){
		if(caserne.popup != NULL){ ecrisImage(167, 90, caserne.popup->largeurImage, caserne.popup->hauteurImage, caserne.popup->donneesRGB);}
		
		// Epee
		if(troupe == TROUPE_EPEE){
			chargeAffichageUnite(caserne, prixBois, prixPierre, prixArgent, prixFaveur, population, temps, attaque, vitesseTrp, capacite, epee, nb_troupe);
		}
		
		// Frondeur
		if(troupe == TROUPE_FRONDEUR){
			chargeAffichageUnite(caserne, prixBois, prixPierre, prixArgent, prixFaveur, population, temps, attaque, vitesseTrp, capacite, frondeur, nb_troupe);
		}
		
		// Archer
		if(troupe == TROUPE_ARCHER){
			chargeAffichageUnite(caserne, prixBois, prixPierre, prixArgent, prixFaveur, population, temps, attaque, vitesseTrp, capacite, archer, nb_troupe);
		}
		
		// Hoplite
		if(troupe == TROUPE_HOPLITE){
			chargeAffichageUnite(caserne, prixBois, prixPierre, prixArgent, prixFaveur, population, temps, attaque, vitesseTrp, capacite, hoplite, nb_troupe);
		}
		
		// Cavalier
		if(troupe == TROUPE_CAVALIER){
			chargeAffichageUnite(caserne, prixBois, prixPierre, prixArgent, prixFaveur, population, temps, attaque, vitesseTrp, capacite, cavalier, nb_troupe);
		}
		
		// Char
		if(troupe == TROUPE_CHAR){
			chargeAffichageUnite(caserne, prixBois, prixPierre, prixArgent, prixFaveur, population, temps, attaque, vitesseTrp, capacite, charr, nb_troupe);
		}
		
		// Catapulte
		if(troupe == TROUPE_CATAPULTE){
			chargeAffichageUnite(caserne, prixBois, prixPierre, prixArgent, prixFaveur, population, temps, attaque, vitesseTrp, capacite, catapulte, nb_troupe);
		}
		
		changeColor(c.noir);
		afficheChaine(prixBois, 15, 500, 450);
		afficheChaine(prixPierre, 15, 500, 417);
		afficheChaine(prixArgent, 15, 500, 385);
		afficheChaine(prixFaveur, 15, 620, 450);
		afficheChaine(population, 15, 620, 417);
		afficheChaine(temps, 12, 620, 385);
		afficheChaine(attaque, 12, 812, 453);
		afficheChaine(vitesseTrp, 12, 812, 419);
		afficheChaine(capacite, 12, 812, 383);
		
		char nbTroupe[100];
		sprintf(nbTroupe, "%d", nb_troupe);
		afficheChaine(nbTroupe, 17, 380, 440);
	}
}

void gereClicGauchePopupCaserne(Popups* popups, int x, int y, Batiment* caserne, float* bois, float* pierre, float* argent, float* faveur, Troupe* troupe, int* nb_troupe, Unite* epee, 
Unite* frondeur, Unite* archer, Unite* hoplite, Unite* cavalier, Unite* charr, Unite* catapulte, RecrutementUnite** fileDeRecrutement){
	
	if(popups->actuel != POPUP_CASERNE){
		return;
	}
	
	Unite* u;
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
			if(*bois >= (*nb_troupe + 1)*(u->prixBois) && *pierre >= (*nb_troupe + 1)*(u->prixPierre) && *argent >= (*nb_troupe + 1)*(u->prixArgent) && *faveur >= (*nb_troupe + 1)*(u->prixFaveur)){
				(*nb_troupe) ++;
			}
		}
		
		// Gère clic sur valider
		if(x > 407 && x < 437 && y > 387 && y < 419){
			if(*nb_troupe > 0){
				if(getTailleFileDeRecrutement(*fileDeRecrutement) < 7){
					RecrutementUnite* recrutement;
					initRecrutementUnite(&recrutement, *nb_troupe, u); 
					ajouteRecrutementUnite(fileDeRecrutement, recrutement);
					*bois = *bois - (*nb_troupe)*(u->prixBois);
					*pierre = *pierre - (*nb_troupe)*(u->prixPierre);
					*argent = *argent - (*nb_troupe)*(u->prixArgent);
					*faveur = *faveur - (*nb_troupe)*(u->prixFaveur);
				}else{
					printf("La file de recrutement est pleine\n");
				}
				
				*nb_troupe = 0;
			}
		}
}

void ajouteUnite(Troupe type, int* nbEpee, int* nbFrondeur, int* nbArcher, int* nbHoplite, int* nbCavalier, int* nbChar, int* nbCatapulte){
	switch(type){
		case TROUPE_EPEE:
			*nbEpee++;
			break;
		case TROUPE_FRONDEUR:
			*nbFrondeur++;
			break;
		case TROUPE_ARCHER:
			*nbArcher++;
			break;
		case TROUPE_HOPLITE:
			*nbHoplite++;
			break;
		case TROUPE_CAVALIER:
			*nbCavalier++;
			break;
		case TROUPE_CHAR:
			*nbChar++;
			break;
		case TROUPE_CATAPULTE:
			*nbCatapulte++;
			break;
	}
}
