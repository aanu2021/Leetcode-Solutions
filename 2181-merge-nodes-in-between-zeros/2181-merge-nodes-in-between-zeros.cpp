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
    ListNode* mergeNodes(ListNode* head) {
        if(!head) return head;
        ListNode * pointer = head;
        while(pointer){
            if(pointer->val == 0){
                pointer = pointer->next;
            }
            else{
                ListNode * nextPointer = pointer;
                int currSum = 0;
                while(nextPointer && nextPointer->val != 0){
                    currSum += nextPointer->val;
                    nextPointer = nextPointer->next;
                }
                pointer->val = currSum;
                pointer->next = nextPointer;
                pointer = pointer->next;
            }
        }
        ListNode * newHead = head->next;
        if(!newHead) return newHead;
        pointer = newHead;
        while(pointer && pointer->next){
            pointer->next = pointer->next->next;
            pointer = pointer->next;
        }
        return newHead;
    }
};