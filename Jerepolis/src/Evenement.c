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
#include "../headers/Attaque.h"

/**
 * Includes correspondant
 * */
#include "../headers/Evenement.h"

extern CouleurTab c;

extern int vitesse;

void initEvenementTroupe(EvenementTroupe** e, int timer, TypeEvenement type, Ennemi* ennemi, int nbEpee, int nbFrondeur, int nbArcher, int nbHoplite, int nbCavalier, int nbChar, int nbCatapulte,
int victoire){
	debug("<initEvenementTroupe> begin");
	
	if(e == NULL){
		error("L'adresse de l'evenement ne doit pas être à NULL");
		debug("<initEvenementTroupe> end : L'adresse de l'évenement est à NULL");
		return;
	}
	
	if(ennemi == NULL){
		error("L'ennemi doit pas être à NULL");
		debug("<initEvenementTroupe> end : L'ennemi est à NULL");
		return;
	}
	
	if(*e != NULL){
		warn("L'evenement n'est pas vide, toutes les anciennes données vont être écrasées");
		*e = NULL;
	}
	
	*e = (EvenementTroupe*) malloc(sizeof(EvenementTroupe));
	if(*e == NULL){
		error("Erreur lors du malloc");
		debug("<initEvenementTroupe> end : malloc error");
		return;
	}
	
	(*e)->timer = timer;
	(*e)->type = type;
	(*e)->ennemi = ennemi;
	(*e)->victoire = victoire;
	(*e)->next = NULL;
	(*e)->nbEpee = nbEpee;
	(*e)->nbFrondeur = nbFrondeur;
	(*e)->nbArcher = nbArcher;
	(*e)->nbHoplite = nbHoplite;
	(*e)->nbCavalier = nbCavalier;
	(*e)->nbChar = nbChar;
	(*e)->nbCatapulte = nbCatapulte;
	
	debug("<initEvenementTroupe> end");
}

void insertEvenementTroupe(EvenementTroupe* e, EvenementTroupe** listeEvenementTroupe){
	debug("<insertEvenementTroupe> begin");
	
	if(e == NULL){
		error("L'evenement à insérer ne doit pas être à NULL");
		debug("<insertEvenementTroupe> end : evenement à insérer est à NULL");
		return;
	}
	
	if(listeEvenementTroupe == NULL){
		error("L'adresse de la tete de liste evenements ne doit pas être à NULL");
		debug("<insertEvenementTroupe> end : L'adresse de la tete de liste evenements est à NULL");
		return;
	}

	if(*listeEvenementTroupe == NULL){
		info("La liste d'evenements est vide");
		*listeEvenementTroupe = e;
		e->next = NULL;
		debug("<insertEvenementTroupe> end : evenement inséré en 1ère position car liste vide");
		return;
	}
	
	if(e->timer < (*listeEvenementTroupe)->timer){
		info("L'evenement est à placer en première position");
		e->next = *listeEvenementTroupe;
		*listeEvenementTroupe = e;
		debug("<insertEvenementTroupe> end : evenement inséré en 1ère position");
		return;
	}
	
	EvenementTroupe* courant = *listeEvenementTroupe;
	while(courant->next != NULL){
		
		if(courant->next->timer > e->timer){
			e->next = courant->next;
			courant->next = e;
			debug("<insertEvenementTroupe> end: evenement inséré au milieu");
			return;
		}
		
		courant = courant->next;
	}
	
	info("L'evenement est à placer en dernière position");
	courant->next = e;
	
	debug("<insertEvenementTroupe> end : evenement inséré à la fin");
}

void printEvenementTroupe(EvenementTroupe* e){
	debug("<printEvenementTroupe> begin");
	
	if(e == NULL){
		info("L'evenement à afficher est à NULL -> rien à afficher");
		debug("<printEvenementTroupe> end : element à NULL");
		return;
	}
	
	printf("timer : %d\n", e->timer);
	printf("ennemi : %s\n", e->ennemi->nom);

	debug("<printEvenementTroupe> end");
}

void printListeEvenementTroupe(EvenementTroupe* listeEvenementTroupe){
	debug("<printListeEvenementTroupe> begin");
	
	if(listeEvenementTroupe == NULL){
		info("La tete de liste est à NULL -> liste vide rien à afficher");
		debug("<printListeEvenementTroupe> end : teteDeListe à NULL");
		return;
	}
	
	EvenementTroupe* courant = listeEvenementTroupe;
	int cpt = 0;
	while(courant != NULL){
		printf("Evenement %d :\n", cpt);
		printEvenementTroupe(courant);
		courant = courant->next;
		cpt++;
		printf("\n");
	}
	
	debug("<printListeEvenementTroupe> end");
}

