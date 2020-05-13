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
#include "../../Logger/headers/Image.h"

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
	*capacitePopulationRestante = ferme.population * 20;
	
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
