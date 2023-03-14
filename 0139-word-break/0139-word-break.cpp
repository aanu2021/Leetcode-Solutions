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
    
    int func2(string &s){
        int n = s.length();
        vector<bool>dp(n+1,false);
        dp[n] = true;
        
        for(int i=n-1;i>=0;i--){
            string word = "";
            for(int j=i;j<n;j++){
                word += s[j];
                if(dict.find(word) != dict.end() && dp[j+1]){
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[0];
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        for(string &str : wordDict){
            dict.insert(str);
        }
        // vector<int>dp(n,-1);
        // int ans = func(s,0,n,dp);
        // if(ans > 0) return true;
        // else return false;
        return func2(s);
    }
};