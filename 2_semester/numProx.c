#include <stdio.h>
#include <stdlib.h>

void resultado(int tamsequencia, int num[], int valoralvo);

void resultado(int tamsequencia, int num[], int valoralvo) {
    int soma = 0;
    //2 em 2 
    for(int j = 0; j < tamsequencia - 1; j++) {
        soma = num[j] + num[j + 1];
        if(soma == valoralvo) {
            printf("%d %d\n", j + 1, j + 2);
        }
    }
    //3 em 3 
    for(int j = 0; j < tamsequencia - 2; j++) {
        soma = num[j] + num[j + 1] + num[j + 2];
        if(soma == valoralvo) {
            printf("%d %d\n", j + 1, j + 3);
        }
    }
    //4 em 4 
    for(int j = 0; j < tamsequencia - 3; j++) {
        soma = num[j] + num[j + 1] + num[j + 2] + num[j + 3];
        if(soma == valoralvo) {
            printf("%d %d\n", j + 1, j + 4);
        }
    }
    //5 em 5 
    for(int j = 0; j < tamsequencia - 4; j++) {
        soma = num[j] + num[j + 1] + num[j + 2] + num[j + 3] + num[j + 4];
        if(soma == valoralvo) {
            printf("%d %d\n", j + 1, j + 5);
        }
    }
    
}

int main()
{
    int tamsequencia;
    scanf("%d", &tamsequencia);
    int *num = (int*)malloc(tamsequencia * sizeof(int));
    int valoralvo;
    for(int i = 0; i < tamsequencia; i++) {
        scanf("%d", &num[i]);
    }
    scanf("%d", &valoralvo);
    resultado(tamsequencia, num, valoralvo);
    free(num);
    

    return 0;
}
