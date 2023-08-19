class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int mini = 1e9, maxi = -1e9;
        for(int i=0;i<n-1;i++){
            if(nums[i] > nums[i+1]){
                mini = min(mini, nums[i+1]);
            }
        }
        for(int i=n-1;i>0;i--){
            if(nums[i-1] > nums[i]){
                maxi = max(maxi, nums[i-1]);
            }
        }
        int l=0,r=n-1;
        for(l=0;l<n;l++){
            if(nums[l] > mini) break;
        }
        for(r=n-1;r>=0;r--){
            if(nums[r] < maxi) break;
        }
        return max(r-l+1,0);
    }
};