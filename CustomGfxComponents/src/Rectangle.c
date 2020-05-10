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
#include "../headers/Keyboard.h"

/**
 * Includes correspondant
 * */
#include "../headers/Rectangle.h"

 /**
  * -----------------------------------------------------------
  * -------------------- 1) INITIALISATION --------------------
  * -----------------------------------------------------------
  * */
  
/**
 * Initialise un rectangle "rect", nécessite de nombreux paramètres pour être le plus complet possible
 * @author Yann LEFEVRE
 * */
void initRectangle(Rec* rect, int x, int y, int largeur, int hauteur, int epaisseurBordure, Couleur cInterieur, Couleur cBordure){
	debug("<initRectangle> begin");
	
	rect->x = x;
	rect->y = y;
	rect->cInterieur = cInterieur;
	rect->cBordure = cBordure;
	rect->hauteur = hauteur;
	rect->largeur = largeur;
	rect->epaisseurBordure = epaisseurBordure;
	
	debug("<initRectangle> end");
}
  
 /**
  * ----------------------------------------------------
  * -------------------- 2) DISPLAY --------------------
  * ----------------------------------------------------
  * */
  
/**
 * Affiche un rectangle "rect" à partir de ses valeurs
 * Il y a différents résultats en fonction de si le rectangle doit être mobile ou non
 * mobile=1 : il évolue en fonction du zoom et des déplacements de l'utilisateur
 * mobile=0 : la position du rectangle est fixe quoi qu'il arrive
 * @author Yann LEFEVRE
 * */
void afficheRectangle(Rec rect){
	debug("<afficheRectangle> begin");
	
	epaisseurDeTrait(1);
	int x1,x2,y1,y2;
	
	// Bordure
	
	couleurCourante(rect.cBordure.r,rect.cBordure.v,rect.cBordure.b);
	// point 1 -> coin bas gauche
	// point 2 -> coin haut droit

		x1 = rect.x - (rect.largeur)/2;
		x2 = rect.x + (rect.largeur)/2;
		y1 = rect.y - (rect.hauteur)/2;
		y2 = rect.y + (rect.hauteur)/2;
	
	if(rect.cBordure.r != -1){
		rectangle(x1,y1,x2,y2);	
	}
	
	// Interieur
	
	couleurCourante(rect.cInterieur.r,rect.cInterieur.v,rect.cInterieur.b);
	
	// point 1 -> coin bas gauche
	// point 2 -> coin haut droit

		x1 = rect.x - (rect.largeur)/2 + rect.epaisseurBordure;
		x2 = rect.x + (rect.largeur)/2 - rect.epaisseurBordure;
		y1 = rect.y - (rect.hauteur)/2 + rect.epaisseurBordure;
		y2 = rect.y + (rect.hauteur)/2 - rect.epaisseurBordure;
		
	if(rect.cInterieur.r != -1){
		rectangle(x1,y1,x2,y2);	
	}
		
	debug("<afficheRectangle> end");
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
bool isOnRectangle(int x, int y, Rec rect){
	debug("<isOnRectangle> begin");
	
	if(x > (rect.x - rect.largeur/2) && x < (rect.x + rect.largeur/2)){
		if(y > (rect.y - rect.hauteur/2) && y < (rect.y + rect.hauteur/2)){
			debug("<isOnRectangle> end : return 1");
			return 1;
		}
	}
	
	debug("<isOnRectangle> end : return 0");
	return 0;
}
