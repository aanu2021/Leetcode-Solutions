class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int>preMax(n);
        vector<int>sufMin(n);
        
        preMax[0] = nums[0];
        sufMin[n-1] = nums[n-1];
        
        for(int i=1;i<n;++i){
            preMax[i] = max(preMax[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;--i){
            sufMin[i] = min(sufMin[i+1],nums[i]);
        }
        
        int left = -1,right = -1;
        
        for(int i=0;i<n-1;i++){
            if(preMax[i] > sufMin[i+1]){
                if(left==-1) left = i;
                right = i+1;
            }
        }
        
        if(left==-1 || right==-1) return 0;
        else return right - left + 1;
        
    }
};