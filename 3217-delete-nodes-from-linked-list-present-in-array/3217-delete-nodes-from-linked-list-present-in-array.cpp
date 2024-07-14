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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode * dummy = new ListNode(-1);
        ListNode * ptr = dummy;
        unordered_set<int>S;
        for(int &ele : nums) S.insert(ele);
        while(head){
            int val = head->val;
            if(S.find(val) == S.end()){
                ptr->next = new ListNode(val);
                ptr = ptr->next;
            }
            head = head->next;
        }
        return dummy->next;
    }
};