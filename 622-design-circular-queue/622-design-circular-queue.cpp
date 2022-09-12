/*

Applications : (1) Memory Management
               (2) Traffic System
               (3) CPU Scheduling

*/

class Node{
  
    public:
    
    int val;
    Node*next;
    
    Node(int val){
        
        this->val=val;
        this->next=NULL;
        
    }
    
};

class MyCircularQueue {
public:
    
    int maxCapacity;
    
    int currSize;
    
    Node*front;
    
    Node*rear;
    
 
    MyCircularQueue(int k) {
        
        maxCapacity=k;
        
        currSize=0;
        
        front=NULL;
        
        rear=NULL;
        
    }
    
    bool enQueue(int value) {
        
        Node*temp=new Node(value);
        
        if(front==NULL || rear==NULL){
            
            front=temp;
            rear=temp;
            currSize++;
            
            return true;
            
        }
        
        else{
            
            if(currSize<maxCapacity){
                
                rear->next=temp;
                
                rear=temp;
                
                currSize++;
                
                return true;
                
            }
            
            else{
                
                return false;
                
            }
            
        }
        
    }
    
    bool deQueue() {
        
        if(front==NULL){
            
            return false;
            
        }
        
        else{
            
            Node*temp=front;
            
            front=front->next;
            
            if(front==NULL){
                
                rear=NULL;
                
            }
            
            delete temp;
            
            currSize--;
            
            return true;
            
        }
        
    }
    
    int Front() {
        
        if(front==NULL){
            return -1;
        }else{
            return front->val;
        }
        
    }
    
    int Rear() {
        
        if(rear==NULL){
            return -1;
        }else{
            return rear->val;
        }
        
    }
    
    bool isEmpty() {
        
        return currSize==0;
        
    }
    
    bool isFull() {
        
        return currSize==maxCapacity;
        
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