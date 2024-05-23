class Solution {
public:
    
    vector<vector<int>>dp;
    
    int func(vector<int>&nums, int i, int mask, int n, int k){
        if(i == n) return 1;
        if(dp[i][mask] != -1) return dp[i][mask];
        int ways = func(nums, i+1, mask, n, k);
        bool flag = true;
        for(int j=0;j<i;j++){
            if((mask&(1<<j))){
                int diff = nums[i] - nums[j];
                if(diff == k){
                    flag = false;
                    break;
                }
            }
        }
        if(flag){
            ways += func(nums, i+1, (mask|(1<<i)), n, k);
        }
        return dp[i][mask] = ways;
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int M = (1<<n);
        dp.clear();
        dp = vector<vector<int>>(n, vector<int>(M, -1));
        int answer = func(nums, 0, 0, n, k);
        return answer - 1;
    }
};

//    2 4 6
//  0 1 2 3
//    1 1 2      
    