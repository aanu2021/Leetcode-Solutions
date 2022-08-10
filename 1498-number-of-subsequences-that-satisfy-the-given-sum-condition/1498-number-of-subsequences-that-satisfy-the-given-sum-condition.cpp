class Solution {
public:
    
    /*
    
    Binary Search Approach
    
    Time Complexity  : O(N*logN)
    Space Complexity : O(N)
    
    */
    
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
    
   
    
    int numSubseq(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        
        ll n=nums.size();
        
        vector<ll>pow2(n+1,0LL);
        
        pow2[0]=1LL;
        
        for(ll i=1;i<=n;++i){
            
            pow2[i]=mul(2LL,pow2[i-1]);
            
        }
        
        
        ll l=0,r=n-1,ans=0LL;
        
        while(l<=r){
            
            ll currsum=nums[l]+nums[r];
            
            if(currsum>target){
                
                r--;
                
            }
            
            else{
                
                ll currval=pow2[r-l];
                
                ans=add(ans,currval);
                
                l++;
                
            }
            
        }
        
        return ans;
        
    }
};