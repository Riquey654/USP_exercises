/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
/*declarar variaveis. switch para ver qual a figura. case e dentro calcula cada um.*/
#include <stdio.h>

int main()
{
    char figura;
    float base, altura, raio, area;
    scanf("%c", &figura);
    switch (figura)
    {
     case 'q':
     scanf("%f", &base);
     area = base*base;
     printf ("%.2f", area);
     break;
     
     case 'r':
     scanf("%f %f", &base, &altura);
     area = base*altura;
     printf("%.2f", area);
     break;
     
     case 't':
     scanf("%f %f", &base, &altura);
     area = (base*altura)/2;
     printf("%.2f", area);
     break;
     
     case 'c':
     scanf("%f", &raio);
     area = (raio*raio)*3.14;
     printf("%.2f", area);
     break;
     
     default:
     break;
    }
    return 0;
}
