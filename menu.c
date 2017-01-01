#include <stdio.h>
#include <graph.h>
#include "snake.h"

struct Config {
  int longueurGrille;
  int hauteurGrille;
  int nombrePastille;
  int tailleSerpent;
};

//void menu(struct Config*);
//void config(struct Config);
//void affichage(int, int);
//void affichageDimensions(int, int);
//void affichageDetails(int, int);

void menu(struct Config* Config) {

  ChoisirCouleurDessin(CouleurParNom("green"));
  EcrireTexte(117, 50, "Snake", 2);

  ChoisirCouleurDessin(CouleurParNom("grey"));
  EcrireTexte(85, 130, "Lancer une partie", 1);

  EcrireTexte(75, 180, "Configurer la partie", 1);

  EcrireTexte(100, 230, "Quitter le jeu", 1);

  // DessinerRectangle(85, 115, 138, 17); 
  // DessinerRectangle(75, 165, 153, 17);
  // DessinerRectangle(100, 215, 103, 17);
 
  int fin = 0;

  while (!fin) {
    SourisCliquee();
    if ((_X) >= 85 && (_Y) >= 115 && (_X) < 223 && (_Y) < 132) { // Lancer la partie
      fenetre((*Config));
      fin = 1;
    }
    if ((_X) >= 75 && (_Y) >= 165 && (_X) < 228 && (_Y) < 182) { // Configurer la partie
      fin = 1;
      config((*Config));
    }
    if ((_X) >= 100 && (_Y) >= 215 && (_X) < 203 && (_Y) < 232) { // Quitter le game
      fin = 1;
    }
  }
}

void config(struct Config Config) {
  int fin = 0;

  ChoisirCouleurDessin(CouleurParNom("white"));
  RemplirRectangle(0, 0, 300, 350);
  ChoisirCouleurDessin(CouleurParNom("black"));
  EcrireTexte(45, 50, "Configuration de la partie", 1);
  ChoisirCouleurDessin(CouleurParNom("grey"));
  EcrireTexte(55, 110, "Taille de la grille de jeu", 1);
  ChoisirCouleurDessin(CouleurParNom("lightgrey"));
  RemplirRectangle(80, 125, 7, 7);
  RemplirRectangle(80, 138, 7, 7);
  affichage(Config.longueurGrille, 1);
  ChoisirCouleurDessin(CouleurParNom("lightgrey"));
  EcrireTexte(139, 140, "x", 1);
  RemplirRectangle(155, 125, 7, 7);
  RemplirRectangle(155, 138, 7, 7);
  affichage(Config.hauteurGrille, 2);
  ChoisirCouleurDessin(CouleurParNom("grey"));
  EcrireTexte(70, 175, "Nombre de pastilles", 1);
  ChoisirCouleurDessin(CouleurParNom("lightgrey"));
  RemplirRectangle(120, 190, 7, 7);
  RemplirRectangle(120, 203, 7, 7);
  affichage(Config.nombrePastille, 3);
  ChoisirCouleurDessin(CouleurParNom("grey"));
  EcrireTexte(82, 240, "Taille du serpent", 1);
  ChoisirCouleurDessin(CouleurParNom("lightgrey"));
  RemplirRectangle(120, 255, 7, 7);
  RemplirRectangle(120, 268, 7, 7);
  affichage(Config.tailleSerpent, 4);
  ChoisirCouleurDessin(CouleurParNom("black"));
  EcrireTexte(82, 315, "Revenir au menu", 1);

  while (!fin) {
    SourisCliquee();
    if ((_X) >= 80 && (_Y) >= 125 && (_X) < 87 && (_Y) < 132) { // longueur ++
      if (Config.longueurGrille >= 99) {}
      else {
	Config.longueurGrille++;
	affichage(Config.longueurGrille, 1);
	_X = 0;
	_Y = 0;
      }
    }
    if ((_X) >= 80 && (_Y) >= 138 && (_X) < 87 && (_Y) < 145) { // longueur --
      Config.longueurGrille--;
      affichage(Config.longueurGrille, 1);
      _X = 0;
      _Y = 0;
    }
    if ((_X) >= 155 && (_Y) >= 125 && (_X) < 162 && (_Y) < 132) { // hauteur ++
      if (Config.hauteurGrille >= 99) {}
      else {
	Config.hauteurGrille++;
	affichage(Config.hauteurGrille, 2);
	_X = 0;
	_Y = 0;
      }
    }
    if ((_X) >= 155 && (_Y) >= 138 && (_X) < 162 && (_Y) < 145) { // hauteur --
      Config.hauteurGrille--;
      affichage(Config.hauteurGrille, 2);
      _X = 0;
      _Y = 0;
    }
    if ((_X) >= 120 && (_Y) >= 190 && (_X) < 127 && (_Y) < 197) { // pastille ++
      Config.nombrePastille++;
      affichage(Config.nombrePastille, 3);
      _X = 0;
      _Y = 0;
    }
    if ((_X) >= 120 && (_Y) >= 203 && (_X) < 127 && (_Y) < 210) { // pastille --
      if (Config.nombrePastille <= 5) {}
      else {
	Config.nombrePastille--;
	affichage(Config.nombrePastille, 3);
	_X = 0;
	_Y = 0;
      }
    }
    if ((_X) >= 120 && (_Y) >= 255 && (_X) < 127 && (_Y) < 262) { // serpent ++
      Config.tailleSerpent++;
      affichage(Config.tailleSerpent, 4);
      _X = 0;
      _Y = 0;
    }
    if ((_X) >= 120 && (_Y) >= 268 && (_X) < 127 && (_Y) < 275) { // serpent --
      if (Config.tailleSerpent <= 5) {}
      else {
	Config.tailleSerpent--;
	affichage(Config.tailleSerpent, 4);
	_X = 0;
	_Y = 0;
      }
    }
    if ((_X) >= 81 && (_Y) >= 300 && (_X) < 220 && (_Y) < 317) { // Revenir au menu
      fin = 1;
      ChoisirCouleurDessin(CouleurParNom("white"));
      RemplirRectangle(0, 0, 300, 350);
      menu(&Config);
    }
  }
}

