#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include <lista.h>


int main () {
    int prioridade;
    int hora, minuto, segundo
    char descricao[51];
    char opcao[3];
    char inicializacao[10];
    
    lista_t lista_prioridade = criar_lista();
    lista_t lista_horario = criar_lista();
    
    scanf("%s", inicializacao);
    while(1) {
        if(strcmp(inicializacao, "add") == 0) {

            //add prior tempo descrição
            scanf("%d", &prioridade);
            scanf("%d:%d:%d", hora, minuto, segundo);
            scanf("%s", descricao);

            funcaoadd(prioridade, hora, minuto, segundo, descricao);

        }
        if(strcmp(inicializacao, "exec") == 0) {

            //exec opção
            scanf("%s", opcao);

            if(strcmp(opcao, "-p") == 0) {
                funcaoexecP();

            }else{//opcao == -t
                funcaoexecT();
            }

        }
        if(strcmp(inicializacao, "next") == 0) {

            //next opção
            scanf("%s", opcao);

            if(strcmp(opcao, "-p") == 0) {
                funcaonextP();

            }else{//opcao == -t
                funcaonextT();
            }

        }
        if(strcmp(inicializacao, "change") == 0) {

            //change opção anterior:novo
            scanf("%s", opcao);

             if(strcmp(opcao, "-p") == 0) {
                funcaochangeP();

            }else{//opcao == -t
                funcaochangeT();
            }

        }
        if(strcmp(inicializacao, "print") == 0) {

            //print opção
            scanf("%s", opcao);

            if(strcmp(opcao, "-p") == 0) {
                funcaoprintP();

            }else{//opcao == -t
                funcaoprintT();
            }

        }
        if(strcmp(inicializacao, "quit") == 0) {
            
            //remover todos os itens da lista!!!!!!!!
            break;
        }





    }
    

    return 0;
}

//Uma lista pra prioridade e outra pra tempo

funcaoadd(lista_t lista_prioridade, lista_t lista_horario, prioridade, hora, minuto, segundo, descricao) {
    
    celula *x = item_criar(prioridade, hora, minuto, segundo, descricao);
    inserir_prioridade(lista_prioridade, x);
    inserir_horario(lista_horario, x);
    //na hora da insercao, insiro o mesmo elemento nas duas listas
    
}
funcaoexecP(lista_t lista_prioridade, lista_t lista_horario) {
    
    celula *p = retorna_inicio(lista_prioridade);
    remover(lista_prioridade, p);
    remover(lista_horario, p);
    
}
funcaoexecT(lista_t lista_prioridade, lista_t lista_horario) {
    
    celula *p = retorna_inicio(lista_horario);
    remover(lista_prioridade, p);
    remover(lista_horario, p);
    
}
funcaonextP(lista_t lista_prioridade) {
    
    celula *p = retorna_inicio(lista_prioridade);
    printf("%d %d:%d:%d %s", p->prior, p->hh, p->mm, p->ss, p->descricao);
    printf("\n");
    
}
funcaonextT(lista_t lista_horario) {
    
    celula *p = retorna_inicio(lista_horario);
    printf("%d %d:%d:%d %s", p->prior, p->hh, p->mm, p->ss, p->descricao);
    printf("\n");
    
}
funcaochangeP(lista_t lista_prioridade);
funcaochangeT(lista_t lista_horario);
funcaoprintP(lista_t lista_prioridade);
funcaoprintT(lista_t lista_horario);