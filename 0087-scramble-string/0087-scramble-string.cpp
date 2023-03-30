class Solution {
public:
    
    /*
    
    int dp[31][31][31];
    
    int func(string &s1,string &s2,int l1,int r1,int l2,int r2){
        
        int len = (r1-l1+1);
        if(dp[l1][r1][l2] != -1) return dp[l1][r1][l2];
        if(l1==r1) return dp[l1][r1][l2] = (s1[l1] == s2[l2]);
        if(s1.substr(l1,len) == s2.substr(l2,len)) return dp[l1][r1][l2] = 1;
        
        for(int k=l1;k<r1;k++){
            int len1 = k-l1+1;
            int len2 = len-len1;
            if(func(s1,s2,l1,l1+len1-1,l2,l2+len1-1) && func(s1,s2,r1-len2+1,r1,r2-len2+1,r2)) return dp[l1][r1][l2] = 1;
            if(func(s1,s2,l1,l1+len1-1,r2-len1+1,r2) && func(s1,s2,r1-len2+1,r1,l2,l2+len2-1)) return dp[l1][r1][l2] = 1;
        }
        
        return dp[l1][r1][l2] = 0;
        
    }
    
    */
    
    bool isScramble(string s1, string s2) {
        int n = s1.length();
        bool dp[n][n][n+1];
        memset(dp,false,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j][1] = (s1[i]==s2[j]);
            }
        }
        for(int len=2;len<=n;len++){
            for(int i=0;i<n-len+1;i++){
                for(int j=0;j<n-len+1;j++){
                    if(s1.substr(i,len) == s2.substr(j,len)){
                        dp[i][j][len] = true;
                    }
                    else{
                        for(int k=1;k<len && !dp[i][j][len];k++){
                            dp[i][j][len] = (dp[i][j][k] && dp[i+k][j+k][len-k]) || (dp[i][j+len-k][k] && dp[i+k][j][len-k]);
                        }
                    }
                }
            }
        }
        return dp[0][0][n];
    }
};