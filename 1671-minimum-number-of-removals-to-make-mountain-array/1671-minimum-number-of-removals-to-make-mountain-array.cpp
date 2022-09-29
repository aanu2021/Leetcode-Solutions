class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int>inc(n,1);
        vector<int>dec(n,1);
        
        for(int i=1;i<n;++i){
            for(int j=0;j<i;++j){
                if(nums[j]<nums[i]){
                    inc[i]=max(inc[i],inc[j]+1);
                }
            }
        }
        
        for(int i=n-2;i>=0;--i){
            for(int j=n-1;j>i;--j){
                if(nums[i]>nums[j]){
                    dec[i]=max(dec[i],dec[j]+1);
                }
            }
        }
        
        int maxLen = 0;
        
        for(int i=0;i<n;++i){
            
            if(inc[i]>1 && dec[i]>1){
                
                maxLen = max(maxLen,inc[i]+dec[i]-1);
                
            }
            
        }
        
        return n-maxLen;
        
    }
};

/*

     2,1,1,5,6,2,3,1
    
inc: 1,1,1,2,3,2,3,1     
dec: 2,1,1,3,3,2,2,1    

*/
    
    