#include<stdio.h> 
#include<stdlib.h> 
#include<stdbool.h>

typedef struct {
    int* data;
    int size; 
    int head; 
    int tail;
    
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    // !remember to allocate memory for queue
    MyCircularQueue* queue = malloc(sizeof(MyCircularQueue));
    queue->data = malloc(sizeof(int) * k); 
    queue->size = k;
    queue->head = -1; 
    queue->tail = -1;
    return queue;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    //queue is full
    if((obj->tail+1) % obj->size == obj->head){
       return false; 
    }else{
        obj->tail = (obj->tail+1) % obj->size;
        obj->data[obj->tail] = value; 
        if(obj->head == -1){
            obj->head = 0; 
        }
        return true; 
    }
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(obj->head == obj->tail){ 
        if(obj->head == -1){
            return false;
        }else{
            //one element left
            obj->head = -1; 
            obj->tail = -1;
            return true;
        }
    }else{
        obj->head = (obj->head+1) % obj->size; 
        return true;
    }
  
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(obj->head != -1){
        return obj->data[obj->head]; 
    }else{
        return -1; 
    }
  
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(obj->tail != -1){
        return obj->data[obj->tail];
    }else{
        return -1;
    }
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->head == -1 || obj->tail == -1;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->tail+1) % obj->size == obj->head;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    if(obj){
        if(obj->data){
            free(obj->data);
        }
        free(obj);
    }
} 


int main(){
    MyCircularQueue* obj = myCircularQueueCreate(3);
    bool param_1 = myCircularQueueEnQueue(obj, 5);
    bool param_2 = myCircularQueueEnQueue(obj, 4);
    bool param_3 = myCircularQueueDeQueue(obj);
    int param_4 = myCircularQueueFront(obj);
    int param_5 = myCircularQueueRear(obj);
    bool param_6 = myCircularQueueIsEmpty(obj);
    bool param_7 = myCircularQueueIsFull(obj);
    myCircularQueueFree(obj);
    return 0;
}