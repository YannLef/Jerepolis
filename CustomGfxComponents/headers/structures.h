#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "stdbool.h"

/**
 * Structure couleur contenant les nuances de rouge (r), vert (v) et bleu (b)
 * */
typedef struct Couleur{
	int r,v,b; // nuances de rouge, vert, bleu
}Couleur;

/**
 * Structure contenant toutes les couleurs utiles de manière récurente
 * On justifie l'utilisation d'une structure et non d'un tableau pour pouvoir se servir des noms et non des indices (plus abstrait mais haut niveau et facile d'utilisation)
 * */
typedef struct CouleurTab{
	Couleur couleurHomme; // 49, 140, 231
	Couleur couleurFemme; // 223, 115, 255
	Couleur couleurMenuDeroulant; // 130, 224, 170
	Couleur gris180; // 180,180,180
	Couleur gris125; //125,125,125
	Couleur blanc; // 255, 255, 255
	Couleur noir; // 0, 0, 0
	Couleur vertPrincipal; // 139,195,74
	Couleur bleuEcriture; // 38, 193, 225
	Couleur fondPrincipal; // 241, 255, 251
	Couleur invisible; // -1, -1, -1
}CouleurTab;

/**
 * Structure matérialisant un rectangle, contient de nombreux paramètres pour répondre à tous les besoins
 * */
typedef struct Rec{
	int x,y; // coordonnées du centre du rectangle -> on calculera les différents point à partir de là
	int hauteur, largeur; // hauteur et largeur du rectangle
	int epaisseurBordure; // largeur de la bordure
	Couleur cInterieur; // couleur de l'intérieur du rectangle
	Couleur cBordure; // couleur des contours du rectangle
}Rec;

/**
 * Structure matérialisant un menu déroulant pouvant se dérouler vers la droite
 * */
typedef struct MenuDeroulantVersDroite{
	
	// Générales, ne changent pas
	int yBas,yHaut; // Le haut et le bas du menu déroulant à afficher
	int xGauche; // La gauche du menu quand celui ci est entierement ouvert
	int xDroite; // La droite du menu quand celui ci est entierement ouvert
	int etat; // =1 si le menu est ENTIEREMENT ouvert, =0 sinon
	
	// En cours
	int xActuel; // Utile pour l'animation : variable qui évolue et permet de faire évoluer l'affichage
	int xFinal; // Utile pour l'animation : variable à atteindre qui permet de faire évoluer xActuel dans un sens ou dans l'autre
}MenuDeroulantVersDroite;

/**
 * Structure contenant des booléens pour chaque touche utilisé dans le programme
 * On justifie l'utilisation d'une structure et non d'un tableau pour pouvoir se servir des noms et non des indices (plus abstrait mais haut niveau et facile d'utilisation)
 * */
typedef struct Keyboard{
	bool key_a; // Touche a minuscule
	bool key_A; // Touche A majuscule
	bool key_b; // Touche b minuscule
	bool key_B; // Touche B majuscule
	bool key_c; // Touche c minuscule
	bool key_C; // Touche C majuscule
	bool key_d; // Touche d minuscule
	bool key_D; // Touche D majuscule
	bool key_e; // Touche e minuscule
	bool key_E; // Touche E majuscule
	bool key_f; // Touche f minuscule
	bool key_F; // Touche F majuscule
	bool key_g; // Touche g minuscule
	bool key_G; // Touche G majuscule
	bool key_h; // Touche h minuscule
	bool key_H; // Touche H majuscule
	bool key_i; // Touche i minuscule
	bool key_I; // Touche I majuscule
	bool key_j; // Touche j minuscule
	bool key_J; // Touche J majuscule
	bool key_k; // Touche k minuscule
	bool key_K; // Touche K majuscule
	bool key_l; // Touche l minuscule
	bool key_L; // Touche L majuscule
	bool key_m; // Touche m minuscule
	bool key_M; // Touche M majuscule
	bool key_n; // Touche n minuscule
	bool key_N; // Touche N majuscule
	bool key_o; // Touche o minuscule
	bool key_O; // Touche O majuscule
	bool key_p; // Touche p minuscule
	bool key_P; // Touche P majuscule
	bool key_q; // Touche q minuscule
	bool key_Q; // Touche Q majuscule
	bool key_r; // Touche r minuscule
	bool key_R; // Touche R majuscule
	bool key_s; // Touche s minuscule
	bool key_S; // Touche S majuscule
	bool key_t; // Touche t minuscule
	bool key_T; // Touche T majuscule
	bool key_u; // Touche u minuscule
	bool key_U; // Touche U majuscule
	bool key_v; // Touche v minuscule
	bool key_V; // Touche V majuscule
	bool key_w; // Touche w minuscule
	bool key_W; // Touche W majuscule
	bool key_x; // Touche x minuscule
	bool key_X; // Touche X majuscule
	bool key_y; // Touche y minuscule
	bool key_Y; // Touche Y majuscule
	bool key_z; // Touche z minuscule
	bool key_Z; // Touche Z majuscule
	
	
	bool key_0; // Touche 0
	bool key_1; // Touche 1
	bool key_2; // Touche 2
	bool key_3; // Touche 3
	bool key_4; // Touche 4
	bool key_5; // Touche 5
	bool key_6; // Touche 6
	bool key_7; // Touche 7
	bool key_8; // Touche 8
	bool key_9; // Touche 9
	
	bool key_spacebar; // Touche espace
	bool key_esc; // Touche echape
	bool key_del; // Touche supprimer
	bool key_backspace; // Touche backsapce
	
	bool key_up; // Touche flèche du haut
	bool key_down; // Touche flèche du bas
	bool key_left; // Touche flèche du gauche
	bool key_right; // Touche flèche de droite
	bool key_page_up; // Touche haut de page (flèche peu utilisée)
	bool key_page_down; // Touche bas de page (flèche peu utilisée)
	
	bool key_slash;
}Keyboard;

