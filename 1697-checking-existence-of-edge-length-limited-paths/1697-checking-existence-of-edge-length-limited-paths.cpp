class DSU{
  
    private:
    
    vector<int>Parent,Rank;
    
    public:
    
    DSU(int n){
        Parent.resize(n);
        Rank.resize(n);
        for(int i=0;i<n;i++){
            Parent[i] = i;
            Rank[i] = 1;
        }
    }
    
    int find(int x){
        if(Parent[x]==x) return x;
        return Parent[x] = find(Parent[x]);
    }
    
    bool isSameLeader(int x,int y){
        int lx = find(x);
        int ly = find(y);
        if(lx != ly){
            return false;
        }
        else{
            return true;
        }
    }
    
    bool Union(int x,int y){
        int lx = find(x);
        int ly = find(y);
        if(lx != ly){
            if(Rank[lx] > Rank[lx]){
                Parent[ly] = lx;
            }
            else{
                Parent[lx] = ly;
                if(Rank[lx]==Rank[ly]) Rank[lx]++;
            }
            return true;
        }
        else{
            return false;
        }
    }
    
    bool isLeader(int x){
        int lx = find(x);
        return lx==x;
    }
    
};

class Solution {
public:
    
    bool static comp(const vector<int>&x,const vector<int>&y){
        return x[2] < y[2];
    }
    
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        
        int q = queries.size();
        int m = edgeList.size();
        
        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i);
        }
        
        sort(edgeList.begin(),edgeList.end(),comp);
        sort(queries.begin(),queries.end(),comp);
        
        vector<bool>answer(q,false);
        DSU obj(n);
        
        int ptr = 0;
        
        for(int i=0;i<q;i++){
            while(ptr < m && edgeList[ptr][2] < queries[i][2]){
                obj.Union(edgeList[ptr][0],edgeList[ptr][1]);
                ptr++;
            }
            answer[queries[i][3]] = obj.isSameLeader(queries[i][0],queries[i][1]);
        }
        return answer;
    }
};