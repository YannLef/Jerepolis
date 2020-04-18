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
#include "../headers/Carre.h"
#include "../headers/Checkbox.h"

/**
 * Includes correspondant
 * */
#include "../headers/RadioButton.h"

 /**
  * -----------------------------------------------------------
  * -------------------- 1) INITIALISATION --------------------
  * -----------------------------------------------------------
  * */

/**
 * Fonction permettant d'initialiser un radiobutton
 * @author Yann LEFEVRE
 * @param on Le numéro de la case à cocher par défaut
 * @param nb le nombre de cases 
 * */
void initRadioButton(radiobutton* rb, char* type, int x, int y, int cote, int epaisseurBordure, couleur cInterieur, couleur cBordure, int nb, int on){
	debug("<initRadioButton> begin");
	
	rb->nb = nb;
	rb->cases = NULL;
	rb->on = on;
	
	if(nb>0){
		rb->cases = malloc(sizeof(checkbox)*nb);
	}
	
	if(strcmp(type,"vertical") == 0){ // Si le radiobutton est de type vertical
		for(int i=0;i<nb;i++){
			if(i == on){
				initCheckbox(&(rb->cases[i]), x, y-(cote*((nb*2)-2))/2 + 2*i*cote, cote, epaisseurBordure, cInterieur, cBordure, 1);
			}else{
				initCheckbox(&(rb->cases[i]), x, y-(cote*((nb*2)-2))/2 + 2*i*cote, cote, epaisseurBordure, cInterieur, cBordure, 0);
			}
		}
	}else{
		for(int i=0;i<nb;i++){
			if(i == on){
				initCheckbox(&(rb->cases[i]), x-(cote*((nb*2)-2))/2 + 2*i*cote, y, cote, epaisseurBordure, cInterieur, cBordure, 1);
			}else{
				initCheckbox(&(rb->cases[i]), x-(cote*((nb*2)-2))/2 + 2*i*cote, y, cote, epaisseurBordure, cInterieur, cBordure, 0);
			}
		}
	}
	
	debug("<initRadioButton> end");
}

/**
  * ----------------------------------------------------
  * -------------------- 2) DISPLAY --------------------
  * ----------------------------------------------------
  * */

/**
 * Fonction permettant d'afficher un radiobutton
 * @author Yann LEFEVRE
 * @param rb le radiobutton en question
 * */
void afficheRadioButton(radiobutton rb){
	debug("<afficheRadioButton> begin");
	
	for(int i=0;i<rb.nb;i++){
		afficheCheckbox(rb.cases[i]);
	}
	
	debug("<afficheRadioButton> end");
}

 /**
  * ---------------------------------------------------
  * -------------------- 3) UPDATE --------------------
  * ---------------------------------------------------
  * */

/**
 * Fonction permettant de mettre à jour le radiobutton en fonction de la valeur assignée au membre "on" de la structure (n° de case sélectionnée)
 * @author Yann LEFEVRE
 * @param rb le radiobutton en question
 * */
void updateRadioButton(radiobutton* rb){
	debug("<updateRadioButton> begin");
	
	for(int i=0;i<rb->nb;i++){
		if(rb->on != -1){ // Si la valeur de on n'est pas -1
			if(rb->on == i){ // Si la valeur de on est égale à la checkbox actuelle, on passe son état à 1
				setEtatCheckbox(&(rb->cases[i]), 1);
			}else{
				setEtatCheckbox(&(rb->cases[i]), 0); // sinon on passe son état à 0
			}
		}else{ // si on = -1, aucune case n'est selectionnée, on passe donc tous les états à 0
			setEtatCheckbox(&(rb->cases[i]), 0);
		}
	}
	
	debug("<updateRadioButton> end");
}

 /**
  * ---------------------------------------------------
  * -------------------- 4) EVENTS --------------------
  * ---------------------------------------------------
  * */

/**
 * Fonction permettant de gérer le clic sur un radiobutton
 * Permet de changer la case sélectionnée
 * @author Yann LEFEVRE
 * @param rb l'adresse du radiobutton en question
 * @param xSouris l'abscisse du clic souris
 * @param ySouris l'ordonnée du clic souris
 * */
void gereClicRadioButton(radiobutton* rb, int xSouris, int ySouris){
	debug("<gereClicRadioButton> begin");
	
	for(int i=0;i<rb->nb;i++){
		if(isOnCarre(xSouris,ySouris,(rb->cases[i]).square)){
			if((rb->cases[i]).etat){ // Si on clique sur une case déjà activée, on la désactive et plus aucunes cases n'est activée
				rb->on = -1;
			}else{ // Si on clique sur une case non activée, elle devient la nouvelle case active
				rb->on = i;
			}
		}
	}
	updateRadioButton(rb);
	
	debug("<gereClicRadioButton> end");
}
