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
    float a, b, c;
    float arit;
    float geo;
    float har;
    scanf("%f %f %f", &a, &b, &c);
    arit = (a+b+c)/3;
    geo = pow((a*b*c),1.0/3.0);
    har = (3)/((1/a)+(1/b)+(1/c));
    printf("Media aritimetica: %.4f\n",arit);
    printf("Media harmonica: %.4f\n",har);
    printf("Media geometrica: %.4f\n",geo);

    return 0;
}
