#ifndef FILE_EXPLORER_H
#define FILE_EXPLORER_H

void recupereInfosFichiersDansDossier(char* cheminDossier, Fichier** fichiers, int* nombreFichiers);

void afficheExplorateurDeFichiers(Fichier* listeFichiers, int nombreFichiers, int debut);

void gereSourisSelectionneFichier(int x, int y, Pages* pActuel, int* debutExplorer, int nombreFichiers, Fichier* fichiers, char** nomSave);

#endif
