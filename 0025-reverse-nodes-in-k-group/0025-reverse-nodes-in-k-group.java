class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        if(head == null) return head;
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode ptr = dummy;
        int cnt = 0;
        while(ptr != null){
            cnt++;
            ptr = ptr.next;
        }
        ListNode prevptr = dummy;
        ListNode current = dummy;
        ListNode nextptr = dummy;
        while(nextptr != null){
            current = prevptr.next;
            nextptr = current.next;
            int toLoop = (cnt > k ? k : 1);
            for(int i=1;i<toLoop;i++){
                current.next = nextptr.next;
                nextptr.next = prevptr.next;
                prevptr.next = nextptr;
                nextptr = current.next;
            }
            prevptr = current;
            cnt -= k;
        }
        return dummy.next;
    }
}

// 0 -> 3 -> 2 -> 1 -> 4 -> 5 -> 6
// p              c    n    
    
//  c->next = n->next;   
//  n->next = p->next;
//  p->next = n;
//  n = c->next;