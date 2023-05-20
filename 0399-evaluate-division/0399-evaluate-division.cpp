class Solution {
public:
    
    unordered_map<string,vector<string>>graph;
    unordered_map<string,double>MAP;
    unordered_map<string,int>visited;
    
    void dfs(string start,string end,bool &found,double &val){
       
        if(visited[start]) return;
        visited[start] = 1;
        
        for(string &child : graph[start]){
            
            string rel = start + "->" + child;
            val *= MAP[rel];
            
            if(child == end){
                found = true;
                return;
            }
            
            dfs(child,end,found,val);
            
            if(found){
                return;
            }
            else{
                val /= MAP[rel];
            }
            
        }
        
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        graph.clear();
        MAP.clear();
        visited.clear();
        
        int n = equations.size();
        int q = queries.size();
        
        vector<double>answer(q,-1.0);
        
        for(int i=0;i<n;i++){
            
            string left = equations[i][0];
            string right = equations[i][1];
            
            string rel = left + "->" + right;
            string rev_rel = right + "->" + left;
            
            graph[left].push_back(right);
            graph[right].push_back(left);
            
            MAP[rel] = values[i];
            MAP[rev_rel] = 1.0/values[i];
            
        }
        
        for(int i=0;i<q;i++){
            
            string left = queries[i][0];
            string right = queries[i][1];
            
            if(graph.find(left) == graph.end() || graph.find(right) == graph.end())
            {
                // cout<<"dada\n";
                answer[i] = -1.0;
                continue;
            }    
            else{
                if(left == right){
                    answer[i] = 1.0;
                    continue;
                }
                else{
                    
                    bool found = false;
                    double val = 1.0;
                    visited.clear();
                    
                    dfs(left,right,found,val);
                    
                    if(found){
                        answer[i] = val;
                    }
                    else{
                        answer[i] = -1.0;
                    }
                    
                    continue;
                }
            }
        }
        
        return answer;
        
    }
};