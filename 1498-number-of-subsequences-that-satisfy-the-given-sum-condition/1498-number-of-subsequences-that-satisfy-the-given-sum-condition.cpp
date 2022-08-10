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
    
    ll modPow(ll a,ll b){
        
        if(b==0){
            return 1LL;
        }
        
        if(b==1){
            return a;
        }
        
        ll res=1LL;
        
        while(b){
            
            if(b%2){
                res=mul(res,a);
            }
            
            b/=2;
            a=mul(a,a);
            
        }
        
        return res;
        
    }
    
    int numSubseq(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        
        ll n=nums.size();
        
        ll ans=0LL;
        
        vector<ll>pow2(n+1,0LL);
        
        pow2[0]=1LL;
        
        for(ll i=1;i<=n;++i){
            
            pow2[i]=mul(pow2[i-1],2LL);
            
        }
        
        for(ll i=0;i<n;++i){
            
            ll req=target-nums[i];
            
            if(req<nums[i]){
                break;
            }
            
            ll idx=upper_bound(nums.begin()+i,nums.end(),req)-nums.begin();
            
            idx--;
            
            ll range=(idx-i);
            
            if(range>=0){
                
                ll curr_add=pow2[range];
                
                ans=add(ans,curr_add);
                
            }
            
        }
        
        return ans;
        
    }
};