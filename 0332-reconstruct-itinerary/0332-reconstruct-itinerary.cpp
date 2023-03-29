class Solution {
public:
    
    unordered_map<string,vector<string>>graph;
    vector<string>path;
    
    void dfs(string &node){
        while(graph[node].size() > 0){
            string nbr = graph[node].back();
            graph[node].pop_back();
            dfs(nbr);
        }
        path.push_back(node);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        for(int i=0;i<n;i++){
            graph[tickets[i][0]].push_back(tickets[i][1]);
        }
        for(auto &itr : graph){
            sort(itr.second.rbegin(),itr.second.rend());
        }
        string src = "JFK";
        dfs(src);
        reverse(path.begin(),path.end());
        return path;
    }
};