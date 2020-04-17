#include <stdlib.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include "../../GfxLib/headers/GfxLib.h" 
#include "../../GfxLib/headers/BmpLib.h"

#include "../headers/structures.h"
#include "../headers/Couleur.h"
#include "../headers/Carre.h"
#include "../headers/Checkbox.h"

 /**
  * -----------------------------------------------------------
  * -------------------- 1) INITIALISATION --------------------
  * -----------------------------------------------------------
  * */

/**
 * Fonction permettant d'initialiser une checkbox
 * @author Yann LEFEVRE
 * */
void initCheckbox(checkbox* cb, int x, int y, int cote, int epaisseurBordure, couleur cInterieur, couleur cBordure, bool etat){
	cb->etat = etat;
	initCarre(&(cb->square), x, y, cote, epaisseurBordure, cInterieur, cBordure);
}

 /**
  * ----------------------------------------------------
  * -------------------- 2) DISPLAY --------------------
  * ----------------------------------------------------
  * */

/**
 * Fonction permettant d'afficher une checkbox
 * @author Yann LEFEVRE
 * */
void afficheCheckbox(checkbox cb){
	afficheCarre(cb.square);
	
	if(cb.etat){
		epaisseurDeTrait(cb.square.epaisseurBordure);
		couleurCourante(0,0,0);
		ligne(cb.square.x - cb.square.cote/2, cb.square.y - cb.square.cote/2, cb.square.x + cb.square.cote/2, cb.square.y + cb.square.cote/2);
		ligne(cb.square.x - cb.square.cote/2, cb.square.y + cb.square.cote/2, cb.square.x + cb.square.cote/2, cb.square.y - cb.square.cote/2);
	}
}

 /**
  * ---------------------------------------------------
  * -------------------- 3) UPDATE --------------------
  * ---------------------------------------------------
  * */

/**
 * Fonction permettant de définir l'etat d'une checkbox
 * @author Yann LEFEVRE
 * */
void setEtatCheckbox(checkbox* cb, bool etat){
	cb->etat = etat;
}

/**
 * Fonction permettant de changer l'etat d'une checkbox
 * @author Yann LEFEVRE
 * */
void toggleEtatCheckbox(checkbox* cb){
	if(cb->etat){
		cb->etat = 0;
	}else{
		cb->etat = 1;
	}
}

 /**
  * ---------------------------------------------------
  * -------------------- 4) EVENTS --------------------
  * ---------------------------------------------------
  * */

/**
 * Fonction permettant de gérer le clic sur une checkbox
 * Permet de changer son état (principe même d'une checkbox)
 * @author Yann LEFEVRE
 * */
void gereClicCheckbox(checkbox* cb, int xSouris, int ySouris){
	if(isOnCarre(xSouris,ySouris,cb->square)){
		toggleEtatCheckbox(cb);
	}
}
