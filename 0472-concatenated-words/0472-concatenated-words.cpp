class Solution {
public:
    
    vector<string>ans;
    unordered_set<string>S;
    
    int func(string &str,int i,int n,vector<int>&dp){
        
        if(i==n) return 1;
        if(dp[i] != -1) return dp[i];
        
        int ans = 0;
        string curr = "";
        for(int j=i;j<n;j++){
            curr += str[j];
            if(S.find(curr) != S.end() && func(str,j+1,n,dp)){
                return dp[i] = 1;
            }
        }
        
        return dp[i] = 0;
        
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        int n = words.size();
        
        for(string &str : words){
            S.insert(str);
        }
        
        for(int i=0;i<n;i++){
            S.erase(words[i]);
            int len = words[i].length();
            vector<int>dp(len,-1);
            int value = func(words[i],0,len,dp);
            if(value == 1){
                ans.push_back(words[i]);
            }
            S.insert(words[i]);
        }
        
        return ans;
        
    }
};