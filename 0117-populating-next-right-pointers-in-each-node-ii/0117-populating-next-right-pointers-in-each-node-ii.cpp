class Solution {
public:
    Node* connect(Node* root) {
        
        if(!root) return NULL;
        
        Node*head = root;
        
        while(head){
            
            Node * dummy = new Node(-1);
            Node * temp = dummy;
            
            while(head){
                
                if(head->left){
                    
                    temp->next = head->left;
                    temp = temp->next;
                    
                }
                
                if(head->right){
                    
                    temp->next = head->right;
                    temp = temp->next;
                    
                }
            
                head = head->next; 
                
            }
            
            head = dummy->next;
            
        }
        
        return root;
        
    }
};