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

Liste creeMaillon(const double pVal, Maillon* pSuiv){
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

Liste ajouteDebut(Liste pListe, PtrMaillon pPtrMail){
    pPtrMail->suivant = pListe;
    pListe = pPtrMail;
    return pListe;
}

Liste ajouteFin(Liste pListe, PtrMaillon pPtrMail){
    Liste vListe = pListe;
    while (pListe->suivant != NULL){
        pListe = pListe->suivant;
    }
    if (pListe->suivant == NULL) pListe->suivant = pPtrMail;
    return vListe;
}

int contient(Liste pListe, double pVal){
    while(pListe->suivant != NULL){
        if (pListe->contenu == pVal) return 1;
        pListe = pListe->suivant;
    }
    return 0;
}

Liste supprimeDebut(Liste pListe){
    if (pListe == NULL)
    {
        free(pListe);
        return NULL;
    }
    Liste vListe = pListe;
    if (pListe->suivant != NULL){
        vListe = pListe->suivant;
        free(pListe);
        return vListe;
    }
    else {
        free(pListe);
        return NULL;
    }
}

Liste supprimeFin(Liste pListe){
    if (pListe->suivant == NULL || pListe == NULL){
        free(pListe);
        return NULL;
    }
    Liste vListe = pListe;
    while(pListe->suivant->suivant != NULL){
        pListe = pListe->suivant;
    }
    free(pListe->suivant);
    pListe->suivant = NULL;
    return vListe;
}

int main(void){
    Liste vListe = NULL;
    int vRep = listeVide(vListe);
    printf("%d\n", vRep);
    afficheListe(vListe);

    vListe = creeMaillon(2.2, NULL);
    PtrMaillon vMaillon1 = creeMaillon(3.3, NULL);
    PtrMaillon vMaillon3 = creeMaillon(6, NULL);
    PtrMaillon vMaillon4 = creeMaillon(20, NULL);
    PtrMaillon vMaillon5 = creeMaillon(8, NULL);
    vListe = ajouteDebut(vListe, vMaillon1);
    vListe = ajouteDebut(vListe, vMaillon3);
    vListe = ajouteDebut(vListe, vMaillon4);
    vListe = ajouteDebut(vListe, vMaillon5);
    PtrMaillon vMaillon2 = creeMaillon(10.5, NULL);
    vListe = ajouteFin(vListe, vMaillon2);
    afficheListe(vListe);

    vRep = contient(vListe, 3.4);
    printf("%d\n", vRep);

    vListe = supprimeDebut(vListe);
    vListe = supprimeDebut(vListe);
    vListe = supprimeDebut(vListe);
    vListe = supprimeDebut(vListe);
    vListe = supprimeDebut(vListe);
    vListe = supprimeDebut(vListe);
    vListe = supprimeDebut(vListe);
    //vListe = supprimeDebut(vListe);
    afficheListe(vListe);
    
   /* vListe = supprimeFin(vListe);
     vListe = supprimeFin(vListe); 
     vListe = supprimeFin(vListe); 
     vListe = supprimeFin(vListe);
     vListe = supprimeFin(vListe);
     vListe = supprimeFin(vListe);
    afficheListe(vListe);*/

    free(vListe);
        
}