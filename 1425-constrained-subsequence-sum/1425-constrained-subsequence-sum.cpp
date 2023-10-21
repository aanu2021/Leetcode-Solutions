class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        int MAX = INT_MIN;
        for(int i=0;i<n;i++){
            MAX = max(MAX, nums[i]);
        }
        priority_queue<pair<int,int>>pq;
        for(int i=n-1;i>=0;i--){
            while(!pq.empty() && pq.top().second > i+k){
                pq.pop();
            }
            int currval = nums[i];
            if(!pq.empty()){
                currval = max(currval, currval + pq.top().first);
            }
            MAX = max(MAX, currval);
            pq.push({currval,i});
        }
        return MAX;
    }
};