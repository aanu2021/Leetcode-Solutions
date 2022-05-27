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
        
        else{
            
            int path1=(lane+1)%3;
            int path2=(lane+2)%3;
            
            if(path1==0){
                path1=3;
            }
            
            if(path2==0){
                path2=3;
            }
            
            return dp[i][lane]=1+min(func(obstacles,i,path1),func(obstacles,i,path2));
            
        }
        
    }
    
    int minSideJumps(vector<int>& obstacles) {
        
        int n=obstacles.size();
        
        memset(dp,-1,sizeof(dp));
        
        int ans=func(obstacles,0,2);
        
        return ans;
        
    }
};