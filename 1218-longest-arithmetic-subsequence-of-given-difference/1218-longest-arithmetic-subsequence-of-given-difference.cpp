class Solution {
public:
    int longestSubsequence(vector<int>& nums, int x) {
        
        int n=nums.size();
        
        int maxLen=0;
        
        map<int,int>mp;
        
        for(int i=0;i<n;++i){
            
            int prevLen=0,currLen=1;
            
            if(mp.find(nums[i]-x)!=mp.end()){
                
                prevLen=mp[nums[i]-x];
                
            }
            
            currLen+=prevLen;
            
            mp[nums[i]]=max(mp[nums[i]],currLen);
            
            maxLen=max(maxLen,mp[nums[i]]);
            
        }
        
        return maxLen;
        
    }
};