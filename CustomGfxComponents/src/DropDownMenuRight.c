#include <stdlib.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>

#include "../../GfxLib/headers/GfxLib.h" 
#include "../../GfxLib/headers/BmpLib.h"

#include "../headers/structures.h"
#include "../headers/Couleur.h"
#include "../headers/Page.h"
#include "../headers/Rectangle.h"

#include "../headers/DropDownMenuRight.h"

extern couleurTab c; // Synchronise le tableau de couleurs

 /**
  * -----------------------------------------------------------
  * -------------------- 1) INITIALISATION --------------------
  * -----------------------------------------------------------
  * */
  
/**
 * Fonction permettant d'initialiser un menu déroulant se déroulant de la gauche vers la droite
 * @author Yann LEFEVRE
 * */
void initMenuDeroulantVersDroite(menuDeroulantVersDroite* menu, int yBas, int yHaut, int xGauche, int xDroite, bool etat){
	// Générales, ne changent pas
	menu->yBas = yBas;
	menu->yHaut = yHaut;
	menu->xGauche = xGauche;
	menu->xDroite = xDroite;
	menu->etat = etat;
	
	// En cours
	if(etat == 0){
		menu->xActuel = xGauche;
		menu->xFinal = xGauche;
	}else{
		menu->xActuel = xDroite;
		menu->xFinal = xDroite;
	}
}
  
 /**
  * ----------------------------------------------------
  * -------------------- 2) DISPLAY --------------------
  * ----------------------------------------------------
  * */
  
/**
 * Fonction affichant un menu déroulant se déroulant de la gauche vers la droite
 * @author Yann LEFEVRE
 * */
void afficheMenuDeroulantVersDroite(menuDeroulantVersDroite* menu, int xEcran, int yEcran, float coefZoom){
	
	for(int i=0; i<25;i++){ // For permettant d'accélérer le déplacement du menu de 18 fois (tout en passant dans les tests et donc sans débordements contrairement à une incrémentation de 18 d'un coup)
		if(menu->xActuel < menu->xFinal){ // Si la taille actuelle est plus petite que la taille finale visée on augmente celle ci
			menu->xActuel ++;
		}else if(menu->xActuel > menu->xFinal){ // Si la taille actuelle est plus grande que la taille finale visée, on diminue celle ci
			menu->xActuel --;
		}
	}
	
	// On affiche le rectangle correspondant
	rec r;
	initRectangle(&r,(menu->xActuel)/2,(menu->yHaut-menu->yBas)/2,menu->xActuel,hauteurFenetre(),0,c.couleurMenuDeroulant,c.couleurFemme);
	afficheRectangle(r,0,xEcran,yEcran,coefZoom);
	
	// On détermine l'état du menu déroulant (ouvert totalement ou non)
	if(menu->xActuel == menu->xDroite){
		menu->etat = 1;
	}else{
		menu->etat = 0;
	}

}

/**
 * Fonction permettant d'afficher le contenu d'un onglet si celui ci est selectionné et entièrement ouvert
 * @author Yann LEFEVRE
 * */
void afficheDetailMenu(int nav[10], pages p, menuDeroulantVersDroite* menuDeroulant){
	if (nav[0] == 1 && menuDeroulant->xActuel == menuDeroulant->xFinal && isOnPage(p,arbre)){ // Si l'onglet actuel est le numéro 0 et que le menu est entièrement ouvert
	
	}else if (nav[7] == 1 && menuDeroulant->xActuel == menuDeroulant->xFinal && isOnPage(p,arbre)){
		
	}else if (nav[5] == 1 && menuDeroulant->xActuel == menuDeroulant->xFinal && isOnPage(p,arbre)){

	}else if (nav[6] == 1 && menuDeroulant->xActuel == menuDeroulant->xFinal && isOnPage(p,arbre)) {
		
	}else if (nav[1] == 1 && menuDeroulant->xActuel == menuDeroulant->xFinal && isOnPage(p,arbre)){

	}else if  (nav[3] == 1 && menuDeroulant->xActuel == menuDeroulant->xFinal && isOnPage(p,arbre)){
			
	}else if (nav[9] == 1 && menuDeroulant->xActuel == menuDeroulant->xFinal && isOnPage(p,arbre)){
		
	}
}
  
 /**
  * --------------------------------------------------
  * -------------------- 3) UPDATE --------------------
  * --------------------------------------------------
  * */