void affichage(int entier, int choix) {
  ChoisirCouleurDessin(CouleurParNom("lightgrey"));
  if (choix == 1)
    affichageDimensions(entier, choix);
  else if (choix == 2)
    affichageDimensions(entier, choix);
  else if (choix == 3)
    affichageDetails(entier, choix);
  else if (choix == 4)
    affichageDetails(entier, choix);
}

void affichageDimensions(int entier, int choix) {
  if (choix == 1) {
    RemplirRectangle(90, 125, 40, 20);
    ChoisirCouleurDessin(CouleurParNom("white"));
    if (entier >= 10) {
      int dizaine = entier / 10;
      int unite = entier % 10;
      char entierTab[3] = {'0', '0', '\0'};
      entierTab[0] = '0' + dizaine;
      entierTab[1] = '0' + unite;
      EcrireTexte(100, 142, entierTab, 1);
    }
    else if (entier < 10) {
      char entierTab[2] = {'0', '\0'};
      entierTab[0] = '0' + entier;
      EcrireTexte(105, 142, entierTab, 1);
    }
  }
  else {
    RemplirRectangle(165, 125, 40, 20);
    ChoisirCouleurDessin(CouleurParNom("white"));
    if (entier >= 10) {
      int dizaine = entier / 10;
      int unite = entier % 10;
      char entierTab[3] = {'0', '0', '\0'};
      entierTab[0] = '0' + dizaine;
      entierTab[1] = '0' + unite;
      EcrireTexte(177, 142, entierTab, 1);
    }
    else if (entier < 10) {
      char entierTab[2] = {'0', '\0'};
      entierTab[0] = '0' + entier;
      EcrireTexte(181, 142, entierTab, 1);
    }
  }
}

void affichageDetails(int entier, int choix) {
  if (choix == 3) {
    RemplirRectangle(130, 190, 40, 20);
    ChoisirCouleurDessin(CouleurParNom("white"));
    if (entier >= 10) {
      int dizaine = entier / 10;
      int unite = entier % 10;
      char entierTab[3] = {'0', '0', '\0'};
      entierTab[0] = '0' + dizaine;
      entierTab[1] = '0' + unite;
      EcrireTexte(140, 207, entierTab, 1);
    }
    else if (entier < 10) {
      char entierTab[2] = {'0', '\0'};
      entierTab[0] = '0' + entier;
      EcrireTexte(145, 207, entierTab, 1);
    }
  }
  else {
    RemplirRectangle(130, 255, 40, 20);
    ChoisirCouleurDessin(CouleurParNom("white"));
    if (entier >= 10) {
      int dizaine = entier / 10;
      int unite = entier % 10;
      char entierTab[3] = {'0', '0', '\0'};
      entierTab[0] = '0' + dizaine;
      entierTab[1] = '0' + unite;
      EcrireTexte(140, 272, entierTab, 1);
    }
    else if (entier < 10) {
      char entierTab[2] = {'0', '\0'};
      entierTab[0] = '0' + entier;
      EcrireTexte(145, 272, entierTab, 1);
    }
  }
}

void main() {
  struct Config Config;
  Config.longueurGrille = 60;
  Config.hauteurGrille = 40;
  Config.nombrePastille = 5;
  Config.tailleSerpent = 10;

  InitialiserGraphique();
  CreerFenetre(20, 20, 300, 350);
  
  menu(&Config);
  
  FermerGraphique();
}
