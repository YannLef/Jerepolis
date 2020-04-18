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
#include "../headers/Page.h"
#include "../headers/ButtonChangePage.h"
#include "../headers/ButtonChangeFile.h"

/**
 * Includes correspondant
 * */
#include "../headers/FileExplorer.h"

extern couleurTab c; // Synchronise le clavier avec les autres fichiers

 /**
  * -----------------------------------------------------------
  * -------------------- 1) INITIALISATION --------------------
  * -----------------------------------------------------------
  * */

/**
 * Fonction permettant de récupérer et organiser les informations sur le contenu d'un dossier
 * @param cheminDossier Le chemin du dossier cible
 * @param fichers L'adresse du tableau de fichiers qui sera rempli avec les informations organisées
 * @author Yann LEFEVRE
 * */
void recupereInfosFichiersDansDossier(char* cheminDossier, fichier** fichiers, int* nombreFichiers){
	debug("<recupereInfosFichiersDansDossier> begin");
	
	// Formule la commande
	int taille = strlen("ls ") + strlen(cheminDossier) + strlen(" -lt>infosFichiers.txt") + 1;
	char* commande = (char*) malloc(sizeof(char)*taille);
	strcpy(commande,"ls ");
	strcat(commande, cheminDossier);
	strcat(commande," -lt>infosFichiers.txt");
	// Execute la commande
	system(commande);
				
	// Ouvre le fichier contenant le résultat de la commande ls exécutée précedement
	FILE* f = fopen("infosFichiers.txt","rt");
	

	char* tmp= (char*)malloc(sizeof(char)*50); // Stockera le nom des fichiers une fois récupéres
	strcpy(tmp,"");

	fscanf(f,"%[^\n]",tmp); // passe la première ligne du fichier
	

	int cpt =  0; // Permet de compter les lignes
	while(feof(f) == 0){ // Boucle jusqu'à ce que la fin du fichier soit atteinte
		
		if(*fichiers != NULL){ // On regarde si le tableau est déjà initilisé ou non
			// Si il est déjà initialisé on doit l'agrandir pour accueillir la prochaine ligne
			fichier* fichierTmp = (fichier*)malloc(sizeof(fichier)*(cpt+1)); // On crée un tableau temporaire de 1 case de plus que l'ancient
			for(int i=0; i<cpt; i++){ // On recopie toutes les informations déjà récupérées dans le nouveau tableau
				strcpy(fichierTmp[i].nom,(*fichiers)[i].nom);
				strcpy(fichierTmp[i].heure,(*fichiers)[i].heure);
				strcpy(fichierTmp[i].jour,(*fichiers)[i].jour);
				strcpy(fichierTmp[i].mois,(*fichiers)[i].mois);
			}
			free(*fichiers); // On libère l'ancien tableau, devenu obsolète
			// On redirige le tableau officiel vers le nouveau tableau
			*fichiers = fichierTmp;
			fichierTmp = NULL;
		}else{ // Si il n'est pas encore initialisé on l'initialise pour qu'il accueille la première donnée
			*fichiers = (fichier*)malloc(sizeof(fichier)*(cpt+1));
		}
		
		// Pour chaque ligne on passe les 5 premiers termes (inutiles pour nous) renvoyés par la commande système.
		for(int i=0;i<5;i++)
			fscanf(f, "%s ", tmp);
			
		fscanf(f, "%s ", tmp); // On récupère terme de chaque ligne qui correspond au mois de fichier.
		strcpy((*fichiers)[cpt].mois, tmp);
			
		fscanf(f, "%s ", tmp); // On récupère terme de chaque ligne qui correspond au jour de fichier.
		strcpy((*fichiers)[cpt].jour, tmp);
			
		fscanf(f, "%s ", tmp); // On récupère terme de chaque ligne qui correspond à l'heure de fichier.
		strcpy((*fichiers)[cpt].heure, tmp);

		fscanf(f, "%[^\n]\n", tmp); // On récupère le dernier terme de chaque ligne qui correspond au nom de fichier.
		strcpy((*fichiers)[cpt].nom, tmp);
		
		
		cpt++; // on incrémente le compteur
	}
	*nombreFichiers = cpt;
	
	free(tmp); // On libère la chaine de caractère tmeporaire
	free(commande); // On libère la chaine de caractère utilisée pour exécuter la commande
	fclose(f);	// On ferme le fichier

	debug("<recupereInfosFichiersDansDossier> end");
}

 /**
  * ----------------------------------------------------
  * -------------------- 2) DISPLAY --------------------
  * ----------------------------------------------------
  * */
  
