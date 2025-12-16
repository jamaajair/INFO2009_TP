#include <stdio.h>

unsigned f_iter(char *s, char c)
{
    unsigned r = 0;

    while (*s) {
        if (*s == c)
            ++r;
        ++s;
    }

    return r;
}



int main(int argc, char const *argv[])
{
    char str[] = "hello world";
    char ch = 'o';
    unsigned count = f_iter(str, ch);
    printf("The character '%c' appears %u times in the string \"%s\".\n", ch, count, str);
    return 0;
}
