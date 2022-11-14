class Solution {
public:
    
    vector<int>Parent;
    vector<int>Size;
    
    int find(int x){
        if(Parent[x]==x) return x;
        return Parent[x] = find(Parent[x]);
    }
    
    bool Union(int x,int y){
        int lx = find(x);
        int ly = find(y);
        if(lx!=ly){
            if(Size[lx]<Size[ly]){
                Parent[lx] = ly;
                Size[ly]+=Size[lx];
            }else{
                Parent[ly] = lx;
                Size[lx]+=Size[ly];
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
        Size.resize(n);
        
        for(int i=0;i<n;i++){
            Parent[i] = i;
            Size[i] = 1;
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