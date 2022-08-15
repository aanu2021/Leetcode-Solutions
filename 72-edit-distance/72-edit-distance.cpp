class Solution {
public:
    
    int dp[502][502];
    
    int func(string &s1,string &s2,int i,int j){
        
        if(i<0 && j<0){
            return 0;
        }
        
        if(i<0 && j>=0){
            return j+1;
        }
        
        if(i>=0 && j<0){
            return i+1;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int num_ops=0;
        
        if(s1[i]==s2[j]){
            
            num_ops=func(s1,s2,i-1,j-1);
            
        }
        
        else{
            
            int insert=func(s1,s2,i,j-1);
            int deletion=func(s1,s2,i-1,j);
            int replace=func(s1,s2,i-1,j-1);
            
            num_ops=1+min({insert,deletion,replace});
            
        }
        
        return dp[i][j]=num_ops;
        
    }
    
    int minDistance(string s1, string s2) {
        
        int m=s1.length();
        int n=s2.length();
        
        /*
        
        Case 1: s1[i]!=s2[j] 
            
                func(i,j) = 1 + min(func(i+1,j),func(i,j+1),func(i+1,j+1));
            
        Case 2: s1[i]==s2[j] 
            
                func(i,j) = func(i+1,j+1)
                
                */
        
        
        memset(dp,-1,sizeof(dp));
        
        int ans=func(s1,s2,m-1,n-1);
        
        return ans;
        
    }
};