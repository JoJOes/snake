#include <stdlib.h>
#include <graph.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "menu.h"
#include "snake.h"

void initialiserTabCases(struct Jeu* Jeu, int tailleGrille) {
  Jeu->tabCases = (enum etatCase*) malloc(sizeof(enum etatCase) * (tailleGrille+1));
  
  int i = 0;
  while (i <= tailleGrille) {
    Jeu->tabCases[i] = vide;
    i++;
  }
  /* On a des cases vides de 0 a tailleGrille - 1 */
}

int avoirColonne(int idCase, struct Config Config) {
  return (idCase%Config.longueurGrille-1)*20;
}

int avoirLigne(int idCase, struct Config Config) {
  return (idCase/Config.longueurGrille)*20;
}

void genererPommes(struct Jeu* Jeu, struct Config Config) {
  int i = 0, tailleGrille = Config.hauteurGrille * Config.longueurGrille, nombreAleatoire;
  ChoisirCouleurDessin(CouleurParNom("black"));
  srand(time(NULL));

  while (i < Config.nombrePastille) {
    nombreAleatoire = rand()%tailleGrille+1;
    if (Jeu->tabCases[nombreAleatoire] == pomme)
      ;
    else {
      Jeu->tabCases[nombreAleatoire] = pomme;
      RemplirRectangle(avoirColonne(nombreAleatoire, Config), avoirLigne(nombreAleatoire, Config), 20, 20);
      i++;
    }
  }
}

void creerSerpent(struct Snake* Snake, int caseDebut, int caseActuelle) {
  struct Membre* premier = (struct Membre*) malloc(sizeof(struct Membre));
  struct Membre* deuxieme = (struct Membre*) malloc(sizeof(struct Membre));

  Snake->tete = deuxieme;
  Snake->queue = premier;
  
  premier->idCase = caseDebut;
  deuxieme->idCase = caseActuelle;
  premier->precedent = deuxieme;
  premier->suivant = NULL;
  deuxieme->precedent = NULL;
  deuxieme->suivant = premier;
}

void agrandirSerpent(struct Snake* Snake, int caseActuelle) {
  struct Membre* ajout = (struct Membre*) malloc(sizeof(struct Membre));

  Snake->tete->precedent = ajout;
  
  ajout->idCase = caseActuelle;
  ajout->suivant = Snake->tete;
  ajout->precedent = NULL;

  Snake->tete = ajout;
}

void reduireSerpent(struct Snake* Snake, struct Config Config) {
  struct Membre* temporaire = Snake->queue;

  Snake->queue->precedent->suivant = NULL;
  Snake->queue = Snake->queue->precedent;
  ChoisirCouleurDessin(CouleurParNom("white"));
  int caseAVider = Snake->queue->idCase;
  RemplirRectangle(avoirColonne(caseAVider, Config), avoirLigne(caseAVider, Config),20,20);
  free(temporaire);
  ChoisirCouleurDessin(CouleurParNom("green"));
}

void fenetre(struct Config Config) {
  
  struct Jeu Jeu;
  int tailleGrille = Config.longueurGrille * Config.hauteurGrille;
  initialiserTabCases(&Jeu, tailleGrille);
  Jeu.tailleSerpent = 1;

  int i,j;
  int r=0;
  int d=0;
  
  InitialiserGraphique();
  CreerFenetre(0,0,20*Config.longueurGrille,20*Config.hauteurGrille+20);
  genererPommes(&Jeu, Config);

  for (j=Config.hauteurGrille;j>0;j--){
    int m = 0;
    for (i=Config.longueurGrille;i>0;i--){
      DessinerRectangle(0+m,0+r,20,20);
      ChoisirCouleurDessin(CouleurParNom("black"));
      d++;
      m += 20;
    }
    r += 20;
  }

  int caseDebut = tailleGrille/2+Config.longueurGrille/2+1;
  int caseActuelle = caseDebut, touche, commencer = 0;
  struct Snake Snake;

  ChoisirCouleurDessin(CouleurParNom("green"));
  RemplirRectangle(avoirColonne(caseDebut, Config), avoirLigne(caseDebut, Config),20,20);

  while (!SourisCliquee()) {
    if (ToucheEnAttente()) {
      touche = Touche();
      commencer = 1;

      switch(touche) {
      case XK_Right:
        caseActuelle++;
        Jeu.direction = droit;
	break;
      case XK_Left:
        caseActuelle--;
        Jeu.direction = gauche;
	break;
      case XK_Down:
	caseActuelle += Config.longueurGrille;
	Jeu.direction = bas;
	break;
      case XK_Up:
        caseActuelle -= Config.longueurGrille;
	Jeu.direction = haut;
	break;
      }
      Jeu.tailleSerpent++;
    }
    else if (commencer) {
      if (Jeu.direction == droit)
	caseActuelle++;
      else if (Jeu.direction == gauche)
	caseActuelle--;
      else if (Jeu.direction == bas)
	caseActuelle += Config.longueurGrille;
      else if (Jeu.direction == haut)
	caseActuelle -= Config.longueurGrille;
      Jeu.tailleSerpent++;
    }
    RemplirRectangle(avoirColonne(caseActuelle, Config), avoirLigne(caseActuelle, Config),20,20);
    if (Jeu.tailleSerpent == 2)
      creerSerpent(&Snake, caseDebut, caseActuelle);
    else if (Jeu.tailleSerpent > 2 && Jeu.tailleSerpent < Config.tailleSerpent+1)
      agrandirSerpent(&Snake, caseActuelle);
    else if (Jeu.tailleSerpent >= Config.tailleSerpent) {
      agrandirSerpent(&Snake, caseActuelle);
      reduireSerpent(&Snake, Config);
    }
    fflush(stdout);
    usleep(500000);
  }
  
  while (!SourisCliquee())
    ;

  printf("%d\n", Snake.tete->idCase);
  printf("%d\n", Snake.tete->suivant->idCase);
  printf("%d\n", Snake.tete->suivant->suivant->idCase);
  printf("%d\n", Snake.tete->suivant->suivant->suivant->idCase);
  FermerGraphique();
  
}
