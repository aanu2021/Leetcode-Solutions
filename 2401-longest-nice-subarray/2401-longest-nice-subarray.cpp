class Solution {
public:
    
    void Mark_Bit(vector<int>&prefix,int num,int &cnt){
        
        for(int i=0;i<32;i++){
            
            if((num&(1<<i))){
                
                prefix[i]++;
                
                if(prefix[i] == 2){
                    cnt++;
                }
                
            }
            
        }
        
    }
    
    
    void Unmark_Bit(vector<int>&prefix,int num,int &cnt){
        
        for(int i=0;i<32;i++){
            
            if((num&(1<<i))){
                
                prefix[i]--;
                
                if(prefix[i] == 1){
                    cnt--;
                }
                
            }
            
        }
        
    }
    
    int longestNiceSubarray(vector<int>& nums) {
        
        int n = nums.size();
        
        int maxLen = 0;
        
        int l = 0, r = 0;
        
        int count = 0;
        
        vector<int>prefix(32,0);
        
        while(l<n && r<n){
            
            Mark_Bit(prefix,nums[r],count);
            
            while(l<=r && count){
                
                Unmark_Bit(prefix,nums[l],count);
                
                l++;
                
            }
            
            maxLen = max(maxLen,r-l+1);    
                
            r++;
            
        }
        
        return maxLen;
        
    }
};