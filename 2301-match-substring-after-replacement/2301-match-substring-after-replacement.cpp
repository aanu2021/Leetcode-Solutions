class Solution {
public:
    bool matchReplacement(string s, string t, vector<vector<char>>& mappings) {
        
        int n=s.length();
        int m=t.length();
        
        vector<vector<bool>>dp(300,vector<bool>(300,false));
        
        for(int i=0;i<mappings.size();i++){
            int x=(int)mappings[i][0];
            int y=(int)mappings[i][1];
            dp[x][y]=true;
        }
        
        bool flag=false;
        
        for(int i=0;i<=n-m;i++){
            
            flag=true;
            
            for(int j=0;j<m;j++){
                
                if(t[j]==s[i+j]){
                    continue;
                }
                
                int x=(int)t[j];
                int y=(int)s[i+j];
                
                if(dp[x][y]==true){
                   continue;
                }else{
                    flag=false;
                    break;
                }
                
            }
            
            if(flag==true){
                break;
            }
            
        }
        
        return flag;
        
    }
};