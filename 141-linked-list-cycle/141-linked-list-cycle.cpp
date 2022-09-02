/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        if(!head){
            return false;
        }
        
        ListNode*ptr=head;
        
        unordered_set<ListNode*>S;
        
        while(ptr!=NULL){
            
            if(S.find(ptr)!=S.end()){
                return true;
            }
            
            S.insert(ptr);
            
            ptr=ptr->next;
            
        }
        
        return false;
        
    }
};