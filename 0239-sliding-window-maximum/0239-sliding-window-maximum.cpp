class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans;
        
        priority_queue<pair<int,int>>pq;
        
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
            while(!pq.empty() && pq.top().second <= (i-k)){
                pq.pop();
            }
            if(i+1>=k){
                ans.push_back(pq.top().first);
            }
        }
        
        return ans;
    }
};