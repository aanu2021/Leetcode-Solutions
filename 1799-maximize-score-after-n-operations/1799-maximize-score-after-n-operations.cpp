class Solution {
public:
    
    int dp[1<<14];
    
    int func(vector<int>&nums,int ops,int mask){
        
        int n = nums.size();
        
        int m = n/2;
        
        if(ops > m) return 0;
        
        if(dp[mask] != -1) return dp[mask];
        
        int currval = 0;
        
        for(int i=0;i<n;i++){
            if((mask&(1<<i))==0) continue;
            for(int j=i+1;j<n;j++){
                if((mask&(1<<j))==0) continue;
                int newMask = mask^(1<<i);
                newMask ^= (1<<j);
                currval = max(currval,(ops*__gcd(nums[i],nums[j])) + func(nums,ops + 1 , newMask));
            }
        }
        
        return dp[mask] = currval;
        
    }
    
    int maxScore(vector<int>& nums) {
        
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        int ans = func(nums,1,(1<<n)-1);
        return ans;
        
    }
};