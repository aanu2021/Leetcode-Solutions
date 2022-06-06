class Solution {
public:
    
    int Parent[1005];
    int Rank[1005];
    
    int islands;
    
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
        
        islands=stones.size();
        
        for(int i=0;i<=1000;i++){
            Parent[i]=i;
            Rank[i]=1;
        }
        
        unordered_map<int,unordered_set<int>>mpx;
        unordered_map<int,unordered_set<int>>mpy;
        
        for(int i=0;i<stones.size();i++){
            mpx[stones[i][0]].insert(i);
            mpy[stones[i][1]].insert(i);
        }
        
        for(auto itr:mpx){
            
            int tp=*itr.second.begin();
            
            for(auto it:itr.second){
                
                Union(tp,it);
                
            }
            
        }
        
        
         for(auto itr:mpy){
            
            int tp=*itr.second.begin();
            
            for(auto it:itr.second){
                
                Union(tp,it);
                
            }
            
        }
        
        return stones.size()-islands;
        
    }
};