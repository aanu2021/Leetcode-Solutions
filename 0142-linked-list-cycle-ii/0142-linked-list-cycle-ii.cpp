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
        ListNode*slow = head;
        ListNode*fast = head;
        bool cyclePresent = false;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                cyclePresent = true;
                break;
            }
        }
        if(!cyclePresent) return NULL;
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};


// L1 = L + m*C + x
// L2 = L + n*C + x

// L2 = 2*L1
// L + n*C + x = 2L + 2*m*C + 2*x
// (n-2*m)*C = L + x
// L + x = K*C
// L + x = (K-1)*C + C
// L = (K-1)*C + C - x


// L1   C   x
// L2