class Solution {
public:
    
    bool isValid(vector<int>&prefix){
        
        for(int i=0;i<32;i++){
            if(prefix[i]>1){
                return false;
            }
        }
        
        return true;
        
    }
    
    int longestNiceSubarray(vector<int>& nums) {
        
        int n = nums.size();
        
        int maxLen = 0;
        
        int l = 0, r = 0;
        
        vector<int>prefix(32,0);
        
        while(l<n && r<n){
            
            for(int bit=31;bit>=0;bit--){
                if((nums[r]&(1<<bit))){
                    prefix[bit]++;
                }
            }
            
            while(l<=r && !isValid(prefix)){
                
                for(int bit=31;bit>=0;bit--){
                    if((nums[l]&(1<<bit))){
                        prefix[bit]--;
                    }
                }
                
                l++;
                
            }
            
            maxLen = max(maxLen,r-l+1);    
                
            r++;
            
        }
        
        return maxLen;
        
    }
};