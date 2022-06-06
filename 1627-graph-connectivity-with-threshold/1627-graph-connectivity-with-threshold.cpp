class Solution {
public:
    
    int Parent[10005];
    int Rank[10005];
    
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
        
    }
    
    vector<bool> areConnected(int n, int t, vector<vector<int>>& queries) {
        
        int m=queries.size();
        
        vector<bool>ans(m,false);
        
        for(int i=1;i<=n;i++){
            Parent[i]=i;
            Rank[i]=1;
        }
        
        for(int i=1;i<=n;i++){
            
            int last=i;
            
            for(int j=1;j*j<=i;j++){
                
                if(i%j==0){
                    
                    if(j>t){
                        Union(last,j);
                    }
                    
                    if((i/j)>t){
                        Union(last,i/j);
                    }
                    
                }
                
            }
            
        }
        
        
        for(int i=0;i<m;i++){
            
            int lx=find(queries[i][0]);
            int ly=find(queries[i][1]);
            
            if(lx==ly){
                ans[i]=true;
            }else{
                ans[i]=false;
            }
            
        }
        
        return ans;
        
    }
};