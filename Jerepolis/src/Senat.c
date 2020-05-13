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
 * Includes Jerepolis
 * */
#include "../headers/structures.h"
#include "../headers/Batiment.h"
#include "../headers/AmeliorationBatiment.h"

/**
 * Includes correspondant
 * */
#include "../headers/Senat.h"

void affichePopupSenat(Popups popups, DonneesImageRGB *maximum, DonneesImageRGB *impossible, DonneesImageRGB *ameliorer, DonneesImageRGB *construire, float* bois, float* pierre, float* argent, ameliorationBatiment* fileDeConstructions,
Batiment senat, Batiment scierie, Batiment ferme, Batiment entrepot, Batiment mine, Batiment carriere, Batiment temple, Batiment caserne){
	
	if(popups.actuel == POPUP_SENAT){
		if(senat.popup != NULL){ ecrisImage(167, 90, senat.popup->largeurImage, senat.popup->hauteurImage, senat.popup->donneesRGB);}
		
		// Sénat
		if(senat.max){
			if(maximum != NULL){ ecrisImage(487, 549, maximum->largeurImage, maximum->hauteurImage, maximum->donneesRGB);}
		}else{
			if(senat.prixAmeliorationBois < *bois && senat.prixAmeliorationPierre < *pierre && senat.prixAmeliorationArgent < *argent && getTailleFileDeConstruction(fileDeConstructions) < 4){
				if(senat.niveau == 0 && senat.nbAmeliorationsEnCours == 0){
					if(construire != NULL){ ecrisImage(487, 549, construire->largeurImage, construire->hauteurImage, construire->donneesRGB);}
				}else{
					if(ameliorer != NULL){ ecrisImage(487, 549, ameliorer->largeurImage, ameliorer->hauteurImage, ameliorer->donneesRGB);}
				}
			}else{
				if(impossible != NULL){ ecrisImage(487, 549, impossible->largeurImage, impossible->hauteurImage, impossible->donneesRGB);}
			}
		}
		// Scierie
		if(scierie.max){
			if(maximum != NULL){ ecrisImage(205, 482, maximum->largeurImage, maximum->hauteurImage, maximum->donneesRGB);}
		}else{
			if(scierie.prixAmeliorationBois < *bois && scierie.prixAmeliorationPierre < *pierre && scierie.prixAmeliorationArgent < *argent && getTailleFileDeConstruction(fileDeConstructions) < 4){
				if(scierie.niveau == 0 && scierie.nbAmeliorationsEnCours == 0){
					if(construire != NULL){ ecrisImage(205, 482, construire->largeurImage, construire->hauteurImage, construire->donneesRGB);}
				}else{
					if(ameliorer != NULL){ ecrisImage(205, 482, ameliorer->largeurImage, ameliorer->hauteurImage, ameliorer->donneesRGB);}
				}
			}else{
				if(impossible != NULL){ ecrisImage(205, 482, impossible->largeurImage, impossible->hauteurImage, impossible->donneesRGB);}
			}
		}
		// Ferme
		if(ferme.max){
			if(maximum != NULL){ ecrisImage(393, 482, maximum->largeurImage, maximum->hauteurImage, maximum->donneesRGB);}
		}else{
			if(ferme.prixAmeliorationBois < *bois && ferme.prixAmeliorationPierre < *pierre && ferme.prixAmeliorationArgent < *argent && getTailleFileDeConstruction(fileDeConstructions) < 4){
				if(ferme.niveau == 0 && ferme.nbAmeliorationsEnCours == 0){
					if(construire != NULL){ ecrisImage(393, 482, construire->largeurImage, construire->hauteurImage, construire->donneesRGB);}
				}else{
					if(ameliorer != NULL){ ecrisImage(393, 482, ameliorer->largeurImage, ameliorer->hauteurImage, ameliorer->donneesRGB);}
				}
			}else{
				if(impossible != NULL){ ecrisImage(393, 482, impossible->largeurImage, impossible->hauteurImage, impossible->donneesRGB);}
			}
		}
		// Carrière
		if(carriere.max){
			if(maximum != NULL){ ecrisImage(581, 482, maximum->largeurImage, maximum->hauteurImage, maximum->donneesRGB);}
		}else{
			if(carriere.prixAmeliorationBois < *bois && carriere.prixAmeliorationPierre < *pierre && carriere.prixAmeliorationArgent < *argent && getTailleFileDeConstruction(fileDeConstructions) < 4){
				if(carriere.niveau == 0 && carriere.nbAmeliorationsEnCours == 0){
					if(construire != NULL){ ecrisImage(581, 482, construire->largeurImage, construire->hauteurImage, construire->donneesRGB);}
				}else{
					if(ameliorer != NULL){ ecrisImage(581, 482, ameliorer->largeurImage, ameliorer->hauteurImage, ameliorer->donneesRGB);}
				}
			}else{
				if(impossible != NULL){ ecrisImage(581, 482, impossible->largeurImage, impossible->hauteurImage, impossible->donneesRGB);}
			}
		}
		// Entrepot
		if(entrepot.max){
			if(maximum != NULL){ ecrisImage(769, 482, maximum->largeurImage, maximum->hauteurImage, maximum->donneesRGB);}
		}else{
			if(entrepot.prixAmeliorationBois < *bois && entrepot.prixAmeliorationPierre < *pierre && entrepot.prixAmeliorationArgent < *argent && getTailleFileDeConstruction(fileDeConstructions) < 4){
				if(entrepot.niveau == 0 && entrepot.nbAmeliorationsEnCours == 0){
					if(construire != NULL){ ecrisImage(769, 482, construire->largeurImage, construire->hauteurImage, construire->donneesRGB);}
				}else{
					if(ameliorer != NULL){ ecrisImage(769, 482, ameliorer->largeurImage, ameliorer->hauteurImage, ameliorer->donneesRGB);}
				}
			}else{
				if(impossible != NULL){ ecrisImage(769, 482, impossible->largeurImage, impossible->hauteurImage, impossible->donneesRGB);}
			}
		}
		// Mine
		if(mine.max){
			if(maximum != NULL){ ecrisImage(205, 404, maximum->largeurImage, maximum->hauteurImage, maximum->donneesRGB);}
		}else{
			if(mine.prixAmeliorationBois < *bois && mine.prixAmeliorationPierre < *pierre && mine.prixAmeliorationArgent < *argent && getTailleFileDeConstruction(fileDeConstructions) < 4){
				if(mine.niveau == 0 && mine.nbAmeliorationsEnCours == 0){
					if(construire != NULL){ ecrisImage(205, 404, construire->largeurImage, construire->hauteurImage, construire->donneesRGB);}
				}else{
					if(ameliorer != NULL){ ecrisImage(205, 404, ameliorer->largeurImage, ameliorer->hauteurImage, ameliorer->donneesRGB);}
				}
			}else{
				if(impossible != NULL){ ecrisImage(205, 404, impossible->largeurImage, impossible->hauteurImage, impossible->donneesRGB);}
			}
		}
		// Caserne
		if(caserne.max){
			if(maximum != NULL){ ecrisImage(393, 404, maximum->largeurImage, maximum->hauteurImage, maximum->donneesRGB);}
		}else{
			if(caserne.prixAmeliorationBois < *bois && caserne.prixAmeliorationPierre < *pierre && caserne.prixAmeliorationArgent < *argent && getTailleFileDeConstruction(fileDeConstructions) < 4){
				if(caserne.niveau == 0 && caserne.nbAmeliorationsEnCours == 0){
					if(construire != NULL){ ecrisImage(393, 404, construire->largeurImage, construire->hauteurImage, construire->donneesRGB);}
				}else{
					if(ameliorer != NULL){ ecrisImage(393, 404, ameliorer->largeurImage, ameliorer->hauteurImage, ameliorer->donneesRGB);}
				}
			}else{
				if(impossible != NULL){ ecrisImage(393, 404, impossible->largeurImage, impossible->hauteurImage, impossible->donneesRGB);}
			}
		}
		// Temple
		if(temple.max){
			if(maximum != NULL){ ecrisImage(581, 404, maximum->largeurImage, maximum->hauteurImage, maximum->donneesRGB);}
		}else{
			if(temple.prixAmeliorationBois < *bois && temple.prixAmeliorationPierre < *pierre && temple.prixAmeliorationArgent < *argent && getTailleFileDeConstruction(fileDeConstructions) < 4){
				if(temple.niveau == 0 && temple.nbAmeliorationsEnCours == 0){
					if(construire != NULL){ ecrisImage(581, 404, construire->largeurImage, construire->hauteurImage, construire->donneesRGB);}
				}else{
					if(ameliorer != NULL){ ecrisImage(581, 404, ameliorer->largeurImage, ameliorer->hauteurImage, ameliorer->donneesRGB);}
				}
			}else{
				if(impossible != NULL){ ecrisImage(581, 404, impossible->largeurImage, impossible->hauteurImage, impossible->donneesRGB);}
			}
		}
	}
}

