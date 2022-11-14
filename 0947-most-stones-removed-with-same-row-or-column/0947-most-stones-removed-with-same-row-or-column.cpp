class Solution {
public:
    
    vector<int>Parent;
    vector<int>Rank;
    
    int find(int x){
        if(Parent[x]==x) return x;
        return Parent[x] = find(Parent[x]);
    }
    
    bool Union(int x,int y){
        int lx = find(x);
        int ly = find(y);
        if(lx!=ly){
            if(Rank[lx] > Rank[ly]){
                Parent[ly] = lx;
            }else{
                Parent[lx] = ly;
                if(Rank[lx]==Rank[ly]){
                    Rank[lx]++;
                }
            }
            return true;
            
        }else{
            return false;
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        
        int n = stones.size();
        
        unordered_map<int,vector<int>>mpx;
        unordered_map<int,vector<int>>mpy;
        
        for(int i=0;i<stones.size();i++){
            mpx[stones[i][0]].push_back(i);
            mpy[stones[i][1]].push_back(i);
        }
        
        Parent.resize(n);
        Rank.resize(n);
        
        for(int i=0;i<n;i++){
            Parent[i] = i;
            Rank[i] = 1;
        }
        
        int ans = 0;
        
        for(auto &itr:mpx){
            int leader = itr.second[0];
            for(auto &it:itr.second){
                bool flag = Union(leader,it);
                if(flag) ans++;
            }
        }
        
        for(auto &itr:mpy){
            int leader = itr.second[0];
            for(auto &it:itr.second){
                bool flag = Union(leader,it);
                if(flag) ans++;
            }
        }
        
        return ans;
        
    }
};