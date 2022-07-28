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
    
    ll func(ll s,ll e){
        
        return ((e*(e+1))/2) - ((s*(s-1))/2);
        
    }
    
    bool isPossible(vector<int>&nums,ll mid,ll k){
        
        ll cnt=0LL;
        
        for(ll i=0;i<nums.size();++i){
            
            cnt+=max(0LL,nums[i]-mid+1LL);
            
        }
        
        return cnt>=k;
        
    }
    
    int maxProfit(vector<int>&nums, int k) {
        
        ll n=nums.size();
        
        ll low=0;
        
        ll high=accumulate(nums.begin(),nums.end(),0LL);
        
        ll ans=-1LL;
        
        while(low<=high){
            
            ll mid=(low+high)/2;
            
            if(isPossible(nums,mid,(ll)k)==true){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
            
        }
        
        sort(nums.rbegin(),nums.rend());
        
        ll req=(ans+1);
        
        ll total=0LL;
        
        for(ll i=0;i<n;++i){
            
            if((ll)nums[i]>=req && k>0){
                
                k-=(nums[i]-req+1);
                
                ll curr=func(req,(ll)nums[i]);
                
                total=add(total,curr);
                
            }
            
        }
        
        ll curr=mul(k,ans);
        
        total=add(total,curr);
        
        return total;
        
    }
};