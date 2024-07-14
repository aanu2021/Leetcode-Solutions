class Solution {
public:
    
    int dp[22][22][22][22];
    
    int func(vector<int>&h, vector<int>&v, int r1, int r2, int c1, int c2){
        if(r1 == (r2-1) && c1 == (c2-1)) return 0;
        if(dp[r1][r2][c1][c2] != -1) return dp[r1][r2][c1][c2];
        int minCost = 1000000000;
        for(int cut=r1+1;cut<r2;cut++){
            int currCost = h[cut-1] + func(h, v, r1, cut, c1, c2) + func(h, v, cut, r2, c1, c2);
            minCost = min(minCost, currCost);
        }
        for(int cut=c1+1;cut<c2;cut++){
            int currCost = v[cut-1] + func(h, v, r1, r2, c1, cut) + func(h, v, r1, r2, cut, c2);
            minCost = min(minCost, currCost);
        }
        return dp[r1][r2][c1][c2] = minCost;
    }
    
    int minimumCost(int m, int n, vector<int>& h, vector<int>& v) {
        memset(dp, -1, sizeof(dp));
        int ans = func(h, v, 0, m, 0, n);
        return ans;
    }
};

