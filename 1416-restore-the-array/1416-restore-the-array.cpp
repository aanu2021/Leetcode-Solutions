class Solution {
public:
    
    typedef long long ll;
    const ll M = 1e9 + 7;
    
    ll dp[100005];
    
    ll func(string &s,int i,int n,int k){
        
        if(i==n) return 1;
        if(dp[i] != -1) return dp[i];
        
        ll ways = 0LL;
        if(s[i]=='0') return dp[i] = 0LL;
        ll num = 0LL;
        
        for(int j=i;j<n;j++){
            num = (num*10) + (ll)(s[j]-'0');
            if(num <= k){
                ways += func(s,j+1,n,k);
                ways %= M;
            }
            else{
                break;
            }
        }
        return dp[i] = ways;
    }
    
    int numberOfArrays(string s, int k) {
        int n = s.length();
        memset(dp,-1,sizeof(dp));
        ll ans = func(s,0,n,k);
        return ans;
    }
};