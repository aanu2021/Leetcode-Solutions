class Solution {
public:
    Node* copyRandomList(Node* head) {
       
        if(!head) return NULL;
        
        Node*iter = head;
        
        // Create the duplicate nodes side by side with the given nodes
        
        while(iter){
            Node*nextNode = iter->next;
            iter->next = new Node(iter->val);
            iter->next->next = nextNode;
            iter = iter->next->next;
        }
        
        iter = head;
        
        // Create the random links for the duplicate nodes
        
        while(iter){
            if(iter->random){
                iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
        }
        
        iter = head;
        
        // Finally we need to link up the duplicate nodes with proper next pointers.
        
        Node*dummy = new Node(-1);
        Node*temp = dummy;
        
        while(iter){
            temp->next = iter->next;
            temp = temp->next;
            iter->next = iter->next->next;
            iter = iter->next;
        }
        
        return dummy->next;
        
    }
};