#include <stdio.h>

long f(int *t)
{
    if (!t[0])
        return 1;
    return t[0] * f(t + 1);
}

int main()
{
    // 1)
//     // a)
//     int x[2] = { 0, 0 };
//     int *y;
//     y = x;
//     (++y)[0] = 1;
//     printf("%d %d\n", x[0], x[1]);

//     // b)
//     int a, b, *c;
//     a = 1;
//     b = 2;
//     c = &a;
//     a += *c;
//     c = &b;
//     *c-- = 3;
//     printf("%d %d\n", a, b);

    // c
    struct MyStruct {
        int val;
        int *adr;
    } x, *y;

    x.adr = &x.val;   
    y = &x;           

    x.val = 41;       
    y->val = 42;   

    // printf("%d\n", *(y->adr)); 

//  2)
    // int a[] = { 1, 0 };
    // int *b[2];
    // int **c;
    // b[*a] = a + 1;
    // c = b;
    // printf("%d\n", **++c);

    // 3)
    // int t[2] = { 1, 2 };
    // int *a, **b;
    // a = t + *t;
    // b = &a;
    // printf("%d\n", *--*b);

    // 4)
    // int t[2] = { -2, 0 };
    // int *a, b;
    // b = *t ? ++*t : --*t;
    // a = &b;
    // printf("%d\n", a[*(t + 1)]);

    // 5)
    // char s[] = "42", *t = "1", *u; 
    // u = s;
    // *++u -= (*t) + 1; // *t = '1' ASCII '1' = 49  => '1' + 1 = 50 => 0 => 0 = caractère '\0'
    // printf("[%s]\n", s);

    return 0;
}
