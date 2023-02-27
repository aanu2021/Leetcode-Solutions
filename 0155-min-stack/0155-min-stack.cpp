class MinStack {
public:
    
    typedef long long ll;
    stack<ll>S;
    ll mini;
    
    MinStack() {
        mini = 1e15;
    }
    
    void push(int val) {
        if(S.empty()){
            mini = val;
            S.push(val);
            return;
        }
        else{
            if(val >= mini){
                S.push(val);
            }
            else{
                S.push((2LL*val) - mini);
                mini = val;
            }
            return;
        }
    }
    
    void pop() {
        if(S.empty()){
            return;
        }
        else{
            ll tp = S.top();
            S.pop();
            if(tp >= mini){
                return;
            }
            else{
                mini = (2*mini - tp);
                return;
            }
        }
    }
    
    int top() {
        if(S.empty()){
            return -1;
        }
        else{
            ll tp = S.top();
            if(tp >= mini){
                return tp;
            }
            else{
                return mini;
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

