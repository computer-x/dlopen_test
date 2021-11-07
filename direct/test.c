#include <stdio.h>
#include "add.h"

int aaa = 0;

int main()
{
    int a = 10, b = 100;
    int c = add(a, b);
    printf("a=%d, b=%d, a+b=%d\n", a, b, c);

    return 0;
}
