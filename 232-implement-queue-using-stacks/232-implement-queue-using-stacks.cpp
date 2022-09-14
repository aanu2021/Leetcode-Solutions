class MyQueue {
public:
    
    stack<int>s1,s2;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        
       s1.push(x);
        
    }
    
    int pop() {
        
        int sz=s1.size();
        
        while(sz>1){
            
            s2.push(s1.top());
            s1.pop();
            sz--;
            
        }
        
        int value=s1.top();
        s1.pop();
        
        while(!s2.empty()){
            
            s1.push(s2.top());
            s2.pop();
            
        }
        
        return value;
        
    }
    
    int peek() {
        
        int sz=s1.size();
        
        while(sz>1){
            
            s2.push(s1.top());
            s1.pop();
            sz--;
            
        }
        
        int value=s1.top();
        s1.pop();
        
        s2.push(value);
        
        while(!s2.empty()){
            
            s1.push(s2.top());
            s2.pop();
            
        }
        
        return value;
        
    }
    
    bool empty() {
        
        return s1.empty();
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */