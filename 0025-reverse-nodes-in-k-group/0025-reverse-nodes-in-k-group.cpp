class Solution {
public:
    
    ListNode * reverseList(ListNode*& head){
        if(!head || !head->next) return head;
        ListNode * prevptr = NULL;
        ListNode * current = head;
        ListNode * nextptr = NULL;
        while(current){
            nextptr = current->next;
            current->next = prevptr;
            prevptr = current;
            current = nextptr;
        }
        return prevptr;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int len = 0;
        ListNode * pointHead = head;
        ListNode * pointer = head;
        ListNode * follow = NULL;
        while(pointer && len < k){
            follow = pointer;
            pointer = pointer->next;
            len++;
        }
        if(len < k) return head;
        ListNode * nextHead = pointer;
        follow->next = NULL;
        pointHead = reverseList(pointHead);
        head->next = reverseKGroup(nextHead, k);
        return pointHead;
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