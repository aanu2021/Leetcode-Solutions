class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int g = numsDivide[0];
        for(int i=1;i<numsDivide.size();i++){
            g = __gcd(g,numsDivide[i]);
        }
        int mini = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(g%nums[i]==0) mini = min(mini,nums[i]);
        }
        int ans = 0;
        if(mini==INT_MAX) return -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] < mini) ans++;
        }
        return ans;
    }
};