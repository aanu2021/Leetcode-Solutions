/*

Applications : (1) Memory Management
               (2) Traffic System
               (3) CPU Scheduling

*/



class MyCircularQueue {
public:
    
    int *arr;
    int front;
    int rear;
    int size;
 
    MyCircularQueue(int k) {
        
        size=k;
        front=-1;
        rear=-1;
        arr=new int[size];
        
    }
    
    bool enQueue(int value) {
        
       if(isFull()){
           
           return false;
           
       }
        
       // Different Cases for Enqueue...... 
        
        if(front==-1){
            
            front=0;
            rear=0;
            arr[rear]=value;
            
        }
        
        else if(rear==size-1 && front!=0){
            
            rear=0;
            arr[rear]=value;
            
        }
        
        else{
            
            rear++;
            arr[rear]=value;
            
        }
        
        return true;
        
    }
    
    bool deQueue() {
        
        if(isEmpty()){
            
            return false;
            
        }
        
        // Different Cases for Dequeue......
        
        if(front==rear){
            
            front=-1;
            rear=-1;
            
        }
        
        else if(front==size-1){
            
            front=0;
            
        }
        
        else{
            
            front++;
            
        }
        
        return true;
        
    }
    
    int Front() {
        
        if(isEmpty()){
            
            return -1;
            
        }
        
        else{
            
            return arr[front];
            
        }
        
    }
    
    int Rear() {
        
        if(isEmpty()){
            
            return -1;
            
        }
        
        else{
            
            return arr[rear];
            
        }
        
    }
    
    bool isEmpty() {
        
        if(front==-1){
            
            return true;
            
        }
        
        else{
            
            return false;
            
        }
        
    }
    
    bool isFull() {
        
       if((front==0 && rear==size-1) || (rear==front-1)){
           
           return true;
           
       }
        
       else{
           
           return false;
           
       }
        
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */