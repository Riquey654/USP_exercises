#include <stdio.h>
#include <stdbool.h>

bool balanceada(char *sequencia);
bool parbalanceado(char abre, char fecha);

bool parbalanceado(char abre, char fecha) {
    return ((abre == '(' && fecha == ')') || (abre == '{' && fecha == '}') || (abre == '[' && fecha == ']'));
}

bool balanceada(char *sequencia) {
    int topo = -1;
    char pilha[1005];

    for (int i = 0; sequencia[i] != '\0'; i++) {
        if (sequencia[i] == '(' || sequencia[i] == '{' || sequencia[i] == '[') {
            pilha[++topo] = sequencia[i];
        } else if (sequencia[i] == ')' || sequencia[i] == '}' || sequencia[i] == ']') {
            if (topo == -1 || !parbalanceado(pilha[topo], sequencia[i])) {
                return false;
            }
            topo--;
        }
    }

    return topo == -1;
}
