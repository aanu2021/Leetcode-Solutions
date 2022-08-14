class Solution {
public:
    
    // Check whether two strings are neighbour to each other , by checking only the different characters at each index.
    
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
        
        // dist[i] --> shortest distance of node i from node src
        
        vector<int>dist(n,1e9);
        
        dist[src]=0;
        
        /* Base Case --> for the src node , there is no node 
        possible which can be parent of it , therefore just assign
        an offset value as its parent node.*/
        
        parent[src].push_back(-1);
        
        
        // Queue DS will surely the best to do a BFS traversal
        
        queue<int>q;
        
        q.push(src);
        
        
        while(!q.empty()){
            
            int node=q.front();
            q.pop();
            
            // Explore all its potential neighbouring nodes.
            
            for(int nbr:graph[node]){
                
                if(dist[nbr] > dist[node] + 1){
                    
                    dist[nbr] = dist[node] + 1;
                    q.push(nbr);
                    parent[nbr].clear();
                    parent[nbr].push_back(node);
                    
                }
                
                else if(dist[nbr] == dist[node] + 1){
                    
                    parent[nbr].push_back(node);
                    
                }
                
            }
            
        }
        
        /* Finally we are done with the BFS traversal and now we
        have all the required relations between a node and its
        immediate parents , which will be a part of atleast one 
        shortest path.*/
        
    }
    
    
    
    void DFS(int node,vector<vector<int>>&parent,vector<int>&path,vector<vector<int>>&allpath){
        
        /* i.e. we able to reach the parent node of the src node,
        that is set to (-1) previously , for now include it in our 
        path , in future in order to calculate the words we will 
        not gonna count it.*/
        
        if(node==-1){
            
            allpath.push_back(path);
            return;
            
        }
        
        
        // Explore all its parent nodes.
        
        for(int par:parent[node]){
            
            path.push_back(par);
            
            DFS(par,parent,path,allpath);
            
            path.pop_back();
            
        }
        
    }
    
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        /* 
        
        As all the strings in wordList dictionary unique to
        each other , therefore it is efficient to access them by
        there indices , by doing these there is no need to store
        map<string,map<string,int>> kind of data structure which
        is space inefficient as well as increase the time 
        complexity indirectly in case of find or erase operations. */
        
        int src=-1,dest=-1;
        
        int n=wordList.size();
        
        for(int i=0;i<n;++i){
            
            if(wordList[i]==beginWord){
                
                src=i;
                
            }
            
            if(wordList[i]==endWord){
                
                dest=i;
                
            }
            
        }
        
        
        /* Data structure needed to store all the valid yet 
           shortest paths from src to dest node.*/
        
        vector<vector<string>>ans;
        
        
        /* Edge Case : When destination string is not found inside
        the wordList dictionary.Then there is no path exist from 
        src to dest. */
        
        if(dest==-1){
            
            return ans;
            
        }
        
        
        /*
        
         Edge Case : When src node is not found inside the given
         dictionary , then we need to insert it inside the 
         dictionary and as a result total size (n) of the 
         dictionay gets increased.
        
        */
        
        
        if(src==-1){
            
            wordList.push_back(beginWord);
            src=n;
            n++;
            
        }
        
        
        /* These Data Structure will store all the possible parent
        nodes of the current node , which are required to build 
        any of the the shortest path */
        
        vector<vector<int>>parent(n);
        
        
        /*
        
        These DS will store the inner links b/w two words , if 
        they are differing only in one character.
        
        */
        
        vector<vector<int>>graph(n);
        
        
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                if(isNeighbour(wordList[i],wordList[j])){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        
        
        
        /* Now call the BFS utility function , that will help us 
        to explore all the shortest paths from src to dest node ,
        by maintaining the relationship b/w current node and its 
        immediate parents . As we want to explore all the paths ,
        so it is mandatory to access its parent , then parent of 
        its parent  , and all the way upto src . Here we access 
        the paths from dest to src  , you can also do the reverse
        of it , if you want.*/
        
        
        BFS(src,graph,parent,n);
        
        
        /*
        
        Once we have all the relations in our pouch , all we need
        to do simply explore all the paths recursively , and for 
        doing these DFS traversal is most efficient one.
        
        */
        
        /*
        
        As we discussed previously , we are start our journey from 
        the end(i.e. the dest node) and keep exploring all the 
        paths upto src node. 
        
        */
        
        /*
        
         To store all the paths's nodes we need to maintain a DS ,
         that will store them , and again a DS that will store all 
         the paths at the end of DFS traversal.
        
        */
        
        vector<int>path;
        
        vector<vector<int>>allpath;
        
        
        DFS(dest,parent,path,allpath);
        
        
        /*
        
    Now at that moment we have all the shortest paths with us.
        
        */
        
        
        for(auto paths:allpath){
            
            vector<string>current_path;
            
            int size=paths.size();
            
            for(int i=0;i<size-1;++i){
                
                current_path.push_back(wordList[paths[i]]);
                
            }
            
            reverse(current_path.begin(),current_path.end());
            
            current_path.push_back(endWord);
            
            ans.push_back(current_path);
            
        }
        
        
        return ans;
        
        
       /*
        
        
        wordLen --> wordList.size();
        wL      --> wordList[i].length();
        E       --> Total number of edges in graph
        
        
        
        Individual Time Complexities :-->
        
        
        O(wordLen) --> For determining src node and dest node.
        
        O(wordLen*wordLen*wL)  --> For precomputing the 
        relationship between each word.
        
        O(wordLen + E) --> For computing BFS traversal
        
        O(wordLen*E)  --> For completing the DFS traversal
        
        
        Time Complexity : summation of all the items 
        
       
       */
        
        
    }
    
    
};