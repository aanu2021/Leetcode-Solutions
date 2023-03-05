class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n==1) return 0;
        queue<int>q;
        vector<int>visited(n,0);
        q.push(0);
        visited[0] = 1;
        unordered_map<int,vector<int>>indices;
        for(int i=0;i<n;i++){
            indices[arr[i]].push_back(i);
        }
        int lvl = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int node = q.front();
                q.pop();
                if(node == n-1){
                    return lvl;
                }
                if(node - 1 >= 0 && visited[node-1] == 0){
                    q.push(node-1);
                    visited[node-1] = 1;
                }
                if(node + 1 < n && visited[node+1] == 0){
                    q.push(node+1);
                    visited[node+1] = 1;
                }
                for(int j : indices[arr[node]]){
                    if(visited[j]) continue;
                    visited[j] = 1;
                    q.push(j);
                }
                indices[arr[node]].clear();
            }
            lvl++;
        }
        return -1;
    }
};