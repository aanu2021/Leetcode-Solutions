class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int cnt = 0;
        ListNode * dummy = new ListNode(-1);
        dummy->next = head;
        ListNode * ptr = dummy;
        while(ptr){
            ptr = ptr->next;
            cnt++;
        }
        
        ListNode * prevptr = dummy;
        ListNode * current = dummy;
        ListNode * nextptr = dummy;
        
        while(cnt > 1){
            int loop = (cnt > k ? k : 1);
            current = prevptr->next;
            nextptr = current->next;
            for(int i=1;i<loop;i++){
                current->next = nextptr->next;
                nextptr->next = prevptr->next;
                prevptr->next = nextptr;
                nextptr = current->next;
            }
            cnt -= k;
            prevptr = current;
        }
        return dummy->next;
    }
};

// 1 2 3 4 5 6
    
// k = 3
    
// 0 1 2 3 4 5 6
    
// cnt = 7   
    
    