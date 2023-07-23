class Solution {
public:
    
    typedef long long ll;
    
    vector<vector<int>>graph;
    unordered_map<int,int>mp;
    
    ll dfs(string &s,int u,int mask,int p){
        
        ll cnt = 0LL;
        
        if(u){
            mask ^= (1<<(s[u]-'a'));
            for(int bit=0;bit<26;bit++){
                int cmask = (1<<bit);
                if(mp.find(mask^cmask) != mp.end()){
                    cnt += mp[mask^cmask];
                }
            }
            cnt += mp[mask];
            mp[mask]++;
        }
        
        for(int v:graph[u]){
            cnt += dfs(s,v,mask,u);
        }
        
        return cnt;
        
    }
    
    long long countPalindromePaths(vector<int>& parent, string s) {
        
        int n = s.length();
        
        mp.clear();
        graph.clear();
        
        mp[0] = 1;
        graph.resize(n);
        
        for(int i=1;i<n;i++){
            graph[parent[i]].push_back(i);
        }
        
        return dfs(s,0,0,-1);
    }
};

/*

have[0] = 1
have[1] = 1    
have[4] = 1
have[5] = 2    
have[6] = 1    
    
1 + 1 + 1 + 1 + 1 + 1 + 1 + 1   =   8  
      
mask = 5 

*/