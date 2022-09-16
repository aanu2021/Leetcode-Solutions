class Solution {
public:
    
    int func(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){
        
        if(i<0){
            
            return j+1;
            
        }
        
        if(j<0){
            
            return i+1;
            
        }
        
        if(dp[i][j]!=-1){
            
            return dp[i][j];
            
        }
        
        if(s1[i]==s2[j]){
            
            return dp[i][j]=func(s1,s2,i-1,j-1,dp);
            
        }
        
        else{
            
            int insert_ops=func(s1,s2,i-1,j,dp);
            int delete_ops=func(s1,s2,i,j-1,dp);
            int replace_ops=func(s1,s2,i-1,j-1,dp);
            
            return dp[i][j]=1+min({insert_ops,delete_ops,replace_ops});
            
        }
        
    }
    
    int minDistance(string s1, string s2) {
        
        int m=s1.length();
        int n=s2.length();
        
        vector<vector<int>>dp(m,vector<int>(n,-1));
        
        int ans=func(s1,s2,m-1,n-1,dp);
        
        return ans;
        
    }
};