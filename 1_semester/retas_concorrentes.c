/******************************************************************************
ler a equacao de 2 retas. Ver se elas se cruzam, e onde se cruzam, em qual eixo
*******************************************************************************/
#include <stdio.h>

int main()
{
    float a1, b1, c1, a2, b2, c2, m1, m2, x, y;
    printf("O programa a seguir vai ler duas retas digitadas pelo usuário na forma 'ax + by + c = 0', e falar se elas se cruzam, e caso positivo, onde se cruzam.");
    printf("Digite os coeficientes da primeira reta, a, b, c, respectivamente: ");
    scanf("%f %f %f", &a1, &b1, &c1);
    printf("Agora, digite os coeficientes da segunda reta, do mesmo modo: ");
    scanf("%f %f %f", &a2, &b2, &c2);
    
    //y = (-ax -c)/b
    
    m1 = -a1/b1;
    m2 = -a2/b2;
    
    if(m1 == m2){
        printf("As retas são paralelas");
    }else{
        
        x = ((c2*b1) - (c1*b2))/((a1*b2) - (a2*b1));
        y = (-a1*x -c1)/b1;
        
        
        printf("As retas se cruzam em 1 ponto,");
        if(x > 0){
            if(y >= 0){
                printf(" no 1° quadrante");
            }else{
                printf(" no 4° quadrante");
            }
        }else{
            if(y >= 0){
                printf(" no 2° quadrante");
            }else{
                printf(" no 3° quadrante");
            }
        }
    }
    return 0;
}

