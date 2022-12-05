class Solution {
public:
    vector<vector<int>>graph;
    
     bool dfs(int u,vector<int>&col){
        
        for(int v:graph[u]){
         
            if(col[v]==col[u]) return false;
            
            if(col[v]==-1){
                
                col[v] = 1 - col[u];
                
                bool flag = dfs(v,col);
                
                if(!flag) return false;
                
            }
            
        }
        
        return true;
        
    }
    
    vector<int>vec;
    bool flag = false;
    
    int func(int u,vector<bool>&vis){
        if(flag){
            for(int i=0;i<vis.size();i++){
                vis[i] = false;
            }
        }
        vis[u] = true;
        queue<int>q;
        q.push(u);
        int lvl = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int node = q.front();
                vec.push_back(node);
                q.pop();
                for(int nbr:graph[node]){
                    if(vis[nbr]) continue;
                    q.push(nbr);
                    vis[nbr] = true;
                }
            }
            lvl++;
        }
        return lvl;
    }
    
    int magnificentSets(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            u--;
            v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int>col(n,-1);
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(col[i]!=-1) continue;
            col[i] = 1;
            if(dfs(i,col)==false){
                return -1;
            }
        }
        
        vector<vector<int>>grps;
        
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            vec.clear();
            func(i,vis);
            grps.push_back(vec);
        }
        
        int ans = 0;
        flag = true;
        
        for(auto grp:grps){
            int curr = 0;
            for(int ele:grp){
                curr = max(curr,func(ele,vis));
            }
            ans += curr;
        }
        
        return ans;
        
    }
};