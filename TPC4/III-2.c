#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h> // NE PAS OUBLIER -lm A LA COMPILATION

typedef double *TabDyn; 

void initTab(TabDyn pTab, const int pTaille){
    for(int i = 0; i < pTaille; i++){
            pTab[i] = sqrt(i);
    }

}

void afficheTab(const TabDyn pTab, const int pTaille){
    for(int i = 0; i < pTaille; i++){
            printf("%f\t", pTab[i]);
    }
}

double moyenne(const TabDyn pTab, const int pTaille){
    int vMoy = 0;
        for(int i = 0; i < pTaille; i++){
            vMoy += pTab[i];

        }
    return vMoy;
}

int main(void){
    int vTaille = 0;
    printf("Entrez la taille du tableau voulu:");
    scanf("%d", &vTaille);

    TabDyn vTab = malloc(vTaille*sizeof(double));
    if (vTab == NULL){
        printf("Allocation incorrecte.\n");
    }
    else {
        initTab(vTab, vTaille);
        afficheTab(vTab, vTaille);
        double vMoy = moyenne(vTab, vTaille);
        
        printf("\nLa valeur moyenne est %f.\n", vMoy);
        free(vTab);
        for(int i = 0; i < vTaille; i++){
            printf("%f\t", vTab[i]);
       }
    }

}