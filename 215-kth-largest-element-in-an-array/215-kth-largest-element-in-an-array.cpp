class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            
            if(pq.size()<k){
                pq.push(nums[i]);
            }
            
            else if(!pq.empty() && pq.top()<nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
            
        }
        
        return pq.top();
        
    }
};