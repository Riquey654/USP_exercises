/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
/*declarar lados do triangulo, verificar se é triangulo, se for triangulo, switch para descobrir se é equilatero, isosceles ou escaleno*/
int main()
{
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    if (A >= B+C || B >= A+C || C >= A+B)
     printf("INVALIDO\n");
    else
     if(A == B && B == C)
      printf("EQUILATERO\n");
      
     else if(A == B || B == C || A == C)
      printf("ISOSCELES\n");
      
     else
      printf("ESCALENO");
     
    return 0;
}
