class Solution {
public:
    Node* copyRandomList(Node* head) {
    
        if(!head){
            return NULL;
        }
        
        
        // Create the copy nodes beside the original ones //
        
        Node*iter=head;
        
        while(iter){
            
            Node*copy=new Node(iter->val);
            
            Node*nextnode=iter->next;
            
            iter->next=copy;
            
            copy->next=nextnode;
            
            iter=iter->next->next;
            
        }
        
        
        // Connecting the random pointers for the copy nodes //
        
        iter=head;
        
        while(iter){
            
            if(iter->random){
                
                iter->next->random=iter->random->next;
                
            }
            
            iter=iter->next->next;
            
        }
        
        
        // Segregate the original nodes from the copy nodes //
        
        iter=head;
        
        Node*dummy_copy=new Node(-1);
        
        Node*copy_head=dummy_copy;
        
        while(iter){
            
            copy_head->next=iter->next;
            
            copy_head=copy_head->next;
            
            iter->next=iter->next->next;
            
            iter=iter->next;
            
        }
        
        return dummy_copy->next;
        
    }
};