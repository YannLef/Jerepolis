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

void initCheckbox(Checkbox* cb, int x, int y, int cote, int epaisseurBordure, Couleur cInterieur, Couleur cBordure, bool etat){
	debug("<initCheckbox> begin");
	
	cb->etat = etat;
	initCarre(&(cb->square), x, y, cote, epaisseurBordure, cInterieur, cBordure);
	
	debug("<initCheckbox> end");
}

 /**
  * ------------------------------------------------------
  * -------------------- 2) AFFICHAGE --------------------
  * ------------------------------------------------------
  * */

void afficheCheckbox(Checkbox cb){
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
  * --------------------------------------------------------
  * -------------------- 3) MISE A JOUR --------------------
  * --------------------------------------------------------
  * */

void setEtatCheckbox(Checkbox* cb, bool etat){
	debug("<setEtatCheckbox> begin");
	
	cb->etat = etat;
	
	debug("<setEtatCheckbox> end");
}

void toggleEtatCheckbox(Checkbox* cb){
	debug("<toggleEtatCheckbox> begin");
	
	if(cb->etat){
		cb->etat = 0;
	}else{
		cb->etat = 1;
	}
	
	debug("<toggleEtatCheckbox> end");
}

 /**
  * -------------------------------------------------------
  * -------------------- 4) EVENEMENTS --------------------
  * -------------------------------------------------------
  * */

void gereClicCheckbox(Checkbox* cb, int xSouris, int ySouris){
	debug("<gereClicCheckbox> begin");
	
	if(isOnCarre(xSouris,ySouris,cb->square)){
		toggleEtatCheckbox(cb);
	}
	
	debug("<gereClicCheckbox> end");
}
