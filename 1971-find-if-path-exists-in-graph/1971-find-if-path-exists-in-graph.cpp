class Solution {
public:
    
    bool dfs(int u, int target, vector<vector<int>>&graph, vector<bool>&visited){
        if(u == target) return true;
        for(int v : graph[u]){
            if(visited[v]) continue;
            visited[v] = true;
            if(dfs(v, target, graph, visited)) return true;
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>graph(n);
        vector<bool>visited(n, false);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        visited[source] = true;
        return dfs(source, destination, graph, visited);
    }
};