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
       
        /*
        
        [0,1,2,0,1,2]   -->   0 1 2
         0 1 2 3 4 5          0 1 2
                              0 1 2
                              0 1 2
                              0 0 1 2
                              0 1 1 2
                              0 1 2 2
            
            001
            0011
            
            000111
            0001111
            
            0001
            0000001
            001
            01
            
            
            cnt0 = (cnt0*2) + 1
            
            cnt1 = (cnt1*2) + cnt0
            
            cnt2 = (cnt2*2) + cnt1
            
           */
        
        
        ll n=nums.size();
        
        ll cnt0=0LL,cnt1=0LL,cnt2=0LL;
        
        for(ll i=0;i<n;++i){
            
            if(nums[i]==0){
                
                cnt0=add(mul(2LL,cnt0),1LL);
                
            }
            
            else if(nums[i]==1){
                
                cnt1=add(mul(2LL,cnt1),cnt0);
                
            }
            
            else{
                
                cnt2=add(mul(2LL,cnt2),cnt1);
                
            }
            
        }
        
        return mod(cnt2);
                              
    }
};