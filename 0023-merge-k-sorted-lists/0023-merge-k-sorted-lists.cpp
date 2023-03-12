class Solution {
public:
    
    ListNode * mergeList(ListNode*& a,ListNode*& b){
        ListNode * ptr1 = a;
        ListNode * ptr2 = b;
        ListNode * dummyNode = new ListNode(-1);
        ListNode * ptr = dummyNode;
        while(ptr1 && ptr2){
            if(ptr1->val <= ptr2->val){
                ptr->next = ptr1;
                ptr1 = ptr1->next;
            }
            else{
                ptr->next = ptr2;
                ptr2 = ptr2->next;
            }
            ptr = ptr->next;
        }
        if(ptr1){
            ptr->next = ptr1;
        }
        if(ptr2){
            ptr->next = ptr2;
        }
        return dummyNode->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return NULL;
        int interval = 1;
        while(interval < n){
            for(int i=0;i+interval < n;i+=(2*interval)){
                lists[i] = mergeList(lists[i],lists[i+interval]);
            }
            interval *= 2;
        }
        return lists[0];
    }
};