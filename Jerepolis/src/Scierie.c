/**
 * Includes Classiques
 * */
#include <stdlib.h>
#include <stdio.h>

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
#include "../../CustomGfxComponents/headers/structures.h"
#include "../../CustomGfxComponents/headers/Couleur.h"
#include "../../CustomGfxComponents/headers/Image.h"

/**
 * Includes Jerepolis
 * */
#include "../headers/structures.h"

/**
 * Includes correspondant
 * */
#include "../headers/Scierie.h"

void affichePopupScierie(Popups popups, Batiment scierie){
	if(popups.actuel == POPUP_SCIERIE){
		if(scierie.popup != NULL){ ecrisImage(167, 90, scierie.popup->largeurImage, scierie.popup->hauteurImage, scierie.popup->donneesRGB);}
	}
}

void gereClicGauchePopupScierie(Popups* popups, int x, int y){
	if(popups->actuel == POPUP_SCIERIE){
		// Gère clic sur la croix
		if(x > 958 && x < 978 && y > 628 && y < 647){
			if(popups->actuel == popups->final){
				popups->final = POPUP_NONE;
			}
		}
	}
}
