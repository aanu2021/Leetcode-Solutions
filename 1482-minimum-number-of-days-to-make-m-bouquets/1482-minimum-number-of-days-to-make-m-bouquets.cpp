class Solution {
public:
    
    typedef long long ll;
    
    bool canMake(vector<int>&nums, int n, int mid, int m, int k){
        int cnt = 0;
        int consecutive = 0;
        for(int i=0;i<n;i++){
            if(nums[i] > mid){
                consecutive = 0;
            }
            else{
                consecutive++;
                if(consecutive == k){
                    cnt++; consecutive = 0;
                }
            }
        }
        return cnt >= m;
    }
    
    int minDays(vector<int>& nums, int m, int k) {
        int n = nums.size();
        ll prod = (ll)((ll)m*(ll)k);
        if(prod > n) return -1;
        int low = 0, high = *max_element(nums.begin(),nums.end());
        int answer = high;
        while(low <= high){
            int mid = low + ((high - low)/2);
            if(canMake(nums, n, mid, m, k)){
                answer = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return answer;
    }
};