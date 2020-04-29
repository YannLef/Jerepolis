/**
 * Includes Classiques
 * */
#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()

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

/**
 * Includes Jerepolis
 * */
#include "Jerepolis/headers/structures.h"
#include "Jerepolis/headers/ModeleBatiment.h"
#include "Jerepolis/headers/AmeliorationBatiment.h"
#include "Jerepolis/headers/Batiment.h"

// Largeur et hauteur par defaut d'une image correspondant a nos criteres
#define LargeurFenetre 1152
#define HauteurFenetre 720

CouleurTab c; // Définit le tableau de couleurs
Keyboard keys; // Définit le clavier -> à synchroniser avec les autres fichiers si nécessaire ("extern")
Mouse souris; // Définit le clavier -> à synchroniser avec les autres fichiers si nécessaire ("extern")
int loggerLevel; // Définit le niveau de log -> à synchroniser avec les autres fichiers via ("extern")

/* La fonction de gestion des evenements, appelee automatiquement par le systeme
des qu'une evenement survient */
void gestionEvenement(EvenementGfx evenement);

int main(int argc, char **argv){
	// Initialise le logger
	setLoggerLevel("none"); // Default
	if(argc == 2){
		setLoggerLevel(argv[1]);
	}
	
	debug("<main> begin");
	initialiseGfx(argc, argv);
	
	prepareFenetreGraphique("GfxLib", LargeurFenetre, HauteurFenetre);
	
	/* Lance la boucle qui aiguille les evenements sur la fonction gestionEvenement ci-apres,
		qui elle-meme utilise fonctionAffichage ci-dessous */
	lanceBoucleEvenements();
	
	debug("<main> end");
	return 0;
}

/* La fonction de gestion des evenements, appelee automatiquement par le systeme
des qu'une evenement survient */
void gestionEvenement(EvenementGfx evenement){
	debug("<gestionEvenement> begin");
	
	// Images
	static DonneesImageRGB *background = NULL;
	
	// Bâtiments
	static Batiment senat;
	static ModeleBatiment* modeleSenat;
	
	static Batiment ferme;
	static ModeleBatiment* modeleFerme;
	
	// File de constructions
	static ameliorationBatiment* fileDeConstructions;
	
	// Ressources
	static int bois;
	static int pierre;
	static int argent;
	
	
	switch (evenement)
	{
		case Initialisation:
			demandeTemporisation(100);
			initCouleurTab(&c); // Initialise le tableau de couleurs
            initKeyboard(); // Initialise le clavier
            
            // Images
            background = lisBMPRGB("../Jerepolis/ressources/images/background.bmp");
            //~ libereDonneesImageRGB(background);
            
            // Bâtiments
            modeleSenat = NULL;
            initModeleBatiment(&modeleSenat, "senat", BATIMENT_NORMAL);
            initBatiment(&senat, modeleSenat,1017, 615);
            
            modeleFerme = NULL;
            initModeleBatiment(&modeleFerme, "ferme", BATIMENT_NORMAL);
            initBatiment(&ferme, modeleFerme,1017, 615);
            
            // File de constructions
            fileDeConstructions = NULL;
            
            // Ressources
            bois = 400;
            pierre = 400;
            argent = 400;
            
            // Tests
			break;
		
		case Temporisation:
			gereFileDeConstructions(&fileDeConstructions);
		
			rafraichisFenetre();
			break;
			
		case Affichage:
			// On part d'un fond d'ecran blanc
			effaceFenetre (255, 255, 255);
			
			if(background != NULL){ ecrisImage(0, 0, background->largeurImage, background->hauteurImage, background->donneesRGB);}
			afficheBatiment(senat);
			afficheBatiment(ferme);
			
			// Affichages ressources (temporaire)
			char texteBois[100];
			sprintf(texteBois,"Bois : %d", bois);
			afficheChaine(texteBois, 20, 50, 150);
			
			char textePierre[100];
			sprintf(textePierre,"Pierre : %d", pierre);
			afficheChaine(textePierre, 20, 50, 100);
			
			char texteArgent[100];
			sprintf(texteArgent,"Argent : %d", argent);
			afficheChaine(texteArgent, 20, 50, 50);

			break;
			
		case Clavier: // Rendu inutilisable car modification des callbacks de glut par le nouveau système de gestion du clavier
			break;
			 
		case ClavierSpecial: // Rendu inutilisable car modification des callbacks de glut par le nouveau système de gestion du clavier
			break;

		case BoutonSouris:
			if (etatBoutonSouris() == GaucheAppuye)
			{
				mouseLeftDown();
			}
			else if (etatBoutonSouris() == GaucheRelache)
			{
				mouseLeftUp();
				gereClicBatiment(&senat, abscisseSouris(), ordonneeSouris(), &bois, &pierre, &argent, &fileDeConstructions);
			}
			break;
		
		case Souris: // Si la souris est deplacée
			break;
		
		case Inactivite: // Quand aucun message n'est disponible
			break;
		
		case Redimensionnement:
			break;
	}
	
	debug("<gestionEvenement> end");
}
