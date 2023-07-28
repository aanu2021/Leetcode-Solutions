class Solution {
public:
    
    typedef long long ll;
    const ll M = 1e9 + 7;
    
    int dp[243][1002];
    
    bool isMaskValid(int mask,int m){
        int prev = -1;
        int mul = 1;
        for(int i=0;i<m;i++){
            int curr = ((mask/mul)%3);
            mul *= 3;
            if(curr == prev) return false;
            prev = curr;
        }
        return true;
    }
    
    vector<int>maskArr(int mask,int m){
        int mul = 1;
        vector<int>v;
        for(int i=0;i<m;i++){
            int curr = ((mask/mul)%3);
            mul *= 3;
            v.push_back(curr);
        }
        return v;
    }
    
    void generateMask(int mask,int currMask,int row,int m,vector<int>&nextMasks){
        if(row == m){
            nextMasks.push_back(currMask);
            return;
        }
        int mul = pow(3,row);
        int prev = ((mask/mul)%3);
        if(prev == 0){
            generateMask(mask,(currMask + 1*pow(3,row)),row+1,m,nextMasks);
            generateMask(mask,(currMask + 2*pow(3,row)),row+1,m,nextMasks);            
        }
        else if(prev == 1){
            generateMask(mask,(currMask + 0*pow(3,row)),row+1,m,nextMasks);
            generateMask(mask,(currMask + 2*pow(3,row)),row+1,m,nextMasks);
        }
        else{
            generateMask(mask,(currMask + 0*pow(3,row)),row+1,m,nextMasks);
            generateMask(mask,(currMask + 1*pow(3,row)),row+1,m,nextMasks);
        }
    }
    
    int func(int mask,int m,int col,int n){
        if(col == n-1){
            return 1;
        }
        if(dp[mask][col] != -1){
            return dp[mask][col];
        }
        vector<int>nextMasks;
        generateMask(mask,0,0,m,nextMasks);
        ll ways = 0LL;
        for(int &nmask : nextMasks){
            if(isMaskValid(nmask,m)){
                ways += (ll)func(nmask,m,col+1,n);
                ways %= M;
            }
        }
        return dp[mask][col] = (int)ways;
    }
    
    int colorTheGrid(int m, int n) {
        int MASK = pow(3,m) - 1;
        ll ways = 0LL;
        memset(dp,-1,sizeof(dp));
        for(int mask=0;mask<=MASK;mask++){
            if(isMaskValid(mask,m)){
                // cout<<mask<<"\n";
                ways += (ll)func(mask,m,0,n);
                ways %= M;
            }
        }
        return (int)ways;
    }
};

   