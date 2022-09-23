class Solution {
public:
    
    vector<int>Parent,Rank;
    
    int find(int x){
        
        if(Parent[x]==x) return x;
        return Parent[x]=find(Parent[x]);
        
    }
    
    bool Union(int x,int y){
        
        int lx=find(x),ly=find(y);
        
        if(lx!=ly){
            
            if(Rank[lx]<Rank[ly]){
                Parent[lx]=ly;
            }else{
                Parent[ly]=lx;
                if(Rank[lx]==Rank[ly]){
                    Rank[lx]++;
                }
            }
            
            return false;
            
        }
        
        else{
            
            return true;
            
        }
        
    }
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        
        int n=edges.size();
        
        Parent.resize(n+1);
        Rank.resize(n+1);
        
        for(int i=1;i<=n;++i){
            Parent[i]=i;
            Rank[i]=1;
        }
        
        int bl1=-1,bl2=-1;
        
        vector<int>indegree(n+1,-1);
        
        for(int i=0;i<n;++i){
            
            int u=edges[i][0];
            int v=edges[i][1];
            
            if(indegree[v]==-1){
                
                indegree[v]=i;
                
            }
            
            else{
                
                bl1=i;
                bl2=indegree[v];
                
            }
            
        }
        
      
        for(int i=0;i<n;++i){
            
            if(i==bl1) continue;
            
            int u=edges[i][0];
            int v=edges[i][1];
            
            bool temp=Union(u,v);
            
            if(temp){
                
                if(bl1==-1){
                    
                    return edges[i];
                    
                }
                
                else{
                    
                    return edges[bl2];
                    
                }
                
            }
            
        }
        
        return edges[bl1];
        
    }
};