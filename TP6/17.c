#include <stdlib.h>
#include <stdio.h>

unsigned my_strlen(const char *s)
{
    unsigned n = 0;
    while (s[n])
        n++;
    return n;
}

char *concat(const char *s1, const char *s2)
{
    unsigned n1, n2;
    unsigned i, j;
    char *res;

    // il nous la taille des deux chaines, vous n'avez pas le droit d'utiliser strlen, il faut la coder vous même !
    n1 = my_strlen(s1); 
    n2 = my_strlen(s2);

    res = malloc(n1 + n2 + 1);
    if (!res)
        return NULL;

    for (i = 0; i < n1; i++)
        res[i] = s1[i];

    for (j = 0; j < n2; j++)
        res[i + j] = s2[j];

    res[n1 + n2] = '\0';

    return res;
}

int main(int argc, char const *argv[])
{
    // test

    char *s1 = "Hello, ";
    char *s2 = "World!";
    char *result = concat(s1, s2);
    if (result) {
        printf("%s\n", result);
        free(result);
    } else {
        printf("Memory allocation failed\n");
    }

    return 0;
}
