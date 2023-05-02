class Solution {
public:
    int arraySign(vector<int>& nums) {
        int c0=0,c1=0,c2=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0) c0++;
            if(nums[i] > 0) c1++;
            if(nums[i] < 0) c2++;
        }
        if(c0 > 0) return 0;
        else return (c2%2==0 ? 1 : -1);
    }
};