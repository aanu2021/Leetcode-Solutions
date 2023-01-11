class Solution {
public:
    
    int total_time;
    vector<vector<int>>graph;
    vector<int>subtree_apple;
    
    void precompute(int u,int p,vector<bool>&hasApple){
        subtree_apple[u] = hasApple[u];
        for(int v:graph[u]){
            if(v==p) continue;
            precompute(v,u,hasApple);
            subtree_apple[u] += subtree_apple[v];
        }
    }
    
    void dfs(int u,int p){
        for(int v:graph[u]){
            if(v==p) continue;
            if(subtree_apple[v]){
                total_time+=2;
                dfs(v,u);
            }
        }
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        graph.clear();
        subtree_apple.clear();
        graph.resize(n);
        subtree_apple.resize(n,0);
        total_time = 0;
        
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        precompute(0,-1,hasApple);
        
        dfs(0,-1);
        
        return total_time;
        
    }
};