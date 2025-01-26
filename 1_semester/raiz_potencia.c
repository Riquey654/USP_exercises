/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <math.h>

int main()
{
    int num;
    scanf("%d", &num);
    double pot = pow(num,10);
    double raiz = sqrt(num);
    printf("Numero: %d\n", num);
    printf("         %5.2e\n", pot);
    printf("        %5.2f\n", raiz);
    return 0;
}

