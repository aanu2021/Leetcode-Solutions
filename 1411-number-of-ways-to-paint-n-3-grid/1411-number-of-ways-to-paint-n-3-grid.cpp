class Solution {
public:
    
    typedef long long ll;
    const ll M = 1e9 + 7;
    
    int dp[30][5002];
    
    bool isMaskValid(int mask){
        int prev = -1;
        int mul = 1;
        for(int i=0;i<3;i++){
            int curr = ((mask/mul)%3);
            mul *= 3;
            if(curr == prev) return false;
            prev = curr;
        }
        return true;
    }
    
    void generateMask(int mask,int col,int currMask,int n,vector<int>&nextMasks){
        if(col == n){
            nextMasks.push_back(currMask);
            return;
        }
        int mul = pow(3,col);
        int bit = ((mask/mul)%3);
        if(bit == 0){
            generateMask(mask,col+1,currMask + 1*mul,n,nextMasks);
            generateMask(mask,col+1,currMask + 2*mul,n,nextMasks);
        }
        else if(bit == 1){
            generateMask(mask,col+1,currMask + 0*mul,n,nextMasks);
            generateMask(mask,col+1,currMask + 2*mul,n,nextMasks);
        }
        else{
            generateMask(mask,col+1,currMask + 0*mul,n,nextMasks);
            generateMask(mask,col+1,currMask + 1*mul,n,nextMasks);
        }
    }
    
    int func(int mask,int row,int n){
        if(row==n-1) return 1;
        if(dp[mask][row] != -1) return dp[mask][row];
        ll ways = 0LL;
        vector<int>nextMasks;
        generateMask(mask,0,0,3,nextMasks);
        for(int &nmask : nextMasks){
            if(isMaskValid(nmask)){
                ways += (ll)func(nmask,row + 1,n);
                ways %= M;
            }
        }
        return dp[mask][row] = (int)ways;
    }
    
    int numOfWays(int n) {
        int MASK = 27;
        ll ways = 0LL;
        memset(dp,-1,sizeof(dp));
        for(int mask=0;mask<MASK;mask++){
            if(isMaskValid(mask)){
                ways += (ll)func(mask,0,n);
                ways %= M;
            }
        }
        return (int)ways;
    }
};