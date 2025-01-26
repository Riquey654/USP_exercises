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
    int binario;
    int resto, resto1, resto2;
    int a, b, c, d;
    int decimal;
    scanf("%d", &binario);
    resto = binario%1000;
    a = binario/1000;
    
    resto1 = resto%100;
    b = resto/100;
    
    resto2 = resto1%10;
    c = resto1/10;
    
    d = resto2/1;
    
    decimal = a*pow(2,3)+ b*pow(2,2)+ c*pow(2,1)+ d*pow(2,0);
    printf("%d", decimal);

    return 0;
}



