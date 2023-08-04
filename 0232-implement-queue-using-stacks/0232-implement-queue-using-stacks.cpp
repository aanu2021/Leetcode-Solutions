class MyQueue {
public:
    
    stack<int>S1,S2;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        S1.push(x);
    }
    
    int pop() {
        if(S2.empty()){
            while(!S1.empty()){
                S2.push(S1.top()); S1.pop();
            }
        }
        int ele = S2.top(); S2.pop();
        return ele;
    }
    
    int peek() {
        if(S2.empty()){
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

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */