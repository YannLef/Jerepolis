void sauvegarde(InputText* nomVille, float* bois, float* pierre, float* argent, float* faveur, Divinite* divinite, Batiment* senat, Batiment* ferme, Batiment* entrepot, Batiment* caserne,
Batiment* temple, Batiment* scierie, Batiment* carriere, Batiment* mine, ameliorationBatiment** fileDeConstructions, int* nbEpee, int* nbFrondeur, int* nbArcher, int* nbHoplite,
int* nbCavalier, int* nbChar, int* nbCatapulte, EvenementTroupe** listeEvenementTroupe);

void charger(InputText* nomVille, float* bois, float* pierre, float* argent, float* faveur, Divinite* divinite, Batiment* senat, ModeleBatiment* modeleSenat, Batiment* ferme,
ModeleBatiment* modeleFerme, Batiment* entrepot, ModeleBatiment* modeleEntrepot, Batiment* caserne, ModeleBatiment* modeleCaserne, Batiment* temple, ModeleBatiment* modeleTemple,
Batiment* scierie, ModeleBatiment* modeleScierie, Batiment* carriere, ModeleBatiment* modeleCarriere, Batiment* mine, ModeleBatiment* modeleMine, ameliorationBatiment** fileDeConstructions,
int* nbEpee, int* nbFrondeur, int* nbArcher, int* nbHoplite, int* nbCavalier, int* nbChar, int* nbCatapulte, EvenementTroupe** listeEvenementTroupe, Ennemi* ennemi);
