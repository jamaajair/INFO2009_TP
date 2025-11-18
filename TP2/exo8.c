#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Entrez un nombre entier : ");
    scanf("%d", &n);



    for (int i = 2; i <= n; i++) {
        int puissance = 0;

        // combien de x i divide n 
        while (n % i == 0) {
            puissance++;
            n = n / i;
        }

        if (puissance > 0) {
            if (puissance == 1)
                printf("%lld ", i);
            else
                printf(" %d ^  %d ", i, puissance);
        }
    }

    // si il est premier 
    if (n > 1)
        printf("%d", n);

    return 0;
}
