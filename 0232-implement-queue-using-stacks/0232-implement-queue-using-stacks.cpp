class MyQueue {
public:
    
    stack<int>S1,S2;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        S1.push(x);
    }
    
    int pop() {
        if(!S2.empty()){
        }
        else{
            while(!S1.empty()){
                S2.push(S1.top()); S1.pop();
            }
        }
        int ele = S2.top();
        S2.pop();
        return ele;
    }
    
    int peek() {
        if(!S2.empty()){
        }
        else{
            while(!S1.empty()){
                S2.push(S1.top()); S1.pop();
            }
        }
        int ele = S2.top();
        return ele;
    }
    
    bool empty() {
        return S1.empty() && S2.empty();
    }
};

