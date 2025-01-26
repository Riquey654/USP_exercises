/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int num, num1, num2, num3;
    char a, b, c, d;
    
    
    scanf("%d", &num);
    
    a = 255 & num;
    num1 = num >> 8;
    b = 255 & num1;
    num2 = num >> 16;
    c = 255 & num2;
    num3 = num >> 24;
    d = 255 & num3;
    printf("%c%c%c%c\n", d, c, b, a);
    
    return 0;
}
