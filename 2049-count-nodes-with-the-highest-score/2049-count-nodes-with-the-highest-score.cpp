class Solution {
public:
    
    typedef long long ll;
    
    int N;
    
    vector<vector<int>>graph;
    
    vector<ll>score;
    
    vector<int>count_sub;
    
    
    void preprocessing(int u,int p){
       
        count_sub[u]=1;
        
        for(int v:graph[u]){
            
            if(v!=p){
                
                preprocessing(v,u);
                
                count_sub[u]+=count_sub[v];
                
            }
            
        }
        
    }
    
    
    void func(int u,int p){
        
        int nodes_in_subtree=count_sub[u];
        
        int upper_nodes=max(1,(N-count_sub[u]));
        
        int left=-1,right=-1;
        
        for(int v:graph[u]){
            
            if(v!=p){
                
                if(left==-1){
                    
                    left=count_sub[v];
                    
                }
                
                else if(left!=-1){
                    
                    right=count_sub[v];
                    
                }
                
                func(v,u);
                
            }
            
        }
        
        left=max(left,1);
        
        right=max(right,1);
        
        ll curr_score=((ll)left*(ll)right*(ll)upper_nodes);
        
        score[u]=curr_score;
        
    }
    
    
    int countHighestScoreNodes(vector<int>& parent) {
        
        int n=parent.size();
        
        N=n;
        
        graph.resize(n);
        
        score.resize(n,0LL);
        
        count_sub.resize(n,0);
        
        
        for(int i=1;i<parent.size();++i){
            graph[parent[i]].push_back(i);
        }
        
        preprocessing(0,-1);
        
        func(0,-1);
        
        // for(ll i=0;i<n;i++){
        //     cout<<score[i]<<" ";
        // }cout<<"\n";
        
        
        sort(score.begin(),score.end());
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            if(score[i]==score.back()){
                ans++;
            }
        }
        
        return ans;
        
    }
};