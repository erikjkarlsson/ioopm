#include <stdio.h>

int main(){
    short i,j = 1;
    short t = 0;
    for (i; i <= 10; i++){
        j = 1;
        t += i;
        for (j; j <= i; j++){
            printf("*");
        }
        
        printf("\n");
    }
    printf("Totalt: %d\n", t);

    return 0;
}
