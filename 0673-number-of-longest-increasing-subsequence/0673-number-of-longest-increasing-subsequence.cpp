class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>lis(n,1);
        vector<int>count(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i]){
                    if(lis[i] < lis[j] + 1){
                        lis[i] = lis[j] + 1;
                        count[i] = count[j];
                    }
                    else if(lis[i] == lis[j] + 1){
                        count[i] += count[j];
                    }
                }
            }
        }
        int maxLIS = 0;
        for(int i=0;i<n;i++){
            maxLIS = max(maxLIS, lis[i]);
        }
        int ways = 0;
        for(int i=0;i<n;i++){
            if(lis[i] == maxLIS){
                ways += count[i];
            }
        }
        return ways;
    }
};