class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        int n = 0;
        ListNode*ptr = head;
        
        while(ptr){
            ptr = ptr->next;
            n++;
        }
        
        vector<ListNode*>ans(k,NULL);
        int index = 0;
        
        if(n < k){
            ptr = head;
            while(ptr){
                ans[index++] = new ListNode(ptr->val);
                ptr = ptr->next;
            }
            return ans;
        }
        
        int each_have = n/k;
        int extra_some = n%k;
        
        ptr = head;
        
        for(int i=0;i<k;i++){
            int currLen = each_have;
            if(extra_some){
                currLen++;
                extra_some--;
            }
            ans[i] = ptr;
            ListNode*follow = ptr;
            while(currLen--){
                follow = ptr;
                ptr = ptr->next;
            }
            follow->next = NULL;
        }
        
        return ans;
        
    }
};