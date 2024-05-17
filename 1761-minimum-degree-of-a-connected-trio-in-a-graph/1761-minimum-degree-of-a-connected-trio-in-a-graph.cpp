class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        for(int i=0;i<m;i++){
            edges[i][0]--;
            edges[i][1]--;
        }
        vector<vector<int>>graph(n);
        vector<vector<int>>adj(n, vector<int>(n, 0));
        for(int i=0;i<m;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            adj[u][v] = 1;
            adj[v][u] = 1;
        }
        int minCost = INT_MAX;
        for(int i=0;i<m;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            for(int nbr : graph[u]){
                if(nbr == v) continue;
                if(adj[nbr][v]){
                    int currCost = graph[u].size() + graph[v].size() + graph[nbr].size();
                    currCost -= 6;
                    minCost = min(minCost, currCost);
                }
            }
            for(int nbr : graph[v]){
                if(nbr == u) continue;
                if(adj[nbr][u]){
                    int currCost = graph[u].size() + graph[v].size() + graph[nbr].size();
                    currCost -= 6;
                    minCost = min(minCost, currCost);
                }
            }
        }
        return minCost == INT_MAX ? -1 : minCost;
    }
};