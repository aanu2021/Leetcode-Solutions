class Solution {
public:
   
    vector<int>dp;
    
    int func(vector<int>&nums,int i,int n,int mask,int ns){
        if(i==n) return 0;
        if(dp[mask] != -1) return dp[mask];
        int currMax = 0;
        for(int slot=1,bit=1;slot<=ns;slot++,bit*=3){
            if((mask/bit)%3){
                currMax = max(currMax,(nums[i]&slot) + func(nums,i+1,n,mask-bit,ns));
            }
        }
        return dp[mask] = currMax;
    }
    
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int n = nums.size();
        int mask = pow(3,numSlots);
        dp = vector<int>(mask,-1);
        int ans = func(nums,0,n,mask-1,numSlots);
        return ans;
    }
};

// 1 2 3 4 5 6
    
// ns = 3
    
// 0 1 2 3 4 5
    
    
// dp[i][mask]    
    
// 3^0 + 3^1 + 3^2 + ..... 

// 3^3 = 27 - 1 = 26
    
// 2*3^2 + 2*3^1 + 2*3^0
    
// 4^3 = 64 - 1 = 63
    
// 3*1 + 3*4 + 3*16    

// 1 + 3 + 9 + 27 = 40
    
    

// 3^1 + 3^2 + 3^3 + 3^4 + ......
    
    