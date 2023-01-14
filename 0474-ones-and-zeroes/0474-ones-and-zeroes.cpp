class Solution {
public:
    
    int dp[602][101][101];
    
    int func(vector<int>&countOne,vector<int>&countZero,int i,int n,int M,int N){
        if(i == n) return 0;
        if(dp[i][M][N] != -1) return dp[i][M][N];
        int ans = func(countOne,countZero,i+1,n,M,N);
        if(M >= countZero[i] && N >= countOne[i]){
            ans = max(ans,1 + func(countOne,countZero,i+1,n,M-countZero[i],N-countOne[i]));
        }
        return dp[i][M][N] = ans;
    }
    
    int findMaxForm(vector<string>& strs, int M, int N) {
        int n = strs.size();
        vector<int>countOne(n,0);
        vector<int>countZero(n,0);
        for(int i=0;i<n;i++){
            int zeroCnt = 0, oneCnt = 0;
            for(char ch:strs[i]){
                if(ch == '0') zeroCnt++;
                else          oneCnt++;
            }
            countOne[i]  = oneCnt;
            countZero[i] = zeroCnt;
        }
        memset(dp,-1,sizeof(dp));
        int ans = func(countOne,countZero,0,n,M,N);
        return ans;
    }
};