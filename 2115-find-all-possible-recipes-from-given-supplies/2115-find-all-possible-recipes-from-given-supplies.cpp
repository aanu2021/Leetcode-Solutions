class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ing, vector<string>& supplies) {
        
        set<string>visited;
        
        map<string,int>indegree;
        
        map<string,int>present;
        
        map<string,vector<string>>graph;
        
        int n=recipes.size();
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<ing[i].size();j++){
                
                graph[ing[i][j]].push_back(recipes[i]);
                
                indegree[recipes[i]]++;
                
            }
            
            present[recipes[i]]++;
            
        }
        
        
        queue<string>q;
        
        for(string str:supplies){
            q.push(str);
        }
        
        while(!q.empty()){
            
            auto curr=q.front();
            q.pop();
            
            if(visited.find(curr)!=visited.end()){
                continue;
            }
            
            visited.insert(curr);
            
            for(string str:graph[curr]){
                
                indegree[str]--;
                
                if(indegree[str]==0){
                    q.push(str);
                }
                
            }
            
        }
        
        
        vector<string>ans;
        
        for(string str:visited){
            
            if(present[str]!=0){
                ans.push_back(str);
            }
            
        }
        
        return ans;
        
    }
};