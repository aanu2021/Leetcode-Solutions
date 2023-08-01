class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int cnt = 0;
        ListNode*dummy = new ListNode(-1);
        dummy->next = head;
        ListNode*ptr = dummy;
        while(ptr){
            cnt++;
            ptr = ptr->next;
        }
        ListNode*prevptr = dummy;
        ListNode*current = dummy;
        ListNode*nextptr = dummy;
        while(nextptr){
            current = prevptr->next;
            nextptr = current->next;
            int toLoop = (cnt > k ? k : 1);
            for(int i=1;i<toLoop;i++){
                current->next = nextptr->next;
                nextptr->next = prevptr->next;
                prevptr->next = nextptr;
                nextptr = current->next;
            }
            prevptr = current;
            cnt -= k;
        }
        return dummy->next;
    }
};