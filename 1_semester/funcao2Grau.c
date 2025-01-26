#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c;
    float raiz1, raiz2;
    scanf("%d %d %d", &a, &b, &c);
    
    if(pow(b,2) - 4 * a * c < 0) {
     printf("NAO EXISTE RAIZ REAL");
    }
    else {
     raiz1 = (-b + sqrt(pow(b, 2) - 4 * a * c))/(2 * a);
     raiz2 = (-b - sqrt(pow(b, 2) - 4 * a * c))/(2 * a);
     
     if (raiz1 > raiz2){
      printf("%.3f %.3f", raiz2, raiz1);
     }
     else if (raiz1 < raiz2){
      printf("%.3f %.3f", raiz1, raiz2);
     }
     else {
      printf("%.3f", raiz1);
     }
     }
      return 0;
}
