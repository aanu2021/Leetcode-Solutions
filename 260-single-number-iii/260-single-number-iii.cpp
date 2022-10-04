class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int n=nums.size();
        
        int ans = 0;
        
        for(int bit=31;bit>=0;bit--){
            
            int cnt = 0;
            
            for(int i=0;i<n;++i){
                
                if((nums[i]&(1<<bit))){
                    
                    cnt++;
                    
                }
                
            }
            
            if(cnt%3){
                
                ans|=(1<<bit);
                
            }
            
        }
        
        return ans;
        
    }
};