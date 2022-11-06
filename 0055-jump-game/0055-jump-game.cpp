class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        int flag = 0;
        
        for(int i=0;i<n;i++){
            if(i>flag) return false;
            flag = max(flag,i+nums[i]);
        }
        return true;
        
    }
};