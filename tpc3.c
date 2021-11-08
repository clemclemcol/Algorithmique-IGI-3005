//https://perso.esiee.fr/~bureaud/E3ST/CStandardLibrary_RossRichardson.pdf

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 2222
/*
//1.2
int main (){
    struct { char lettre; int chiffre; } vGroupe1, vGroupe2;

    vGroupe1.lettre = 'J';
    vGroupe1.chiffre = 1;
    vGroupe2=vGroupe1; // que si vGroupe1 et 2 sont créés ensemble!

    printf("%c%d\n", vGroupe1.lettre, vGroupe1.chiffre);
    printf("%c%d\n", vGroupe2.lettre, vGroupe2.chiffre);
}

//2.1
typedef struct { char lettre ; int chiffre ; } Groupe;

void afficheGroupe(const Groupe pGroupe){
    printf("%c%d\n", pGroupe.lettre, pGroupe.chiffre);
}

Groupe saisieGroupe(){
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

int main (){
    Groupe vGroupe1, vGroupe2;
    vGroupe1 = saisieGroupe();
    vGroupe2.lettre = vGroupe1.lettre;
    vGroupe2.chiffre = vGroupe1.chiffre;
    afficheGroupe(vGroupe1);
    afficheGroupe(vGroupe2);
}

//3.1 et 3.2
typedef struct { char lettre ; int chiffre ; } Groupe;

void afficheGroupe(const Groupe* pGroupe){
    printf("%c%d\n", pGroupe->lettre, pGroupe->chiffre);
}

Groupe saisieGroupe(){
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

int main (){
    Groupe vGroupe1, vGroupe2;
    vGroupe1 = saisieGroupe();
    vGroupe2.lettre = vGroupe1.lettre;
    vGroupe2.chiffre = vGroupe1.chiffre;
    afficheGroupe(&vGroupe1);
    afficheGroupe(&vGroupe2);
}


//4.2
typedef Chaine30 char[30];
typedef struct { Chaine30 nom; Chaine30 prenom; int promo; }  Etudiant;


void afficheEtudiant(Etudiant* pEtudiant){
    printf("%s\t%s\t%d\n", pEtudiant->nom, pEtudiant->prenom, pEtudiant->promo);
}

int calculLongueur(char* pChaine){
    int vCompt = 0;
    while (pChaine[vCompt]!='\0'){
        if (pChaine[vCompt] == '\n'){
            pChaine[vCompt] = '\0';
        }
        vCompt ++;
    }
    return vCompt;
}

Etudiant saisieEtudiant(){
    Etudiant vEtudiant;
    char c;
    int vLong;
    do{
        printf("Entrez le nom:");
        fgets(vEtudiant.nom, 30, stdin);
        vLong = calculLongueur(vEtudiant.nom);
    }while(!isupper(vEtudiant.nom.lettre[0]) && !isupper(vEtudiant.prenom[vLong]));
    
    do{
        printf("Entrez le prenom:");
        fgets(vEtudiant.prenom, 30, stdin);
        vLong = calculLongueur(vEtudiant.prenom);
    }while(!isupper(vEtudiant.prenom[0]) && !islower(vEtudiant.prenom[vLong]));

    do{
        printf("Entrez le numero de l'annee d'etude:");
        scanf("%d", &vEtudiant.promo);
    }while (vEtudiant.promo > 6);
    
    afficheEtudiant(&vEtudiant);
    return vEtudiant;
}

int main (){
    Etudiant vEtudiant;
    vEtudiant = saisieEtudiant();
    afficheEtudiant(&vEtudiant);
}



//5.2
typedef char Chaine30[30];
typedef struct { Chaine30 nom; Chaine30 prenom; int promo; }  Etudiant;
typedef Etudiant Esiee[MAX];

void afficheEtudiant(Etudiant* pEtudiant){
    printf("%s\t%s\t%d\n", pEtudiant->nom, pEtudiant->prenom, pEtudiant->promo);
}

int calculLongueur(char* pChaine){
    int vCompt = 0;
    int vLong =0;
    while (pChaine[vCompt]!='\0'){
        if (pChaine[vCompt] == '\n'){
            pChaine[vCompt] = '\0';
        }
        vCompt ++;
    }
}

Etudiant saisieEtudiant(){
    Etudiant vEtudiant;
    char c;
    int vLong;
    
    do{
        printf("Entrez le nom:");
        fgets(vEtudiant.nom, 30, stdin);
        vLong = calculLongueur(vEtudiant.nom);
        vEtudiant.nom[0] = toupper(vEtudiant.nom[0]);
        vEtudiant.nom[vLong] = tolower(vEtudiant.nom[vLong]);
    }while (vEtudiant.nom[0]=='\0');
    
    do{
        printf("Entrez le prenom:");
        fgets(vEtudiant.prenom, 30, stdin);
        vLong = calculLongueur(vEtudiant.prenom);
        vEtudiant.prenom[0] = toupper(vEtudiant.prenom[0]);
        vEtudiant.prenom[vLong] = tolower(vEtudiant.prenom[vLong]);
    }while(vEtudiant.prenom[0]=='\0');

    do{
        printf("Entrez le numero de l'annee d'etude:");
        scanf("%d", &vEtudiant.promo);
    }while (vEtudiant.promo > 6);
    
    afficheEtudiant(&vEtudiant);
    return vEtudiant;
}

int main (){
    Esiee vEcole;
    vEcole[0] = saisieEtudiant();
    vEcole[2] = saisieEtudiant();
    vEcole[1] = vEcole[0];
    afficheEtudiant(&vEcole[0]);
    afficheEtudiant(&vEcole[1]);
    afficheEtudiant(&vEcole[2]);
}

*/
//5.3
typedef char Chaine30[30];
typedef struct { Chaine30 nom; Chaine30 prenom; int promo; }  Etudiant;
typedef Etudiant Esiee[MAX];

