class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode*ptr = head;
        int n = 0; // Length of the LL
        while(ptr){
            ptr = ptr->next;
            n++;
        }

        vector<ListNode*>ans(k,NULL); 

        // Case 1 --> n < k (some seg might be empty)

        if(n < k){

            ptr = head;

            for(int i=0;i<n;i++){
                ans[i] = new ListNode(ptr->val);
                ptr = ptr->next;
            }

            return ans;

        }  

        // Case 2 --> n >= k (every seg must have some nodes + no two parts should have a size differing by more than one)

        //  Len = 13  k = 3

        //  10 / 3 = 3   (3*3) = 9  10 - 9 = 1

        //  5 4 4  

        //  each segment will get (n/k) nodes for sure
        //  additionally first (n%k) segments get one nodes extra

         int each_have = (n/k);
         int extra_some = (n%k);

         for(int i=0;i<k;i++){

             int currLen = each_have;
             if(extra_some > 0) currLen++;
             extra_some--;

             ListNode * pointer = head;
             ListNode * follow = pointer;
             ListNode * temp = pointer;

             while(currLen){
                 follow = pointer;
                 pointer = pointer->next;
                 currLen--;
             }
             
             follow->next = NULL;
             head = pointer;
             ans[i] = temp;

         }

         return ans;

    }
};