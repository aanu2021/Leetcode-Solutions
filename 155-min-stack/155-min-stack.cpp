class MinStack {
public:
    
    typedef long long ll;
    
    stack<ll>S;
    
    ll mini;
    
    MinStack() {
        
        mini=LONG_MAX;
        
    }
    
    void push(int val) {
        
        if(S.empty()){
            
            mini=val;
            
            S.push(val);
            
        }
        
        else{
            
            if(val<mini){
                
                S.push((ll)2*val-mini);
                
                mini=val;
                
            }
            
            else{
                
                S.push(val);
                
            }
            
        }
        
    }
    
    void pop() {
        
        if(S.empty()){
            
            return;
            
        }
        
        else{
            
            if(S.top()<mini){
                
                mini=2*mini-S.top();
                S.pop();
                
            }
            
            else{
                
                S.pop();
                
            }
            
        }
        
    }
    
    int top() {
        
        if(S.empty()){
            
            return -1;
            
        }
        
        else{
            
            if(S.top()<mini){
                
                return mini;
                
            }
            
            else{
                
                return S.top();
                
            }
            
        }
        
    }
    
    int getMin() {
        
        if(S.empty()){
            
            return -1;
            
        }
        
        else{
            
            return mini;
            
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