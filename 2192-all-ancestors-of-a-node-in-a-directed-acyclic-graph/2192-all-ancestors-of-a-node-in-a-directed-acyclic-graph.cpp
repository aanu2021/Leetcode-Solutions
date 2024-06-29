class Solution {
public:
    
    void dfs(int node, vector<vector<int>>&parent, int n, set<int>&S){
        if(S.find(node) != S.end()) return;
        S.insert(node);
        for(int &ancestor : parent[node]) dfs(ancestor, parent, n, S);
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int>degree(n, 0);
        vector<vector<int>>parent(n);
        vector<vector<int>>graph(n);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            degree[v]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(degree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front(); q.pop();
            for(int &nbr : graph[node]){
                degree[nbr]--;
                parent[nbr].push_back(node);
                if(degree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
        vector<vector<int>>answer(n);
        for(int i=0;i<n;i++){
            set<int>S;
            for(auto &ancestor : parent[i]){
                dfs(ancestor, parent, n, S);
            }
            for(auto &ele : S){
                answer[i].push_back(ele);
            }
        }
        return answer;
    }
};

// 0 -> 3
// 0 -> 4
// 1 -> 3
// 2 -> 4
// 2 -> 7
// 3 -> 5
// 3 -> 6
// 3 -> 7
// 4 -> 6
    
// 0 1 2 3 4 5 6 7
// 0 0 0 2 2 1 2 2
    
// . . . . . . . .
    
    