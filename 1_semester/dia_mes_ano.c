/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
  int ano, mes, dia;
  scanf("%*[a-z]");
  scanf("%3x%2d%2o", &ano, &mes, &dia);
  printf("Data: %02d/%02d/%04d\n", dia, mes, ano);
    return 0;
}

