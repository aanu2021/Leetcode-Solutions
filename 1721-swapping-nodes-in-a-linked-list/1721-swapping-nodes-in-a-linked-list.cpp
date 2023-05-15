class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        int n=0;
        
        ListNode*p=head;
        
        while(p!=NULL){
            p=p->next;
            n++;
        }
        
        
        int tempk=k;
        
        k--;
        
        ListNode*ptr=head;
        
        while(ptr!=NULL && k>0){
            ptr=ptr->next;
            k--;
        }
        
        k=tempk;
        
        int req=n-k+1;
        
        req--;
        
        ListNode*qtr=head;
        
        while(qtr!=NULL && req>0){
            qtr=qtr->next;
            req--;
        }
        
        swap(ptr->val,qtr->val);
        
        return head;
        
    }
};