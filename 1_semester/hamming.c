#include <stdio.h>

void bin1(int num, int binario1[10]);
void bin2(int num, int binario2[10]);
void ham(int binario1[10], int binario2[10], int *contador);

void bin1(int num, int binario1[10])
{
    
    for(int i = 9; i >= 0; i--) {
        if(num % 2 == 0) {
            binario1[i] = 0;
            num = num / 2;
        }else{
            binario1[i] = 1;
            num = num / 2;
        }
            
    }
}
void bin2(int num, int binario2[10])
{
        for(int i = 9; i >= 0; i--) {
            if(num % 2 == 0) {
                binario2[i] = 0;
                num = num / 2;
            }else{
                binario2[i] = 1;
                num = num / 2;
            }
                
        }
        
    
}
void ham(int binario1[10], int binario2[10],int *contador)
{
    for(int i = 0; i < 10; i++) {
        if(binario1[i] != binario2[i])
            (*contador)++;
    }
}



int main()
{
    int contador = 0;
    int num1, num2;
    int binario1[10];
    int binario2[10];
    scanf("%d %d", &num1, &num2);
    bin1(num1,binario1);
    bin2(num2, binario2);
    ham(binario1, binario2, &contador);
    
    printf("%d", contador);

    return 0;
}



