class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long count=1,sz=nums.size(),patches=0,i=0;
        
        while(count<=n){
            if(i<sz && nums[i]<=count){
                count+=nums[i++];
            }
            else{
                count*=2;
                patches++;
            }
        }
        return patches;
    }
};