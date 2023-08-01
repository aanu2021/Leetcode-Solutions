class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode * nextNode = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return nextNode;
    }
};