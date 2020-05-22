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
#include "../headers/Evenement.h"

/**
 * Includes correspondant
 * */
#include "../headers/Attaque.h"

extern CouleurTab c;

void gereClicAttaquerMain(int x, int y, Popups* p){
	if(p->actuel == p->final && p->actuel == POPUP_NONE){
		
		if(x > 990 && x < 1134 && y > 417 && y < 438){
			p->final = POPUP_ATTAQUER;
		}
	}

}

void affichePopupAttaque(Popups p, DonneesImageRGB* attaquer, int nbAttEpee, int nbAttFrondeur, int nbAttArcher, int nbAttHoplite, int nbAttCavalier, int nbAttChar, int nbAttCatapulte, Ennemi e){
	if(p.actuel == POPUP_ATTAQUER){
		if(attaquer != NULL){ ecrisImage(167, 90, attaquer->largeurImage, attaquer->hauteurImage, attaquer->donneesRGB);}
		
		char txt[100];
		changeColor(c.blanc);
		epaisseurDeTrait(3);
		
		// Epee joueur
		sprintf(txt,"%d", nbAttEpee);
		afficheChaine(txt, 15, 336, 387);
		
		// Frondeur joueur
		sprintf(txt,"%d", nbAttFrondeur);
		afficheChaine(txt, 15, 405, 387);
		
		// Archer joueur
		sprintf(txt,"%d", nbAttArcher);
		afficheChaine(txt, 15, 477, 387);
		
		// Hoplite joueur
		sprintf(txt,"%d", nbAttHoplite);
		afficheChaine(txt, 15, 544, 387);
		
		// Cavalier joueur
		sprintf(txt,"%d", nbAttCavalier);
		afficheChaine(txt, 15, 614, 387);
		
		// Char joueur
		sprintf(txt,"%d", nbAttChar);
		afficheChaine(txt, 15, 684, 387);
		
		// Catapulte joueur
		sprintf(txt,"%d", nbAttCatapulte);
		afficheChaine(txt, 15, 750, 387);
		
		
		
		
		// Epee ennemi
		sprintf(txt,"%d", e.nbEpee);
		afficheChaine(txt, 15, 336, 518);
		
		// Frondeur ennemi
		sprintf(txt,"%d", e.nbFrondeur);
		afficheChaine(txt, 15, 405, 518);
		
		// Archer ennemi
		sprintf(txt,"%d", e.nbArcher);
		afficheChaine(txt, 15, 477, 518);
		
		// Hoplite ennemi
		sprintf(txt,"%d", e.nbHoplite);
		afficheChaine(txt, 15, 544, 518);
		
		// Cavalier ennemi
		sprintf(txt,"%d", e.nbCavalier);
		afficheChaine(txt, 15, 614, 518);
		
		// Char ennemi
		sprintf(txt,"%d", e.nbChar);
		afficheChaine(txt, 15, 684, 518);
		
		// Catapulte ennemi
		sprintf(txt,"%d", e.nbCatapulte);
		afficheChaine(txt, 15, 750, 518);
		
		epaisseurDeTrait(1);
	}
}

void initAttTroupes(int* nbAttEpee, int* nbAttFrondeur, int* nbAttArcher, int* nbAttHoplite, int* nbAttCavalier, int* nbAttChar, int* nbAttCatapulte){
	*nbAttEpee = 0;
	*nbAttFrondeur = 0;
	*nbAttArcher = 0;
	*nbAttHoplite = 0;
	*nbAttCavalier = 0;
	*nbAttChar = 0;
	*nbAttCatapulte = 0;
}

