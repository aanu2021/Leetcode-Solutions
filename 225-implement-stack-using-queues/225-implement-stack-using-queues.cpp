class Node{
  
    public:
    
    int val;
    Node*next;
    
    Node(int val){
        
        this->val=val;
        this->next=NULL;
        
    }
    
};

class Queue{
  
    public:
    
    Node*head;
    Node*tail;
    int siz;
    
    Queue(){
        
        head=NULL;
        tail=NULL;
        siz=0;
        
    }
    
    void push(int data){
        
        if(!head){
            
            head=new Node(data);
            tail=head;
            siz++;
            return;
            
        }
        
        else{
            
            tail->next=new Node(data);
            tail=tail->next;
            siz++;
            return;
            
        }
        
    }
    
    void pop(){
        
        if(!head){
            
            return;
            
        }
        
        else{
            
            head=head->next;
            
            if(!head){
                
                tail=NULL;
                
            }
            
            siz--;
            
            return;
            
        }
        
    }
    
    int front(){
        
        if(!head){
            return -1;
        }else{
            return head->val;
        }
        
    }
    
    int size(){
        
        return siz;
        
    }
    
    bool empty(){
        
        return !head;
        
    }
    
};

class MyStack {
public:
    
    Queue q;
    
    MyStack() {
        
    }
    
    void push(int x) {
        
        q.push(x);
        
        int sz=q.size();
        
        while(sz>1){
            
            q.push(q.front());
            q.pop();
            sz--;
            
        }
        
    }
    
    int pop() {
        
        int value=q.front();
        q.pop();
        
        return value;
        
    }
    
    int top() {
        
        int value=q.front();
        
        return value;
        
    }
    
    bool empty() {
        
        return q.empty();
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */