/**
 * Includes Classiques
 * */
#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include <time.h>

/**
 * Includes GfxLib
 * */
#include "GfxLib/headers/GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "GfxLib/headers/BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "GfxLib/headers/ESLib.h" // Pour utiliser valeurAleatoire()

/**
 * Includes Logger
 * */
#include "Logger/headers/Logger.h"

/**
 * Includes CustomGfxComponents
 * */
#include "CustomGfxComponents/headers/structures.h"
#include "CustomGfxComponents/headers/Mouse.h"
#include "CustomGfxComponents/headers/Couleur.h"
#include "CustomGfxComponents/headers/Keyboard.h"
#include "CustomGfxComponents/headers/Navbar.h"
#include "CustomGfxComponents/headers/InputText.h"
#include "CustomGfxComponents/headers/Rectangle.h"
#include "CustomGfxComponents/headers/Page.h"
#include "CustomGfxComponents/headers/Image.h"

/**
 * Includes Jerepolis
 * */
#include "Jerepolis/headers/structures.h"
#include "Jerepolis/headers/ModeleBatiment.h"
#include "Jerepolis/headers/AmeliorationBatiment.h"
#include "Jerepolis/headers/Batiment.h"
#include "Jerepolis/headers/Senat.h"
#include "Jerepolis/headers/Ferme.h"
#include "Jerepolis/headers/Entrepot.h"
#include "Jerepolis/headers/Mine.h"
#include "Jerepolis/headers/Carriere.h"
#include "Jerepolis/headers/Scierie.h"
#include "Jerepolis/headers/Temple.h"
#include "Jerepolis/headers/Caserne.h"
#include "Jerepolis/headers/Simplifications.h"
#include "Jerepolis/headers/RecrutementUnite.h"
#include "Jerepolis/headers/Accueil.h"
#include "Jerepolis/headers/Attaque.h"
#include "Jerepolis/headers/Ennemi.h"
#include "Jerepolis/headers/Evenement.h"

/**
 * Includes minunit
 * */
#include "minunit/minunit.h"

CouleurTab c; // Définit le tableau de couleurs
Keyboard keys; // Définit le clavier -> à synchroniser avec les autres fichiers si nécessaire ("extern")
Mouse souris; // Définit le clavier -> à synchroniser avec les autres fichiers si nécessaire ("extern")
int loggerLevel; // Définit le niveau de log -> à synchroniser avec les autres fichiers via ("extern")
int vitesse; // Définit la vitesse du jeu

Unite epee;

MU_TEST(test_initUnite){
	initUnite(&epee, "epee", 95, 0, 85, 0, 1, 10000, 5, 48, 16, TROUPE_EPEE);

	mu_check(epee.prixBois == 95);
	mu_check(epee.prixPierre == 0);
	mu_check(epee.prixArgent == 85);
	mu_check(epee.prixFaveur == 0);
	mu_check(epee.population == 1);
	mu_check(epee.temps == 10000);
	mu_check(epee.attaque == 5);
	mu_check(epee.vitesse == 48);
	mu_check(epee.capacite == 16);
	mu_check(epee.type == TROUPE_EPEE);
}

MU_TEST_SUITE(test_suite) {
	MU_RUN_TEST(test_initUnite);
}

void gestionEvenement(EvenementGfx evenement){}

int main(int argc, char **argv){
	// Initialise le logger
	setLoggerLevel("none"); // Default
	if(argc == 2){
		setLoggerLevel(argv[1]);
	}
	
	debug("<main> begin");
	initialiseGfx(argc, argv);
	
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	
	debug("<main> end");
	return 0;
}
