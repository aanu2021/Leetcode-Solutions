class Solution {
public:
    
    ListNode * reverseList(ListNode * head){
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
    
    void printList(ListNode * head){
        ListNode * ptr = head;
        while(ptr){
            cout<<ptr->val<<"->";
            ptr = ptr->next;
        }
        cout<<"\n";
    }
    
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;
        ListNode * slow = head;
        ListNode * fast = head;
        ListNode * followSlow = NULL;
        while(fast && fast->next){
            followSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        followSlow->next = NULL;
        fast = head;
        slow = reverseList(slow);
        ListNode * dummy = new ListNode(-1);
        ListNode * ptr = dummy;
        while(slow && fast){
            ptr->next = fast;
            fast = fast->next;
            ptr = ptr->next;
            ptr->next = slow;
            slow = slow->next;
            ptr = ptr->next;
        }
        if(slow){
            ptr->next = slow;
        }
        head = dummy->next;
    }
};

/*

    1 2 3 4

    1 2
    4 3
    1 4 2 3


    1 2 3 4 5

    1 2 
    5 4 3

    1 5 2 4 3  

*/