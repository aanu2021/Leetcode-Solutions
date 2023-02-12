class Solution {
public:
    
    typedef long long ll;
    
    vector<vector<int>>graph;
    vector<int>subtree;
    
    void precompute(int u,int p){
        subtree[u]++;
        for(int v:graph[u]){
            if(v==p) continue;
            precompute(v,u);
            subtree[u] += subtree[v];
        }
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        n++;
        graph = vector<vector<int>>(n);
        subtree = vector<int>(n,0);
        for(int i=0;i<roads.size();i++){
            graph[roads[i][0]].push_back(roads[i][1]);
            graph[roads[i][1]].push_back(roads[i][0]);
        }
        precompute(0,-1);
        ll ans = 0LL;
        for(int i=1;i<n;i++){
            ans += (ll)(subtree[i]/seats);
            if(subtree[i]%seats){
                ans++;
            }
        }
        return ans;
    }
};