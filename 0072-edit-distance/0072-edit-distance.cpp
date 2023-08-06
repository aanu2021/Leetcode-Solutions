class Solution {
public:
    
    vector<vector<int>>dp;
    
    int func(string &s1,string &s2,int i,int j,int m,int n){
        if(i==m){
            return (n-j);
        }
        if(j==n){
            return (m-i);
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j] = func(s1,s2,i+1,j+1,m,n);
        }
        else{
            int ins = func(s1,s2,i,j+1,m,n);
            int del = func(s1,s2,i+1,j,m,n);
            int rep = func(s1,s2,i+1,j+1,m,n);
            return dp[i][j] = 1 + min({ins,del,rep});
        }
    }
    
    int minDistance(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        dp.clear();
        dp = vector<vector<int>>(m+1,vector<int>(n+1,-1));
        int ans = func(s1,s2,0,0,m,n);
        return ans;
    }
};