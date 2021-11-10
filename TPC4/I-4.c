#include <stdio.h>
#include <stdlib.h>

int main(void){
    double *vReel = malloc(sizeof(double));
    if (vReel == NULL){
        printf("Allocation échouée.");
        return 0;
    }
    else {
        *vReel = 4.0/3.0;
        *vReel *= 2;
        printf("%f\n", *vReel);
        printf("%p\n", vReel);
        free(vReel);
        printf("%f\n", *vReel);
        vReel = NULL;
        printf("%p\n", vReel);
    }
}