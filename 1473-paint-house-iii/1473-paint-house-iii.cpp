class Solution {
public:
    
    int dp[105][23][105];
    
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
        
       // cout<<"as,jdhamsd\n";
        
        if(i>=m){
            
            if(target==0){
               // cout<<"I am in\n";
                return 0;
            }else{
                return 1e9;
            }
            
        }
        
       // cout<<"as,jdhamsd\n"; 
        
        if(dp[i][prev][target]!=-1){
            
            // cout<<dp[i][prev][target]<<"\n";
            
            return dp[i][prev][target];
            
        }
        
       // cout<<"as,jdhamsd\n";
        
        int ans=1e9;
        
        if(nums[i]!=0){ // house is already painted.
            
           // cout<<prev<<" "<<nums[i]<<endl;
            
            if(nums[i]!=prev && target>0){
                
                ans=min(ans,func(nums,cost,i+1,nums[i],target-1,m,n));
                
            }
            
             if(nums[i]==prev){
                
                    ans=min(ans,func(nums,cost,i+1,nums[i],target,m,n));
                
            }
            
        }
        
        
        else{  // we have to paint the house.
            
            for(int j=0;j<n;j++){
                
                if((j+1)!=prev && target>0){
                    
              //  cout<<i<<" "<<j+1<<" "<<"New neighbourhood\n"; 
                    
                ans=min(ans,cost[i][j] + func(nums,cost,i+1,j+1,target-1,m,n));
                    
                  //  cout<<ans<<"\n";
                
                    
                }
                
                 if((j+1)==prev){
                    
                  // cout<<i<<" "<<j+1<<" "<<"Old neighbourhood\n"; 
                    
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
        
        // dp[i][j][k] --> i-th index , j-th color , k number of neighborhoods.
        
        int ans=func(nums,cost,0,n+1,target,m,n);
        
//         for(int i=0;i<m;i++){
//             for(int j=0;j<=n;j++){
//                 for(int k=0;k<m;k++){
//                     cout<<dp[i][j][k]<<" ";
//                 }
//             }
//         }
        
        // cout<<ans<<"\n";
        
        if(ans>=1e9){
            return -1;
        }else{
            return ans;
        }
 
        
    }
};