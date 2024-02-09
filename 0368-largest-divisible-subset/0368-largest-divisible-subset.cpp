class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, 1);
        vector<int>prev(n, -1);
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j] == 0){
                    if(dp[i] < 1 + dp[j]){
                        dp[i] = 1 + dp[j];
                        prev[i] = j;
                    }
                }
            }
        }
        int maxLen = *max_element(dp.begin(),dp.end());
        int idx = -1;
        for(int i=0;i<n;i++){
            if(dp[i] == maxLen){
                idx = i; break;
            }
        }
        vector<int>answer;
        while(idx != -1){
            answer.push_back(nums[idx]);
            idx = prev[idx];
        }
        sort(answer.begin(),answer.end());
        return answer;
    }
};