
class Solution {
public:
    
    struct Node{
      
        ListNode*curr;
        int value;
        
        Node(ListNode*c,int val){
            
            curr=c;
            value=val;
            
        }
        
    };
    
    struct comp{
      
        bool operator()(const Node&x,const Node&y){
            
            return x.curr->val > y.curr->val;
            
        }
        
    };
    
   
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int n=lists.size();
        
        if(n==0){
            return NULL;
        }
        
        if(n==1){
            return lists[0];
        }
        
        
        vector<ListNode*>ptr(n);
        
        priority_queue<Node,vector<Node>,comp>pq;
        
        for(int i=0;i<n;++i){
            
            ptr[i]=lists[i];
            
            if(lists[i]!=NULL){
                pq.push({lists[i],i});
            }
            
        }
        
        ListNode*dummy=new ListNode(-1);
        
        ListNode*head=dummy;
        
        while(!pq.empty()){
            
            auto curr=pq.top();
            pq.pop();
            
            ListNode*currptr=curr.curr;
            
            int idx=curr.value;
            
            head->next=currptr;
            
            head=head->next;
            
            ptr[idx]=ptr[idx]->next;
            
            if(ptr[idx]!=NULL){
                
                pq.push({ptr[idx],idx});
                
            }
            
            
        }
        
        return dummy->next;
        
    }
};