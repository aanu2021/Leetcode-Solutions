class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int>inc(n,1);
        vector<int>dec(n,1);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    inc[i]=max(inc[i],1+dec[j]);
                }else if(nums[i]<nums[j]){
                    dec[i]=max(dec[i],1+inc[j]);
                }
            }
        }
        
        int maxLen = 0;
        
        for(int i=0;i<n;i++){
            maxLen = max(maxLen,inc[i]);
            maxLen = max(maxLen,dec[i]);
        }
        
        return maxLen;
        
    }
};