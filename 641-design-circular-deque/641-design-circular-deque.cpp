class Node{
    
  public:
    
    int val;
    Node*next;
    Node*prev;
    
    Node(int val){
        
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
        
    }
    
};

class MyCircularDeque {
public:
    
    Node*front;
    Node*rear;
    int currSize;
    int maxCapacity;
    
    MyCircularDeque(int k) {
        
        currSize=0;
        maxCapacity=k;
        front=NULL;
        rear=NULL;
        
    }
    
    bool insertFront(int value) {
        
        if(isFull()){
            return false;
        }
        
        Node*temp=new Node(value);
        
        if(front==NULL){
            
            front=temp;
            rear=temp;
            
        }
        
        else{
            
            temp->next=front;
            front->prev=temp;
            front=temp;
            
        }
        
        currSize++;
        
        return true;
        
    }
    
    bool insertLast(int value) {
        
        if(isFull()){
            return false;
        }
        
        Node*temp=new Node(value);
        
        if(front==NULL){
            
            front=temp;
            rear=temp;
            
        }
        
        else{
            
            rear->next=temp;
            temp->prev=rear;
            rear=temp;
            
        }
        
        currSize++;
        
        return true;
        
    }
    
    bool deleteFront() {
        
        if(isEmpty()){
            return false;
        }
        
        front=front->next;
        
        if(front==NULL){
            rear=NULL;
        }else{
            front->prev=NULL;
        }
        
        currSize--;
        
        return true;
        
    }
    
    bool deleteLast() {
        
        if(isEmpty()){
            return false;
        }
        
        rear=rear->prev;
        
        if(rear==NULL){
            front=NULL;
        }else{
            rear->next=NULL;
        }
        
        currSize--;
        
        return true;
        
    }
    
    int getFront() {
        
        if(isEmpty()){
            return -1;
        }else{
            return front->val;
        }
        
    }
    
    int getRear() {
        
        if(isEmpty()){
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
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */