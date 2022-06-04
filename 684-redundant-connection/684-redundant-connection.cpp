class Solution {
public:
    
    int Parent[1005];
    int Rank[1005];
    
    int find(int x){
        
        if(Parent[x]==x){
            return x;
        }
        
        int temp=find(Parent[x]);
        
        return Parent[x]=temp;
        
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
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        for(int i=0;i<=1000;i++){
            Parent[i]=i;
            Rank[i]=1;
        }
        
        vector<int>ans;
        
        for(int i=0;i<edges.size();i++){
            
            int u=edges[i][0];
            int v=edges[i][1];
            
            int p1=find(u);
            int p2=find(v);
            
            bool flag=Union(p1,p2);
            
            if(flag==true){
                ans=edges[i];
                break;
            }
            
        }
        
        return ans;
        
    }
};