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
#include "../headers/SliderVertical.h"

extern mouse souris;

 /**
  * -----------------------------------------------------------
  * -------------------- 1) INITIALISATION --------------------
  * -----------------------------------------------------------
  * */
  
/**
 * Fonction permettant d'initialiser un slider vertical
 * @author Yann LEFEVRE
 * */
void initSliderVertical(sliderVertical* sli, int x, int y, int hauteur, int epaisseurLigne, int epaisseurPointeur, couleur cLigne, couleur cPointeur, int min, int max, int* var){
	
	sli->x = x;
	sli->y = y;
	sli->hauteur = hauteur;
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
 * Fonction permettant d'afficher un slider vertical
 * @author Yann LEFEVRE
 * */
void afficheSliderVertical(sliderVertical sli){
	// Partie ligne
	epaisseurDeTrait(sli.epaisseurLigne);
	changeColor(sli.cLigne);
	ligne(sli.x,sli.y-sli.hauteur/2,sli.x,sli.y+sli.hauteur/2);
	
	// Partie pointeur
	int tailleTotale = sli.hauteur;
	int plageTotale = sli.max - sli.min;
	
	// On fait un produit scalaire pour transformer la valeur en avancement de la barre
	int posY=0;
		posY = (*(sli.var) - sli.min )*tailleTotale/plageTotale;
	// On trace le point 
	epaisseurDeTrait(sli.epaisseurPointeur);
	changeColor(sli.cPointeur);
	point(sli.x,sli.y - sli.hauteur/2 + posY);
}

 /**
  * ---------------------------------------------------
  * -------------------- 3) EVENTS --------------------
  * ---------------------------------------------------
  * */

/**
 * Fonction permettant de faire varier la valeur du slider vertical en fonction du déplacement de la souris
 * @author Yann LEFEVRE
 * */
void gereClicSliderVertical(sliderVertical* sli, int xSouris, int ySouris){
	if(mouseLeftIsDown()){
		if(ySouris >= sli->y - sli->hauteur/2){
			if(ySouris <= sli->y + sli->hauteur/2){
				if(xSouris >= sli->x - 10 && xSouris <= sli->x + 10){
					float posY =  ySouris - (sli->y - sli->hauteur/2);
					float tailleTotale = sli->hauteur;
					float plageTotale = sli->max - sli->min;
					*(sli->var) = sli->min + posY*plageTotale/tailleTotale;
				}
			}else if(ySouris <= sli->y - 10 + sli->hauteur/2){
				*(sli->var) = sli->max;
			}
		}else if(ySouris >= sli->y + 10 - sli->hauteur/2){
			*(sli->var) = sli->min;
		}
	}
}
