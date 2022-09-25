class Solution {
public:
    
    int maxLen=0;
    
    int dfs(int u,vector<vector<int>>&graph,string &col){
        
        int internal_chain = 1;
        
        int longest_chain = 1;
        
        int cand1 = 0, cand2 = 0;
        
        for(int v:graph[u]){
            
            int val = dfs(v,graph,col);
            
            if(col[v]!=col[u]){
                
                if(cand1==0){
                    
                    cand1 = val;
                    
                }
                
                else if(cand1 < val){
                    
                    cand2 = cand1;
                    cand1 = val;
                    
                }
                
                else if(cand2 < val){
                    
                    cand2 = val;
                    
                }
                
            }
            
        }
        
            
            internal_chain+=cand1;
            longest_chain+=cand1;
       
            internal_chain+=cand2;
     
            maxLen=max(maxLen,max(internal_chain,longest_chain));

            return longest_chain;
        
    }
    
    int longestPath(vector<int>& parent, string s) {
        
        int n=s.length();
        
        vector<vector<int>>graph(n);
        
        for(int i=1;i<n;++i){
            graph[parent[i]].push_back(i);
        }
        
        int ans = dfs(0,graph,s);
        
        return maxLen;
        
    }
};