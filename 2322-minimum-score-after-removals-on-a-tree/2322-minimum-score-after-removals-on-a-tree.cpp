class Solution {
public:
    
    vector<vector<int>>graph;
    
    vector<int>a;
    
    vector<vector<bool>>visited;
    
    vector<int>xs;
    
    int N;
    
    void dfs(int u,int p){
        
        visited[u][u]=true;
        
        xs[u]=a[u];
        
        for(int v:graph[u]){
            
            if(v!=p){
                
                dfs(v,u);
                
                xs[u]^=xs[v];
                
                for(int j=0;j<N;j++){
                    
                    visited[u][j]=visited[u][j] || visited[v][j];
                    
                }
                
            }
            
        }
        
    }
    
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        
        int n=nums.size();
        
        N=n;
        
        graph.resize(n);
        a.resize(n);
        xs.resize(n);
        
        for(int i=0;i<n;i++){
            a[i]=nums[i];
        }
        
        for(int i=0;i<edges.size();++i){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        visited=vector<vector<bool>>(n,vector<bool>(n,false));
        
        int ans=INT_MAX;
        
        dfs(0,-1);
        
        for(int i=1;i<n;i++){
            
            for(int j=i+1;j<n;j++){
                
                int u=i,v=j;
                
                if(visited[u][v]==true || visited[v][u]==true){
                    
                    if(visited[v][u]==true){
                        
                        swap(v,u);
                        
                    }
                    
                    int val1=xs[v];
                    int val2=xs[u]^xs[v];
                    int val3=xs[0]^xs[u];
                    
                    ans=min(ans,max({val1,val2,val3})-min({val1,val2,val3}));
                    
                }
                
                else{
                    
                    int val1=xs[v];
                    int val2=xs[u];
                    int val3=xs[0]^xs[u]^xs[v];
                    
                     ans=min(ans,max({val1,val2,val3})-min({val1,val2,val3}));
                    
                }
                
            }
            
        }
        
        return ans;
        
    }
};