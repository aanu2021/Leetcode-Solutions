class Solution {
public:
    
    int Parent[1005];
    int Rank[1005];
    
    int islands=0;
    
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
            
            islands--;
            
        }
       
    }
    
    int removeStones(vector<vector<int>>& stones) {
        
        for(int i=0;i<=1000;i++){
            Parent[i]=i;
            Rank[i]=1;
        }
        
        islands=stones.size();
        
        for(int i=0;i<stones.size();i++){
            
           for(int j=i;j<stones.size();j++){
               
               if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                   Union(i,j);
               }
               
           }
            
        }
        
        return stones.size()-islands;
        
    }
};