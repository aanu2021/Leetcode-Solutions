class KthLargest {
public:
    
    priority_queue<int,vector<int>,greater<int>>minheap;
    
    int L;
    
    KthLargest(int k, vector<int>& nums) {
        
        int n = nums.size();
        L = k;
        
        for(int i=0;i<n;i++){
            minheap.push(nums[i]);
            if(minheap.size() > L){
                minheap.pop();
            }
        }
        
    }
    
    int add(int val) {
        
        minheap.push(val);
        if(minheap.size() > L){
            minheap.pop();
        }
        
        return minheap.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */