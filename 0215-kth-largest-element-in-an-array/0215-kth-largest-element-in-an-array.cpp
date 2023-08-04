class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int,vector<int>,greater<int>>minHeap;
        for(int i=0;i<n;i++){
            if(minHeap.size() < k){
                minHeap.push(nums[i]);
            }
            else if(!minHeap.empty() && minHeap.top() < nums[i]){
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }
        return minHeap.top();
    }
};