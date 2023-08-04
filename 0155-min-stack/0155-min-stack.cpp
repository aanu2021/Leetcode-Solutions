class Node{
   public:
    int val;
    Node*next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

class MinStack {
public:
    
    Node*head;
    Node*minHead;
    
    MinStack() {
        head = NULL;
        minHead = NULL;
    }
    
    void push(int val) {
        if(!head){
            head = new Node(val);
            minHead = new Node(val);
            return;
        }
        Node*newHead = new Node(val);
        Node*newMinHead = new Node(val);
        newMinHead->val = min(newMinHead->val, minHead->val);
        newHead->next = head;
        newMinHead->next = minHead;
        head = newHead;
        minHead = newMinHead;
    }
    
    void pop() {
        head = head->next;
        minHead = minHead->next;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return minHead->val;
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