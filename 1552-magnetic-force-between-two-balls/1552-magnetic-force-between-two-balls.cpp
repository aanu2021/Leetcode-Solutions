class Solution {
public:
    
    bool canPlace(vector<int>&nums, int n, int mid, int m){
        int placed = 1, prev = nums[0];
        for(int i=1;i<n;i++){
            if((nums[i]-prev) >= mid){
                placed++;
                prev = nums[i];
            }
        }
        return placed >= m;
    }
    
    int maxDistance(vector<int>& nums, int m) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int low = 0, high = nums[n-1] - nums[0];
        int answer = -1;
        while(low <= high){
            int mid = (low + high)/2;
            if(canPlace(nums, n, mid, m)){
                answer = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return answer;
    }
};