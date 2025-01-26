#include <stdio.h>
#include <string.h>
#include <math.h>

int stringtoint(char *string, int base);

int stringtoint(char *string, int base) {
    //tranformar o número que esta em string para um int em decimal
    
    //strlen indica as unidades...strlen - 1 indica as dezenaas...
    
    int numdecimal = 0;
    int elevado = 0;
    //fazer um switch case para receber a base e tranformar para decimal
    
    switch(base) {
        case 2:
            for(int i = strlen(string) - 1; i >= 0; i--) {
                float mult2;
                //adiciona-se 1 à variavel 'elevado' a cada iteração
                mult2 = pow(2,elevado);
                numdecimal = numdecimal + (string[i] - 48) * mult2; 
                //-48 pq de acordo com a tabela ascii
                elevado++;
            }
            break;
            
        case 3:
            for(int i = strlen(string) - 1; i >= 0; i--) {
                float mult3;
                //adiciona-se 1 à variavel 'elevado' a cada iteração
                mult3 = pow(3,elevado);
                numdecimal = numdecimal + (string[i] - 48) * mult3; 
                //-48 pq de acordo com a tabela ascii
                elevado++;
            }
            break;
            
        case 4:
            for(int i = strlen(string) - 1; i >= 0; i--) {
                float mult4;
                //adiciona-se 1 à variavel 'elevado' a cada iteração
                mult4 = pow(4,elevado);
                numdecimal = numdecimal + (string[i] - 48) * mult4; 
                //-48 pq de acordo com a tabela ascii
                elevado++;
            }
            break;
            
        case 5:
            for(int i = strlen(string) - 1; i >= 0; i--) {
                float mult5;
                //adiciona-se 1 à variavel 'elevado' a cada iteração
                mult5 = pow(5,elevado);
                numdecimal = numdecimal + (string[i] - 48) * mult5; 
                //-48 pq de acordo com a tabela ascii
                elevado++;
            }
            break;
            
        case 6:
            for(int i = strlen(string) - 1; i >= 0; i--) {
                float mult6;
                //adiciona-se 1 à variavel 'elevado' a cada iteração
                mult6 = pow(6,elevado);
                numdecimal = numdecimal + (string[i] - 48) * mult6; 
                //-48 pq de acordo com a tabela ascii
                elevado++;
            }
            break;
            
        case 7:
            for(int i = strlen(string) - 1; i >= 0; i--) {
                float mult7;
                //adiciona-se 1 à variavel 'elevado' a cada iteração
                mult7 = pow(7,elevado);
                numdecimal = numdecimal + (string[i] - 48) * mult7; 
                //-48 pq de acordo com a tabela ascii
                elevado++;
            }
            break;
            
        case 8:
            for(int i = strlen(string) - 1; i >= 0; i--) {
                float mult8;
                //adiciona-se 1 à variavel 'elevado' a cada iteração
                mult8 = pow(8,elevado);
                numdecimal = numdecimal + (string[i] - 48) * mult8; 
                //-48 pq de acordo com a tabela ascii
                elevado++;
            }
            break;
            
        case 9:
            for(int i = strlen(string) - 1; i >= 0; i--) {
                float mult9;
                //adiciona-se 1 à variavel 'elevado' a cada iteração
                mult9 = pow(9,elevado);
                numdecimal = numdecimal + (string[i] - 48) * mult9; 
                //-48 pq de acordo com a tabela ascii
                elevado++;
            }
            break;
        
    }
    return numdecimal;
    
    
}

int main()
{
    char string[99];
    int base;
    int resposta;
    printf("Digite, em ordem, uma string somente com dígitos, e a sua base. Após isso, essa string será convertida para um número em decimal.")
    scanf("%s %d",string, &base);
    resposta = stringtoint(string, base);
    printf("%d", resposta);

    return 0;
}
