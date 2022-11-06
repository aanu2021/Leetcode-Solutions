class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++){
            adj[arr[i]].push_back(i);
        }
        vector<bool>visited(n,false);
        queue<int>q;
        q.push(0);
        visited[0] = true;
        int lvl = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                
                int node = q.front();
                q.pop();
                
                if(node==n-1) return lvl;
                
                if(node-1>=0 && visited[node-1]==false){
                    q.push(node-1);
                    visited[node-1] = true;
                }
                
                if(node+1<n && visited[node+1]==false){
                    q.push(node+1);
                    visited[node+1] = true;
                }
                
                while(adj[arr[node]].size()){
                    
                    int j = adj[arr[node]].back();
                    adj[arr[node]].pop_back();
                    
                    if(visited[j]==false){
                        q.push(j);
                        visited[j] = true;
                    }
                    
                }
                
            }
            lvl++;
        }
        return -1;
    }
};