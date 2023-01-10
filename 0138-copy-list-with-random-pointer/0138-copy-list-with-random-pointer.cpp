class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>mapp;
        
        // Clone a single nodes without next and random pointer.
        Node*ptr = head;
        while(ptr){
            Node*curr = new Node(ptr->val);
            mapp[ptr] = curr;
            ptr = ptr->next;
        }
        
        // Start Cloning the single nodes with their corresponding next pointers.
        ptr = head;
        while(ptr){
            if(ptr->next){
                mapp[ptr]->next = mapp[ptr->next];
            }
            ptr = ptr->next;
        }
        
        // Ends up by cloning single nodes with their corresponding random pointers.
        ptr = head;
        while(ptr){
            if(ptr->random){
                mapp[ptr]->random = mapp[ptr->random];
            }
            ptr = ptr->next;
        }
        
        return mapp[head];
        
    }
};