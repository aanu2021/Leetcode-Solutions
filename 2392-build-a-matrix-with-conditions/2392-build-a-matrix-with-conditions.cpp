class Solution {
public:
    
    
    
    // return false if the graph formed is cyclic in nature. 
    //normal graph building and topological sort code
    bool buildGraph(vector<vector<int> >& arr, int n, vector<int>& data) {
        vector<int> adj[n + 1];
        vector<int> indeg(n + 1, 0);
        for(auto& curr: arr) {
            adj[curr[0]].push_back(curr[1]);
            indeg[curr[1]]++;
        }
        queue<int> q;
        for(int i = 1; i <= n; i++) {
            if(indeg[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            data.push_back(node);
            for(auto& x: adj[node]) {
                if(--indeg[x] == 0) {
                    q.push(x);
                }
            }
        }
        return data.size() == n;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> topoRow, topoCol;
        
        // if the graph formed by the two arrays is cyclic, then answer is not possible.
        if(!buildGraph(rowConditions, k, topoRow) || !buildGraph(colConditions, k, topoCol)) {
            return {};
        }
        
        int row[k + 1], col[k + 1];
    
        
        for(int i = 0; i < k; i++) {
            row[topoRow[i]] = i;
            col[topoCol[i]] = i;
        }
        
        vector<vector<int> > arr(k, vector<int>(k, 0));
        for(int i = 1; i <= k; i++) {
            arr[row[i]][col[i]] = i;
        }
        return arr;
        
    }
};