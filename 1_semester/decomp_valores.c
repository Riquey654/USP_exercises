/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int entrada, a, b, c, d, e, f, g;
    int resto;
    
    scanf("%d", &entrada);
    
    a = entrada/100;
    resto = entrada%100;
    printf("%d nota(s) de R$ 100\n",a);
    
    b = resto/50;
    resto = resto%50;
    printf("%d nota(s) de R$ 50\n",b);
    
    c = resto/20;
    resto = resto%20;
    printf("%d nota(s) de R$ 20\n",c);
    
    d = resto/10;
    resto = resto%10;
    printf("%d nota(s) de R$ 10\n",d);
    
    e = resto/5;
    resto = resto%5;
    printf("%d nota(s) de R$ 5\n",e);
    
    f = resto/2;
    resto = resto%2;
    printf("%d nota(s) de R$ 2\n",f);
    
    g = resto/1;
    resto = entrada%1;
    printf("%d moeda(s) de R$ 1\n",g);

    return 0;
}