void afficheEtudiant(Etudiant* pEtudiant){
    printf("%s\t%s\t%d\n", pEtudiant->nom, pEtudiant->prenom, pEtudiant->promo);
}

int calculLongueur(char* pChaine){
    int vCompt = 0;
    while(pChaine[vCompt] != '\0'){
        if (pChaine[vCompt] == '\n'){
            pChaine[vCompt] = '\0';
            return vCompt;
        }
        vCompt ++;
    }
    return vCompt;
}

void changeNom(Etudiant* pEtudiant, int pLong){
    for(int i = 0; i < pLong; i++){
        pEtudiant->nom[i] = toupper(pEtudiant->nom[i]);
    }
}

void changePrenom(Etudiant* pEtudiant, int pLong){
    pEtudiant->prenom[0] = toupper(pEtudiant->prenom[0]);
    for(int i = 1; i < pLong; i++){
        pEtudiant->prenom[i] = tolower(pEtudiant->prenom[i]);
    }
}

Etudiant saisieEtudiant(){
    Etudiant vEtudiant;
    int vLong;
    
    do{
        printf("Entrez le nom:");
        fgets(vEtudiant.nom, 30, stdin);
        vLong = calculLongueur(vEtudiant.nom);
        changeNom(&vEtudiant, vLong);
    }while (vEtudiant.nom[0]=='\0');
    
    do{
        printf("Entrez le prenom:");
        fgets(vEtudiant.prenom, 30, stdin);
        vLong = calculLongueur(vEtudiant.prenom);
        changePrenom(&vEtudiant, vLong);
    }while(vEtudiant.prenom[0]=='\0');

    do{
        printf("Entrez le numero de l'annee d'etude:");
        scanf("%d", &vEtudiant.promo);
    }while (vEtudiant.promo > 6);
    
    afficheEtudiant(&vEtudiant);
    return vEtudiant;
}


int main (){
    Esiee vEcole;
    vEcole[0] = saisieEtudiant(); 
    vEcole[1] = saisieEtudiant();
    vEcole[2] = saisieEtudiant();
    printf("\n");
    for(int i = 0; i < 3-1; i++){
        for (int j = 1; j < 3; j++){
            if ((i != j) && (strcmp(vEcole[i].nom, vEcole[j].nom) == 0)){
                afficheEtudiant(&vEcole[i]);
                afficheEtudiant(&vEcole[j]);
            }
        }
    }
    
}