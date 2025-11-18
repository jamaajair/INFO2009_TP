
#include <stdio.h>
#include <stdlib.h>

void Bienvenue(int id) {
    printf("*********************************************\n\n");
    printf("\t Bienvenue, votre id est : %d !\n\n", id);
    printf("====== Noos allons prodéder aux calculs =====\n\n");
}

void AfficherTableau(int tableau[], int taille) {
    printf("Contenu du tableau :\n");
    printf("[");
    for (int i = 0; i < taille; i++) {
        printf(" %d ", tableau[i]);
    }
    printf("]\n");
}

int Produit(int T[], int N){
    int produit = 1;
    
    for (int i = 0; i < N; i++)
    {
        produit *= T[i];
    }
    return produit;
}



int Somme(int table[], int N){

    int somme = 0;
    int i;
    for( i = 0; i<N; i++){
        somme += table[i];
    }

    return somme;
}

int Max(int tableau[], int Size){
    int max = tableau[0]; 

    for (int i = 1; i < Size; i++)
    {
        if(tableau[i] > max){
            max  = tableau[i];
        }
    }
    return max;
}

int Min(int tableau[], int Size){
    int min = tableau[0]; 

    for (int i = 1; i < Size; i++)
    {
        if(tableau[i] < min){
            min  = tableau[i];
        }
    }
    return min;
}

int Moyenne(int tableau[], int N){
    return Somme(tableau, N) / N;

}



int main() {


    int id; 
    printf("Entrez votre identifiant : ");
    scanf("%d", &id);

    int tableau[10];

    for (int i = 0; i < 10; i++) {
        tableau[i] = rand() %10;
    }


    Bienvenue(id);

    AfficherTableau(tableau, 10);

    int produit = Produit(tableau, 10);
    int somme = Somme(tableau, 10);
    int max = Max(tableau, 10);
    int min = Min(tableau, 10);
    int moyenne = Moyenne(tableau, 10);

    printf("**************** Résultats des calculs ****************\n\n");
    printf("Somme des éléments : %d\n\n", somme);
    printf("Moyenne des éléments : %d\n\n", moyenne);
    printf("Valeur maximale : %d\n\n", max);
    printf("Valeur minimale : %d\n\n", min);
    printf("Produit des éléments : %d\n\n", produit);
    printf("*******************************************************\n\n");
    printf("Merci %d pour choisir notre programme !\n\n", id);
    
    return 0;
}

