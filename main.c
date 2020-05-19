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

// Largeur et hauteur par defaut d'une image correspondant a nos criteres
#define LargeurFenetre 1152
#define HauteurFenetre 720

CouleurTab c; // Définit le tableau de couleurs
Keyboard keys; // Définit le clavier -> à synchroniser avec les autres fichiers si nécessaire ("extern")
Mouse souris; // Définit le clavier -> à synchroniser avec les autres fichiers si nécessaire ("extern")
int loggerLevel; // Définit le niveau de log -> à synchroniser avec les autres fichiers via ("extern")
int vitesse; // Définit la vitesse du jeu

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
	static DonneesImageRGB *accueilBackground = NULL;
	static DonneesImageRGB *background = NULL;
	static DonneesImageRGB *backgroundZeus = NULL;
	static DonneesImageRGB *backgroundPoseidon = NULL;
	static DonneesImageRGB *backgroundHades = NULL;
	static DonneesImageRGB *ameliorer = NULL;
	static DonneesImageRGB *construire = NULL;
	static DonneesImageRGB *impossible = NULL;
	static DonneesImageRGB *maximum = NULL;
	static DonneesImageRGB *infosBatiment = NULL;
	static DonneesImageRGB *annuler = NULL;
	
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
	
	// Unite
	static Unite epee;
	static int nbEpee;
	
	static Unite frondeur;
	static int nbFrondeur;
	
	static Unite archer;
	static int nbArcher;
	
	static Unite hoplite;
	static int nbHoplite;
	
	static Unite cavalier;
	static int nbCavalier;
	
	static Unite charr;
	static int nbChar;
	
	static Unite catapulte;
	static int nbCatapulte;
	
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
	
	// Divinité
	static Divinite divinite;
	static Divinite divinite_selec;
	
	// Troupe caserne
	static Troupe troupe;
	static int nb_troupe;
	static RecrutementUnite* fileDeRecrutement;
	
	switch (evenement)
	{
		case Initialisation:
			demandeTemporisation(50);
			initCouleurTab(&c); // Initialise le tableau de couleurs
            initKeyboard(); // Initialise le clavier
            vitesse = 1;
            
            // Pages
            initPage(&p, accueil);
            
            // Popup
            initPopups(&popups);
            
            // Images
            chargeImages(&accueilBackground, &background, &backgroundZeus, &backgroundPoseidon, &backgroundHades, &ameliorer, &construire, &impossible, &maximum, &infosBatiment, &annuler);
            
            // Bâtiments
			initBatiments(&modeleSenat, &senat, &modeleFerme, &ferme, &modeleCarriere, &carriere, &modeleScierie, &scierie, &modeleMine, &mine, &modeleEntrepot, &entrepot, &modeleTemple, &temple, &modeleCaserne, &caserne);
            
            // Unités
            initUnites(&epee, &frondeur, &archer, &hoplite, &cavalier, &charr, &catapulte);
            nbEpee = 0;
            nbFrondeur = 0;
            nbArcher = 0;
            nbHoplite = 0;
            nbCavalier = 0;
            nbChar = 0;
            nbCatapulte = 0;
            
            // File de constructions
            fileDeConstructions = NULL;
            
            // Ressources
            faveur = 0;
            bois = 200;
            pierre = 200;
            argent = 200;
            stockageEntrepot = 0;
            capacitePopulationRestante = 0;
            
            // Nom ville
            initInputText(&nomVille, 0, 576, 699, 156, 26, 2, c.invisible, c.invisible);
            setString(&nomVille, "Nom de la ville");
            
            // Divinite
            divinite = DIVINITE_NONE;
            divinite_selec = DIVINITE_NONE;
            
            // Troupe caserne
            troupe = TROUPE_EPEE;
            nb_troupe = 0;
            fileDeRecrutement = NULL;
            
			break;
		
		case Temporisation:
			updatePage(&p);
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
					genereFaveurs(temple, divinite, &faveur);
					gereFileDeRecrutement(caserne, &fileDeRecrutement, &nbEpee, &nbFrondeur, &nbArcher, &nbHoplite, &nbCavalier, &nbChar, &nbCatapulte);
					break;
			}
		
			rafraichisFenetre();
			break;
			
		case Affichage:
			// On part d'un fond d'ecran blanc
			effaceFenetre (255, 255, 255);
			
			switch(p.pActuel){
				case accueil:
					if(accueilBackground != NULL){ ecrisImage(0, 0, accueilBackground->largeurImage, accueilBackground->hauteurImage, accueilBackground->donneesRGB);}
					break;
				case partie:
					// Affichage du fond
					afficheBackground(divinite, background, backgroundZeus, backgroundPoseidon, backgroundHades);
					
					changeColor(c.blanc);
					char texteVitesse[100];
					sprintf(texteVitesse,"x%d", vitesse);
					afficheChaine(texteVitesse, 20, 1121, 625);
					
					// Affichage des batiments
					afficheBatiments(senat, ferme, carriere, scierie, mine, entrepot, temple, caserne);
					
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
					afficheFileDeConstructions(fileDeConstructions, annuler);
					
					// Affiche nom ville
					afficheInputTexte(nomVille);
					
					// Affiche informations batiments
					afficheInfosBatiment(senat, infosBatiment, ferme, scierie, entrepot, carriere, caserne, temple, mine);
					
					// Affiche popup
					affichePopupSenat(popups, maximum, impossible, ameliorer, construire, &bois, &pierre, &argent, fileDeConstructions, senat, scierie, ferme, entrepot, mine, carriere, temple, caserne);
					affichePopupMine(popups, mine);
					affichePopupFerme(popups, ferme);
					affichePopupEntrepot(popups, entrepot, bois, pierre, argent, stockageEntrepot);
					affichePopupCarriere(popups, carriere);
					affichePopupScierie(popups, scierie);
					affichePopupTemple(popups, temple);
					affichePopupCaserne(popups, caserne, troupe, nb_troupe, epee, frondeur, archer, hoplite, cavalier, charr, catapulte);
					
					// Affichage de la file de recrutement
					afficheFileDeRecrutement(fileDeRecrutement, annuler, popups);
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
				switch(p.pActuel){
					case accueil:
						gereClicAccueil(abscisseSouris(), ordonneeSouris(), &accueilBackground, &background, &backgroundZeus, &backgroundPoseidon, &backgroundHades, &ameliorer, &construire, &impossible,
						&maximum, &infosBatiment, &annuler, &p, modeleSenat, &senat, modeleFerme, &ferme, modeleCarriere, &carriere, modeleScierie, &scierie, modeleMine, &mine, modeleEntrepot,
						&entrepot, modeleTemple, &temple, modeleCaserne, &caserne, &bois, &pierre, &argent, &faveur, &nbEpee, &nbFrondeur, &nbArcher, &nbHoplite, &nbCavalier, &nbChar, &nbCatapulte,
						&fileDeConstructions, &fileDeRecrutement, &divinite, &popups, &divinite_selec, &troupe, &nb_troupe, &nomVille);
						break;
					case partie:
						gereSourisInputText(&nomVille, abscisseSouris(), ordonneeSouris());
				
						// Clic Batiments
						if(popups.actuel == POPUP_NONE){
							gereClicGaucheBatiment(&senat, abscisseSouris(), ordonneeSouris(), &popups);
							if(mine.niveau > 0){
								gereClicGaucheBatiment(&mine, abscisseSouris(), ordonneeSouris(), &popups);
							}
							gereClicGaucheBatiment(&ferme, abscisseSouris(), ordonneeSouris(), &popups);
							gereClicGaucheBatiment(&entrepot, abscisseSouris(), ordonneeSouris(), &popups);
							if(carriere.niveau > 0){
								gereClicGaucheBatiment(&carriere, abscisseSouris(), ordonneeSouris(), &popups);	
							}
							if(scierie.niveau > 0){
								gereClicGaucheBatiment(&scierie, abscisseSouris(), ordonneeSouris(), &popups);
							}
							if(temple.niveau > 0){
								gereClicGaucheBatiment(&temple, abscisseSouris(), ordonneeSouris(), &popups);
							}
							if(caserne.niveau > 0){
								gereClicGaucheBatiment(&caserne, abscisseSouris(), ordonneeSouris(), &popups);
							}
						}
						
						// Clic Popups
						gereClicGauchePopupSenat(&popups, abscisseSouris(), ordonneeSouris(), &bois, &pierre, &argent, &fileDeConstructions, &senat, &scierie, &ferme, &carriere, &entrepot, &mine,
						&caserne, &temple);
						gereClicGauchePopupMine(&popups, abscisseSouris(), ordonneeSouris());
						gereClicGauchePopupFerme(&popups, abscisseSouris(), ordonneeSouris());
						gereClicGauchePopupEntrepot(&popups, abscisseSouris(), ordonneeSouris());
						gereClicGauchePopupCarriere(&popups, abscisseSouris(), ordonneeSouris());
						gereClicGauchePopupScierie(&popups, abscisseSouris(), ordonneeSouris());
						gereClicGauchePopupTemple(&popups, abscisseSouris(), ordonneeSouris(), &temple, &faveur, &divinite);
						gereClicGauchePopupCaserne(&popups, abscisseSouris(), ordonneeSouris(), &caserne, &bois, &pierre, &argent, &faveur, &troupe, &nb_troupe, &epee, &frondeur, &archer, &hoplite,
						&cavalier, &charr,
						&catapulte, &fileDeRecrutement);
						
						// Clic File de Constructions
						gereClicFileDeConstruction(abscisseSouris(), ordonneeSouris(), &fileDeConstructions, &bois, &pierre, &argent);
						
						// Clic File de Recrutement
						gereClicFileDeRecrutement(abscisseSouris(), ordonneeSouris(), &fileDeRecrutement, popups, &bois, &pierre, &argent, &faveur);
						
						// Clic vitesse
						gereClicVitesse(abscisseSouris(), ordonneeSouris());
						
						// Clic quitter
						gereClicQuitter(abscisseSouris(), ordonneeSouris(), &p);
						break;
				}
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
