/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>
int main()
{
    int numA;
    int numB;
    scanf("%d", &numA);
    scanf("%d", &numB);
    bool X = numA > numB;
    bool Y = numA % 2 == 0;
    bool Z = !(numB % 3 == 0);
    bool W = (numA > numB && numA % 2 == 0);
    bool V = (numA > numB || numA % 2 == 0);
    printf("A > B: %d\n", X);
    printf("A eh par: %d\n", Y);
    printf("B NAO eh multiplo de 3: %d\n", Z);
    printf("A > B e A eh par: %d\n", W);
    printf("A > B ou A eh par: %d\n", V);

    return 0;
}
