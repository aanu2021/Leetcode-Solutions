class Solution {
public:
    Node* copyRandomList(Node* head) {
       
        if(!head) return NULL;
        
        Node*iter = head;
        
        while(iter){
            Node*nextNode = iter->next;
            Node*copyNode = new Node(iter->val);
            iter->next = copyNode;
            copyNode->next = nextNode;
            iter = iter->next->next;
        }
        
        iter = head;
        
        while(iter){
            if(iter->random){
                iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
        }
        
        iter = head;
        
        Node*dummy = new Node(-1);
        Node*copy = dummy;
        
        while(iter){
            copy->next = iter->next;
            copy = copy->next;
            iter->next = iter->next->next;
            iter = iter->next;
        }
        
        return dummy->next;
        
    }
};