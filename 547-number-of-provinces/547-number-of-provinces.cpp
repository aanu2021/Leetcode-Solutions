class Solution {
public:
    
    int Parent[205];
    int Rank[205];
    
    int islands;
    
    int find(int x){
        if(Parent[x]==x){
            return x;
        }
        int temp=find(Parent[x]);
        return Parent[x]=temp;
    }
    
    void Union(int x , int y){
        
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
            
            islands--;
            
        }
        
    }
    
    int findCircleNum(vector<vector<int>>& graph) {
        
        int n=graph.size();
        
        islands=n;
        
        for(int i=0;i<=202;i++){
            Parent[i]=i;
            Rank[i]=1;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(graph[i][j]==1 && i!=j){
                    Union(i,j);
                }
            }
        }
        
        return islands;
        
    }
};