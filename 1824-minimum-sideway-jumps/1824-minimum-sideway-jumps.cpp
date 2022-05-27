class Solution {
public:
    
    int dp[500005][4];
    
    int func(vector<int>&obstacles,int i,int lane){
        
        if(i==obstacles.size()-1){
            return 0;
        }
        
        if(obstacles[i]==lane){
            return 1e9;
        }
        
        if(dp[i][lane]!=-1){
            return dp[i][lane];
        }
        
        if(obstacles[i+1]==0 || obstacles[i+1]!=lane){
            return dp[i][lane]=func(obstacles,i+1,lane);
        }
        
        // If the next point is free from stones or there is a stone in any of the three paths except the current lane , then just proceed forward.......
        
     
        
        // Otherwise we have to change our direction from current point to avoid the obstacle lying at the next point of the current lane.........
        
            
            int ans=1e9;
            
            int curr;
            
            if(lane==1){
                
                curr=min(1+func(obstacles,i,2),1+func(obstacles,i,3));
                
            }
            
            else if(lane==2){
                                                            curr=min(1+func(obstacles,i,1),1+func(obstacles,i,3));
                 
            }
            
            else if(lane==3){
                
                curr=min(1+func(obstacles,i,1),1+func(obstacles,i,2));
                
            }
            
           return dp[i][lane]=min(ans,curr);
            
        
        
    }
    
    int minSideJumps(vector<int>& obstacles) {
        
        int n=obstacles.size();
        
        memset(dp,-1,sizeof(dp));
        
        int ans=func(obstacles,0,2);
        
        return ans;
        
    }
};