#include <stdio.h> 
#include <stdlib.h> 
#define TRUE 1 
#define FALSE 0

int isPrime(int number){ 
    if(number < 2){ 
        return FALSE; 
    }

    for(int i = 2; i <= number/2; i++){
        if(number % i == 0){ 
            return FALSE; 
        }
    }
    return TRUE; 
}

int main(int argc, char *argv[]){ 
    if(argc < 2){ 
        printf("Missing test number!"); 
        return EXIT_FAILURE; 
    }

    int test_number = atoi(argv[1]); 
    int ans = isPrime(test_number); 
    if(ans){ 
        printf("%d is prime\n", test_number); 
    }else{ 
        printf("%d is not prime\n", test_number); 
    }
    return EXIT_SUCCESS;
}