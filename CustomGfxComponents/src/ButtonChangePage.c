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
#include "../headers/Page.h"
#include "../headers/Rectangle.h"

/**
 * Includes correspondant
 * */
#include "../headers/ButtonChangePage.h"

 /**
  * -----------------------------------------------------------
  * -------------------- 1) INITIALISATION --------------------
  * -----------------------------------------------------------
  * */
  
/**
 * Fonction permettant d'initialiser un bouton ayant pour unique but de changer de page d'affichage
 * Tous les paramètres sont spécifiques à l'affichage du bouton, excepté la page qui doit correspondre à la page sur laquelle on sera rediriger après le clic
 * @author Yann LEFEVRE
 * */
void initBoutonChangePage(BoutonChangePage* b, char* string, int x, int y, int largeur, int hauteur, int epaisseurBordure, Couleur cInterieur, Couleur cBordure, Couleur cText, int epaisseurTrait, Page pageSuivante){
	debug("<initBoutonChangePage> begin");
	
	int i=0;
	int taille=1;
	while(string[i] != '\0'){
		taille++;
		i++;
	}
	
	b->string = malloc(sizeof(char)*taille);
	
	int k=0;
	for(k=0;k<taille-1;k++){
		b->string[k] = string[k];
	}
	
	b->pageSuivante = pageSuivante;
	b->cText = cText;
	b->epaisseurTrait = epaisseurTrait;
	
	b->string[k] = '\0';
	
	initRectangle(&(b->rect),x,y,largeur,hauteur,epaisseurBordure,cInterieur, cBordure);
	
	debug("<initBoutonChangePage> end");
}

 /**
  * ----------------------------------------------------
  * -------------------- 2) DISPLAY --------------------
  * ----------------------------------------------------
  * */
  
/**
 * Fonction permettant d'afficher un bouton permettant de changer de page
 * @author Yann LEFEVRE
 * */
void afficheBoutonChangePage(BoutonChangePage b){
	debug("<afficheBoutonChangePage> begin");
	
	afficheRectangle(b.rect);
	if(b.string != NULL){
		couleurCourante(b.cText.r,b.cText.v,b.cText.b);
		epaisseurDeTrait(b.epaisseurTrait);
		
		int i=0; // compteur
		int maxSize=1; // On calcule la taille maximum de la chaîne
		while(b.string[i] != '\0'){
			maxSize++;
			i++;
		}
	
		float taille;
		
		if(b.rect.largeur > b.rect.hauteur){
			taille = b.rect.hauteur/(maxSize*0.3); // Calcule la taille de la police pour qu'elle s'adapte à la taille du bouton
		}else{
			taille = b.rect.largeur/(maxSize*0.7); // Calcule la taille de la police pour qu'elle s'adapte à la taille du bouton
		}
		int x = b.rect.x - tailleChaine(b.string,taille)/2;
		int y = b.rect.y - taille/3;
		afficheChaine(b.string,taille,x,y);
	}
	
	debug("<afficheBoutonChangePage> end");
}

 /**
  * ---------------------------------------------------
  * -------------------- 3) EVENTS --------------------
  * ---------------------------------------------------
  * */
  
/**
 * Fonction permettant de changer de page d'affichage en fonction du clic sur un bouton
 * @author Yann LEFEVRE
 * */
void gereSourisBoutonChangePage(BoutonChangePage b, Pages* pActuel, int xSouris, int ySouris){
	debug("<gereSourisBoutonChangePage> begin");
	
	if(pActuel->pActuel == pActuel->pFinal){ // On vérifie que la page n'a pas été modifié par d'autres fonctions
		// On vérifie que le clic est bel est bien sur le bouton
		if(xSouris > (b.rect.x - b.rect.largeur/2) && xSouris < (b.rect.x + b.rect.largeur/2)){
			if(ySouris > (b.rect.y - b.rect.hauteur/2) && ySouris < (b.rect.y + b.rect.hauteur/2)){
				pActuel->pFinal = b.pageSuivante; // On ordonne le changement de page, mais celui-ci ne sera affecté qu'au passage dans la fonction updatePage (pour éviter de fausser les prochains appels de fonction)
			}
		}
	}
	
	debug("<gereSourisBoutonChangePage> end");
}
