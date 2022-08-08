class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int>tails;
        
        tails.push_back(nums[0]);
        
        for(int i=1;i<n;++i){
            
            if(tails.back()<nums[i]){
                tails.push_back(nums[i]);
            }
            
            else{
                int index=lower_bound(tails.begin(),tails.end(),nums[i])-tails.begin();
                tails[index]=nums[i];
            }
            
        }
        
        return tails.size();
        
    }
};