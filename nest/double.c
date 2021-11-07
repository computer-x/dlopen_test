#include <stdio.h>
#include "add.h"


int print_add(int a, int b)
{
    int c = add(a, b);
    printf("a=%d, b=%d, a+b=%d\n", a, b, c);

    return 0;
}
