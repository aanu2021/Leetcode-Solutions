
class Solution {
public:
    
    ListNode*mergeTwoList(ListNode*&head1,ListNode*&head2){
        
        ListNode*ptr1=head1;
        ListNode*ptr2=head2;
        
        ListNode*dummy=new ListNode(-1);
        
        ListNode*ptr=dummy;
        
        while(ptr1!=NULL && ptr2!=NULL){
            
            if(ptr1->val<=ptr2->val){
                ptr->next=ptr1;
                ptr1=ptr1->next;
            }
            
            else{
                ptr->next=ptr2;
                ptr2=ptr2->next;
            }
            
            ptr=ptr->next;
            
        }
        
        while(ptr1!=NULL){
            
            ptr->next=ptr1;
            ptr1=ptr1->next;
            ptr=ptr->next;
            
        }
        
        while(ptr2!=NULL){
            
            ptr->next=ptr2;
            ptr2=ptr2->next;
            ptr=ptr->next;
            
        }
        
        return dummy->next;
        
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int n=lists.size();
        
        if(n==0){
            return NULL;
        }
        
        if(n==1){
            return lists[0];
        }
        
        
        int interval=1;
        
        
        while(interval<n){
            
            for(int i=0;i+interval<n;i+=(2*interval)){
                
                lists[i]=mergeTwoList(lists[i],lists[i+interval]);
                
                
            }
            
            interval*=2;
            
        }
        
        return lists[0];
        
    }
};