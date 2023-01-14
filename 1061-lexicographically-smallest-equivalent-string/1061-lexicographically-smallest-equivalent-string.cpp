class Solution {
public:
    
    vector<vector<int>>adj;
    vector<int>vis;
    vector<int>component;
    
    void DFS(int u,int &minele){
        vis[u] = 1;
        component.push_back(u);
        minele = min(minele,u);
        for(int v=0;v<26;v++){
            if(vis[v]) continue;
            if(adj[u][v] == 0) continue;
            DFS(v,minele);
        }
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        adj = vector<vector<int>>(26,vector<int>(26,0));
        vis = vector<int>(26,0);
        for(int i=0;i<n;i++){
            adj[s1[i]-'a'][s2[i]-'a'] = 1;
            adj[s2[i]-'a'][s1[i]-'a'] = 1;
        }
        vector<int>minComp(26);
        for(int i=0;i<26;i++){
            minComp[i] = i;
        }
        for(int i=0;i<26;i++){
            if(vis[i]) continue;
            int j = i;
            int minele = 26;
            component.clear();
            DFS(j,minele);
            for(int &ele : component){
                minComp[ele] = min(minComp[ele],minele);
            }
        }
        for(int i=0;i<baseStr.length();i++){
            baseStr[i] = (char)(minComp[baseStr[i]-'a'] + 'a');
        }
        return baseStr;
    }
};