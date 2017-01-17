#ifndef MENU.H
#define MENU.H

struct Config {
  int longueurGrille;
  int hauteurGrille;
  int nombrePastille;
  int tailleSerpent;
};

void menu(struct Config*);
void config(struct Config);
void affichage(int, int);
void affichageDimensions(int, int);
void affichageDetails(int, int);

#endif
