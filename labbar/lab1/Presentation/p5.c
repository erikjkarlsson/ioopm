#include <stdio.h>
#include <stdlib.h>
#include <math.h>




int main(int argc, char *argv[])
{

    int number = atoi(argv[1]);

    for (int testA = 2; testA < number; testA++){
            
        for (int testB = 2; testB < number; testB++){
            
            if (testA * testB == number){ 
                // The integer n is prime if there exists two integers a and b 
                // such that a * b = n
                printf("%d is not a prime number!\n\n", number);
                return 0;
            }
        }   
    }
    
    printf("%d is a prime number!\n\n", number);
    
    return 0;
}