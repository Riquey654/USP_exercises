
#include <stdio.h>

struct atividade {
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
    int segundo;
    char nome[99];
};

int main()
{
    int n;
    scanf("%d", &n);
    struct atividade tarefa[n];
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d %d %d %d %[^\n]", &tarefa[i].dia, &tarefa[i].mes, &tarefa[i].ano, &tarefa[i].hora, &tarefa[i].minuto, &tarefa[i].segundo, tarefa[i].nome);
    }
    for(int i = 0; i < n; i++) {
        printf("%02d/%02d/%04d - %02d:%02d:%02d \n%s\n", tarefa[i].dia, tarefa[i].mes, tarefa[i].ano, tarefa[i].hora, tarefa[i].minuto, tarefa[i].segundo, tarefa[i].nome);
    }

    return 0;
}
