class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>dp(k,0);
        int currSum = 0 , ans = 0;
        for(int i=0;i<n;i++){
            currSum += nums[i];
            currSum = ( ( (currSum + k) % k) + k ) % k;
            dp[currSum]++;
        }
        ans += dp[0];
        for(int i=0;i<k;i++){
            ans += ((dp[i]*(dp[i]-1))/2);
        }
        return ans;
    }
};


   /* 


    a0 a1 a2 a3 a4 a5 a6

    p0 p1 p2 p3 p4 p5 p6
    
    subarray_sum[2...5] = (a0 + a1 + a2 + a3 + a4 + a5) - (a0 + a1)
        
    subarray_sum[2...5] = (p5) - (p1)
        
    subarray_sum[l...r] = (p[r]) - (p[l-1])
        
    Let say the subarray starting at index l , and ending at index 
    r , is divisible by k.
        
    subarray_sum[l...r] % k == 0
        
    (p[r] - p[l-1]) % k     == 0
        
    ((p[r] % k) - (p[l-1] % k)) % k == 0  
        
    p[r] = (q1*k) + r1
    p[l-1] = q2*k + r2
    
    (r1 - r2) % k == 0
        
    r1 == r2  
    
    
    */

