class MinStack {
public:
    
    stack<pair<int,int>>S;
    
    MinStack() {
        
    }
    
    void push(int val) {
        if(S.empty()){
            S.push({val,val});
            return;
        }
        else{
            int tp = S.top().second;
            S.push({val,min(val,tp)});
            return;
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
        if(S.empty()) return -1;
        else return S.top().first;
    }
    
    int getMin() {
        if(S.empty()) return -1;
        else return S.top().second;
    }
};

