class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int>prefix(32,0);
        
        for(int i=0;i<n;++i){
            
            for(int j=31;j>=0;j--){
                
                if((nums[i]&(1<<j))){
                    
                    prefix[j]++;
                    
                }
                
            }
            
        }
        
        int ans = 0;
        
        for(int i=0;i<32;i++){
            
            if(prefix[i]%3){
                
                ans|=(1<<i);
                
            }
            
        }
        
        return ans;
        
    }
};