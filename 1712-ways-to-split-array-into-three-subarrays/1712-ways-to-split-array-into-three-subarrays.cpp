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
    
    int waysToSplit(vector<int>& nums) {
        
        ll n=nums.size();
        
        vector<ll>prefix(n+1,0LL);
        
        prefix[0]=(ll)nums[0];
        
        for(ll i=1;i<n;i++){
            prefix[i]=prefix[i-1]+(ll)nums[i];
        }
        
        ll ans=0LL;
        
        for(ll i=0;i<n-2;++i){
            
            ll leftsum=prefix[i];
            
            ll idx=lower_bound(prefix.begin()+i+1,prefix.end(),leftsum+prefix[i])-prefix.begin();
            
            if(idx>=n-1){
                continue;
            }
            
            ll low=idx,high=n-2;
            
            ll index=-1;
            
            while(low<=high){
                
                ll mid=(low+high)/2;
                
                ll middlesum=prefix[mid]-leftsum;
                
                ll rightsum=prefix[n-1]-prefix[mid];
                
                if(middlesum>=leftsum && rightsum>=middlesum){
                    
                    index=mid;
                    low=mid+1;
                    
                }else{
                    
                    high=mid-1;
                    
                }
                
            }
            
            ll curr=(index-idx+1);
            
            if(curr>0){
                
              //  cout<<i<<" "<<index<<endl;
                
                ans=add(ans,curr);   
                
            }
            
        }
        
        return ans;
        
    }
};