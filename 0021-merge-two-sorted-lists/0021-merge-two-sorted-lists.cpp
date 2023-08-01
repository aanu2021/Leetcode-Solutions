class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val > l2->val) swap(l1,l2);
        ListNode*res = l1;
        while(l1 && l2){
            ListNode*tmp = l1;
            while(l1 && l1->val <= l2->val){
                tmp = l1;
                l1 = l1->next;
            }
            tmp->next = l2;
            swap(l1,l2);
        }
        return res;
    }
};