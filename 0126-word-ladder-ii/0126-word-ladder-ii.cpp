class Solution {
public:
    
    bool isMatch(string &s1,string &s2){
        int n = s1.length();
        int diff = 0;
        for(int i=0;i<n;i++){
            if(s1[i] != s2[i]) diff++;
        }
        return diff == 1;
    }
    
    void BFS(int src,int dest,int n,vector<vector<int>>&graph,vector<vector<int>>&parent){
        
        queue<int>q;
        q.push(src);
        
        vector<int>dist(n,1e9);
        dist[src] = 0;
        parent[src] = {-1};
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int nbr : graph[node]){
                if(dist[nbr] > dist[node] + 1){
                    dist[nbr] = dist[node] + 1;
                    parent[nbr].push_back(node);
                    q.push(nbr);
                }
                else if(dist[nbr] == dist[node] + 1){
                    parent[nbr].push_back(node);
                }
            }
        }
        
    }
    
    void DFS(int node,int n,vector<vector<int>>&parent,vector<int>&path,vector<vector<int>>&allPath){
        
        if(node==-1){
            allPath.push_back(path);
            return;
        }
        for(int nbr : parent[node]){
            path.push_back(nbr);
            DFS(nbr,n,parent,path,allPath);
            path.pop_back();
        }
        
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        int n = wordList.size();
        
        int srcIdx = -1, destIdx = -1;
        for(int i=0;i<wordList.size();i++){
            if(wordList[i] == endWord){
                destIdx = i;
            }
            if(wordList[i] == beginWord){
                srcIdx = i;
            }
        }
        
        if(destIdx == -1) return {};
        if(srcIdx == -1){
            srcIdx = n;
            n++;
            wordList.push_back(beginWord);
        }
        
        vector<vector<int>>graph(n);
        vector<vector<int>>parent(n);
        vector<vector<string>>answer;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isMatch(wordList[i],wordList[j])){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        
        BFS(srcIdx,destIdx,n,graph,parent);
        
        // for(int i=0;i<n;i++){
        //     cout<<wordList[i]<<"=>";
        //     for(int j=0;j<parent[i].size();j++){
        //         if(parent[i][j]==-1) continue;
        //         cout<<wordList[parent[i][j]]<<" ";
        //     }cout<<"\n";
        // }
        
        vector<int>path;
        vector<vector<int>>allPath;
        
        DFS(destIdx,n,parent,path,allPath);
        
        for(int i=0;i<allPath.size();i++){
            vector<string>currPath;
            allPath[i].pop_back();
            currPath.push_back(endWord);
            for(int j=0;j<allPath[i].size();j++){
                currPath.push_back(wordList[allPath[i][j]]);
            }
            reverse(currPath.begin(),currPath.end());
            answer.push_back(currPath);
        }
        
        return answer;
        
    }
};

/*

src = hit
des = cog

hit hot dot dog lot log cog
0   1    2   3   4   5   6
    
0 -> [1]
1 -> [0,2,4]
2 -> [1,3,4]
3 -> [2,5,6]
4 -> [1,2,5]
5 -> [3,4,6]
6 -> [3,5]

0   
1
2 4
3 5
6
    
dist[i] = shortest distance of the i-th word from src.
now we have to backtrack from the endWord 
and create edges from the current word to immediately previous word , which can lead us to the src word.
    
 After that , we have to do a simple DFS traversal from the endWord using all the previously created edges during bfs traversal , and add them in our resultant container.   

*/