void clicPopupAttaque(int x, int y, Popups* p, int* nbAttEpee, int* nbAttFrondeur, int* nbAttArcher, int* nbAttHoplite, int* nbAttCavalier, int* nbAttChar, int* nbAttCatapulte, int* nbEpee,
int* nbFrondeur, int* nbArcher, int* nbHoplite, int* nbCavalier, int* nbChar, int* nbCatapulte, EvenementTroupe** listeEvenementTroupe, Ennemi* ennemi, Unite epee, Unite frondeur, Unite archer,
Unite hoplite, Unite cavalier, Unite charr, Unite catapulte){
	if(p->actuel == p->final && p->actuel == POPUP_ATTAQUER){
		
		// Clic croix
		if(x > 901 && x < 921 && y > 622 && y < 642){
			p->final = POPUP_NONE;
		}
		
		// Clic - epee
		if(x > 320 && x < 336 && y > 359 && y < 375 ){
			if(*nbAttEpee > 0){
				*nbAttEpee = *nbAttEpee - 1;	
			}
		}
		
		// Clic + epee
		if(x > 345 && x < 363 && y > 359 && y < 375){
			if(*nbAttEpee < *nbEpee){
				*nbAttEpee = *nbAttEpee + 1;
			}
		}
		
		// Clic - frondeur
		if(x > 389 && x < 405 && y > 359 && y < 375){
			if(*nbAttFrondeur > 0){
				*nbAttFrondeur = *nbAttFrondeur - 1;	
			}
		}
		
		// Clic + frondeur
		if(x > 414 && x < 432 && y > 359 && y < 375){
			if(*nbAttFrondeur < *nbFrondeur){
				*nbAttFrondeur = *nbAttFrondeur + 1;
			}
		}
		
		// Clic - archer
		if(x > 458 && x < 475 && y > 359 && y < 375){
			if(*nbAttArcher > 0){
				*nbAttArcher = *nbAttArcher - 1;
			}
		}
		
		// Clic + archer
		if(x > 482 && x < 501 && y > 359 && y < 375){
			if(*nbAttArcher < *nbArcher){
				*nbAttArcher = *nbAttArcher + 1;
			}
		}
		
		// Clic - hoplite
		if(x > 528 && x < 544 && y > 359 && y < 375){
			if(*nbAttHoplite > 0){
				*nbAttHoplite = *nbAttHoplite - 1;
			}
		}
		
		// Clic + hoplite
		if(x > 552 && x < 569 && y > 359 && y < 375){
			if(*nbAttHoplite < *nbHoplite){
				*nbAttHoplite = *nbAttHoplite + 1;
			}
		}
		
		// Clic - cavalier
		if(x >  595 && x < 613 && y > 359 && y < 375){
			if(*nbAttCavalier > 0){
				*nbAttCavalier = *nbAttCavalier - 1;
			}
		}
		
		// Clic + cavalier
		if(x > 620 && x < 639 && y > 359 && y < 375){
			if(*nbAttCavalier < *nbCavalier){
				*nbAttCavalier = *nbAttCavalier + 1;
			}
		}
		
		// Clic - char
		if(x > 664 && x < 682 && y > 359 && y < 375){
			if(*nbAttChar > 0){
				*nbAttChar = *nbAttChar - 1;
			}
		}
		
		// Clic + char
		if(x > 690 && x < 708 && y > 359 && y < 375){
			if(*nbAttChar < *nbChar){
				*nbAttChar = *nbAttChar + 1;
			}
		}
		
		// Clic - catapulte
		if(x > 734 && x < 750 && y > 359 && y < 375){
			if(*nbAttCatapulte > 0){
				*nbAttCatapulte = *nbAttCatapulte - 1;
			}
		}
		
		// Clic + catapulte
		if(x > 758 && x < 778 && y > 359 && y < 375){
			if(*nbAttCatapulte < *nbCatapulte){
				*nbAttCatapulte = *nbAttCatapulte + 1;
			}
		}
		
		// Clic attaquer
		if(x > 461 && x < 630 && y > 108 && y < 133){
			if(*nbAttEpee + *nbAttFrondeur + *nbAttArcher + *nbAttHoplite + *nbAttCavalier + *nbAttChar + *nbAttCatapulte > 0){
				EvenementTroupe* e;
				initEvenementTroupe(&e, calculeTempsDeTrajet(*nbAttEpee, *nbAttFrondeur, *nbAttArcher, *nbAttHoplite, *nbAttCavalier, *nbAttChar, *nbAttCatapulte, epee, frondeur, archer, hoplite,
				cavalier, charr, catapulte, *ennemi), EVENEMENT_ATTAQUE_SORTANTE, ennemi, *nbAttEpee, *nbAttFrondeur, *nbAttArcher, *nbAttHoplite, *nbAttCavalier, *nbAttChar, *nbAttCatapulte);
				insertEvenementTroupe(e, listeEvenementTroupe);
				
				// Retire les troupes du compteur
				*nbEpee = *nbEpee - *nbAttEpee;
				*nbFrondeur = *nbFrondeur - *nbAttFrondeur;
				*nbArcher = *nbArcher - *nbAttArcher;
				*nbHoplite = *nbHoplite - *nbAttHoplite;
				*nbCavalier = *nbCavalier - *nbAttCavalier;
				*nbChar = *nbChar - *nbAttChar;
				*nbCatapulte = *nbCatapulte - *nbAttCatapulte;
				
				// Réinitialise les compteurs de troupes sélectionnées
				*nbAttEpee = 0;
				*nbAttFrondeur = 0;
				*nbAttArcher = 0;
				*nbAttHoplite = 0;
				*nbAttCavalier = 0;
				*nbAttChar = 0;
				*nbAttCatapulte = 0;
				
				printf("L'attaque a bien été lancée contre %s\n", ennemi->nom);
			}
		}
		
		// Clic toutes unités
		if(x > 243 && x < 266 && y > 352 && y < 375){
			*nbAttEpee = *nbEpee;
			*nbAttFrondeur = *nbFrondeur;
			*nbAttArcher = *nbArcher;
			*nbAttHoplite = *nbHoplite;
			*nbAttCavalier = *nbCavalier;
			*nbAttChar = *nbChar;
			*nbAttCatapulte = *nbCatapulte;
		}
	}
}

