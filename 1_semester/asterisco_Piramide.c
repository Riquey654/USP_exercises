/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int n;
   
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        for(int k = n - 1; k >= i; k--){
            printf(" ");
        }
        for(int j = 1; j <= i ; j++) {
        printf("**");
        }
    printf("\n");
    }

    return 0;
}
/*5
     **
    ****
   ******
  ********
 ***********/