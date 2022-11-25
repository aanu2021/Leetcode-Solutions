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
    
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>left(n,-1);
        vector<int>right(n,n);
        stack<int>S;
        for(int i=0;i<n;i++){
            while(!S.empty() && arr[S.top()]>=arr[i]){
                S.pop();
            }
            if(!S.empty()){
                left[i] = S.top();
            }
            S.push(i);
        }
        while(!S.empty()){
            S.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!S.empty() && arr[S.top()]>arr[i]){
                S.pop();
            }
            if(!S.empty()){
                right[i] = S.top();
            }
            S.push(i);
        }
        ll ans = 0LL;
        for(int i=0;i<n;i++){
            ll l=(ll)(i-left[i]);
            ll r=(ll)(right[i]-i);
            ll muli = mul(l,r);
            ll curr = mul(muli,(ll)arr[i]);
            ans = add(ans,curr);
        }
        return ans;
    }
};