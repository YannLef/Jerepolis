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
#include "../headers/Page.h"
#include "../headers/Formulaire.h"
#include "../headers/DropDownMenuRight.h"
#include "../headers/InputText.h"

/**
 * Includes correspondant
 * */
#include "../headers/Navbar.h"

 /**
  * -----------------------------------------------------------
  * -------------------- 1) INITIALISATION --------------------
  * -----------------------------------------------------------
  * */

void initNavbar(int nav[10]){
	debug("<initNavbar> begin");
	
	for(int i=0;i<10;i++){
		nav[i] = 0;
	}
	
	debug("<initNavbar> end");
}

 /**
  * --------------------------------------------------------
  * -------------------- 2) MISE A JOUR --------------------
  * --------------------------------------------------------
  * */

void actualiseNavbar(int nbBouton, int nav[10]){
	debug("<actualiseNavbar> begin");
	
	switch(nbBouton){
		case 0:
		break;
		
		case 1:
		break;
		
		case 2:
		break;
		
		case 3:
		break;
		
		case 4:
		break;
		
		case 5:
		break;
		
		case 6:
		break;
		
		case 7:
		break;
		
		case 8:
		break;
		
		case 9:
		break;
	}
	
	debug("<actualiseNavbar> end");
}

 /**
  * -------------------------------------------------------
  * -------------------- 3) EVENEMENTS --------------------
  * -------------------------------------------------------
  * */

void gereSourisNavbar(int xSouris, int ySouris, int nav[10]){
	debug("<gereSourisNavbar> begin");
	
	if(xSouris >= 0 && xSouris <= 70){ // Si le x du clic se trouve entre 0 et 70, il est bien dans la zone de la navbar
		for(int i=0; i<8; i++){ // En partant du haut on a 7 boutons de chacun 70 px de haut, pour chacuns d'eux on vérifie si le clic à lieu dessus
			if(ySouris < hauteurFenetre() - 70*i && ySouris > hauteurFenetre() - 70*i - 70){
				actualiseNavbar(i, nav); // On appelle la fonction qui gère les actions en indiquant l'indice du bouton cliqué
			}
		}
		
		for(int i=0; i<2; i++){ // En partant du bas on a 2 boutons de hacun 70 px de bas, on vérifie si ils sont cliqués
			if(ySouris > 70*i && ySouris < 70*i + 70){
				actualiseNavbar(9-i, nav); // On appelle la fonction qui gère les actions en indiquant l'indice du bouton cliqué
			}
		}
	}
	
	debug("<gereSourisNavbar> end");
}

