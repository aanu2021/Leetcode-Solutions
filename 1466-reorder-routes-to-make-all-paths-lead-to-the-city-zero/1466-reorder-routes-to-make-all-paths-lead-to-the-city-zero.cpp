class Solution {
public:
    
    vector<vector<pair<int,int>>>graph;
    
    int dfs(int u,int p){
        int sum = 0;
        for(auto &nbrs:graph[u]){
            int v = nbrs.first;
            int wt = nbrs.second;
            if(v==p) continue;
            sum += wt;
            sum += dfs(v,u);
        }
        return sum;
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        graph.resize(n);
        for(int i=0;i<connections.size();i++){
            graph[connections[i][0]].push_back({connections[i][1],0});
            graph[connections[i][1]].push_back({connections[i][0],1});
        }
        int change = dfs(0,-1);
        return n-1-change;
    }
};