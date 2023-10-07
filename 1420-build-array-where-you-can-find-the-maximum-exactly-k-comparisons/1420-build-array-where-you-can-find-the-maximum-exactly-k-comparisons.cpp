class Solution {
public:
    
    typedef long long ll;
    const ll M = 1e9 + 7;
    
    int dp[52][102][52];
    
    int func(int index,int pMax,int k,int n,int m){
        if(k < 0) return 0;
        if(index == n){
            return k==0;
        }
        if(dp[index][pMax][k] != -1) return dp[index][pMax][k];
        ll ways = 0LL;
        for(int num=1;num<=m;num++){
            ways += (ll)func(index+1,max(pMax,num),k-(num > pMax ? 1 : 0),n,m);
            ways %= M;
        }
        return dp[index][pMax][k] = (int)ways;
    }
    
    int numOfArrays(int n, int m, int k) {
        memset(dp,-1,sizeof(dp));
        int ans = func(0,0,k,n,m);
        return ans;
    }
};