/**
 * Fonction regroupant l'affichage de la page explorateur de fichier
 * Permet notamment de faciliter la lecture du main
 * @author Yann LEFEVRE
 * */
void afficheExplorateurDeFichiers(DonneesImageRGB* enteteFondExplorateur, DonneesImageRGB* fondExplorateur, fichier* listeFichiers, boutonChangePage exitOpenTree, boutonChangeFichiers nextFichiers, boutonChangeFichiers previousFichiers, int xEcran, int yEcran, float coefZoom, int debutAffichageExplorateur, int nombreFichiers){
	debug("<afficheExplorateurDeFichiers> begin");
	
	if (enteteFondExplorateur != NULL){ ecrisImage(0, 640, enteteFondExplorateur->largeurImage, enteteFondExplorateur->hauteurImage, enteteFondExplorateur->donneesRGB);} // Si l'image de l'entête de l'explorateur de fichier a pu être lue, on l'affiche
	int cpt=debutAffichageExplorateur;
	for(int i=560; i>=80;i=i-80){
		if (fondExplorateur != NULL){ ecrisImage(0, i, fondExplorateur->largeurImage, fondExplorateur->hauteurImage, fondExplorateur->donneesRGB);} // Si l'image de l'entête de l'explorateur de fichier a pu être lue, on l'affiche
		if(cpt < nombreFichiers){
			couleurCourante(c.bleuEcriture.r,c.bleuEcriture.v,c.bleuEcriture.b);
			afficheChaine(listeFichiers[cpt].nom, 25, 50, i+27.5);
			int taille = strlen(listeFichiers[cpt].mois) + strlen(listeFichiers[cpt].jour) + strlen(listeFichiers[cpt].heure) + 3; // + 4 pour avoir la place de mettre les / et le \0
			char* date = (char*) malloc(sizeof(char)*taille);
			strcpy(date,listeFichiers[cpt].mois);
			strcat(date,"/");
			strcat(date,listeFichiers[cpt].jour);
			strcat(date,"/");
			strcat(date,listeFichiers[cpt].heure);
			afficheChaine(date, 25, 1150, i+27.5);
			cpt++;
		}
	}
	afficheBoutonChangePage(exitOpenTree, xEcran, yEcran, coefZoom);
	afficheBoutonChangeFichiers(nextFichiers, xEcran, yEcran, coefZoom);
	afficheBoutonChangeFichiers(previousFichiers, xEcran, yEcran, coefZoom);
	
	debug("<afficheExplorateurDeFichiers> end");
}


 /**
  * ----------------------------------------------------
  * -------------------- 3) EVENTS --------------------
  * ----------------------------------------------------
  * */

/**
 * Fonction permettant de selectionner un fichier en cliquant dessus via l'explorateur de fichiers.
 * Modifie la variable static du main fichierCharge en lui attribuant le fichier selectionne et change de page pour afficher l'arbre seelctionne
 * @author Yann LEFEVRE
 * */
void gereSourisSelectionneFichier(int xSouris, int ySouris, int* debutAffichageExplorateur, int nombreFichiers, pages* pActuel, fichier* listeFichiers, fichier* fichierCharge, char** fileNameI,
char** fileNameM){
	debug("<gereSourisSelectionneFichier> begin");
	
	int cpt=*debutAffichageExplorateur; // Le compteur permettant de savoir à quel fichier on en est / écolue en même temps que la boucle
	for(int i=560; i>=80;i=i-80){ // On boucle sur toutes les lignes affichants les fichiers
		if(cpt < nombreFichiers){ // On vérifie qu'il y a bien un fichier affiché à cet endroit de l'écran (et non pas une case vide si il n'y a plus assez de fichiers à afficher)
			if(xSouris > 0 && xSouris < largeurFenetre() && ySouris > i && ySouris < i+80){
				*fichierCharge = listeFichiers[cpt]; // Enregistre le fichier selectionne dans la varible du main préu à cet effet
							
			}
			cpt++;
		}
	}
	
	debug("<gereSourisSelectionneFichier> end");
}
