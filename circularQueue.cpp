#include<iostream> 
#include<vector> 

using namespace std; 


class MyCircularQueue {
private:
    vector<int> data; 
    int size; 
    int head; 
    int tail; 
public:
    MyCircularQueue(int k) {
        //use resize to set the capacity 
        data.resize(k);
        size = k;
        head = -1; 
        tail = -1; 
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false; 
        } 
        
        if(isEmpty()){
            head = 0;
        }
      
        tail = (tail+1) % size; 
        data[tail] = value; 
        return true; 
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false; 
        }

        if(tail == head){
            tail = -1; 
            head = -1; 
        }else{
            head = (head + 1) % size;
        }
        return true;
    }
    
    int Front() {     
        return isEmpty()? -1 : data[head];
    }
    
    int Rear() {
        return isEmpty()? -1 : data[tail];
    }
    
    bool isEmpty() {
        return tail == -1; 
    }
    
    bool isFull() {
        return (tail+1) % size == head; 
        
    }

    ~MyCircularQueue(){}
};


int main(){
    MyCircularQueue* obj = new MyCircularQueue(5);
    bool param_1 = obj->enQueue(3);
    bool param_2 = obj->deQueue();
    int param_3 = obj->Front();
    int param_4 = obj->Rear();
    bool param_5 = obj->isEmpty();
    bool param_6 = obj->isFull();
    return 0; 
}
