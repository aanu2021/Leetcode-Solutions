class Solution {
public:
    
    typedef long long ll;
    
    const ll M = 1e9 + 7;
    
    ll mod(ll a){
        return ((a%M)+M)%M;
    }
    
    ll mul(ll a,ll b){
        return mod(mod(a)*mod(b));
    }
    
    ll add(ll a,ll b){
        return mod(mod(a)+mod(b));
    }
    
    
    int countSpecialSubsequences(vector<int>& nums) {
        
        ll n=nums.size();
        
        ll cnt0=0LL,cnt1=0LL,cnt2=0LL;
        
        for(ll i=0;i<n;i++){
            
            if(nums[i]==0){
                cnt0=add(mul(2LL,cnt0),1LL);
            }
            
            else if(nums[i]==1){
                cnt1=add(cnt0,mul(2LL,cnt1));
            }
            
            else{
                cnt2=add(cnt1,mul(2LL,cnt2));
            }
            
        }
        
        return mod(cnt2);
        
    }
};