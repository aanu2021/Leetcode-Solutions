class Solution {
public:
    
    int ans=0;
    
    int Parent[1005];
    int Rank[1005];
    
    
    int find(int x){
        
        if(Parent[x]==x){
            return x;
        }
        
        int temp=find(Parent[x]);
        
        return Parent[x]=temp;
        
    }
    
    
    void Union(int x,int y){
       
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
            
        }
        
        else{
            
            ans++;
            
        }
        
    }
    
    
    
    int regionsBySlashes(vector<string>& grid) {
        
        int n=grid.size();
        
        
        for(int i=0;i<=1002;i++){
            Parent[i]=i;
            Rank[i]=1;
        }
        
        
        n++;
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                int cell=(i*n)+j;
                
                if(i==0 || i==n-1 || j==0 || j==n-1){
                    Union(0,cell);
                }
                
            }
        }
        
        
        for(int i=0;i<grid.size();i++){
            
            for(int j=0;j<grid.size();j++){
                
                if(grid[i][j]=='/'){
                    
                    int cell1=((i+1)*n)+j;
                    int cell2=(i*n)+(j+1);
                    
                    Union(cell1,cell2);
                    
                }
                
                else if(grid[i][j]=='\\'){
                    
                    int cell1=(i*n)+j;
                    int cell2=((i+1)*n)+(j+1);
                    
                    Union(cell1,cell2);
                    
                }
                
            }
            
        }
        
        
        return ans;
        
    }
};