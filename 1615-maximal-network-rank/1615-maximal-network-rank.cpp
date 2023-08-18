class Solution {
public:
    
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>>graph(n);
        for(int i=0;i<roads.size();i++){
            graph[roads[i][0]].insert(roads[i][1]);
            graph[roads[i][1]].insert(roads[i][0]);
        }
        int maxSize = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int degree_u = graph[i].size();
                int degree_v = graph[j].size();
                int currSize = degree_u + degree_v;
                if(graph[i].find(j) != graph[j].end()){
                    currSize--;
                }
                maxSize = max(maxSize, currSize);
            }
        }
        return maxSize;
    }
};

/*

1. undirected graph
2. degree[u] + degree[v] - (Rank[u] != Rank[v])
    
    0 - 1 - 2 - 3     5 - 6
            |         | 
            4         7
            
*/            