void gereListeEvenementTroupe(EvenementTroupe** listeEvenementTroupe, Unite epee, Unite frondeur, Unite archer, Unite hoplite, Unite cavalier, Unite charr, Unite catapulte,
int* nbEpee, int* nbFrondeur, int* nbArcher, int* nbHoplite, int* nbCavalier, int* nbChar, int* nbCatapulte, float* pierre, float* bois, float* argent){
	debug("<gereListeEvenementTroupe> begin");
	
	if(listeEvenementTroupe == NULL){
		error("L'adresse de la liste d'evenement troupe ne doit pas être à NULL");
		debug("<gereListeEvenementTroupe> end : l'adresse de la liste d'evenement troupe est à NULL");
		return;
	}
	
	if(*listeEvenementTroupe == NULL){
		info("La liste d'evenements troupe est vide");
		debug("<gereListeEvenementTroupe> end : la liste d'evenement troue est vide");
		return;
	}
	
	EvenementTroupe* courant = *listeEvenementTroupe;
	
	while(courant != NULL){
		courant->timer -= 50*vitesse;
		if(courant->timer < 0){
			*listeEvenementTroupe = courant->next;
			finEvenementTroupe(courant, epee, frondeur, archer, hoplite, cavalier, charr, catapulte, listeEvenementTroupe, nbEpee, nbFrondeur, nbArcher, nbHoplite, nbCavalier, nbChar, nbCatapulte,
			pierre, bois, argent);
		}
		
		courant = courant->next;
	}
	
	debug("<gereListeEvenementTroupe> end");
}

void finEvenementTroupe(EvenementTroupe* e, Unite epee, Unite frondeur, Unite archer, Unite hoplite, Unite cavalier, Unite charr, Unite catapulte, EvenementTroupe** listeEvenementTroupe,
int* nbEpee, int* nbFrondeur, int* nbArcher, int* nbHoplite, int* nbCavalier, int* nbChar, int* nbCatapulte, float* pierre, float* bois, float* argent){
	
	if(e->type == EVENEMENT_ATTAQUE_SORTANTE){
		printf("Combat contre %s\n",e->ennemi->nom);
		int resultat = combat(e, epee, frondeur, archer, hoplite, cavalier, charr, catapulte);
		
		if(resultat == -1){ // Défaite du joueur
			// Toutes les troupes du joueur sont mortes
		}else{ // Victoire du joueur
			// Des troupes ont survécu, elles reviennent dans la ville
			EvenementTroupe* retour;
			initEvenementTroupe(&retour, calculeTempsDeTrajet(e->nbEpee, e->nbFrondeur, e->nbArcher, e->nbHoplite, e->nbCavalier, e->nbChar, e->nbCatapulte, epee, frondeur, archer, hoplite,
			cavalier, charr, catapulte, *(e->ennemi)), EVENEMENT_RETOUR_TROUPE, e->ennemi, e->nbEpee, e->nbFrondeur, e->nbArcher, e->nbHoplite, e->nbCavalier, e->nbChar, e->nbCatapulte, 1);
			insertEvenementTroupe(retour, listeEvenementTroupe);
		}
	}
	
	if(e->type == EVENEMENT_RETOUR_TROUPE){
		// Le joueur récupère les troupes survivantes
		*nbEpee = *nbEpee + e->nbEpee;
		*nbFrondeur = *nbFrondeur + e->nbFrondeur;
		*nbArcher = *nbArcher + e->nbArcher;
		*nbHoplite = *nbHoplite + e->nbHoplite;
		*nbCavalier = *nbCavalier + e->nbCavalier;
		*nbChar = *nbChar + e->nbChar;
		*nbCatapulte = *nbCatapulte + e->nbCatapulte;
		
		// Si le joueur a gagné une bataille, ses troupes ont pillé l'adversaire perdant
		if(e->victoire == 1){
			// Le joueur gagne les ressources pillées par ses troupes revenantes
			float capaciteArmee = calculeCapaciteArmee(e, epee, frondeur, archer, hoplite, cavalier, charr, catapulte);
			printf("capactié de ressources : %f\n", capaciteArmee);
			*pierre = *pierre + capaciteArmee;
			*bois = *bois + capaciteArmee;
			*argent = *argent + capaciteArmee;
		}
	}
	
	free(e);
	e = NULL;
}

