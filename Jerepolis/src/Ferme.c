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
#include "../headers/Ferme.h"

void actualiseCapacitePopulationRestante(int* capacitePopulationRestante, Batiment ferme, Batiment senat, Batiment entrepot, Batiment scierie, Batiment temple, Batiment carriere, Batiment caserne,
Batiment mine){
	// Production
	*capacitePopulationRestante = 10 + ferme.population * 20;
	
	// Consommation
	*capacitePopulationRestante -= ferme.population;
	*capacitePopulationRestante -= senat.population;
	*capacitePopulationRestante -= entrepot.population;
	*capacitePopulationRestante -= scierie.population;
	*capacitePopulationRestante -= temple.population;
	*capacitePopulationRestante -= carriere.population;
	*capacitePopulationRestante -= caserne.population;
	*capacitePopulationRestante -= mine.population;
}

void affichePopupFerme(Popups popups, Batiment ferme){
	if(popups.actuel == POPUP_FERME){
		if(ferme.popup != NULL){ ecrisImage(167, 90, ferme.popup->largeurImage, ferme.popup->hauteurImage, ferme.popup->donneesRGB);}
	}
}

void gereClicGauchePopupFerme(Popups* popups, int x, int y){
	if(popups->actuel == POPUP_FERME){
		// Gère clic sur la croix
		if(x > 958 && x < 978 && y > 628 && y < 647){
			if(popups->actuel == popups->final){
				popups->final = POPUP_NONE;
			}
		}
	}
}
