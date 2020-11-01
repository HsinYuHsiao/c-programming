#include <stdio.h> 

int main(){ 
    int a=5, b=10; 
    int* ptr = &b; 
    *ptr = 15; 
    printf("%d\n", a+b);

    return 0; 
}