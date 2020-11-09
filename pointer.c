#include <stdio.h>
#include <stdlib.h> 

void swap(int* x, int* y){ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
}

int sumArray(int * array, int n){ 
    int answer = 0; 
    int * ptr = array; 
    for(int i = 0; i < n; i++){ 
        answer += *ptr; 
        ptr++; 
    }
    return answer; 
} 

int maxElement(int * array, int n){
    int max_index = 0; 
    for(int i = 0; i < n; i++){ 
        if(*(array + i) > *(array + max_index)){ 
            max_index = i; 
        }
    }
    return max_index; 
}

//broken code
//myArray in Stack frame - destroyed after the function is done
int * initArray(int size){ 
    int myArray[size]; 
    for(int i = 0; i < size; i++){
        myArray[i] = i; 
    } 
    return myArray; 
} 

//WORK!! 
//array is now in HEAP, won't be deleted until free is called 
int *initArrayHeap(int size){ 
    int * array = malloc(size * sizeof(*array)); 
    if(array != NULL){
        for(int i = 0; i < size; i++){ 
            array[i] = i; 
        }
    }
    return array;
}

int stringEqual(const char * str1, const char *str2){ 
    const char * p1 = str1; 
    const char * p2 = str2; 
    while(*p1 == *p2){ 
        if(*p1 == '\0'){ 
            return 1; 
        }
        p1++; 
        p2++; 
    }
    return 0; 
}

/*function name is a pointer to function*/

void incAll(int * data, int n){ 
    for(int i = 0; i < n; i++){ 
        data[i] = data[i]+1; 
    }
}

void squareAll(int * data, int n){ 
    for(int i = 0; i < n; i++){ 
        data[i] = data[i] * data[i]; 
    }
}

void doubleAll(int * data, int n){ 
    for(int i = 0; i < n; i++){ 
        data[i] = data[i] * 2; 
    }
} 

int inc(int x){
    return x+1; 
}

int square(int x){ 
    return x*x; 
}

int doubleX(int x){ 
    return x*2;
}

void doToAll(int * data, int n, int (*f)(int)){ 
    for(int i = 0; i < n; i++){ 
        data[i] = f(data[i]); 
    }
}

int main(){  
    /*pointer basic*/ 
    int a = 5, b = 10; 
    int* ptr = &a;
    *ptr = 15; 
    printf("a = %d, b = %d\n", a, b); 
    swap(&a, &b); 
    printf("a = %d, b = %d\n", a, b); 

    /*array*/ 
    int data[4] = {4, 6, 8, 2}; 
    int sum = sumArray(data, 4); 
    printf("sum = %d\n", sum);  
    printf("The index of the largest element in data is %d\n", maxElement(data, 4));
    
    /*dangling pointer - segmentation fault*/
    /*int *p = initArray(2); 
    for(int i = 0; i < 2; i++){ 
        printf("%d\n", p[i]); 
    }*/
    
    /*string*/ 
    char * str1 = "Hello"; 
    char * str2 = "Hello\0"; 
    printf("Are str1 and str2 the same? %d\n", stringEqual(str1, str2)); 

    const char * word[] = {"A", "cat", "likes", "sleeping", NULL}; 
    const char ** sptr = word; 
    while(*sptr != NULL){
        printf("%s\n", *sptr); 
        sptr++; 
    }    

    /*function pointer*/
    doToAll(data, 4, inc); 
    doToAll(data, 4, square); 
    doToAll(data, 4, doubleX); 




    return EXIT_SUCCESS; 
}