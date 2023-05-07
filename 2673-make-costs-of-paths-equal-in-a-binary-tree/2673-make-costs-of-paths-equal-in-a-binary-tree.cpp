class Solution {
public:
    
    typedef long long ll;
    
    vector<vector<int>>graph;
    vector<ll>subtree;
    vector<ll>C;
    ll target;
    
    void precompute(int u,int p){
        subtree[u] = C[u];
        ll nbrMax = 0LL;
        for(int v:graph[u]){
            if(v==p) continue;
            precompute(v,u);
            nbrMax = max(nbrMax,subtree[v]);
        }
        subtree[u] += nbrMax;
    }
    
    void dfs(int u,int p,ll upperSum,ll &increment){
        upperSum += C[u];
        vector<ll>need;
        int child = 0;
        for(int v:graph[u]){
            if(v==p) continue;
            child++;
            need.push_back(target - (upperSum + subtree[v]));
        }
        if(child==0){
            increment += (target-upperSum);
            return;
        }
        else{
            ll minNeed = 1e15;
            for(ll &ele : need){
                minNeed = min(minNeed,ele);
            }
            upperSum += minNeed;
            increment += minNeed;
            for(int v:graph[u]){
                if(v==p) continue;
                dfs(v,u,upperSum,increment);
            }
            return;
        }
    }
    
    int minIncrements(int n, vector<int>& cost) {
        // Build The Tree
        graph.clear();
        subtree.clear();
        C.clear();
        graph.resize(n+1);
        subtree.resize(n+1,0LL);
        reverse(cost.begin(),cost.end());
        cost.push_back(0);
        reverse(cost.begin(),cost.end());
        for(int i=0;i<=n;i++){
            C.push_back((ll)cost[i]);
        }
        // for(int i=1;i<=n;i++){
        //     cout<<C[i]<<" ";
        // }cout<<"\n";
        
        for(int i=1;i<=n;i++){
            int left = (2*i);
            int right = (2*i + 1);
            if(left <= n){
                graph[i].push_back(left);
                graph[left].push_back(i);
            }
            if(right <= n){
                graph[i].push_back(right);
                graph[right].push_back(i);
            }
        }
        
        precompute(1,-1);
        target = subtree[1];
        // cout<<target<<"\n";
        ll inc = 0LL;
        
        dfs(1,-1,0LL,inc);
        return (int)inc;
        
    }
};