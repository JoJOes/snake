#include<stdlib.h>
#include<graph.h>
#include<stdio.h>

/*enum e_numero{1,2,3,4,5};
 enum e_etat{};
  
struct Case {
  e_numero;              
  e_etat;                                                                                          }

int etat(Case case,e_numero case,e_etat case){                                                                                                                                                                                
    for (i=0;i<5;i++){                                                                                                                                                                                                           
      case.numero =i;                                                                                                                                                                                                            
      case.etat c=1;                                                                                                                                                                                                             
      printf("%d %d", case.numero, case.etat;                                                                                                                                                                                    
    }
                           
*/

void fenetre (struct Config Config) {
  srand(time(NULL));
  
  int i,j,l,h;
  int r=0;
  int etat=0;
  
  int taille=Config.longueurGrille*Config.hauteurGrille;
  int haz6=rand()%Config.longueurGrille+1;
  int haz7=rand()%Config.longueurGrille+1;
  int haz8=rand()%Config.longueurGrille+1;
  int haz9=rand()%Config.longueurGrille+1;
  int haz10=rand()%Config.longueurGrille+1;
  int haz1=rand()%Config.hauteurGrille+1;
  int haz2=rand()%Config.hauteurGrille+1;
  while (haz2==haz1 &&!( haz7==haz8 || haz7==haz9 || haz7==haz6 || haz7==haz10)){
    haz2=rand()%h+1;
  }
  int haz3=rand()%Config.hauteurGrille+1;
  while (haz3==haz1 || haz3==haz2 && !(haz8==haz7 || haz8==haz9 || haz8==haz6 || haz8==haz10)){
    haz3=rand()%h+1;
  }
  int haz4=rand()%Config.hauteurGrille+1;
  
  while (haz4==haz1 || haz4==haz2 || haz4==haz3 && !(haz9==haz8 || haz9==haz7 || haz9==haz6 || haz9==haz10)){
    haz4=rand()%Config.hauteurGrille+1;
  }
  int haz5=rand()%Config.hauteurGrille+1;
  
  while (haz5==haz1 || haz5==haz2 || haz5==haz3 || haz5==haz4 &&!( haz10==haz8 || haz10==haz9 || haz10==haz6 || haz10==haz7)){
    haz5=rand()%Config.hauteurGrille+1;
  }
  int d=0;
  
  int* tab=malloc(sizeof(int)*(taille));
  InitialiserGraphique();
  CreerFenetre(0,0,20*h,20*l+20);
  for (j=Config.longueurGrille;j>0;j--){
    int m=0;
    for (i=Config.hauteurGrille;i>0;i--){
      DessinerRectangle(0+m,0+r,20,20);
      ChoisirCouleurDessin (CouleurParNom("black"));
      if (i==haz1 && j==haz6  ||i==haz2&& j==haz7 || i==haz3&& j==haz8 || i==haz4&& j==haz9 ||i==haz5 && j==haz10){
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
  int tmp=d;
  for (i=0;i<taille;i++){
    printf ("%d", tab[i]);
  }
  Touche();
  FermerGraphique();
  
}
