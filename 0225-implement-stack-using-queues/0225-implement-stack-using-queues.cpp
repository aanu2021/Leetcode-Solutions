class MyStack {
public:
    
    queue<int>q;
    
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int sz = q.size();
        for(int i=0;i<sz-1;i++){
            q.push(q.front()); q.pop();
        }
    }
    
    int pop() {
        int ele = q.front(); q.pop();
        return ele;
    }
    
    int top() {
        int ele = q.front();
        return ele;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */