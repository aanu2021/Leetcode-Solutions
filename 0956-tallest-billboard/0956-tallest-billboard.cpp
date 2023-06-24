class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        
        int n = rods.size();
        int MAX = 10001;
        
        vector<vector<bool>>dp(n+1,vector<bool>(MAX,false));
        vector<vector<int>>mx(n+1,vector<int>(MAX,0));
        
        dp[0][5000] = true;
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<MAX;j++){
                
                // DROP inside BOX-1
                
                if(j-rods[i] >= 0 && dp[i][j-rods[i]]){
                    dp[i+1][j] = true;
                    mx[i+1][j] = max(mx[i+1][j], mx[i][j-rods[i]] + rods[i]);
                }
                
                // DROP inside BOX-2
                
                if(j+rods[i] < MAX && dp[i][j+rods[i]]){
                    dp[i+1][j] = true;
                    mx[i+1][j] = max(mx[i+1][j],mx[i][j+rods[i]]);
                }
                
                // Leave it
                
                if(dp[i][j]){
                    dp[i+1][j] = true;
                    mx[i+1][j] = max(mx[i+1][j],mx[i][j]);
                }
                
            }
            
        }
        
        return mx[n][5000];
        
    }
};

/*

we have three options to choose from :-
    
    a. Pick the rod and drop it inside BOX-1.
    b. Pick the rod and drop it inside BOX-2.
    c. Skip it for both the boxes.
        
We can denote their contribution as : 
   
    a. +1
    b. -1
    c.  0
        
and why so?
        
Let's take an example 
        
        [1,2,3,4,5,6]
         0 1 2 3 4 5
        
        We skip the 0-th element 
        We drop 1-st,2-nd,4-h elements inside BOX-1
        We drop 3-rd,5-th elements inside BOX-2
        
        Total contribution : (1*0) + (2*1) + (3*1) + (4*(-1)) + (5*1) + (6*(-1))
            
        = 0
            
        That is what we are looking for, heights of both the wheels must be same
        
        H1 = H2
        H1 - H2 = 0
        H1 + (-1)*H2 = 0
            
        Now the problem boils down to - is it possible to keep track of their contributions optimally, indeed possible. When DP is there, no fear :)))    
        
*/        