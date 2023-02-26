class Solution {
public:
    
    int func(string &s1,string &s2,int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i == m && j == n) return 0;
        if(i == m) return (n-j);
        if(j == n) return (m-i);
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(s1[i] == s2[j]){
            return dp[i][j] = func(s1,s2,i+1,j+1,m,n,dp);
        }
        else{
            int insOps = func(s1,s2,i,j+1,m,n,dp);
            int delOps = func(s1,s2,i+1,j,m,n,dp);
            int repOps = func(s1,s2,i+1,j+1,m,n,dp);
            return dp[i][j] = 1 + min({insOps,delOps,repOps});
        }
    }
    
    int minDistance2(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans = func(s1,s2,0,0,m,n,dp);
        return ans;
    }
    
    int minDistance(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        s1 = "#" + s1;
        s2 = "#" + s2;
        vector<int>prev(n+1,0);
        for(int i=1;i<=n;i++) prev[i] = i;
        for(int i=1;i<=m;i++){
            vector<int>curr(n+1,0);
            curr[0] = i;
            for(int j=1;j<=n;j++){
                if(s1[i] == s2[j]){
                    curr[j] = prev[j-1];
                }
                else{
                    curr[j] = 1 + min({curr[j-1],prev[j-1],prev[j]});
                }
            }
            for(int j=0;j<=n;j++){
                prev[j] = curr[j];
            }
        }
        return prev[n];
    }
    
};