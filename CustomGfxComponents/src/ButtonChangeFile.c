#include <stdlib.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>

#include "../../GfxLib/headers/GfxLib.h" 
#include "../../GfxLib/headers/BmpLib.h"

#include "../headers/structures.h"
#include "../headers/Couleur.h"
#include "../headers/Rectangle.h"

#include "../headers/ButtonChangeFile.h"

 /**
  * -----------------------------------------------------------
  * -------------------- 1) INITIALISATION --------------------
  * -----------------------------------------------------------
  * */
  
/**
 * Fonction permettant d'initialiser un bouton ayant pour unique but de naviguer dans l'explorateur de fichier
 * Tous les paramètres sont spécifiques à l'affichage du bouton
 * @author Yann LEFEVRE
 * */
void initBoutonChangeFichiers(boutonChangeFichiers* b, char* string, int x, int y, int largeur, int hauteur, int epaisseurBordure, couleur cInterieur, couleur cBordure, couleur cText, int epaisseurTrait, int effet){
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
	
	b->cText = cText;
	b->epaisseurTrait = epaisseurTrait;
	b->effet = effet;
	
	b->string[k] = '\0';
	
	initRectangle(&(b->rect),x,y,largeur,hauteur,epaisseurBordure,cInterieur, cBordure);
	
}

 /**
  * ----------------------------------------------------
  * -------------------- 2) DISPLAY --------------------
  * ----------------------------------------------------
  * */

/**
 * Fonction permettant d'afficher un bouton permettant de naviguer dans l'explorateur de fichiers
 * @author Yann LEFEVRE
 * */
void afficheBoutonChangeFichiers(boutonChangeFichiers b, int xEcran, int yEcran, float coefZoom){
	afficheRectangle(b.rect,0,xEcran,yEcran,coefZoom);
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
			taille = b.rect.hauteur/(maxSize*0.5); // Calcule la taille de la police pour qu'elle s'adapte à la taille du bouton
		}else{
			taille = b.rect.largeur/(maxSize*0.7); // Calcule la taille de la police pour qu'elle s'adapte à la taille du bouton
		}
		int x = b.rect.x - tailleChaine(b.string,taille)/2;
		int y = b.rect.y - taille/3;
		afficheChaine(b.string,taille,x,y);
	}
}

 /**
  * ---------------------------------------------------
  * -------------------- 3) EVENTS --------------------
  * ---------------------------------------------------
  * */

/**
 * Fonction permettant de changer de page d'affichage de l'explorateur de fichiers en fonction du clic
 * @author Yann LEFEVRE
 * */
void gereSourisBoutonChangeFichiers(boutonChangeFichiers b, int* debutAffichageExplorateur, int nombreFichiers, int xSouris, int ySouris){
	// On vérifie que le clic est bel est bien sur le bouton
	if(xSouris > (b.rect.x - b.rect.largeur/2) && xSouris < (b.rect.x + b.rect.largeur/2)){
		if(ySouris > (b.rect.y - b.rect.hauteur/2) && ySouris < (b.rect.y + b.rect.hauteur/2)){
			if(*debutAffichageExplorateur + b.effet >= 0 && *debutAffichageExplorateur + b.effet <= nombreFichiers) // On vérifie que le premier élément qu'on demande est bien existant (dans la plage du nombre de fichiers)
				*debutAffichageExplorateur += b.effet; // On incrémente le numéro du premier élément à afficher en fonction de l'effet du bouton
		}
	}
}
