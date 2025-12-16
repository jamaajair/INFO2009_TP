
#include <stdio.h>

unsigned f_iter(char *s)
{
    unsigned r = 0;

    while (*s) {
        if (*s != ' ' && *s != '\n')
            r++;
        s++;
    }

    return r;
}


int main(int argc, char const *argv[])
{
    char str[] = "hello world\nthis is a test";
    unsigned count = f_iter(str);
    printf("The number of non-space characters in the string is: %u\n", count);
    return 0;
}
