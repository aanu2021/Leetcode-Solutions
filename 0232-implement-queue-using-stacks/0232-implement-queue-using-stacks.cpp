class MyQueue {
public:
    
    stack<int>S;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        S.push(x);
    }
    
    int pop() {
        if(S.empty()){
            return -1;
        }
        int x = S.top(); S.pop();
        if(S.empty()){
            return x;
        }
        int item = pop();
        S.push(x);
        return item;
    }
    
    int peek() {
        if(S.empty()){
            return -1;
        }
        int x = S.top(); S.pop();
        if(S.empty()){
            S.push(x);
            return x;
        }
        int item = peek();
        S.push(x);
        return item;
    }
    
    bool empty() {
        return S.empty();
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