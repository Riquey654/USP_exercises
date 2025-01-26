/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    float euc, man;
    float X, Y, x, y;
    scanf("%f%f\n %f%f", &X, &Y, &x, &y);
    euc = sqrt(pow(X-x,2)+pow(Y-y,2));
    man = fabs(X-x)+ fabs(Y-y);
    printf("Distancia euclidiana: %.3f\n",euc);
    printf("Distancia Manhattan: %.3f\n",man);

    return 0;
}
