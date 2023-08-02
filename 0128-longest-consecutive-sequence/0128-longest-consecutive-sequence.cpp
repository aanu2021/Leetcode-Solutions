class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int maxLen = 0;
        for(int i=0;i<n;i++){
            int prev = nums[i];
            int j = i;
            int currLen = 1;
            while(j<n && nums[j]-prev <= 1){
                if(nums[j]-prev == 1){
                    currLen++;
                }
                prev = nums[j];
                j++;
            }
            maxLen = max(maxLen, currLen);
            i = j;
            i--;
        }
        return maxLen;
    }
};