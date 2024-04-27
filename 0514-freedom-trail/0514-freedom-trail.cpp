class Solution {
public:
    
    vector<vector<int>>dp;
    
    int func(string &s, string &p, int i, int j, vector<vector<int>>&prevIndex, vector<vector<int>>&nextIndex, int n, int m){
        if(j == m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int reqIndex = (int)(p[j] - 'a');
        int op1 = (i - prevIndex[i][reqIndex] + n)%n;
        op1 += func(s, p, prevIndex[i][reqIndex], j+1, prevIndex, nextIndex, n, m);
        int op2 = (nextIndex[i][reqIndex] - i + n)%n;
        op2 += func(s, p, nextIndex[i][reqIndex], j+1, prevIndex, nextIndex, n, m);
        // cout<<i<<" "<<j<<" "<<op1<<" "<<op2<<"\n";
        return dp[i][j] = 1 + min(op1, op2);
    }
    
    int findRotateSteps(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>>prevIndex(n, vector<int>(26, -1));
        vector<vector<int>>nextIndex(n, vector<int>(26, -1));
        vector<int>indexMap(26, -1);
        for(int i=0;i<2*n;i++){
            int index = (i%n);
            indexMap[s[index]-'a'] = index;
            for(int j=0;j<26;j++){
                if(indexMap[j] == -1) continue;
                prevIndex[index][j] = indexMap[j];
            }
        }
        for(int i=0;i<26;i++){
            indexMap[i] = -1;
        }
        for(int i=2*n-1;i>=0;i--){
            int index = (i%n);
            indexMap[s[index]-'a'] = index;
            for(int j=0;j<26;j++){
                if(indexMap[j] == -1) continue;
                nextIndex[index][j] = indexMap[j];
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<10;j++){
        //         cout<<nextIndex[i][j]<<" ";
        //     }cout<<"\n";
        // }
        dp.clear();
        dp = vector<vector<int>>(n, vector<int>(m, -1));
        int ans = func(s, p, 0, 0, prevIndex, nextIndex, n, m);
        return ans;
    }
};