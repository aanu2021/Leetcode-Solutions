class Solution {
public:
    
    int maxLen=0;
    
    int dfs(int u,vector<vector<int>>&graph,string &col){
        
        int internal_chain = 1;
        
        int longest_chain = 1;
        
        vector<int>v;
        
        for(int v1:graph[u]){
            
            int val = dfs(v1,graph,col);
            
            if(col[v1]!=col[u]){
                
                v.push_back(val);
                
            }
            
        }
        
        sort(v.rbegin(),v.rend());
        
        int sz=v.size();
        
        if(sz>0){
            
            internal_chain+=v[0];
            longest_chain+=v[0];
            
        }
        
        if(sz>1){
            
            internal_chain+=v[1];
            
        }
        
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