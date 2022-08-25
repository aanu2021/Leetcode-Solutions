class Solution {
public:
    
    struct Node{
      
        ListNode*curr;
        int index;
        
        Node(ListNode*node,int idx){
            
            curr=node;
            index=idx;
            
        }
        
    };
    
    
    struct comp{
      
        bool operator()(const Node&x,const Node&y){
            
            return x.curr->val > y.curr->val;
            
        }
        
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int k=lists.size();
        
        if(k==0){
            return NULL;
        }
        
        if(k==1){
            return lists[0];
        }
        
        vector<ListNode*>ptr(k);
        
        priority_queue<Node,vector<Node>,comp>pq;
        
        for(int i=0;i<k;++i){
            
            ptr[i]=lists[i];
            
            if(lists[i]!=NULL){
                
                pq.push({lists[i],i});
                
            }
            
        }
        
        
        ListNode*dummy=new ListNode(-1);
        
        ListNode*head=dummy;
        
        
        while(!pq.empty()){
            
            auto current=pq.top();
            pq.pop();
            
            ListNode*ptrr=current.curr;
            int idx=current.index;
            
            head->next=ptrr;
            head=head->next;
            
            ptr[idx]=ptr[idx]->next;
            
            if(ptr[idx]){
                
                pq.push({ptr[idx],idx});
                
            }
            
        }
        
        return dummy->next;
        
    }
};