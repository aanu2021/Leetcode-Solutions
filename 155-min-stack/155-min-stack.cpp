class MinStack {
public:
    
    stack<pair<int,int>>S;
    
    MinStack() {
        
    }
    
    void push(int val) {
        
        if(S.empty()){
            
            S.push({val,val});
            
        }
        
        else{
            
            S.push({val,min(val,S.top().second)});
            
        }
        
    }
    
    void pop() {
        
        if(S.empty()){
            
            return;
            
        }
        
        else{
            
            S.pop();
            
        }
        
    }
    
    int top() {
        
        if(S.empty()){
            
            return -1;
            
        }
        
        else{
            
            return S.top().first;
            
        }
        
    }
    
    int getMin() {
        
        if(S.empty()){
            
            return -1;
            
        }
        
        else{
            
            return S.top().second;
            
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