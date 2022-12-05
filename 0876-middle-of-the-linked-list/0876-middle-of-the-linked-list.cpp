class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode*slow=head;
        ListNode*fast=head;
        ListNode*follow=NULL;
        while(fast && fast->next){
            follow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        follow->next = NULL;
        return slow;
    }
};