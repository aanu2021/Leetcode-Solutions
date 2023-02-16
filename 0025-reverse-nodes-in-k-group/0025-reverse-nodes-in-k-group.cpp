class Solution {
public:
    
    ListNode * reverseList(ListNode *&head){
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
        int cnt = 0;
        ListNode * ptr = head;
        ListNode * temp = NULL;
        while(ptr && cnt < k){
            temp = ptr;
            ptr = ptr->next;
            cnt++;
        }
        if(cnt < k){
            return head;
        }
        else{
           // Reverse the first k nodes
           // Recursively do the same for remaining nodes
            ListNode * nextNodes = temp->next;
            temp->next = NULL;
            head = reverseList(head);
            ListNode * currPtr = head;
            while(currPtr && currPtr->next){
                currPtr = currPtr->next;
            }
            currPtr->next = reverseKGroup(nextNodes,k);
            return head;
        }
    }
};

// 1 -> 2 -> 3
    
// nextptr = current->next;
// current->next = prevptr;
// prevptr = current;
// current = nextptr;