class Solution {
public:
    
    set<string>st;
    
    map<string,int>dp;
    
    int func(string s){
        
        if(s.length()==0){
            return 1;
        }
        
        if(dp[s]!=0){
            return dp[s];
        }
        
        dp[s]=-1;
        
        string str="";
        
        for(int i=0;i<s.length();i++){
            
            str+=s[i];
            
            if(st.find(str)!=st.end() && func(s.substr(i+1))==1){
                return dp[s]=1;
            }
            
        }
        
        return dp[s]=-1;
        
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        for(string str:wordDict){
            st.insert(str);
        }
        
        int n=s.length();
        
        int ans=func(s);
        
        return ans==1 ? true : false;
        
    }
};