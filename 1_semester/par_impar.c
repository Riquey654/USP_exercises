/******************************************************************************

Par ou impar

*******************************************************************************/
#include <stdio.h>

int main()
{
    char jogador1[10];
    char jogador2[10];
    int decis,numpartidas;
    int num1, num2, soma;
    
    scanf("%s %s", jogador1, jogador2);
    scanf("%d",&decis);
    scanf("%d", &numpartidas);
    for(int i = 1; i <= numpartidas; i++) {
        scanf("%d %d", &num1, &num2);
        if(num1 == 0 && num2 == 0) {
            printf("Refazendo a rodada\n");
            i--;
        }else{
            //decis == 0, jogador 1 é par
            if(decis == 0) {
                soma = num1 + num2;
                if(soma % 2 == 0) {
                    printf("%s venceu!\n",jogador1 );
                }else{
                    printf("%s venceu!\n", jogador2);
                }
            }else{
                soma = num1 + num2;
                if(soma % 2 == 0) {
                    printf("%s venceu!\n",jogador2 );
                }else{
                    printf("%s venceu!\n", jogador1);
                }
            }
        }
    }
    return 0;
}






