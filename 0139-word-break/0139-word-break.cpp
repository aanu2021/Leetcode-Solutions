class Solution {
public:
    
    unordered_set<string>dict;
    
    int func(string &s,int i,int n,vector<int>&dp){
        if(i==n) return 1;
        if(dp[i] != -1) return dp[i];
        string word = "";
        int currValue = 0;
        for(int j=i;j<n;j++){
            word += s[j];
            if(dict.find(word) != dict.end() && func(s,j+1,n,dp)){
                currValue = 1;
                break;
            }
        }
        return dp[i] = currValue;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<int>dp(n,-1);
        for(string &str : wordDict){
            dict.insert(str);
        }
        int ans = func(s,0,n,dp);
        if(ans > 0) return true;
        else return false;
    }
};