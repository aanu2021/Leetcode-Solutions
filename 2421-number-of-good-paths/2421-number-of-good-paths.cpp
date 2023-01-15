class Solution {
public:
    
    vector<int>Parent;
    vector<int>Rank;
    
    int find(int x){
        if(Parent[x] == x) return x;
        return Parent[x] = find(Parent[x]);
    }
    
    void Union(int x,int y){
        int lx = find(x);
        int ly = find(y);
        if(lx != ly){
            if(Rank[lx] < Rank[ly]){
                Parent[lx] = ly;
            }
            else{
                Parent[ly] = lx;
                if(Rank[lx] == Rank[ly]) Rank[lx]++;
            }
        }
    }
    
    int numberOfGoodPaths(vector<int>& value, vector<vector<int>>& edges) {
        int n = value.size();
        map<int,vector<int>>vals;
        map<int,vector<pair<int,int>>>adj;
        for(int i=0;i<n;i++){
            vals[value[i]].push_back(i);
        }
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[max(value[u],value[v])].push_back({u,v});
        }
        int ans = n;
        Parent.resize(n);
        Rank.resize(n);
        for(int i=0;i<n;i++){
            Parent[i] = i;
            Rank[i] = 1;
        }
        for(auto &x : adj){
            int currval = x.first;
            for(auto &y : x.second){
                Union(y.first,y.second);
            }
            map<int,int>cnt;
            for(auto &ele : vals[currval]){
                cnt[find(ele)]++;
            }
            for(auto &itr : cnt){
                int z = itr.second;
                ans += ((z*(z-1))/2);
            }
        }
        return ans;
    }
};