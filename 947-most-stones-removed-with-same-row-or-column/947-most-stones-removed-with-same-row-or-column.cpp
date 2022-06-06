class Solution {
public:
    
    int Parent[1005];
    int Rank[1005];
    
    int islands=0;
    
    int find(int x){
        
        if(Parent[x]==x){
            return x;
        }
        
        return Parent[x]=find(Parent[x]);
        
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
       
        int n=stones.size();
        
        islands=n;
        
        for(int i=0;i<n;i++){
            Parent[i]=i;
            Rank[i]=1;
        }
        
        unordered_map<int,vector<int>>mpx;
        unordered_map<int,vector<int>>mpy;
        
        for(int i=0;i<n;i++){
            
            mpx[stones[i][0]].push_back(i);
            mpy[stones[i][1]].push_back(i);
            
        }
        
        
        for(auto itr:mpx){
            
            int tp=itr.second.back();
            
            for(auto it:itr.second){
                
                Union(it,tp);
                
            }
            
        }
        
        
         for(auto itr:mpy){
            
            int tp=itr.second.back();
            
            for(auto it:itr.second){
                
                Union(it,tp);
                
            }
            
        }
        
        
        return n-islands;
        
    }
};