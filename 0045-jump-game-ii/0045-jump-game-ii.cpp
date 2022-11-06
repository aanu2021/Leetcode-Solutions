class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        int currmax=min(nums[0],n-1);
        if(currmax==n-1) return 1;
        int nextmax = -1;
        int jumps = 1;
        for(int i=0;i<n;i++){
            nextmax=max(nextmax,min(n-1,i+nums[i]));
            if(i==currmax){
                currmax = nextmax;
                jumps++;
            }
            if(currmax==n-1){
                return jumps;
            }
        }
        return -1;
    }
};