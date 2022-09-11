class Node{
    
  public:
    
    int val;
    Node*next;
    
    Node(int val){
        
        this->val=val;
        this->next=NULL;
        
    }
    
};


class MinStack {
   
    private:
    
    Node*Stack;
    Node*minStack;
    
    public:
    
    MinStack() {
        
        Stack=NULL;
        minStack=NULL;
        
    }
    
    void push(int val) {
        
        if(!Stack){
            
            Stack=new Node(val);
            minStack=new Node(val);
            
            return;
            
        }
        
        else{
            
            Node*temp=new Node(val);
            
            temp->next=Stack;
            Stack=temp;
            
            Node*mintemp=new Node(val);
            
            mintemp->val=min(mintemp->val,minStack->val);
            
            mintemp->next=minStack;
            minStack=mintemp;
            
            return;
            
        }
        
    }
    
    void pop() {
        
        if(!Stack){
            
            return;
            
        }
        
        else{
            
            Stack=Stack->next;
            minStack=minStack->next;
            
            return;
            
        }
        
    }
    
    int top() {
        
        if(!Stack){
            
            return -1 ;
            
        }
        
        else{
            
            int currval=Stack->val;
            
            return currval;
            
        }
        
    }
    
    int getMin() {
        
        if(!Stack){
            
            return -1 ;
            
        }
        
        else{
            
            int currval=minStack->val;
            
            return currval;
            
        }
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */