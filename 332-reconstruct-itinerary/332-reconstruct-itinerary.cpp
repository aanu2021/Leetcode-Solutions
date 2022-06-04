class Solution {
public:
    
    struct comp{
      
        bool operator()(const string&s1,const string&s2){
            return s1 > s2;
        }
        
    };
    
    vector<string>result;
    
    unordered_map<string,priority_queue<string,vector<string>,comp>>mp;
    
    void dfs(string str){
        
        auto &curr=mp[str];
        
        while(!curr.empty()){
            
            string nbr=curr.top();
            curr.pop();
            
            dfs(nbr);
            
        }
        
        result.push_back(str);
        
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        for(int i=0;i<tickets.size();i++){
            mp[tickets[i][0]].push(tickets[i][1]);
        }
        
        dfs("JFK");
        
        reverse(result.begin(),result.end());
        
        return result;
        
    }
};