/**
 * Enumération permettant de générer différents affichages sous forme de "pages"
 * */
typedef enum {accueil, partie} Page;

/**
 * Structure permettant de gérer l'affichage des pages : pFinal permet de ne pas changer de page brusquement en plein milieu d'un traitement.
 * */
typedef struct Pages{
	Page pActuel;
	Page pFinal;
}Pages;

/**
 * Structure permettant d'avoir un bouton qui permet de changer de page au clic
 * */
typedef struct BoutonChangePage{
	Rec rect;
	Page pageSuivante;
	char* string;
	Couleur cText;
	int epaisseurTrait;
}BoutonChangePage;

/**
 * Structure matérialisant un input de type texte (permettant à l'utilisateur de rentrer du texte depuis le programme directement)
 * @author Yann LEFEVRE
 * */
typedef struct InputText{
	bool etat; // définit si l'input est selectionné(=1) ou non(=0)
	int size; // taille actuelle de la chaine entrée
	char* string; // la chaine de caractères écrite par l'utilisateur
	Rec rect; // rectangle utilisé pour l'affichage
}InputText;

/**
 * Structure permettant de rassember toutes les informations récupérées concernant un fichier stocké sur l'ordinateur
 * */
typedef struct Fichier{
	char nom[50];
	char heure[10];
	char jour[10];
	char mois[15];
	
}Fichier;

/**
 * Structure permettant d'avoir un bouton qui permet de changer les fichiers affichés
 * */
typedef struct BoutonChangeFichiers{
	Rec rect;
	char* string;
	Couleur cText;
	int epaisseurTrait;
	int effet; // la valeur dont sera incrémenté le numéro du premier élément affiché
}BoutonChangeFichiers;

/**
 * Structure permettant d'avoir un slider (input type range) qui permet de faire évoluer une variable qui lui est affecté en utilisant la souris
 * Ce slider est horizontal et permet donc de changer la valeur en bougeant la souris de droite à gauche
 * */
typedef struct SliderHorizontal{ 
	int x;
	int y;
	int largeur;
	int epaisseurLigne;
	int epaisseurPointeur;
	Couleur cLigne;
	Couleur cPointeur;
	int* var;
	int min;
	int max;
}SliderHorizontal;

/**
 * Structure permettant d'avoir un slider (input type range) qui permet de faire évoluer une variable qui lui est affecté en utilisant la souris
 * Ce slider est vertical et permet donc de changer la valeur en bougeant la souris de haut en bas
 * */
typedef struct SliderVertical{ 
	int x;
	int y;
	int hauteur;
	int epaisseurLigne;
	int epaisseurPointeur;
	Couleur cLigne;
	Couleur cPointeur;
	int* var;
	int min;
	int max;
}SliderVertical;

/**
 * Structure permettant de gérer la souris : de savoir en temps réel si les boutons sont appuyés ou relachés
 * */
typedef struct Mouse{
	bool clicLeft;
	bool clicRight;
}Mouse;

/**
 * Structure permettant de matérialiser un carré
 * */
typedef struct Carre{
	int x,y; // coordonnées du centre du rectangle -> on calculera les différents point à partir de là
	int cote; // hauteur et largeur du rectangle
	int epaisseurBordure; // largeur de la bordure
	Couleur cInterieur; // couleur de l'intérieur du rectangle
	Couleur cBordure; // couleur des contours du rectangle
}Carre;

/**
 * Structure matérialisant une checkbox (carré pouvant avoir deux états uniquement : 0 ou 1 en fonction de si elle est cochée ou non)
 * */
typedef struct Checkbox{
	bool etat; // l'état signalisant si la checkbox est cochée ou non
	Carre square; // Le carré servant de fond pour la checkbox
}Checkbox;

/**
 * Structure matérialisant un radiobutton
 * */
typedef struct Radiobutton{
	int on; // numéro de l'unique case selectionnée (-1 si aucun)
	int nb; // le nombre de cases
	Checkbox* cases; // le tableau contenant les différentes checkbox matérialisant les différentes cases du radiobutton
}Radiobutton;

/**
 * Structure matérialisant un input de type select, permettant de choisir parmi différentes options proposées
 * */
typedef struct InputSelect{
	char** options; // La liste des mots représentant les options
	int nbOptions; // Le nombre d'options
	int initial; // La valeur initialement selectionnée
}InputSelect;

/**
 * @brief Structure permettatn de farie des rectangles avec les angles arrondis
 */
typedef struct BoundedRectangle
{
    int x;
    int y;
    int largeur;
    int hauteur;
    int epaisseurBordure;
    Couleur cInterieur;
    Couleur cBordure;
}BoundedRectangle;

/**
 * @brief Structure matérialisant les messages permettant le communication avec l'assistant
 * */
typedef struct Message{
	bool sender; // 0 si assistant, 1 si utilisateur
	char* string; // Le message
}Message;

/**
 * Structure permettant d'avoir un bouton qui permet de changer de page au clic
 * */
typedef struct BoutonSendMessage{
	Rec rect;
	char* string;
	Couleur cText;
	int epaisseurTrait;
}BoutonSendMessage;

/**
 * Structure matérialisant un formulaire, pouvant contenir différents composants graphiques
 * */
typedef struct Form {
	int nbCheckbox, nbRadioButton, nbInpuText; // Les compteurs d'inputs
	    
    Checkbox** tabCheckbox; //tableau des adresses de checkbox
    Radiobutton** tabRadioButton; //tableau des adresses de radio button
    InputText** tabInpuText; //tableau des adresses de input text
}Form;


#endif



