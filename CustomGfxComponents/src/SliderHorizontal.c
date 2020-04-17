#include <stdlib.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>

#include "../../GfxLib/headers/GfxLib.h" 
#include "../../GfxLib/headers/BmpLib.h"

#include "../headers/structures.h"
#include "../headers/Couleur.h"
#include "../headers/Mouse.h"
#include "../headers/Page.h"
#include "../headers/SliderHorizontal.h"

extern mouse souris;

 /**
  * -----------------------------------------------------------
  * -------------------- 1) INITIALISATION --------------------
  * -----------------------------------------------------------
  * */

/**
 * Fonction permettant d'initialiser un slider horizontal
 * @author Yann LEFEVRE
 * */
void initSliderHorizontal(sliderHorizontal* sli, int x, int y, int largeur, int epaisseurLigne, int epaisseurPointeur, couleur cLigne, couleur cPointeur, int min, int max, int* var){
	
	sli->x = x;
	sli->y = y;
	sli->largeur = largeur;
	sli->epaisseurLigne = epaisseurLigne;
	sli->epaisseurPointeur = epaisseurPointeur;
	sli->cLigne = cLigne;
	sli->cPointeur = cPointeur;
	sli->min = min;
	sli->max = max;
	sli->var = var; // Le pointeur vers la variable que fait évoluer le slider
	
}

 /**
  * ----------------------------------------------------
  * -------------------- 2) DISPLAY --------------------
  * ----------------------------------------------------
  * */

/**
 * Fonction permettant d'afficher un slider horizontal
 * @author Yann LEFEVRE
 * */
void afficheSliderHorizontal(sliderHorizontal sli){
	// Partie ligne
	epaisseurDeTrait(sli.epaisseurLigne);
	changeColor(sli.cLigne);
	ligne(sli.x-sli.largeur/2,sli.y,sli.x+sli.largeur/2,sli.y);
	
	// Partie pointeur
	int tailleTotale = sli.largeur;
	int plageTotale = sli.max - sli.min;
	
	// On fait un produit scalaire pour transformer la valeur en avancement de la barre
	int posX=0;
		posX = (*(sli.var))*tailleTotale/plageTotale;
	// On trace le point 
	epaisseurDeTrait(sli.epaisseurPointeur);
	changeColor(sli.cPointeur);
	point(sli.x - sli.largeur/2 + posX,sli.y);
}

 /**
  * ---------------------------------------------------
  * -------------------- 3) EVENTS --------------------
  * ---------------------------------------------------
  * */

/**
 * Fonction permettant de faire varier la valeur du slider horizontal en fonction du déplacement de la souris
 * @author Yann LEFEVRE
 * */
void gereClicSliderHorizontal(sliderHorizontal* sli, int xSouris, int ySouris){
	if(mouseLeftIsDown()){
		if(xSouris >= sli->x - sli->largeur/2){
			if(xSouris <= sli->x + sli->largeur/2){
				if(ySouris >= sli->y - 10 && ySouris <= sli->y + 10){
					float posX =  xSouris - sli->x + sli->largeur/2;
					float tailleTotale = sli->largeur;
					float plageTotale = sli->max - sli->min;
					*(sli->var) = posX*plageTotale/tailleTotale + 0.5;
					
				}
			}else if(xSouris <= sli->x - 10 + sli->largeur/2){
				*(sli->var) = sli->max;
			}
		}else if(xSouris >= sli->x + 10 - sli->largeur/2){
			*(sli->var) = sli->min;
		}
	}
}
