#include <stdlib.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>

#include "../../GfxLib/headers/GfxLib.h" 
#include "../../GfxLib/headers/BmpLib.h"

#include "../headers/structures.h"
#include "../headers/Couleur.h"
#include "../headers/Keyboard.h"
#include "../headers/Page.h"
#include "../headers/Formulaire.h"
#include "../headers/DropDownMenuRight.h"
#include "../headers/Navbar.h"
#include "../headers/InputText.h"

 /**
  * -----------------------------------------------------------
  * -------------------- 1) INITIALISATION --------------------
  * -----------------------------------------------------------
  * */
  
/**
 * Fonction permettant d'initialiser la Navbar
 * -> c'est un tableau de 9 entiers correspondants aux 9 boutons de la Navbar
 * @author Yann LEFEVRE
 * */
void initNavbar(int nav[10]){
	for(int i=0;i<10;i++){
		nav[i] = 0;
	}
}

 /**
  * ---------------------------------------------------
  * -------------------- 2) UPDATE --------------------
  * ---------------------------------------------------
  * */
  
/**
 * Fonction transformant les clics sur la Navbar en actions concrètes
 * @author Yann LEFEVRE
 * */
void actualiseNavbar(int nbBouton, int nav[10]){
	
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
}

 /**
  * ---------------------------------------------------
  * -------------------- 3) EVENTS --------------------
  * ---------------------------------------------------
  * */

/**
 * Fonction permettant de gérer les clics sur la Navbar
 * Appelle une fonction qui gère les clics en fonction du bouton cliqué dans la navbar
 * @author Yann LEFEVRE
 * */
void gereSourisNavbar(int xSouris, int ySouris, int nav[10]){
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
}

