#include<stdlib.h>
#include<graph.h>
#include<stdio.h>
#include <unistd.h>
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

int avoirColonne(int idCase) {
  return (idCase%60-1)*20;
}

int avoirLigne(int idCase) {
  return (idCase/60)*20;
}

void fenetre (struct Config Config) {
  srand(time(NULL));
  
  struct Jeu Jeu;
  int tailleGrille = Config.longueurGrille * Config.hauteurGrille;
  initialiserTabCases(&Jeu, tailleGrille);
  Jeu.tailleSerpent = 0;

  int i,j;
  int r=0;  
  
  int taille=Config.longueurGrille*Config.hauteurGrille;
  int haz6=rand()%Config.hauteurGrille+1;
  int haz7=rand()%Config.hauteurGrille+1;
  int haz8=rand()%Config.hauteurGrille+1;
  int haz9=rand()%Config.hauteurGrille+1;
  int haz10=rand()%Config.hauteurGrille+1;
  int haz1=rand()%Config.longueurGrille+1;
  int haz2=rand()%Config.longueurGrille+1;
  int haz3=rand()%Config.longueurGrille+1;
  int haz4=rand()%Config.longueurGrille+1;
  int haz5=rand()%Config.longueurGrille+1;

  while (haz2==haz1 || haz2==haz3 || haz2==haz4 || haz2==haz5/* &&!( haz7==haz8 || haz7==haz9 || haz7==haz6 || haz7==haz10)*/){
    haz2=rand()%Config.longueurGrille+1;
  }
  
  while (haz3==haz1 || haz3==haz2 ||haz3==haz4 || haz3==haz5/*&& !(haz8==haz7 || haz8==haz9 || haz8==haz6 || haz8==haz10)*/){
    haz3=rand()%Config.longueurGrille+1;
  }
  
  while (haz4==haz1 || haz4==haz2 || haz4==haz3 || haz4==haz5/*&& !(haz9==haz8 || haz9==haz7 || haz9==haz6 || haz9==haz10)*/){
    haz4=rand()%Config.longueurGrille+1;
  }
  
  while (haz5==haz1 || haz5==haz2 || haz5==haz3 || haz5==haz4/* &&!( haz10==haz8 || haz10==haz9 || haz10==haz6 || haz10==haz7)*/){
    haz5=rand()%Config.longueurGrille+1;
  }
  int d=0;
  
  int* tab=malloc(sizeof(int)*(taille));
    InitialiserGraphique();
  CreerFenetre(0,0,20*Config.longueurGrille,20*Config.hauteurGrille+20);
  ChoisirCouleurDessin (CouleurParNom("green"));
  RemplirRectangle((Config.longueurGrille/2)*20,(Config.hauteurGrille/2)*20,20,20);
  for (j=Config.hauteurGrille;j>0;j--){
    int m=0;
    for (i=Config.longueurGrille;i>0;i--){   
      DessinerRectangle(0+m,0+r,20,20);
      ChoisirCouleurDessin (CouleurParNom("black"));
      if (i==haz1 && j==haz6  ||i==haz2 && j==haz7 || i==haz3&& j==haz8 || i==haz4&& j==haz9 ||i==haz5 && j==haz10){
        tab[0+d]=1;
	  RemplirRectangle(0+m,0+r,20,20);
      }
      else {
	tab[taille-(taille-d)]=0;
      }
      d++;
      m+=20;
      
    }
    r+=20;
  }

  int caseDebut = 1230;

  while (1) {
    if (ToucheEnAttente()) {
      if (Touche() == XK_Right) {
	caseDebut++;
	RemplirRectangle(avoirColonne(caseDebut),avoirLigne(caseDebut),20,20);
      }
      if (Touche() == XK_Left) {
        caseDebut--;
        RemplirRectangle(avoirColonne(caseDebut),avoirLigne(caseDebut),20,20);
      }
      if (Touche() == XK_Down) {
	caseDebut += 60;
	RemplirRectangle(avoirColonne(caseDebut),avoirLigne(caseDebut),20,20);
      }
      if (Touche() == XK_Up) {
        caseDebut -= 60;
        RemplirRectangle(avoirColonne(caseDebut),avoirLigne(caseDebut),20,20);
      }
    }
    fflush(stdout);
    usleep(500000);
  }


  /*  int tmp=d;
  for (i=0;i<taille;i++){
    printf ("%d", tab[i]);
    }*/
  while (!SourisCliquee());
  FermerGraphique();
  
}
