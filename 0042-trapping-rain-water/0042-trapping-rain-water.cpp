class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n);
        vector<int>suffix(n);
        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];
        for(int i=1;i<n;i++){
            prefix[i] = max(prefix[i-1], nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            suffix[i] = max(suffix[i+1], nums[i]);
        }
        int answer = 0;
        for(int i=0;i<n;i++){
            answer += min(prefix[i], suffix[i]) - nums[i];
        }
        return answer;
    }
};