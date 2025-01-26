#include <stdio.h>

int main()
{
    int n, num, primo, contador1;
    int contador;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        contador = 0;
        scanf("%d", &num);
        for(int j = 1; j <= num; j++) {
            if(num % j == 0) {
                contador++;
            }
        }
        if(contador <= 2){
            printf("%d eh primo.\n", num);
        } else {
            printf("%d nao eh primo, o proximo primo eh ", num);
            primo = num + 1;
            while (1) {
                contador1 = 0;
                for(int k = 1; k <= primo; k++) {
                    if(primo % k == 0) {
                        contador1++;
                    }
                }
                if(contador1 == 2) {
                    break;
                }
                primo++;
            }
            printf("%d.\n", primo);
        }
    }    

    return 0;
}
