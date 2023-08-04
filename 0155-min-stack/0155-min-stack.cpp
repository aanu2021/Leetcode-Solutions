class MinStack {
public:
    
    typedef long long ll;
    stack<ll>S;
    ll mini;
    
    MinStack() {
        mini = 1e15;
    }
    
    void push(int value) {
        ll val = (ll)value;
        if(S.empty()){
            S.push(val);
            mini = val;
            return;
        }
        if(val < mini){
            S.push(2*val-mini);
            mini = val;
            return;
        }
        else{
            S.push(val);
        }
    }
    
    void pop() {
        ll tp = S.top(); S.pop();
        if(tp < mini){
            mini = 2*mini - tp;
            return;
        }
    }
    
    int top() {
        ll tp = S.top();
        if(tp < mini){
            return mini;
        }
        else{
            return tp;
        }
    }
    
    int getMin() {
        return mini;
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