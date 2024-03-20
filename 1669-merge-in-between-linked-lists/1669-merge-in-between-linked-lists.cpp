class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode*ptr = list1;
        ListNode * follow = NULL;
        while(a > 0){
            follow = ptr;
            ptr = ptr->next;
            a--;
        }
        ptr = list1;
        ListNode * nextFollow = list1;
        while(b > 0){
            ptr = ptr->next;
            b--;
        }
        nextFollow = ptr->next;
        ListNode * ptr2 = list2;
        while(ptr2 && ptr2->next){
            ptr2 = ptr2->next;
        }
        ptr2->next = nextFollow;
        follow->next = list2;
        return list1;
    }
};