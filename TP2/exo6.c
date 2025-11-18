#include <stdio.h>

int main() {
    long long z;   
    int compteur = 0;

    printf("Entrez un nombre entier (> 1) : ");
    scanf("%lld", &z);

    if (z <= 1)
    {
        printf("Le nombre doit être supérieur à 1.\n");
        return 0;
    }
    
    while (z > 1) {
        if (z % 2 == 0) {
            z = z / 2;
        } else {
            z = 3 * z + 1;
        }
        compteur++;
    }

    printf("Nombre d'étapes pour atteindre 1 : %d\n", compteur);
    return 0;
}
