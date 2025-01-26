#include <stdio.h>
#include <math.h>

int main()
{
    float x;
    float seno = 0;
    scanf("%f", &x);
    for(int i = 1; i <= 50; i++){
        int h = (2*i-1);
        float pot = 1;
        for(int j = 1;j <= h; j++){
            if(j % 2 != 0){
                pot = pot*x;
            }else{
                pot = -pot*x;
            }    
        }
        float fat = 1;
        for(int k = 1; k <= h;k++){
            fat = fat*k;
        }
        seno = seno + pot/fat;
    }
    printf("%.6f", seno);

    return 0;
}


