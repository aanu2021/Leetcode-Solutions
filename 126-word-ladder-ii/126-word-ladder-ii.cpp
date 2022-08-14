class Solution {
public:
    
    // These utility helps us to determine whether two different words can be the neighbour of each other or not.
    
    bool isNeighbour(string &s1,string &s2){
        
        int n=s1.length();
        
        int diff=0;
        
        for(int i=0;i<n;++i){
            
            if(s1[i]!=s2[i]){
                diff++;
            }
            
        }
        
        return diff==1;
        
    }
    
    
    void BFS(int src,vector<vector<int>>&graph,vector<vector<int>>&parent,int n){
        
        vector<int>dist(n,1e9);
        
        dist[src]=0;
        
        queue<int>q;
        
        q.push(src);
        
        // By default there is no parent of our source , as it is our starting point.
        
        parent[src]={-1};
        
        
        while(!q.empty()){
            
            int node=q.front();
            q.pop();
            
            for(int nbr:graph[node]){
                
                if(dist[nbr]>dist[node] + 1){
                    
                    q.push(nbr);
                    
                    dist[nbr]=dist[node] + 1;
                    
                    parent[nbr].clear();
                    
                    parent[nbr].push_back(node);
                    
                }
                
                else if(dist[nbr]==dist[node] + 1){
                    
                    parent[nbr].push_back(node);
                    
                }
                
            }
            
        }
        
        
    }
    
    
    void AllShortestPaths(int node,vector<vector<int>>&parent,vector<int>&path,vector<vector<int>>&allpath){
        
        if(node==-1){
            
            allpath.push_back(path);
            
            return;
            
        }
        
        for(int par:parent[node]){
            
            path.push_back(par);
            
            AllShortestPaths(par,parent,path,allpath);
            
            path.pop_back();
            
        }
        
    }
    
    
    vector<vector<string>> findLadders(string bW, string eW, vector<string>& wordList) {
        
        vector<vector<string>>ans;
        
        int n=wordList.size();
        
        
         int src=-1,dest=-1;
        
        for(int i=0;i<n;++i){
            
            if(wordList[i]==bW){
                
                src=i;
                
            }
            
            if(wordList[i]==eW){
                
                dest=i;
                
            }
            
        }
        
        
       // cout<<src<<" "<<dest<<"\n";
        
        // When the endWord is not found , then definitely there doesn't exist any path from beginWord to it.
        
        if(dest==-1){
            
            return ans;
            
        }
        
        // Same Logic goes here.
        
        if(src==-1){
            
            wordList.push_back(bW);
            
            src=n;
            
            n++;
            
        }
        
        
        vector<vector<int>>graph(n);
        
        vector<int>path;
        
        
        
        
        // Create a graph of words's indices , providing wordList[i] and wordList[j] are neighbour of each other.
        
        for(int i=0;i<n;++i){
            
            for(int j=i+1;j<n;++j){
                
                if(isNeighbour(wordList[i],wordList[j])){
                    
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                    
                }
                
            }
            
        }
        
        
        // Stores all the parent nodes of the current node.
        
        vector<vector<int>>parent(n);
        
       
        
        
        // Otherwise we have to find the parent-child relationship first using BFS traversal .
        
        BFS(src,graph,parent,n);
        
        
        // After formulating the parent array , now it is the time to explore all possible paths , but from destination node towards source node.
        
        vector<vector<int>>paths;
        
        AllShortestPaths(dest,parent,path,paths);
        
        cout<<paths.size()<<"\n";
        
        for(auto curr:paths){
            
            vector<string>currpath;
            
            int sz=curr.size();
            
            for(int i=0;i<sz-1;++i){
                
                currpath.push_back(wordList[curr[i]]);
                
            }
            
            reverse(currpath.begin(),currpath.end());
            
            currpath.push_back(wordList[dest]);
            
            ans.push_back(currpath);
            
        }
        
        return ans;
        
    }
};