float calculeCapaciteArmee(EvenementTroupe* e, Unite epee, Unite frondeur, Unite archer, Unite hoplite, Unite cavalier, Unite charr, Unite catapulte){
	return e->nbEpee*epee.capacite/3 + e->nbFrondeur*frondeur.capacite/3 + e->nbArcher*archer.capacite/3 + e->nbHoplite*hoplite.capacite/3 + e->nbCavalier*cavalier.capacite/3
					+ e->nbChar*charr.capacite/3 + e->nbCatapulte*catapulte.capacite/3;
}

int combat(EvenementTroupe* e, Unite epee, Unite frondeur, Unite archer, Unite hoplite, Unite cavalier, Unite charr, Unite catapulte){
	int attaqueJoueur = e->nbEpee*epee.attaque + e->nbFrondeur*frondeur.attaque + e->nbArcher*archer.attaque + e->nbHoplite*hoplite.attaque + e->nbCavalier*cavalier.attaque + e->nbChar*charr.attaque
						+ e->nbCatapulte*catapulte.attaque;
	int attaqueEnnemi = e->ennemi->nbEpee*epee.attaque + e->ennemi->nbFrondeur*frondeur.attaque + e->ennemi->nbArcher*archer.attaque + e->ennemi->nbHoplite*hoplite.attaque
					+ e->ennemi->nbCavalier*cavalier.attaque + e->ennemi->nbChar*charr.attaque + e->ennemi->nbCatapulte*catapulte.attaque;
	
	int resultat = attaqueJoueur - attaqueEnnemi;
	info("Attaque joueur : %d\n", attaqueJoueur);
	info("Attaque ennemi : %d\n", attaqueEnnemi);
	info("Resultat : %d\n", resultat);
	
	if(resultat > 0){ // Victoire du joueur
		printf("Victoire\n");
		calculeUnitesRestantes(&(e->nbEpee), &(e->nbFrondeur), &(e->nbArcher), &(e->nbHoplite), &(e->nbCavalier), &(e->nbChar), &(e->nbCatapulte), resultat, attaqueJoueur);
		return 1;
	}else{ // Défaite du joueur
		printf("Défaite\n");
		calculeUnitesRestantes(&(e->ennemi->nbEpee), &(e->ennemi->nbFrondeur), &(e->ennemi->nbArcher), &(e->ennemi->nbHoplite), &(e->ennemi->nbCavalier), &(e->ennemi->nbChar),
								&(e->ennemi->nbCatapulte), -resultat, attaqueEnnemi);
		return -1;
	}
}

void calculeUnitesRestantes(int* nbEpee, int* nbFrondeur, int* nbArcher, int* nbHoplite, int* nbCavalier, int* nbChar, int* nbCatapulte, int resultat, int attaque){
	*nbEpee = *nbEpee - (*nbEpee - (*nbEpee)*resultat/attaque);
	*nbFrondeur = *nbFrondeur - (*nbFrondeur - (*nbFrondeur)*resultat/attaque);
	*nbArcher = *nbArcher - (*nbArcher - (*nbArcher)*resultat/attaque);
	*nbHoplite = *nbHoplite - (*nbHoplite - (*nbHoplite)*resultat/attaque);
	*nbCavalier = *nbCavalier - (*nbCavalier - (*nbCavalier)*resultat/attaque);
	*nbChar = *nbChar - (*nbChar - (*nbChar)*resultat/attaque);
	*nbCatapulte = *nbCatapulte - (*nbCatapulte - (*nbCatapulte)*resultat/attaque);
}

