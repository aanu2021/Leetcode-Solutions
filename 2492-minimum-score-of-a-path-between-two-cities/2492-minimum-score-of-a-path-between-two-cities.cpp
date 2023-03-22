class Solution {
public:
    
    vector<vector<int>>graph;
    vector<int>visited;
    
    void dfs(int u){
        visited[u] = 1;
        for(int v : graph[u]){
            if(visited[v]) continue;
            dfs(v);
        }
    }
    
    int minScore(int n, vector<vector<int>>& roads) {
        graph.clear();
        visited.clear();
        graph = vector<vector<int>>(n+1);
        visited = vector<int>(n+1,0);
        for(int i=0;i<roads.size();i++){
            int u = roads[i][0];
            int v = roads[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs(1);
        int minEdgeWt = 1e9;
        for(int i=0;i<roads.size();i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            if(visited[u] && visited[v]){
                minEdgeWt = min(minEdgeWt,w);
            }
        }
        return minEdgeWt;
    }
};

// may not be connected
// particular city can be visited multiple times
// first find out the connected component containing 1 and n
// and eventually mark all those nodes of that component
// then add only those edges which are somehow part of the connected component.
// Minimum edge weight should be our optimal answer.