class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<bool>prefix(n,false);
        
        vector<bool>suffix(n,false);
        
        
        prefix[0]=true;
        
        suffix[n-1]=true;
        
        for(int i=1;i<n;i++){
            
            if(nums[i]>=nums[i-1]){
                prefix[i]=prefix[i-1];
            }
            
            else{
                prefix[i]=false;
            }
            
        }
        
        
        for(int i=n-2;i>=0;i--){
            
            if(nums[i]<=nums[i+1]){
                suffix[i]=suffix[i+1];
            }
            
            else{
                suffix[i]=false;
            }
            
        }
        
        
        for(int i=0;i<n;i++){
            
            bool left=(i-1>=0 ? prefix[i-1] : true);
            
            bool right=(i+1<n ? suffix[i+1] : true);
            
            int maxleft=(i-1>=0 ? nums[i-1] : INT_MIN);
            
            int minRight=(i+1<n ? nums[i+1] : INT_MAX);
            
            if(left==true && right==true && maxleft<=minRight){
                return true;
            }
            
        }
        
        return false;
        
    }
};