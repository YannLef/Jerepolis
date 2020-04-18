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
#include "../headers/Formulaire.h"
#include "../headers/Couleur.h"
#include "../headers/Keyboard.h"

/**
 * Includes correspondant
 * */
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
	debug("<initPage> begin");
	
	p->pActuel = pActuel;
	p->pFinal = pActuel;
	
	debug("<initPage> end");
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
	debug("<updatePage> begin");
	
	p->pActuel = p->pFinal;
	
	debug("<updatePage> end");
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
	debug("<isOnPage> begin");
	
	if(p.pActuel == pTest){
		debug("<isOnPage> end : return 1");
		return 1;
	}
	
	debug("<isOnPage> end : return 0");
	return 0;
}

/**
 * Fonction permettant de tester si la page passé en paramètre est la future page (pFinal deviendra pActuel à l'appel de la fonction updatePage)
 * @author Yann LEFEVRE
 * */
bool willBeOnPage(pages p, page pTest){
	debug("<willBeOnPage> begin");
	
	if(p.pFinal == pTest){
		debug("<willBeOnPage> end : return 1");
		return 1;
	}
	
	debug("<willBeOnPage> end : return 0");
	return 0;
}