int calculeVitesseArmee(int nbAttEpee, int nbAttFrondeur, int nbAttArcher, int nbAttHoplite, int nbAttCavalier, int nbAttChar, int nbAttCatapulte, Unite epee, Unite frondeur, Unite archer, Unite hoplite,
Unite cavalier, Unite charr, Unite catapulte){
	int speed = 1000;
	
	if(nbAttCatapulte > 0 && catapulte.vitesse < speed){
		speed = catapulte.vitesse;
	}
	
	if(nbAttChar > 0 && charr.vitesse < speed){
		speed = charr.vitesse;
	}
	
	if(nbAttCavalier > 0 && cavalier.vitesse < speed){
		speed = cavalier.vitesse;
	}
	
	if(nbAttHoplite > 0 && hoplite.vitesse < speed){
		speed = hoplite.vitesse;
	}
	
	if(nbAttArcher > 0 && archer.vitesse < speed){
		speed = archer.vitesse;
	}
	
	if(nbAttFrondeur > 0 && frondeur.vitesse < speed){
		speed = frondeur.vitesse;
	}
	
	if(nbAttEpee > 0 && epee.vitesse < speed){
		speed = epee.vitesse;
	}
	
	return speed;
}

int calculeTempsDeTrajet(int nbAttEpee, int nbAttFrondeur, int nbAttArcher, int nbAttHoplite, int nbAttCavalier, int nbAttChar, int nbAttCatapulte, Unite epee, Unite frondeur, Unite archer, Unite hoplite,
Unite cavalier, Unite charr, Unite catapulte, Ennemi ennemi){
	int speed = calculeVitesseArmee(nbAttEpee, nbAttFrondeur, nbAttArcher, nbAttHoplite, nbAttCavalier, nbAttChar, nbAttCatapulte, epee, frondeur, archer, hoplite, cavalier, charr, catapulte);
	int distance = ennemi.distance;
	
	return (int)distance/(int)speed;
}
