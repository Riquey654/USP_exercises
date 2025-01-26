/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    char digito;
    scanf("%c", &digito);
    if(('A' <= digito && digito <= 'Z') || ('a' <= digito && digito <= 'z')){
    
        if(digito == 'a' || digito == 'e' || digito == 'i' || digito == 'o' || digito == 'u' || digito == 'A' || digito == 'E' || digito == 'I' || digito == 'O' || digito == 'U') {
            printf("Eh uma vogal");
        }else{
            printf("Eh uma consoante");
        }}
    else 
        printf("Nao eh uma letra do alfabeto");
    
    return 0;
}

