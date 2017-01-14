#ifndef SNAKE.H
#define SNAKE.H

enum etatCase {vide,serpent,pomme,obstacle};
enum direction {haut,bas,gauche,droit};

struct Jeu{
  enum etatCase* tabCases;
  enum direction direction;
  int tailleSerpent;
};

void initialiserTabCases(struct Jeu*, int);
int avoirColonne(int);
int avoirLigne(int);
void fenetre (struct Config);

#endif
