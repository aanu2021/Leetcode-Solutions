class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int n=nums.size();
        
        int maxsum=0;
        
        int count=0;
        
        map<int,int>mp;
        
        int l=0,r=0;
        
        int currsum=0;
        
        while(l<n && r<n){
            
            if(mp[nums[r]]>0){
                count++;
            }
            
            mp[nums[r]]++;
            
            currsum+=nums[r];
            
            while(l<=r && count>0){
                
                mp[nums[l]]--;
                
                currsum-=nums[l];
                
                if(mp[nums[l]]==1){
                    count--;
                }
                
                l++;
                
            }
            
            maxsum=max(maxsum,currsum);
            r++;
            
        }
        
        return maxsum;
        
    }
};