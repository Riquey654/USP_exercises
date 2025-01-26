#include <stdio.h>

int main()
{
    int tempo;
    float velocidadeA, velocidadeB;
    float amais;
    int corridas;
    
    scanf("%d", &corridas);
    for(int a = 1; a <= corridas; a++){
    
    scanf("%f %f %d", &velocidadeA, &velocidadeB, &tempo);
    float distanciaA = velocidadeA*tempo;
    float distanciaB = velocidadeB*tempo;
    
    if(tempo == 0){
                    printf("A corrida ainda nao comecou\n");
    }else{
        if(velocidadeA != 0){
            if(velocidadeB == 0){
                printf("O piloto B desistiu inesperadamente\n");
            }else{
                if(tempo < 0){
                printf("De alguma forma os pilotos voltaram no tempo\n");
                }else{
                    if(tempo == 0){
                        printf("A corrida ainda nao comecou\n");
                    }else{
                        if (velocidadeA > velocidadeB) {
                            amais = distanciaA - distanciaB;
                        printf("O kart A venceu e percorreu %.2fkm a mais que o kart B\n", amais);
                        }else{
                            if(velocidadeA < velocidadeB){
                                amais = distanciaB - distanciaA;
                                printf("O kart B venceu e percorreu %.2fkm a mais que o kart A\n", amais);
                            }else{
                                printf("Os karts empataram, percorrendo cada %.2fkm\n", distanciaA);
                            }
                        }
                    }
                }   
            } 
        }else{
            if(velocidadeA == 0 && velocidadeB == 0)
                printf("Os dois pilotos nao querem competir\n");
            else{
                printf("O piloto A desistiu inesperadamente\n");
            }
        
        }
    }
    }
    return 0;
}




