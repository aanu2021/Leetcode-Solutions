class Solution {
public:
    
    vector<vector<int>>graph;
    vector<int>need;
    
    void dfs(int u,int tim,int &maxi){
        maxi = max(maxi,tim);
        for(int v : graph[u]){
            dfs(v,tim + need[u],maxi);
        }
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        graph.clear();
        need.clear();
        
        graph.resize(n);
        need.resize(n);
        
        for(int i=0;i<n;i++) need[i] = informTime[i];
        
        for(int i=0;i<n;i++){
            if(manager[i]==-1) continue;
            graph[manager[i]].push_back(i);
        }
        
        int maxTime = 0;
        dfs(headID,0,maxTime);
        
        return maxTime;
        
    }
};