class Solution {
public:

    /*

    L2 = 2*L1
    (L + n*c + x) = 2*(L + m*c + x)
    (n-2*m)*c = L+x
    (L+x) is a multiple of length of the cycle present in LL 

    */

    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        
        // check whether a cycle present in the LL
        
        bool isCycle = false;
        
        ListNode * slow = head;
        ListNode * fast = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                isCycle = true;
                break;
            }
        }
        
        if(!isCycle) return NULL;
        
        fast = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};