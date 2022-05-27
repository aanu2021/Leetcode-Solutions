class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        
        int n=nums.size();
        
        map<int,int>mp;
        
        int currsum=0;
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            
            currsum+=nums[i];
            
            if(currsum==target || mp.find(currsum-target)!=mp.end()){
                ans++;
                mp.clear();
                currsum=0;
            }
            
            else{
                mp[currsum]=i;
            }
            
        }
        
        return ans;
        
    }
};