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

class MinStack {
public:
    
    Node* Stack;
    Node* minStack;
    
    MinStack() {
        Stack = NULL;
        minStack = NULL;
    }
    
    void push(int val) {
        if(!Stack){
            Stack = new Node(val);
            minStack = new Node(val);
            return;
        }
        else{
            Node* temp = new Node(val);
            temp->next = Stack;
            Stack = temp;
            Node * mintemp = new Node(min(val,minStack->val));
            mintemp->next = minStack;
            minStack = mintemp;
        }
    }
    
    void pop() {
        if(!Stack){
            return;
        }
        else{
            Stack = Stack->next;
            minStack = minStack->next;
        }
    }
    
    int top() {
        if(!Stack) return -1;
        else return Stack->val;
    }
    
    int getMin() {
        if(!Stack) return -1;
        else return minStack->val;
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