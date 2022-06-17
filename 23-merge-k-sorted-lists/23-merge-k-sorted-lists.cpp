class Solution {
public:
    
    ListNode*mergeList(ListNode*&head1,ListNode*&head2){
        
        ListNode*ptr1=head1;
        ListNode*ptr2=head2;
        
        ListNode*dummy=new ListNode(-1);
        
        ListNode*temp=dummy;
        
        while(ptr1!=NULL && ptr2!=NULL){
            
            if(ptr1->val<ptr2->val){
                temp->next=ptr1;
                ptr1=ptr1->next;
            }else{
                temp->next=ptr2;
                ptr2=ptr2->next;
            }
            
            temp=temp->next;
            
        }
        
        while(ptr1!=NULL){
            
            temp->next=ptr1;
            ptr1=ptr1->next;
            temp=temp->next;
            
        }
        
        while(ptr2!=NULL){
            
            temp->next=ptr2;
            ptr2=ptr2->next;
            temp=temp->next;
            
        }
        
        return dummy->next;
        
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int n=lists.size();
        
        if(n==0){
            return NULL;
        }
        
        int interval=1;
        
        while(interval<n){
            
            for(int i=0;i+interval<n;i+=2*interval){
                
                lists[i]=mergeList(lists[i],lists[i+interval]);
                
            }
            
            interval*=2;
            
        }
        
        return lists[0];
        
    }
};