void gereClicListeEvenementTroupe(EvenementTroupe** listeEvenementTroupe, int x, int y, Popups p, Unite epee, Unite frondeur, Unite archer, Unite hoplite, Unite cavalier, Unite charr, Unite catapulte){
	if(*listeEvenementTroupe == NULL){
		return;
	}
	
	if(p.actuel == p.final && p.actuel == POPUP_NONE){
		EvenementTroupe* courant = *listeEvenementTroupe;
		int cpt = 0;
		EvenementTroupe* precedent;
		
		while(courant != NULL){
			if(x > 940 && x < 940+211 && y > 355 - 55*cpt && y < 355 - 55*cpt + 50){
				if(courant->type == EVENEMENT_ATTAQUE_SORTANTE){
					if(x > 1112 && x < 1133 && y > 355 - 55*cpt + 5 && y < 355 - 55*cpt + 45){
						printf("close\n");
						if(cpt == 0){
							*listeEvenementTroupe = courant->next;
							
							EvenementTroupe* retour;
							initEvenementTroupe(&retour, calculeTempsDeTrajet(courant->nbEpee, courant->nbFrondeur, courant->nbArcher, courant->nbHoplite, courant->nbCavalier, courant->nbChar,
							courant->nbCatapulte, epee, frondeur, archer, hoplite, cavalier, charr, catapulte, *(courant->ennemi)) - courant->timer, EVENEMENT_RETOUR_TROUPE, courant->ennemi,
							courant->nbEpee, courant->nbFrondeur, courant->nbArcher, courant->nbHoplite, courant->nbCavalier, courant->nbChar, courant->nbCatapulte, 0);
							insertEvenementTroupe(retour, listeEvenementTroupe);
							
							
							free(courant);
							courant = NULL;
							return;
						}else{
							precedent->next = courant->next;
							
							EvenementTroupe* retour;
							initEvenementTroupe(&retour, calculeTempsDeTrajet(courant->nbEpee, courant->nbFrondeur, courant->nbArcher, courant->nbHoplite, courant->nbCavalier, courant->nbChar,
							courant->nbCatapulte, epee, frondeur, archer, hoplite, cavalier, charr, catapulte, *(courant->ennemi)) - courant->timer, EVENEMENT_RETOUR_TROUPE, courant->ennemi,
							courant->nbEpee, courant->nbFrondeur, courant->nbArcher, courant->nbHoplite, courant->nbCavalier, courant->nbChar, courant->nbCatapulte, 0);
							insertEvenementTroupe(retour, listeEvenementTroupe);
							
							free(courant);
							courant = NULL;
							return;
						}
					}
				}
			}
			
			cpt++;
			precedent = courant;
			courant = courant->next;
		}
	}
}

void afficheEvenement(EvenementTroupe* e, int numero, DonneesImageRGB* attaqueSortante, DonneesImageRGB* retourTroupe){
	debug("<afficheEvenement> begin");
	
	if(e == NULL){
		error("L'evenement ne doit pas être à NULL");
		debug("<afficheEvenement> end : L'evenement est à NULL");
		return;
	}
	
	if(e->type == EVENEMENT_ATTAQUE_SORTANTE){
		if(attaqueSortante != NULL){ ecrisImage(940, 355 - 55*numero, attaqueSortante->largeurImage, attaqueSortante->hauteurImage, attaqueSortante->donneesRGB);}
	}
	
	if(e->type == EVENEMENT_RETOUR_TROUPE){
		if(retourTroupe != NULL){ ecrisImage(940, 355 - 55*numero, retourTroupe->largeurImage, retourTroupe->hauteurImage, retourTroupe->donneesRGB);}
	}
		
		char tmp[100];
		changeColor(c.noir);
		
		// Temps restant
		int h, m, s;
		int t = (e->timer/1000)/vitesse;
		h = (t/3600);
		m = (t - h*3600)/60;
		s = (t - h*3600 - m*60);
		sprintf(tmp, "%dh %dmin %dsec", h, m , s);
		afficheChaine(tmp, 10, 1000, 385 - 55*numero);
		
		// Ennemi
		sprintf(tmp, "%s", e->ennemi->nom);
		afficheChaine(tmp, 8, 1000, 370 - 55*numero);
	
	debug("<afficheEvenement> end");
}

void afficheListeEvenementTroupe(EvenementTroupe* e, DonneesImageRGB* attaqueSortante, DonneesImageRGB* retourTroupe){
	debug("<afficheListeEvenementTroupe> begin");
	
	if(e == NULL){
		info("La tete de liste evenement troupe est à NULL");
		debug("<afficheEvenement> end : La tete de liste evenement troupe est à NULL");
		return;
	}
	
	EvenementTroupe* courant = e;
	int cpt = 0;
	
	while(courant != NULL){
		afficheEvenement(courant, cpt, attaqueSortante, retourTroupe);
		
		cpt++;
		courant = courant->next;
	}
	
	debug("<afficheListeEvenementTroupe> end");
}
