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
    
    ListNode* mergeKLists2(vector<ListNode*>& lists) {
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
    
    /*
    
    Time Complexity : O(N*K*logK)
    Space Complexity : O(N*logK)
    
    */
    
    struct Node{
        
        ListNode * ptr;
        int index;
        
    };
    
    struct comp{
      
        bool operator()(const Node&x, const Node&y){
            return x.ptr->val > y.ptr->val;
        }
        
    };
    
    ListNode* mergeKLists(vector<ListNode*>&lists){
        int n = lists.size();
        if(n==0) return NULL;
        priority_queue<Node,vector<Node>,comp>pq;
        for(int i=0;i<n;i++){
            if(lists[i]){
                pq.push({lists[i],i});   
            }
        }
        ListNode * dummyNode = new ListNode(-1);
        ListNode * temp = dummyNode;
        while(!pq.empty()){
            auto curr = pq.top(); pq.pop();
            int index = curr.index;
            temp->next = curr.ptr;
            temp = temp->next;
            if(lists[index]->next){
                lists[index] = lists[index]->next;
                pq.push({lists[index],index});
            }
        }
        return dummyNode->next;
    }
    
};