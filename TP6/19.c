
#include <stdio.h>
#include <stdlib.h>

int *entrelace(const int *t1, const int *t2, unsigned n)
{
    int *res;
    unsigned i;

    res = malloc(2 * n * sizeof(int));
    if (!res)
        return NULL;

    for (i = 0; i < n; i++) {
        res[2 * i]     = t1[i];
        res[2 * i + 1] = t2[i];
    }

    return res;
}



int main(int argc, char const *argv[])
{
    int t1[] = {1, 3, 5};
    int t2[] = {2, 4, 6};
    unsigned n = 3;
    int *result = entrelace(t1, t2, n);
    if (result) {
        for (unsigned i = 0; i < 2 * n; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
        free(result);
    } else {
        printf("Erreur dans L'Allocation mémoire\n");
    }
    return 0;
}
