#ifndef SNAKE.H1
#define SNAKE.H

enum etatCase {vide,serpent,pomme,obstacle};
enum direction {haut,bas,gauche,droit};

struct Jeu {
  enum etatCase* tabCases;
  enum direction direction;
  int tailleSerpent;
};

struct Membre {
  int idCase;
  struct Membre* precedent;
  struct Membre* suivant;
};

struct Snake {
  struct Membre* tete;
  struct Membre* queue;
};

void initialiserTabCases(struct Jeu*, int);
int avoirColonne(int, struct Config);
int avoirLigne(int, struct Config);
void genererPommes(struct Jeu*, struct Config);
void creerSerpent(struct Snake*, int, int);
void agrandirSerpent(struct Snake*, int);
void reduireSerpent(struct Snake*, struct Config);
void fenetre (struct Config);

#endif
