class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int>lis(n,1);
        vector<int>count(n,1);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j]){
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
        
        int ways = 0;
        int maxLIS = 0;
        for(int i=0;i<n;i++){
            maxLIS = max(maxLIS, lis[i]);
        }
        
        for(int i=0;i<n;i++){
            if(lis[i] == maxLIS){
                ways += count[i];
            }
        }
        
        return ways;
    }
};

/*

       1 2 4 3 5 4 7 2
lis    1 2 3 3 4 4 5 1
count  1 1 1 1 2 1 3 1   


*/