int calculeXFinBouton(int xDebut){
	// La largeur d'un bouton est de 168px
	return xDebut + 168;
}

int calculeYFinBouton(int yDebut){
	// La largeur d'un bouton est de 168px
	return yDebut + 17;
}

void gereClicGauchePopupSenat(Popups* popups, int x, int y, float* bois, float* pierre, float* argent, ameliorationBatiment** fileDeConstructions, Batiment* senat, Batiment* scierie,
Batiment* ferme, Batiment* carriere, Batiment* entrepot, Batiment* mine, Batiment* caserne, Batiment* temple){
	if(popups->actuel == POPUP_SENAT){
		// Gère clic sur la croix
		if(x > 960 && x < 978 && y > 633 && y < 647){
			if(popups->actuel == popups->final){
				popups->final = NONE;
			}
		}
		
		// Gère clic sur le bouton du sénat
		if(x > 487 && x < calculeXFinBouton(487) && y > 549 && y < calculeYFinBouton(549)){
			if(senat->max){
				printf("Votre sénat est déjà au niveau maximum\n");
			}else{
				if(senat->prixAmeliorationBois < *bois && senat->prixAmeliorationPierre < *pierre && senat->prixAmeliorationArgent < *argent && getTailleFileDeConstruction(*fileDeConstructions) < 4){
					amelioreBatiment(senat, bois, pierre, argent, fileDeConstructions);
				}else{
					printf("Vous n'avez pas assez de ressources\n");
				}
			}
		}
		 
		// Gère clic sur le bouton de la scierie
		if(x > 205 && x < calculeXFinBouton(205) && y > 482 && y < calculeYFinBouton(482)){
			if(scierie->max){
				printf("Votre scierie est déjà au niveau maximum\n");
			}else{
				if(scierie->prixAmeliorationBois < *bois && scierie->prixAmeliorationPierre < *pierre && scierie->prixAmeliorationArgent < *argent && getTailleFileDeConstruction(*fileDeConstructions) < 4){
					amelioreBatiment(scierie, bois, pierre, argent, fileDeConstructions);
				}else{
					printf("Vous n'avez pas assez de ressources\n");
				}
			}
		}
		 
		// Gère clic sur le bouton de la ferme
		if(x > 393 && x < calculeXFinBouton(393) && y > 482 && y < calculeYFinBouton(482)){
			if(ferme->max){
				printf("Votre ferme est déjà au niveau maximum\n");
			}else{
				if(ferme->prixAmeliorationBois < *bois && ferme->prixAmeliorationPierre < *pierre && ferme->prixAmeliorationArgent < *argent && getTailleFileDeConstruction(*fileDeConstructions) < 4){
					amelioreBatiment(ferme, bois, pierre, argent, fileDeConstructions);
				}else{
					printf("Vous n'avez pas assez de ressources\n");
				}
			}
		}
		
		// Gère clic sur le bouton de la carrière
		if(x > 581 && x < calculeXFinBouton(581) && y > 482 && y < calculeYFinBouton(482)){
			if(carriere->max){
				printf("Votre carriere est déjà au niveau maximum\n");
			}else{
				if(carriere->prixAmeliorationBois < *bois && carriere->prixAmeliorationPierre < *pierre && carriere->prixAmeliorationArgent < *argent && getTailleFileDeConstruction(*fileDeConstructions) < 4){
					amelioreBatiment(carriere, bois, pierre, argent, fileDeConstructions);
				}else{
					printf("Vous n'avez pas assez de ressources\n");
				}
			}
		}
		
		// Gère clic sur le bouton de l'entrepot
		if(x > 769 && x < calculeXFinBouton(769) && y > 482 && y < calculeYFinBouton(482)){
			if(entrepot->max){
				printf("Votre entrepot est déjà au niveau maximum\n");
			}else{
				if(entrepot->prixAmeliorationBois < *bois && entrepot->prixAmeliorationPierre < *pierre && entrepot->prixAmeliorationArgent < *argent && getTailleFileDeConstruction(*fileDeConstructions) < 4){
					amelioreBatiment(entrepot, bois, pierre, argent, fileDeConstructions);
				}else{
					printf("Vous n'avez pas assez de ressources\n");
				}
			}
		}
		
		// Gère clic sur le bouton de la mine
		if(x > 205 && x < calculeXFinBouton(205) && y > 404 && y < calculeYFinBouton(404)){
			if(mine->max){
				printf("Votre mine est déjà au niveau maximum\n");
			}else{
				if(mine->prixAmeliorationBois < *bois && mine->prixAmeliorationPierre < *pierre && mine->prixAmeliorationArgent < *argent && getTailleFileDeConstruction(*fileDeConstructions) < 4){
					amelioreBatiment(mine, bois, pierre, argent, fileDeConstructions);
				}else{
					printf("Vous n'avez pas assez de ressources\n");
				}
			}
		}
		
		// Gère clic sur le bouton de la caserne
		if(x > 393 && x < calculeXFinBouton(393) && y > 404 && y < calculeYFinBouton(404)){
			if(caserne->max){
				printf("Votre caserne est déjà au niveau maximum\n");
			}else{
				if(caserne->prixAmeliorationBois < *bois && caserne->prixAmeliorationPierre < *pierre && caserne->prixAmeliorationArgent < *argent && getTailleFileDeConstruction(*fileDeConstructions) < 4){
					amelioreBatiment(caserne, bois, pierre, argent, fileDeConstructions);
				}else{
					printf("Vous n'avez pas assez de ressources\n");
				}
			}
		}
		
		// Gère clic sur le bouton du temple
		if(x > 581 && x < calculeXFinBouton(581) && y > 404 && y < calculeYFinBouton(404)){
			if(temple->max){
				printf("Votre temple est déjà au niveau maximum\n");
			}else{
				if(temple->prixAmeliorationBois < *bois && temple->prixAmeliorationPierre < *pierre && temple->prixAmeliorationArgent < *argent && getTailleFileDeConstruction(*fileDeConstructions) < 4){
					amelioreBatiment(temple, bois, pierre, argent, fileDeConstructions);
				}else{
					printf("Vous n'avez pas assez de ressources\n");
				}
			}
		}
	}
}

void actualisePopup(Popups* popups){
	popups->actuel = popups->final;
}
