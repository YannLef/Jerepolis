/**
 * Includes Classiques
 * */
#include <stdlib.h> 
#include <stdio.h> 
#include <math.h> 
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
#include "../headers/structures.h"
#include "../headers/Couleur.h"
#include "../headers/Carre.h"

/**
 * Includes correspondant
 * */
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
	debug("<initCheckbox> begin");
	
	cb->etat = etat;
	initCarre(&(cb->square), x, y, cote, epaisseurBordure, cInterieur, cBordure);
	
	debug("<initCheckbox> end");
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
	debug("<afficheCheckbox> begin");
	
	afficheCarre(cb.square);
	
	if(cb.etat){
		epaisseurDeTrait(cb.square.epaisseurBordure);
		couleurCourante(0,0,0);
		ligne(cb.square.x - cb.square.cote/2, cb.square.y - cb.square.cote/2, cb.square.x + cb.square.cote/2, cb.square.y + cb.square.cote/2);
		ligne(cb.square.x - cb.square.cote/2, cb.square.y + cb.square.cote/2, cb.square.x + cb.square.cote/2, cb.square.y - cb.square.cote/2);
	}
	
	debug("<afficheCheckbox> end");
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
	debug("<setEtatCheckbox> begin");
	
	cb->etat = etat;
	
	debug("<setEtatCheckbox> end");
}

/**
 * Fonction permettant de changer l'etat d'une checkbox
 * @author Yann LEFEVRE
 * */
void toggleEtatCheckbox(checkbox* cb){
	debug("<toggleEtatCheckbox> begin");
	
	if(cb->etat){
		cb->etat = 0;
	}else{
		cb->etat = 1;
	}
	
	debug("<toggleEtatCheckbox> end");
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
	debug("<gereClicCheckbox> begin");
	
	if(isOnCarre(xSouris,ySouris,cb->square)){
		toggleEtatCheckbox(cb);
	}
	
	debug("<gereClicCheckbox> end");
}