/**
 * Fonction envoyant un signal d'extension à menu déroulant se déroulant de la gauche vers la droite
 * @author Yann LEFEVRE
 * */
void agrandiMenuDeroulantVersDroite(menuDeroulantVersDroite* menu){
	menu->xFinal = menu->xDroite; // Définit l'objectif à atteindre en x à droite.
}

/**
 * Fonction envoyant un signal de repli à un menu déroulant se déroulant de la gauche vers la droite
 * @author Yann LEFEVRE
 * */
void reduiMenuDeroulantVersDroite(menuDeroulantVersDroite* menu){
	menu->xFinal = menu->xGauche; // Définit l'objectif à atteindre en x à gauche.
}

 /**
  * ---------------------------------------------------
  * -------------------- 4) EVENTS --------------------
  * ---------------------------------------------------
  * */

/**
 * Fonction permettant de réguler quand ouvrir ou fermer le menu déroulant
 * -> Cas classique : si tous les onglets sont fermés et qu'on clique sur l'un deux, le menu s'ouvre. Si on reclique sur le même, le menu se referme. 
 * En revanche si on clique sur un autre onglet, le menu reste ouvert (pour ne pas le fermer pour le réouvrir)
 * @author Yann LEFEVRE
 * */
void gereMenuDeroulantVersDroite(int nav[10], menuDeroulantVersDroite* menuDeroulant){
	int tmp=0; // variable temporaire permettant de savoir si un onglet est ouvert ou non.
	int tmp2=-1; // variable permettant de savoir quel est le numéro de l'onglet ouvert
	
	for(int i=0;i<10;i++){ // On boucle pour testser facilement les 9 onglets / boutons
		if(nav[i]==1){ // Si l'onglet est ouvert, on passe la variable temporaire à 1
			tmp=1;
			tmp2=i; // on stock le numéro de l'onglet ouvert
		}
	}
	
	if(tmp==0){ // Si la variable temporaire n'a pas été passé à 1, alors aucuns onglets n'est ouverts alors on demande la fermeture du menu (si il est déjà fermé il ne se passera rien)
		reduiMenuDeroulantVersDroite(menuDeroulant);
	}else{ // En revanche si la variable temporaire a été passé à 1, on demande l'ouverture du menu (si il est déjà ouvert rien ne se passera)
		switch(tmp2){ // En fonction de quel onglet est ouvert, on agit différemment
			case 0:
				menuDeroulant->xFinal = menuDeroulant->xDroite; // On agrandi le menu jusqu'à sa valeur par défaut
				break;
			
			case 1:
				menuDeroulant->xFinal = menuDeroulant->xDroite; // On agrandi le menu jusqu'à sa valeur par défaut
				break;
			
			case 2: // Rien car save = pas de menu qui s'ouvre
				break;
			
			case 3:
				menuDeroulant->xFinal = menuDeroulant->xDroite; // On agrandi le menu jusqu'à sa valeur par défaut
				break;
			
			case 4:
				// On n'ouvre aps le menu car ce bouton est le bouton arbre
				break;
			
			case 5:
				menuDeroulant->xFinal = menuDeroulant->xDroite; // On agrandi le menu jusqu'à sa valeur par défaut
				break;
			
			case 6:
				menuDeroulant->xFinal = menuDeroulant->xDroite; // On agrandi le menu jusqu'à sa valeur par défaut
				break;
			
			case 7:
				menuDeroulant->xFinal = menuDeroulant->xDroite; // On agrandi le menu jusqu'à sa valeur par défaut
				break;
			
			case 8:
				// On n'ouvre pas le menu car ce bouton est la croix et ne correspond à aucun onglet : il permet de revenir à la page précédente	
			break;
			
			case 9: // Si l'onglet ouvert est le 8 (paramètres), on veut que le menu s'affiche en plein écran
				menuDeroulant->xFinal = largeurFenetre(); // On agrandi le menu jusqu'au bout de la fenêtre (car onglet paramètre)
			break;
			
		}
	}	
}
