class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        int currJump = min(nums[0],n-1);
        if(currJump == n-1) return 1;
        int nextJump = -1;
        int jumps = 1;
        for(int i=0;i<n;i++){
            nextJump = max(nextJump,min(n-1,i+nums[i]));
            if(i == currJump){
                currJump = nextJump;
                jumps++;
            }
            if(currJump == n-1) return jumps;
        }
        return -1;
    }
};