class Solution {
public:
    
    vector<vector<pair<int,int>>>graph;
    vector<int>subtree;
    vector<int>ans;
    
    void precompute(int u,int p){
        int sum = 0;
        for(auto &nbrs:graph[u]){
            int v = nbrs.first;
            int wt = nbrs.second;
            if(v==p) continue;
            sum += wt;
            precompute(v,u);
            sum += subtree[v];
        }
        subtree[u] = sum;
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        
        graph.clear();
        subtree.clear();
        ans.clear();
        
        graph.resize(n);
        subtree.resize(n,0);
        ans.resize(n,0);
        
        for(int i=0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];
            graph[u].push_back({v,1});
            graph[v].push_back({u,0});
        }
        
        precompute(0,-1);
        return subtree[0];
    }
};