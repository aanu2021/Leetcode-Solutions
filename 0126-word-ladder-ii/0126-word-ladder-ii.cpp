class Solution {
public:
    
    bool isMatch(string &s1,string &s2){
        int n = s1.length();
        int diff = 0;
        for(int i=0;i<n;i++){
            if(s1[i] != s2[i]) diff++;
        }
        return diff==1;
    }
    
    void BFS(int src,int n,vector<vector<int>>&graph,vector<vector<int>>&parent){
        
        vector<int>dist(n,1e9);
        dist[src] = 0;
        parent[src].push_back(-1);
        queue<int>q;
        q.push(src);
        while(!q.empty()){
            int node = q.front(); q.pop();
            for(int nbr:graph[node]){
                if(dist[nbr] > 1 + dist[node]){
                    dist[nbr] = 1 + dist[node];
                    parent[nbr].push_back(node);
                    q.push(nbr);
                }
                else if(dist[nbr] == 1 + dist[node]){
                    parent[nbr].push_back(node);
                }
            }
        }
        
    }
    
    void DFS(int node,int n,vector<vector<int>>&parent,vector<int>&path,vector<vector<int>>&allPath){
        
        if(node == -1){
            allPath.push_back(path);
            return;
        }
        
        for(int par : parent[node]){
            path.push_back(par);
            DFS(par,n,parent,path,allPath);
            path.pop_back();
        }
        
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int src = -1;
        int dest = -1;
        int n = wordList.size();
        for(int i=0;i<wordList.size();i++){
            if(wordList[i]==endWord){
                dest = i;
                break;
            }
        }
        if(dest == -1) return {};
        for(int i=0;i<wordList.size();i++){
            if(wordList[i]==beginWord){
                src = i;
                break;
            }
        }
        if(src == -1){
            wordList.push_back(beginWord);
            src = n;
            n++;
        }
        
        vector<vector<int>>graph(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isMatch(wordList[i],wordList[j])){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        
        vector<vector<int>>parent(n);
        BFS(src,n,graph,parent);
        
        vector<vector<int>>allPath;
        vector<int>path;
        DFS(dest,n,parent,path,allPath);
        
        // for(int i=0;i<allPath.size();i++){
        //     for(int j=0;j<allPath[i].size();j++){
        //         if(allPath[i][j]!=-1){
        //             cout<<wordList[allPath[i][j]]<<" ";
        //         }
        //     }cout<<"\n";
        // }
        
        vector<vector<string>>ans;
        
        for(int i=0;i<allPath.size();i++){
            vector<string>currPath;
            allPath[i].pop_back();
            currPath.push_back(wordList[dest]);
            for(int j=0;j<allPath[i].size();j++){
                currPath.push_back(wordList[allPath[i][j]]);
            }
            reverse(currPath.begin(),currPath.end());
            ans.push_back(currPath);
        }
        
        return ans;
        
    }
};