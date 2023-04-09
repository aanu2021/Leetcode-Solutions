class Solution {
public:
    
    vector<vector<int>>graph;
    vector<vector<int>>rgraph;
    vector<int>visited;
    vector<int>pathVisited;
    vector<int>indegree;
    vector<vector<int>>colorCnt;
    
    bool isCycle(int u){
        visited[u] = 1;
        pathVisited[u] = 1;
        
        for(int v:rgraph[u]){
            if(visited[v]){
                if(pathVisited[v]) return true;
            }
            else{
                bool flag = isCycle(v);
                if(flag) return true;
            }
        }
        
        pathVisited[u] = 0;
        return false;
    }
    
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        // first check if a cycle is present or not.
        // then consider every possible character ('a' - 'z')
        // to find the actual ordering of nodes, go for toposort
        
        int n = colors.size();
        graph.resize(n);
        rgraph.resize(n);
        visited.resize(n,0);
        pathVisited.resize(n,0);
        indegree.resize(n,0);
        colorCnt = vector<vector<int>>(n,vector<int>(26,0));
        
        for(int i=0;i<edges.size();i++){
            graph[edges[i][1]].push_back(edges[i][0]);
            rgraph[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][0]]++;
        }
        
        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            if(isCycle(i)) return -1;
        }
        
        int maxColor = 0;
        vector<int>topo;
        queue<int>q;
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front(); q.pop();
            topo.push_back(node);
            for(int nbr : graph[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0) q.push(nbr);
            }
        }
        
        // for(int &ele : topo){
        //     cout<<ele<<" ";
        // }cout<<"\n";
        
        if(topo.size() != n) return -1;
        
        for(int u:topo){
            colorCnt[u][colors[u]-'a'] = 1;
            for(int v:rgraph[u]){
                for(int c=0;c<26;c++){
                    colorCnt[u][c] = max(colorCnt[u][c],colorCnt[v][c] + ((colors[u]-'a')==c ? 1 : 0));
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<26;j++){
                maxColor = max(maxColor,colorCnt[i][j]);
                // cout<<colorCnt[i][j]<<" ";
            }
        }
        
        return maxColor;
        
    }
};