class TreeAncestor {
public:
    
    vector<vector<int>>up;
    
    vector<vector<int>>graph;
    
    void preprocess(int u,int p){
        
        up[u][0] = p;
        
        for(int i=1;i<20;i++){
            
            if(up[u][i-1]!=-1){
                
                up[u][i] = up[up[u][i-1]][i-1];
                
            }
            
        }
        
        for(int v:graph[u]){
            
            if(v==p){
                continue;
            }
            
            preprocess(v,u);
            
        }
        
    }
    
    TreeAncestor(int n, vector<int>& parent) {
        
        up.clear();
        
        up=vector<vector<int>>(n+1,vector<int>(20,-1));
        
        graph.clear();
        
        graph=vector<vector<int>>(n+1);
        
        for(int i=1;i<n;i++){
            graph[parent[i]].push_back(i);
        }
        
        preprocess(0,-1);
        
    }
    
    int getKthAncestor(int node, int k) {
        
        for(int i=19;i>=0;i--){
            
            if(node==-1){
                
                break;
                
            }
            
            if((k&(1<<i))){
                
                node = up[node][i];
                
                k-=(1<<i);
                
            }
            
        }
        
        return node;
        
    }
};

