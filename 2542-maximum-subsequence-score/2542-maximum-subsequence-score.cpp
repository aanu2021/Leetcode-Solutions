class Solution {
public:
    
    typedef long long ll;
    
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n = nums1.size();
        
        vector<pair<int,int>>nums;
        for(int i=0;i<n;i++){
            nums.push_back({nums2[i],nums1[i]});
        }
        
        sort(nums.rbegin(),nums.rend());
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        ll maxscore = 0LL;
        ll currSum = 0LL;
        
        for(int i=0;i<n;i++){
            
            int minEle = nums[i].first;
            
            pq.push(nums[i].second);
            currSum += (ll)nums[i].second;
            
            if(pq.size() > k){
                currSum -= pq.top(); pq.pop();
            }
            
            if(pq.size()==k){
                ll currScore = (ll)minEle*currSum;
                maxscore = max(maxscore,currScore);
            }
            
        }
        
        return maxscore;
        
    }
};