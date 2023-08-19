class DSU{
  
    private:
    
    int n;
    vector<int>Parent;
    vector<int>Rank;
    
    public:
    
    DSU(int n){
        this->n = n;
        Parent.resize(n);
        Rank.resize(n);
        for(int i=0;i<n;i++){
            Parent[i] = i;
            Rank[i] = 1;
        }
    }
    
    int find(int x){
        if(Parent[x] == x) return x;
        return Parent[x] = find(Parent[x]);
    }
    
    bool Union(int x,int y){
        int lx = find(x);
        int ly = find(y);
        if(lx != ly){
            if(Rank[lx] > Rank[ly]){
                Parent[ly] = lx;
            }
            else{
                Parent[lx] = ly;
                if(Rank[lx] == Rank[ly]){
                    Rank[lx]++;
                }
            }
            return true;
        }
        
        else{
            return false;
        }
    }
    
    bool isConnected(){
        for(int i=0;i<n;i++){
            int p = find(i);
            int rp = find(0);
            if(p != rp){
                return false;
            }
        }
        return true;
    }
    
};

class Solution {
public:
    
    bool static comp(const vector<int>&x,const vector<int>&y){
        return x[2] < y[2];
    }
    
    int findMST(vector<vector<int>>&edges,int n,int exclude,int pref){
        int mstSum = 0;
        int m = edges.size();
        
        DSU obj(n);
        
        for(int i=0;i<m;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            if(i==pref){
                mstSum += w;
                obj.Union(u,v);
            }
        }
        
        for(int i=0;i<m;i++){
            if(i==pref || i==exclude) continue;
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            if(obj.Union(u,v)){
                mstSum += w;
            }
        }
        
        if(obj.isConnected() == false) return 1e9;
        else return mstSum;
        
    }
    
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        
        int m = edges.size();
        
        for(int i=0;i<m;i++){
            edges[i].push_back(i);
        }
        
        sort(edges.begin(),edges.end(),comp);
        
        vector<int>critical(m,0);
        vector<int>not_part_mst(m,0);
        
        int MSTSum = findMST(edges,n,-1,-1);
        
        // cout<<MSTSum<<"\n";
        
        for(int i=0;i<m;i++){
            int currSum = findMST(edges,n,i,-1);
            // cout<<currSum<<"\n";
            if(currSum > MSTSum) critical[edges[i][3]] = 1;
        }
        
        for(int i=0;i<m;i++){
            if(critical[edges[i][3]]==1) continue;
            int currSum = findMST(edges,n,-1,i);
            if(currSum > MSTSum) not_part_mst[edges[i][3]] = 1;
        }
        
        vector<vector<int>>answer(2);
        
        for(int i=0;i<m;i++){
            if(critical[i]==1) answer[0].push_back(i);
        }
        for(int i=0;i<m;i++){
            if(not_part_mst[i] == 0 && critical[i]==0) answer[1].push_back(i);
        }
        
        return answer;
        
    }
};