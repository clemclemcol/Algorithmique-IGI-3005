#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h> // NE PAS OUBLIER -lm A LA COMPILATION

typedef struct tmp_maillon {
  double contenu;
  struct tmp_maillon * suivant;  
} Maillon;

/*typedef struct {                     
  double contenu;                          
  Maillon* suivant;    
} Maillon; */

typedef Maillon* PtrMaillon;
typedef PtrMaillon Liste;

int listeVide(const Liste pListe){
    return(pListe == NULL);
}

void afficheListe(const Liste pListe){
    if(!listeVide(pListe)){
        printf("%f->", pListe->contenu);
        afficheListe(pListe->suivant);
    }
    else {
         printf("NULL\n");
    }
}

PtrMaillon creeMaillon(const double pVal, Maillon* pSuiv){
    Liste vMaillon = malloc(sizeof(PtrMaillon));
    if (vMaillon == NULL){
        printf("Allocation incorrecte.\n");
        return NULL;
    }
    else {
        vMaillon->contenu = pVal;
        vMaillon->suivant = pSuiv;
        return vMaillon;
    }
  
}

int main(void){
    Liste vListe = malloc(sizeof(PtrMaillon));
    vListe = creeMaillon(2.2, NULL);
    int vResp = listeVide(vListe);
    printf("%d\n", vResp);
    afficheListe(vListe);
        
}