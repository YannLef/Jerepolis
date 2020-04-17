#include <stdlib.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>

#include "../../GfxLib/headers/GfxLib.h" 
#include "../../GfxLib/headers/BmpLib.h"

#include "../headers/structures.h"
#include "../headers/Formulaire.h"
#include "../headers/Couleur.h"
#include "../headers/Keyboard.h"
#include "../headers/Page.h"

 /**
  * -----------------------------------------------------------
  * -------------------- 1) INITIALISATION --------------------
  * -----------------------------------------------------------
  * */

/**
 * Fonction permettant d'initialiser la page d'un programme
 * @author Yann LEFEVRE
 * */
void initPage(pages* p, page pActuel){
	p->pActuel = pActuel;
	p->pFinal = pActuel;
}

 /**
  * ---------------------------------------------------
  * -------------------- 2) UPDATE --------------------
  * ---------------------------------------------------
  * */
  
/**
 * Fonction permettant de changer de page de manière fluide ( à la fin du passage dans la boucle temporisation et non brutalement en plein traitement !)
 * @author Yann LEFEVRE
 * */
void updatePage(pages* p){
	p->pActuel = p->pFinal;
}

 /**
  * --------------------------------------------------
  * -------------------- 3) TESTS --------------------
  * --------------------------------------------------
  * */
 
/**
 * Fonction permettant de tester si la page passé en paramètre est la page actuelle
 * @author Yann LEFEVRE
 * */
bool isOnPage(pages p, page pTest){
	if(p.pActuel == pTest){
		return 1;
	}
	
	return 0;
}

/**
 * Fonction permettant de tester si la page passé en paramètre est la future page (pFinal deviendra pActuel à l'appel de la fonction updatePage)
 * @author Yann LEFEVRE
 * */
bool willBeOnPage(pages p, page pTest){
	if(p.pFinal == pTest){
		return 1;
	}
	
	return 0;
}
