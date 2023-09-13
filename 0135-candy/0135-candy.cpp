class Solution {
public:
    int candy(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr(n,1);
        for(int i=1;i<n;i++){
            if(nums[i] > nums[i-1]){
                arr[i] = max(arr[i], 1 + arr[i-1]);
            }
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i] > nums[i+1]){
                arr[i] = max(arr[i], 1 + arr[i+1]);
            }
        }
        int totalSum = 0;
        for(int i=0;i<n;i++){
            totalSum += arr[i];
        }
        return totalSum;
    }
};