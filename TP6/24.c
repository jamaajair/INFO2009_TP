#include <stdio.h>
#include <stdlib.h>


typedef struct element {
    int value;
    struct element *next;
} element;

element *build_buffer(const int *t, unsigned n)
{
    element *first = NULL;
    element *prev = NULL;
    element *curr;
    unsigned i;

    for (i = 0; i < n; i++) {
        curr = malloc(sizeof(element));
        if (!curr)
            return NULL;   /* gestion simple d’erreur */

        curr->value = t[i];
        curr->next = NULL;

        if (!first)
            first = curr;
        else
            prev->next = curr;

        prev = curr;
    }

    /* rendre la structure circulaire */
    prev->next = first;

    return first;
}

int sum_buffer(const element *first)
{
    int sum = 0;
    const element *p = first;

    if (!first)
        return 0;

    do {
        sum += p->value;
        p = p->next;
    } while (p != first);

    return sum;
}


void free_buffer(element *first)
{
    element *p, *next;

    if (!first)
        return;

    p = first->next;
    while (p != first) {
        next = p->next;
        free(p);
        p = next;
    }

    free(first);
}


int main(int argc, char const *argv[])
{
    
    int t[] = {1, 2, 3, 4, 5};
    unsigned n = 5;
    element *buffer = build_buffer(t, n);
    if (!buffer) {
        printf("Erreur dans L'Allocation mémoire\n");
        return 1;
    }
    int total = sum_buffer(buffer);
    printf("La somme des éléments dans le buffer circulaire est : %d\n", total);
    free_buffer(buffer);

    return 0;
}
