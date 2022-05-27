class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
        int dp[n];
        
        memset(dp,0,sizeof(dp));
        
        dp[0]=1;
        
        int m=primes.size();
        
        int pointer[m];
        
        memset(pointer,0,sizeof(pointer));
        
        for(int i=1;i<n;i++){
            
            int minn=INT_MAX;
            
            for(int j=0;j<m;j++){
                
                int curr=primes[j]*dp[pointer[j]];
                
                minn=min(minn,curr);
                
            }
            
            dp[i]=minn;
            
            for(int j=0;j<m;j++){
                
                if((primes[j]*dp[pointer[j]])==minn){
                    pointer[j]++;
                }
                
            }
            
        }
        
        return dp[n-1];
        
    }
};