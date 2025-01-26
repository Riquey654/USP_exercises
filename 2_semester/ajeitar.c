#include <stdio.h>
#include <string.h>

struct registro {
    char nome[13];
    int idade;
    float altura;
    int indiceini;
};

void swap(int *num1, int *num2);
void insertion_sort(int n, struct registro pessoas[n]);

void swap(int *num1, int *num2) {
    int aux;
    aux = *num1;
    *num1 = *num2;
    *num2 = aux;
}
void insertion_sort(int n, struct registro pessoas[n]) {
    int i, j;
    struct registro chave;
    for(i = 1; i < n; i++) {
        
        chave = pessoas[i];
        j = i - 1;
        
        
        while(j >= 0 && (strcmp(chave.nome,pessoas[j].nome)) < 0 ) {
            int indice = pessoas[j].indiceini;
            pessoas[j].indiceini = pessoas[j + 1].indiceini;
            pessoas[j + 1].indiceini = indice;
            
            pessoas[j + 1] = pessoas[j];
            j = j - 1;
        }
        pessoas[j + 1] = chave;
        
        
        
        if(strcmp(chave.nome,pessoas[j].nome) == 0) {
        
            j = i - 1;
            while(j >= 0 && chave.idade > pessoas[j].idade) {
                int indice = pessoas[j].indiceini;
                pessoas[j].indiceini = pessoas[j + 1].indiceini;
                pessoas[j + 1].indiceini = indice;
                
                pessoas[j + 1] = pessoas[j];
                j = j - 1;
            }
            pessoas[j + 1] = chave;
            
            
            if(pessoas[j + 1].idade == pessoas[i].idade) {
                j = i - 1;
                while(j >= 0 && chave.altura < pessoas[j].altura) {
                    int indice = pessoas[j].indiceini;
                    pessoas[j].indiceini = pessoas[j + 1].indiceini;
                    pessoas[j + 1].indiceini = indice;
                
                    pessoas[j + 1] = pessoas[j];
                    j = j - 1;
                }
                pessoas[j + 1] = chave;
            }
        }

    }


}




int main()
{
    int n;
    scanf("%d", &n);
    struct registro pessoas[n];
    for(int i = 0; i < n; i++) {
        scanf(" %s", pessoas[i].nome);
        scanf("%d", &pessoas[i].idade);
        scanf("%f", &pessoas[i].altura);
        pessoas[i].indiceini = i;

    }
    insertion_sort(n, pessoas);

    
    for(int i = 0; i < n; i++) {
    
        printf("%d;", pessoas[i].indiceini);
    }

    return 0;
}
