class Solution {
public:
    
    typedef long long ll;
    
    const ll M = 1e9 + 7;
    
    int countPalindromicSubsequences(string s) {
        
        int n=s.length();
        
        vector<int>next(n,n);
        vector<int>prev(n,-1);
        
        unordered_map<char,int>index;
        
        for(int i=0;i<n;++i){
            
            if(index.find(s[i])!=index.end()){
                
                prev[i]=index[s[i]];
                
            }
            
            index[s[i]]=i;
            
        }
        
        index.clear();
        
        for(int i=n-1;i>=0;--i){
            
            if(index.find(s[i])!=index.end()){
                
                next[i]=index[s[i]];
                
            }
            
            index[s[i]]=i;
            
        }
        
        vector<vector<ll>>dp(n,vector<ll>(n,0LL));
        
        for(int i=0;i<n;++i){
            dp[i][i]=1LL;
        }
        
        for(int i=0;i<n-1;++i){
            dp[i][i+1]=2LL;
        }
        
        for(int L=3;L<=n;L++){
            
            for(int i=0;i<n-L+1;i++){
                
                int j = i+L-1;
                
                // There is no match b/w extreme characters //
                
                if(s[i]!=s[j]){
                    
                    dp[i][j] += dp[i+1][j];
                    dp[i][j] += dp[i][j-1];
                    dp[i][j] %= M;
                    dp[i][j] -= dp[i+1][j-1];
                    dp[i][j] += M;
                    dp[i][j] %= M;
                    
                }
                
                // First and Last Characters are matched //
                
                else{
                    
                    int n=next[i];
                    int p=prev[j];
                    
                    // No extreme character at the middle //
                    
                    if(n > p){
                        
                        dp[i][j] += (2LL*dp[i+1][j-1]);
                        dp[i][j] += 2LL;
                        dp[i][j] %= M;
                        
                    }
                    
                    // One occurenece of extreme character //
                    
                    else if(n==p){
                        
                        dp[i][j] += (2LL*dp[i+1][j-1]);
                        dp[i][j] += 1LL;
                        dp[i][j] %= M;
                        
                    }
                    
                    // Multiple occurences are possible //
                    
                    else{
                        
                        dp[i][j] += (2LL*dp[i+1][j-1]);
                        dp[i][j] -= dp[n+1][p-1];
                        dp[i][j] += M;
                        dp[i][j] %= M;
                        
                    }
                    
                }
                
            }
            
        }
        
        return dp[0][n-1]%M;
        
    }
};