/*

Time Complexity  : O(N*N)
Space Complexity : O(wordDict Length)

*/

class Solution {
public:
    
    unordered_set<string>S;
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        for(string str:wordDict){
            S.insert(str);
        }
        
        int n = s.length();
        
        vector<bool>dp(n+1,false);
        
        dp[n] = true;
        
        for(int i=n-1;i>=0;i--){
            
            string str = "";
            
            for(int j=i;j<n;j++){
                
                str+=s[j];
                
                if(S.find(str)!=S.end() && dp[j+1]){
                    
                    dp[i] = true;
                    break;
                    
                }
                
            }
            
        }
        
        return dp[0];
        
    }
};