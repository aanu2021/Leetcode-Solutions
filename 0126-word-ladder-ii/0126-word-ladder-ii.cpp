class Solution {
public:
    
    vector<vector<string>>ans;
    
    bool isNeighbour(string &s1,string &s2){
        int n = s1.length();
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                cnt++;
            }
        }
        return cnt==1;
    }
    
    void BFS(int src,int n,vector<vector<int>>&graph,vector<vector<int>>&parent){
        
        queue<int>q;
        q.push(src);
        
        vector<int>dist(n,1e9);
        dist[src] = 0;
        
        parent[src].push_back(-1);
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            for(int nbr:graph[node]){
                
                if(dist[nbr] > dist[node] + 1){
                    
                    dist[nbr] = dist[node] + 1;
                    q.push(nbr);
                    parent[nbr].push_back(node);
                    
                }
                
                else if(dist[nbr] == dist[node] + 1){
                    
                    parent[nbr].push_back(node);
                    
                }
                
            }
            
        }
        
    }
    
    void DFS(int node,vector<vector<int>>&parent,vector<int>&path,vector<vector<int>>&allPaths){
        
        if(node==-1){
            allPaths.push_back(path);
            return;
        }
        
        for(int nbr:parent[node]){
            
            path.push_back(nbr);
            
            DFS(nbr,parent,path,allPaths);
            
            path.pop_back();
            
        }
        
    }
    
    vector<vector<string>> findLadders(string bW, string eW, vector<string>& wordList) {
        
        int n = wordList.size();
        
        int src=-1,dest=-1;
        
        for(int i=0;i<n;i++){
            if(wordList[i]==bW){
                src=i;
            }
            if(wordList[i]==eW){
                dest=i;
            }
        }
        
        if(dest==-1){
            return ans;
        }
        
        if(src==-1){
            src=n;
            wordList.push_back(bW);
            n++;
        }
        
        vector<vector<int>>graph(n);
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isNeighbour(wordList[i],wordList[j])){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        
        vector<vector<int>>parent(n);
        
        BFS(src,n,graph,parent);
        
        vector<vector<int>>allPaths;
        
        vector<int>path;
        
        DFS(dest,parent,path,allPaths);
        
        for(auto &paths:allPaths){
            
            int sz = paths.size();
            
            vector<string>curr_path;
            
            for(int i=0;i<sz-1;i++){
                curr_path.push_back(wordList[paths[i]]);
            }
            
            reverse(curr_path.begin(),curr_path.end());
            curr_path.push_back(eW);
           // reverse(curr_path.begin(),curr_path.end());
            
            ans.push_back(curr_path);
            
        }
        
        return ans;
        
    }
};