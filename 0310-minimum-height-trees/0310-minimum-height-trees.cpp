class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>degree(n, 0);
        vector<vector<int>>graph(n);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            degree[u]++; degree[v]++;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int>level(n, 0);
        queue<int>q;
        int lvl = 0;
        for(int i=0;i<n;i++){
            if(degree[i] == 1) q.push(i);
        }
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int node = q.front(); q.pop();
                level[node] = lvl;
                for(int &nbr : graph[node]){
                    degree[nbr]--;
                    if(degree[nbr] == 1){
                        q.push(nbr);
                    }
                }
            }
            lvl++;
        }
        int maxLevel = *max_element(level.begin(),level.end());
        vector<int>answer;
        for(int i=0;i<n;i++){
            if(level[i] == maxLevel) answer.push_back(i);
        }
        return answer;
    }
};