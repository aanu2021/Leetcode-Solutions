class Solution {
public:
    
    int getNodesCount(TreeNode* root){
        if(!root) return 0;
        return 1 + getNodesCount(root->left) + getNodesCount(root->right);
    }
    
    void precompute(TreeNode* root, vector<vector<int>>&graph, vector<int>&parent, vector<int>&left, vector<int>&right){
        if(!root) return;
        if(root->left){
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
            parent[root->left->val] = root->val;
            left[root->val] = root->left->val;
        }
        if(root->right){
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
            parent[root->right->val] = root->val;
            right[root->val] = root->right->val;
        }
        precompute(root->left, graph, parent, left, right);
        precompute(root->right, graph, parent, left, right);
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        if(!root) return "";
        int n = getNodesCount(root);
        
        vector<vector<int>>graph(n+1);
        vector<int>parent(n+1, -1);
        vector<int>left(n+1, -1);
        vector<int>right(n+1, -1);
        vector<int>previous(n+1, -1);
        vector<int>visited(n+1, 0);
        
        precompute(root, graph, parent, left, right);
        
        queue<int>q;
        q.push(startValue);
        visited[startValue] = 1;
        
        while(!q.empty()){
            int node = q.front(); q.pop();
            for(auto &nbr : graph[node]){
                if(visited[nbr]) continue;
                visited[nbr] = 1;
                previous[nbr] = node;
                q.push(nbr);
            }
        }
        
        string direction = "";
        int node = destValue;
        
        while(node != startValue){
            int curr_node = node;
            int prev_node = previous[curr_node];
            if(left[prev_node] == curr_node){
                direction += "L";
            }
            else if(right[prev_node] == curr_node){
                direction += "R";
            }
            else{
                direction += "U";
            }
            node = prev_node;
        }
        
        reverse(direction.begin(),direction.end());
        return direction;
    }
};