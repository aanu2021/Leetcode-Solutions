class Solution {
public:
    
    set<string>st;
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        for(string str:wordDict){
            st.insert(str);
        }
        
        st.insert("");
        
        int n=s.length();
        
        vector<bool>dp(n+1,false);
        
        for(int i=0;i<n;i++){
            
            if(st.find(s.substr(0,i+1))!=st.end()){
                dp[i]=true;
                continue;
            }
            
            for(int j=0;j<=i;j++){
                
                string right=s.substr(j+1,i-j);
                
                
                if(dp[j]==true && st.find(right)!=st.end()){
                    dp[i]=true;
                    break;
                }
                
            }
            
        }
        
        return dp[n-1];
        
    }
};