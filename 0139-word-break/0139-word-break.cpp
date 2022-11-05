class Solution {
public:
    
    unordered_set<string>S;
    
    int dp[302];
    
    int func(string &s,int i,int n){
        
        if(i==n){
            return 1;
        }
        
        if(dp[i]!=-1){
            return dp[i];
        }
        
        int ans = 0;
        
        string str = "";
        
        for(int j=i;j<n;j++){
            
            str+=s[j];
            
            if(S.find(str)!=S.end() && func(s,j+1,n)==1){
                
                return dp[i] = 1;
                
            }
            
        }
        
        return dp[i] = 0;
        
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        for(string str:wordDict){
            S.insert(str);
        }
        
        int n = s.length();
        
        memset(dp,-1,sizeof(dp));
        
        int ans = func(s,0,n);
        
        if(ans==1){
            return true;
        }else{
            return false;
        }
        
    }
};