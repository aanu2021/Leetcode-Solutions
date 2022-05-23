class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        int len=strs.size();
        
        vector<vector<int>>dp(m+5,vector<int>(n+5,0));
        
        for(string str:strs){
            
            int cnt0=0,cnt1=0;
            
            for(char ch:str){
                if(ch=='0'){
                    cnt0++;
                }else{
                    cnt1++;
                }
            }
            
            
            for(int i=m;i>=cnt0;i--){
                
                for(int j=n;j>=cnt1;j--){
                    
                    dp[i][j]=max(dp[i][j],dp[i-cnt0][j-cnt1]+1);
                    
                }
                
            }
            
        }
        
        return dp[m][n];
        
    }
};