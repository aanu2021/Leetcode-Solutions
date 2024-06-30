class Solution {
public:
    
    int getDiameter(vector<vector<int>>&graph, int n){
        vector<int>dist(n, 0);
        vector<int>visited(n, 0);
        queue<int>q;
        q.push(0);
        visited[0] = 1;
        int lvl = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int node = q.front(); q.pop();
                dist[node] = lvl;
                for(int &nbr : graph[node]){
                    if(visited[nbr]) continue;
                    visited[nbr] = 1;
                    q.push(nbr);
                }
            }
            lvl++;
        }
        int leaf = max_element(dist.begin(),dist.end()) - dist.begin();
        for(int i=0;i<n;i++){
            visited[i] = 0;
            dist[i] = 0;
        }
        q.push(leaf);
        visited[leaf] = 1;
        lvl = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int node = q.front(); q.pop();
                dist[node] = lvl;
                for(int &nbr : graph[node]){
                    if(visited[nbr]) continue;
                    visited[nbr] = 1;
                    q.push(nbr);
                }
            }
            lvl++;
        }
        return *max_element(dist.begin(),dist.end());
    }
    
    int getLevelFromCenter(int src, vector<vector<int>>&graph, int n){
        vector<int>visited(n, 0);
        vector<int>dist(n, 0);
        queue<int>q;
        q.push(src);
        visited[src] = 1;
        int lvl = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int node = q.front(); q.pop();
                dist[node] = lvl;
                for(int &nbr : graph[node]){
                    if(visited[nbr]) continue;
                    visited[nbr] = 1;
                    q.push(nbr);
                }
            }
            lvl++;
        }
        return *max_element(dist.begin(),dist.end());
    }
    
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        
        int n = edges1.size();
        int m = edges2.size();
        n++;
        m++;
        vector<vector<int>>graph1(n);
        vector<vector<int>>graph2(m);
        vector<int>degree1(n, 0);
        vector<int>degree2(m, 0);
        
        for(int i=0;i<edges1.size();i++){
            int u = edges1[i][0];
            int v = edges1[i][1];
            graph1[u].push_back(v);
            graph1[v].push_back(u);
            degree1[u]++; degree1[v]++;
        }
        
        for(int i=0;i<edges2.size();i++){
            int u = edges2[i][0];
            int v = edges2[i][1];
            graph2[u].push_back(v);
            graph2[v].push_back(u);
            degree2[u]++; degree2[v]++;
        }
        
        vector<int>level1(n, 0);
        vector<int>level2(m, 0);
        queue<int>q;
        for(int i=0;i<n;i++){
            if(degree1[i] == 1) q.push(i);
        }
        int lvl = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int node = q.front(); q.pop();
                level1[node] = lvl;
                for(int &nbr : graph1[node]){
                    degree1[nbr]--;
                    if(degree1[nbr] == 1){
                        q.push(nbr);
                    }
                }
            }
            lvl++;
        }
        int src1 = max_element(level1.begin(),level1.end()) - level1.begin();
        int mL1 = getLevelFromCenter(src1, graph1, n);
        for(int i=0;i<m;i++){
            if(degree2[i] == 1) q.push(i);
        }
        lvl = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int node = q.front(); q.pop();
                level2[node] = lvl;
                for(int &nbr : graph2[node]){
                    degree2[nbr]--;
                    if(degree2[nbr] == 1){
                        q.push(nbr);
                    }
                }
            }
            lvl++;
        }
         int src2 = max_element(level2.begin(),level2.end()) - level2.begin();
        int mL2 = getLevelFromCenter(src2, graph2, m);
        int minDiameter = mL1 + mL2 + 1;
        // cout<<minDiameter<<"\n";
        minDiameter = max(minDiameter, getDiameter(graph1, n));
        minDiameter = max(minDiameter, getDiameter(graph2, m));
        return minDiameter;
    }
};