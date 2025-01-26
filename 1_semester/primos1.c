#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);
    for (int i = 2; i <= num; i++) {
        int contador = 0;
        while (num % i == 0) {
            num = num/i;
            contador++;
            if(num % i != 0) {
                printf("%d %d\n", i, contador);
            
            }    
        }
    }

    return 0;
}

