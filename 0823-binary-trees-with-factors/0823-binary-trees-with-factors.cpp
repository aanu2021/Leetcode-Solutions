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
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        unordered_map<int,int>indexMap;
        vector<ll>dp(n,1LL);
        for(int i=0;i<n;i++){
            indexMap[arr[i]] = i;
        }
        for(int i=1;i<n;i++){
            int ele = arr[i];
            for(int j=0;j<i;j++){
                if(ele%arr[j]) continue;
                int req = (ele/arr[j]);
                if(indexMap.find(req) != indexMap.end()){
                    dp[i] += mul(dp[j], dp[indexMap[req]]);
                    dp[i] %= M;
                }
            }
        }
        ll total = 0LL;
        for(int i=0;i<n;i++){
            total += dp[i];
            total %= M;
        }
        return total;
    }
};