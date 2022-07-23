class Solution {
public:
    
    typedef long long ll;
    
    ll dp[1<<14];
    
    ll func(vector<int>&nums1,vector<int>&nums2,ll i,ll mask){
        
        if(i>=nums1.size()){
            return 0LL;
        }
        
        if(dp[mask]!=-1){
            return dp[mask];
        }
        
        ll ans=1e14;
        
        for(ll j=0;j<nums2.size();++j){
            
            if((mask&(1LL<<j))==0){
                
               ans=min(ans,(nums1[i]^nums2[j])+func(nums1,nums2,i+1,(mask|(1LL<<j))));
                
            }
            
        }
        
        return dp[mask] = ans;
        
    }
    
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        
        ll n=nums1.size();
        
        memset(dp,-1,sizeof(dp));
        
        ll ans=func(nums1,nums2,0LL,0LL);
        
        return ans;
        
    }
};