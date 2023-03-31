class Solution {
public:
    
    typedef long long ll;
    const ll M = 1e9 + 7;
    
    ll dp[52][52][12];
    int pre[52][52];
    
    int numberOfApples(int r1,int c1,int r2,int c2){
        r1++; c1++; r2++; c2++;
        return (pre[r2][c2] - pre[r2][c1-1] - pre[r1-1][c2] + pre[r1-1][c1-1]);
    }
    
    ll func(int r1,int c1,int r2,int c2,int k){
        
        if(k==1) return 1LL;
        if(dp[r1][c1][k] != -1LL) return dp[r1][c1][k];
       
        ll ways = 0LL;
        
        for(int row=r1;row<r2;row++){
            int apple1 = numberOfApples(r1,c1,row,c2);
            int apple2 = numberOfApples(row+1,c1,r2,c2);
            if(apple1 && apple2){
                ways += func(row+1,c1,r2,c2,k-1);
                ways %= M;
            }
        }
        
        for(int col=c1;col<c2;col++){
            int apple1 = numberOfApples(r1,c1,r2,col);
            int apple2 = numberOfApples(r1,col+1,r2,c2);
            if(apple1 && apple2){
                ways += func(r1,col+1,r2,c2,k-1);
                ways %= M;
            }
        }
        
        return dp[r1][c1][k] = ways;
    }
    
    int ways(vector<string>& pizza, int k) {
        
        int m = pizza.size();
        int n = pizza[0].length();
        
        memset(dp,-1LL,sizeof(dp));
        memset(pre,0,sizeof(pre));
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                pre[i][j] = (pizza[i-1][j-1]=='A') + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
            }
        }
        
        ll ans = func(0,0,m-1,n-1,k);
        return ans;
        
    }
};