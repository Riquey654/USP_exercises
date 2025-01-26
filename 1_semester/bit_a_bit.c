/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int A, B;
    scanf("%d %d", &A, &B);
    int a, b, c, d, e, f;
    a = A & B;
    b = A | B;
    c = A ^ B;
    d = ~A;
    e = A >> 2;
    f = B << 1;
    printf("A and B: %d\n",a);
    printf("A or B: %d\n",b);
    printf("A xor B: %d\n",c);
    printf("not A: %d\n",d);
    printf("A right shift 2: %d\n",e);
    printf("B left shift 1: %d\n",f);

    return 0;
}
