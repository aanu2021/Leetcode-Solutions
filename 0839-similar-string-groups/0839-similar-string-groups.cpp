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
    
    bool isMatch(string &s1,string &s2){
        int n = s1.length();
        int diff = 0;
        for(int i=0;i<n;i++){
            diff += (s1[i] != s2[i]);
        }
        return diff==0 || diff==2;
    }
    
    int numSimilarGroups(vector<string>& strs) {
        
        int n = strs.size();
        DSU obj(n);
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isMatch(strs[i],strs[j])){
                    obj.Union(i,j);
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

