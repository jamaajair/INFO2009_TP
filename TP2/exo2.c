#include<stdio.h>
 
int main()
{
    int i = 0, j = 0;
    while (i < 1000)
    {
        if (f(i) > f(j)){
            continue;
        }
        j += i;
    }
   
    
}
