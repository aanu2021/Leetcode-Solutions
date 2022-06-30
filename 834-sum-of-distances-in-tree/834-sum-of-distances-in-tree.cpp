class Solution {
public:
    
    typedef long long ll;
    
    vector<vector<ll>>graph;

    ll N;

    vector<ll>countsub;

    vector<ll>distsub;

    vector<int>ans;
    
    
    void preprocessing(ll u,ll p){

        countsub[u]=1;
        distsub[u]=0;

        for(ll v:graph[u]){

            if(v!=p){

                preprocessing(v,u);

                countsub[u]+=countsub[v];

                distsub[u]+=countsub[v]+distsub[v];

            }

        }

    }


    void func(ll u,ll p,ll par_ans){

        ll node_cnt_subtree=countsub[u];

        ll dist_in_subtree=distsub[u];

        ans[u]=dist_in_subtree + (N-node_cnt_subtree) + par_ans;

        for(ll v:graph[u]){

            if(v!=p){

                ll partial_ans = ans[u] - distsub[v] - countsub[v];

                func(v,u,partial_ans);

            }

        }

    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        N=n;
        
        graph.resize(N);
    
        countsub.resize(N,0);

        distsub.resize(N,0);

        ans.resize(N,0);
        
        for(ll i=0;i<edges.size();++i){
            
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
            
        }
        
        preprocessing(0,-1);
    
        func(0,-1,0);
        
        return ans;
        
        
    }
};