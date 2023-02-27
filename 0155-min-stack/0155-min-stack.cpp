class Node{
  
    public:
    
    int val;
    Node*next;
    
    Node(){
        this->next = NULL;
    }
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
    
};

class Stack{
  
    public:
    
    Node*node;
    int len;
    
    Stack(){
        node = NULL;
        len = 0;
    }
    
    void push_stack(int item){
        if(!node){
            node = new Node(item);
            len++;
            return;
        }
        else{
            Node*newNode = new Node(item);
            newNode->next = node;
            node = newNode;
            len++;
            return;
        }
    }
    
    void pop_stack(){
        if(!node){
            return;
        }
        else{
            node = node->next;
            len--;
            return;
        }
    }
    
    int top_stack(){
        if(!node) return -1;
        else return node->val;
    }
    
    int size(){
        return len;
    }
    
    void clear(){
        node = NULL;
    }
    
};

class MinStack {
public:
    
    Stack obj1;
    Stack obj2;
    
    MinStack() {
        
    }
    
    void push(int val) {
        if(obj1.size() == 0){
            obj1.push_stack(val);
            obj2.push_stack(val);
        }
        else{
            int item = obj2.top_stack();
            obj1.push_stack(val);
            obj2.push_stack(min(val,item));
        }
    }
    
    void pop() {
        obj1.pop_stack();
        obj2.pop_stack();
    }
    
    int top() {
        if(obj1.size() == 0) return -1;
        else return obj1.top_stack();
    }
    
    int getMin() {
        if(obj2.size() == 0) return -1;
        else return obj2.top_stack();
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