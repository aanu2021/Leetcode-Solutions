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
    
    int maxArea(int h, int w, vector<int>& hC, vector<int>& vC) {
        
        ll maxheight=0LL,maxwidth=0LL;
        
        hC.push_back(0);
        hC.push_back(h);
        
        vC.push_back(0);
        vC.push_back(w);
        
        sort(hC.begin(),hC.end());
        sort(vC.begin(),vC.end());
        
        for(ll i=1;i<hC.size();++i){
            maxheight=max(maxheight,(ll)hC[i]-hC[i-1]);
        }
        
        for(ll i=1;i<vC.size();++i){
            maxwidth=max(maxwidth,(ll)vC[i]-vC[i-1]);
        }
        
        return mul(maxheight,maxwidth);
        
    }
};