class Solution {
public:
    
    int endingMask;
    
    vector<vector<int>>dp;
    
    int func(int node,vector<vector<int>>&graph,int mask){
        
        if((mask&(mask-1))==0) return 0;
        
        if(dp[node][mask]!=-1) return dp[node][mask];
        
        dp[node][mask] = 1e9;
        
        for(int nbr:graph[node]){
            
            if((mask&(1<<nbr))){
                
                int last_pick = func(nbr,graph,(mask^(1<<node)));
                int not_last_pick = func(nbr,graph,mask);
                
                dp[node][mask]=min(dp[node][mask],1+min(last_pick,not_last_pick));
                
            }
            
        }
        
        return dp[node][mask];
        
    }
    
    int shortestPathLength(vector<vector<int>>& graph) {
    
        int n=graph.size();
        
        endingMask=(1<<n)-1;
        
        dp = vector<vector<int>>(n,vector<int>(endingMask+1,-1));
        
        int ans = 1e9;
        
        for(int i=0;i<n;++i){
            
            ans=min(ans,func(i,graph,endingMask));
            
        }
        
        return ans;
        
    }
};