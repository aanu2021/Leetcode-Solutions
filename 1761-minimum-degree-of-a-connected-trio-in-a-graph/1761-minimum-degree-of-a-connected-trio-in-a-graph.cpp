class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        
        vector<unordered_set<int>>graph(n);
        vector<int>checked(n, 0);
        int minCost = INT_MAX;
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            u--; v--;
            graph[u].insert(v);
            graph[v].insert(u);
        }
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            u--; v--;
            for(auto nbr : graph[u]){
                if(nbr == v) continue;
                if(graph[v].find(nbr) != graph[v].end()){
                    int total = graph[u].size() + graph[v].size() + graph[nbr].size();
                    total -= 6;
                    minCost = min(minCost, total);
                    checked[u] = 1;
                    checked[v] = 1;
                    checked[nbr] = 1;
                }
            }
            for(auto nbr : graph[v]){
                if(nbr == u) continue;
                if(graph[u].find(nbr) != graph[u].end()){
                    int total = graph[u].size() + graph[v].size() + graph[nbr].size();
                    total -= 6;
                    minCost = min(minCost, total);
                    checked[u] = 1;
                    checked[v] = 1;
                    checked[nbr] = 1;
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(checked[i]) cnt++;
        }
        if(cnt == 0) return -1;
        else return minCost;
        // int answer = 0;
        // for(int i=0;i<edges.size();i++){
        //     int u = edges[i][0];
        //     int v = edges[i][1];
        //     u--; v--;
        //     if((checked[u] && !checked[v]) || (!checked[u] && checked[v]))
        //     {
        //         answer++;
        //     }
        // }
        // return answer;
    }
};