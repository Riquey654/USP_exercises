#include <stdio.h>
#include <stdlib.h>

struct pessoa {
    int ID;
    char nome[12];
    int idade;
};

int main()
{
    FILE *fp;
    struct pessoa indiv;
    int escolha;
    //a flag foi criada para verificar se o registro já existe
    int sair = 0;
    int IDgenerico;
    char nomearq[50];
    do {
        scanf("%d", &escolha);
        switch(escolha) {
                
            case 1:
                //nome do arquivo, o ID, nome e idade da pessoa
                scanf("%s %d %s %d", nomearq, &indiv.ID, indiv.nome, &indiv.idade);
                fp = fopen(nomearq, "ab");
                fwrite(&indiv, sizeof(struct pessoa), 1, fp);
                
                fclose(fp);
                break;
                
                
            case 2:
                int flag = 0;
                scanf("%s %d", nomearq, &IDgenerico);
                fp = fopen(nomearq, "rb");
                if(fp == NULL) {
                    printf("Arquivo não encontrado.\n");
                    break;
                }else{
                
                while(1) {
                    fread(&indiv, sizeof(indiv), 1, fp);
                    if(feof(fp))
                        break;
                    if(IDgenerico == indiv.ID){
                        printf("ID: %d | NOME: %s | IDADE: %d\n",indiv.ID, indiv.nome, indiv.idade);
                        flag = 1;
                    }
                }
                if(flag == 0) {
                    printf("Registro não encontrado.\n");
                }
                fclose(fp);
                }
            
                break;
                
                
            case 3:
                scanf("%s", nomearq);
                fp = fopen(nomearq, "rb");
                if(fp == NULL) {
                    printf("Arquivo não encontrado.\n");
                    break;
                }else{
                    while(1) {
                        fread(&indiv, sizeof(indiv), 1, fp);
                        if(feof(fp))
                            break;
                        printf("ID: %d | NOME: %s | IDADE: %d\n",indiv.ID, indiv.nome, indiv.idade);
                    }
                    fclose(fp);
                }
                break;
                
        }
    }while(escolha != 0);
    

    return 0;
}
