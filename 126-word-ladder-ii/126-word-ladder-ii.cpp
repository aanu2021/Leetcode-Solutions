class Solution {
public:

/*

        Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
        
        Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
        
        Explanation: There are 2 shortest transformation sequences:
        "hit" -> "hot" -> "dot" -> "dog" -> "cog"
        "hit" -> "hot" -> "lot" -> "log" -> "cog"
		
		comments are explained with this example*
*/    

//check two strings are neighbour i.e -> they should have only one difference
// if only one difference then it returns true
bool isNeighbour(string &a, string &b)
{
    
    if(a.size() != b.size())
    {
        return false;
    }
    int diff = 0;
    for(int i=0; i<a.size(); i++)
    {
        if(a[i] != b[i])            //if diff character increase the count by 1
        {
            diff++;
        }
    }
    // if diff was return true else false
    return diff == 1;
    
}

//create the parent array by using shortest path distance array
void BFS(vector<int> parent[], vector<vector<int>> &graph, int src, int n)
{
    // initially all nodes are infinity
    vector<int> dist(n, 1005);
    queue<int> q;
    
    //parent of src will be -1
    parent[src] = {-1};
    //starting with src node
    q.push(src);
    //dist of src will be 0
    dist[src] = 0;
    
    
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        
        
        for(auto u : graph[x])
        {
            //if u is reached with lesser distance, then update the parent array
            if(dist[u] > dist[x] + 1)
            {   
                dist[u] = dist[x] + 1;
                q.push(u);
                parent[u].clear();
                parent[u].push_back(x);
            }
            //if u is reached with same distance, then update the parent array (in qn, they aksed all the paths)
            else if(dist[u] == dist[x] + 1)
            {
                parent[u].push_back(x);
            }
        }
        
    }
    
    /*
        parent array after bfs function
    
      6 -> {3, 5}
      5 -> {4}
      3 -> {2}
      4 -> {1}
      2 -> {1}
      1 -> {0}
      0 -> {-1}
      
        
        
    */
    
}

// from the parent array it creates all the paths
void shortestPathDFS(int node,  vector<int> parent[], vector<vector<int>> &allPaths, vector<int> path)
{
    // if we raeched -1, then add the path to allPaths
    if(node == -1)
    {
        allPaths.push_back(path);
        return;
    }
    
    for(auto it : parent[node])
    {
        path.push_back(it);
        //recursive dfs function
        shortestPathDFS(it, parent, allPaths, path);
        //backtracking
        path.pop_back();
    }
    
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
{
    
    int n = wordList.size();
    
    int src = -1;
    int dest = -1;
    
    // storing the ans
    vector<vector<string>> ans;
    
    
    for(int i=0; i<n; i++)
    {
        //finding the src index
        if(wordList[i] == beginWord)
        {
            src = i;
        }
        //finding the destination index
        else if(wordList[i] == endWord)
        {
            dest = i;
        }
    }
    
    //if destination string was not found, return empty array
    if(dest == -1)
    {
        return ans;
    }
    
    //if sourec string was not found, then add it in the first position, so update no of elements(n) and destination index
    if(src == -1)
    {
        
        wordList.emplace(wordList.begin(), beginWord);
        src = 0;        //src index will be 0
        dest++;
        n++;
        
    }
    
    vector<vector<int>> graph(n, vector<int>());    // graph, which points the word which has only one difference   
    /*(i.e)
    
    words = ["hit", hot","dot","dog","lot","log","cog"]
    index =   0      1     2     3     4      5    6  
    
    hit - {hot}     => {0}
    hot - {hit, dot, lot}   => {0, 2, 4}
    dot - {dog, hot, lot}   => {1, 3, 4}
    dog - {2, 5, 6}
    lot - {1, 2,5}
    log - {3, 4, 6}
    cog - {3, 5}
    
    */
    vector<vector<int>> allPaths;   //stores all the paths, but only the indexes => should be converted from index to strings
    vector<int> parent[n];          // stores the parent of all nodes
    /*
        
        see in bfs function
    
    */
    
    
    vector<int> path;   //stores every single path (like temporary array)
    
    
    // to create a graph
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(isNeighbour(wordList[i], wordList[j]))
            {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    
    BFS(parent, graph, src, n);
    shortestPathDFS(dest, parent, allPaths, path);
    
    
    /*
    
        AllPaths => {{3,2,1,0,-1}, {5,4,1,0,-1}}
    
    */
    
    
    for(auto paths : allPaths)
    {
        
        vector<string> stringPath;
        
        int size = paths.size();
        
        // paths => {3,2,1,0,-1}
        //-1 should not be accessed so size - 1
        // stringPath = {dog, dot, hot, hit}
        
        for(int i=0; i<size-1; i++)
        {
            stringPath.push_back(wordList[paths[i]]);
        }
        //reverse the stringPath
        // stringPath = {hit, hot, dot, dog}
        reverse(stringPath.begin(), stringPath.end());
        
        /*
                for(int i = size-2; i>=0; i--)
                {
                    stringPath.push_back(wordList[paths[i]]);
                }
        */
        
        // add the destination string
        //stringPath => {hit, hot, dot, dog, cog}
        stringPath.push_back(wordList[dest]);
        
        //now add it to the ans
        ans.push_back(stringPath);
        
    }
    
    return ans;
    //ans => {{"hit","hot","dot","dog","cog"}, {"hit","hot","lot","log","cog"}}
}
};