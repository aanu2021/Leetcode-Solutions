class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        int currsum=0;
        
        int minsum=1e9;
        
        int m=n-k;
        
        for(int i=0;i<m;i++){
            currsum+=nums[i];
        }
        
        minsum=currsum;
        
        for(int i=m;i<n;i++){
            currsum+=nums[i];
            currsum-=nums[i-m];
            minsum=min(minsum,currsum);
        }
        
        int sum=0;
        
        for(int i:nums){
            sum+=i;
        }
        
        return (sum-minsum);
        
    }
};