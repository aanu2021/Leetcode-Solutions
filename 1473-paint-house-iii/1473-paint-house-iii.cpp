class Solution {
public:
    
    int dp[105][23][105];
    
    
    /*
    
    Try to analyze the variable quantities in these problem ,
    i.e --> index of the current house (let say i) , color of the
    house at (i-1)-th index , the given target neighborhoods till
    i-th index.*/
    
    /*
    
    
    Now Neighborhoods is a maximal groups of continuous house that
    are painted with the same color , that is why we have to keep
    track of the previous house's color , for example 
    
    [1,2,2,3,3,2,1,1] --> Now [1] --> nbrhd=1
                              [1,2] -->nbrhd=2      [1!=2]
                              [1,2,2] -->nbrhd=2    [2==2]
                              [1,2,2,3] -->nbrhd=3  [2!=3]
                              [1,2,2,3,3]-->nbrhd=3 [3==3]
                              [1,2,2,3,3,2]-->nbrhd=4[3!=2]
                              
                              and so on.......
    
    */
    
    
    /*
    
    Once we are able to figure out the variable states , we have to form a recurrence and in order to reduce the time compleixty for repeating subproblems , we should memoize it --> Top-Down DP.
    
    */
    
    // dp[i][j][k] --> i-th house , j=th prev color , k-th remaining target --> Minimum cost (optimally).
    
    
    /*
    
       Parameter of function call --> 1. House
                                      2. Cost Array
                                      3. i-th index
                                      4. j-th prev color
                                      5. k-th remaining target
                                      6. m
                                      7. n
    
    */
    
    
    int func(vector<int>&nums,vector<vector<int>>&cost,int i,int prev,int target,int m,int n){
        
        
        // Base Case ( if target is not achieved we shouldn't pick it in our final answer )
        
        if(i>=m){
            
            if(target==0){
                return 0;
            }else{
                return 1e9;
            }
            
        }
        
        
        // Memoization Part 
        
        if(dp[i][prev][target]!=-1){
            
            return dp[i][prev][target];
            
        }
        
    
        int ans=1e9;
        
        if(nums[i]!=0){ // house is already painted.
        
            
            if(nums[i]!=prev && target>0){
                
                ans=min(ans,func(nums,cost,i+1,nums[i],target-1,m,n));
                
            }
            
             if(nums[i]==prev){
                
                    ans=min(ans,func(nums,cost,i+1,nums[i],target,m,n));
                
            }
            
        }
        
        
        else{  // We have to paint the house with color from (j=1,2,3,.....,n)
            
            for(int j=0;j<n;j++){
                
                if((j+1)!=prev && target>0){
   
                    
                ans=min(ans,cost[i][j] + func(nums,cost,i+1,j+1,target-1,m,n));
        
                    
                }
                
                 if((j+1)==prev){
                
                    ans=min(ans,cost[i][j] + func(nums,cost,i+1,j+1,target,m,n));
                    
                }
                
            }
            
        }
        
        return dp[i][prev][target] = ans;
        
        
    }
    
    int minCost(vector<int>& nums, vector<vector<int>>& cost, int m, int n, int target) {
        
        for(int i=0;i<=m+1;++i){
            
            for(int j=0;j<=n+2;j++){
                
                for(int k=0;k<=m+1;k++){
                    
                    dp[i][j][k]=-1;
                    
                }
                
            }
            
        }
        

        
        int ans=func(nums,cost,0,n+1,target,m,n);
 
       
        if(ans>=1e9){
            return -1;
        }else{
            return ans;
        }
 
        
    }
};