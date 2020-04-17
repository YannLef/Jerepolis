#ifndef FORM_H
#define FORM_H

void initForm(Form* formulaire);
void freeForm(Form* formulaire);

void addCheckboxToForm(Form* formulaire, checkbox* cb);

void addRadioButtonToForm(Form* formulaire, radiobutton* rb);

void addInputTextToForm(Form* formulaire, inputText* rb);

void afficheForm(Form formulaire, int xEcran, int yEcran, float coefZoom);

void gereClicForm(Form formulaire, int xSouris, int ySouris);

void updateForm(Form formulaire);

#endif
