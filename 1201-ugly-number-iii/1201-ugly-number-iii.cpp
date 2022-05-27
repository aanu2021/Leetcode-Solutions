class Solution {
public:
    
    typedef long long ll;
    
    ll lcm(ll a,ll b){
        
        return ((a*b)/(__gcd(a,b)));
        
    }
    
    int nthUglyNumber(int nn, int aa, int bb, int cc) {
        
        ll n=nn;
        ll a=aa;
        ll b=bb;
        ll c=cc;
        
        ll ans=-1LL;
        
        ll low=1LL,high=1e18;
        
        while(low<=high){
            
            ll mid=(low+high)/2;
            
            ll o=(mid/a)+(mid/b)+(mid/c)-(mid/lcm(a,b))-(mid/lcm(b,c))-(mid/lcm(a,c))+(mid/lcm(a,lcm(b,c)));
            
            if(o>=n){
                ans=mid;
                high=mid-1;
            }
            
            else{
                low=mid+1;
            }
            
        }
        
        return ans;
        
    }
};