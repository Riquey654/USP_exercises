#include <stdio.h>
#include <time.h>

unsigned int mdc(unsigned int m, int n);

unsigned int mdc(unsigned int m, int n) {
    
    if(n == 0)
        return m;
    else {
        mdc(n, m % n);
    }
    
}

int main()
{
    unsigned int m, n;
    scanf("%u %u", &m, &n);
    
    clock_t inicio = clock();
    
    unsigned int maxdiv;
    maxdiv = mdc(m, n);
    printf("%u\n", maxdiv);
    
    time_t final = clock();
    double elapsed = (double)(final - inicio) / CLOCKS_PER_SEC;
    printf("%lfs\n", elapsed);

    return 0;
}

