//MDC entre dois números

#include <stdio.h>
#include <time.h>

int main()
{
    unsigned int m, n;
    int maxdiv;
    scanf("%u %u", &m, &n);
    clock_t inicio = clock();
    if(m > n) {
        for(int i = 1; i <= n; i++) {
            if(m % i == 0 && n % i == 0) {
                maxdiv = i;
            }
        }
    }else{//m < n
        for(int i = 1; i <= m; i++) {
            if(m % i == 0 && n % i == 0) {
                maxdiv = i;
            }
        }
    }
    printf("%d\n", maxdiv);
    time_t final = clock();
    double elapsed = (double)(final - inicio) / CLOCKS_PER_SEC;
    printf("%lfs\n", elapsed);

    return 0;
}


