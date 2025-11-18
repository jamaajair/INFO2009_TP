#include <stdio.h>


int main(int argc, char const *argv[])
{
    int x = 42, y = 21;
    int z = x++ + --y;  // Post-increment and pre-decrement
    printf("a) x = %d, y = %d, z = %d\n", x, y, z);

    z -= x++ && y++ ? 1 : 2;
    printf("b) x = %d, y = %d, z = %d\n", x, y, z);

    z += ++x && ++y ? 1 : 2;
    printf("c) x = %d, y = %d, z = %d\n", x, y, z);

    z = x > 0 || !++y ? x++ : ++x;
    printf("d) x = %d, y = %d, z = %d\n", x, y, z);

    z = (x++, x > 0) ? !x : 1 - !x;
    printf("e) x = %d, y = %d, z = %d\n", x, y, z);

    return 0;
}
