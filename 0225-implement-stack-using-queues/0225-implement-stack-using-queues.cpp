class MyStack {
public:
    
    queue<int>q;
    
    MyStack() {
        
    }
    
    void push(int x) {
        int sz = q.size();
        q.push(x);
        while(sz--){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        if(q.size() == 0){
            return -1;
        }
        else{
            int ele = q.front(); q.pop();
            return ele;
        }
    }
    
    int top() {
        if(q.size() == 0){
            return -1;
        }
        else{
            int ele = q.front();
            return ele;
        }
    }
    
    bool empty() {
        return q.empty();
    }
};

