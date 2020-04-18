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

/**
 * Includes correspondant
 * */
#include "../headers/Carre.h"

 /**
  * -----------------------------------------------------------
  * -------------------- 1) INITIALISATION --------------------
  * -----------------------------------------------------------
  * */
  
/**
 * Initialise un carre , nécessite de nombreux paramètres pour être le plus complet possible
 * @param square le pointeur vers le carré à initialiser
 * @param x l'abscisse du centre du carré
 * @param y l'odronnée du centre du carré
 * @param cote la taille du côté du carré
 * @param epaisseurBordure l'épaisseur de trait du carré
 * @param cInterieur la couleure intérieure du carré
 * @param cBordure la couleur des contours du carré
 * @author Yann LEFEVRE
 * */
void initCarre(carre* square, int x, int y, int cote, int epaisseurBordure, couleur cInterieur, couleur cBordure){
	debug("<initCarre> begin");
	
	square->x = x;
	square->y = y;
	square->cInterieur = cInterieur;
	square->cBordure = cBordure;
	square->cote = cote;
	square->epaisseurBordure = epaisseurBordure;
	
	debug("<initCarre> end");
}
  
 /**
  * ----------------------------------------------------
  * -------------------- 2) DISPLAY --------------------
  * ----------------------------------------------------
  * */
  
/**
 * Affiche un carre à partir de ses valeurs
 * @author Yann LEFEVRE
 * */
void afficheCarre(carre square){
	debug("<afficheCarre> begin");
	
	epaisseurDeTrait(1);
	int x1,x2,y1,y2;
	
	// Bordure
	
	changeColor(square.cBordure);
	// point 1 -> coin bas gauche
	// point 2 -> coin haut droit

	x1 = square.x - (square.cote)/2;
	x2 = square.x + (square.cote)/2;
	y1 = square.y - (square.cote)/2;
	y2 = square.y + (square.cote)/2;
	
	rectangle(x1,y1,x2,y2);
	
	// Interieur
	
	changeColor(square.cInterieur);
	
	// point 1 -> coin bas gauche
	// point 2 -> coin haut droit
	x1 = square.x - (square.cote)/2 + square.epaisseurBordure;
	x2 = square.x + (square.cote)/2 - square.epaisseurBordure;
	y1 = square.y - (square.cote)/2 + square.epaisseurBordure;
	y2 = square.y + (square.cote)/2 - square.epaisseurBordure;
	
	rectangle(x1,y1,x2,y2);
	
	debug("<afficheCarre> end");
}

 /**
  * --------------------------------------------------
  * -------------------- 3) TESTS --------------------
  * --------------------------------------------------
  * */
  
/**
 * Fonction vérifiant si un point de coordonnée (x,y) appartient à un rectangle donné
 * @author Yann LEFEVRE
 * */
bool isOnCarre(int x, int y, carre square){
	debug("<isOnCarre> begin");
	
	if(x > (square.x - square.cote/2) && x < (square.x + square.cote/2)){
		if(y > (square.y - square.cote/2) && y < (square.y + square.cote/2)){
			debug("<isOnCarre> end : return 1");
			return 1;
		}
	}
	
	debug("<isOnCarre> end : return 0");
	return 0;
}
