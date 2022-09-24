class Solution {
public:
    
    vector<bool>visited;
    
    void dfs(int u,vector<int>&leftChild,vector<int>&rightChild)
    {
        
        if(visited[u]) return;
        
        visited[u] = true;
        
        if(leftChild[u]!=-1) dfs(leftChild[u],leftChild,rightChild);
        
        if(rightChild[u]!=-1) dfs(rightChild[u],leftChild,rightChild);
        
    }    
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        
        visited.resize(n,false);
        
        vector<int>indegree(n,0);
        
        for(int i=0;i<n;++i){
            if(leftChild[i]!=-1){
                indegree[leftChild[i]]++;
            }
            if(rightChild[i]!=-1){
                indegree[rightChild[i]]++;
            }
        }
        
        // For a valid directed tree , except root every node must have exactly one indegree //
        
        for(int i=0;i<n;++i){
            if(indegree[i]>=2){
                return false;
            }
        }
        
        int root_cnt=0;
        
        // Check how many potential candidates are present over there for being a root node , if it is more than one then return false //
        
        int root_node = -1;
        
        for(int i=0;i<n;++i){
            if(indegree[i]==0){
                root_cnt++;
                root_node = i;
            }
        }
        
        if(root_cnt!=1) return false;
        
        // Finally ,we should take care about disconnected tree , for doing these just do a simple dfs traversal from the current root node and if at the end of dfs traversal , all the nodes are visited , then it is a valid tree //
        
        dfs(root_node,leftChild,rightChild);
        
        for(int i=0;i<n;++i){
            
            if(!visited[i]) return false;
            
        }
        
        return true;
        
    }
};