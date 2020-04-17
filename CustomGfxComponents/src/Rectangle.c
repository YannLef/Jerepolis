#include <stdlib.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>

#include "../../GfxLib/headers/GfxLib.h" 
#include "../../GfxLib/headers/BmpLib.h"

#include "../headers/structures.h"
#include "../headers/Couleur.h"
#include "../headers/Keyboard.h"

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
void initRectangle(rec* rect, int x, int y, int largeur, int hauteur, int epaisseurBordure, couleur cInterieur, couleur cBordure){
	rect->x = x;
	rect->y = y;
	rect->cInterieur = cInterieur;
	rect->cBordure = cBordure;
	rect->hauteur = hauteur;
	rect->largeur = largeur;
	rect->epaisseurBordure = epaisseurBordure;
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
void afficheRectangle(rec rect, bool mobile, int xEcran, int yEcran, float coefZoom){
	epaisseurDeTrait(1);
	int x1,x2,y1,y2;
	
	// Bordure
	
	couleurCourante(rect.cBordure.r,rect.cBordure.v,rect.cBordure.b);
	// point 1 -> coin bas gauche
	// point 2 -> coin haut droit
	if(mobile){
		x1 = rect.x - (rect.largeur*coefZoom)/2;
		x2 = rect.x + (rect.largeur*coefZoom)/2;
		y1 = rect.y - (rect.hauteur*coefZoom)/2;
		y2 = rect.y + (rect.hauteur*coefZoom)/2;
	}else{
		x1 = rect.x - (rect.largeur)/2;
		x2 = rect.x + (rect.largeur)/2;
		y1 = rect.y - (rect.hauteur)/2;
		y2 = rect.y + (rect.hauteur)/2;
	}
	
	if(mobile){
		x1 += xEcran*coefZoom;
		y1 += yEcran*coefZoom;
		x2 += xEcran*coefZoom;
		y2 += yEcran*coefZoom;
	}
	
	rectangle(x1,y1,x2,y2);
	
	// Interieur
	
	couleurCourante(rect.cInterieur.r,rect.cInterieur.v,rect.cInterieur.b);
	
	// point 1 -> coin bas gauche
	// point 2 -> coin haut droit
	if(mobile){
		x1 = rect.x - (rect.largeur*coefZoom)/2 + rect.epaisseurBordure;
		x2 = rect.x + (rect.largeur*coefZoom)/2 - rect.epaisseurBordure;
		y1 = rect.y - (rect.hauteur*coefZoom)/2 + rect.epaisseurBordure;
		y2 = rect.y + (rect.hauteur*coefZoom)/2 - rect.epaisseurBordure;
	}else{
		x1 = rect.x - (rect.largeur)/2 + rect.epaisseurBordure;
		x2 = rect.x + (rect.largeur)/2 - rect.epaisseurBordure;
		y1 = rect.y - (rect.hauteur)/2 + rect.epaisseurBordure;
		y2 = rect.y + (rect.hauteur)/2 - rect.epaisseurBordure;
	}
	
	if(mobile){
		x1 += xEcran*coefZoom;
		y1 += yEcran*coefZoom;
		x2 += xEcran*coefZoom;
		y2 += yEcran*coefZoom;
	}
	
	if(coefZoom>0.5 || !mobile)
		rectangle(x1,y1,x2,y2);
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
bool isOnRectangle(int x, int y, rec rect){
	if(x > (rect.x - rect.largeur/2) && x < (rect.x + rect.largeur/2)){
		if(y > (rect.y - rect.hauteur/2) && y < (rect.y + rect.hauteur/2)){
			return 1;
		}
	}
	return 0;
}

/**
 * Fonction vérifiant si un point de coordonnée (x,y) appartient à un rectangle mobile donné
 * @author Yann LEFEVRE
 * */
bool isOnRectangleMobile(int x, int y, rec rect, int xEcran, int yEcran, float coefZoom){
	if(x > (rect.x + xEcran*coefZoom - (rect.largeur*coefZoom)/2) && x < (rect.x + xEcran*coefZoom + (rect.largeur*coefZoom)/2)){
		if(y > (rect.y + yEcran*coefZoom - (rect.hauteur*coefZoom)/2) && y < (rect.y + yEcran*coefZoom + (rect.hauteur*coefZoom)/2)){
			return 1;
		}
	}
	return 0;
}
