class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(!head){
            return NULL;
        }
        
        
        // Original Node -> Copy Node -> Original Node ->... //
        
        Node*iter=head;
        
        while(iter){
            
            Node*next_node=iter->next;
            
            Node*copy_node=new Node(iter->val);
            
            iter->next=copy_node;
            
            copy_node->next=next_node;
            
            iter=iter->next->next;
            
        }
        
        
        // Update the Random Pointers for the copied nodes //
        
        iter=head;
        
        while(iter){
            
            if(iter->random){
                
                iter->next->random=iter->random->next;
                
            }
            
            iter=iter->next->next;
            
        }
        
        
        // Segregate the original nodes from the copied ones //
        
        iter=head;
        
        Node*dummy_copy_head=new Node(-1);
        
        Node*copy_head=dummy_copy_head;
        
        
        while(iter){
            
            copy_head->next=iter->next;
            
            iter->next=iter->next->next;
            
            iter=iter->next;
            
            copy_head=copy_head->next;
            
        }
        
        return dummy_copy_head->next;
        
    }
};