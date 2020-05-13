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
#include "Logger/headers/Image.h"

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
	
	// Pages
	static Pages p;
	
	// Popup
	static Popups popups;
	
	// Images
	static DonneesImageRGB *background = NULL;
	static DonneesImageRGB *ameliorer = NULL;
	static DonneesImageRGB *construire = NULL;
	static DonneesImageRGB *impossible = NULL;
	static DonneesImageRGB *maximum = NULL;
	static DonneesImageRGB *infosBatiment = NULL;
	
	// Bâtiments
	static Batiment senat;
	static ModeleBatiment* modeleSenat;
	
	static Batiment ferme;
	static ModeleBatiment* modeleFerme;
	
	static Batiment carriere;
	static ModeleBatiment* modeleCarriere;
	
	static Batiment scierie;
	static ModeleBatiment* modeleScierie;
	
	static Batiment mine;
	static ModeleBatiment* modeleMine;
	
	static Batiment entrepot;
	static ModeleBatiment* modeleEntrepot;
	
	static Batiment temple;
	static ModeleBatiment* modeleTemple;
	
	static Batiment caserne;
	static ModeleBatiment* modeleCaserne;
	
	// File de constructions
	static ameliorationBatiment* fileDeConstructions;
	
	// Ressources
	static float faveur;
	static float bois;
	static float pierre;
	static float argent;
	static int stockageEntrepot;
	static int capacitePopulationRestante;
	
	// Nom ville
	static InputText nomVille;
	
	switch (evenement)
	{
		case Initialisation:
			demandeTemporisation(20);
			initCouleurTab(&c); // Initialise le tableau de couleurs
            initKeyboard(); // Initialise le clavier
            
            // Pages
            initPage(&p, partie);
            
            // Popup
            popups.actuel = NONE;
            popups.final = NONE;
            
            
            // Images
            background = lisBMPRGB("../Jerepolis/ressources/images/background.bmp");
            ameliorer = lisBMPRGB("../Jerepolis/ressources/images/boutons/ameliorer.bmp");
            construire = lisBMPRGB("../Jerepolis/ressources/images/boutons/construire.bmp");
            impossible = lisBMPRGB("../Jerepolis/ressources/images/boutons/impossible.bmp");
            maximum = lisBMPRGB("../Jerepolis/ressources/images/boutons/maximum.bmp");
            infosBatiment = lisBMPRGB("../Jerepolis/ressources/images/batiments/infos.bmp");
            
            // Bâtiments
            modeleSenat = NULL;
            initModeleBatiment(&modeleSenat, "senat", BATIMENT_NORMAL);
            initBatiment(&senat, modeleSenat, 610, 370, 605, 720, 380, 445);
            
            modeleFerme = NULL;
            initModeleBatiment(&modeleFerme, "ferme", BATIMENT_NORMAL);
            initBatiment(&ferme, modeleFerme, 706, 400, 730, 830, 400, 460);
            
            modeleCarriere = NULL;
            initModeleBatiment(&modeleCarriere, "carriere", BATIMENT_PRODUCTION);
            initBatiment(&carriere, modeleCarriere, 414, 314, 425, 535, 320, 370);
            
            modeleScierie = NULL;
            initModeleBatiment(&modeleScierie, "scierie", BATIMENT_PRODUCTION);
            initBatiment(&scierie, modeleScierie, 645, 238, 645, 705, 240, 290);
            
            modeleMine = NULL;
            initModeleBatiment(&modeleMine, "mine", BATIMENT_PRODUCTION);
            initBatiment(&mine, modeleMine, 435, 460, 453, 490, 472, 500);
            
            modeleEntrepot = NULL;
            initModeleBatiment(&modeleEntrepot, "entrepot", BATIMENT_NORMAL);
            initBatiment(&entrepot, modeleEntrepot, 577, 326, 580, 660, 330, 370);
            
            modeleTemple = NULL;
            initModeleBatiment(&modeleTemple, "temple", BATIMENT_PRODUCTION);
            initBatiment(&temple, modeleTemple, 398, 420, 400, 480, 420, 470);
            
            modeleCaserne = NULL;
            initModeleBatiment(&modeleCaserne, "caserne", BATIMENT_NORMAL);
            initBatiment(&caserne, modeleCaserne, 480, 378, 483, 580, 382, 437);
            
            // File de constructions
            fileDeConstructions = NULL;
            
            // Ressources
            faveur = 200;
            bois = 200;
            pierre = 200;
            argent = 200;
            stockageEntrepot = 0;
            capacitePopulationRestante = 0;
            
            // Nom ville
            initInputText(&nomVille, 0, 576, 699, 156, 26, 2, c.invisible, c.invisible);
            setString(&nomVille, "Nom de la ville");
            
            // Tests
            
			break;
		
		case Temporisation:
			switch(p.pActuel){
				case accueil:
				
					break;
				case partie:
					gereFileDeConstructions(&fileDeConstructions);
					updateInputText(&nomVille);
					actualisePopup(&popups);
					actualiseStockageEntrepot(&stockageEntrepot, entrepot);
					actualiseCapacitePopulationRestante(&capacitePopulationRestante, ferme, senat, entrepot, scierie, temple, carriere, caserne, mine);
					genereRessource(carriere, &pierre, stockageEntrepot);
					genereRessource(scierie, &bois, stockageEntrepot);
					genereRessource(mine, &argent, stockageEntrepot);
					genereRessource(temple, &faveur, 500);
					break;
			}
		
			rafraichisFenetre();
			break;
			
		case Affichage:
			// On part d'un fond d'ecran blanc
			effaceFenetre (255, 255, 255);
			
			switch(p.pActuel){
				case accueil:
				
					break;
				case partie:
					// Affichage du fond
					if(background != NULL){ ecrisImage(0, 0, background->largeurImage, background->hauteurImage, background->donneesRGB);}
					// Affichage des batiments
					afficheBatiment(senat);
					afficheBatiment(ferme);
					afficheBatiment(carriere);
					afficheBatiment(scierie);
					afficheBatiment(mine);
					afficheBatiment(entrepot);
					afficheBatiment(temple);
					afficheBatiment(caserne);
					
					// Affichage ressources
					changeColor(c.blanc);
					char texteFaveur[100];
					sprintf(texteFaveur,"%.0f", faveur);
					afficheChaine(texteFaveur, 20, 94, 520);
					
					char texteBois[100];
					sprintf(texteBois,"%.0f", bois);
					afficheChaine(texteBois, 20, 70, 460);
					
					char textePierre[100];
					sprintf(textePierre,"%.0f", pierre);
					afficheChaine(textePierre, 20, 70, 403);
					
					char texteArgent[100];
					sprintf(texteArgent,"%.0f", argent);
					afficheChaine(texteArgent, 20, 70, 345);
					
					char texteCapacitePopulationRestante[100];
					sprintf(texteCapacitePopulationRestante,"%d", capacitePopulationRestante);
					afficheChaine(texteCapacitePopulationRestante, 20, 70, 287);
					
					// Affichage de la file de constructions
					afficheFileDeConstructions(fileDeConstructions);
					
					// Affiche nom ville
					afficheInputTexte(nomVille);
					
					// Affiche informations batiments
					afficheInfosBatiment(senat, infosBatiment, ferme, scierie, entrepot, carriere, caserne, temple, mine);
					
					// Affiche popup
					affichePopupSenat(popups, maximum, impossible, ameliorer, construire, &bois, &pierre, &argent, fileDeConstructions, senat, scierie, ferme, entrepot, mine, carriere, temple, caserne);
					break;
			}

			break;
			
		case Clavier: // Rendu inutilisable car modification des callbacks de glut par le nouveau système de gestion du clavier
			break;
			 
		case ClavierSpecial: // Rendu inutilisable car modification des callbacks de glut par le nouveau système de gestion du clavier
			break;

		case BoutonSouris:
			if (etatBoutonSouris() == GaucheAppuye){
				printf("x : %d y : %d\n", abscisseSouris(), ordonneeSouris());
				mouseLeftDown();
			}else if (etatBoutonSouris() == GaucheRelache){
				mouseLeftUp();
				gereSourisInputText(&nomVille, abscisseSouris(), ordonneeSouris());
				gereClicGaucheBatiment(&senat, abscisseSouris(), ordonneeSouris(), &popups);
				gereClicGauchePopupSenat(&popups, abscisseSouris(), ordonneeSouris(), &bois, &pierre, &argent, &fileDeConstructions, &senat, &scierie, &ferme, &carriere, &entrepot, &mine, &caserne, &temple);
			}
			
			if(etatBoutonSouris() == DroiteAppuye){
				mouseRightDown();
			}else if(etatBoutonSouris() == DroiteRelache){
				mouseRightUp();
				switch(p.pActuel){
					case accueil:
					
						break;
					case partie:
						gereClicDroitBatiment(&senat, abscisseSouris(), ordonneeSouris());
						gereClicDroitBatiment(&ferme, abscisseSouris(), ordonneeSouris());
						gereClicDroitBatiment(&carriere, abscisseSouris(), ordonneeSouris());
						gereClicDroitBatiment(&scierie, abscisseSouris(), ordonneeSouris());
						gereClicDroitBatiment(&mine, abscisseSouris(), ordonneeSouris());
						gereClicDroitBatiment(&entrepot, abscisseSouris(), ordonneeSouris());
						gereClicDroitBatiment(&temple, abscisseSouris(), ordonneeSouris());
						gereClicDroitBatiment(&caserne, abscisseSouris(), ordonneeSouris());
						break;
				}
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
