/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        ListNode * slow = head;
        ListNode * fast = head;
        while(n > 0){
            slow = slow->next;
            n--;
        }
        if(slow == NULL){
            head = head->next;
            return head;
        }
        while(slow && slow->next){
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = fast->next->next;
        return head;
    }
};

// 1 -> 2 -> 3 -> 4 -> 5
                   
    