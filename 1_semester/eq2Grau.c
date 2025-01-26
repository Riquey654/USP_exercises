/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <math.h>
// eq de 2 grau
int main()
{
    int a;
    int b;
    int c;
    int x;
    long int y;
    scanf("%d %d %d %d", &a, &b, &c, &x);
    y = a*(pow(x,2)) + b*x + c;
    printf("%ld\n", y);

    return 0;
}
