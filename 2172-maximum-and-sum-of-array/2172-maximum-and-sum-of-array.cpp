class Solution {
public:
   
    vector<vector<int>>dp;
    
    int func(vector<int>&nums,int i,int n,int mask,int ns,int numSlots){
        
        if(i==n) return 0;
        if(dp[i][mask] != -1) return dp[i][mask];
        int currMax = 0;
        for(int j=0;j<ns;j++){
            if((mask&(1<<j))==0) continue;
            int curr = j;
            if(j >= numSlots) curr -= numSlots;
            currMax = max(currMax,((curr+1)&nums[i]) + func(nums,i+1,n,(mask^(1<<j)),ns,numSlots));
        }
        return dp[i][mask] = currMax;
        
    }
    
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int n = nums.size();
        int ns = 2*numSlots;
        int MASK = (1<<ns);
        dp = vector<vector<int>>(n,vector<int>(MASK,-1));
        int ans = func(nums,0,n,MASK-1,ns,numSlots);
        return ans;
    }
};

// 1 2 3 4 5 6
    
// ns = 3
    
// 0 1 2 3 4 5
    
    
// dp[i][mask]    
    
// 3^0 + 3^1 + 3^2 + .....     