class DSU{
  
    public:
    
    DSU(int n){
        Parent.resize(n);
        Rank.resize(n);
        for(int i=0;i<n;i++){
            Parent[i] = i;
            Rank[i] = 1;
        }
    }
    
    vector<int>Parent;
    vector<int>Rank;
    
    int find(int x){
        if(Parent[x]==x) return x;
        return Parent[x] = find(Parent[x]);
    }
    
    void Union(int x,int y){
        int lx = find(x);
        int ly = find(y);
        if(Rank[lx] > Rank[ly]){
            Parent[ly] = lx;
        }
        else{
            Parent[lx] = ly;
            if(Rank[lx]==Rank[ly]) Rank[lx]++;
        }
    }
    
    bool isLeader(int x){
        return Parent[x]==x;
    }
    
};

class Solution {
public:
    
    int numSimilarGroups(vector<string>& strs) {
        
        int n = strs.size();
        DSU obj(n);
        
        
        unordered_map<string,vector<int>>mapp;
        for(int i=0;i<n;i++){
            mapp[strs[i]].push_back(i);
        }
        for(auto &itr : mapp){
            int l = itr.second[0];
            for(auto &it : itr.second){
                obj.Union(l,it);
            }
        }
        
        unordered_map<string,int>indexMap;
        for(int i=0;i<n;i++){
            indexMap[strs[i]] = i;
        }
        
        for(int i=0;i<n;i++){
            int len = strs[i].length();
            for(int j=0;j<len;j++){
                for(int k=j+1;k<len;k++){
                    swap(strs[i][j],strs[i][k]);
                    if(indexMap.find(strs[i]) != indexMap.end()){
                        obj.Union(i,indexMap[strs[i]]);
                    }
                    swap(strs[i][j],strs[i][k]);
                }
            }
        }
        
        int groups = 0;
        for(int i=0;i<n;i++){
            if(obj.isLeader(i)) groups++;
        }
        return groups;
    }
};