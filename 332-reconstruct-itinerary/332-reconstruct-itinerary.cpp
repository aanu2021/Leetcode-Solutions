class Solution {
public:
    
   
    
    vector<string>result;
    
    unordered_map<string,vector<string>>graph;
    
    void dfs(string str){
        
        auto &curr=graph[str];
        
        while(curr.size()>0){
            
            string nbr=curr.back();
            curr.pop_back();
            
            dfs(nbr);
            
        }
        
        result.push_back(str);
        
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        for(int i=0;i<tickets.size();i++){  
            graph[tickets[i][0]].push_back(tickets[i][1]);
        }
        
        for(auto&itr:graph){
            sort(itr.second.rbegin(),itr.second.rend());
        }
        
        dfs("JFK");
        
        reverse(result.begin(),result.end());
        
        return result;
        
    }
};