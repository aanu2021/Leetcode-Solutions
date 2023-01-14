class Solution {
public:
    
   /* int dp[602][101][101];
    
    int func(vector<int>&countOne,vector<int>&countZero,int i,int n,int M,int N){
        if(i == n) return 0;
        if(dp[i][M][N] != -1) return dp[i][M][N];
        int ans = func(countOne,countZero,i+1,n,M,N);
        if(M >= countZero[i] && N >= countOne[i]){
            ans = max(ans,1 + func(countOne,countZero,i+1,n,M-countZero[i],N-countOne[i]));
        }
        return dp[i][M][N] = ans;
    } */
    
    int findMaxForm(vector<string>& strs, int M, int N) {
        int n = strs.size();
        vector<int>countOne(n+1,0);
        vector<int>countZero(n+1,0);
        for(int i=0;i<n;i++){
            int zeroCnt = 0, oneCnt = 0;
            for(char ch:strs[i]){
                if(ch == '0') zeroCnt++;
                else          oneCnt++;
            }
            countOne[i+1]  = oneCnt;
            countZero[i+1] = zeroCnt;
        }
        int dp[n+1][M+1][N+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            int cntZero = countZero[i];
            int cntOne  = countOne[i];
            for(int zero = 0;zero <= M;zero++){
                for(int one = 0;one <= N;one++){
                    dp[i][zero][one] = dp[i-1][zero][one];
                    if(zero >= cntZero && one >= cntOne){
                        dp[i][zero][one] = max(dp[i][zero][one],1 + dp[i-1][zero-cntZero][one-cntOne]);
                    }
                }
            }
        }
        return dp[n][M][N];
    }
};