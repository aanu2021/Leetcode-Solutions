class Solution {
public:
    
    typedef long long ll;
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<unordered_map<ll,ll>>dp(n);
        
        ll ans=0;
        
        for(int i=1;i<n;++i){
            
            for(int j=0;j<i;++j){
                
                ll diff=(ll)nums[i]-nums[j];
                
                ll cnt=0;
                
                if(dp[j].find(diff)!=dp[j].end()){
                    
                    cnt=dp[j][diff];
                    
                }
                
                ans+=cnt;
                
                dp[i][diff]+=(cnt+1);
                
            }
            
        }
        
        return ans;
        
    }
};