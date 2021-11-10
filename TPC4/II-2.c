#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct { char lettre ; int chiffre ; } Groupe;

void afficheGroupe(const Groupe* pGroupe){
    printf("%c%d\n", pGroupe->lettre, pGroupe->chiffre);
}

Groupe saisieGroupe(void){
    Groupe vGroupe;
    char c;
    do{
        printf("Entrez une lettre:");
        scanf("%c", &vGroupe.lettre);
        scanf("%c", &c);
    }while(!isupper(vGroupe.lettre));
    
    do{
        printf("Entrez un chiffre:");
        scanf("%d", &vGroupe.chiffre);
        scanf("%c", &c);
    }while(vGroupe.chiffre >= 10);
    return vGroupe;
}

int main(void){
    Groupe* vGroupe1 = malloc(sizeof(Groupe));
    Groupe* vGroupe2 = malloc(sizeof(Groupe));
    if (vGroupe1 == NULL && vGroupe2 == NULL){
        printf("Allocation incorrecte.\n");
        return 0;
    }
    *vGroupe1 = saisieGroupe();
    vGroupe2->lettre = vGroupe1->lettre;
    vGroupe2->chiffre = vGroupe1->chiffre;
    afficheGroupe(vGroupe1);
    afficheGroupe(vGroupe2);
    free(vGroupe1);
    free(vGroupe2);
}