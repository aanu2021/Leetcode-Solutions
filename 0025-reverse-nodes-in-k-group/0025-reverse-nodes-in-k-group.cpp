class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;
        ListNode*dummy = new ListNode(-1);
        dummy->next = head;
        ListNode*ptr = dummy;
        int cnt = 0;
        while(ptr){
            ptr = ptr->next;
            cnt++;
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

/*

len = 6
     
      -------  
     |       |
0    1  2    3 -> 4 -> 5
p    c  n         
|    |  | 
|    ----
|       |
 --------   
    
0 -> 2 -> 1 -> 3 -> 4 -> 5    
p         c         n     
    
1 -> 4
3 -> 2
0 -> 3    
    
c->next = n->next
n->next = p->next
p->next = n
n = c->next

*/