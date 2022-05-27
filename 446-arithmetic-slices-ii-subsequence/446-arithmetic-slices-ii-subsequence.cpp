class Solution {
public:
    
    typedef long long ll;
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        ll n=nums.size();
        
        vector<unordered_map<ll,ll>>mp(n);
        
        ll ans=0LL;
        
        for(ll i=1;i<n;i++){
            
            for(ll j=0;j<i;j++){
                
                ll diff=((ll)nums[i]-(ll)nums[j]);
                
                ll sum=0LL;
                
                if(mp[j].find(diff)!=mp[j].end()){
                    
                    sum=mp[j][diff];
                    
                }
                
                ans+=sum;
                
                mp[i][diff]+=(sum+1);
                
            }
            
        }
        
        return ans;
        
    }
};