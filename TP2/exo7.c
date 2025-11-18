#include <stdio.h>

int main() {


     // n! / (m!*(n-m)!)
    int n, m;
    int fact_n = 1, fact_m = 1, fact_nm = 1;
    int resultat;

    printf("Entrez la valeur de n : ");
    scanf("%d", &n);

    printf("Entrez la valeur de m : ");
    scanf("%d", &m);

    if (m < 0 || m > n) {
        printf("Erreur : il faut que 0 <= m <= n.\n");
        return 0;
    }

    // n!
    for (int i = 1; i <= n; i++) {
        fact_n = fact_n * i;
    }

    // m!
    for (int i = 1; i <= m; i++) {
        fact_m = fact_m * i;
    }

    // (n - m)!
    // int nm = n - m;
    for (int i = 1; i <= n - m; i++) {
        fact_nm = fact_nm * i;
    }

    // C(n, m) = n! / (m! * (n - m)!)
    resultat = fact_n / (fact_m * fact_nm);

    printf("C(%d, %d) = %lld\n", n, m, resultat);

    return 0;
}
