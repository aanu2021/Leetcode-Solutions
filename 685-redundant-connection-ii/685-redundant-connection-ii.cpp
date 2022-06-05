class Solution {
public:
    
    int Parent[1005];
    int Rank[1005];
    
    int find(int x){
        if(Parent[x]==x){
            return x;
        }
        return Parent[x]=find(Parent[x]);
    }
    
    bool Union(int x,int y){
        
        int lx=find(x);
        int ly=find(y);
        
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
        
        // Case 1 --> 2 Parent
        // Case 2 --> Cycle
        // Case 3 --> 2 Parent + Cycle
        
        int n=edges.size();
        
        for(int i=0;i<=n;i++){
            Parent[i]=i;
            Rank[i]=1;
        }
        
        vector<int>indegree(n+1,-1);
        
        int bl1=-1,bl2=-1;
        
        for(int i=0;i<edges.size();i++){
            
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
        
        
        for(int i=0;i<edges.size();i++){
            
            if(i==bl1){
                continue;
            }
            
            int x=edges[i][0];
            int y=edges[i][1];
            
            bool temp=Union(x,y);
            
            if(temp==true){
                
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