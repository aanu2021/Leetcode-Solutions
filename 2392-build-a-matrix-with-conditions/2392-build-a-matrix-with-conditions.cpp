class Solution {
public:
    
    vector<int>topo_sort(int k, vector<vector<int>>&edges){
        int m = edges.size();
        vector<vector<int>>graph(k+1);
        vector<int>indegree(k+1, 0);
        for(int i=0;i<m;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int>q;
        vector<int>topo;
        for(int i=1;i<=k;i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front(); q.pop();
            topo.push_back(node);
            for(int &nbr : graph[node]){
                indegree[nbr]--;
                if(indegree[nbr] == 0) q.push(nbr);
            }
        }
        
        if(topo.size() != k) return {};
        else return topo;
    }
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        vector<int>row_topo = topo_sort(k, rowConditions);
        vector<int>col_topo = topo_sort(k, colConditions);
        
        if(row_topo.size() == 0 || col_topo.size() == 0) return {};
        vector<vector<int>>grid(k, vector<int>(k, 0));
        unordered_map<int,int>rowMap,colMap;
        
        for(int i=0;i<k;i++){
            rowMap[row_topo[i]] = i;
            colMap[col_topo[i]] = i;
        }
        
        for(int i=1;i<=k;i++){
            grid[rowMap[i]][colMap[i]] = i;
        }
        return grid;
        
    }
};