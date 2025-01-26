#include <string.h>
#include <stdio.h>

int main()
{
    char str1[99];
    char str2[99];
    char strfinal[200];
    int h = 0;
    
    scanf("%s", str1);
    scanf("%s", str2);
    
    for(int i = 0; i < strlen(str1); i++) {
        strfinal[i] = str1[i];
    }
    for(int j = strlen(str1); j < strlen(str1) + strlen(str2); j++) {
        strfinal[j] = str2[h];
        h++;
    }
    
    printf("%ld\n", strlen(strfinal));
    for(int i = 0; i < strlen(strfinal); i++) {
        printf("%c", strfinal[i]);
    }

    return 0;
}
