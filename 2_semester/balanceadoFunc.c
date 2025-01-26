#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool balanceada(char *sequencia);

bool balanceada(char *sequencia) {
    // [91  ]93  {123   }125   (40   )41

    //farei um strlen sem o string h
    int contador = 0;
    while(sequencia[contador] != '\0') {
        contador++;
    }
    int parametro = contador;
    //usei essa variavel como parametro para decrementala dentro do loop
    for(int i = 0; i < contador; i++) {
        if(sequencia[i] == '[' || sequencia[i] == '{' || sequencia[i] == '(') {
            if(sequencia[i] == '['){
                if(sequencia[i] == sequencia[parametro - 1] - 2){
                    parametro--;
                }else{
                    return false;
                }
            }
            if(sequencia[i] == '{'){
                if(sequencia[i] == sequencia[parametro - 1] - 2){
                    parametro--;
                }else{
                    return false;
                }
            }
            if(sequencia[i] == '('){
                if(sequencia[i] == sequencia[parametro - 1] - 1){
                    parametro--;
                }else{
                    return false;
                }
            }
            
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
   char str_sequencia[1005];
   int qtd=0;
   
   /*qtd de sequencias a serem lidas e analisadas*/
   scanf("%d", &qtd);

   for(int i=0; i<qtd; i++){
      scanf("%s", str_sequencia);
      if(balanceada(str_sequencia))
      	printf("BALANCEADO\n");
      else
      	printf("NÃO BALANCEADO\n");
   }    
   return 0;
   
}