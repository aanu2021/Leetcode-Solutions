class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(!head){
            return NULL;
        }
        
        map<Node*,Node*>mp;
        
        Node*ptr=head;
        
        
        while(ptr){
            
            mp[ptr]=new Node(ptr->val);
            
            ptr=ptr->next;
            
        }
        
        
        ptr=head;
        
        while(ptr){
            
            mp[ptr]->next=mp[ptr->next];
            mp[ptr]->random=mp[ptr->random];
            ptr=ptr->next;
            
        }
        
        return mp[head];
        
    }
};