class Solution {
public:
    
    vector<vector<int>>graph;
    
    int t=0;
    
    vector<int>tin;
    
    vector<int>tout;
    
    vector<int>a;
    
    vector<int>xs;
    
    
    void dfs(int u,int p){
        
        tin[u]=t++;
        
        xs[u]=a[u];
        
        for(int v:graph[u]){
            
            if(v!=p){
                
                dfs(v,u);
                
                xs[u]^=xs[v];
                
                // tout[u]=t++;
                
            }
            
            tout[u]=t++;
            
        }
        
    }
    
    
    bool isAncestor(int u,int v){
        
        if(tin[u]<=tin[v] && tout[v]<=tout[u]){
            return true;
        }else{
            return false;
        }
        
    }
    
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        
        int n=nums.size();
        
        graph.resize(n);
        
        tin.resize(n);
        
        tout.resize(n);
        
        xs.resize(n);
        
        a.resize(n);
        
        a=nums;
        
        
        for(int i=0;i<edges.size();++i){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        
        dfs(0,-1);
        
        int ans=INT_MAX;
        
        for(int i=1;i<n;i++){
            
            for(int j=i+1;j<n;j++){
                
                int u=i,v=j;
                
                if(isAncestor(u,v) || isAncestor(v,u)){
                    
                    if(isAncestor(v,u)){
                        swap(u,v);
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