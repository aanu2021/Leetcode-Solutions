class Solution {
public:
    
    typedef long long ll;
    
    vector<vector<int>>graph;
    
    vector<int>subtree_count;
    
    int N;
    
    vector<ll>curr_node_score;
    
    
    void precompute(int u){
        
          subtree_count[u]=1;
        
          for(int v:graph[u]){

              precompute(v);

              subtree_count[u]+=subtree_count[v];

          }
        
    }
    
    
    void func(int u){
        
        ll upper_nodes=max(1LL,(ll)(N-subtree_count[u]));
        
        ll sz=graph[u].size();
        
        ll left_nodes=1LL,right_nodes=1LL;
        
        if(sz>0){
            
            left_nodes=max(left_nodes,(ll)subtree_count[graph[u][0]]);
            
        }
        
        if(sz>1){
            
            right_nodes=max(right_nodes,(ll)subtree_count[graph[u][1]]);
            
        }
        
        ll curr_scores=(upper_nodes*left_nodes*right_nodes);
        
        curr_node_score[u]=curr_scores;
        
        
        for(int v:graph[u]){
            
            func(v);
            
        }
        
    }
    
    
    int countHighestScoreNodes(vector<int>& parent) {
        
        int n=parent.size();
        
        
        graph.resize(n);
        
        subtree_count.resize(n,0);
        
        curr_node_score.resize(n,0LL);
        
        
        for(int i=1;i<n;++i){
            
            graph[parent[i]].push_back(i);
            
        }
        
        
        precompute(0);
        
        N=subtree_count[0];
        
        
        func(0);
        
        
        
        ll max_score=*max_element(curr_node_score.begin(),curr_node_score.end());
        
        
        int highest_score_nodes=0;
            
        
        for(int i=0;i<n;++i){
            
            if(curr_node_score[i]==max_score){
                
                highest_score_nodes++;
                
            }
            
        }
        
        return highest_score_nodes;
        
    }
};