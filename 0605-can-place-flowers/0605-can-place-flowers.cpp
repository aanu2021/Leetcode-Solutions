class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) continue;
            if((i==0 || nums[i-1]==0) && (i+1==nums.size() || nums[i+1]==0)){
                nums[i] = 1;
                cnt++;
                continue;
            }
        }
        return cnt >= n;
    }
};