class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int low = 0, high = nums[n-1] - nums[0];
        int ans = high;
        while(low <= high){
            int mid = (low + high)/2;
            int cnt = 0;
            for(int i=1;i<n;i++){
                if((nums[i]-nums[i-1]) <= mid){
                    cnt++;
                    i++;
                }
            }
            if(cnt >= p){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};